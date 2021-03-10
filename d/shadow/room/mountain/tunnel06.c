#include <std.h>
#include "../cave.h"

inherit BTUNNEL;

void create() {
   ::create();
   set_exits( ([
      "south" : TUNNEL+"tunnel05",
      "southeast" : TUNNEL+"tunnel07"
   ]) );
}
