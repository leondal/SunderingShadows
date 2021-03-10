//coded by Odin
inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "axe", "waraxe" }));
   set_name("dwarven waraxe");
   set_short("A dwarven waraxe");
   set_long("A dwarven waraxe has a large, ornate head mounted to a thick handle, making it too large to use in one hand without special training.");
   set_weight(8);
   set_size(2);
   set("value", 30);
   set_wc(1,10);
   set_large_wc(1,10);
   set_type("slashing");
   set_prof_type("axe");
   set_weapon_speed(6);
   set_weapon_prof("exotic");
   set_critical_threat_range(1);
   set_critical_hit_multiplier(3);
   set_damage_type("slashing");
   set_property("repairtype",({"weaponsmith"}));
}
