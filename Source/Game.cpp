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
	nave = new Nave(screen,"../Data/minave.bmp",(WIDTH_SCREEN/2),(HEIGHT_SCREEN-80),MODULO_MINAVE_NAVE);
    menu=new Nave(screen,"../Data/Fondo Menu.bmp",0,0,MODULO_FONDOMENU_FONDO);
    textos=new Nave(screen,"../Data/menu.bmp",0,0,MODULO_TEXTO_TITULO);

	
	for(int i=0;i<10;i++){
		enemigoArreglo[i] = new Nave(screen,"../Data/enemigo.bmp",i*60,0,MODULO_ENEMIGO_NAVE);
		enemigoArreglo[i]->SetAutoMovimiento(false);
		enemigoArreglo[i]->SetPasoLimite(4);

	}
	tick=0;
	opcionseleccionada=MODULO_TEXTO_MENU_OPCION1;

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
			
			Iniciando();
			estado = ESTADO_MENU;
			
			break;
		case Estado::ESTADO_MENU:
			menu->Pintar();
			textos->Pintar(MODULO_TEXTO_TITULO,150,50);
			textos->Pintar(MODULO_TEXTOS_NOMBRE,200,440);
			Menu();
			break;
			
		case Estado::ESTADO_JUGANDO:
			
			printf("\n3. ESTADO_JUGANDO");
			
			for(int i=0;i<10;i++){
				enemigoArreglo[i]->Actualizar();
			}
			MoverEnemigo();
			
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
			
			for(int i=0; i<10;i++)
			enemigoArreglo[i]->Pintar();
		
			break;
			getchar();
			break;
		case Estado::ESTADO_TERMINANDO:
			
			printf("\n4. ESTADO_TERMINANDO");
			getchar();
			break;
		case Estado::ESTADO_FINALIZANDO:
			
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
}   void CGame::Menu(){

	for(int i= MODULO_TEXTO_MENU_OPCION1, j = 0; i <= MODULO_TEXTO_MENU_OPCION2; i++, j++ ){
		if(i==opcionseleccionada)
			textos->Pintar(i+2,200,180+(j*80));
		else
        textos->Pintar(i, 200, 140+(j*80));
	}




}

