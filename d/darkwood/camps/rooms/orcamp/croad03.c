#include <std.h>
#include "../../elfisland1.h"
inherit BCAMP;
void create() {
   ::create();
   set("long",
      "%^RESET%^%^ORANGE%^This is the entrance to the large camp in the"+
      " middle of the camp. The entrance is wide and the path leading inside"+
      " looks well traveled. The door way is outlined by two trees with a ripped"+
      " branch placed between them to hold the cloth up and provide an obvious"+
      " entrance. This tent definitely appears to be the center of society in this"+
      " camp."
   );
   set_exits( ([ 
      "south" : CAMP+"croad02", 
      "enter" : CAMP+"maintent" 
   ]) );
   set_pre_exit_functions(({"enter"}),({"GoThroughDoor"}));
}

int GoThroughDoor()
{

   if(!present("orc bandit"))
   {
   return 1;
   }
   if(TP->query_invis())
   {
   return 1;
   }
   else
   {
   tell_object(TP,"The orc pushes you down to the ground.");
   tell_room(ETP,"The orc pushes "+TPQCN+" down to the ground in "+TP->query_possessive()+" attempt to go inside.",TP);
   return 0;
   }
}

void reset()
{
   ::reset();
   if(!present("bandit")) {
      new(MON+"bandit")->move(TO);
      new(MON+"bandit")->move(TO);
   }
}
