#include "ScoreScreen.h"

ScoreScreen::ScoreScreen(sf::RenderWindow* window, AssetManager& assets) : window(window), assets(assets)
{
	this->event = sf::Event();

	// Creating buttons
	this->buttons.push_back(new Button(this->assets, { 0.f, 200.f }, ButtonType::Menu));

	this->scoreBoard.setTexture(assets.scoreBoard);
	this->scoreBoard.setOrigin({ float(this->scoreBoard.getTextureRect().width ) / 2, float(this->scoreBoard.getTextureRect().height) / 2 }); // center of the sprite
	this->scoreBoard.setPosition(sf::Vector2f(0.f, 0.f));

	this->background.setTexture(assets.homescreenBackgroundTexture);
	sf::IntRect backgroundRect = this->background.getTextureRect();
	this->background.setOrigin({ float(backgroundRect.width) / 2, float(backgroundRect.height) / 2 }); // center of the sprite
	this->background.setPosition({ 0.f, 0.f });
	this->matchBackground();
}

void ScoreScreen::displayScores()
{
	std::ifstream iputFile("scores.json");
	nlohmann::json jsonInput;
	if (!(iputFile.peek() == std::ifstream::traits_type::eof()))
	{
		std::multimap<int, std::string, std::greater<int> > scoreMap;
		iputFile >> jsonInput; //read scores to json library if file is not empty.
		for (auto& element : jsonInput) {
			scoreMap.insert(std::pair<int, std::string>(element["score"], element["name"]));
		}
		std::multimap<int, std::string, std::greater<int>>::iterator first = scoreMap.begin();
		if (scoreMap.size() > 8) { last = std::next(first, 8); } else { last = std::next(first, scoreMap.size()); }
		for (std::multimap<int, std::string, std::greater<int>>::iterator it = first; it != last; it++) {
			scoreTextVector.push_back(sf::Text((it->second + ": " + std::to_string(it->first)), assets.arial, 28));
			scoreTextVector.back().setFillColor(sf::Color::Red);
		}
	}
	else { //no scores in file: scores.json
		scoreTextVector.push_back(sf::Text("No scores", assets.arial, 28));
		scoreTextVector.back().setFillColor(sf::Color::Red);
	}
	iputFile.close();
}


void ScoreScreen::matchBackground() {
	sf::IntRect textureRect = this->background.getTextureRect();
	sf::Vector2u windowSize = this->window->getSize();
	int width = textureRect.width;
	int height = textureRect.height;
	// Calculate width scale
	float widthScale = float(windowSize.x) / width;
	// Calculate height scale
	float heightScale = float(windowSize.y) / width;
	// Change scale to biggest value
	if (widthScale > heightScale) {
		this->background.setScale({ widthScale, widthScale });
	}
	else {
		this->background.setScale({ heightScale, heightScale });
	}
}

Screen ScoreScreen::update(float deltaTimeSeconds) {
	Screen nextScreen = this->pollEvents();
	float textx = -100.f, texty = -150.f;
	for (sf::Text &text : scoreTextVector) {
		text.setPosition(sf::Vector2f(textx, texty));
		texty += 38;
	}
	return nextScreen;
}

void ScoreScreen::toggleFullscreen() {
	if (this->isFullScreen) this->window->create(sf::VideoMode(640, 480), "Z-Rush");				// windowed
	else this->window->create(sf::VideoMode::getDesktopMode(), "Z-Rush", sf::Style::Fullscreen);	// fullscreen

	sf::View view = this->window->getView();
	view.setSize(sf::Vector2f(this->window->getSize()));
	view.setCenter({ 0.f, 0.f });
	this->window->setView(view);
	this->matchBackground();
	this->isFullScreen = !this->isFullScreen;
}

Screen ScoreScreen::pollEvents()
{
	Screen returnValue = Screen::None;
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed: {
			this->window->close();
			break;
		}
		case sf::Event::Resized: {
			sf::View view = this->window->getView();
			view.setSize(sf::Vector2f(this->window->getSize()));
			this->window->setView(view);
			this->matchBackground();
			break;
		}
		case sf::Event::KeyPressed: {
			// toggle fullscreen mode
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				toggleFullscreen();
			}
			// close the game
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				this->window->close();
			}
			break;
		}
		case sf::Event::MouseMoved: {
			// Update buttons
			for (Button* button : buttons) {
				button->buttonSelected(this->window->mapPixelToCoords({ this->event.mouseMove.x , this->event.mouseMove.y }));
			}
		}
		case sf::Event::MouseButtonPressed: {
			if (event.mouseButton.button == sf::Mouse::Left) {
				ButtonType buttonPressed = ButtonType::None;
				// Check if a button was pressed
				for (Button* button : buttons) {
					buttonPressed = button->buttonPressed();
					if (buttonPressed != ButtonType::None) {
						// A button was pressed
						switch (buttonPressed) {
						case ButtonType::Menu: {
							returnValue = Screen::MainMenu;
							break;
						}
						default: break;
						}
					}
				}
			}
		}
		default: break;
		}
	}
	return returnValue;
}

bool ScoreScreen::running()
{
	return this->window->isOpen();
}

void ScoreScreen::render()
{
	this->window->clear();
	this->window->draw(this->background);
	this->window->draw(this->logo);
	for (Button* button : this->buttons) {
		button->draw(this->window);
	}
	this->window->draw(this->scoreBoard);
	for (sf::Text text : this->scoreTextVector) {
		this->window->draw(text);
	}
	this->window->display();
}



Screen ScoreScreen::run()
{
	sf::View view = this->window->getView();
	view.setCenter({ 0.f, 0.f });
	this->window->setView(view);
	this->displayScores();

	Screen nextScreen = Screen::None;
	float deltaTimeSeconds;
	sf::Clock clock;

	while (nextScreen == Screen::None && this->running()) {
		deltaTimeSeconds = clock.restart().asSeconds();
		nextScreen = this->update(deltaTimeSeconds);
		this->render();
	}
	scoreTextVector.clear();
	return nextScreen;
}
