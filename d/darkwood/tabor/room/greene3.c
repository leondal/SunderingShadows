//updated by Circe 6/2/04 with color, etc.
// Greene Street, Tabor
// Thorn@ShadowGate
// 000922
// Tabor
// greene3.c
// added random guard spawn by *Styx* 9/18/05

#include <std.h>
#include "../include/tabor.h"

inherit CROOM;

void create() {
  set_monsters( ({ "/d/darkwood/tabor/mon/guard" }), ({random(3)+1}) );
  monster_party(40);
  ::create();
  set_travel(DIRT_ROAD);
  set_terrain(CITY);
  set_light(2);
  set_name("Greene Street, Tabor");
  set_short("Greene Street, Tabor");
  set_long(
@TABOR
%^BOLD%^Greene Street, Tabor%^RESET%^
You are standing near the %^BOLD%^%^BLACK%^Town Gaol %^RESET%^in Tabor. Here you are looking at
the side of the %^BOLD%^%^BLACK%^prison %^RESET%^and see a few barred windows with those
imprisoned looking out at you with mixed expressions of sadness and
anger. To the north, you see a intersection with an east-west street
that appears to be the end of %^GREEN%^Greene Street%^RESET%^.

%^GREEN%^Greene Street %^RESET%^continues to the south.
%^BOLD%^%^BLUE%^Gwydion Street %^RESET%^is just to the north.
TABOR
    );
  set_exits(([
    "south" : ROOMDIR+"greene2",
    "north" : ROOMDIR+"gwy5"
  ]));
  set_listen("default","You hear the sounds of a busy town all around you.");
  set_smell("default","The slightly rank scent of a busy city "+
    "lingers in the air.");
  set_items(([
    "gaol" : "The gaol is not much to look at, but it is most defintely a prison.",
  ]));
}

void reset(){
  ::reset();
  if(!present("street_light",TO))
    new("/d/common/obj/misc/street_light")->move(TO);
}

