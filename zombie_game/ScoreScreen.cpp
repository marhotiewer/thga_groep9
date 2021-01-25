#include "ScoreScreen.h"
#include <sstream>
//#include <iostream>
#include <iomanip>


ScoreScreen::ScoreScreen(sf::RenderWindow* window, AssetManager& assets) : window(window), assets(assets)
{
	// Creating buttons
	this->buttons.push_back(new Button(this->assets, { 264.5f, 230.f }, ButtonType::Play));
	this->scoreBoard.setTexture(assets.scoreBoard);
	this->scoreBoard.setPosition(sf::Vector2f(264.5f, 284.f));
	//this->buttons.push_back(new Button(this->assets, { 264.5f, 284.f }, ButtonType::Quit));
	//this->buttons.push_back(new Button(this->assets, { 264.5f, 338.f }, ButtonType::Options));
	//this->buttons.push_back(new Button(this->assets, { 264.5f, 392.f }, ButtonType::Scores));
	this->event = sf::Event();

	this->alpha_max = 1 * 255;
	this->alpha_div = 1;
	this->logo.setTexture(assets.gameLogoTexture);
	this->logo.setPosition({ 231.f, 20.f });
	this->background.setTexture(assets.homescreenBackgroundTexture);
	this->background.setPosition({ 0.f, 0.f });
	//this->background.setColor(sf::Color(255, 255, 255, alpha))
}

Screen ScoreScreen::update(float deltaTimeSeconds) {
	Screen nextScreen = this->pollEvents();
	float testx = 284.5f, testy = 292.f;
	for (sf::Text &text : scoreTextVector) {
		text.setPosition(sf::Vector2f(testx, testy));
		testy += 38;
	}
	return nextScreen;
}

void ScoreScreen::toggleFullscreen() {
	if (this->isFullScreen) this->window->create(sf::VideoMode(640, 480), "Zombie Game");				// windowed
	else this->window->create(sf::VideoMode::getDesktopMode(), "Zombie Game", sf::Style::Fullscreen);	// fullscreen
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
			sf::Vector2i mousePosInt = sf::Mouse::getPosition(*this->window);
			sf::Vector2f mousePos{ float(mousePosInt.x), float(mousePosInt.y) };
			for (Button* button : buttons) {
				button->buttonSelected(mousePos);
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

bool ScoreScreen::running()
{
	return this->window->isOpen();
}

void ScoreScreen::render()
{
	this->window->clear();
	// Draw stuff
	this->window->draw(this->background);
	this->window->draw(this->logo);
	for (Button* button : buttons) {
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
	std::ifstream iputFile("scores.json");
	nlohmann::json jsonInput;
	if (!(iputFile.peek() == std::ifstream::traits_type::eof()))
	{
		std::multimap<int, std::string, std::greater<int> > scoreMap;
		iputFile >> jsonInput; //read scores to json library if file is not empty.
		for (auto& element : jsonInput) {
			scoreMap.insert(std::pair<int, std::string> (element["score"], element["name"]));
		}
		auto first = scoreMap.begin();
		auto last = std::next(first, scoreMap.size());
		if (scoreMap.size() < 10) { auto last = std::next(first, scoreMap.size()); }
		for (auto it = first; it != last; it++) {
			scoreTextVector.push_back(sf::Text((it->second + ": " + std::to_string(it->first)), assets.arial, 28));
			scoreTextVector.back().setFillColor(sf::Color::Green);
			//std::cout << it->first << " : " << it->second << std::endl;
		}
	}
	else {
		std::cout << "no scores" << std::endl;;
	}
	iputFile.close();
	
	sf::Clock clock;
	float deltaTimeSeconds;
	Screen nextScreen = Screen::None;
	while (nextScreen == Screen::None && this->running()) {
		deltaTimeSeconds = clock.restart().asSeconds();
		nextScreen = this->update(deltaTimeSeconds);
		this->render();
	}
	return nextScreen;
}
