#include <std.h>
#include "keep.h"
inherit ROOM;

int FLAG;

void create()
{
   ::create();
   set_property("indoors",1);
   set_property("light",1);
   set_short("A secret basement");
   set_long(
   "You have come to a dead end in this basement. The ceiling, floor and"+
   " walls are as smooth as every place else, but in the center of the back"+
   " wall is a large hole. There is a lever to the right of it. To the south"+
   " the passage continues back to the stairs."
   );
   set_smell("default","The faint scent of charred flesh can still be smelt.");
   set_listen("default","The silence is eerie.");
   set_items(([
   "lever" : "The lever is in the up position. Maybe you could pull it to"+
   " move it downward.",
   "hole" : "The large hole in the center of the wall is open.",
   "walls" : "The walls are unnaturally smooth, forming perfect angles with"+
   " the floor and ceiling. There is a hole and a lever in the back wall.",
   "ceiling" : "The ceiling is flat and smooth, very unnatural.",
   "floor" : "The floor is level and smooth.",
   ]));
   set_exits(([
   "south" : ROOMS+"basement2",
   ]));
}

void init()
{
   ::init();
   add_action("pull","pull");
}

void pull(string str)
{
   if(str != "lever") {
      write("Pull what?\n");
      return 1;
   }
   if(FLAG == 1) {
      write("You pull the lever upwards and the hole opens.");
      tell_room(ETP,""+TPQCN+" pulls the lever upwards and the hole opens.",TP);
      add_item("hole","The large hole in the center of the wall is open.");
      add_item("lever","The lever is in the up position. Maybe you could"+
      " pull it to move it downward.");
      "/d/newbie/rooms/keep/basement1.c"->toggle_trap("north");
      FLAG = 0;
      return 1;
   }
   else {
      write("You pull the lever downwards and a stone moves into place to"+
      " block the hole.");
      tell_room(ETP,""+TPQCN+" pulls the lever downwards and a stone moves"+
      " in place to block the hole.",TP);
      add_item("hole","The hole in the wall is blocked by a stone.");
      add_item("lever","The lever has been pulled down.");
      FLAG = 1;
      "/d/newbie/rooms/keep/basement1.c"->toggle_trap("north");
      return 1;
   }
}
