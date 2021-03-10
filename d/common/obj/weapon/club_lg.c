inherit "/std/weapon";

create()
{
    ::create();

    set_id(({ "club", "mclub", "large club" }));
    set_name("large club");
    set_short("A large club");
    set_long(
        "This is a large wooden club, so large it takes two hands for any normal size humanoid to wield and swing it.  It is rather plain and ordinary, roughly carved from a large tree limb.  It is thicker at the ends and narrows down to a slender handle that you can grip it with.  It is generally used to hit someone with, and is a rather crude weapon."
        );
    set_weight(10);
    set_size(3);
    set("value", 1);
    set_wc(1, 12);
    set_large_wc(1, 12);
    set_type("bludgeoning");
    set_prof_type("club");
    set_weapon_prof("simple");
    set_weapon_speed(6);
    set_property("repairtype", ({ "woodwork" }));
    set_critical_threat_range(1);
    set_critical_hit_multiplier(2);
    set_damage_type("bludgeoning");
}
