#include <std.h>
inherit STABLE;

void create() {
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
  set_property("light", 1);
  set_property("indoors",1);
  set_short("The Stables of Muileann");
  set_long("%^RESET%^%^CYAN%^You have entered the stables of Muileann. This is where visitors of the town, such as yourself, can leave their horses for tending, but it is very much at your own risk. This probably comes as no surprise to you, but things around here have a habit of turning up %^BOLD%^dead%^RESET%^%^CYAN%^. There's a sign here you could %^BOLD%^read%^RESET%^%^CYAN%^, if you're interested in making a purchase.%^RESET%^\n");
  set_smell("default", "You smell fresh hay, manure, and leather.");
  set_listen("default","You hear the neighing of many mounts back in the "
             "stable area.");
  set_exits( ([
     "out":"/d/koenig/town/room1.c",
          "up" : "/d/koenig/town/stable2.c"
]) );
  set_animal(({"horse","pony","donkey"}),({"/d/shadow/mon/horse","/d/common/mounts/pony","/d/common/mounts/donkey"}));
  set_animal_price(({"horse","pony","donkey"}),({75,45,30}));
  set_stalls(10);
  ::fill_stalls();
}

void reset()
{
  ::reset();
  if(!present("tanner"))
    new("/d/koenig/town/mon/tanner.c")->move(this_object());
}