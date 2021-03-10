inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "trident" }));
   set_name("trident");
   set_short("A trident");
   set_long(
  "  This three pronged spear looks very vicious.  The center tine is longer than the side two which are horribly barbed."
   );
   set_weight(6);
   set_size(2);
   set("value", 15);
  set_wc(1,8);
   set_large_wc(1,8);
   set_type("pierce");
set_prof_type("spear");
   set_weapon_speed(7);
   set_weapon_prof("martial");
   set_critical_threat_range(1);
   set_critical_hit_multiplier(3);
   set_damage_type("piercing");
   set_property("repairtype",({"weaponsmith"}));
}
