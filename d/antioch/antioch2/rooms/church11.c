#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
	::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_short("%^BOLD%^Room of the advanced acolytes");
	set_long(
	"This is a well kept room that belongs to the advanced acolytes. In the"+
	" far left and right corners of the room are bunk beds, one set in each corner."+
	" The bunk beds look rather cozy, however, with fluffy white blankets and"+
	" thick pillows. Across from each bunk bed is a mahogany dresser that you"+
	" can hang clothes in and store other items. The floor is carpeted with a"+
	" thick sky blue rug. In the center of the room is a pair of desks that"+
	" are back to back. The desks are kept very neat with writing paper and"+
	" ink quills stacked in piles. A thick candle in a pewter holder sits"+
	" towards the back of each desk. The candle holder catches all the wax"+
	" that would otherwise drip all over the desk. On the back wall of the"+
	" room are two book shelves, one placed near each bunk bed. In the center"+
	" of the far wall is a painting. The painting shows a pleasant scene of a"+
	" summer picnic. People have gathered together on top of a hill and there"+
	" are tables piled high with delicious foods. Everyone is happy and having"+
	" a good time."
	);
	set_smell("default","The scent of spiced apples drifts in from beneath"+
	" the door.");
	set_listen("default","The room is completely silent.");
	set_items(([
	({"floor","carpet","blue carpet","sky blue carpet","rug"}) : "%^BOLD%^%^CYAN%^A"+
 	" thick sky blue carpet covers the floor of the room. It is kept very"+
	" clean and gives the room a calm feeling.",
	"ceiling" : "The ceiling is flat and made of stones.",
	({"bed","bunk bed","bunk beds","beds"}) : "There are two sets of bunk beds"+
	" here, one in either corner of the room. They are a little larger than"+
	" normal bunk beds and look to be quite comfortable. Fluffy white blankets"+
	" cover the beds along with thick pillows.",
	({"covers","blankets","bed spreads","fluffy covers","fluffy blankets"}) : "%^BOLD%^These"+
	" comfortable looking blankets are folded neatly on top of the bunk beds."+
	" They look like they would be very warm and soft.",
	({"pillow","pillows"}) : "Each bed has a thick pillow to fall asleep on.",
	({"dresser","dressers","mahogany dresser","mahogany dressers"}) : "Across"+
	" from the foot of each bunk bed is a mahogany dresser. There is a mirror"+
	" on the front of each dresser and the doors open up to allow a place for"+
	" hanging garments. There are drawers at the bottom as well to place other"+
	" personal belongings in.",
	({"desk","desks"}) : "In the center of the room are two desks that have"+
	" been placed back to back to conserve space. The desks are kept quite"+
	" orderly with neat stacks of paper and writing quills. There are no"+
	" stains on the top of the desks and a large candle in a pewter holder"+
	" sits towards the back of each desk. The candle holder catches all the"+
	" wax that would otherwise spill onto the desk.",
	"candle" : "Two large blue candles sit on top of each desk. The acolytes"+
	" light them when they need to study.",
	"candle holder" : "This pewter candle holder is rather ordinary. It catches"+
	" the wax that drips down the sides of the candles so it doesn't spill onto"+
	" the desk.",
	"paper" : "Neat stacks of paper can be found on top of the desk.",
	({"quill","quills","writing quills","ink quills"}) : "Quills used for"+
	" writing can be found carefully placed on the desk tops so that the ink"+
	" doesn't spill out.",
	({"book shelf","book shelves"}) : "There are two book shelves on the back"+
	" wall of the room, spaced out from eachother to leave a gap in the middle."+
	" They are filled with volumes of ancient writings and scrolls, copies of"+
	" sacred tomes and instructional books. They are kept very well organized"+
	" and there doesn't appear to be a book out of place.",
	({"books","scrolls","texts","tomes"}) : "Numerous books and scrolls are"+
	" stacked neatly on the book shelves. They appear to be kept in very good"+
	" shape.",
	({"painting","picture","portrait"}) : "The painting in the center of the"+
	" back wall boasts a lovely picture of a summertime picnic. There are two"+
	" large tables covered in delicious looking foods and checkered blankets"+
	" spread out for people to sit on. Everyone looks quite happy."
	]));
	set_exits(([
	"west" : ROOMS+"church8"
	]));
	set_door("door",ROOMS+"church8","west",0);
}

void reset()
{
	::reset();
	if(!present("acolyte")) {
		switch(random(3)) {
			case 0:
				new(MONS+"alcolyte")->move(TO);
				break;
			case 1:
				new(MONS+"alcolyte")->move(TO);
				new(MONS+"alcolyte")->move(TO);
				break;
			case 2:
				new(MONS+"alcolyte")->move(TO);
				new(MONS+"alcolyte")->move(TO);
				new(MONS+"alcolyte")->move(TO);
				break;
		}
	}
}

