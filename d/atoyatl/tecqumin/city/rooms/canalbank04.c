#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit CANALBANK_BASE;


void create() {
  ::create();
  swing_dest = "canalbank03";
  blockdir = "west";
  set_exits( ([
	"north":CITY_ROOM + "hut01",
      "south":CITY_ROOM + "ruin02",
      "northeast":CITY_ROOM + "city_jung07"
    ]) );
}


