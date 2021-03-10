#include <std.h>
#include "../../valley.h"
inherit RING;

void create()
{
   ::create();
   set_exits( ([
   "southeast" : FRING+"f24",
   "southwest" : FRING+"f26",
   ]) );
}
