#include <std.h>
#include "../../newbie.h"

inherit INH"townmove.c";

void create() {
   ::create();
	set_terrain(CITY);
	set_travel(PAVED_ROAD);
   set_name("Starlight Avenue in Offestry");
   set_short("Starlight Avenue in Offestry");
   set_long(
@NEWBIE
You are walking on Starlight Court, in the middle of a residential area. This area seems to be relaxed and laid-back, with neighbors talking over fences and children playing wherever there is an empty space. There is little traffic along this sidestreet, mostly residents going to and from their houses. Every once in a while someone calls a friendly greeting to you.  The house to the south has a %^BOLD%^%^GREEN%^green door%^RESET%^ and to the north is a house with a %^YELLOW%^yellow door%^RESET%^.
NEWBIE
   );   
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly and lights your way.");
   set_listen("default","You hear the sounds of children playing and neighbors chatting.");
   set_smell("default","The air is fresh and clean.");
   set_property("light",2);
   set_items(([
      "streets":"The streets are cobbled and new. They lead throughout the city.",
      "houses":"The houses appear to be living space for small families. Most likely those who work in the city have their residences in this area.",
   ]));
   set_exits(([
      "west":MAINTOWN"erstreet2",
      "east":MAINTOWN"erstreet4",
      "north":MAINTOWN"ehouse5",
      "south":MAINTOWN"ehouse1",
   ]));
   set_door("yellow door","/d/newbie/rooms/town/ehouse5","north",0);
   set_door("green door","/d/newbie/rooms/town/ehouse1","south",0);
   set_open("yellow door",0);
   "/d/newbie/rooms/town/ehouse5"->set_open("yellow door",0);
   set_open("green door",0);
   "/d/newbie/rooms/town/ehouse1"->set_open("green door",0);
}

void reset(){
	::reset();
	if(!present("street_light",TO))
	new(MISCDIR+"street_light")->move(TO);
}
