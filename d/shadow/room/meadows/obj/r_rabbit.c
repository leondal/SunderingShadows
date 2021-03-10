#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   "/d/shadow/room/meadows/obj/d_rabbit"->create_rabbit(TO);
   set_size(random(3)+1);
}
