//m4.c

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;

int taken;

void create(){
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("Old Library");
   set_short("Old Library");
   set_property("no teleport",1);
   set_property("indoors",1);
   set_property("light",2);
   set_long(
@OLI
   %^ORANGE%^An Old Library%^RESET%^
%^RESET%^This is an old library. Many eons of %^BOLD%^knowledge%^RESET%^ must be stored here.
Secrets of time, space, history and the future reside here. Large
old %^ORANGE%^shelves%^RESET%^ rise high into the ceiling here. %^MAGENTA%^Books%^RESET%^ are stacked neatly
in some places, thrown in in others. One book stands out a bit. %^BOLD%^Dust%^RESET%^
covers most of the stacks, but some of them look as if they are frequently used. The monks must study here.
OLI
   );

   set_items(([
      "books":"These books look used and old. Great knowledge is stored here. A single book seems to stand out here.",
      "book":"This book is larger brighter and not quite right.",
      "shelves":"You notice the shelves here are full of dusty, must covered books.",

      ]));
   set_exits(([
       "east":MONASTERY+"m24",
       "south":MONASTERY+"m23",
      "north":MONASTERY+"m21",
      ]));
   set_smell("default","An odor of must and dust is dominant here.");
   set_listen("default","You seem to hear long dead whispers.");
}

void init(){
   ::init();
   add_action("take","take");
}

int take(string str){
   if(!str || str != "book"){
      return notify_fail("Take what?\n");
   }

   if(taken){
      return notify_fail("There is no book there now.\n");
   }
   taken = 1;

   write("As you reach for the book it leaps from your grasp and lands on the floor.");
   tell_room(TO,"As "+TPQCN+" reaches for the book, it leaps from "+TP->query_possessive()+" grasp and lands on the floor.",TP);
   new(OBJ+"book")->move(TO);
   return 1;
}

void reset(){
   ::reset();
   taken = 0;
}
