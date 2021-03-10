#include <std.h>
#include "../inherit/keep.h"
inherit ROOM;

void create() {
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
   set_property("indoors",1);
   set_property("light",1);
   set_name("A hidden passage");
   set_short("A hidden passage");
   set_long("%^ORANGE%^A hidden passage%^RESET%^\n"
"You are standing in a hidden passageway that continues along to the west, "
"although you can't see very far in the dim light.  The corridor seems to "
"have survived the ravages of time fairly well, as the %^BLUE%^walls "
"%^RESET%^are still intact.  You do notice that the %^ORANGE%^floor "
"%^RESET%^in this this part of the passageway is completely free from dust, "
"which seems rather strange...\n");
   set_smell("default","A faint sulfuric smell hangs in the air here.");
   set_listen("default","Everything is fairly quiet.");
   set_items(([
     ({"walls","wall"}) : "%^BLUE%^The walls at either end of the "
"passageway are coated with a layer of age-old grime and dust, but aside "
"from this they seem to have withstood the passage of time fairly well.  "
"They certainly have not crumbled, the way some walls outside have done.  "
"However, the %^ORANGE%^floor %^BLUE%^in this middle section of the "
"corridor is perfectly clean, and free of dust.  How strange...%^RESET%^",
     "floor" : "%^ORANGE%^The floor here is completely free from dust, which "
"seems rather strange given the state of the rest of this building.  It "
"almost looks like there is something glistening across the center of the "
"passage for a moment, but then you lose sight of it.  Perhaps you should "
"%^YELLOW%^search %^RESET%^%^ORANGE%^around?%^RESET%^",
     ({"string","silver string"}) : ((:TO,"trap_desc":)),
   ]));
   set_exits(([
     "west" : ROOMS"floor8",
     "east" : ROOMS"floor6",
   ]));
   set_search("default",(:TO,"search_here":));
   set_trap_functions(({"west"}),({"fireball"}),({"west"}));
}

int fireball(object targ) {
   int i, j;
   object *inven;

   inven = all_living(TO);
   j = sizeof(inven);
   if(TP->query_true_invis()) return 0;

   tell_object(TP,"%^BOLD%^%^RED%^As you attempt to move west a trap is "
"sprung and a fireball explodes in the passage!%^RESET%^");
   tell_room(ETP,"%^BOLD%^%^RED%^As "+TPQCN+" attempts to move west a trap "
"is sprung and a fireball explodes into the passage!%^RESET%^",TP);
   toggle_trap("west","west");
   for(i=0;i<j;i++) {
     if(!objectp(inven[i])) continue;
     if(inven[i] == TO || inven[i] == TP) continue;
     if(inven[i]->query_true_invis()) continue;
     if(!"daemon/saving_d"->saving_throw(inven[i],"spell")) {
       tell_object(inven[i],"%^BOLD%^%^RED%^The fireball scorches your "
"flesh!%^RESET%^");
       inven[i]->do_damage("torso",random(3)+5);
     }
     else {
       tell_object(inven[i],"%^RED%^You manage to avoid the worst of the "
"blast but are still badly scalded from the flames.%^RESET%^");
       inven[i]->do_damage("torso",random(3)+2);
     }
     inven[i]->add_attacker(TO);
     inven[i]->continue_attack();
     if(objectp(inven[i])) inven[i]->remove_attacker(TO); 
   }
   if(!"daemon/saving_d"->saving_throw(TP,"spell")) {
     tell_object(TP,"%^RED%^The explosion of the fireball throws you "
"backwards and burns your flesh!%^RESET%^");
     TP->do_damage("torso",random(8)+10);
     TP->add_attacker(TO);
     TP->continue_attack();
     if(objectp(TP)) TP->remove_attacker(TO);
     return 1;
   }
   tell_object(TP,"%^BOLD%^%^RED%^You grit your teeth and manage to sustain "
"as little damage as possible.%^RESET%^");
   TP->do_damage("torso",random(3)+5);
   TP->add_attacker(TO);
   TP->continue_attack();
   if(objectp(TP)) TP->remove_attacker(TO);
   return 1;
}

void reset() {
   ::reset();
   if(!TO->query_trap_status("west","west")) {
     TO->toggle_trap("west","west");
     tell_room(TO,"%^ORANGE%^A small click can be heard from within the "
"wall.%^RESET%^");
   }
}   

int search_here() {
   if(TO->query_trap_status("west","west")) {
     tell_object(TP,"%^YELLOW%^You search around the room and discover a "
"%^WHITE%^silver string %^YELLOW%^so tiny you can barely see it even now.  "
"It is stretched out across the western section of the passage.%^RESET%^");
     tell_room(ETP,"%^YELLOW%^"+TPQCN+" searches the room and seems to find "
"something of interest.%^RESET%^",TP);
     if(TP->is_class("thief"))
       tell_object(TP,"%^BOLD%^%^RED%^This is obviously some kind of trap.  "
"You should disarm it with your %^YELLOW%^trap %^RED%^ability before "
"continuing.%^RESET%^");
     else {
       if(TP->query_stats("intelligence") > random(20))
         tell_object(TP,"%^BOLD%^%^RED%^You come to the conclusion that it "
"must be a trap of some sort.%^RESET%^");
     }
     return 1;
   }
   tell_object(TP,"%^YELLOW%^You search around the room and discover a "
"broken %^WHITE%^silver string %^YELLOW%^along the western section of the "
"passage along with scorch marks on the walls and floor.%^RESET%^");
   tell_room(ETP,"%^YELLOW%^"+TPQCN+" searches the room and seems to find "
"something of interest.%^RESET%^",TP);
   if(TP->is_class("thief"))
      tell_object(TP,"%^BOLD%^%^RED%^The string looks like it may be what "
"is left of some kind of trap.%^RESET%^");
   return 1;
}

string trap_desc() {
   if(TO->query_trap_status("west","west"))
     return("%^BOLD%^%^WHITE%^There is a string here that is very slender, "
"tiny, and almost impossible to see.  It is stretched out over the western "
"end of this passage and is low near the floor.  It is not completely tight "
"and there is some give to the string.%^RESET%^");
   else return("%^BOLD%^%^WHITE%^There is a broken string here near the "
"western end of the corridor, along with scorch marks on the walls and "
"floor.%^RESET%^");
}
