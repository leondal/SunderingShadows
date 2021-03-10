#include "../../tecqumin.h"
inherit PLAT_BASE;

void create() {
  ::create();
  set_exits( ([ "west" : TREEHOUSE + "/rooms/"+ "platform01",
                       "southeast" : TREEHOUSE + "/rooms/"+ "platform03"]) );
}

