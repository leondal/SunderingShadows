#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   "/d/shadow/room/meadows/obj/d_shirt"->create_shirt(TO);
   set_size(random(3)+1);
}
