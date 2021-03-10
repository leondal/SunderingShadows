#include <std.h>
#include "../../tecqumin.h"
inherit ROOM;

void create(){
    object ob;
   ::create();
   set_property("no teleport",1);
   set_travel(DIRT_ROAD);
   set_terrain(BARREN);
    set_short("Archery range");
    set_long("You are in the tabaxi Archery range, better be careful!");
    set_exits( ([
         "east" : TABAXROOM+"archery",
    ]) );
    ob = new("/std/obj/target");
    ob->set_difficulty(10);
    ob->move(TO);
}
