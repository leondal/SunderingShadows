#include <std.h>
#include "../cave.h"

inherit BTUNNEL;

void create() {
   ::create();
   set_exits( ([
      "northwest" : TUNNEL+"tunnel06",
      "southeast" : TUNNEL+"tunnel08"
   ]) );
}
