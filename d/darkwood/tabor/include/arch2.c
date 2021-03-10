#include <std.h>
#include "../include/tabor.h"
inherit ROOM;

void create(){
    object ob;
   ::create();
   set_property("no teleport",1);
   set_travel(DIRT_ROAD);
   set_terrain(BARREN);
    set_short("Archery range");
    set_long("You are in Tabor's Archery range, better be careful!");
    set_exits( ([
    "south" : "/d/darkwood/tabor/include/arch1",
    "north" : "/d/darkwood/tabor/include/arch3",
    ]) );
    ob = new("/std/obj/target");
    ob->set_difficulty(20);
    ob->move(TO);
}
