#include <std.h>
#include "keep.h"
inherit VAULT;

void create()
{
   ::create();
   set_property("indoors",1);
   set_property("light",1);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_short("The Conference Room");
   set_long(
   "You are standing in what once was most likely a conference room for the officers"+
   " of the keep. There is a large rectangular table in the middle with chairs around"+
   " it and a very crude map of the surrounding areas placed in the center of the"+
   " table. There are paintings on the north and south walls, and a %^BOLD%^%^BLACK%^pedestal%^RESET%^ with a"+
   " statue on the southeastern corner."
   );
   set_smell("default","The room is filled with dust.");
   set_listen("default","Everything is fairly quiet here.");
   set_items(([
   "table" : "There is a large rectangular table made of cherry wood in the center"+
   " of the room. A very crude map of the surrounding area is displayed in the"+
   " center, but it is so old and out-dated that it doesn't show you anything useful.",
   "chairs" : "There are six chairs surrounding the table, they are made of matching"+
   " cherry wood and are padded for comfort.",
   "paintings" : "There are paintings here, one on the north wall and one on the"+
   " south wall. They were probably expensive when they were new, but they have not"+
   " endured their time in the dust very well and the paint is chipping and the"+
   " tapestry decaying.",
   "pedestal" : "%^BOLD%^%^BLACK%^There is an ebony pedestal in the southeastern corner"+
   " with a beautiful %^WHITE%^ivory statue%^BLACK%^ carved into the shape of a dragon.",
   ({"statue","ivory statue","dragon statue"}) : "%^WHITE%^%^BOLD%^This is a beautiful"+
   " and carefully worked piece of ivory that has been carved into the shape of a"+
   " standing dragon. The wings extend outward and are incredibly detailed. The"+
   " exquisite craftsmanship makes you want to reach out and touch it.",
   "floor" : "The floor is covered in dust, it's obvious no one comes here anymore.",
   ]));
   set_exits(([
   "west" : ROOMS+"keep10",
   ]));
   set_door("door",ROOMS+"keep10","west");
   set_locked("door",1,"lock");
   lock_difficulty("door",20,"lock");
   set_search("statue","As you search the statue you realize that you could %^BOLD%^move%^RESET%^ the wings.");
}

void reset()
{
   ::reset();
   set_exits((["west" : ROOMS+"keep10"]));
}

void init()
{
   ::init();
   add_action("touch","touch");
   add_action("move","move");
}

void touch(string str)
{
   if(str != "dragon" && str != "statue" && str != "wings") {
      tell_object(TP,"Why would you want to touch THAT??");
      return 1;
   }
   tell_object(TP,"%^BOLD%^You reach out and gently touch the ivory statue. It"+
   " is cold and smooth to the touch, and the craftsmanship is excellent. On"+
   " touching the wings you realize that you can make them move...you wonder what"+
   " would happen if you did so.");
   tell_room(ETP,""+TPQCN+" reaches out and touches the ivory statue.",TP);
   return 1;
}

void move(string str)
{
   if(str != "wings" && str != "dragon" && str != "statue") {
      tell_object(TP,"Move what?");
      return 1;
   }
   if(member_array("east",ETP->query_exits()) != -1) {
      tell_object(TP,"You hear a click as you move the wings of the statue down and"+
      " the east wall closes.");
      tell_room(ETP,"You hear a click as "+TPQCN+" moves the wings of the statue and"+
      " the east wall closes.",TP);
      remove_exit("east");
      tell_room("/d/newbie/rooms/keep/keep38","You hear a click and the west wall"+
      " slides back into place, closing the passage.");
      "/d/newbie/rooms/keep/keep38"->remove_exit("west");
      return 1;
   }
   else {
      tell_object(TP,"You move the wings of the statue upwards and hear a click as"+
      " the east wall slides to the side, revealing a secret passage.");
      tell_room(ETP,""+TPQCN+" moves the wings of the statue and you hear a click as"+
      " the east wall slides to the side to reveal a passage.",TP);
      add_exit(ROOMS+"keep38","east");
      tell_room("/d/newbie/rooms/keep/keep38","You hear a click as the west wall"+
      " slides open, revealing a passage.");
      "/d/newbie/rooms/keep/keep38"->add_exit(ROOMS+"keep39","west");
      return 1;
   }
}
