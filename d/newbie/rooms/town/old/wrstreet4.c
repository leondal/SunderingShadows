#include "../../newbie.h"

inherit INH"townmove.c";

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("Goldstone Court in Offestry");
   set_short("Goldstone Court in Offestry");
   set_long(
@NEWBIE
You are at the end of Goldstone Court, in the middle of a residential area. Few people are on the streets, although you get the feeling that you are being observed from somewhere. Tall fences, trees, and bushes line the street, keeping the houses somewhat hidden.  The house to the south has a %^RED%^red door%^RESET%^ and to the north is a house with a %^CYAN%^cyan door%^RESET%^.  The street ends to the west at a house with a %^GREEN%^green door%^RESET%^."
NEWBIE
   );
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly and lights your way.");
   set_listen("default","The noise of the city seems to be quieter here.");
   set_smell("default","The air is fresh and clean.");
   set_property("light",2);
   set_items(([
      "streets":"The streets are cobbled and new. They lead throughout the city.",
      "houses":"The houses are good-sized estates, most likely for the more affluent residents of the city.",
   ]));
   set_exits(([
      "east":MAINTOWN"wrstreet3",
      "west":MAINTOWN"whouse3",
      "north":MAINTOWN"whouse4",
      "south":MAINTOWN"whouse2",
   ]));
   set_door("cyan door","/d/newbie/rooms/town/whouse4","north",0);
   set_door("red door","/d/newbie/rooms/town/whouse2","south",0);
   set_door("green door","/d/newbie/rooms/town/whouse3","west",0);
   set_open("cyan door",0);
   "/d/newbie/rooms/town/whouse4"->set_open("cyan door",0);
   set_open("red door",0);
   "/d/newbie/rooms/town/whouse2"->set_open("red door",0);
   set_open("green door",0);
   "/d/newbie/rooms/town/whouse3"->set_open("green door",0);
}

void reset(){
	::reset();
	if(!present("street_light",TO))
	new(MISCDIR+"street_light")->move(TO);
}
