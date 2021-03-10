#include <std.h>
#include "../cave.h"

inherit BTUNNEL;

void create() {
   ::create();
   set_exits( ([
      "southwest" : TUNNEL+"tunnel04",
      "north" : TUNNEL+"tunnel06"
   ]) );
}
