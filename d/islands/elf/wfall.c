//water garden
#include <std.h>
#include "elf.h"
inherit "/std/pier";

void create(){
    ::create();
    set_terrain(GRASSLANDS);
    set_travel(GAME_TRACK);
    set_climate("mountain");
    set_name("Ashta'Rathai water garden");
    set_short("water garden");
    set_long((:TO,"long_desc":));
	set("night long",(:TO,"night_desc":));

    set_exits(([
	 "north": ROOMS"mythal", 
     "south": ROOMS"water", 
     "east": ROOMS"cliff6", 
     "west": ROOMS"cliff5", 	 ]));
	 set_invis_exits(({"north"}));
   	set_items(([
      (({"waterfall"})) :
        "The waterfall cascades down a cliff wall to the north.",
      (({"pool"})) : "The pool is a deep blue with mist coming off of it.  Perhaps there are fish in there?",
      (({"ivy"})) : "Ivy grows up along the cliff. ",
	  (({"limestone"})) : "There are limestone steps"+
	  " with ivy covering them.  They circle north "+
	  "around the pool.  They also go back to the "+
	  "south towards the water garden. ",
	 (({"keep"})) : "To the south a keep stands.  "+
	  "It is propped on pillars and has a single tower in the center. ",
	   ]));
   set_search("default","It is hard to see behind the waterfall.");
   set_search("waterfall","To the north, behind the waterfall,"+
   " you catch a glimpse of a flickering light");
   set_listen("default",
   "Sounds of falling water fills one's ears.");
   set_smell("default",
   "It smells of warm fresh water.");
   set_max_fishing(6);
   set_chance(12);
   set_max_catch(8);
   set_fish((["arctic lamprey" : 10, "nothern pike" : 3 ]));
}

string long_desc(){
  
   return("%^CYAN%^You walk a bit up the slope and"+
   " come across a %^BOLD%^waterfall %^RESET%^%^CYAN%^"+
"c%^WHITE%^a%^CYAN%^s%^WHITE%^c%^CYAN%^a%^WHITE%^d%^CYAN%^i%^WHITE%^"+
"n%^CYAN%^g into a %^BOLD%^%^BLUE%^deep blue pool%^RESET%^%^MAGENTA%^."+
" %^CYAN%^ To the north are several small %^GREEN%^ivy "+
"overgrown%^CYAN%^ steps that lead to the %^ORANGE%^"+
"limestone%^CYAN%^ outcropping%^MAGENTA%^.%^CYAN%^  "+
"The pool overflows southward towards the grove%^MAGENTA%^"+
".%^CYAN%^  The water of the pool is warm and "+
"refreshing to the touch%^MAGENTA%^.%^CYAN%^  "+
"Cool mists come from the waterfall filling the "+
"area with a slight haze%^MAGENTA%^. %^RESET%^"+
"\nTo the south is an elegant keep.");
 
}
string night_desc() {
   return("%^BLUE%^You walk a bit up the slope"+
   " and come across a %^BOLD%^waterfall%^RESET%^%^BLUE%^ "+
"c%^WHITE%^a%^BLUE%^s%^WHITE%^c%^BLUE%^a%^WHITE%^d%^BLUE%^i"+
"%^WHITE%^n%^BLUE%^g into a %^BOLD%^%^BLUE%^deep blue pool%^RESET%^%^MAGENTA%^."+
"%^BLUE%^ To the north are several small %^GREEN%^ivy "+
"overgrown%^BLUE%^ steps that lead to the %^ORANGE%^limestone"+
"%^BLUE%^ outcropping%^MAGENTA%^.%^BLUE%^  The pool "+
"overflows southward towards the grove%^MAGENTA%^.%^BLUE%^"+
"  The water of the pool is warm and "+
"refreshing to the touch%^MAGENTA%^.%^BLUE%^  "+
"Cool mists come from the waterfall filling the "
"area with a slight haze%^MAGENTA%^. %^RESET%^"+
"\nTo the south is an elegant keep.");
}
string query_weather(){ return "%^BOLD%^%^WHITE%^A mist covers the area."; }
