#include <std.h>
inherit ARMOUR;

void create()
{
   ::create();
   "/d/shadow/room/kildare/obj/b_sweater"->create_sweater(TO);
   set_size(random(3)+1);
}
