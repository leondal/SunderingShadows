#include <std.h>
inherit ARMOUR;
  void create(){
  ::create();
  set_name("dark plate");
  set_id(({"plate","breastplate","dark breastplate","dark plate"}));
  set_short("%^RESET%^%^BLUE%^Dark Plate%^RESET%^");
set_long(
           "This full plate armor is a dark color.  It is the armor chosen by several knights for its skillful craftsmanship."
          );
  set_weight(30);
  set_value(10000);
  set_type("armour");
  set_limbs(({"torso"}));
  set_wear((:TO,"extra_wear":));
  set_ac(7);
  set_property("enchantment",2);
}
int extra_wear(){
   write("You pull the dark armor on.");
  say(""+TPQCN+" pulls on the dark armor.");
  return 1;
}
