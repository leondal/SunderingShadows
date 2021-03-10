//s4.c

#include <std.h>
#include "../tharis.h"

inherit ROOM;

int FLAG;

void create(){
   ::create();
    set_terrain(STONE_BUILDING);
    set_travel(BACK_ALLEY);
   set_property("light",2);
   set_property("indoors",1);
   set_short("Healer's anteroom");
   set_long(
@JAVAMAKER
   %^CYAN%^Healer's anteroom\n%^RESET%^
This room has several cots in it. There are buckets of water
sitting around and dirty sheets about. You see spots of blood
sitting uncleaned on the floor. Obviously people with dire wounds
come here for healing, but why?
JAVAMAKER
   );

   set_smell("default","You can smell the blood beginning to ripen, and the dirty sheets. ");
   set_listen("default","You hear the scratching of rats and the trickle of water.");
   set_items(([
      "sheets":"There must have been recently many wounded here, because these sheets all look recently soiled, and soiled badly.",
      "buckets":"These buckets have mildly clean water in them. They are obviously the attempt to keep something clean while washing wounds.",
      "blood":"These bloody areas are new, they have been walked through and spread about.",
   ]));

   set_exits(([
      "north":ROOMS"s3",
      "west":ROOMS"dwarfhealer",
   ]));

//   set_invis_exits(({}));
//   set_trap_functions(({}),({}),({}));
//   set_pre_exit_functions(({}),({}));
//   set_post_exit_functions(({}),({})); Commenting these out since they don't seem to be needed - Circe 9/20/03
}


void reset(){
   ::reset();
//   FLAG = 0;
}

void init(){
   ::init();
//   add_action("pull","pull");
//   add_action("pull","move");

}

/*

int pull(string str){
   if(str != "tapestry" && str != "tapestries");

   tell_object(TP,"You notice that one of the tapestries is covering a door to the south.");
   FLAG = 1;
   return 1;

}
This whole section about the tapestry was creating bug reports.  It seems like it was never finished.  I'm commenting it out for now.  If we need it, and/or someone decides to finish it later, we can put it back in.  If we do, we need to at least *mention* that there are tapestries in the description.  Circe 9/20/03
*/