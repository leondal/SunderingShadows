#include "../../tecqumin.h"
inherit PLAT_BASE;

void create() {
  ::create();
  set_exits( ([ "northeast" : TREEHOUSE + "/rooms/"+ "platform04",
                       "west" : TREEHOUSE + "/rooms/"+ "platform06"]) );
}
