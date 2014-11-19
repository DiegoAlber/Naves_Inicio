#include "SpriteDef.h"
#include "Config.h"
SpriteDef::SpriteDef(){
	modulos[0].id = MODULO_MINAVE_NAVE;
	modulos[0].x = 0;
	modulos[0].y = 0;
	modulos[0].w = 64;
	modulos[0].h = 64;

	modulos[1].id = MODULO_FONDOMENU_FONDO;
	modulos[1].x = 0;
	modulos[1].y = 0;
	modulos[1].w = WIDTH_SCREEN;
	modulos[1].h = HEIGHT_SCREEN;

	modulos[2].id = MODULO_ENEMIGO_NAVE;
	modulos[2].x = 0;
	modulos[2].y = 0;
	modulos[2].w = WIDTH_SCREEN;
	modulos[2].h = HEIGHT_SCREEN;

	modulos[3].id = MODULO_TEXTO_TITULO;
	modulos[3].x = 150;
	modulos[3].y = 114;
	modulos[3].w = 344;
	modulos[3].h = 73;

	modulos[4].id =MODULO_TEXTOS_NOMBRE ;
	modulos[4].x = 197;
	modulos[4].y = 213;
	modulos[4].w = 246;
	modulos[4].h = 20;

	modulos[5].id = MODULO_TEXTO_MENU_OPCION1;
	modulos[5].x = 164;
	modulos[5].y = 240;
	modulos[5].w = 153;
	modulos[5].h = 35;

	modulos[6].id = MODULO_TEXTO_MENU_OPCION2;
	modulos[6].x = 207;
	modulos[6].y = 291;
	modulos[6].w = 110;
	modulos[6].h = 33;

	modulos[7].id = MODULO_TEXTO_MENU_OPCION1_SELECCIONADO;
	modulos[7].x = 322;
	modulos[7].y = 241;
	modulos[7].w = 153;
	modulos[7].h = 34;

	modulos[8].id = MODULO_TEXTO_MENU_OPCION2_SELECCIONADO;
	modulos[8].x = 325;
	modulos[8].y = 290;
	modulos[8].w = 108;
	modulos[8].h = 34;
}