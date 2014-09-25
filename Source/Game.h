#include <SDL.h>


class CGame
{
public:
	enum Estado{
	ESTADO_INICIANDO,
	ESTADO_MENU,
	ESTADO_JUGANDO,
	ESTADO_TERMINANDO,
	ESTADO_FINALIZADO,
};
	bool Start();
	static CGame instanceGame;

	CGame();
	void Finalize();

private:
	void iniciando();
	SDL_Surface *screen;

	Estado estado;

};