#include <std.h>

int searched;

inherit WATER;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_terrain(DEEP_WATER);
    set_travel(FRESH_BLAZE);
    set_short("Underwater");
    set_long(
@KAYLA
You are underwater in the Shadowlord lake.  The water is very dirty
down here.  The lake bottom is filled with lots of stones and dark, murky
sand.
KAYLA
    );
    set_exits(([
       "out" : "/d/deku/open/cave"
    ] ));
    set_search("stones", (: TO,"find_stone":));
    set_search("sand", "You find a pile of stones!");
    set_items(([
    ] ));
}

int find_stone() {
  if(present("elemental")) {
    write("The elemental stirs the water up and it is hard to see.");
    return 1;
  }
  if( searched || !random(2) ) {
    write("You search the stones, but find nothing unusual.");
    searched = 1;
    return 1;
  }
  else {
    write("You find a %^RED%^red%^RESET%^ stone among the stones.");
    new("/d/deku/misc/red")->move(TO);
    searched = 1;
    return 1;
  }
}

void reset() {
  ::reset();
  searched = 0;
  if(!present("elemental")) new("/d/deku/monster/water")->move(TO);
}
