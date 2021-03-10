#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_short("The Nimble Thimble");
	set_long(
	"The shop seems a little cluttered. Rolls of various cloths in"+
	" different shades are around the room. Garments with markings"+
	" for adjustment and half-made articles are hung on racks that"+
	" are scattered all over. Scissors, needles, and all shades of"+
	" thread can be found here. A few mirrors are also placed in"+
	" strategic spots about the room. On the right wall is a little"+
	" window with a pot of miniature roses on the window sill. Their"+
	" sweet fragrance seems to fill the room. Measuring tapes and"+
	" sticks are all over the place, a few have even fallen to the"+
	" floor. A desk towards the back of the room is covered in cloth"+
	" and patterns with a few papers that hold notes for certain"+
	" items to be worked on. In a back room you can even see a loom"+
	" that the tailor must use to make some of her fabric with. Jars"+
   " of dye rest not too far from the room. The style and variety"+
	" in this little shop is impressive. There is probably only one"+
	" tailor in town, and she seems to be quite busy trying to fill"+
	" all the orders."
	);
	set_smell("default","The flowers on the window sill smell lovely.");
	if(query_night() == 1) {
		set_listen("default","It is peacefully quiet at this time of night.");
	}
	else {
		set_listen("default","The owner is humming a pretty tune.");
	}
	set_items(([
	"floor" : "The floor is swept very clean but a few yards of"+
	" fabric and some measuring tapes have fallen onto it.",
	({"mirror","mirrors"}) : "There are three mirrors placed around"+
	" the room so as to catch the best light and allow the customer"+
	" to see the clothing from all angles when worn.",
	({"flowers","pot","roses"}) : "%^BOLD%^%^RED%^A pot of miniature roses sits on"+
	" the window sill and fills the room with their wonderful fragrance.",
	"window sill" : "The window sill supports a pot of roses.",
	"window" : "%^BOLD%^%^CYAN%^There is a small window on the southern wall that is"+
	" framed by pretty blue curtains.",
	"curtains" : "%^BOLD%^%^CYAN%^These curtains frame the window"+
	" and can be closed to allow the customers more privacy.",
	"loom" : "In the back room there is a large loom that is used"+
	" for creating some of the fabric in the store.",
	({"containers","container","jars","dye"}) : "Jars of dye sit on"+
	" the floor of the back room near the loom.",
	({"room","back room"}) : "The back room of the store contains"+
	" the loom and some jars of dye, but you can't get in there.",
	({"clothing","garments"}) : "Various types of clothing in"+
	" different stages of completion are hung on racks around the"+
	" room.",
	({"cloth","fabric","rolls","yards of fabric","yards of cloth"}) : "Many"+
	" rolls of all sorts of fabric clutter the room. Several yards"+
	" of different types are draped over stools, some have even"+
	" slipped down to the floor. You can see cotton, silk, wools, and"+
	" mixtures of each in all sorts of shades here.",
	({"rack","racks"}) : "Clothing racks are scattered about the"+
	" room. They are simple wooden constructions that consist of a"+
	" round length of wood that is supported on either end with a"+
	" triangular base.",
	({"stool","stools"}) : "Several stools of varying heights are"+
	" placed about the room. Some are for customers to sit on, while"+
	" the shorter ones are for customers to stand on while the"+
	" tailor takes their measures.",
	"desk" : "A small desk is tucked into a corner in the room and"+
	" is covered with yards of fabric, measuring tapes, and patterns"+
	" for clothing.",
	({"measuring tape","measuring tapes","measuring stick","measuring sticks"}) : "Lots"+
	" of measuring tapes and sticks can be found all over the room."+
	" Some are on desks or stools, others have fallen to the floor."+
	" There is always one within easy reach.",
	({"pattern","patterns"}) : "Patterns for dresses and jackets"+
	" can be found on the cluttered desk in the back of the room.",
	"scissors" : "A pair of sharp scissors used for cutting fabric"+
	" are on top of the desk.",
	({"needle","needles"}) : "Sewing needles of varying lengths are"+
	" all over the place.",
	"thread" : "Spools of thread are scattered across the room and"+
	" they come in a variety of colors.",
	]));
	set_exits(([
	"west" : ROOMS+"street11",
	]));
	set_door("door",ROOMS+"street11","west",0);
}

void reset()
{
	::reset();
	if(!present("mina")) {
		new(MONS+"mina.c")->move(TO);
	}
}
