	#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

CGame::CGame(){
	int estado = 0;
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
            
		//Maquina de estados
		switch(estado){
		case 0: Estado::ESTADO_INICIANDO;
			break;
		case 1:Estado::ESTADO_MENU;
			break;
		case 2: Estado::ESTADO_JUGANDO;
			break;
		case 3: Estado::ESTADO_TERMINANDO;
			break;
		case 4: Estado::ESTADO_FINALIZADO;
			break;
				salirJuego = true;
			break;
		};
    }
	return true;
}
