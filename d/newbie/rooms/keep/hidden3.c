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
"west.%^RESET%^",
     "walls" : "%^BLUE%^The walls are made of unremarkable stone blocks and "
"appear quite sturdy, although they are dulled by a layer of dust and grime. "
"There is a small metal %^ORANGE%^knob %^BLUE%^on the east wall.%^RESET%^",
     "dust" : "%^ORANGE%^Everything here is covered in a thick layer of dust, "
"hinting at just how long this passageway has lain in disuse.%^RESET%^",
     "knob" : "%^ORANGE%^There is a small metal knob on the side of the east "
"wall.  It appears as though you could %^YELLOW%^turn %^RESET%^%^ORANGE%^it"
".%^RESET%^",
   ]));
   set_exits(([
     "south" : ROOMS"hidden4",
     "west" : ROOMS"hidden2",
   ]));
}

void reset() {
   ::reset();
   if(member_array("east",TO->query_exits()) != -1) {
     tell_room(TO,"%^ORANGE%^The opening in the east wall slides soundlessly "
"shut.%^RESET%^");
     remove_exit("east");
     if(member_array("west",ROOMS"hidden3"->query_exits()) != -1) {
       tell_room(ROOMS"storage3","%^ORANGE%^The opening in the west wall slides "
"soundlessly shut.%^RESET%^");
       ROOMS"storage3"->remove_exit("west");
     }
   }
}

void init() {
   ::init();
   add_action("turn","turn");
}

int turn(string str) {
   if(!str) return notify_fail("Turn what?\n");
   if(str != "knob") return notify_fail("Turn what?\n");
   if(member_array("east",ETP->query_exits()) != -1) {
     tell_object(TP,"%^ORANGE%^You turn the tiny knob and watch as the small "
"opening in the east wall slides shut.%^RESET%^");
     tell_room(ETP,"%^ORANGE%^"+TPQCN+" turns the knob and the east wall "
"slides soundlessly shut.%^RESET%^",TP);
     remove_exit("east");
     if(member_array("west",ROOMS"storage3"->query_exits()) != -1) {
       tell_room(ROOMS"storage3","%^ORANGE%^The opening in the west wall slides "
"soundlessly closed.%^RESET%^");
       ROOMS"storage3"->remove_exit("west");
     }
   }
   else {
     tell_object(TP,"%^ORANGE%^You turn the knob and a section of the east wall "
"slides to the side, revealing a small armory.%^RESET%^");
     tell_room(ETP,"%^ORANGE%^"+TPQCN+" turns the knob and a section of the east "
"wall slides to the side to reveal a small armory.%^RESET%^",TP);
     add_exit(ROOMS"storage3","east");
     if(member_array("west",ROOMS"storage3"->query_exits()) == -1) {
       tell_room(ROOMS"storage3","%^ORANGE%^A section of the west wall slides "
"to the side, revealing an entry to a secret passage.%^RESET%^");
       ROOMS"storage3"->add_exit(ROOMS"hidden3","west");
     }
   }
   return 1;
}

string my_long() {
   if(member_array("east",ETP->query_exits()) != -1)
     return("%^RESET%^%^ORANGE%^A secret passage%^RESET%^\n"
"This appears to be a secret passage.  Every surface is covered in a thick "
"layer of %^ORANGE%^dust%^RESET%^, hinting at a long abandonment.  Even the "
"dark stone %^BLUE%^walls %^RESET%^are dulled by the grime of ages.  A faded "
"and worn %^GREEN%^rug %^RESET%^lies underfoot.  Nothing else here seems "
"remarkable, save for a small %^RED%^knob %^RESET%^on the wall. The passage "
"continues to the west and south, while an opening in the wall leads east into "
"a small armory.\n");
     return("%^RESET%^%^ORANGE%^A secret passage%^RESET%^\n"
"This appears to be a secret passage.  Every surface is covered in a thick "
"layer of %^ORANGE%^dust%^RESET%^, hinting at a long abandonment.  Even the "
"dark stone %^BLUE%^walls %^RESET%^are dulled by the grime of ages.  A faded "
"and worn %^GREEN%^rug %^RESET%^lies underfoot.  Nothing else here seems "
"remarkable, save for a small %^RED%^knob %^RESET%^on the wall. The passage "
"continues to the west and south.\n");
}
