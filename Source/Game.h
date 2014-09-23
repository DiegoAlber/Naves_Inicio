
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
	Estado estado;
};