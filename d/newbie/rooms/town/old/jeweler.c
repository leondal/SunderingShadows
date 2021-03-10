#include <std.h>
#include "../../newbie.h"
inherit INH"townmove.c";

void create()
{
	::create();
	set_property("indoors",1);
	set_short("The Smokey Quartz");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
	set_long(
	"This is a quaint little jewelers shop just off of Highspire Avenue. The shop is"+
   " rather small, but every inch of space seems to be covered in sparkling jewelry."+
	" There are silver and gold chains, necklaces, bracelets, rings, and more. This is"+
	" the perfect place to buy your girlfriend a present, or something special for"+
	" yourself. Pine cabinets are set up all about the room, with glass inlaid in the tops"+
	" so that you can see the merchandise without touching it. Everything here seems to"+
	" be of fine quality, but there is no telling what would happen if worn into battle."
	);
	set_property("light",2);
	set_smell("default","The shop smells faintly of pine.");
	set_listen("default","Wind chimes tinkle in the faint breeze.");
	set_items(([
	({"chimes","wind chimes"}) : "Some silver wind chimes are hung by the door, they're"+
	" moving slightly in the breeze, creating a pleasant sound.",
	({"cabinets","pine cabinets","glass cabinets","display"}) : "Pine cabinets are scattered"+
	" about the room. They have glass lids inlaid in them and all appear to be locked."+
   " This keeps the jewelry safe from would-be thieves. If you wish to see something,"+
	" you must ask the shop keeper to show it to you.",
	"floor" : "The floor is covered in a thin green rug.",
	]));
	set_exits(([
	"south" : MAINTOWN"wstreet1",
	]));
}

void reset() {
   ::reset();
   if(!present("selyvia")) {
      find_object_or_load(MON"selyvia")->move(TO);
   }
}
