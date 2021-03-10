#include <std.h>
inherit ARMOUR;

void create()
{
   ::create();
   set_name("leather cloak");
   set_short("%^RESET%^%^ORANGE%^A leather cloak%^RESET%^");
   set_id(({"cloak","leather cloak"}));
   set_long(
   "%^ORANGE%^This is a nice looking leather cloak. It is dark brown in color and has been"+
   " treated to help keep the wearer safe from the elements. There is a hood that"+
   " one could pull over the head when it is raining, and it ties in the front around"+
   " the neck.%^RESET%^"
   );
   set_weight(3);
   set_type("clothing");
   set_size(random(3)+1);
   set_limbs(({"neck"}));
   set_value(30);
   set_cointype("silver");
   set_wear("You tie the cloak about your neck and feel more protected from the elements.");
}
