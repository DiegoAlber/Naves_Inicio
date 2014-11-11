#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Config.h"
#include <SDL.h>
#include <SDL_image.h>

CGame::CGame(){
	tiempoFrameInicial=0;
	estado=ESTADO_INICIANDO;
	//atexit(SDL_Quit);
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
	delete nave;
	
	delete *enemigoArreglo;
	SDL_FreeSurface(screen);
	SDL_Quit();
}

void CGame::Iniciando(){
	if (SDL_Init( SDL_INIT_VIDEO )){
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	screen = SDL_SetVideoMode( WIDTH_SCREEN, HEIGHT_SCREEN, 24, SDL_HWSURFACE);
	if (screen == NULL)
	{
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_WM_SetCaption( "Mi primer Juego", NULL );
	atexit(SDL_Quit);
	nave = new Nave(screen,"../Data/minave.bmp",(WIDTH_SCREEN/2)/*-(sprite->WidthModule(0)/2)*/,(HEIGHT_SCREEN-80)/*-(sprite->HeightModule(0))*/);
	//-enemigo = new Nave(screen,"../Data/enemigo.bmp",0,0);
	//-enemigo->SetAutoMovimiento(false);
	
	for(int i=0;i<10;i++){
		enemigoArreglo[i] = new Nave(screen,"../Data/enemigo.bmp",i *60,0);
		enemigoArreglo[i]->SetAutoMovimiento(false);
		enemigoArreglo[i]->SetPasoLimite(4);

	}
	tick=0;

	//-enemigo->SetPasoLimite(4);
	//-enemigo->SetAutoMovimiento();
	//delete nave;
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;

	while (salirJuego == false){  
		//Maquina de estados
		switch(estado){
		case Estado::ESTADO_INICIANDO:
			//system("cls");
			/*printf("\n1. ESTADO_INICIANDO");
			printf("\n2. ESTADO_MENU");
			printf("\n3. ESTADO_JUGANDO");
			printf("\n4. ESTADO_TERMINANDO");
			printf("\n2. ESTADO_MENU");
			printf("\n5. ESTADO_FINALIZANDO");
			scanf("%d",&estado);*/
			Iniciando();
			estado = ESTADO_MENU;
			//getchar();
			break;
		case Estado::ESTADO_MENU:
			//-enemigo->Actualizar();
			for(int i=0;i<10;i++){
				enemigoArreglo[i]->Actualizar();
			}
			MoverEnemigo();
			/*system("cls");
			printf("\n2. ESTADO_MENU");*/
			//nave->PintarModulo(1,0,0);
			SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format,0,0,0)); // Color de pantalla y velocidad
			keys = SDL_GetKeyState(NULL);
			if(keys[SDLK_RIGHT]){
				if(!EsLimitePantalla(nave, BORDE_DERECHO))
					nave->Mover(1);
			}
			if(keys[SDLK_LEFT]){
				nave->Mover(-1);
			}
			nave->Pintar();
			//-enemigo->Pintar();
			for(int i=0; i<10;i++)
			enemigoArreglo[i]->Pintar();
			//getchar();
			break;
		case Estado::ESTADO_JUGANDO:
			system("cls");
			printf("\n3. ESTADO_JUGANDO");
			getchar();
			break;
		case Estado::ESTADO_TERMINANDO:
			system("cls");
			printf("\n4. ESTADO_TERMINANDO");
			getchar();
			break;
		case Estado::ESTADO_FINALIZANDO:
			system("cls");
			printf("\n5. ESTADO_FINALIZANDO");
			getchar();
			salirJuego = false;
			Finalize();
			break;
		}
		while(SDL_PollEvent(&event)) // aqui se creara una lista de events ocurridos
		{
			if(event.type == SDL_QUIT) {salirJuego = true;} // si se detecta una salida de SDL
			if(event.type == SDL_KEYDOWN) {  }
		}

		//Este codigo estara provicionalmente aqui.
		SDL_Flip(screen);
	    //Calculando FPS
		tiempoFrameFinal=SDL_GetTicks();
		printf("Frames:%d Tiempo:%d Tiempo Promedio:%f Tiempo por Frame:%d \n",tick,SDL_GetTicks(),(float)SDL_GetTicks()/(float)tick,tiempoFrameFinal-tiempoFrameInicial);
		tiempoFrameInicial=tiempoFrameFinal;//Marcamos el inicio nuevamente
		tick++;
		
	}
	return true;
}
bool CGame::EsLimitePantalla(Nave * objeto, int bandera){
	if(bandera & BORDE_IZQUIERDO)
		if(objeto->ObtenerX() <= 0)
			return true;
	if(bandera & BORDE_SUPERIOR)
		if(objeto->ObtenerY() <= 0)
			return true;
	if(bandera & BORDE_DERECHO)
		if(objeto->ObtenerX() >= WIDTH_SCREEN - objeto->ObtenerW())
			return true;
	if(bandera & BORDE_INFERIOR)
		if(objeto->ObtenerY() >= HEIGHT_SCREEN - objeto->ObtenerH())
			return true;
	return false;
}

void CGame::MoverEnemigo(){
	/*if(enemigo->ObtenerPasoActual()==0)
		if(!EsLimitePantalla(enemigo,BORDE_DERECHO))
			enemigo->Mover(1);
		else{
			enemigo->IncrementarPasoActual();
			enemigo->IncrementarPasoActual();
		}
	if(enemigo->ObtenerPasoActual()==0)
		if(!EsLimitePantalla(enemigo,BORDE_IZQUIERDO))
			enemigo->Mover(1);
		else{
			enemigo->IncrementarPasoActual();
			enemigo->IncrementarPasoActual();
		}
		*/ //esto tambien es de enemigo


		for(int i=0;i<10;i++){
			

	if(enemigoArreglo[i]->ObtenerPasoActual()==0)
		if(!EsLimitePantalla(enemigoArreglo[i],BORDE_DERECHO))
			enemigoArreglo[i]->Mover(1);
		else{
			enemigoArreglo[i]->IncrementarPasoActual();
			enemigoArreglo[i]->IncrementarPasoActual();
		}

		//*****************************//
	if(enemigoArreglo[i]->ObtenerPasoActual()==2)
		if(!EsLimitePantalla(enemigoArreglo[i],BORDE_IZQUIERDO))
			enemigoArreglo[i]->Mover(-1);
		else{
			enemigoArreglo[i]->IncrementarPasoActual();
			enemigoArreglo[i]->IncrementarPasoActual();
		}
		}
}

