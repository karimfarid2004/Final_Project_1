#include "Output.h"
#include <cmath>
#define PI 3.14159

Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 80;
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = WHITE;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
////////////////////////////////////////////	//////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	ClearToolBar();
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_SLCT] = "images\\MenuItems\\select.jpg";
	MenuItemImages[ITM_SHAPES] = "images\\MenuItems\\shapes.jpg";
	MenuItemImages[ITM_COLOR] = "images\\MenuItems\\Color_Wheel.jpg";
	MenuItemImages[ITM_FILL] = "images\\MenuItems\\Color_Fill.jpg";
	MenuItemImages[ITM_PLYMOD] = "images\\MenuItems\\Play_Mode.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\redo.jpg";
	MenuItemImages[ITM_DLET] = "images\\MenuItems\\delete.jpg";
	MenuItemImages[ITM_CLR] = "images\\MenuItems\\clear_all.jpg";
	MenuItemImages[ITM_REC] = "images\\MenuItems\\rec.jpg";
	MenuItemImages[ITM_END] = "images\\MenuItems\\stop.jpg";
	MenuItemImages[ITM_PLY] = "images\\MenuItems\\play.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\download.jpg";
	MenuItemImages[ITM_EXIT_DRAWMODE] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	
	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
	
	CreateShapesToolBarTAB();		// Displays the selected shape on the toolbar
	CreateColorsToolBarTAB();		// Displays the selected color on the toolbar
	CreateFillColorsToolBarTAB();   // Displays the selected filling color on the toolbar
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{	
	ClearToolBar();
	UI.InterfaceMode = MODE_PLAY;

	
	///TODO: write code to create Play mode menu
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_TYP_COLOR] ="images\\MenuItems\\Color_Wheel.jpg";
	MenuItemImages[ITM_TYP_SHAPE] ="images\\MenuItems\\shapes.jpg";
	MenuItemImages[ITM_TYP_BOTH] = "images\\MenuItems\\both.jpg";
	MenuItemImages[ITM_SWITCH]= "images\\MenuItems\\switch.jpg";
	MenuItemImages[ITM_EXIT_PLAYMODE] = "images\\MenuItems\\Menu_Exit.jpg";
	

	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	
	
	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateShapesToolBar() const
{
	ClearToolBar();
	UI.InterfaceMode = SHAPES_SELECTION;

	string MenuItemImages[SHAPES_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\ShapesItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_CIRC] = "images\\ShapesItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_TRI] = "images\\ShapesItems\\Menu_Tri.jpg";
	MenuItemImages[ITM_SQU] = "images\\ShapesItems\\Menu_Squ.jpg";
	MenuItemImages[ITM_HEX] = "images\\ShapesItems\\Menu_Hex.jpg";


	for (int i = 1; i < SHAPES_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], (i-1) * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);


	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
void Output::CreateColorsToolBar() const
{
	ClearToolBar();
	UI.InterfaceMode = COLOR_SELECTION;

	string MenuItemImages[COLOR_ITM_COUNT];
	MenuItemImages[ITM_BLACK] = "images\\ColorItems\\Black.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\ColorItems\\Yellow.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\ColorItems\\Orange.jpg";
	MenuItemImages[ITM_RED] = "images\\ColorItems\\Red.jpg";
	MenuItemImages[ITM_GREEN] = "images\\ColorItems\\Green.jpg";
	MenuItemImages[ITM_BLUE] = "images\\ColorItems\\Blue.jpg";


	for (int i = 1; i < COLOR_ITM_COUNT ; i++)
		pWind->DrawImage(MenuItemImages[i], (i-1) * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
void Output::CreateFillColorsToolBar() const
{
	ClearToolBar();
	UI.InterfaceMode = FILL_COLOR_SELECTION;

	string MenuItemImages[FILL_COLOR_ITM_COUNT];
	MenuItemImages[ITM_BLACK_FILL] = "images\\ColorItems\\Black.jpg";
	MenuItemImages[ITM_BLUE_FILL] = "images\\ColorItems\\Blue.jpg";
	MenuItemImages[ITM_GREEN_FILL] = "images\\ColorItems\\Green.jpg";
	MenuItemImages[ITM_ORANGE_FILL] = "images\\ColorItems\\Orange.jpg";
	MenuItemImages[ITM_RED_FILL] = "images\\ColorItems\\Red.jpg";
	MenuItemImages[ITM_YELLOW_FILL] = "images\\ColorItems\\Yellow.jpg";
	MenuItemImages[ITM_NO_FILL] = "images\\ColorItems\\No_Fill.jpg";

	for (int i = 0; i < FILL_COLOR_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i* UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
void Output::CreateShapesToolBarTAB() const
{
	UI.InterfaceMode = MODE_DRAW;

	string MenuItemImages[SHAPES_ITM_COUNT];
	MenuItemImages[ITM_SHAPE] = "images\\MenuItems\\shapes.jpg";
	MenuItemImages[ITM_RECT] = "images\\ShapesItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_CIRC] = "images\\ShapesItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_TRI] = "images\\ShapesItems\\Menu_Tri.jpg";
	MenuItemImages[ITM_HEX] = "images\\ShapesItems\\Menu_Hex.jpg";
	MenuItemImages[ITM_SQU] = "images\\ShapesItems\\Menu_Squ.jpg";


	pWind->DrawImage(MenuItemImages[shapenum], 1 * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
void Output::CreateColorsToolBarTAB() const
{
	UI.InterfaceMode = MODE_DRAW;

	string MenuItemImages[COLOR_ITM_COUNT];
	MenuItemImages[ITM_NONE] = "images\\ColorItems\\Color_Wheel_None.jpg";
	MenuItemImages[ITM_BLACK] = "images\\ColorItems\\Color_Wheel_Black.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\ColorItems\\Color_Wheel_Yellow.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\ColorItems\\Color_Wheel_Orange.jpg";
	MenuItemImages[ITM_RED] = "images\\ColorItems\\Color_Wheel_Red.jpg";
	MenuItemImages[ITM_GREEN] = "images\\ColorItems\\Color_Wheel_Green.jpg";
	MenuItemImages[ITM_BLUE] = "images\\ColorItems\\Color_Wheel_Blue.jpg";


		pWind->DrawImage(MenuItemImages[colornum], 2 * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
void Output::CreateFillColorsToolBarTAB() const
{
	UI.InterfaceMode = MODE_DRAW;

	string MenuItemImages[FILL_COLOR_ITM_COUNT];
	MenuItemImages[ITM_BLACK_FILL] = "images\\ColorItems\\Fill_Color_Black.jpg";
	MenuItemImages[ITM_BLUE_FILL] = "images\\ColorItems\\Fill_Color_Blue.jpg";
	MenuItemImages[ITM_GREEN_FILL] = "images\\ColorItems\\Fill_Color_Green.jpg";
	MenuItemImages[ITM_ORANGE_FILL] = "images\\ColorItems\\Fill_Color_Orange.jpg";
	MenuItemImages[ITM_RED_FILL] = "images\\ColorItems\\Fill_Color_Red.jpg";
	MenuItemImages[ITM_YELLOW_FILL] = "images\\ColorItems\\Fill_Color_Yellow.jpg";
	MenuItemImages[ITM_NO_FILL] = "images\\ColorItems\\Fill_Color_No_Fill.jpg";

	pWind->DrawImage(MenuItemImages[fillcolornum], 3 * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}
void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////
//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}


void Output::DrawSq(Point Ctr, GfxInfo SqGfxInfo, bool selected) const              //====================================//
                                                                                   //		Square Drawing Function  	 //
                                                                                  //====================================//
{
	color DrawingClr;                   // To determinate either the Square will be drawn Highlighted or Not
	if (selected)
		DrawingClr = UI.HighlightColor; //Square should be drawn highlighted
	else
		DrawingClr = SqGfxInfo.DrawClr;   // Square should be drawn with a certain color ( Not Highlighted)
	pWind->SetPen(DrawingClr, 1);        // Set the Pen Color by a certain color  (Highlighted or Not) and its Size
	drawstyle style;                     // To determinate either the Square will be drawn Fiiled or Framed
	if (SqGfxInfo.isFilled)
	{
		style = FILLED;                      //Square should be drawn filled
		pWind->SetBrush(SqGfxInfo.FillClr);  //Set the brush Color by a certain color (FillClr) if square is filled
	}
	else
		style = FRAME;                   // Square should be drawn Framed (Not Filled)
	int length = 200;
	Point P1, P2;
		P1.x = Ctr.x - length / 2;
		P1.y = Ctr.y - length / 2;        // set the X coordinates and Y coordinates of the two points of square 
		P2.x = Ctr.x + length / 2;
		P2.y = Ctr.y + length / 2;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);  /*Call the included function DrawRectangle in CMUgraphicsLib to draw the Square
		                                                  by sending(X coordinate of First point, Y coordinate of First point,
														  X coordinate of Second point, Y coordinate of Second point,The style of drawing(Filled or Framed))*/
		                                                      									
}


void Output::DrawTgl(Point P1, Point P2, Point P3, GfxInfo TglGfxInfo, bool selected) const       //====================================//
                                                                                                 //		Triangle Drawing Function  	   //
                                                                                                //====================================//
{
	color DrawingClr;                     // To determinate either the Triangle will be drawn Highlighted or Not
	if (selected)
		DrawingClr = UI.HighlightColor;  //Triangle should be drawn highlighted
	else
		DrawingClr = TglGfxInfo.DrawClr; // Triangle should be drawn with a certain color ( Not Highlighted)
	pWind->SetPen(DrawingClr, 1);         // Set the Pen Color by a certain color (Highlighted or Not)  and its Size
	drawstyle style;              // To determinate either the Triangle will be drawn Fiiled or Framed
	if (TglGfxInfo.isFilled)
	{
		style = FILLED;                       //Triangle should be drawn filled
		pWind->SetBrush(TglGfxInfo.FillClr);  //Set the brush Color by a certain color (FillClr) if Triangle is filled
	}
	else
		style = FRAME;        // Triangle should be drawn Framed (Not Filled)
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);          /* Call the included function DrawTriangle in CMUgraphicsLib to draw the Triangle
	                                                                          by sending(X coordinate of First point ,Y coordinate of First point,X coordinate of Second point ,Y coordinate of Second point
																			    X coordinate of Third point ,Y coordinate of Third point,The style of drawing(Filled or Framed)) */

}

void Output::DrawHex(Point Ctr, GfxInfo HexGfxInfo, bool selected) const           //====================================//
                                                                                  //		Hexagon Drawing Function    //
                                                                                 //====================================//
{
	color DrawingClr;                    // To determinate either the Hexagon will be drawn Highlighted or Not
	if (selected)
		DrawingClr = UI.HighlightColor;  //Hexagon should be drawn highlighted
	else
		DrawingClr = HexGfxInfo.DrawClr;       // Hexagon should be drawn with a certain color ( Not Highlighted)
	pWind->SetPen(DrawingClr, 1);          // Set the Pen Color by a certain color (Highlighted or Not) and its Size
	drawstyle style;                      // To determinate either the Hexagon will be drawn Fiiled or Framed
	if (HexGfxInfo.isFilled)
	{
		style = FILLED;                       //Hexagon should be drawn filled
		pWind->SetBrush(HexGfxInfo.FillClr);  //Set the brush Color by a certain color (FillClr) if Hexagon is filled
	}
	else
		style = FRAME;                // Hexagon should be drawn Framed (Not Filled)
	int vertices = 6;                // Number of vertices in Hexagon
	int length = 100;               // Length of Hexagon
	int* Px = new int[vertices];   // Array of X coordinate of Hexagon points
	int* Py = new int[vertices];   // Array of Y coordinate of Hexagon points

	for (int i = 0; i < vertices; i++)
	{
		Px[i] = Ctr.x + length * cos((i) * (PI / 3));  //Set the value of Array of X coordinate of Hexagon points ....NOTE: The angle between two consecutive points is PI / 3
		Py[i] = Ctr.y - length * sin((i) * (PI / 3));  //Set the value of Array of Y coordinate of Hexagon points ....NOTE: The angle between two consecutive points is PI / 3
	}

	pWind->DrawPolygon(Px, Py, vertices, style);           /* Call the included function DrawPolygon in CMUgraphicsLib to draw the Hexagon
	                                                       by sending(Array of x coordinate, Array of y coordinate, Number of vertices, The style of drawing(Filled or Framed)) */
	delete[]Px;       // Deallocate memory location       
	delete[]Py;
	Px = NULL;       // Good practise to set the pointer to NULL
	Py = NULL;

}
void Output::DrawCir(Point Ctr, Point P2, GfxInfo CirGfxInfo, bool selected) const           //====================================//
                                                                                            //		Circle Drawing Function       //
                                                                                           //====================================//
{ 
	color DrawingClr;                    // To determinate either the Circle will be drawn Highlighted or Not
	if (selected)
		DrawingClr = UI.HighlightColor;  // Circle  should be drawn highlighted
	else
		DrawingClr = CirGfxInfo.DrawClr;  // Circle should be drawn with a certain color ( Not Highlighted)
	pWind->SetPen(DrawingClr, 1);         // Set the Pen color by a certain color  (Highlighted or Not) and its Size
	drawstyle style;                      // To determinate either the Circle will be drawn Fiiled or Framed
	if (CirGfxInfo.isFilled)
	{
		style = FILLED;                        // Circle should be drawn filled
		pWind->SetBrush(CirGfxInfo.FillClr);  //Set the brush Color by a certain color (FillClr) if Circle is filled 
	}
	else
		style = FRAME;                         // Circle should be drawn Framed (Not Filled)
	int Radius = sqrt(pow((P2.x - Ctr.x), 2) + pow((P2.y - Ctr.y), 2));  // Calculate the radius of the Circle
	pWind->DrawCircle(Ctr.x, Ctr.y, 1, style);          // determinate the centre point

	pWind->DrawCircle(Ctr.x, Ctr.y, Radius, style);      /*Call the included function DrawCircle in CMUgraphicsLib to draw the Circle
														   by sending (X coordinate of centre point ,Y coordinate of centre point,Radius of the Circle,The style of drawing(Filled or Framed))*/

}
//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

