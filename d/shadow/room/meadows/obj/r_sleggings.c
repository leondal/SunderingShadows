#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   "/d/shadow/room/meadows/obj/s_leggings"->create_leggings(TO);
   set_size(random(3)+1);
}
