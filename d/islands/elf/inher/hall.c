//gate to keep
#include <std.h>
#include <daemons.h>
#include "../elf.h"
inherit CVAULT;


void create(){
    ::create();
set_property( "light", 2);
    set_property( "indoors", 1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("Ashata'Rathai Keep");
    set_short("Elegant Keep");
    set_long("%^BOLD%^Elegant Keep
%^BLUE%^%^BOLD%^T%^RESET%^his hallway is very elaborate%^BOLD%^%^BLUE%^"+
",%^RESET%^ it has a %^CYAN%^marble floor%^RESET%^ and is lit by "
"%^BOLD%^%^MAGENTA%^numerous violet lights%^BLUE%^.%^RESET%^"+
"  The walls are elaborately decorated with pictures "+
"telling battles of elves and statues of long "+
"passed on elven heroes%^BLUE%^.%^RESET%^  The exits are"+
" framed by %^BOLD%^%^MAGENTA%^archways%^RESET%^ shaped like %^BOLD%^%^MAGENTA%^winged elves%^BLUE%^.%^RESET%^  "+
"The wings reach upward and touch each other in the"+
" center of the ceiling%^BLUE%^.%^RESET%^ \n");

	set_items(([
      (({"floor","marble floor"})) :
        "The floor is made of marble with patterns of leaves etched on it.",
      (({"lights","violet lights"})) : "The lights float near the ceiling.",
      (({"wall","walls"})) : "The walls have paintings "+
	  "of regal elves.",
	   (({"statue","statues"})) : "There are statues of elven "+
	  "heroes.  They look gallant.",
	  (({"archway","archways","winged elves"})) : "Archways go along the walls and"+
	  " up to the cieling.  They are carved in such a way to "+
	  "look like giant wings.",
	   ]));

   
   
   set_listen("default","Sounds of people walking on the stone can be heard.");
   set_smell("default",
   "The air here is pleasant.");
  
}
// toning this down to cull population
void reset(){
 ::reset();

 switch  (random(8)){
  case 0:set_monsters(({MON"guard"}),({roll_dice(1,3)}));
         return;
  case 1:set_monsters(({MON"guard2"}),({roll_dice(1,3)}));
         return;
  case 2:set_monsters(({MON"guard2",MON"guard"}),({roll_dice(1,4),roll_dice(1,4)}));
		 return;
  case 3:set_monsters(({MON"mage"}),({roll_dice(1,2)}));
         return;
  
  }
 
}
