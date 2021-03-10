#include <std.h>
#include "keep.h"
inherit ROOM;

void create()
{
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_short("A secret basement");
   set_long(
   "You have traveled down the stairs into a hidden basement. The passage"+
   " continues to the north, branching off into two side rooms. The room is"+
   " made from solid stone, as though it was formed naturally, though that"+
   " is obviously impossible. The ceiling, floor and walls are completely"+
   " flat and smooth, joining together at right angles. This was clearly"+
   " the work of some powerful magic user, but for what purpose? The stone"+
   " steps lead back up to relative safety, but you notice that the floor"+
   " and the first few steps are scorched black. A few charred remains of"+
   " %^BOLD%^bones%^RESET%^ are scattered about the edges of the room. What could have"+
   " happened here?"
   );
   set_smell("default","The smell of charred flesh seems to hang in the air here.");
   set_listen("default","The silence is eerie.");
   set_items(([
   "floor" : "The floor is perfectly level and smooth, but there is a wide"+
   " path of black scorch marks travelling from a little ways in front of"+
   " you back to the first few steps of the stairs. There are a few bits"+
   " and pieces of charred bones that have been blasted to the side. You"+
   " have an uneasy feeling about this place.",
   "stairs" : "The stone stairs lead back up to the trap door and safety.",
   "walls" : "The walls are unnaturally smooth, forming perfect angles with"+
   " the floor and ceiling.",
   "ceiling" : "The ceiling is flat and smooth, very unnatural. There is a trap door"+
   " in the ceiling that leads back up to the secret passage.",
   "bones" : "%^BOLD%^The charred remains of a few bits of bones have"+
   " obviously been blasted off to the sides of the room here. There is"+
   " not much left, and you doubt the people survived whatever happened.",
   "steps" : "The first few steps of the stairs are scorched black, as"+
   " though some great force has repeatedly blasted this area.",
   "trap door" : "There is a trap door in the ceiling that leads back up to the"+
   " secret passage.",
   ]));
   set_search("default","You find the bones of the dead, and don't wish to join them.");
   set_search("floor",(:TO,"search_em":));
   set_search("walls",(:TO,"search_em":));
   set_exits(([
   "up" : ROOMS+"keep37",
   "north" : ROOMS+"basement2",
   ]));
   set_trap_functions(({"north"}),({"electrocute"}),({"north"}));
   set_pre_exit_functions(({"up"}),({"GoThroughDoor"}));
}

int GoThroughDoor()
{
   if(member_array("down","/d/newbie/rooms/keep/keep37"->query_exits()) == -1) {
      tell_object(TP,"You push the trap door open and climb up the stairs.");
      tell_room(ETP,""+TPQCN+" pushes the trap door open and climbs up the stairs.",TP);
      "/d/newbie/rooms/keep/keep37"->add_exit("/d/newbie/rooms/keep/basement1","down");
      tell_room("/d/newbie/rooms/keep/keep37","A trap door opens up from the floor!");
      return 1;
   }
   return 1;
}

int electrocute(string str)
{
   if(!"daemon/saving_d"->saving_throw("spell")) {
      write("%^BOLD%^A bolt of lightning shoots from the north"+
      " and blasts into you!");
      tell_room(TO,"%^BOLD%^As "+TPQCN+" begins to walk north a lightning bolt"+
      " blasts "+TP->query_objective()+" backwards!",TP);
      TP->do_damage("torso",random(7)+10);
      TP->add_attacker(TO);
      TP->continue_attack();
// adding objectp check in case they die  *Styx*  11/15/03, last change 5/16/03
      if(objectp(TP))
         TP->remove_attacker(TO);
      return 1;
   }
   write("%^BOLD%^A bolt of lightning shoots from the north and hits you,"+
   " you barely manage to stagger into the next room.");
   tell_room(TO,"%^BOLD%^As "+TPQCN+" walks north a bolt of lightning hits"+
   " "+TP->query_objective()+"!",TP);
   TP->do_damage("torso",random(5)+5);
   TP->add_attacker(TO);
   TP->continue_attack();
// adding objectp check in case they die  *Styx*  11/15/03, last change 5/16/03
   if(objectp(TP))
      TP->remove_attacker(TO);
   if (!TP->query_ghost()) {
   return 0;
  } else {
   tell_room(TO,"%^BOLD%^"+TPQCN+" screams horribly as the electricity takes their life away.");
   return 1;
  }
}

int search_em(string str)
{
   if(TP->is_class("thief")) {
      tell_object(TP,"You search the area and find two small holes on either"+
      " side of the passage to the north, it is obviously some sort of a trap.");
      return 1;
   }
   else if(TP->query_stats("intelligence") < random(20)) {
      tell_object(TP,"You notice two very small holes on either side of the"+
      " passage to the north. Perhaps they set off some kind of trap?");
      return 1;
   }
   tell_object(TP,"You find nothing odd.");
   return 1;
}
