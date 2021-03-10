//cave14.c - Used as inherit for others
#include <std.h>
#include "echoes.h"
inherit CROOM;

void pick_critters();

void create(){
    pick_critters();
    set_repop(35);
    ::create();
    set_indoors(1);
    set_terrain(NAT_CAVE);
    set_travel(RUTTED_TRACK);
    set_property("light",1);
    set_name("Inside Echoes Mountains");
    set_short("Inside Echoes Mountains");
    set_long(
       "%^YELLOW%^Inside Echoes Mountains%^RESET%^\n"+
       "The smooth, %^BOLD%^%^BLACK%^dark gray walls %^RESET%^of "+
       "this tunnel through Echoes Mountains seem partially "+
       "naturally carved.  Some signs of fantastic workmanship "+
       "suggest that the dwarves who make their home here have "+
       "expanded and improved upon nature's beauty.  The %^BOLD%^"+
       "%^BLUE%^vaulted ceilings %^RESET%^are supported and "+
       "decorated by %^YELLOW%^archways %^RESET%^carved of stone "+
       "and placed every fifteen feet without variance.  %^BOLD%^"+
       "%^BLUE%^Columns %^RESET%^carved in relief march along the "+
       "walls between the arches, creating a sense of being in the "+
       "open air despite the drab walls of the tunnels.\n"
    );

    set_items(([
      (({"wall","walls","gray walls","stone walls"})) : "The dark gray stone walls "+
         "are perfectly smooth except for the carved columns and archways.  Aging "+
         "spots and darker gray stone in places suggest that these tunnels have "+
         "stood for some time and that they were probably initially naturally "+
         "carved.",
      (({"ceiling","ceilings","vaulted ceilings"})) : "The ceiling of the tunnel "+
         "rises high overhead, making the caverns seem open rather than stuffy.  "+
         "From what you can see, they seem to be hewn smooth between the archways.",
      (({"archway","archways"})) : "The tall archways are set into the walls and "+
         "curve as they near the ceiling, being lost in the shadows above.  They "+
         "have the simple, elegant lines characteristic of dwarven stonework.",
      (({"column","columns"})) : "The rounded columns protruding from the walls "+
         "of the tunnel are fluted but otherwise very simple.  They are well-made "+
         "and show very few signs of wear, indicating that they are maintained.",
      (({"floor","ground"})) : "The stone floor of the tunnels is strewn with a "+
         "light covering of dust and occasional small rocks.  For the most part, "+
         "it is quite clean and smooth, but rises and falls, making travel a "+
         "little difficult." 
	]));
   set_smell("default","You smell the slightly stale air of the tunnels.");
   set_listen("default","You hear the reverberance of echoes throughout the caves.");
 
    set_exits(([
        "north" : ROOMS"cave15",
      "west" : ROOMS"cave42",
        "south" : ROOMS"cave13"
   	]));
}

void reset(){
/*
   int active;
   active = has_mobs();  
   if(!active) { 
      if(mons)  mons = ([]);  
      pick_critters();
   }
*/
   ::reset();
   switch(random(5)){
      case 0:  tell_room(TO,"%^BOLD%^You hear the metallic clink of "+
                  "pick against rock somewhere deeper in the cavern.");
               break;
      case 1:  tell_room(TO,"%^BOLD%^%^BLACK%^Several moths suddenly "+
                  "flitter out of a crack in the wall.");
               break;
      case 2:  tell_room(TO,"%^BOLD%^%^BLUE%^You think you see something "+
                  "dart down a passageway just ahead, sticking to the "+
                  "shadows.");
               break;
      case 3:  tell_room(TO,"%^YELLOW%^You catch the glitter of gold "+
                  "within one of the walls and can't help but wonder "+
                  "how much you could make mining here.");
               break;
      case 4:  tell_room(TO,"%^BOLD%^%^BLUE%^A young dwarven child "+
                  "brushes past, running off down the passageway.");
               break;
   }
}

void pick_critters(){
      switch(random(6)) {     
        case 0..2:  break;
        case 3:  set_monsters( ({MOBS"dwarf"}),({random(2)+1}));
                 break;
        case 4:  set_monsters( ({MOBS"dwarf", MOBS"worker"}),({1, 1}));
                 break;
        case 5:  set_monsters( ({MOBS"worker"}),({1}));
                 break;
      }
}