//set weight to 5, bringing in line with other small weps. Nienne, 03/07.
inherit "/std/weapon";

void create()
{
    ::create();
    set_id(({ "iron claw", "claw" }));
    set_name("iron claw");
    set_short("An iron claw");
    set_long("Attached to a metal brace are three six" +
             " inch pointed claws.  Two straps attached" +
             " to the metal brace allow for the claw to be" +
             " fitted in place on the wearer's forearm.  " +
             "The iron claw is a favorite weapon for pugilists" +
             " as well as followers of Malar.");
    set_type("slashing");
    set_prof_type("knuckles");
    set_weapon_prof("simple");
    set_weight(2);
    set_size(1);
    set_wc(1, 6);
    set_weapon_speed(4);
    set_large_wc(1, 6);
    set_value(10);
    set_critical_threat_range(1);
    set_critical_hit_multiplier(2);
    set_damage_type("slashing");
    set_property("repairtype", ({ "weaponsmith" }));
}
