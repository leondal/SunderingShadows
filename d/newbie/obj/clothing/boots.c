#include <std.h>
inherit ARMOUR;

void create()
{
   ::create();
   set_name("pair of boots");
   set_short("%^RESET%^%^ORANGE%^A pair of boots%^RESET%^");
   set_id(({"boots","pair of boots","leather boots"}));
   set_long("%^ORANGE%^This is a pair of fine leather boots. They are well oiled to help keep out water"+
   " and they lace up to about the mid-calf.%^RESET%^"
   );
   set_weight(2);
   set_size(random(3)+1);
   set_limbs(({"left foot","right foot"}));
   set_type("clothing");
   set_value(20);
   set_cointype("silver");
   set_wear("You lace the boots up tight.");
}
