#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   "/d/dagger/Torm/obj/d_pearls"->create_pearls(TO);
}
