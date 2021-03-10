#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_short("Southeast corner of Tanar road");
  set_long(
  "Southeast corner of Tanar road.\n"
  "  Tanar road goes north and west here along the edges of Torm proper."
    "  A set of stairs lead up to the walls which continue out into the water."
  "  A long boardwalk leads out onto the Dagger Sea and you can see a ship docked at its north side, with many sailors offloading goods."
    "  You can see northeast across the harbor here many more ships maneuvering about the other docks and boardwalks and finally the far corner of the city where the walls lead off into the water."
  );
  set("night long",
  "%^BLUE%^"
  "The air here is a bit chilly and the ever present fog is still"+
  " covering the ground.  Stairs lead up out of the fog onto the city"+
  " walls and a boardwalk leads east onto the shadowy Dagger Sea.  Tanar"+
  " here goes north and west following the edges of the city, although"+
  " you can't see very far down them."
  );
  set_exits(([
  "up":TCITY+"c90",
  "north":TCITY+"c76",
  "east":TCITY+"c84",
  "west":TCITY+"c82",
  ]));
}
