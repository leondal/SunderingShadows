#include <std.h>
#include "../../valley.h"
inherit RING;

void create()
{
   ::create();
   set_exits( ([
   "southwest" : FRING+"f5",
   "northwest" : FRING+"f3",
   ]) );
}
