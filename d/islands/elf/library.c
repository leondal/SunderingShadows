//library
#include <std.h>
#include "elf.h"
inherit LIBRARY;


void create(){
    ::create();
    set_property( "light", 2);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
	set_public_library(1);
    set_deposit(200);
    set_library_name("Ashata'Rathai_Library");
    set_name("Library");
    set_short("Library");
    set_long(
"%^GREEN%^Great arching %^CYAN%^pillars%^GREEN%^ cascade throughout this part of the keep supporting "
"the numerous intricately crafted bookshelves going %^BOLD%^%^BLACK%^unnaturally %^RESET%^high%^MAGENTA%^.%^GREEN%^ The "
"size of the room is %^BOLD%^%^BLACK%^enormous%^RESET%^%^GREEN%^ in regards to the rest of the citadel%^MAGENTA%^.%^GREEN%^ The "
"towering%^MAGENTA%^,%^GREEN%^ and arched walls of the library leave you wondering how it fits "
"inside the small citadel%^MAGENTA%^.%^GREEN%^  There are many thick and decorated "
"bookshelves%^MAGENTA%^.%^GREEN%^ Some books are so high one has climb to get to them%^MAGENTA%^.%^GREEN%^  Most of "
"them are of well known and influential elven scholars, though there are some others "
"that are older%^MAGENTA%^:%^GREEN%^ stories and legends that have been around for "
"centuries%^MAGENTA%^.%^GREEN%^  Others are tomes of the magic that elves are so well known "
"for%^MAGENTA%^.%^GREEN%^  Several %^ORANGE%^desks%^GREEN%^ and %^ORANGE%^tables%^GREEN%^ are placed randomly around the room with "
"miscellaneous books sitting upon them%^MAGENTA%^,%^GREEN%^ as if someone had left them in the "
"middle of reading a story and left it just sitting there%^MAGENTA%^.%^GREEN%^%^RESET%^");

	set_items(([
      (({"pillars"})) :
        "There are etched pillars that go far up.",
      (({"bookshelves"})) : "The bookshelves cascade up higher than even a giant could reach.",
      (({"desks","tables"})) : "The library has many "+
	  "places to read.  Elves sometimes leave books out with no fear of them being stolen.",
	   ]));

   
      set_exits(([ "south" : ROOMS"hall6",
        "west" : ROOMS"hall7",	  ]));

   set_listen("default","The place smells of books.");
   set_smell("default",
   "Turning pages can be heard.");
}
void reset(){
  ::reset();
  if(!present("librarian")) 
      find_object_or_load(MON"librarian")->move(TO);
}
