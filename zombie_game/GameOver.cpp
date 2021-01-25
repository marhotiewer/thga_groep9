#include "GameOver.h"

GameOver::GameOver(sf::RenderWindow* window, AssetManager& assets, Game &game) : window(window), assets(assets), game(game)
{
	// Creating buttons
	this->buttons.push_back(new Button(this->assets, { 364.5f, 400.f }, ButtonType::Scores));
	this->buttons.push_back(new Button(this->assets, { 164.5f, 400.f }, ButtonType::Quit));
	this->playerText.setFont(assets.arial);
	this->playerText.setPosition(500, 500);
	this->playerText.setCharacterSize(40);
	this->playerText.setFillColor(sf::Color::Green);

	this->event = sf::Event();

	this->alpha_max = 1 * 255;
	this->alpha_div = 1;
	this->logo.setTexture(assets.gameOverTexture);
	this->logo.setPosition({ 0.f, 150.f });
	this->background.setTexture(assets.homescreenBackgroundTexture);
	this->background.setPosition({ 0.f, 0.f });
}

Screen GameOver::saveScoreToFile(int points)
{
	if (points == 0) { return Screen::MainMenu; }
	std::ifstream iputFile("scores.json");
	nlohmann::json jsoninput;
	if (!(iputFile.peek() == std::ifstream::traits_type::eof()))
	{
		iputFile >> jsoninput;//read scores to json library if file is not empty.
	}
	iputFile.close();

	std::ofstream outputFile("scores.json");
	nlohmann::json newScore;
	newScore["name"] = playerInput;
	newScore["score"] = this->game.player->getPoints();
	jsoninput.push_back(newScore);
	outputFile << jsoninput; //write scores to json scores file.
	outputFile.close();
	return Screen::MainMenu;
}

void GameOver::matchBackground()
{
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

Screen GameOver::update(float deltaTimeSeconds) {
	Screen nextScreen = this->pollEvents();
	return nextScreen;
}

void GameOver::toggleFullscreen() {
	if (this->isFullScreen) this->window->create(sf::VideoMode(640, 480), "Zombie Game");				// windowed
	else this->window->create(sf::VideoMode::getDesktopMode(), "Zombie Game", sf::Style::Fullscreen);	// fullscreen

	sf::View view = this->window->getView();
	view.setSize(sf::Vector2f(this->window->getSize()));
	view.setCenter({ 0.f, 0.f });
	this->window->setView(view);
	this->matchBackground();
	this->isFullScreen = !this->isFullScreen;
}

Screen GameOver::pollEvents()
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
		case sf::Event::TextEntered:
			if (event.text.unicode < 128)
			{
				this->playerInput += event.text.unicode;
				this->playerText.setString(this->playerInput);
			}
			break;
		case sf::Event::KeyPressed: {
			// toggle fullscreen mode
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				toggleFullscreen();
			}
			// close the game
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				this->window->close();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
				if (!this->playerInput.empty()) {
					this->playerInput.erase(this->playerInput.size() - 1);
					this->playerText.setString(this->playerInput);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				this->canSaveScore = true;
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
						case ButtonType::Play: {
							// Play the game!
							returnValue = Screen::Game;
							break;
						}
						case ButtonType::Quit: {
							// Quit the game :(
							window->close();
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

bool GameOver::running()
{
	return this->window->isOpen();
}

void GameOver::render()
{
	this->window->clear();
	// Draw stuff
	this->window->draw(background);
	this->window->draw(logo);
	for (Button* button : buttons) {
		button->draw(window);
	}
	this->window->draw(this->playerText);
	this->window->display();
}

Screen GameOver::run()
{
	int points = this->game.player->getPoints();

	sf::View view = this->window->getView();
	view.setCenter({ 0.f, 0.f });
	this->window->setView(view);

	sf::Clock clock;
	float deltaTimeSeconds;
	Screen nextScreen = Screen::None;

	while (nextScreen == Screen::None && this->running()) {
		deltaTimeSeconds = clock.restart().asSeconds();
		nextScreen = this->update(deltaTimeSeconds);
		this->render();
		if (canSaveScore) {
			return this->saveScoreToFile(points);
		}
	}
	return nextScreen;
}
