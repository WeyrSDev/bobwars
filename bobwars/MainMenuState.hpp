#ifndef MAIN_MENU_STATE
#define MAIN_MENU_STATE

#include "GamePlayState.hpp"
#include "ENGINE\Logger.hpp"
#include <SFUI\Button.hpp>
#include "ResourceManager.hpp"

#include "StateMachine.hpp"
#include "StateBase.hpp"

class MainMenuState : public AppState2
{
public:
	MainMenuState(AppEngine2* app_);
	~MainMenuState();

	void Pause();
	void Resume();

	void HandleEvents();
	void Update();
	void Draw();

private:
	bool mouseIsOver(sf::Shape &object);

	AppEngine2* app;

	ResourceManager resMan;

	sf::RectangleShape logoShape;
	sf::Texture		   logoTexture;

	SFUI::Button playButton;
	SFUI::Button loadButton;
	SFUI::Button settingsButton;
	SFUI::Button exitButton;
};

#endif // !MAIN_MENU_STATE
