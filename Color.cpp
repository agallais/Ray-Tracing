#include "Color.h"



Color::Color()
{
}

Color::Color(int bblue, int rred, int ggreen)
{
	blue = bblue;
	red = rred;
	green = ggreen;

}


Color::~Color()
{
}

void Color::intensity(double lvl)
{
	blue = (int)255 * lvl;
	green = (int)255 * lvl;
	red = (int)255 * lvl;
}
