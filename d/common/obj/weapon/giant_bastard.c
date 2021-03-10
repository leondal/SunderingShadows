//giant weapon by Circe 12/3/04
inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "sword", "bastard sword", "2-handed bastard sword", "bastard", "bastard_two", "2-handed sword","giant sword","giant bastard sword" }));
   set_name("giant bastard sword");
   set_short("giant bastard sword");
   set_long(
      "This enormous sword is large enough for a giant to wield in "+
      "two hands.  The double-edge blade features a long, shallow "+
      "blood groove leading to the leather-wrapped hilt.  A functional "+
      "crossguard protects the hands.  The sword is hardly decorative, "+
      "but seems sturdy and functional."
   );
   set_weight(15);
   set_size(4);
   set_value(80);
   set_wc(3,6);
   set_large_wc(3,6);
   set_type("slash");
   set_weapon_speed(8);
   set_weapon_prof("martial");
   set_critical_threat_range(2);
   set_critical_hit_multiplier(2);
   set_damage_type("slashing");
   set_property("repairtype",({"weaponsmith"}));
}
