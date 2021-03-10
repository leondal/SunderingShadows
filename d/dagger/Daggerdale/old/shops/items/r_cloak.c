#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   "/d/shadow/room/meadows/obj/d_cloak"->create_cloak(TO);
   add_id("dagger_clothing");
}
