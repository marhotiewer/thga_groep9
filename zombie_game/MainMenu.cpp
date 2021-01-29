#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow* window, AssetManager& assets) : window(window), assets(assets)
{
	this->event = sf::Event();

	this->buttons.push_back(new Button(this->assets, { 0.f, 27.f }, ButtonType::Play));
	this->buttons.push_back(new Button(this->assets, { 0.f, 81.f }, ButtonType::Scores));
	this->buttons.push_back(new Button(this->assets, { 0.f, 135.f }, ButtonType::Quit));
	
	this->logo.setTexture(assets.gameLogoTexture);
	sf::IntRect logoRect = this->logo.getTextureRect();
	this->logo.setOrigin({ float(logoRect.width) / 2, float(logoRect.height) / 2 }); // center of the sprite
	this->logo.setPosition({ 0.f, -118.5f });

	this->background.setTexture(assets.homescreenBackgroundTexture);
	sf::IntRect backgroundRect = this->background.getTextureRect();
	this->background.setOrigin({ float(backgroundRect.width) / 2, float(backgroundRect.height) / 2 }); // center of the sprite
	this->background.setPosition({ 0.f, 0.f });

	this->clickSound = sf::Sound(this->assets.mainMenuClickSound);
	this->clickSound.setVolume(50.f);
}

MainMenu::~MainMenu() {
	this->assets.mainMenuSoundtrack.stop();
	for (Button* button : this->buttons) delete button;
}

void MainMenu::matchBackground() {
	sf::IntRect textureRect = this->background.getTextureRect();
	sf::Vector2u windowSize = this->window->getSize();

	// Calculate width, height scales
	float widthScale = float(windowSize.x) / textureRect.width;
	float heightScale = float(windowSize.y) / textureRect.width;

	// Change scale to biggest value
	if (widthScale > heightScale) {
		this->background.setScale({ widthScale, widthScale });
	}
	else {
		this->background.setScale({ heightScale, heightScale });
	}
}

Screen MainMenu::update(float deltaTimeSeconds) {
	Screen nextScreen = this->pollEvents();
	return nextScreen;
}

void MainMenu::toggleFullscreen() {
	if (this->isFullScreen) this->window->create(sf::VideoMode(640, 480), "Z-Rush");				// windowed
	else this->window->create(sf::VideoMode::getDesktopMode(), "Z-Rush", sf::Style::Fullscreen);	// fullscreen

	sf::View view = this->window->getView();
	view.setSize(sf::Vector2f(this->window->getSize()));
	view.setCenter({ 0.f, 0.f });
	this->window->setView(view);
	this->matchBackground();
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
				this->assets.mainMenuSoundtrack.stop();
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
					this->assets.mainMenuSoundtrack.stop();
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
							this->clickSound.play();
							switch (buttonPressed) {
								case ButtonType::Play: {
									// Play the game!
									returnValue = Screen::Game;
									this->assets.mainMenuSoundtrack.stop();
									break;
								}
								case ButtonType::Quit: {
									// Quit the game :(
									window->close();
								}
								case ButtonType::Scores:
									//show the score screen.
									returnValue = Screen::Scores;
									break;
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
	this->window->draw(this->background);
	this->window->draw(this->logo);
	for (Button* button : this->buttons) button->draw(this->window);
	this->window->display();
}

Screen MainMenu::run()
{
	sf::View view = this->window->getView();
	view.setCenter({ 0.f, 0.f });
	this->window->setView(view);

	matchBackground();

	Screen nextScreen = Screen::None;
	sf::Clock clock;
	float deltaTime;
	if(!(this->assets.mainMenuSoundtrack.getStatus() == this->assets.mainMenuSoundtrack.Playing))	this->assets.mainMenuSoundtrack.play();

	while (nextScreen == Screen::None && this->running())
	{
		deltaTime = clock.restart().asSeconds();
		nextScreen = this->update(deltaTime);
		this->render();
	}
	return nextScreen;
}
