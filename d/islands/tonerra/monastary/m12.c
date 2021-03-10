//m1.c

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;

void create(){
   ::create();
   set_terrain(SCRUB_LANDS);
   set_travel(GAME_TRACK);
   set_short("An open plain");
   set_property("light",2);
   set_property("no teleport",1);
   set_long(
@OLI
   %^BOLD%^%^GREEN%^An open plain%^RESET%^
%^RESET%^%^GREEN%^The grass seems beaten down here. Upon closer inspection you
see signs of %^RED%^blood%^GREEN%^ and some bits of %^RESET%^steel%^GREEN%^ or %^RESET%^iron%^GREEN%^. It seems that the
culmination of this journey through the plains has led you to here. Why?%^RESET%^
OLI
   );
   set_items(([
      "grass":"The grass appears to be beaten down by movement, like someone had done a lot of stomping around.",
      ]));
   set_smell("default","The smells of green grass and some thistle greet you.");
   set_listen("default","The wind blows lightly by. In the distance you hear a grunt.");
   set_exits(([
      "east":MONASTERY+"m9",
      "west":MONASTERY+"m15",
      "north":MONASTERY+"m8",
      "south":MONASTERY+"m10",
      ]));
}

void reset(){
   ::reset();
   if(!present("statue")){
      new(OBJ+"statue")->move(TO);
   }
}

