#include <std.h>
#include "../../elfisland1.h"

inherit BCPATH;

void create() {
   ::create();
   set_exits( ([
      "south" : CPATH+"cpath07",
      "west" : CPATH+"cpath05",
   ]) );
}
