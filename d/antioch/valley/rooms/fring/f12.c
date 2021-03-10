#include <std.h>
#include "../../valley.h"
inherit RING;

void create()
{
   ::create();
   set_exits( ([
   "southwest" : FRING+"f13",
   "northwest" : FRING+"f11",
   ]) );
}
