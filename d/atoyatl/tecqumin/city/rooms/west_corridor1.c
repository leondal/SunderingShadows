#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit CORRIDORBASE;


void create() {
  ::create();

  set_exits(([
     "east" : CITY_ROOM + "throne_room",
     "south" : CITY_ROOM + "west_corridor2"
   ]));
  set_door("west door", CITY_ROOM + "throne_room", "east", 0);
  set_door_description("east door", "This grand door is made of"
    +" %^BOLD%^%^BLACK%^time-blackened h%^RESET%^%^ORANGE%^a%^BOLD%^"
    +"%^BLACK%^rdw%^RESET%^%^ORANGE%^oo%^BOLD%^%^BLACK%^d%^RESET%^,"
    +" and carved with symbols of the %^CYAN%^Tecqumin gods%^RESET%^."
    +" Despite its name, this door leads to the east from here.");

}


