#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   "/d/shadow/room/meadows/obj/d_cloak"->create_cloak(TO);
   set_size(random(3)+1);
}
