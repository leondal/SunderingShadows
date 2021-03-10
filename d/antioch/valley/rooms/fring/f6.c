#include <std.h>
#include "../../valley.h"
inherit RING;

void create()
{
   ::create();
   set_exits( ([
   "northeast" : FRING+"f7",
   "southeast" : FRING+"f5",
   ]) );
}
