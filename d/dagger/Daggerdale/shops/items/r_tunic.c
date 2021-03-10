#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   "/d/shadow/room/meadows/obj/d_tunic"->create_tunic(TO);
   add_id("dagger_clothing");
}
