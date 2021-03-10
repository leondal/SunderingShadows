#include <std.h>
#include "../inherit/keep.h"
inherit ROOM;

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_name("A secret basement");
   set_short("%^RESET%^%^ORANGE%^A secret basement%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^A secret basement%^RESET%^\n"
"At the base of these stairs is a short hallway, leading to two doorways "
"further north.  The hall itself is made from solid %^BLUE%^stone%^RESET%^, "
"lending a drab and dreary appearance to the passageway.  Stone "
"%^ORANGE%^stairs %^RESET%^lead back up to relative safety from the remains "
"upon the floor before you.  You notice that part of the %^RED%^floor "
"%^RESET%^is scorched black, and the charred remains of a few "
"%^BOLD%^%^WHITE%^bones %^RESET%^are scattered along the edges of the room.  "
"Perhaps it would be wise to tread carefully...\n");
   set_smell("default","The smell of charred flesh hangs in the air.");
   set_listen("default","The silence is eerie.");
   set_items(([
     ({"floor","scorches","marks","scorch marks"}) : "%^RED%^The floor is "
"perfectly level and smooth, but there is a wide path of blackened scorch marks "
"travelling from the middle of the hallway, back to the first few steps of the "
"stairs.  There are a few bits and pieces of charred %^BOLD%^%^WHITE%^bones "
"%^RESET%^%^RED%^that have been blasted to the side.  It definitely gives you "
"an uneasy feeling about this place.%^RESET%^",
     "stairs" : "%^ORANGE%^The stone stairs lead back up to a %^RED%^trap door "
"%^ORANGE%^and apparent safety.  The first few steps have been scorched black, "
"as though some great force has been repeatedly blasted at them.%^RESET%^",
     ({"stone","hall"}) : "%^BLUE%^The walls are made of stone, cut unnaturally "
"smoothly.  They offer a dreary aspect to the hallway beyond.  A few odd "
"indentations can be seen on the %^CYAN%^walls%^BLUE%^.%^RESET%^",
     "bones" : "%^BOLD%^%^WHITE%^The charred remains of a few bits of bones "
"have been blasted off to the sides of the hallway.  Little else remains to "
"hint at who they might once have belonged to.%^RESET%^",
     ({"trapdoor","trap door"}) : "%^RED%^There is a trap door in the ceiling "
"that leads back up to rooms above.%^RESET%^",
     "walls" : ((:TO,"walls_desc":)),
   ]));
   set_search("default","%^BLUE%^You find the bones of the dead, and don't wish "
"to join them.  A few odd indentations can be seen on the %^CYAN%^walls%^BLUE%^"
".%^RESET%^");
   set_exits(([
     "up" : ROOMS+"hidden4",
     "north" : ROOMS+"basement2",
   ]));
   set_trap_functions(({"north"}),({"electrocute"}),({"north"}));
   set_pre_exit_functions(({"up"}),({"GoThroughDoor"}));
}

int GoThroughDoor() {
   if(member_array("down",ROOMS"hidden4"->query_exits()) == -1) {
      tell_object(TP,"%^ORANGE%^You push the trap door open and climb up the "
"stairs.%^RESET%^");
      tell_room(ETP,"%^ORANGE%^"+TPQCN+" pushes the trap door open and climbs "
"up the stairs.%^RESET%^",TP);
      ROOMS"hidden1"->add_exit(ROOMS"basement1","down");
      tell_room(ROOMS"hidden4","%^ORANGE%^A trap door opens up from the "
"floor!%^RESET%^");
      return 1;
   }
   return 1;
}

int electrocute(string str) {
   toggle_trap("north");
   tell_object(TP,"%^YELLOW%^As you step forward, a crackle reaches your ears, "
"and twin bolts of lightning arc out from within the walls to thunder into you "
"with a horrible jolt!%^RESET%^");
   tell_room(TO,"%^YELLOW%^As "+TPQCN+" walks north, twin bolts of lightning "
"arc out from the walls to jolt "+TP->query_objective()+"!%^RESET%^",TP);
   TP->do_damage("torso",random(7)+10);
   TP->add_attacker(TO);
   TP->continue_attack();
   if(objectp(TP)) TP->remove_attacker(TO);
   if (!TP->query_ghost()) return 0;
   else {
     tell_room(TO,"%^BOLD%^%^WHITE%^"+TPQCN+" screams horribly as the "
"electricity takes their life away.%^RESET%^");
     return 1;
   }
}

string walls_desc() {
   string myreturn;
   myreturn = "%^CYAN%^Looking at the walls on either side of the hallway, you "
"note a few small holes.  Each is blackened around the opening.%^RESET%^";
   if(TP->is_class("thief")) {
     if(TO->query_trap_status("north","north")) myreturn += "  %^CYAN%^It is "
"obviously some kind of trap, and is likely still active.%^RESET%^";
     else myreturn += "  %^CYAN%^It is obviously some kind of trap, though it "
"looks as though it has been recently triggered.%^RESET%^";
   }
   else {
     if(TP->query_stats("intelligence") >= random(20))
       myreturn += "  %^CYAN%^Perhaps it is some kind of trap?%^RESET%^";
   }
   return myreturn;
}

void reset() {
   ::reset();
   if(!TO->query_trap_status("north","north")) {
     TO->toggle_trap("north","north");
     tell_room(TO,"%^CYAN%^A small click can be heard from within the "
"wall.%^RESET%^");
   }
}
