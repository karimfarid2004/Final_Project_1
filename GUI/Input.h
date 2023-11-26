#ifndef INPUT_H
#define INPUT_H

#include "..\DEFS.h"
#include "UI_Info.h" 
#include "..\CMUgraphicsLib\CMUgraphics.h"

class Output;   // forward declaration

class Input		//The application manager should have a pointer to this class
{
private:
	window *pWind;	//Pointer to the Graphics Window
	int lengthSq = 200;
	int lengthHexa = 100;
public:
	Input(window *pW);		//Consturctor
	void GetPointClicked(int &x, int &y) const;//Get coordinate where user clicks
	void CheckPointClicked(int a, Output* statusPo, Point & P, Point * P2=NULL ) const;		//second point with pointer we need to check one point in each time except circle
	void QuesPointClicked();

	string GetSrting(Output* pO, bool& msgent) const ;	 //Returns a string entered by the user

	ActionType GetUserAction() const; //Read the user click and map to an action

	~Input();
};

#endif
