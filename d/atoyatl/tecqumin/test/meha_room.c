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
  set_name("In a side room in a palace");
  set_short("In a side room in a palace");
  set_long( "This is a small, minimally furnished room inside the Tecqumin"
           +" palace. There's not much more to say about it, really."
           +" There'll"
           +" probably be more description in the finished room, but it'll"
           +" be pretty much all padding. Unless I change my mind about"
           +" that, or I'm just playing a sneaky trick to make you miss"
           +" something fun in the final version." );
  set_items(([  ]));
  set_smell("default","There is a damp, musty smell in here.");
  set_listen("default","The only sounds drift in from the jungle outside.");
  set_exits( ([ "northwest" : TEST + "start.c" ]) );
}

void reset(){
  object mehaq;
  ::reset();
  mehaq = present("mehaq", TO);
  if (!objectp(mehaq)){
    mehaq = new(MOB + "empress.c");
    mehaq->move(TO);
  }
}