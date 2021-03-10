#include <std.h>
#include "../inherit/keep.h"
inherit ROOM;

int FLAG;

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_name("A secret passage");
   set_short("%^RESET%^%^ORANGE%^A secret passage%^RESET%^");
   set_long(((:TO,"my_long":)));
   set_smell("default","The passage is filled with dust.");
   set_listen("default","Everything is fairly quiet.");
   set_items(([
     ({"floor","rug"}) : "%^GREEN%^Most of the floor is covered by a worn rug.  "
"It was once perhaps a beautiful piece of work, done in a geometric design with "
"vibrant shades of red and orange, merging to display a large sun in the very "
"center.  Now, though, it is terribly faded and likely worthless.%^RESET%^",
     ({"desk","chair"}) : "%^RED%^A plain desk sits on the west side of the "
"room with a simple chair.  Both pieces of furniture seem intact, but whatever "
"forgeries or scribed secrets are now lost to time, as all the parchments "
"within its drawers have long crumbled and are unreadable.%^RESET%^",
     "couch" : "%^MAGENTA%^A small wine-colored couch sits on the eastern side "
"of the room.  It appears to be in worse shape than the desk, covered in dust "
"and mold.%^RESET%^",
     "chest" : ((:TO,"chest_desc":)),
     "scratches" : ((:TO,"scratches_desc":)),
     ({"stairs","trap door","trapdoor"}) : ((:TO,"trapdoor_desc":)),
   ]));
   set_exits(([
     "north" : ROOMS"hidden3",
   ]));
}

void reset() {
   ::reset();
   if(FLAG) {
     FLAG = 0;
     if(member_array("down",TO->query_exits()) != -1) remove_exit("down");
     tell_room(TO,"%^ORANGE%^The chest drops back into place, obscuring the "
"trap door from view.%^RESET%^");
   }
}

void init() {
   ::init();
   add_action("move","move");
   add_action("lift","lift");
   add_action("shut","shut");
}

int move(string str) {
   if(!str) return notify_fail("Move what?\n");
   if(str != "chest") return notify_fail("You can't move that.\n");
   if(FLAG) {
     tell_object(TP,"%^ORANGE%^The chest has already been moved.%^RESET%^");
     return 1;
   }
   tell_object(TP,"%^ORANGE%^You drag the chest aside, revealing a trap door"
"!%^RESET%^");
   tell_room(ETP,"%^ORANGE%^"+TPQCN+" drags the chest aside, revealing a trap "
"door.%^RESET%^",TP);
   FLAG = 1;
   return 1;
}

int lift(string str) {
   if(!str) return notify_fail("Lift what?\n");
   if(str != "trap door" && str != "trapdoor")
     return notify_fail("You can't lift that.\n");
   if(!FLAG) {
     tell_object(TP,"What "+str+"?");
     return 1;
   }
   if(member_array("down",ETP->query_exits()) != -1) {
     tell_object(TP,"%^ORANGE%^The trap door is already open!%^RESET%^");
     return 1;
   }
   tell_object(TP,"%^ORANGE%^You lift the trap door, revealing some stairs "
"leading down.%^RESET%^");
   tell_room(ETP,"%^ORANGE%^"+TPQCN+" lifts the trap door, revealing some "
"stairs leading down.%^RESET%^",TP);
   add_exit(ROOMS"basement1","down");
   return 1;
}

int shut(string str) {
   if(!str) return notify_fail("What are you trying to shut?\n");
   if(str != "trap door" && str != "trapdoor")
     return notify_fail("You can't shut that.\n");
   if(!FLAG) {
     tell_object(TP,"What "+str+"?");
     return 1;
   }
   if(member_array("down",ETP->query_exits()) != -1) {
     tell_object(TP,"%^ORANGE%^You shut the trap door.%^RESET%^");
     tell_room(ETP,"%^ORANGE%^"+TPQCN+" shuts the trap door.%^RESET%^",TP);
     remove_exit("down");
     return 1;
   }
   tell_object(TP,"%^ORANGE%^It seems to already be shut.%^RESET%^");
   return 1;
}

string my_long() {
   if(FLAG)
     return("%^RESET%^%^ORANGE%^A secret passage%^RESET%^\n"
"You have come to a dead end of a secret passage, in what appears to be a "
"meeting chamber, and not a public one at that.  A large woven %^CYAN%^rug "
"%^RESET%^covers the floor here, faded and worn from age.  There is a "
"%^RED%^desk %^RESET%^on the west side of the room with a chair, and a small "
"%^MAGENTA%^couch %^RESET%^on the east side.  A large wooden %^ORANGE%^chest "
"%^RESET%^is on the south side of the room,  lying partially open.  It seems "
"to have been recently dragged aside, revealing a %^RED%^trap door%^RESET%^.\n");
   return("%^RESET%^%^ORANGE%^A secret passage%^RESET%^\n"
"You have come to a dead end of a secret passage, in what appears to be a "
"meeting chamber, and not a public one at that.  A large woven %^CYAN%^rug "
"%^RESET%^covers the floor here, faded and worn from age.  There is a "
"%^RED%^desk %^RESET%^on the west side of the room with a chair, and a small "
"%^MAGENTA%^couch %^RESET%^on the east side.  A large wooden %^ORANGE%^chest "
"%^RESET%^is on the south side of the room,  lying partially open.\n");
}

string chest_desc() {
   if(FLAG) return("%^ORANGE%^A large wooden chest has been placed against the "
"south wall of the room.  It is slightly open and is filled with mildewed books "
"and parchment.  It has been recently moved to reveal a trap door.%^RESET%^");
   return("%^ORANGE%^A large wooden chest has been placed against the south "
"wall of the room.  It is slightly open and is filled with mildewed books and "
"parchment. You notice a few %^YELLOW%^scratches %^RESET%^%^ORANGE%^on the "
"floor around the chest.%^RESET%^");
}

string scratches_desc() {
   if(FLAG) return("You do not notice that here.");
   return("%^YELLOW%^There are a few scratch marks that you can see on the "
"floor near the chest, where the rug doesn't quite cover.  It looks like the "
"chest has been shifted before, making you wonder what would happen if you "
"tried to %^WHITE%^move %^YELLOW%^it yourself.%^RESET%^");
}

string trapdoor_desc() {
   if(!FLAG) return("You do not notice that here.");
   if(member_array("down",ETP->query_exits()) != -1)
     return("%^ORANGE%^The wooden chest has been moved to reveal a trap door "
"within the floor.  It is open, allowing passage to a set of stairs that lead "
"down into darkness.  You could %^YELLOW%^shut %^RESET%^%^ORANGE%^it if you "
"wanted to.%^RESET%^");
   return("%^ORANGE%^The wooden chest has been moved to reveal a trap door "
"within the floor.  It is shut, but you could probably %^YELLOW%^lift %^RESET%^"
"%^ORANGE%^it.%^RESET%^");
}
