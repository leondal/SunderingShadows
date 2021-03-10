#include "../../tecqumin.h"
inherit PLAT_BASE;

void create() {
  ::create();
  set_exits( ([ "southeast" : TREEHOUSE + "/rooms/"+ "platform06",
                       "north" : TREEHOUSE + "/rooms/"+ "platform08"]) );
}
