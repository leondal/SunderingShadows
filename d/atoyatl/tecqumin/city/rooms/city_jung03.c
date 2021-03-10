#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit TECBASE + "jung_base.c";


void create() {
  ::create();

  set_exits(([ 
      "southwest" : CITY_ROOM + "canalbank02"
   ]));
}



string long_desc(){

return base_desc();

}
