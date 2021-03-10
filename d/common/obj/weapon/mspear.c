inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "spear","medium spear" }));
   set_name("medium spear");
   set_short("A medium spear");
  set_long(
   "This is a short, one-handed stabbing spear."
   "  It's not so long as to be to hard to use while still retaining the use of a shield, or a leash for hunting dogs."
  );
   set_weight(4);
   set_size(2);
   set("value", 10);
   set_wc(1,8);
   set_large_wc(1,8);
   set_type("piercing");
   set_prof_type("spear");
   set_weapon_speed(6);
   set_weapon_prof("simple");
   set_property("repairtype",({"woodwork"}));
   set_critical_threat_range(1);
   set_critical_hit_multiplier(2);
   set_damage_type("piercing");
}
