#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit ROOM;


void create() {
  ::create();
  set_short("Inside the stockade");
  set_long("You are in the northwest section of the %^ORANGE%^stockade%^RESET%^. There are many small"
           +" huts, presumably housing for the tabaxi peasants. A steep stairway leads up onto the"
           +" battlements");
  set_exits( ([ "up" : TABAXROOM + "battlement1", 
             "south" : TABAXROOM + "west_section",
              "east" : TABAXROOM + "north_section"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}

string query_granary_dir(){
  return "east";
}
