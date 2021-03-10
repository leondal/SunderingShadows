#include <std.h>
#include "../inherit/keep.h"
inherit VAULT;

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_name("A conference room");
   set_short("%^RESET%^%^ORANGE%^A conference room%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^A conference room%^RESET%^\n"
"You are in what once was most likely a conference room.  There is a "
"large rectangular %^RED%^table %^RESET%^in the middle with chairs around it, "
"and a very crude %^GREEN%^map %^RESET%^of the surrounding areas placed in it's "
"centre.  Two %^CYAN%^paintings %^RESET%^have been hung upon the north and "
"south walls, adding a little color to the otherwise drab room, despite that "
"they are mostly faded.  A lone %^BOLD%^%^WHITE%^pedestal %^RESET%^with a "
"%^BLUE%^statue %^RESET%^atop it sits in the southeastern corner.\n");
   set_smell("default","The room is filled with dust.");
   set_listen("default","Everything is fairly quiet here.");
   set_items(([
     ({"table","chairs"}) : "%^RED%^There is a large rectangular table made of "
"cherry wood in the center of the room.  It is coated in dust and worn from "
"age.  Six chairs of matching wood encircle the table, some looking fairly "
"fragile and ready to fall apart.%^RESET%^",
     "map" : "%^GREEN%^A very crude map of the surrounding area is displayed in
the center of the table.  Unfortunately, it is so faded and out-of-date that it doesn't show anything useful.%^RESET%^",
     "paintings" : "%^CYAN%^Two paintings are hung upon the walls, one on the "
"south and one on the north.  They were probably quite valuable when they were "
"new, but they have not endured the years well.  The paint is chipping and the "
"tapestry decaying.%^RESET%^",
     "pedestal" : "%^BOLD%^%^WHITE%^There is an ebony pedestal sitting alone in "
"the southeastern corner of the room.  Atop it sits a beautiful ivory "
"%^RESET%^%^BLUE%^statue %^BOLD%^%^WHITE%^carved into the shape of a dragon"
".%^RESET%^",
     ({"statue","ivory statue","dragon statue"}) : "%^BLUE%^Atop the ebon "
"pedestal stands a beautiful and carefully worked piece of ivory that has been "
"carved into the shape of a standing dragon.  The wings extend outward and are "
"incredibly detailed.  The exquisite craftsmanship makes you want to reach out "
"and %^YELLOW%^touch %^RESET%^%^BLUE%^it.%^RESET%^",
   ]));
   set_exits(([
     "west" : ROOMS"keep7",
   ]));
   set_search("default","%^ORANGE%^As your eyes scan the room, they are "
"constantly drawn back to the %^BLUE%^statue%^ORANGE%^.  It is so lifelike in "
"crafting that you almost want to reach out and %^YELLOW%^touch %^RESET%^"
"%^ORANGE%^it.%^RESET%^");
   set_door("door",ROOMS"keep7","west","keep master_key");
   set_door_description("door","%^ORANGE%^Fairly sturdy and set with an iron "
"lock, this door seems to have withstood the ravages of time quite well"
".%^RESET%^");
   set_locked("door",1,"lock");
   lock_difficulty("door",20,"lock");
   add_lock("door","keep master_key","lock","This is a standard 2 tumbler door "
"lock.  It looks fairly sturdy and undamaged, and would probably need a key or "
"some other specific tools to open.");
}

void reset() {
   ::reset();
   if(member_array("east",TO->query_exits()) != -1) {
     tell_room(TO,"%^YELLOW%^You hear a click as the east wall slides closed"
".%^RESET%^");
     remove_exit("east");
     if(member_array("west",ROOMS"hidden2"->query_exits()) != -1) {
       tell_room(ROOMS"hidden2","%^ORANGE%^You hear a click and the west wall "
"slides back into place, closing the passage.%^RESET%^");
       ROOMS"hidden2"->remove_exit("west");
     }
   }
}

void init() {
   ::init();
   add_action("touch","touch");
   add_action("move","move");
}

int touch(string str) {
   if(!str) return notify_fail("Touch what?\n");
   if(str != "dragon statue" && str != "ivory statue" && str != "statue" && str != "wings")
     return notify_fail("Why would you touch that?\n");
   tell_object(TP,"%^BOLD%^%^WHITE%^You reach out and gently touch the ivory "
"statue.  It is cold and smooth to the touch, and the craftsmanship is "
"excellent.  On touching the wings you realize that you can make them "
"%^YELLOW%^move%^WHITE%^.%^RESET%^");
   tell_room(ETP,"%^BOLD%^%^WHITE%^"+TPQCN+" reaches out and touches the ivory "
"statue.%^RESET%^",TP);
   return 1;
}

int move(string str) {
   if(!str) return notify_fail("Move what?\n");
   if(str != "dragon statue" && str != "ivory statue" && str != "statue" && str != "wings")
     return notify_fail("Why would you move that?\n");
   if(member_array("east",ETP->query_exits()) != -1) {
     tell_object(TP,"%^YELLOW%^You hear a click as you move the wings of the "
"statue down, and the east wall closes.%^RESET%^");
     tell_room(ETP,"%^YELLOW%^You hear a click as "+TPQCN+" moves the wings of "
"the statue, and the east wall closes.%^RESET%^",TP);
     remove_exit("east");
     if(member_array("west",ROOMS"hidden2"->query_exits()) != -1) {
       tell_room(ROOMS"hidden2","%^ORANGE%^You hear a click and the west wall "
"slides back into place, closing the passage.%^RESET%^");
       ROOMS"hidden2"->remove_exit("west");
     }
   }
   else {
     tell_object(TP,"%^YELLOW%^You move the wings of the statue up, and hear a "
"click as the east wall slides open to reveal a secret passage.%^RESET%^");
     tell_room(ETP,"%^YELLOW%^"+TPQCN+" moves the wings of the statue, and you "
"hear a click as the east wall slides open to reveal a passage.%^RESET%^",TP);
     add_exit(ROOMS"hidden2","east");
     if(member_array("west",ROOMS"hidden2"->query_exits()) == -1) {
       tell_room(ROOMS"hidden2","%^ORANGE%^You hear a click as the west wall "
"slides open, revealing a passage.%^RESET%^");
       ROOMS"hidden2"->add_exit(ROOMS"hidden1","west");
     }
   }
   return 1;
}
