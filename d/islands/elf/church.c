#include <std.h>
#include "elf.h"
inherit "/std/church.c";

void create() {
  ::create();
  set_terrain(ICE);
  set_travel(SLICK_FLOOR);
  set_property("light",3);
  set_climate("arctic");
  set_name("Shrine in the snow");
  set_property( "light", 2);
  set_property( "indoors", 0);
  set_short("%^BOLD%^%^WHITE%^A small shrine" );
  set_long("%^CYAN%^This is a small shrine that is unmanned out "+
  "in the cold next to the walls.  Travelers often stop here"+
  " to pray for for their trip before heading out into the"+
  " cold.  The whole shrine is covered in snow and ice but"+
  " it is large enough to still be noticeable.  To the north"+
  " is a frost covered wall and to the west leads back to the gate. " );
   set_exits( ([
      "west": ROOMS"gate",
      ]) );
  set_smell( 
   "default", "You smell the purity of the snow. ",   );
  set_listen( 
   "default", "You hear the sound of souls in peace. ",   );
}
