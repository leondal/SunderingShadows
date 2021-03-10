#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("Vault of the Serpent");
    set_long(
@KAYLA
%^RED%^Vault of the Serpent%^RESET%^
As your torches illuminate this chamber, you see a large statue in
the center of the room.  The statue is made of stone and resembles
a large humanoid with a bulls head.  The hands of the statue are
held out and hold a velvet cushion.  Encircling the statue on the
floor is a 20' diameter mosaic of a black dragon.
KAYLA
    );
    set_exits(([
       "east" : "/d/deku/fortress/hallN7"
    ] ));
    set_items(([
"cushion" : "The velvet cushion holds a red necklace in the form of a snake",
"statue" : "This statue is made of stone and resembles a large humanoid with a bull's head",
    ] ));
}

void reset() {
  ::reset();
   if(!present("giant serpent")) {
      new("/d/deku/monster/serpent")->move(TO);
  }
}
