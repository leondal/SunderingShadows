#include "elf.h"
#include <std.h>

inherit ROOM;

void create(){
    object ob;
   ::create();
    set_terrain(VILLAGE);
    set_travel(DIRT_ROAD);
    set_short("Archery range");
    set_long("This is one of the rooms housing archery "+
      "targets used by the trainer.  You realize this is a "+
      "VERY bad place to be, and you should probably "+
      "leave the quickest way you can!");
    set_exits( ([
    "south":ROOMS"arch",
      "north" : ROOMS"arch1",
    ]) );
      ob = new("/std/obj/target");
      ob->set_difficulty(20);
	  ob->set_overall_ac(-5);
      ob->move(TO);
}