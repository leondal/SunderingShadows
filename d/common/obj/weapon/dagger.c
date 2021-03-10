inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "dagger" }));
   set_name("dagger");
   set_short("A dagger");
   set_long(
   "A gleam catches your eye from the blade of this finely made weapon."
   "  Its small size and good point make it a perfect weapon for people who don't want to have to worry about space for carrying a larger weapon."
   );
   set_weight(2);
   set_size(1);
   set("value", 2);
   set_wc(1,4);
   set_large_wc(1,4);
   set_type("piercing");
   set_weapon_prof("simple");
   set_weapon_speed(2);
   set_critical_threat_range(2);
   set_critical_hit_multiplier(2);
   set_damage_type("piercing");
   set_property("repairtype",({"weaponsmith"}));
}
