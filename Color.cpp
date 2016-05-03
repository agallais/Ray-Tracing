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
	blue = (int) blue * lvl;
	green = (int) green * lvl;
	red = (int) red * lvl;
}
