inherit "/std/armour";
#include <std.h>

void create() {
    ::create();
  set_name("high collared cloak");
  set_id(({"cloak","high collared cloak"}));
  set_short("%^BLUE%^High collared cloak%^RESET%^");
    set("long", 
  "  This cloak is black as shadows at midnight and its high collar comes up past the wearers ears to protect them from the cold or perhaps hide their face from prying eyes.");
    set_weight(10);
set("value",1000);
    set_type("clothing");
    set_limbs( ({ "torso" }) );
  set_ac(0);
  set_property("enchantment",2);
}
