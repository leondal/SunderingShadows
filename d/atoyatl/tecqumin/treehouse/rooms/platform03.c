#include "../../tecqumin.h"
inherit PLAT_BASE;

void create() {
  ::create();
  set_exits( ([ "northwest" : TREEHOUSE + "/rooms/"+ "platform02",
                       "south" : TREEHOUSE + "/rooms/"+ "platform04"]) );
}
