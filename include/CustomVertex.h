#ifndef CUSTOMVERTEX_H_GUARD
#define CUSTOMVERTEX_H_GUARD

struct VF4
{
	float f1, f2, f3, f4;
	VF4(float f1_ = 0.0, float f2_ = 0.0, float f3_ = 0.0, float f4_ = 0.0) : f1(f1_), f2(f2_), f3(f3_), f4(f4_) { }
};

struct VF3
{
	float f1, f2, f3;
	VF3(float f1_ = 0.0, float f2_ = 0.0, float f3_ = 0.0) : f1(f1_), f2(f2_), f3(f3_) { }
};

struct VF2
{
	float f1, f2;
	VF2(float f1_ = 0.0, float f2_ = 0.0) : f1(f1_), f2(f2_) { }
};

struct VI3 {
	int32_t i1, i2, i3;
	
	VI3(int32_t i1_ = 0, int32_t i2_ = 0, int32_t i3_ = 0) : i1(i1_), i2(i2_), i3(i3_) { }
};

struct Color
{
	float r, g, b, a;
};

struct CUSTOM_VERTEX
{
   VF3 pos;
	VF2 txcoord;
	float tx_page;
	Color color;
	
	CUSTOM_VERTEX(float x, float y, float z, float u = 0.0, float v = 0.0, float txp = 0.0) :
		pos(x, y, z), txcoord(u, v), tx_page(txp)
	{
		// color = al_map_rgb(0, 0, 0); <-- can't be called till allegro is initialized...
		// CUSTOM_VERTEX may be used statically before allegro is initialized.
		color.r = 1.0;
		color.g = 0.0;
		color.b = 1.0;
		color.a = 1.0;
	}
	
	CUSTOM_VERTEX(VF3 pos_ = VF3(), VF2 txc = VF2(), float txp = 0.0) :
		pos(pos_), txcoord(txc), tx_page(txp)
	{
		// color = al_map_rgb(0, 0, 0); <-- can't be called till allegro is initialized...
		// CUSTOM_VERTEX may be used statically before allegro is initialized.
		color.r = 0.0;
		color.g = 0.0;
		color.b = 0.0;
		color.a = 0.0;
	}
	
	CUSTOM_VERTEX(float x, float y, float z, float u, float v, Color c, float txp = 0) :
		pos(x, y, z), txcoord(u, v), tx_page(txp), color(c)
	{ }
};

#endif /* CUSTOMVERTEX_H_GUARD */
