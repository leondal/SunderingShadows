#include <std.h>
#include "../../valley.h"
inherit RING;

void create()
{
   ::create();
   set_exits( ([
   "northeast" : FRING+"f11",
   "southeast" : FRING+"f9",
   ]) );
}
