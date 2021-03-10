//msecret.c

#include <std.h>
#include "../tharis.h"

inherit VAULT;

void create(){
   ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
   set_property("light",1);
   set_property("indoors",1);

   set_short(
@JAVAMAKER
Storage Room for the Merchants' Guild
JAVAMAKER
   );

   set_long(
@JAVAMAKER
    Storage Room for the Merchants' Guild
This room is stacked with papers and receipts and accounting
stuff. The musty and dry air in this room must keep some of the
papers safe but you notice that those toward the back and the
bottom are closer to the original state of dust then anything else.
legible.
JAVAMAKER
   );

   set_smell("default","Dust and mold attack your senses.");
   set_listen("default","This is a silent place.");
   set_items(([
      "papers":"There are probably hundreds of papers here, many in varying languages.  You might be able to read through some of them.",
   ]));

   set_exits(([
      "out":ROOMS"merchant",
   ]));

   set_invis_exits(({}));
   set_trap_functions(({}),({}),({}));
   set_pre_exit_functions(({}),({}));
   set_post_exit_functions(({}),({}));
}


void reset(){
   ::reset();

}

void init(){
   ::init();
    add_action("read","read");
}


int read(string str){
     if(!str || (str != "paper" && str != "papers")) return 0;
     write("As you try to pick up or move the papers, most of them crumble.  "
       "What you can make out seems to be related to old business along with "
       "some of the Tharis government's records related to controlling the "
       "local elves.");
     return 1;
}
