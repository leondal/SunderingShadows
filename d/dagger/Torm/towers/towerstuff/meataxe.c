inherit "/std/weapon";

create() {
    ::create();
  set_id(({"axe","meat axe",
  }));
  set_name("meat axe");
  set_short("meat axe");
   set_long(
  "  This heavy one handed weapon is stained black and its edge is rusted with old blood."
  "  Its hard to know exactly what to call it, its large heavy square blade reminds you of a cleaver, but its extended handle gives it more leverage like an axes."
   );
  set_weight(10);
  set_size(2);
   set("value", 2);
  set_wc(1,8);
  set_large_wc(2,5);
  set_type("slashing");
  set_weapon_speed(5);
  set_property("enchantment",1);
  set_prof_type("medium axe");
}
