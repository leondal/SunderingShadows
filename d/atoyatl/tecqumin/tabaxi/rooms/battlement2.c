#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit TABAXROOM + "battlement.c";


void create() {
  ::create();
  set_short("On the battlement");
  set_long("You are on the battlement, above the north section of the stockade. You can see over to"
          +" the jungle, a short distance away to the north. There doesn't appear to be an easy way"
          +" down from here, but you"
          +" can see ladders down into the stockade to the east and west of you.");
  set_exits( ([ "east" : TABAXROOM + "battlement3" ,
                "west": TABAXROOM + "battlement1"
             ]) );
  field_name = TABAXROOM + "main_field";
  set_field(find_object_or_load(field_name));
}

void clean_up(){
  string f;
  f = field_name;
  ::clean_up();
  field_name = f;
}

void init(){
  ::init();
  if (!objectp(field)){
    set_field(find_object_or_load(field_name));
  }
}
string query_granary_dir(){
  return "east";
}
