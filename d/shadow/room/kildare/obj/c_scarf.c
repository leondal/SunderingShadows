#include <std.h>
#include "../kildare.h"
inherit ARMOUR;

void create()
{
   ::create();
   "/d/shadow/room/kildare/obj/b_scarf"->create_scarf(TO);
}
