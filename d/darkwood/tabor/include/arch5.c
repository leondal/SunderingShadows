#include <std.h>
#include "../include/tabor.h"
inherit ROOM;

void create(){
    object ob;
   ::create();
   set_property("no teleport",1);
   set_terrain(BARREN);
   set_travel(DIRT_ROAD);
    set_short("Archery range");
    set_long("You are in Tabor's Archery range, better be careful!");
    set_exits( ([
    "south" : "/d/darkwood/tabor/include/arch4",
    "north" : "/d/darkwood/tabor/include/arch6",
    ]) );
    ob = new("/std/obj/target");
    ob->set_difficulty(50);
    ob->move(TO);
}
