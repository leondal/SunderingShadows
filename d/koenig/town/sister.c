#include <std.h>
inherit "/std/room";

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light",0);
  set_property("indoors", 1);
  set_short("Inside the Painting");
  set_long("%^CYAN%^You are inside of the painting now, adventurer, and you find that rather hard to "+
"believe! You are standing upon a %^ORANGE%^beach%^CYAN%^ with cliffs behind you, and "+
"much to your surprise the %^GREEN%^three hags%^CYAN%^ from the painting now stand before you with "+
"but one thought on their minds: To %^BOLD%^%^RED%^kill%^RESET%^%^CYAN%^ you before you can escape!");
  set_smell("default", "You smell something like sea water.%^RESET%^\n");
  set_listen("default", "You hear strange and unreassuring noises.");
  set_exits( ([
     "out" : "/d/koenig/town/house4"
           ]) );
}

void reset() {
  ::reset();
  if(!present("vexia")) {
    new("/d/koenig/town/mon/vexia")->move(this_object());
  }
  if(!present("magglerak")) {
    new("/d/koenig/town/mon/magglerak")->move(this_object());
  }
  if(!present("thess")) {
    new("/d/koenig/town/mon/thess")->move(this_object());
  }
}
