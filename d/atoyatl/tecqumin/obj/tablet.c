#include <std.h>
#include "../tecqumin.h"
inherit CULT_ITEM;

create(){
  ::create();
  set_name("tablet");
  set_id(({"tablet","stone tablet","heavy stone tablet"}));
  set_short("tablet");
  set_text(query_name());
  set_long("A heavy stone tablet, carefully engraved with numerous"
          +" pictographs arranged in lines across the flat surface.\n" 
          + query_text());
  set_weight(8);
  set_value(200);
}