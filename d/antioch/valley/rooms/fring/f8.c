#include <std.h>
#include "../../valley.h"
inherit RING;

void create()
{
   ::create();
   set_exits( ([
   "southwest" : FRING+"f9",
   "northwest" : FRING+"f7",
   ]) );
}
