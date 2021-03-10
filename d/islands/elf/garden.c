//garden with healer
#include <std.h>
#include "elf.h"
inherit HEALER;


void create(){
    ::create();
   set_terrain(GRASSLANDS);
   set_travel(GAME_TRACK);
  
    set_climate("mountain");
    set_name("garden");
    set_short("garden");
    set_long((:TO,"long_desc":));
	set("night long",(:TO,"night_desc":));

   set_exits(([
    "south": ROOMS"hgarden",  ]));
   	set_items(([
      (({"flowers"})) :
        "Flowers sit along a path planted in vases..",
      (({"stonework","statues","archways"})) : "Throughout this area,"+
	  " there is much stonework.  Statues of elves and fey creatures "+
	  "are here.  Etched archways are here.  The stonework is incredible. ",
	  (({"gazebo"})) : "A gazebo made from woven branches is here.",
	 (({"hut"})) : "The hut looks to be a place that a healer would set up "+
	 "shop. ",
	   ]));
 
   set_listen("default",
   "Sounds of the outdoors fill the area.");
   set_smell("default",
   "It smells of fresh plants.");
   set_name("nerwen");


}

string long_desc(){
  
   return("%^GREEN%^In this terraced courtyard "+
"garden, many flowers have bee planted in vases and alongside extravagant "
"elven stonework%^MAGENTA%^,%^GREEN%^ such as statues and archways%^MAGENTA%^.%^GREEN%^ A "
"single circular path of stones works it way up northward%^MAGENTA%^.%^GREEN%^"
"  The short path throughout the courtyard is beautifully crafted and shimmers with"
" elven magic.%^MAGENTA%^.%^GREEN%^  Several thick branches of trees intertwine over a small stone "
"gazebo in the center%^MAGENTA%^.%^GREEN%^  Wandering around%^MAGENTA%^,%^GREEN%^ one notices a hut off in a "
"corner%^MAGENTA%^.%^GREEN%^  In it%^MAGENTA%^,%^GREEN%^ there are several floating vials that are hovering in mid "
"air%^MAGENTA%^.%^GREEN%^  All the architecture of the various structures is beautiful%^MAGENTA%^,%^GREEN%^ almost "
"magical in nature%^MAGENTA%^.%^GREEN%^  Walls surround the place to the north%^MAGENTA%^,%^GREEN%^ east and west%^MAGENTA%^.%^GREEN%^\n");
 
}
string night_desc() {
   return("%^BLUE%^In this terraced courtyard "+
"garden, many flowers have bee planted in vases and alongside extravagant "
"elven stonework%^GREEN%^.%^BLUE%^such as statues and archways%^GREEN%^.%^BLUE%^ A "
"single circular path of stones works it way up northward%^GREEN%^.%^BLUE%^"
"  The short path throughout the courtyard is beautifully crafted and shimmers with"
" elven magic.%^GREEN%^.%^BLUE%^ Several thick branches of trees intertwine over a small stone "
"gazebo in the center%^GREEN%^.%^BLUE%^ Wandering around%^GREEN%^.%^BLUE%^one notices a hut off in a "
"corner%^GREEN%^.%^BLUE%^ In it%^GREEN%^.%^BLUE%^there are several floating vials that are hovering in mid "
"air%^GREEN%^.%^BLUE%^ All the architecture of the various structures is beautiful%^GREEN%^.%^BLUE%^almost "
"magical in nature%^GREEN%^.%^BLUE%^ Walls surround the place to the north%^GREEN%^.%^BLUE%^east and west%^GREEN%^.\n");
}
string query_weather(){ return "%^BOLD%^%^WHITE%^A mist covers the area."; }
void reset(){
string clerk;
   ::reset();
   clerk = MON"nerwin";
   if(!present("nerwin")) {
find_object_or_load(MON"nerwen")->move(TO);
}
if (!present("stone"))
  new(OBJ"stone9")->move(TO);
}
