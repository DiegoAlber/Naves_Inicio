#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>


CGame::CGame(){
	estado= ESTADO_INICIANDO;
	//ACT3: Mal, este codigo debe de ir en el metodo "Iniciando()"
	/////ACT3: Mal, Esta seccion no debe estar aqui. Debe estar en el metodo iniciando.
	//if (SDL_Init(SDL_INIT_VIDEO)){
	//printf("Error %s",SDL_GetError());
	//exit(EXIT_FAILURE);
	//}
	//screen=SDL_SetVideoMode( 640,480,24, SDL_SWSURFACE);
    //if(screen==NULL){
	//printf("Error %s", SDL_GetError());
	//exit(EXIT_FAILURE);
	//}
	//SDL_WM_SetCaption("Mi primer Juego",NULL);
	//////ACT3: Hasta aqui.
	atexit(SDL_Quit);
}

//ACT3: Mal, falto crear este metodo
void CGame::iniciando(){
	if (SDL_Init(SDL_INIT_VIDEO)){
	printf("Error %s",SDL_GetError());
	exit(EXIT_FAILURE);
	}
	screen=SDL_SetVideoMode( 640,480,24, SDL_SWSURFACE);
    if(screen==NULL){
	printf("Error %s", SDL_GetError());
	exit(EXIT_FAILURE);
	}
	SDL_WM_SetCaption("Mi primer Juego",NULL);
}


// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
	SDL_Quit();
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
            
		//Maquina de estados
		switch(estado){
		case 0: Estado::ESTADO_INICIANDO;
			//ACT3: Mal, falto llamar al metodo "iniciando()"
			iniciando();
			estado=ESTADO_MENU;
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

		SDL_Flip(screen);
    }
	return true;
}
