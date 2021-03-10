#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "You are standing in the kitchen and dining room area of this elven"+
   " home. There is a square table with four chairs around it in the"+
   " center of the room. Along the east wall is a sink, counter, and"+
   " cabinets along with several small plants of potted herbs. The"+
   " room is fairly simple and has lamps on the north and south walls.");
   set_smell("default","There is a lovely herbal fragrance in the room.");
   set_listen("default","The wind rustles through the leaves outside.");
   set_items(([
   ({"table","square table"}) : "There is a square tiled table in the"+
   " center of the room. The tiles have a woodland scene painted on them"+
   " that is rather soothing to look at.",
   "chairs" : "There are four oak chairs that surround the table.",
   "sink" : "There is a sink along the east wall, apparently whoever"+
   " lives here enjoys cooking.",
   "counter" : "There is a large counter along the east wall that has"+
   " a sink in it, and several potted herbs on top of it.",
   "cabinets" : "There are cabinets above and below the counter that"+
   " hold silverware, dishes, and cooking utensils.",
   ({"plants","potted plants","herbs","potted herbs"}) : "%^BOLD%^%^GREEN%^There"+
   " are several different types of herbs that have been placed in"+
   " ceramic pots. None of them are very big, although they smell"+
   " wonderful. You recognized basil, parsley, oregano, thyme,"+
   " peppermint, a bit of lemon grass, and some other more exotic"+
   " herbs.",
   "lamps" : "There are two lamps, one on the north wall and one on the"+
   " south wall. They have stained glass shades, one has the image of a"+
   " blue bird perched on a branch and the other has the image of a"+
   " squirrel climbing a tree.",
   ]));
   set_exits( (["west":RPATH3+"3one25"]) );
}
