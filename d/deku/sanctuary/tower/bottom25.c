#include <std.h>
#include "../dragon.h";

inherit BBVAULT;

void create() {
   ::create();
   set_long(
      "%^BOLD%^%^BLACK%^This room is full of broken crates. Some are empty"+
      " and some are leaking their contents out onto the water covered floor."+
      " The crates are strewn about the floor in a careless manner as if someone"+
      " or something was in a rage as it walked through the room. The walls and"+
      " ceiling are in good shape when you take into consideration how long this"+
      " place must have been abandoned. The water is not so high here, as there"+
      " is a large grate in the middle of the floor to deal with such problems."
   );
   set_items( ([
      ({"floor","ceiling","walls"}) : "The floor, ceiling, and walls are all in good shape and appear to be sturdy.",
      "crates" : "Most of the crates are busted open and sporadically tossed about the room.",
      "grate" : "The grate is a drain for the water.",
   ]) );
   set_exits( ([
      "door" : TOWER+"bottom07",
      "south" : TOWER+"bottom24",
   ]) );
   set_door("door",TOWER+"bottom07","door","cellar key");
}

void reset() {
   ::reset();
   if(!present("goblin")) {
      new(GOBO)->move(TO);
      new(GOBO)->move(TO);
      new(GOBO)->move(TO);
      new(GOBO)->move(TO);
      new(GOBO)->move(TO);
      new(GOBO)->move(TO);
      new(GOBO)->move(TO);
   }
}
