#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   "/d/shadow/room/meadows/obj/d_leggings"->create_leggings(TO);
   add_id("dagger_clothing");
}
