//updated base damage - Circe 4/29/04
inherit "/std/weapon";

create()
{
    ::create();
    set_id(({ "sickle" }));
    set_name("sickle");
    set_short("A sickle");
    set_long("This short, heavy tool has a curved, almost " +
             "semicircular, blade with the inside of the curve " +
             "used most often to cut.  It doesn't look like a very " +
             "effective weapon compared to things like a two handed " +
             "sword, but surprise is often the key.");
    set_weight(3);
    set_size(1);
    set_value(6);
    set_cointype("silver");
    set_wc(1, 6);
    set_large_wc(1, 6);
    //set_wc(1,6);
    //set_large_wc(2,4);
    set_type("piercing");
    set_prof_type("small blades");
    set_weapon_speed(4);
    set_weapon_prof("simple");
    set_critical_threat_range(1);
    set_critical_hit_multiplier(2);
    set_damage_type("slashing");
    set_property("repairtype", ({ "weaponsmith" }));
}
