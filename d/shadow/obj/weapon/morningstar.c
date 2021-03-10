inherit "/std/weapon";

create() {
    ::create();
    set_id(({ "morningstar","morning star","star"}));
   set_name("morning star");
   set_short("A morning star");
   set_long(
   "The handle is a three foot wooden shaft that is topped with a chain and spiked ball."
   );
   set_weight(12);
   set_size(2);
   set("value", 10);
   set_wc(2,4);
   set_large_wc(1,6);
   set_type("bludgeoning");
   set_prof_type("mace");
   set_weapon_speed(7);
}
