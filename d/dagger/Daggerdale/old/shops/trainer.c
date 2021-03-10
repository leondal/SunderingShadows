#include <std.h>

inherit ROOM;

void create(){
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);

    set_short("Daggerdale training arena");
   set_long(
      "You have entered the great training room in Daggerdale.  All around you is blood splattered on the walls from 'mistakes' in training.  You hope that you will be luckier as you look over the giant that is to be your trainer with a shudder."
   );
   set_light(2);
   set_indoors(1);
   set_exits(([
   "north" : "/d/dagger/Daggerdale/streets/street20",
  ]));
 }


 void reset(){
    ::reset();
    if(!present("mykadok"))
      new("/d/dagger/Daggerdale/shops/npcs/mykadok.c")->move(TO);
 }
