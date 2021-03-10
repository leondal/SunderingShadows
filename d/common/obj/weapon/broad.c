inherit "/std/weapon";

create()
{
    ::create();
    set_id(({ "sword", "broad sword", "broad" }));
    set_name("broad sword");
    set_short("A broad sword");
    set_long(
        "This sword has a thick, heavy blade and looks like it would stand up to combat for a long time."
        );
    set_weight(4);
    set_size(2);
    set("value", 10);
    set_wc(2, 4);
    set_large_wc(2, 4);
    set_prof_type("medium blades");
    set_weapon_prof("martial");
    set_type("slashing");
    set_weapon_speed(5);

    set_critical_threat_range(2);
    set_critical_hit_multiplier(2);
    set_damage_type("slashing");
    set_property("repairtype", ({ "weaponsmith" }));
}
