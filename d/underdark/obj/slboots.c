//Changed to random magical since they were being abused per talk with T - Cythera 5/05\\
#include <std.h>

inherit ARMOUR;

void create() {
   ::create();
   set_name("boots");
   set_id(({"boots","soft leather boots"}));
   set_short("%^BOLD%^%^BLACK%^Soft leather boots%^RESET%^");
   set_long(
      "These boots are flexible and soft. The exterior of the boots is much like the interior, smooth and tanned. It is obvious these boots were made for efficiency rather than comfort. They are form fitting around the foot and tight at the calf. They would be ideal for moving with stealth."
   );

   set_weight(2);
   set_value(150);
   set_size(2);
   if(!random(6)) {
		set_property("enchantment",1);
	}
   set_type("clothing");
   set_limbs(({"left foot","right foot"}));
   set_wear((:TO,"wearit":));
}
int wearit() {
   tell_object(TP,"%^BOLD%^%^BLACK%^Your feet fill the boots like a glove%^RESET%^.");
   return 1;
}
