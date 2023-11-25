#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	int shapenum = 0;
	int fillcolornum = 0;
	int colornum = 0;
	Output();		

	window* CreateWind(int, int, int, int) const;	//creates the application window
	void CreateDrawToolBar() const;					//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;					//creates Play mode toolbar & menu
	void CreateStatusBar() const;					//creates the status bar
	void CreateShapesToolBar() const;				//creates Shapes toolbar
	void CreateColorsToolBar() const;				//creates Colors toolbar
	void CreateFillColorsToolBar() const;			//creates Fill Colors toolbar
	void CreateFillColorsToolBarTAB()const;			//creates a changable icon for fill colors in draw mode toolbar
	void CreateColorsToolBarTAB() const;			//creates a changable icom for colors in draw mode toolbar
	void CreateShapesToolBarTAB() const;			//creates a changable icon for shapes in draw mode toolbar

	Input* CreateInput() const;		//creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;		//Clears the drawing area
	void ClearToolBar() const;		//Clears current toolbar
	
	// -- Figures Drawing functions
		// -- Figures Drawing functions
	//////////////////////////////////////////////  yousef ADEL _start ....
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a rectangle

	void DrawSq(Point P1, GfxInfo SqGfxInfo, bool selected = false) const;	//Draw a square

	void DrawTgl(Point P1, Point P2, Point P3, GfxInfo TglGfxInfo, bool selected = false) const;  //Draw a triangle

	void DrawHex(Point P1, GfxInfo HexGfxInfo, bool selected = false) const; //Draw a hexagon

	void DrawCir(Point P1, Point P2, GfxInfo CirGfxInfo, bool selected = false) const; //Draw a circle

	//////////////////////////////////////////////  yousef ADEL _end

	/////Make similar functions for drawing all other figure types.

	void PrintMessage(string msg) const;	//Print a message on Status bar


	
	~Output();
};

#endif