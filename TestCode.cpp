#include "GUI\Input.h"
#include "GUI\Output.h"

//This is a test code to test the Input and Output classes

int main()
{
	int x, y;
	Output* pOut = new Output();
	Input* pIn = pOut->CreateInput();

	//Starting the test
	pOut->PrintMessage("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	
	//			Create The FULL Tool bar, the drawing area and the status bar	
	//			This has already been done through the constructor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	
	//			Drawing all the Figures with all possible states: 
	//			Non-filled, Filled, and highlighted in both cases			
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST2: Now we will show that Output class can draw any figure in any state, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	GfxInfo gfxInfo;	//to be used with draw function of the class Ouput
	Point P1, P2, P3;

	/// =============================2.1- Rectangle Test============================== ///
	/// ============================================================================== ///

	pOut->PrintMessage("Drawing a Rectangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue"); // print a message in status bar
	pIn->GetPointClicked(x, y);                       //Wait for any click to start Rectangle test

	// 2.1.1 - Drawing non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> non-filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);                 // Take the first point from the user
	pIn->CheckPointClicked(ITM_RECT, pOut, P1);       // Check the first point if it's Valid (Inside the Drawing Area and not to draw on the tool bar) or Not 
	pOut->DrawPoint(P1.x, P1.y);					  // Show the vertices of the figure 
	pIn->GetPointClicked(P2.x, P2.y);                 // Take the second point from the user
	pIn->CheckPointClicked(ITM_RECT, pOut, P2);       // Check the second point if it's Valid (Inside the Drawing Area and not to draw on the tool bar) or Not 
	pOut->DrawPoint(P2.x, P2.y);				

	gfxInfo.BorderWdth = 5;                           //Set the width of Figure (Rectangle) borders
	gfxInfo.DrawClr = BLACK;	                      //Select the color of the Figure (Rectangle) borders
	gfxInfo.isFilled = false;	                      //Figure (Rectangle) is NOT filled (Framed)
	pOut->DrawRect(P1, P2, gfxInfo, false);	 /*Call the drawing function (DrawRect) in output class
											   by sending(The first point, The second point, Information about color and if Rectangle is filled or not ,
												 To know if Rectangle is selected(To highlight it) or not (false which means it's not selected))*/

	// 2.1.2 - Drawing highlighted non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);				          // Wait for any click from the user to Highlight the non-filled Rectangle
	pOut->DrawRect(P1, P2, gfxInfo, true);            // now the fourth parameter is true because it's Highlighted

	// 2.1.3 - Drawing a filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->CheckPointClicked(ITM_RECT, pOut, P1);
	pOut->DrawPoint(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->CheckPointClicked(ITM_RECT, pOut, P2);
	pOut->DrawPoint(P2.x, P2.y);
	gfxInfo.BorderWdth = 6;			                  
	gfxInfo.DrawClr = BLUE;			                  
	gfxInfo.FillClr = GREEN;		                  //Select the fill color of the Figure (Rectangle)
	gfxInfo.isFilled = true;		                  //Figure (Rectangle) is filled
	pOut->DrawRect(P1, P2, gfxInfo, false);           // now the fourth parameter is false because it's not Highlighted

	// 2.1.4 - Drawing a highlighted filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);					      // Wait for any click from the user to Highlight the filled Rectangle
	pOut->DrawRect(P1, P2, gfxInfo, true);		     

	pOut->PrintMessage("Drawing a Rectangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	                      //Wait for any click to finish the Rectangle test
	pOut->ClearDrawArea();                            // Clear the drawing area to draw the next test

	/// =============================2.2- Square Test============================== ///
	/// =========================================================================== ///

	pOut->PrintMessage("Drawing a Square, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	                      //Wait for any click to start Square test

	// 2.2.1 - Drawing non-filled square
	pOut->PrintMessage("Drawing a Square ==> non-filled,  Click one point");
	pIn->GetPointClicked(P1.x,P1.y);                  // Take the point (Centre) from the user
	pIn->CheckPointClicked(ITM_SQU, pOut, P1);        // Check the point (Centre) if it's Valid (Inside the Drawing Area and not to draw on the tool bar) or Not
	pOut->DrawPoint(P1.x, P1.y);					  // Show the Centre of the square

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;
	gfxInfo.isFilled = false;
	pOut->DrawSq(P1, gfxInfo, false);   /*Call the drawing function (DrawSq) in output class
										  by sending(The point(Centre),Information about color and if Square is filled or not ,
											  To know if square is selected(To highlight it) or not (false which means it's not selected))*/

	// 2.2.2 - Drawing highlighted non-filled square
	pOut->PrintMessage("Drawing a Square ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);                       // Wait for any click from the user to Highlight the non-filled Square
	pOut->DrawSq(P1, gfxInfo, true);

	// 2.2.3 - Drawing a filled square
	pOut->PrintMessage("Drawing a Square ==> filled,  Click one point");
	pIn->GetPointClicked(P1.x, P1.y);                 
	pIn->CheckPointClicked(ITM_SQU, pOut, P1);        				  

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;
	gfxInfo.FillClr = GREEN;
	gfxInfo.isFilled = true;
	pOut->DrawSq(P1, gfxInfo, false);


	// 2.2.4 - Drawing a highlighted filled square
	pOut->PrintMessage("Drawing a Square ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);                       // Wait for any click from the user to Highlight the filled Square
	pOut->DrawSq(P1, gfxInfo, true);


	pOut->PrintMessage("Drawing a Square Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	                      //Wait for any click to finish Square test
	pOut->ClearDrawArea();                            // Clear the drawing area to draw the next test

	/// =============================2.3- Triangle Test============================== ///
	/// ============================================================================= ///

	pOut->PrintMessage("Drawing a Triangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	                      //Wait for any click to start Triangle test

	// 2.3.1 - Drawing non-filled triangle
	pOut->PrintMessage("Drawing a Triangle ==> non-filled,  Click three points");    
	pIn->GetPointClicked(P1.x, P1.y);                 // Take the first point from the user
	pIn->CheckPointClicked(ITM_TRI, pOut, P1);        // Check the first point if it's Valid (Inside the Drawing Area) or Not
	pOut->DrawPoint(P1.x, P1.y);					  	
	pIn->GetPointClicked(P2.x, P2.y);                 // Take the second point from the user
	pIn->CheckPointClicked(ITM_TRI, pOut, P2);        // Check the second point if it's Valid (Inside the Drawing Area) or Not
	pOut->DrawPoint(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);                 // Take the third point from the user
	pIn->CheckPointClicked(ITM_TRI, pOut, P3);        // Check the third point if it's Valid (Inside the Drawing Area) or Not
	pOut->DrawPoint(P3.x, P3.y);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;
	gfxInfo.isFilled = false;
	pOut->DrawTgl(P1, P2, P3, gfxInfo, false);  /*Call the drawing function (DrawTgl) in output class
												  by sending(The first point,The second point,The third point,Information about color and if Triangle is filled or not,
												   To know if Triangle is selected(To highlight it) or not (false which means it's not selected))*/

	// 2.3.2 - Drawing highlighted non-filled triangle
	pOut->PrintMessage("Drawing a Triangle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);                       // Wait for any click from the user to Highlight the non-filled Triangle
	pOut->DrawTgl(P1, P2, P3, gfxInfo, true);


	// 2.3.3 - Drawing a filled triangle

	pOut->PrintMessage("Drawing a Triangle ==> filled,  Click three points");    
	pIn->GetPointClicked(P1.x, P1.y);                
	pIn->CheckPointClicked(ITM_TRI, pOut, P1);       
	pOut->DrawPoint(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);                 
	pIn->CheckPointClicked(ITM_TRI, pOut, P2);        
	pOut->DrawPoint(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);                 
	pIn->CheckPointClicked(ITM_TRI, pOut, P3);        
	pOut->DrawPoint(P3.x, P3.y);

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;
	gfxInfo.FillClr = GREEN;
	gfxInfo.isFilled = true;
	pOut->DrawTgl(P1, P2, P3, gfxInfo, false);


	// 2.3.4 - Drawing a highlighted filled triangle
	pOut->PrintMessage("Drawing a Triangle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);                       // Wait for any click from the user to Highlight the filled Triangle
	pOut->DrawTgl(P1, P2, P3, gfxInfo, true);



	pOut->PrintMessage("Drawing a Triangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	                      // Wait for any click to finish Triangle test
	pOut->ClearDrawArea();                            // Clear the drawing area to draw the next test

	/// =============================2.4- Hexagon Test============================== ///
	/// ============================================================================ ///

	pOut->PrintMessage("Drawing a Hexagon, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);                       //Wait for any click to start Hexagon test

	// 2.4.1 - Drawing non-filled hexagon
	pOut->PrintMessage("Drawing a Hexagon ==> non-filled,  Click one point");
	pIn->GetPointClicked(P1.x, P1.y);                 // Take the point (Centre) from the user
	pIn->CheckPointClicked(ITM_HEX, pOut, P1);        // Check the point (Centre) if it's Valid (Inside the Drawing Area and not to draw on the tool bar) or Not
	pOut->DrawPoint(P1.x, P1.y);					  // Show the Centre of the Hexagon
	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;
	gfxInfo.isFilled = false;
	pOut->DrawHex(P1, gfxInfo, false);  /*Call the drawing function(DrawHex) in output class
										  by sending(The point(Centre),Information about color and if Hexagon is filled or not ,
											To know if Hexagon is selected(To highlight it) or not (false which means it's not selected))*/

	// 2.4.2 - Drawing highlighted non-filled hexagon
	pOut->PrintMessage("Drawing a Hexagon ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);                       // Wait for any click from the user to Highlight the non-filled Hexagon
	pOut->DrawHex(P1, gfxInfo, true);


	// 2.4.3 - Drawing a filled hexagon
	pOut->PrintMessage("Drawing a Hexagon ==> filled,  Click one point");
	pIn->GetPointClicked(P1.x, P1.y);                
	pIn->CheckPointClicked(ITM_HEX, pOut, P1);       

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;
	gfxInfo.FillClr = GREEN;
	gfxInfo.isFilled = true;
	pOut->DrawHex(P1, gfxInfo, false);


	// 2.4.4 - Drawing a highlighted filled hexagon
	pOut->PrintMessage("Drawing a Hexagon ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);                       // Wait for any click from the user to Highlight the filled Hexagon
	pOut->DrawHex(P1, gfxInfo, true);                 


	pOut->PrintMessage("Drawing a Hexagon Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	                      //Wait for any click to finish Hexagon test
	pOut->ClearDrawArea();                            // Clear the drawing area to draw the next test

	///// =============================2.5- Circle Test=============================== ///
	/// ============================================================================ ///

	pOut->PrintMessage("Drawing an Circle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x, y);	                      //Wait for any click to start Circle test

	// 2.5.1 - Drawing non-filled circle
	pOut->PrintMessage("Drawing a Circle ==> non-filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);                 // Take the first point (Centre) from the user
	pIn->CheckPointClicked(ITM_CIRC, pOut, P1, &P1);  // check the Centre point (not to draw on the tool bar)
	pOut->DrawPoint(P1.x, P1.y);				      // To draw the Centre point to be able to determinate the radius much easier
	pIn->GetPointClicked(P2.x, P2.y);                 // Take the second point from the user
	pIn->CheckPointClicked(ITM_CIRC,pOut ,P1, &P2);   // Check the points if they are Valid ( not to draw on the tool bar) or Not
	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;
	gfxInfo.isFilled = false;
	pOut->DrawCir(P1, P2, gfxInfo, false);  /*Call the drawing function (DrawCir) in output class
											 by sending(The first point (Centre),the second point,Information about color and if Circle is filled or not ,
											  To know if Circle is selected(To highlight it) or not (false which means it's not selected))*/

	// 2.5.2 - Drawing highlighted non-filled circle
	pOut->PrintMessage("Drawing a Circle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);                       // Wait for any click from the user to Highlight the non-filled Circle
	pOut->DrawCir(P1, P2, gfxInfo, true);


	// 2.5.3 - Drawing a filled circle
	pOut->PrintMessage("Drawing a Circle ==> filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);                 // Take the first point (Centre) from the user
	pIn->CheckPointClicked(ITM_CIRC, pOut, P1, &P1);  // check the Centre point (not to draw on the tool bar)
	pOut->DrawPoint(P1.x, P1.y);				      // To draw the Centre point to be able to determinate the radius much easier
	pIn->GetPointClicked(P2.x, P2.y);                 // Take the second point from the user
	pIn->CheckPointClicked(ITM_CIRC, pOut, P1, &P2);  // Check the points if they are Valid ( not to draw on the tool bar) or Not

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;
	gfxInfo.FillClr = GREEN;
	gfxInfo.isFilled = true;
	pOut->DrawCir(P1, P2, gfxInfo, false);


	// 2.5.4 - Drawing a highlighted filled circle
	pOut->PrintMessage("Drawing a Circle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);                       // Wait for any click from the user to Highlight the filled Circle
	pOut->DrawCir(P1, P2, gfxInfo, true);



	pOut->PrintMessage("Drawing a Circle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	                      //Wait for any click to finish Circle test
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3:
	//			Input Class: Read strings from the user
	///////////////////////////////////////////////////////////////////////////////////
	string message;

	pOut->PrintMessage("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	pOut->PrintMessage("Testing Input ability to read strings");

	pIn->QuesKeyClicked();

	pOut->PrintMessage("Enter a message:");
	message = pIn->GetString(pOut);
	pOut->PrintMessage(message);

	pIn->QuesPointClicked();

	pOut->PrintMessage("You Entered " + message);
	pIn->GetPointClicked(x, y);


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4:
	//			Input Class : Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST4: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;


	do
	{
		ActType = pIn->GetUserAction();

		switch (ActType)
		{
		case SELECT:
			pOut->PrintMessage("You have selected the Select Option");
			break;
		case TO_ShapesToolBar:
			pOut->PrintMessage("Action: Switch to shapes tool bar, creating Design tool bar");
			pOut->CreateShapesToolBar();
			break;
		case DRAW_RECT:
			pOut->ClearPopUp();
			pOut->PrintMessage("Action: Draw a Rectangle , Click anywhere");
			pOut->CreateShapesToolBarTAB();
			pOut->shapenum = 1;
			pOut->CreateShapesToolBarTAB();
			break;
		case DRAW_CIRCLE:
			pOut->ClearPopUp();
			pOut->PrintMessage("Action: Draw a Circle , Click anywhere");
			pOut->CreateShapesToolBarTAB();
			pOut->shapenum = 2;
			pOut->CreateShapesToolBarTAB();
			break;
		case DRAW_TRIANGLE:
			pOut->ClearPopUp();
			pOut->PrintMessage("Action: Draw a Triangle , Click anywhere");
			pOut->CreateShapesToolBarTAB();
			pOut->shapenum = 3;
			pOut->CreateShapesToolBarTAB();
			break;
		case DRAW_HEXAGON:
			pOut->ClearPopUp();
			pOut->PrintMessage("Action: Draw a Hexagon , Click anywhere");
			pOut->CreateShapesToolBarTAB();
			pOut->shapenum = 4;
			pOut->CreateShapesToolBarTAB();
			break;
		case DRAW_SQUARE:
			pOut->ClearPopUp();
			pOut->PrintMessage("Action: Draw a Square , Click anywhere");
			pOut->CreateShapesToolBarTAB();
			pOut->shapenum =5;
			pOut->CreateShapesToolBarTAB();
			break;
		case STATUS:
			pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
			break; 
		case TOOLBAR:
				pOut->PrintMessage("Action: a click on the ToolBar, Click anywhere");
				break;

		case DRAWING_AREA:
			pOut->PrintMessage("Action: a click on the Drawing Area, Click anywhere");
			break;

		case EMPTY:
			pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
			
			break;

		case TO_DRAW:
			pOut->ClearToolBar();
			pOut->PrintMessage("Action: Switch to Draw Mode, creating simulation tool bar");
			pOut->CreateDrawToolBar();
			break;

		case TO_PLAY:
			pOut->ClearToolBar();
			pOut->PrintMessage("Action: Switch to Play Mode, creating Design tool bar");
			pOut->CreatePlayToolBar();
			break;
		case PLAYBOTH:
			pOut->PrintMessage("Action: Play Color-Shape Game");
			break;
		case PLAYCOLOR:
			pOut->PrintMessage("Action: Play-Color Game ");
			break;
		case PLAYSHAPE:
			pOut->PrintMessage("Action: Play-Shape Game");
			break;
		case TO_COLOR:
			pOut->PrintMessage("Action: Switch to Color toolbar, creating Design tool bar");
			pOut->CreateColorsToolBar();
			break;
		case SELECT_BLACK:
			pOut->ClearPopUp();
			pOut->PrintMessage("You have selected the color black");
			pOut->CreateColorsToolBarTAB();
			pOut->colornum = 1;
			pOut->CreateColorsToolBarTAB();
			break;
		case SELECT_BLUE:
			pOut->ClearPopUp();
			pOut->PrintMessage("You have selected the color blue");
			pOut->CreateColorsToolBarTAB();
			pOut->colornum = 2;
			pOut->CreateColorsToolBarTAB();
			break;
		case SELECT_GREEN:
			pOut->ClearPopUp();
			pOut->PrintMessage("You have selected the color green");
			pOut->CreateColorsToolBarTAB();
			pOut->colornum = 3;
			pOut->CreateColorsToolBarTAB();
			break;
		case SELECT_ORANGE:
			pOut->ClearPopUp();
			pOut->PrintMessage("You have selected the color orange");
			pOut->CreateColorsToolBarTAB();
			pOut->colornum = 4;
			pOut->CreateColorsToolBarTAB();
			break;
		case SELECT_RED:
			pOut->ClearPopUp();
			pOut->PrintMessage("You have selected the color red");
			pOut->CreateColorsToolBarTAB();
			pOut->colornum = 5;
			pOut->CreateColorsToolBarTAB();
			break;
		case SELECT_YELLOW:
			pOut->ClearPopUp();
			pOut->PrintMessage("You have selected the color yellow");
			pOut->CreateColorsToolBarTAB();
			pOut->colornum = 6;
			pOut->CreateColorsToolBarTAB();
			break;
		case TO_FILL:
			pOut->PrintMessage("Action: Switch to Fill toolbar, creating Design tool bar");
			pOut->CreateFillColorsToolBar();
			break;
		case SELECT_NO_FILL:
			pOut->ClearPopUp();
			pOut->PrintMessage("You have selected no fill");
			pOut->CreateFillColorsToolBarTAB();
			pOut->fillcolornum = 0;
			pOut->CreateFillColorsToolBarTAB();
			break;
		case SELECT_BLACK_FILL:
			pOut->ClearPopUp();
			pOut->PrintMessage("You have selected the color black for fill");
			pOut->CreateFillColorsToolBarTAB();
			pOut->fillcolornum = 1;
			pOut->CreateFillColorsToolBarTAB();
			break;
		case SELECT_BLUE_FILL:
			pOut->ClearPopUp();
			pOut->PrintMessage("You have selected the color blue for fill");
			pOut->CreateFillColorsToolBarTAB();
			pOut->fillcolornum = 2;
			pOut->CreateFillColorsToolBarTAB();
			break;
		case SELECT_GREEN_FILL:
			pOut->ClearPopUp();
			pOut->PrintMessage("You have selected the color green for fill");
			pOut->CreateFillColorsToolBarTAB();
			pOut->fillcolornum = 3;
			pOut->CreateFillColorsToolBarTAB();
			break;
		case SELECT_ORANGE_FILL:
			pOut->ClearPopUp();
			pOut->PrintMessage("You have selected the color orange for fill");
			pOut->CreateFillColorsToolBarTAB();
			pOut->fillcolornum = 4;
			pOut->CreateFillColorsToolBarTAB();
			break;
		case SELECT_RED_FILL:
			pOut->ClearPopUp();
			pOut->PrintMessage("You have selected the color red for fill");
			pOut->CreateFillColorsToolBarTAB();
			pOut->fillcolornum = 5;
			pOut->CreateFillColorsToolBarTAB();
			break;
		case SELECT_YELLOW_FILL:
			pOut->ClearPopUp();
			pOut->PrintMessage("You have selected the color yellow for fill");
			pOut->CreateFillColorsToolBarTAB();
			pOut->fillcolornum = 6;
			pOut->CreateFillColorsToolBarTAB();
			break;
		case UNDO:
			pOut->PrintMessage("You have selected undo");
			break;
		case REDO:
			pOut->PrintMessage("You have selected redo");
			break;
		case DEL:
			pOut->PrintMessage("You have selected delete a figure");
			break;
		case CLEAR:
			pOut->PrintMessage("You have selected clear all");
			break;
		case RECVID:
			pOut->PrintMessage("You have selected recording video");
			break;
		case ENDVID:
			pOut->PrintMessage("You have selected end recording");
			break;
		case PLYVID:
			pOut->PrintMessage("You have selected play recorded video");
			break;
		case SAVE:
			pOut->PrintMessage("You have selected save video");
			break;
		case LOAD:
			pOut->PrintMessage("You have selected load saved video");
			break;
		case EXIT:
				break;
		}
	}while(ActType != EXIT);


	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x,y);


	delete pIn;
	delete pOut;
	return 0;
}


