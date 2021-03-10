#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
   ::create();
   set_name("grey cloak");
   set_short("A grey cloak");
   set_id(({"cloak","grey cloak"}));
   set_long(
   "This cloak is made of a wonderfully soft material that is a pleasure to simply"+
   " touch. The outside has been treated with something to help it stay partially"+
   " water resistant, and the inside is lined with a soft fur that helps to keep"+
   " you warm but not hot. A simple silver clasp latches in the front and there is"+
   " a hood in the back."
   );
   set_value(5);
   set_cointype("silver");
   set_type("clothing");
   set_limbs(({"neck"}));
   set_ac(0);
   set_weight(1);
}
