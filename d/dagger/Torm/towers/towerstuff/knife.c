inherit "/std/weapon";

create() {
    ::create();
  set_id(({"knife","butcher knife","dagger",
  }));
  set_name("butcher knife");
  set_short("butcher knife");
   set_long(
  "  This long single edge knife has an edge that looks like its been tended to carefully while the rest of it has been ignored."
  "  Its got a very sharp point, but rust spots the edge of the blade and the wooden handle is stained black with ancient blood."
   );
  set_weight(5);
   set_size(1);
   set("value", 2);
  set_wc(1,5);
  set_large_wc(2,3);
   set_type("piercing");
   set_weapon_speed(2);
  set_property("enchantment",1);
}
