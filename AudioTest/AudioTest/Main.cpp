#include <stdio.h>
#include <irrKlang.h>
#include <chrono>
#include <thread>
#include <iostream>

int main() {
	char c;
	bool isRunning = true;
	irrklang::ISoundEngine* engine = irrklang::createIrrKlangDevice();
	irrklang::ISound* music = engine->play2D("media/getout.ogg", true, false, true);
	while (isRunning) {
		c = getchar();
		switch (c) {
		case 'q':
			isRunning = false;
			for (float volume = 1.0f; volume > 0.0f; volume -= 0.01f) {
				std::cout << volume << std::endl;
				music->setVolume(volume);
				std::this_thread::sleep_for(std::chrono::milliseconds(30));
			}
			break;
		case 'b':
			engine->play2D("media/bell.wav");
			break;
		case 'e':
			engine->play2D("media/explosion.wav");
			break;
		/*case 'd':
			break;*/
		}
	}
	engine->drop(); //deletes the engine
	return 0;
}