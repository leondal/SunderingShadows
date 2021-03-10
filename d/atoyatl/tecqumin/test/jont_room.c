#include <std.h>
#include <move.h>
#include <daemons.h>
#include "../tecqumin.h"

inherit ROOM;


string long_desc();

void create() {
  ::create();
  set_indoors(1);
  set_property("light", 2);
  set_terrain(STONE_BUILDING);
  set_travel(PAVED_ROAD);
  set_name("Somewhere in a Ziggurat");
  set_short("Somewhere in a Ziggurat");
  set_long( (:TO, "long_desc":) );
  set_items(([  ]));
  set_smell("default","There is a damp, musty smell in here.");
  set_listen("default","The only sounds drift in from the jungle outside.");
  set_exits( ([ "south" : TEST + "start.c" ]) );
}
void init() {
   ::init();
}

void reset(){
  object jontar;
  ::reset();
  jontar = present("jontar", TO);
  if (!objectp(jontar)){
    jontar = new(MOB + "jontar.c");
    jontar->move(TO);
  }
}

string long_desc(){
  return "This is a musty room somewhere in the interior of a Tecqumin"
         +" ziggurat. There should be the ghost of a priest here. If not,"
         +" please complain vociferously";
}
