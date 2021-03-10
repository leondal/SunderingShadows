#include <std.h>
#include "../juran.h"

inherit ROOM;

create() {
        ::create();
set_light(-1);
   set_indoors(1);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_short("Fighters' antechamber");
   set_long("%^BOLD%^%^WHITE%^"
      "Welcome to the Juran Fighters' guild.  "+
      "You see grisly trophies that were taken in battle "+
      "along the walls of the room.  You see an entrance to "+
      "the fighter's store to the north."
        );
   set_exits( ([
        "southwest" : JROOMS+"r34",
        "north" : JROOMS+"fg2",
   ]) );
}
