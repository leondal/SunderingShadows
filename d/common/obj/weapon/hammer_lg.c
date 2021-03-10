//new by Styx 5/19/01 for Newbietown to cover having a large hammer.

inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "warhammer","hammer","large hammer",
	"large war hammer", "war hammer" }));
   set_name("warhammer");
   set_short("A large war hammer");
   set_long(
  "  This is a large and very heavy iron war hammer.  It has a long, thick head on one side, counterbalanced on the other by a heavy spike.  It definitely has its uses if you want to try to crack someone out of their shell and will likely hurt all size targets pretty effectively."
   );
   set_weight(15);
   set_size(3);
   set("value", 10);
   set_wc(2,6);
   set_large_wc(2,6);
   set_type("bludgeoning");
   set_prof_type("hammer");
   set_weapon_speed(8);
   set_weapon_prof("martial");
   set_critical_threat_range(1);
   set_critical_hit_multiplier(3);
   set_damage_type("bludgeoning");
   set_property("repairtype",({"weaponsmith"}));
}
