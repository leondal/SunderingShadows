#include <std.h>
#include "keep.h"
inherit ROOM;

void create()
{
   ::create();
   set_property("indoors",1);
   set_property("light",1);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_short("A secret passage");
   set_long(
   "You are standing in a hidden passage adjacent to the mage's study. It is"+
   " fairly dusty and probably hasn't been used in some time. There is a lever"+
   " on the eastern wall that you can probably pull to open and close the"+
   " northern passage. You can't make out much to the west, but the passage"+
   " continues in that direction."
   );
   set_smell("default","Dust from the passage tickles your nose.");
   set_listen("default","Everything is fairly quiet.");
   set_items(([
   "lever" : "There is a lever on the wall here, perhaps you should pull it?",
   ]));
   set_exits(([
   "west" : ROOMS+"floor7",
   ]));
}

void init()
{
   ::init();
   add_action("pull","pull");
}

void reset()
{
   ::reset();
   set_exits((["west" : ROOMS+"floor7"]));
}

void pull(string str)
{
   if(str != "lever")
      return notify_fail("Pull what?\n");
   if(member_array("north",ETP->query_exits()) != -1) {
      tell_object(TP,"You pull the lever and watch as a section of the wall"+
      " slides across to close the northern passage.");
      tell_room(ETP,""+TPQCN+" pulls the lever and you see a section of the wall"+
      " slide across to close the northern passage.",TP);
      remove_exit("north");
      "/d/newbie/rooms/keep/floor5"->remove_exit("south");
      tell_room("/d/newbie/rooms/keep/floor5","The southern bookshelf slides"+
      " back into place, closing the secret passage.");
      return 1;
   }
   else {
      tell_object(TP,"You pull the lever and hear a grinding noise as the wall"+
      " slides open to reveal a doorway on the north.");
      tell_room(ETP,""+TPQCN+" pulls a lever and you hear a grinding noise as the"+
      " wall slides open to reveal a doorway on the north.",TP);
      add_exit(ROOMS+"floor5","north");
      "/d/newbie/rooms/keep/floor5"->add_exit(ROOMS+"floor6","south");
      tell_room("/d/newbie/rooms/keep/floor5","The southern bookshelf slides"+
      " to the side, revealing a passage to the south.");
      return 1;
   }
}
