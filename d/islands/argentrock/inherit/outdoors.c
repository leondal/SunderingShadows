//Outdoor room inherit -- Yves
#include <std.h>
#include "/../argabbr.h"
inherit CROOM;

void create(){
  ::create();
  set_terrain(BRANCHES);
  set_travel(LEDGE);
  set_property("indoors",0);
  set_property("light",2);
  set_name("platform");
  set_short("A hidden platform in the trees of Argentrock Forest");
  set_smell("default","Fresh breaths of the forest restore you.");
  set_listen("default","You hear gusts of wind blow through the forest.");
}

