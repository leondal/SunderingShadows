#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   "/d/dagger/Daggerdale/shops/items/d_boots"->create_boots(TO);
}
