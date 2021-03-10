#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   "/d/shadow/room/meadows/obj/d_skirt"->create_skirt(TO);
   add_id("dagger_clothing");
}
