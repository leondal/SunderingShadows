//cave26.c
#include <std.h>
#include "echoes.h"

inherit ECHOES;

void create(){
    ::create();
    set_long(
      "%^YELLOW%^Inside Echoes Mountains%^RESET%^\n"+
      "The smooth, %^BOLD%^%^BLACK%^dark gray walls %^RESET%^of this tunnel through Echoes Mountains seem "+
      "partially naturally carved.  Some signs of fantastic workmanship suggest "+
      "that the dwarves who make their home here have expanded and improved upon "+
      "nature's beauty.  The %^BOLD%^%^BLUE%^vaulted ceilings %^RESET%^are supported and decorated by "+
      "%^YELLOW%^archways %^RESET%^carved of stone and placed every fifteen feet without variance.  "+
      "%^BOLD%^%^BLUE%^Columns %^RESET%^carved in relief march along the walls between the arches, "+
      "creating a sense of being in the open air despite the drab walls of the tunnels.  The "+
      "main tunnel ends here in this large cavern, though a smaller one branches off to the north. "+
      "A %^BOLD%^%^BLACK%^large, black hole %^RESET%^takes up part of the floor near the "+
      "eastern wall."
    );
    add_item("hole","Looking closer, you can see a room below.  There are large rocks "+
	      "piled up, creating a crude and most likely treacherous stairway.");
	    
    set_pre_exit_functions(({"down"}),({"go_down"}));
    set_post_exit_functions( ({"down"}), ({"GoThroughDoor"}) );
    set_exits(([
        "down" : ROOMS"cave61",
        "west" : ROOMS"cave25",
	"north" : ROOMS"tunnel01"
   	]));
   set_smell("default","The stench of unwashed bodies and uncleanliness wafts "
        "up from the hole in the floor.");
}
/*
void reset() {
  ::reset();
  if(!present("mountain dwarf") && !random(2)) {
    if(sizeof(children(MOBS"dwarf")) < 10) {
      new(MOBS"dwarf")->move(TO);
      new(MOBS"dwarf")->move(TO);
    }
  }
}
*/
int go_down() {
   if(TP->query_invis()) return 1;
  if(present("mountain dwarf")) {
      write("%^MAGENTA%^The dwarf says:%^RESET%^  Beware!  Those tunnels are "+
        "infested with ogres and other beasts!!  A few brave adventurers who "+
        "had bested the goblins in the stronghold came back victorious, but "+
        "many others have lost their lives!");
    return 1;
  }
  return 1;
}

void GoThroughDoor() {
//	if(!userp(TP)) return;
	if(avatarp(TP) && TP->query_invis()) return;
	if(!random(4)) {
	  tell_room(ETP,TPQCN+" slips and falls trying to pick a way down the "
	     "pile of rocks.", TP);
	  tell_room(TP,"You slip and fall trying to pick a way down the pile of rocks!"
	     "\n%^BLUE%^Tumbling the rest of the way down leaves you badly bruised.");
     TP->do_damage("torso",random(6)+8);
     return;
   }
   return;
}	
