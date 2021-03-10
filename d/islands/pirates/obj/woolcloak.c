#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("woolen cloak");
   set_id(({"cloak","woolen cloak","wool cloak"}));
    switch(random(9)){
      case 0..2:
      set_short("%^RESET%^%^ORANGE%^woolen cloak%^RESET%^");
      set_long("%^ORANGE%^This cloak is very tightly woven of delicate woolen fibers and dyed a soft brown "
"shade.  It is warm in winter because the wool doesn't feel cold to the touch, and yet is thin enough to "
"breathe and be comfortable in summer also.  The tailoring is outstanding and it appears to be treated to "
"resist water and other elements.\n%^RESET%^");
      break;

      case 3..5:
      set_short("%^WHITE%^%^BOLD%^woolen cloak%^RESET%^");
      set_long("%^WHITE%^%^BOLD%^This cloak is very tightly woven of delicate woolen fibers and dyed a faded "
"white shade.  It is warm in winter because the wool doesn't feel cold to the touch, and yet is thin enough "
"to breathe and be comfortable in summer also.  The tailoring is outstanding and it appears to be treated to "
"resist water and other elements.\n%^RESET%^");
      break;

      case 6..8:
      set_short("%^BLACK%^%^BOLD%^woolen cloak%^RESET%^");
      set_long("%^BLACK%^%^BOLD%^This cloak is very tightly woven of delicate woolen fibers and dyed a dull "
"black shade.  It is warm in winter because the wool doesn't feel cold to the touch, and yet is thin enough "
"to breathe and be comfortable in summer also.  The tailoring is outstanding and it appears to be treated to "
"resist water and other elements.\n%^RESET%^");
      break;
   }
   set_weight(3);
   set_type("clothing");
   set_limbs(({"neck"}));
   set_ac(0);
   set_property("enchantment",2);
   set_item_bonus("magic resistance",1);
   set_value(500+random(2)*750);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_lore("%^WHITE%^%^BOLD%^Cloaks such as these are commonly favoured by seagoing pirates.  Because of "
"the extensive travels they sometimes undertake, they prefer the cloaks' convenience in all types of weather "
"and season, and their durability over standard garments.%^RESET%^\n");
   set_property("lore difficulty",12);
}

int wear_fun() {
  tell_object(ETO,"The cloak fits itself to your shoulders and feels wonderful.");
  return 1;
}

int remove_fun() {
  tell_object(ETO,"You miss the feel of the soft wool around your shoulders.");
  return 1;
}
