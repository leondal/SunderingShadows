#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit ROOM;


void create() {
  ::create();
  set_short("Inside the stockade");
  set_long("You are in the northeast section of the %^ORANGE%^stockade%^RESET%^. There are many small"
           +" huts, presumably housing for the tabaxi peasants. A steep stairway leads up onto the"
           +" battlements. A stone entrance leads to a set of steps descending below the ground.");
  set_items( ([ ({"entrance", "stone entrance", "steps"}) : "An entrance cut into the side of a large"
           +"rock in the ground leads to a stairway desending into the earth", 
              ({"hut", "huts"}): "The tabaxi have occupied small, flat roofed, square wooden buildings"
                 ]));
  set_exits( ([ "up" : TABAXROOM + "battlement3", 
             "south" : TABAXROOM + "east_section",
              "west" : TABAXROOM + "north_section",
              "down" : TABAXROOM + "granary"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}

string query_granary_dir(){
  return "down";
}