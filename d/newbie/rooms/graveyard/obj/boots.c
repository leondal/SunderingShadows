#include <std.h>
inherit ARMOUR;
void create() {
   ::create();
   set_name("boots");
   set_short("%^BOLD%^%^BLACK%^A pair of ragged boots%^RESET%^");
   set_id(({"boots","ragged boots","pair of boots","pair of ragged boots"}));
   set_long("%^ORANGE%^Ragged %^RESET%^though they are, these boots appear to be at least somewhat sturdy.  "
"Some sort of %^BOLD%^%^BLACK%^thick black hide %^RESET%^has been used to craft them, with laces up the front "
"of each.  The soles are rather worn, but still %^BLUE%^solid %^RESET%^enough to protect the feet, and the "
"leather is aged and rough around the toes.  The boots smell rather %^GREEN%^awful%^RESET%^.\n");
   set_weight(2);
   set_value(3);
   set_limbs(({"left foot","right foot"}));
   set_type("clothing");
   set_size(2);
   set_wear("You can't help but wrinkle your nose at the smell of the boots, as you slip them on.");
   set_remove("You slide off the boots, and your feet feel better already.");
}
