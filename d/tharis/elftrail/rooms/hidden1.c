//hidden.c
#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){
  ::create();
   set_terrain(LIGHT_FOREST);
   set_travel(FOOT_PATH);
  set_property("light",1);
  set_short( "dense forest" );
  set_long(
  "Glade in the dense forest.\n"
  "  %^CYAN%^The forest closes in on all sides of this forest path."
  "  The forest is old here.  "
  "  The woods start to thin as you climb higher towards the"+
  " mountains edges."
  "  There are fallen down trees all around here. "+
  " It looks like this older part of the wood has"+
  " been claimed by nature."
  "\n"
  );
  set_smell("default",
  "You can smell the fresh scent of pines and forest air."  );
  set_listen("default",
  "The wind whistles through the trees."  );
  set_search("default","The thick trees make you wonder"+
  " what could be hidden behind their trunks.");
  set_search("trees","Searching the trees, you think you"+
  " see a path leading off to the east.");
  set_search("room",(:TO,"search_room":)); 
  set_items(([
  "trees":"They start to thin to more scrubby types to the northwest.",
  "path":"If there was a path it is hard to tell.",
  ]));
  set_exits(([
  "west":ROOMS"elfpath005",
  ]));
}
int search_room(string str){
     if(present("stone",TO)) return 0;
     tell_object(TP,"You dig through the bush and find"+
         " a strange stone covered with odd symbols.");
         new("/d/islands/elf/obj/pstone1")->move(TO);
      return 1;
}
