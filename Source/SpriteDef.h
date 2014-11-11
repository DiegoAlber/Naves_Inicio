#ifndef _SPRITEDEF_H__
#define _SPRITEDEF_H__

class SpriteDef{

    struct Modulos{
	int id;
	int x;
	int y;
	int w;
	int h;

	};
public:
	Modulos modulos[1];
	SpriteDef();

};

#endif