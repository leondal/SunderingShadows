inherit "/std/weapon";

create() {
    ::create();
set_id(({ "knife","dagger"}));
   set_name("knife");
   set_short("A knife");
   set_long(
  "  This looks like a heavy kitchen knife."
   "  It's got a single curved edge and doesn't really look that sturdy compared to a regular dagger for combat."
   );
   set_weight(2);
   set_size(1);
   set("value", 5);
   set_cointype("silver");
   set_wc(1,4);
   set_large_wc(1,4);
   set_type("piercing");
   set_weapon_speed(2);
   set_weapon_prof("simple");
   set_critical_threat_range(2);
   set_critical_hit_multiplier(2);
   set_damage_type("piercing");
   set_property("repairtype",({"weaponsmith"}));
}
