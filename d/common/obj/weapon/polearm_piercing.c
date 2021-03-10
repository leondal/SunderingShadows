inherit "/std/weapon";

create()
{
    ::create();
    set_id(({ "polearm" }));
    set_name("polearm");
    set_short("A piercing polearm");
    set_long("This is a piercing polearm.");
    set_weight(8);
    set_size(3);
    set("value", 5);
    set_wc(3, 4);
    set_large_wc(3, 4);
    set_type("pierce");
    set_prof_type("polearm");
    set_weapon_prof("martial");
    set_weapon_speed(10);
    set_critical_threat_range(1);
    set_critical_hit_multiplier(3);
    set_damage_type("piercing");
    set_property("repairtype", ({ "weaponsmith" }));
}
