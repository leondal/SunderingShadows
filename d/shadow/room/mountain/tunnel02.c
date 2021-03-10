#include <std.h>
#include "../cave.h"

inherit BTUNNEL;

void create() {
   ::create();
   set_exits( ([
      "east" : TUNNEL+"tunnel03",
      "west" : TUNNEL+"tunnel01"
   ]) );
}
