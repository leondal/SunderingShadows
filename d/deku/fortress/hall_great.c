#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(DIRT_ROAD);
    set_short("The Great Hall");
    set_long(
@KAYLA
%^YELLOW%^Great Hall%^RESET%^
A long oak table with many chairs lies in the middle of this
chamber.  To the west a large wall hanging depicts a red wyvern
on a black background.  Below this an immense fireplace is set
into the stone.  A large and very ornate wooden chest rests
against the middle of the north wall.  A tall wooden cabinet 
stands in the southwest corner.
KAYLA
    );
    set_smell("default","A faintly nauseating smell of death and decay hangs in the air.");
    set_exits(([
       "east" : "/d/deku/fortress/hallN1"
    ] ));
    set_items(([
       "chest" : "This ten foot long chest is, in fact, a sarcophagus.",
       "cabinet" : "This cabinet holds silver table setting.",
	"table" : "A large oval oak table that occupies the middle of this chamber."
    ] ));
}

void reset() {
  ::reset();
  if(!present("stone giant")) {
    new("/d/deku/fortress/monster/stone")->move(TO);
  }
  if(!present("cloud giant")) {
    new("/d/deku/fortress/monster/cloud")->move(TO);
  }
  if(!present("hill giant")) {
    new("/d/deku/fortress/monster/hill")->move(TO);
  }
}
