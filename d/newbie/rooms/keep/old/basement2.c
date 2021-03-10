#include <std.h>
#include "keep.h"
inherit VAULT;

int STONE;

void create()
{
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
   set_property("indoors",1);
   set_property("light",1);
   set_short("A secret basement");
   set_long(
   "This is part of a short passageway in the secret basement you've found."+
   " Straight north appears to be a dead end. There is a large door on the"+
   " west that appears to be in perfect condition. On the east it looks as"+
   " though there is a doorway, but if so, the door is made of stone and has"+
   " no knob. You don't see an easy way to open it."
   );
   set_smell("default","The faint scent of charred flesh lingers in the air.");
   set_listen("default","The silence is eerie.");
   set_items(([
   "hole" : "There is a tiny hole to the right of the stone doorway, it"+
   " almost looks like you could %^BOLD%^insert%^RESET%^ an item into it,"+
   " but it is a very unusual shape.",
   "doorway" : "The doorway is made of solid stone that is a slightly"+
   " lighter color than the walls. It is perfectly smooth, and has no knob"+
   " or any other apparent way to open it. Upon closer inspection, however,"+
   " you see a small hole on the right of the doorway.",
   "door" : "There is a large, sturdy door on the west.",
   "walls" : "The walls are unnaturally smooth, forming perfect angles with"+
   " the floor and ceiling. On the west wall there is a large and sturdy"+
   " door. On the right there appears to be another doorway, but it is made"+
   " of solid stone.",
   "ceiling" : "The ceiling is flat and smooth, very unnatural.",
   "floor" : "The floor is level and smooth.",
   ]));
   set_exits(([
   "south" : ROOMS+"basement1",
   "north" : ROOMS+"basement5",
   "west" : ROOMS+"basement3",
   ]));
   set_door("door",ROOMS+"basement3","west","keep master_key");
   set_locked("door",1,"lock");
   lock_difficulty("door",20,"lock");
}

void init()
{
   ::init();
   add_action("insert","insert");
}

void insert(string str)
{
   object obj;

   if(!str) {
      tell_object(TP,"Try insert <item> into hole");
      return 1;
   }
   if(STONE == 1) {
      tell_object(TP,"There is already something in the hole!");
      return 1;
   }
   if(str != "stone into hole") {
      tell_object(TP,"Try insert <item> into hole");
      return 1;
   }
   if(!present("keep_stone",TP)) {
      tell_object(TP,"The stone you have doesn't seem to fit, you had"+
      " better find another one.");
      return 1;
   }
   else {
      STONE = 1;
      add_exit(ROOMS+"basement4","east");
      tell_object(TP,"The stone fits perfectly!");
      tell_room(TP,""+TPQCN+" inserts a stone into the hole.",TP);
      obj = present("keep_stone",TP);
      obj->remove();
      tell_room(TP,"The stone portal slowly slides open.");
      add_item("hole","There is a slight indentation in the eastern wall"+
      " to the right of the portal, but it is filled.");
      set_long("This is part of a short passageway in the secret basement"+
      " you've found. Straight north appears to be a dead end. There is a"+
      " large door on the west that appears to be in perfect condition. On"+
      " the east it looks as though there is a stone archway.");
      return 1;
   }
}
