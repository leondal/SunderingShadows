#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit TABAXROOM + "battlement.c";


void create() {
  ::create();
  set_short("On the battlement");
  set_long("You are on the battlement, above the west section of the stockade. You can see over to the"
          +" high field outside from here. If you wanted, you could target enemies in the field"
          +", with a missile weapon. There doesn't appear to be an easy way down from here, but you"
          +" can see ladders down into the stockade to the east and west of you.");
  set_exits( ([ "north" : TABAXROOM + "battlement1" ,
                "south": TABAXROOM + "battlement7"
             ]) );
  field_name = TABAXROOM + "high_field";
  set_field(find_object_or_load(field_name));
}

void clean_up(){
  string f;
  f = field_name;
  ::clean_up();
  field_name = f;
}

string query_granary_dir(){
  return "north";
}

void init(){
  ::init();
  if (!objectp(field)){
    set_field(find_object_or_load(field_name));
  }
}