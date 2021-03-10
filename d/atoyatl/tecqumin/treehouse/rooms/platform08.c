#include "../../tecqumin.h"
inherit PLAT_BASE;

void create() {
  ::create();
  set_exits( ([ "south" : TREEHOUSE + "/rooms/" + "platform07",
                       "northeast" : TREEHOUSE + "/rooms/" + "platform01"]) );
}
