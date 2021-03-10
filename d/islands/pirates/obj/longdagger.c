#include <std.h>
inherit "/d/common/obj/weapon/dagger";

void create() {
   ::create();
   set_name("long dagger");
   set_id(({"dagger","long dagger"}));
   set_short("A long dagger");
   set_long("This is a longer style of a standard dagger.  It is a very light weapon, small and "
"maneuverable, but with the advantage of having a slightly greater range than a normal dagger.");
   set_weight(3);
   set_value(10);
   set_wc(1,5);
   set_large_wc(1,4);
   if(!random(2)) set_property("enchantment",1);
}
