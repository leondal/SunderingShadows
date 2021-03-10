#include <std.h>
#include "../piratedefs.h"
inherit CROOM;

void create(){
   set_monsters(({MON"piratecrew",MON"piratecrew2",MON"piratecrew3"}),({1,2,1}));
   ::create();
   set_property("light",2);
   set_property("indoors",0);
   set_terrain(WOOD_BUILDING);
   set_travel(DECAYED_FLOOR);
   set_name("Aftercastle");
   set_short("Aftercastle");
   set_long("%^BOLD%^Aftercastle%^RESET%^\n"
"This is the rear deck of the pirate boat.  The ship must be an %^BLUE%^older%^RESET%^ design, as it only "
"has one such deck, which consists of %^ORANGE%^wooden boards %^RESET%^that are probably long overdue for a "
"polish.  A %^ORANGE%^wooden rail %^RESET%^runs around the length of the deck, almost like a small defensive "
"wall that would probably defend quite well from arrows and other such missiles.  From this higher vantage "
"point, you have a clear view of the ship's main deck just below you.\n");
   set_smell("default","You smell fresh ocean air minced with the smell of charred wood.");
   set_listen("default","You hear the boards of the ship creak in an unsettling way.");
   set_items(([
     ({"deck","boards","wooden boards"}):"The wooden boards beneath your feet form the rear deck of this "
"ship.  They look rather old, and are in need of a good polish.",
     "rail":"A wooden rail runs around the edge of the deck, probably as a defense against arrows and other "
"similar missile attacks."
   ]));
   set_exits(([
     "maindeck":COVE"boata02"
   ]));
}
