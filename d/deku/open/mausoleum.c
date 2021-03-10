#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",0);
    set_terrain(CEMETERY);
    set_travel(FOOT_PATH);
    set_short("Mausoleum of the Fortress");
    set_long(
@KAYLA
The building before you was apparently designed to represent the 
enternal rest of the former lords of the Fortress, but beneath 
the current skies, lit only by lighting and wrapped in the clinging
fog, the structure has an ominous foreboding appearance.  A pair
of massive stone doors marks the face of the monument to death.
KAYLA
    );
    set_listen("default","You hear sounds of a eerie cry or moan.");
    set_smell("default","All around you reeks with decay.");
    set_exits(([
       "south" : "/d/deku/fortress/grave8",
       "enter" : "/d/deku/dark/narthex"
    ] ));
  set_pre_exit_functions(({"enter"}),({"go_enter"}));
    set_items(([
       "doors":"Entrance to the Mausolem, the doors are made out of Stone."
    ] ));
}

int go_enter() {
  write("The doors creep open as you enter the realm of death. A %^RED%^red");
  write("shimmering light creeps through the open doors.  You wonder");
  write("what you got yourself into this time.\n");
  return 1;
}
  
