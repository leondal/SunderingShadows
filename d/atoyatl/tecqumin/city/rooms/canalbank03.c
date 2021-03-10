#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit CANALBANK_BASE;


void create() {
  ::create();
  swing_dest = "canalbank04";
  blockdir = "east";
  set_exits( ([
	"northwest":JCITY+"rooms/city_jung01"
    ]) );
}


