#include "../../tecqumin.h"
inherit PLAT_BASE;

void create() {
  ::create();
  set_exits( ([ "east" : TREEHOUSE + "/rooms/"+ "platform05",
                       "northwest" : TREEHOUSE + "/rooms/"+ "platform07"]) );
}
