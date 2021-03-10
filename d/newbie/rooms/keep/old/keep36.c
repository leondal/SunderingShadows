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
   set_short("A secret passage");
   set_long(
   "You are standing in a secret passage. There really isn't much to this room, it"+
   " is covered in dust and no one else has probably set foot in here for some time."+
   " There is a faded and worn rug laid out across the floor, probably to muffle"+
   " the footsteps of anyone walking around back here. On the east wall is a little"+
   " knob of some kind. The passage continues to the west and south."
   );
   set_smell("default","The passage is filled with dust.");
   set_listen("default","Everything is fairly quiet.");
   set_items(([
   "floor" : "The floor has a rug laid out across it and is covered in dust.",
   "rug" : "The rug appears faded and rather worn, it was probably placed here to"+
   " keep footsteps from echoing and giving the secret passage away. It extends"+
   " to the west.",
   ({"wall","walls"}) : "The walls are made of unremarkable stone blocks and appear"+
   " quite sturdy. There is a small metal knob on the east wall, you wonder what it's for.",
   "knob" : "There is a small metal knob on the side of the east wall. It appears"+
   " as though you could turn it, but what would happen?",
   ]));
   set_exits(([
   "south" : ROOMS+"keep37",
   "west" : ROOMS+"keep38",
   ]));
}

void reset()
{
   ::reset();
   set_exits(([
   "south" : ROOMS+"keep37",
   "west" : ROOMS+"keep38",
   ]));
}

void init()
{
   ::init();
   add_action("turn","turn");
   do_random_encounters(({MONS+"spider"}),70,1);
}

void turn(string str)
{
   if(str != "knob") {
      return notify_fail("Turn what?\n");
   }
   if(member_array("east",ETP->query_exits()) != -1) {
      tell_object(TP,"You turn the tiny knob and watch as the small opening in the"+
      " east wall slides shut.");
      tell_room(ETP,""+TPQCN+" turns a knob and the east wall slides soundlessly shut.",TP);
      remove_exit("east");
      tell_room("/d/newbie/rooms/keep/keep35","The opening in the west wall slides"+
      " soundlessly closed.");
      "/d/newbie/rooms/keep/keep35"->remove_exit("west");
      return 1;
   }
   else {
      tell_object(TP,"You turn the knob and a section of the east wall slides to the"+
      " side, revealing a passage.");
      tell_room(ETP,""+TPQCN+" turns a knob and a section of the east wall slides to"+
      " the side to reveal a passage.",TP);
      add_exit(ROOMS+"keep35","east");
      tell_room("/d/newbie/rooms/keep/keep35","A section of the west wall slides to"+
      " the side, revealing a passage.");
      "/d/newbie/rooms/keep/keep35"->add_exit(ROOMS+"keep36","west");
      return 1;
   }
}
