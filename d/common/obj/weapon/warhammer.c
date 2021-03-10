inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "warhammer","hammer","war hammer" }));
   set_name("medium warhammer");
   set_short("A medium war hammer");
   set_long("  This is a heavy iron war hammer."
    "  It has a long, thick head on one side counterbalanced on the other by "
    "a heavy spike.  It definitely has its uses if you want to try to crack "
    "someone out of their shell." );
   set_weight(10);
   set_size(2);
   set("value", 2);
   set_wc(1,8);
   set_large_wc(1,8);
   set_type("bludgeoning");
   set_prof_type("hammer");
   set_weapon_speed(5);
   set_weapon_prof("martial");
   set_critical_threat_range(1);
   set_critical_hit_multiplier(3);
   set_damage_type("bludgeoning");
   set_property("repairtype",({"weaponsmith"}));
}
