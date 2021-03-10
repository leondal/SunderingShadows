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
  You are walking along Goldstone Court, in the middle of a residential area. Few people are on the streets, although you get the feeling that you are being observed from somewhere. Tall fences, trees, and bushes line the street, keeping the houses somewhat hidden.  The house to the south has a %^ORANGE%^brown door%^RESET%^ and to the north is a house with a %^BLUE%^blue door%^RESET%^.  The street continues on west.
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
      "east":MAINTOWN"wrstreet2",
      "west":MAINTOWN"wrstreet4",
      "north":MAINTOWN"whouse5",
      "south":MAINTOWN"whouse1",
   ]));
   set_door("blue door","/d/newbie/rooms/town/whouse5","north",0);
   set_door("brown door","/d/newbie/rooms/town/whouse1","south",0);
   set_open("blue door",0);
   "/d/newbie/rooms/town/whouse5"->set_open("blue door",0);
   set_open("brown door",0);
   "/d/newbie/rooms/town/whouse1"->set_open("brown door",0);
}

void reset(){
	::reset();
	if(!present("street_light",TO))
	new(MISCDIR+"street_light")->move(TO);
}
