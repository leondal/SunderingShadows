//owagon21.c - Entrance to Raiders hall added 12/14/03 after Koenig was moved.  The hall had been there.  Circe
#include <std.h>
#include "../shadow.h"

inherit "/d/shadow/room/inherits/owagon.c";

void create(){
    ::create();
    set_long(
"%^GREEN%^An old wagon trail%^RESET%^
%^ORANGE%^This old wagon %^WHITE%^trail%^ORANGE%^ leads north and east through the rocky terrain that makes up the foot hill area south and east of the joint between the Echoes Mountains and the Charu Mountains. This rocky rutted trail has seen little use. Obviously once a smugglers wagon trail blazed to bypass the tariffs found in Shadow City. Now those traveling here risk bandits and worse, for this is obviously not patrolled. You notice that the %^BOLD%^%^BLACK%^boulders%^RESET%^%^ORANGE%^ and %^GREEN%^scrub%^ORANGE%^ forest growth provide ample ambush opportunity. A length of %^GREEN%^bushes%^ORANGE%^ just along the road here seems unusually thick.%^RESET%^
"
        );
    add_item("bushes","The bushes seem quite thick and well-tended.");
    set_search("default","The bushes growing along the side of the road catch your attention.");
    set_search("bushes","Searching through the bushes, you think you see the opening of a cave just behind them.  Perhaps you could enter the cave?");
    set_exits(([
               "south":FORESTDIR+"owagon20",
               "north":FORESTDIR+"owagon24",
               ]));
}

void init(){
   ::init();
   add_action("enter","enter");
}

int enter(string str){
   if(!str){
      tell_object(TP,"Maybe you should try to enter the cave.");
      return 1;
   }
   if(str == "cave" || str == "bushes"){
      tell_object(TP,"You carefully work your way through the bushes.");
      tell_room(ETP,""+TPQCN+" searches through the bushes, then disappears!",TP);
      TP->move("/d/guilds/raiders/hall/cave1");
      TP->force_me("look");
      return 1;
   }
   return 0;
}
