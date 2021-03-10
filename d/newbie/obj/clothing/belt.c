#include <std.h>
inherit ARMOUR;

void create()
{
   ::create();
   set_name("leather belt");
   set_short("%^RESET%^%^ORANGE%^A leather belt%^RESET%^");
   set_id(({"belt","leather belt"}));
   set_long("%^RESET%^%^ORANGE%^This is a nice looking brown leather belt with a %^YELLOW%^brass%^RESET%^%^ORANGE%^ buckle.%^RESET%^");
   set_weight(1);
   set_type("ring");
   set_limbs(({"waist"}));
   set_size(random(3)+1);
   set_value(5);
   set_cointype("silver");
   set_wear("You buckle the belt around your waist.");
}
