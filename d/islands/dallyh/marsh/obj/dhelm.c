#include <std.h>
inherit "/std/armour";

void create() {
    ::create();
set_name("dark helmet");
set_id(({"dark helmet","helm","dark helm","helmet"}));
set_short("%^RESET%^%^BLUE%^Dark Helmet%^RESET%^");
set_long(
   "This is the helmet worn by the evil knights of the realm.  It covers most of the face leaving only the eyes and mouth exposed.  It looks as though it provides a lot of protection."
          );
set_weight(10);
set_value(100);
set_type("chain");
set_wear((:TO,"extra_wear":));
set_limbs(({"head"}));
set_ac(1);
set_property("enchantment",2);
}
int extra_wear(){
  write("%^RESET%^%^BLUE%^You feel the evil seep into you as you slide on the dark helmet.%^RESET%^");
  say("%^RESET%^%^BLUE%^"+TPQCN+" slides on the dark helmet.%^RESET%^");
return 1;
}
