#include <iostream>
#include "cScreen.h"
#include <SFML/Graphics.hpp>

class MainMenu : public cScreen
{
private:
	int alpha_max;
	int alpha_div;
	bool playing;
public:
	MainMenu(void);
	int Run(sf::RenderWindow& window) override;
};

MainMenu::MainMenu(void)
{
	alpha_max = 1 * 255;
	alpha_div = 1;
	playing = false;
}

int MainMenu::Run(sf::RenderWindow& window)
{
	sf::Event Event;
	bool Running = true;
	sf::Texture TitleTexture;
	sf::Texture BackgroundTexture;
	sf::Texture ButtonTexture;
	sf::Texture PlayTexture;
	sf::Texture QuitTexture;
	sf::Texture OptionsTexture;
	sf::Texture ScoresTexture;
	sf::Sprite Title;
	sf::Sprite Background;
	sf::Sprite Buttons;
	sf::Sprite PlayButton;
	sf::Sprite QuitButton;
	sf::Sprite OptionsButton;
	sf::Sprite ScoresButton;
	sf::Text Menu3;
	int menu = 0;
	int alpha = 0;

	TitleTexture.loadFromFile("title.png");
	Title.setTexture(TitleTexture);
	Title.setScale({ 0.3,0.3 });
	Title.setPosition({ 180.f, 20.f });

	BackgroundTexture.loadFromFile("MenuImage.png");
	Background.setTexture(BackgroundTexture);
	Background.setColor(sf::Color(255, 255, 255, alpha));
	Background.setPosition({ 15.f, 24.f });

	ButtonTexture.loadFromFile("buttons.png");
	Buttons.setTexture(ButtonTexture);
	Buttons.setColor(sf::Color(255, 255, 255, alpha));
	Buttons.setScale({ 0.5,0.5 });
	Buttons.setPosition({ 280.f,230.f });

	PlayTexture.loadFromFile("play.png");
	PlayButton.setTexture(PlayTexture);
	PlayButton.setColor(sf::Color(255, 255, 255, alpha));
	PlayButton.setScale({ 0.5,0.5 });
	PlayButton.setPosition({ 310.f, 242.f });

	QuitTexture.loadFromFile("quit.png");
	QuitButton.setTexture(QuitTexture);
	QuitButton.setColor(sf::Color(255, 255, 255, alpha));
	QuitButton.setScale({ 0.5,0.5 });
	QuitButton.setPosition({ 310.f, 296.f });

	OptionsTexture.loadFromFile("options.png");
	OptionsButton.setTexture(OptionsTexture);
	OptionsButton.setColor(sf::Color(255, 255, 255, alpha));
	OptionsButton.setScale({ 0.5,0.5 });
	OptionsButton.setPosition({ 292.f, 350.f });

	ScoresTexture.loadFromFile("scores.png");
	ScoresButton.setTexture(ScoresTexture);
	ScoresButton.setColor(sf::Color(255, 255, 255, alpha));
	ScoresButton.setScale({ 0.5,0.5 });
	ScoresButton.setPosition({ 296.5f, 405.f });

	if (playing)
	{
		alpha = alpha_max;
	}

	while (Running)
	{
		//Verifying events
		while (window.pollEvent(Event))
		{
			// Window closed
			if (Event.type == sf::Event::Closed)
			{
				return (-1);
			}
			//Key pressed
			if (Event.type == sf::Event::KeyPressed)
			{
				switch (Event.key.code)
				{
				case sf::Keyboard::Up:
					if (menu == 0) {
						menu = 3;
					}
					else {
						menu--;
					}
					break;
				case sf::Keyboard::Down:
					if (menu == 3) {
						menu = 0;
					}
					else {
						menu++;
					}
					break;
				case sf::Keyboard::Return:
					if (menu == 0)
					{
						playing = true;
						return (1);
					}
					else if (menu == 1) {
						return -1;
					}
					else
					{
						return (-1);
					}
					break;

				default:
					break;
				}
			}
		}
		//When getting at alpha_max, we stop modifying the sprite
		if (alpha < alpha_max)
		{
			alpha++;
		}
		Background.setColor(sf::Color(255, 255, 255, alpha / alpha_div));
		Buttons.setColor(sf::Color(255, 255, 255, alpha / alpha_div));
		if (menu == 0)
		{
			PlayButton.setColor(sf::Color(255, 0, 0, 255));
			QuitButton.setColor(sf::Color(255, 255, 255, 255));
			OptionsButton.setColor(sf::Color(255, 255, 255, 255));
			ScoresButton.setColor(sf::Color(255, 255, 255, 255));
		}
		else if (menu == 1)
		{
			PlayButton.setColor(sf::Color(255, 255, 255, 255));
			QuitButton.setColor(sf::Color(255, 0, 0, 255));
			OptionsButton.setColor(sf::Color(255, 255, 255, 255));
			ScoresButton.setColor(sf::Color(255, 255, 255, 255));
		}
		else if (menu == 2)
		{
			PlayButton.setColor(sf::Color(255, 255, 255, 255));
			QuitButton.setColor(sf::Color(255, 255, 255, 255));
			OptionsButton.setColor(sf::Color(255, 0, 0, 255));
			ScoresButton.setColor(sf::Color(255, 255, 255, 255));
		}
		else if (menu == 3)
		{
			PlayButton.setColor(sf::Color(255, 255, 255, 255));
			QuitButton.setColor(sf::Color(255, 255, 255, 255));
			OptionsButton.setColor(sf::Color(255, 255, 255, 255));
			ScoresButton.setColor(sf::Color(255, 0, 0, 255));
		}
		else

		//Clearing screen
		window.clear();
		//Drawing
		window.draw(Background);
		window.draw(Buttons);
		window.draw(Title);
		if (alpha == alpha_max)
		{
			if (playing)
			{
				window.draw(Menu3);
			}
			else
			{
				window.draw(PlayButton);
				window.draw(QuitButton);
				window.draw(OptionsButton);
				window.draw(ScoresButton);
			}
		}
		window.display();
	}

	//Never reaching this point normally, but just in case, exit the windowlication
	return (-1);
}