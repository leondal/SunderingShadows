// updated dex bonus from the new system. Nienne, 09/07.
#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("buckled boots");
   set_id(({"boots","buckled boots","tall boots","leather boots","black boots"}));
   set_short("%^BLACK%^%^BOLD%^Swashbuckler's Boots%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^tall buckled boots%^RESET%^");
   set_long("%^WHITE%^%^BOLD%^These boots are tall enough to reach partway up the shins, and are formed of a "
"%^BLACK%^shiny black leather%^WHITE%^ upon the upper surface.  The soles are reinforced with several layers "
"of similar leather, protecting the feet from harm.  Up the outer side of each, a row of flamboyant%^YELLOW%^"
" golden buckles%^WHITE%^ firmly secure the boot.\n%^RESET%^");
   set_weight(3);
   set_type("clothing");
   set_limbs(({"right foot","left foot"}));
   set_ac(0);
   set_property("enchantment",2);
   set_value(280);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_lore("%^WHITE%^%^BOLD%^These boots are a common possession of pirates and swashbucklers, for their "
"sturdy make and the secure buckles.  Not to mention their stylish appearance.%^RESET%^\n");
   set_property("lore difficulty",8);
   set_item_bonus("dexterity",1);
   set_property("repairtype",({"tailor", "leatherwork"}));
}

int wear_fun() {
   if(ETO->query_highest_level() < 14) {
     tell_object(ETO,"%^WHITE%^%^BOLD%^You can't seem to be able to force your feet into the boots.%^RESET%^");
     return 0;
   }
   tell_object(ETO,"%^BLACK%^%^BOLD%^The boots fit perfectly to your feet, making your movements easy and "
"graceful.%^RESET%^");
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^BLACK%^%^BOLD%^You feel less confident in your stride as you remove the boots."
"%^RESET%^");
   return 1;
}
