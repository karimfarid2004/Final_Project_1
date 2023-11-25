#include "Input.h"
#include "Output.h"
#define PI 3.14159

Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}
void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}
void Input::CheckPointClicked(int a, Point & P1 ,Point * P2) const
{
	switch (a)
	{
	case 0:
	{
		while (P1.y < UI.ToolBarHeight)
		{
			GetPointClicked(P1.x, P1.y);
		}
	}
		break;
	case 1:
	{
		while (P1.y - length1/2 < UI.ToolBarHeight)
		{
			GetPointClicked(P1.x, P1.y);
		}
	}
		break;
	case 2:
		while (P1.y  - length2 * cos((PI / 6)) < UI.ToolBarHeight)
		{
			GetPointClicked(P1.x, P1.y);
		}
		break;
	case 3:

		while (P1.y - UI.ToolBarHeight< sqrt(pow((P2->x - P1.x), 2) + pow((P2->y - P1.y), 2)))
		{
			GetPointClicked(P2->x, P2->y);
		}
		break;
	
	}

}

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	string entered = "You Entered ";
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
		{
			string str = entered + Label;
			return str;
		}
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_SLCT: return SELECT;
			case ITM_SHAPES: return TO_ShapesToolBar;
			case ITM_PLYMOD: return TO_PLAY;
			case ITM_COLOR: return TO_COLOR;
			case ITM_FILL: return TO_FILL;
			case ITM_UNDO: return UNDO;
			case ITM_REDO: return REDO;
			case ITM_DLET: return DEL;
			case ITM_CLR: return CLEAR;
			case ITM_REC: return RECVID;
			case ITM_END: return ENDVID;
			case ITM_PLY: return PLYVID;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_EXIT_DRAWMODE: return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_PLAY)	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);

			switch (ClickedItemOrder) {

			case ITM_SWITCH:return TO_DRAW;
			case ITM_TYP_COLOR:return PLAYCOLOR;
			case ITM_TYP_SHAPE:return PLAYSHAPE;
			case ITM_TYP_BOTH:return PLAYBOTH;
			case ITM_EXIT_PLAYMODE:return EXIT;

			default: return EMPTY;
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		return STATUS;
	}
	else if (UI.InterfaceMode == COLOR_SELECTION) //GUI is in Color Selection
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth) + 1;

			switch (ClickedItemOrder) {

			case ITM_BLACK:return SELECT_BLACK;
			case ITM_BLUE:return SELECT_BLUE;
			case ITM_GREEN:return SELECT_GREEN;
			case ITM_ORANGE:return SELECT_ORANGE;
			case ITM_RED:return SELECT_RED;
			case ITM_YELLOW:return SELECT_YELLOW;

			default: return EMPTY;

			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		return STATUS;
	}
	else if (UI.InterfaceMode == FILL_COLOR_SELECTION) //GUI is in Fill Color Selection
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth) ;



			switch (ClickedItemOrder) {

			case ITM_BLACK:return SELECT_BLACK_FILL;
			case ITM_BLUE:return SELECT_BLUE_FILL;
			case ITM_GREEN:return SELECT_GREEN_FILL;
			case ITM_ORANGE:return SELECT_ORANGE_FILL;
			case ITM_RED:return SELECT_RED_FILL;
			case ITM_YELLOW:return SELECT_YELLOW_FILL;
			case ITM_NO_FILL:return SELECT_NO_FILL;

			default: return EMPTY;
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		return STATUS;
			
	}
	else if (UI.InterfaceMode == SHAPES_SELECTION) //GUI is in Shapes Selection
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth) + 1;

			switch (ClickedItemOrder) {
			case ITM_RECT:return DRAW_RECT;
			case ITM_CIRC:return DRAW_CIRCLE;
			case ITM_TRI:return DRAW_TRIANGLE;
			case ITM_HEX:return DRAW_HEXAGON;
			case ITM_SQU:return DRAW_SQUARE;

			default: return EMPTY;

			}

		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		return STATUS;
		
	}
}
	
Input::~Input(){}
