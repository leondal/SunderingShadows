#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit GARDENBASE;

void create() {
  ::create();
  set_exits( (["indoors" : CITY_ROOM + "throne_room",
                  "west" : CITY_ROOM + "garden_west"]) );
  set_door("double door", CITY_ROOM + "throne_room", "indoors", 0);
  set_door_description("double door", "These double doors lead in"
    +" to the palace throne room. Latticed openings in the wooden doors"
    +" allow you to peer in, even when they are closed.");
}

void init(){
  ::init();
}

