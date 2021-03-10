#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit CORRIDORBASE;


void create() {
  ::create();

  set_exits(([
    "north" : CITY_ROOM + "taluc_room",
     "east" : CITY_ROOM + "throne_room",
     "west" : CITY_ROOM + "west_corridor2"
   ]));
  set_exits(([  "north" : CITY_ROOM + "taluc_room",
                "south" : CITY_ROOM + "east_corridor2",
                 "west" : CITY_ROOM + "throne_room"    ]));
  set_door("east door", CITY_ROOM + "throne_room", "west", 0);
  set_door_description("east door", "This grand door is made of"
    +" %^BOLD%^%^BLACK%^time-blackened h%^RESET%^%^ORANGE%^a%^BOLD%^"
    +"%^BLACK%^rdw%^RESET%^%^ORANGE%^oo%^BOLD%^%^BLACK%^d%^RESET%^,"
    +" and carved with symbols of the %^CYAN%^Tecqumin gods%^RESET%^."
    +" Despite its name, this door leads to the west from here.");
  set_door("office door", CITY_ROOM + "taluc_room", "north", 0);
  set_door_description("office door", "A simple wooden door");

}


