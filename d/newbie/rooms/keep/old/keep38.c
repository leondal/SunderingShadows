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
   " the footsteps of anyone walking around back here. You notice a button on the"+
   " wall to the southwest."
   );
   set_smell("default","The passage is filled with dust.");
   set_listen("default","Everything is fairly quiet.");
   set_items(([
   "floor" : "The floor has a rug laid out across it and is covered in dust.",
   "rug" : "The rug appears faded and rather worn, it was probably placed here to"+
   " keep footsteps from echoing and giving the secret passage away. It extends"+
   " to the north and east.",
   "button" : "There is a button on the south side of the west wall, perhaps you"+
   " could push it?",
   ]));
   set_exits(([
   "north" : ROOMS+"keep40",
   "east" : ROOMS+"keep36",
   ]));
}

void reset()
{
   ::reset();
   set_exits((["north" : ROOMS+"keep40","east" : ROOMS+"keep36"]));
}

void init()
{
   ::init();
   add_action("push","push");
}

void push(string str)
{
   if(str != "button") {
      tell_object(TP,"Push what?");
      return 1;
   }
   if(member_array("west",ETP->query_exits()) != -1) {
      tell_object(TP,"You hear a click as you push the button and the west wall slides"+
      " back into place, closing the passage.");
      tell_room(ETP,"You hear a click as "+TPQCN+" pushes a button, the west wall"+
      " slides shut, closing the passage.",TP);
      remove_exit("west");
      tell_room("/d/newbie/rooms/keep/keep39","You hear a click and the east wall"+
      " slides shut, closing the passage.");
      "/d/newbie/rooms/keep/keep39"->remove_exit("east");
      return 1;
   }
   else {
      tell_object(TP,"You push the button and hear a click as the west wall slides"+
      " to the side, revealing a doorway.");
      tell_room(ETP,"You hear a click as "+TPQCN+" pushes a button, the west wall"+
      " slides open, revealing a passage.",TP);
      add_exit(ROOMS+"keep39","west");
      tell_room("/d/newbie/rooms/keep/keep39","You hear a click and the east wall"+
      " slides to the side, revealing a hidden passage.");
      "/d/newbie/rooms/keep/keep39"->add_exit(ROOMS+"keep38","east");
      return 1;
   }
}
