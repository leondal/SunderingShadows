#include <std.h>
#include <daemons.h>
#include "/d/islands/tonerra/areadefs.h"

inherit CAT;

void create(){
  ::create();
  set_indoors(1);
  set_light(2);
  set_short("Catacombs");
  set_long(
@DESC
%^BLUE%^You are in the center of the catacombs beneath the
old monastery.
Walkways lead in all directions. The center of the floor, is a
great seal. Dark passage ways lead in all directions here. The
dust on the floor is tracked and unsettled.
DESC
  );
  set_items(([
   "seal":"This seal is made of 3 interlinking circles. It appears to serve as a cover for an openning.",
   ]));
  set_listen("default","You hear some small creatures scurrying among the remains.");
  set_smell("default","You smell the rotting remains all around you.");
  set_exits(([
    "north":CATACOMBS+"cat28",
    "south":CATACOMBS+"cat40",
    "east":CATACOMBS+"cat34",
    "west":CATACOMBS+"cat46",
    "northeast":CATACOMBS+"cat31",
    "southwest":CATACOMBS+"cat43",
    "southeast":CATACOMBS+"cat37",
    "northwest":CATACOMBS+"cat49",
  ]));

  set_post_exit_functions(({"down"}),({"down"}));
  if(!random(5))
     new(MON+"tombt")->move(TO);
}

void reset(){
   object * critters, critter, env;
   int flag;
   ::reset();
   remove_exit("down");
   flag = 1;
   if(!random(5))
   {
     flag = 0;
     critters = children(MON + "tombt");
     if (sizeof(critters)>0)
     {
       foreach (critter in critters)
       {
         env = environment(critter);
         if (objectp(env))
         {
           flag = 1;
         }
       }
     }
   }
   if (flag ==0) new(MON+"tombt")->move(TO);
}

void init(){
   ::init();
   add_action("lift","lift");
}

int lift(string str)
{
   if(!str || str != "seal"){
      return notify_fail("Lift what?\n");
   }

   tell_room(TO,TPQCN+" lifts the seal with great effort.",TP);
   tell_object(TP,"With great effort you lift the seal.");
   add_exit(LAVA+"lava1","down");
   return 1;
}

void down()
{
    tell_room(ETP,TPQCN+" falls into the room.",TP);
    tell_object(TP,"You slip and slide down into the lava tubes.");
    WORLD_EVENTS_D->inject_event((["Waking A Mad God" : (["start message" : "%^BOLD%^%^BLACK%^Creatures across the world are stirred up and "+
    "more powerful!! Something has come far %^BOLD%^%^RED%^too close%^BOLD%^%^BLACK%^ to the dwelling place of an ancient
god!!!%^RESET%^", 
    "event type" : "monster modifications", "length" : 120,
    "notification" : "More dangerous monsters!", "event name" : "Waking A Mad God", "modifier" : (["strength" : 2, "dexterity" : 2, "intelligence" :
2, 
    "wisdom" : 2, "constitution" : 2, "charisma" : 2, "level" : 2, "health" : roll_dice(4,10)]), "announce" : 1, "announce to" : "world" ]),]));    
}
