inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "axe", "battle","battle axe", "large axe" }));
   set_name("large battle axe");
   set_short("A large battle axe");
   set_long(
      "This impressive axe is two-headed, with the double blades "+
      "opposing each other.  The handle is quite long and made of "+
      "sturdy wood to provide a strong grip for an axe of this size.  "+
      "It is much larger than most axes, and could probably be wielded "+
      "by most people in both hands."
   );
   set_weight(10);
   set_size(3);
   set_value(15);
   set_wc(3,4);
   set_large_wc(3,4);
   set_type("slashing");
   set_prof_type("axe");
   set_weapon_speed(8);
   set_weapon_prof("martial");
   set_critical_threat_range(1);
   set_critical_hit_multiplier(3);
   set_damage_type("slashing");
   set_property("repairtype",({"weaponsmith"}));
}
