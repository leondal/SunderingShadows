//Coded by odin
inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "sword", "estoc" }));
     set_name("falcata");
   set_short("An estoc");
   set_long(
   "An estoc is a sword about as long as a bastard sword, but designed exclusively for thrusting attacks. Its blade is a steel spike with a triangular, square, or hexagonal cross-section."
   );
   set_weight(4);
   set_size(2);
   set("value", 35);
   set_wc(2,4);
   set_large_wc(2,4);
   set_type("piercing");
   set_weapon_speed(6);
   set_weapon_prof("exotic");
   set_critical_threat_range(3);
   set_critical_hit_multiplier(2);
   set_damage_type("piercing");
   set_property("repairtype",({"weaponsmith"}));
}
