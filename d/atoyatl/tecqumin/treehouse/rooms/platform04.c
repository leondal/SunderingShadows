#include "../../tecqumin.h"
inherit PLAT_BASE;

void create() {
  ::create();
  set_exits( ([ "north" : TREEHOUSE + "/rooms/"+ "platform03",
                       "southwest" : TREEHOUSE + "/rooms/"+ "platform05"]) );
}
