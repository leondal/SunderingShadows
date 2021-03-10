#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit GARDENBASE;

void create() {
  ::create();
  set_exits( ([ "east" : CITY_ROOM + "garden_east"]) );
}

void init(){
  ::init();
}

