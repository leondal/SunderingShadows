// Silver Ring of Protection (for Wizzes only)
// Thorn@ShadowGate
// 000925
// arop.c

#include <std.h>

inherit "/std/armour";

int uses, old;
object protect;

int resist_magic();



create() {
  ::create();
  set_property("ring of protection", 1);
  set_name("silver ring");
  set_id(({
    "band", "ring of protection",
    "metal band", "silver band",
    "silver ring", "ring"
  }));
  set("short","a silver ring");
  set_long(
@AZHA
  This is a silver ring of protection.  If you aren't an Avatar,
you may as well offer this now because you you do not have the 
power to wield such an artifact.
AZHA
);
  set_type("ring");
  set_weight(0);
  set("value", 0);
  set_limbs(({"right hand","left hand"}));
  set_property("enchantment",1);
  set_ac(20);
  set_wear((:TO,"do_wear":));
}

int do_wear() { 
  if(!avatarp(TP)) {
    write("This band sputters and disappears as you try to wear it.");
    TO->remove();
  }
  return 1;
}

