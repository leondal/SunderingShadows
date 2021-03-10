inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "pick"}));
   set_name("pick");
   set_short("A pick");
   set_long(
   "This pick looks like a strengthened and shortened version of the mining tool."
   "  The punctures this thing could inflict would be gruesome indeed and you doubt even the heaviest armor would be able to deflect its blows."
   );
   set_weight(6);
   set_size(2);
   set("value", 8);
   set_wc(1,6);
   set_large_wc(1,6);
     set_type("piercing");
set_prof_type("short blades");
   set_weapon_speed(5);
   set_weapon_prof("martial");
   set_critical_threat_range(1);
   set_critical_hit_multiplier(4);
   set_damage_type("piercing");
   set_property("repairtype",({"weaponsmith"}));
}
