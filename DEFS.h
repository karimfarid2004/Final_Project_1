#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	SELECT,
	TO_ShapesToolBar,
	DRAW_RECT,			//Draw Rectangle
	DRAW_SQUARE,		//Draw Rectangle		
	DRAW_CIRCLE,		//Draw Circle
	DRAW_TRIANGLE,		//Draw Triangle
	DRAW_HEXAGON,		//Draw Hexagon
	EXIT,				//Exit
	TO_DRAW,			//Switch interface to Draw mode
	TO_PLAY,			//Switch interface to Play mode
	TO_COLOR,			//To select the colors
	TO_FILL,			//To select the fill colors
	UNDO,				//Select undo
	REDO,				//Select redo
	DEL,				//Select delete figure
	CLEAR,				//Clear all figures
	RECVID,				//Start recording video
	ENDVID,				//End recording video
	PLYVID,				//Play video
	SAVE,				//Save the file
	LOAD,				//Load saved files
	PLAYCOLOR,			//Select color to play with
	PLAYSHAPE,			//Select the shape to play with
	PLAYBOTH,			//Select both colors and shapes to play with
	EMPTY,				//A click on empty place in the toolbar
	DRAWING_AREA,		//A click on the drawing area
	STATUS,				//A click on the status bar
	SELECT_BLACK,		//Selecting the color black
	SELECT_BLUE,		//Selecting the color blue
	SELECT_GREEN,		//Selecting the color green
	SELECT_ORANGE,		//Selecting the color orange
	SELECT_RED,			//Selecting the color red
	SELECT_YELLOW,		//Selecting the color yellow
	SELECT_BLACK_FILL,	//Selecting the fiil color black
	SELECT_BLUE_FILL,	//Selecting the fill color blue
	SELECT_GREEN_FILL,	//Selecting the fill color green
	SELECT_ORANGE_FILL,	//Selecting the fill color orange
	SELECT_RED_FILL,	//Selecting the fill color red
	SELECT_YELLOW_FILL,	//Selecting the fill color yellow
	SELECT_NO_FILL		//Selecting the no fill

	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif