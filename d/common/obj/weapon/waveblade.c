inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "waveblade" }));
   set_name("waveblade");
   set_short("A waveblade");
   set_long("Also known as a scorpion's tail due to its unique, stinger-like shape, this short, double-curved blade has no hilt but features a knuckle guard.");
   set_weight(2);
   set_size(1);
   set("value", 2);
   set_wc(1,6);
   set_large_wc(1,6);
   set_type("slashing");
   set_weapon_prof("exotic");
   set_weapon_speed(2);
   set_critical_threat_range(3);
   set_critical_hit_multiplier(2);
   set_damage_type("slashing");
   set_property("repairtype",({"weaponsmith"}));
}
