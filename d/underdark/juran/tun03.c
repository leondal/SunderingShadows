#include <std.h>
#include "../underdark.h";
#include "juran.h";

inherit BTUNNEL;

void create() {
   ::create();
   set_exits( ([
      "ascend" : TUNNEL+"tun02",
      "south" : TUNNEL+"tun04",
   ]) );
   set_pre_exit_functions( ({"south"}), ({"GoThroughDoor"}) );
}

int GoThroughDoor(){
   if(TP->query_highest_level() < 15) {
      tell_object(TP, "You catch a sudden chill and think this might not be such a good idea.");
      return 0;
   }
   return 1;
}
