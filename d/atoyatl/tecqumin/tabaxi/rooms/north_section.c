#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit ROOM;


void create() {
  ::create();
  set_short("Inside the stockade");
  set_long("You are in the northern part of the %^ORANGE%^stockade%^RESET%^, near the fence. There"
          +" are many small huts, presumably housing for the tabaxi peasants. To the east and west,"
          +" you can see stairways leading up to the battlements. The main centre of the community is"
          +" to the south");
  set_exits( ([ "east" : TABAXROOM + "northeast_corner" ,
                "west" : TABAXROOM + "northwest_corner", 
               "south" : TABAXROOM + "centre"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}

string query_granary_dir(){
  return "east";
}