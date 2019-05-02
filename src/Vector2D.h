#pragma once
class Vector2D
{
public:
	Vector2D(void);
	Vector2D(int inx, int iny); 
	~Vector2D(void);
	
	void operator += (Vector2D v2);
	void operator -= (Vector2D v2);
	Vector2D operator + (Vector2D v2);
	Vector2D operator - (Vector2D v2);
	Vector2D operator / (int n);
	Vector2D operator * (int n);
	bool operator == (Vector2D v);
	bool operator != (Vector2D v);

	int x;
	int y;

};

