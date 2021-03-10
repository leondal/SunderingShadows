#include <std.h>
#include "../../valley.h"
inherit RING;

void create()
{
   ::create();
   set_exits( ([
   "southeast" : FRING+"f12",
   "southwest" : FRING+"f10",
   ]) );
}
