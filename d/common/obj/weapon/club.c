//changed base damage - Circe 4/29/04
inherit "/std/weapon";

create()
{
    ::create();

    set_id(({ "club", "small club" }));
    set_name("small club");
    set_short("A small club");
    set_long("This small club has been roughly carved from a piece " +
             "of oak.  It has a slender handle and gradually thickens along " +
             "its length, eventually reaching its thickest cross section at " +
             "the opposite end.  They are common, although generally rather " +
             "crude weapons."
             );
    set_weight(3);
    set_size(1);
    set_prof_type("club");
    set_weapon_prof("simple");
    set_value(5);
    set_cointype("silver");
    set_wc(1, 6);
    set_large_wc(1, 6);
    set_type("bludgeoning");
    set_weapon_speed(4);
    set_property("repairtype", ({ "woodwork" }));
    set_critical_threat_range(1);
    set_critical_hit_multiplier(2);
    set_damage_type("bludgeoning");
}
