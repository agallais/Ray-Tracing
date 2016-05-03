#pragma once
class Color
{
public:
	int blue;
	int green;
	int red;
	Color();
	Color(int bblue, int rred, int ggreen);
	~Color();
	void intensity(double lvl);

};

