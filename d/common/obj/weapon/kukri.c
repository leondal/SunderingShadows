inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "kukri" }));
   set_name("kukri");
   set_short("A kukri");
   set_long(
   "The kukri is a knife with a distinct recurve in the blade. Used as both a tool and as a weapon in the Dallyh area, it is primarily designed for chopping.");
   set_weight(2);
   set_size(1);
   set("value", 2);
   set_wc(1,4);
   set_large_wc(1,4);
   set_type("slashing");
   set_weapon_prof("martial");
   set_weapon_speed(2);
   set_critical_threat_range(3);
   set_critical_hit_multiplier(2);
   set_damage_type("slashing");
   set_property("repairtype",({"weaponsmith"}));
}
