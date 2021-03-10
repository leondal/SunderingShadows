#include <std.h>
#include "../../valley.h"
inherit RING;

void create()
{
   ::create();
   set_exits( ([
   "northeast" : FRING+"f3",
   "southeast" : FRING+"f1",
   ]) );
}
