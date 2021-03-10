//garden with healer
#include <std.h>
#include "elf.h"
inherit ROOM;


void create(){
    ::create();
   set_terrain(GRASSLANDS);
   set_travel(GAME_TRACK);
  
    set_climate("mountain");
    set_name("hanging garden");
    set_short("hanging garden");
    set_long((:TO,"long_desc":));
	set("night long",(:TO,"night_desc":));

   set_exits(([
    "west": ROOMS"hall2",
    "east": ROOMS"hall5",	
   "south": ROOMS"corridor",
    "north": ROOMS"garden",	]));
   	set_items(([
      (({"flowers"})) :
        "Flowers sit along a path planted in vases.",
      (({"stonework","statues","archways"})) : "Throughout this area,"+
	  " there is much stonework.  Statues of elves and fey creatures "+
	  "are here.  Etched archways are here.  The stonework is incredible. ",
	  
	   ]));
 
   set_listen("default",
   "Sounds of the outdoors fill the area.");
   set_smell("default",
   "It smells of fresh plants.");

}

string long_desc(){
  
   return("%^GREEN%^In this terraced courtyard garden%^MAGENTA%^,%^GREEN%^ many flowers have"+
" been planted in vases alongside extravagant elven stonework such as "+
"statues and archways%^MAGENTA%^.%^GREEN%^ Above%^MAGENTA%^,%^GREEN%^ rows of stone planters let flowers hang "+
"and bloom%^MAGENTA%^.%^GREEN%^  A single path of stones works it way up northward and"+
" southward%^MAGENTA%^.%^GREEN%^ The short path throughout the courtyard is beautifully"+
" crafted and shimmers with elven magic%^MAGENTA%^.%^GREEN%^  All the architecture of"+
" the various structures is beautiful%^MAGENTA%^,%^GREEN%^ almost magical in nature%^MAGENTA%^.%^GREEN%^ \n");
 
}
string night_desc() {
   return("%^BLUE%^In this terraced courtyard garden%^GREEN%^.%^BLUE%^  Many flowers are planted in vases and "
"alongside extravagant elven stonework%^GREEN%^,%^BLUE%^ such as statues and archways%^GREEN%^.%^BLUE%^  A "
"single circular path of stones works it way up northward%^GREEN%^.%^BLUE%^  The short path "
"throughout the courtyard becomes beautiful crafted and shimmers with "
"elven magic%^GREEN%^.%^BLUE%^   All the architecture of the various structures is beautiful%^GREEN%^,%^BLUE%^ almost "
"magical in nature%^GREEN%^.%^BLUE%^  Walls surround the place to the north%^GREEN%^,%^BLUE%^ east and west%^GREEN%^.%^BLUE%^\n");
}
string query_weather(){ return "%^BOLD%^%^WHITE%^A mist covers the area."; }
void reset(){
::reset();
if (!present("anarane"))
  new(MON"anarane")->move(TO);
}
