#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit ROOM;


void create() {
  ::create();
  set_short("Inside the stockade");
  set_long("You are in the eastern section of the %^ORANGE%^stockade%^RESET%^, by the fence. The main"
          +" centre of the community is to the west. You can see stairways leading up to the"
          +" battlements to the north and south. There is the entrance to a large communal food hall"
          +" here.");
  set_exits( ([ "north" : TABAXROOM + "northeast_corner" ,
               "south": TABAXROOM + "southeast_corner",
               "west" : TABAXROOM + "centre",
           "foodhall" : TABAXROOM + "foodhall"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}

string query_granary_dir(){
  return "north";
}