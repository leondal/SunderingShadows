//m4.c

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;

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
in some places, thrown in in others. %^BOLD%^Dust%^RESET%^ covers most of the stacks,
but some of them look as if they are frequently used.
OLI
   );

   set_items(([
      "books":"These books look used and old. Great knowledge is stored here. One book looks frequently used, or at least frequently taken.",
      "shelves":"You notice the shelves here are full of dusty, must covered books, except for one book.",
      "book":"One of the many books here looks well refered to. As if many people have taken it in the past.",
      ]));
   set_smell("default","An odor of must and dust is dominant here.");
   set_listen("default","You seem to hear long dead whispers.");
}

void init(){
   ::init();

   add_action("take","take");
}

int take(string str){
   if(!str || str != "book")
      return notify_fail("Take what?\n");

   if(flag){
      write("You take the book but you notice it pulls, but nothing happens.");
      return 1;
   }

   flag = 1;
   add_exit(MONASTERY+"m17","east");
   tell_room(TO,"%^BOLD%^As "+TPQCN+" tries to take a book from the shelves a wall slides back revealing a passage.",TP);
   write("You take the book but you notice it pulls, you hear a sliding behind you.");
   return 1;

}

void reset(){
   ::reset();
   remove_exit("east");
   flag = 0;
}
