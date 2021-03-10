#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   "/d/shadow/room/meadows/obj/d_jacket"->create_jacket(TO);
   add_id("dagger_clothing");
}
