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
  set_name("Off to one side of the throne room");
  set_short("Off to one side of the throne room");
  set_long( "This room is off to one side from the throne room. Like where"
           +" the ruler's advisor type might be." );
  set_items(([  ]));
  set_smell("default","There is a damp, musty smell in here.");
  set_listen("default","The only sounds drift in from the jungle outside.");
  set_exits( ([ "west" : TEST + "start.c" ]) );
}

void reset(){
  object taluc;
  ::reset();
  taluc = present("taluc", TO);
  if (!objectp(taluc)){
    taluc = new(MOB + "taluc.c");
    taluc->move(TO);
  }
}

