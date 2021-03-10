#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;

void create(){
  ::create();
  set_indoors(1);
  set_light(1);
  set_property("no teleport",1);
  set_property("used sticks",1);
  set_short("Temple Waiting area");
  set_long(
@DESC
   %^BOLD%^%^RED%^Temple Waiting Area%^RESET%^
You are standding before two large stone doors. Much like the last
three rooms, they stand sealed before with the great symbol of ibrandul.
This room has no use at all. Looks as if it was built sealed and left.
Will the rest of the temple be this desolate. Is Ibrandul really dead?


DESC
  );
  set_listen("default","The lava flowing under your feet makes a strange buzzing sound.");
  set_smell("default","You smell the burning lava and hot rocks.");
  set_exits(([
    "out":LAVA+"temple2",

  ]));

  set_items(([
   "doors":"These are large stone doors. They have a great seal on them embedded with a symbol.",
   "seal":"This is a great metal seal. It holds the doors fast. It has a great symbol in it.",
   "symbol":"This is a collect of 4 rings. One on top, one on the bottom, one to the right, one to the left. The ring on the east is just a carving, as if the ring itself is missing. Looks as if one needs to be inserted."
   ]));
}

void init(){
   ::init();

   add_action("insert","insert");

}

int insert(string str){
   object ob;
   if(!str){
      return notify_fail("insert what?\n");

   }

   if(strsrch(str,"ring") == -1){
      return notify_fail("You can't insert that.\n");
   }

   if(!ob=present(str,TP)){
      return notify_fail("You don't have that.\n");

   }

   if(!ob->id("east")){
      return notify_fail("That is not the right ring.\n");
   }
   ob->remove();

   tell_room(TO,"%^RED%^In a blaze of fire the North Ring is placed in the spot.");
   tell_room(TO,"%^RED%^With a creak and a snap the seal is broken and the door creaks open.");
   add_exit(LAVA+"temple4","enter");
   return 1;
}

void reset(){
   ::reset();
   remove_exit("enter");
}
