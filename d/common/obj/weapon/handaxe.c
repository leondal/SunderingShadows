inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "handaxe", "hand axe", "axe" }));
   set_name("handaxe");
   set_short("A hand axe");
   set_long(
   "This single bladed axe has about a two foot handle suitable for wielding in one hand.  It looks like it could chop wood or enemies equally well."
   );
   set_weight(5);
   set_size(1);
   set("value", 1);
   set_wc(1,6);
   set_large_wc(1,4);
   set_type("slashing");
   set_prof_type("axe");
   set_weapon_speed(4);
   set_weapon_prof("martial");
   set_critical_threat_range(2);
   set_critical_hit_multiplier(3);
   set_damage_type("slashing");
   set_property("repairtype",({"weaponsmith"}));
}
