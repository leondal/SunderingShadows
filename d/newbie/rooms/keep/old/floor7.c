/*Several checks were added in the trap function to make sure what we're trying to 
remove_attacker() from is still an object (using objectp(whatever), it was bugging
whenever the object died in the continue_attack() phase.  Should be fixed now
Saide - 10/23/03*/
// fixing the trap so it does get triggered instead of going off no matter what *Styx* 6/05

#include <std.h>
#include "/d/newbie/rooms/keep/keep.h"
inherit ROOM;

void create()
{
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
   set_property("indoors",1);
   set_property("light",1);
   set_name("Secret passage fireball trap");
   set_short("A secret passage");
   set_long(
   "You are in a secret passage on the second floor of a ruined keep. This room"+
   " is fairly plain, not much but stone walls, ceiling, and floor. You do"+
   " notice that this room is free from dust, which seems rather strange..."
   );
   set_smell("default","A faint sulfuric smell hangs in the air here.");
   set_listen("default","Everything is fairly quiet here.");
   set_items(([
   "ceiling" : "The ceiling is made of unremarkable stone blocks.",
   ({"walls","wall"}) : "The walls are made of square stone blocks and seem"+
   " quite sturdy.",
   "floor" : "The floor is free from dust, which is rather strange. It almost"+
   " looks like there is something across the center of the passage for a moment,"+
   " but then you lose sight of it. Perhaps you should search it?",
   ({"string","silver string"}) : "This string is very slender, tiny, and almost"+
   " impossible to see. It is stretched out over the western end of this passage and"+
   " is low near the floor. It is not completely tight and there is some give to the"+
   " string.",
   ]));
   set_exits(([
   "west" : ROOMS+"floor8",
   "east" : ROOMS+"floor6",
   ]));
   set_search("default",(:TO,"search_here":));
   set_trap_functions(({"west"}),({"fireball"}),({"west"}));
}

int fireball(object targ)
{
   int i, j;
   object *inven;

   inven = all_living(TO);
   j = sizeof(inven);
   if(TP->query_true_invis()) return 0;

   tell_object(TP,"%^BOLD%^%^RED%^As you attempt to move west a trap is sprung and a fireball"+
   " explodes in the passage!");
   tell_room(ETP,"%^BOLD%^%^RED%^As "+TPQCN+" attempts to move west a trap is sprung and a fireball"+
   " explodes into the passage!",TP);
   toggle_trap("west");
   for(i=0;i<j;i++) {
      if(!objectp(inven[i])) continue;
      if(inven[i] == TO) continue;
      if(inven[i] == TP) continue;
      if(inven[i]->query_true_invis()) continue;   // added by Styx 8/15/03
      if(!"daemon/saving_d"->saving_throw(inven[i],"spell")) {
         tell_object(inven[i],"%^BOLD%^%^RED%^The fireball scorches your flesh!");
         inven[i]->do_damage("torso",random(3)+5);
      }
      else {
         tell_object(inven[i],"%^RED%^You manage to avoid the worst of the blast but"+
         " are still badly scalded from the flames.");
         inven[i]->do_damage("torso",random(3)+2);
      }
      
	  inven[i]->add_attacker(TO);
	  inven[i]->continue_attack();
	  if(objectp(inven[i])) {	
			inven[i]->remove_attacker(TO); 
	  }
   }
   if(!"daemon/saving_d"->saving_throw(TP,"spell")) {
      tell_object(TP,"%^RED%^The explosion of the fireball throws you backwards and burns your"+
      " flesh!");
      TP->do_damage("torso",random(8)+10);
      TP->add_attacker(TO);
      TP->continue_attack();
	  if(objectp(TP)) {
			TP->remove_attacker(TO);
	  }
      return 1;
   }
   tell_object(TP,"%^BOLD%^%^RED%^You grit your teeth and manage to sustain as"+
   " little damage as possible as you fight your way west.");
   TP->do_damage("torso",random(3)+5);
   TP->add_attacker(TO);
   TP->continue_attack();
   if(objectp(TP)) {
		TP->remove_attacker(TO);
   }
   return 0;
}

void reset() {
   ::reset();
// added so trap will reset *Styx* 6/05
   if(!trapped("west") && !random(5))
      toggle_trap("west");
}   

int search_here() {
 if(trapped("west")) {  // check added *Styx* 6/05
   tell_object(TP,"You search around the room and discover a silver string so tiny you can barely see it even now. It is stretched out across the western section of the passage.");
   tell_room(ETP,""+TPQCN+" searches the room and seems to find something of interest.",TP);
   if(TP->is_class("thief")) {
      tell_object(TP,"This is obviously some kind of trap, you should disarm it before continuing.");
   }
   else if(TP->query_stats("intelligence") > random(20)) {
      tell_object(TP,"You come to the conclusion that it must be a trap of some sort.");
   }
   return 1;
 } // adding so can tell if trap is set or tripped *Styx* 6/05
   tell_object(TP,"You search around the room and discover a broken silver string along the western section of the passage along with %^BOLD%^%^BLACK%^scorch marks %^RESET%^on the walls and floor.");
   tell_room(ETP,""+TPQCN+" searches the room and seems to find something of interest.",TP);
   if(TP->is_class("thief"))
      tell_object(TP,"The string looks like it may be what is left of some kind of trap.");
   return 1;
} 
