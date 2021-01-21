#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow* window, AssetManager& assets) : window(window), assets(assets)
{
	// Creating buttons
	this->buttons.push_back(new Button(this->assets, { 264.5f, 230.f }, ButtonType::Play));
	this->buttons.push_back(new Button(this->assets, { 264.5f, 284.f }, ButtonType::Quit));
	this->buttons.push_back(new Button(this->assets, { 264.5f, 338.f }, ButtonType::Options));
	this->buttons.push_back(new Button(this->assets, { 264.5f, 392.f }, ButtonType::Scores));

	this->event = sf::Event();

	this->alpha_max = 1 * 255;
	this->alpha_div = 1;
	this->logo.setTexture(assets.gameLogoTexture);
	this->logo.setPosition({ 231.f, 20.f });
	this->background.setTexture(assets.homescreenBackgroundTexture);
	this->background.setPosition({ 0.f, 0.f });
	//this->background.setColor(sf::Color(255, 255, 255, alpha))
	this->backgroundMusic = &this->assets->mainMenuSoundtrack;
	this->clickSound = sf::Sound(this->assets->mainMenuClickSound);
	this->clickSound.setVolume(50.f);
}

Screen MainMenu::update(float deltaTimeSeconds) {
	Screen nextScreen = this->pollEvents();
	return nextScreen;
}

void MainMenu::toggleFullscreen() {
	if (this->isFullScreen) this->window->create(sf::VideoMode(640, 480), "Zombie Game");				// windowed
	else this->window->create(sf::VideoMode::getDesktopMode(), "Zombie Game", sf::Style::Fullscreen);	// fullscreen
	this->isFullScreen = !this->isFullScreen;
}

Screen MainMenu::pollEvents()
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
							this->clickSound.play();
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

bool MainMenu::running()
{
	return this->window->isOpen();
}

void MainMenu::render()
{
	this->window->clear();
	// Draw stuff
	this->window->draw(background);
	this->window->draw(logo);
	for (Button* button : buttons) {
		button->draw(window);
	}
	this->window->display();
}

Screen MainMenu::run()
{
	backgroundMusic->play();
	sf::Clock clock;
	float deltaTimeSeconds;
	Screen nextScreen = Screen::None;
	while ( nextScreen == Screen::None && this->running() ) {
		deltaTimeSeconds = clock.getElapsedTime().asSeconds();
		clock.restart();
		nextScreen = this->update(deltaTimeSeconds);
		this->render();
	}
	return nextScreen;
}
