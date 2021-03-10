#include <std.h>
#include "../cave.h"

inherit BTUNNEL;

void create() {
   ::create();
   set_exits( ([
      "north" : TUNNEL+"tunnel03",
      "northeast" : TUNNEL+"tunnel05"

   ]) );
}
