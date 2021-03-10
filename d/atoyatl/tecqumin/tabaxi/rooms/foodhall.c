#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit ROOM;


void create() {
  ::create();
  set_short("In the food hall");
  set_long("You are in a large, communal food hall. There's a circular table in the middle of the"
          +" room, at about knee height, with reed mats set out around it for sitting on. The room is"
          +" fairly sparse, but adequate for the needs of a small community. There is a kitchen area"
          +" to the south.");
  set_exits( ([ "south" : TABAXROOM + "kitchen" ,
               "out": TABAXROOM + "east_section"
             ]) );
}

void init(){
  ::init();
  set_had_players(3);
}

string query_granary_dir(){
  return "out";
}