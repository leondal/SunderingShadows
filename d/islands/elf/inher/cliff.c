//cliff
#include <std.h>
#include "../elf.h"
inherit CROOM;


void create(){
 if(base_name(TO) != "/d/islands/elf/inher/cliff")
 switch  (random(11)){
  case 0:set_monsters(({MON"guard"}),({roll_dice(1,2)}));
         break;
  case 1:set_monsters(({MON"guard2"}),({roll_dice(1,2)}));
         break;
  case 2:set_monsters(({MON"guard2",MON"guard"}),({roll_dice(1,2),roll_dice(1,2)}));
		 break;
  case 3:set_monsters(({MON"citizen"}),({roll_dice(1,2)}));
         break;
  }
    ::create();
    set_terrain(GRASSLANDS);
    set_travel(GAME_TRACK);
    set_repop(40);
    set_climate("mountain");
    set_name("cliff");
    set_short("cliff");
    set_long((:TO,"long_desc":));
	set("night long",(:TO,"night_desc":));
	set_items(([
      (({"meadow"})) :
        "A beautiful mist shrouds the meadow.",
	  (({"water","streams","waterfall"})) :
        "In the north there is a waterfall that is the source of the streams.",
      (({"plants"})) : "The plant life here is quite exotic.",
      (({"moss"})) : "The lower parts of the cliff are covered in moss.",
	  (({"cliff","cliffs"})) : "Steep cliffs line the "
         "northernmost edge of the grove.",
	  (({"wall","walls"})) : "The cliff is lined with a white wall "+
        "meant to fend off invaders.",
	   ]));
 
   set_listen("default",
   "Birds cherp softly and sounds of soft winds blowing can be heard");
   set_smell("default",
   "The lush smell of grasses and plants fill your senses");

}

string long_desc(){
  
   return("%^CYAN%^The grove comes to an end at the base of "+
"towering cliffs%^RESET%^.%^CYAN%^ Because of the geothermic energy of the grove%^RESET%^,%^CYAN%^ the granite "+
"walls are warm and moist%^RESET%^.%^CYAN%^ Soft moss lines the bottom of the cliffs%^RESET%^,%^CYAN%^ making "+
"them pleasant to touch%^RESET%^.%^CYAN%^ Numerous plants and trees extend up the cliff side "+
"and line the edge of the cliff far above your head%^RESET%^.%^CYAN%^ At the top of the cliff "+
"you can see the massive white walls which were built%^RESET%^,%^CYAN%^ and are now patrolled "+
"by the elves%^RESET%^%^RESET%^.%^CYAN%^"+
"\n");
 
}
string night_desc() {
  return ("%^BLUE%^This granite cliff slopes upward along "+
  "the edge of the grove%^CYAN%^.%^BLUE%^  The cliff face is lower"+
  " to the south and higher to the north%^CYAN%^.%^BLUE%^  "+
  "At night it is impossible to see the top of this cliff%^CYAN%^.%^BLUE%^"+
  "  The stone face of the cliff is warm%^CYAN%^.%^BLUE%^  "+
  "It is covered in patches of moss and ivy%^CYAN%^.%^BLUE%^  "+
  "Light from the night sky does not reach down here as the"+
  " mist blocks out all but the brightest moonlight%^CYAN%^.%^RESET%^"+
   "\n");
}
string query_weather(){ return "%^BOLD%^%^WHITE%^A mist covers the area."; }

void reset(){
 ::reset();

 
}
