//Ekibi Caverns by Circe 3/13/05
#include <std.h>
#include "../ekibi.h"

inherit EKIBI;

void create(){
   ::create();
   set_long(::query_long()+"There is a large %^YELLOW%^hole "+
      "%^RESET%^in the ceiling here, letting in a small amount "+
      "of light.\n");
   add_item("hole","The hole looks to be the only way up.  If you had "+
      "the right skill or climbing tools, you could probably <climb> "+
      "up out of this cavern.");
   set_exits(([
      "northeast" : PATHEXIT"c2",
      "southeast" : PATHEXIT"c7"
   ]));
   set_climb_exits((["climb":({ PATHEXIT"cave",10,5,100})]));
   set_fall_desc("You lose your grip and fall to the cave floor.");
   set_post_exit_functions(({"northeast","southeast"}),({"GoThroughDoor","GoThroughDoor"}));
}

int GoThroughDoor(){
   tell_object(TP,"%^BOLD%^%^MAGENTA%^Don't forget to %^YELLOW%^<"+
      "%^MAGENTA%^search%^YELLOW%^> %^MAGENTA%^the rooms you are in.");
   return 1;
}
