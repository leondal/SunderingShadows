#include <std.h>
#include <move.h>
#include <daemons.h>
#include "../tecqumin.h"

inherit ROOM;


string long_desc();

void create() {
  ::create();
  set_exits( ([ "southeast" : TEST + "start" ]) );
}

void reset(){
  object quali;
  ::reset();
  quali = present("quali", TO);
  if (!objectp(quali)){
    quali = new(MOB + "quali.c");
    quali->move(TO);
  }
}

