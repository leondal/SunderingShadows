#include <std.h>
#include "../inherit/keep.h"
inherit ROOM;

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
     ({"floor","rug"}) : "%^GREEN%^The cold stone floor is mostly covered by a "
"rug that appears faded and rather worn. it was probably placed here to keep "
"footsteps from echoing and revealing this secret passageway. It extends to the "
"east.%^RESET%^",
     "walls" : "%^BLUE%^The walls are made of unremarkable stone blocks and "
"appear quite sturdy, although they are dulled by a layer of dust and grime. "
"There is a small %^CYAN%^button %^BLUE%^on the wall.%^RESET%^",
     "dust" : "%^ORANGE%^Everything here is covered in a thick layer of dust, "
"hinting at just how long this passageway has lain in disuse.%^RESET%^",
     "button" : "%^CYAN%^There is a small, flat button on the side of the south "
"wall.  It appears as though you could %^YELLOW%^push %^RESET%^%^CYAN%^it"
".%^RESET%^",
   ]));
   set_exits(([
     "east" : ROOMS"hidden3",
   ]));
}

void reset() {
   ::reset();
   if(member_array("west",TO->query_exits()) != -1) {
     tell_room(TO,"%^ORANGE%^The opening in the west wall slides soundlessly "
"shut.%^RESET%^");
     remove_exit("west");
     if(member_array("east",ROOMS"hidden1"->query_exits()) != -1) {
       tell_room(ROOMS"hidden1","%^ORANGE%^The opening in the east wall slides "
"soundlessly shut.%^RESET%^");
       ROOMS"hidden1"->remove_exit("east");
     }
   }
}

void init() {
   ::init();
   add_action("push","push");
}

int push(string str) {
   if(!str) return notify_fail("Push what?\n");
   if(str != "button") return notify_fail("Push what?\n");
   if(member_array("west",ETP->query_exits()) != -1) {
     tell_object(TP,"%^ORANGE%^You push the button and watch as the small "
"opening in the west wall slides shut.%^RESET%^");
     tell_room(ETP,"%^ORANGE%^"+TPQCN+" pushes the button and the west wall "
"slides soundlessly shut.%^RESET%^",TP);
     remove_exit("west");
     if(member_array("east",ROOMS"hidden1"->query_exits()) != -1) {
       tell_room(ROOMS"hidden1","%^ORANGE%^The opening in the east wall slides "
"soundlessly closed.%^RESET%^");
       ROOMS"hidden1"->remove_exit("east");
     }
   }
   else {
     tell_object(TP,"%^ORANGE%^You push the button and a section of the west "
"wall slides to the side, revealing a small room.%^RESET%^");
     tell_room(ETP,"%^ORANGE%^"+TPQCN+" pushes the button and a section of the "
"west wall slides to the side to reveal a small room.%^RESET%^",TP);
     add_exit(ROOMS"hidden1","west");
     if(member_array("east",ROOMS"hidden1"->query_exits()) == -1) {
       tell_room(ROOMS"hidden1","%^ORANGE%^A section of the east wall slides "
"to the side, revealing an entry to a secret passage.%^RESET%^");
       ROOMS"hidden1"->add_exit(ROOMS"hidden2","east");
     }
   }
   return 1;
}

string my_long() {
   if(member_array("west",ETP->query_exits()) != -1)
     return("%^RESET%^%^ORANGE%^A secret passage%^RESET%^\n"
"This appears to be a secret passage.  Every surface is covered in a thick "
"layer of %^ORANGE%^dust%^RESET%^, hinting at a long abandonment.  Even the "
"dark stone %^BLUE%^walls %^RESET%^are dulled by the grime of ages.  A faded "
"and worn %^GREEN%^rug %^RESET%^lies underfoot.  Nothing else here seems "
"remarkable, save for a small %^CYAN%^button %^RESET%^on the wall. The passage "
"continues to the east, while an opening in the wall leads west into a small "
"room.\n");
     return("%^RESET%^%^ORANGE%^A secret passage%^RESET%^\n"
"This appears to be a secret passage.  Every surface is covered in a thick "
"layer of %^ORANGE%^dust%^RESET%^, hinting at a long abandonment.  Even the "
"dark stone %^BLUE%^walls %^RESET%^are dulled by the grime of ages.  A faded "
"and worn %^GREEN%^rug %^RESET%^lies underfoot.  Nothing else here seems "
"remarkable, save for a small %^CYAN%^button %^RESET%^on the wall. The passage "
"continues to the east.\n");
}
