#include <std.h>
#include "../cave.h"

inherit BTUNNEL;

void create() {
   ::create();
   set_exits( ([
      "west" : TUNNEL+"tunnel02",
      "south" : TUNNEL+"tunnel04"
   ]) );
}
