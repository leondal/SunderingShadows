#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit CANALBANK_BASE;


void create() {
  ::create();
  swing_dest = "canalbank02";
  blockdir = "east";
  set_exits( ([
	"southwest":JCITY+"rooms/city_jung02"
    ]) );
}


