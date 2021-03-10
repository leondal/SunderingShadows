#include <std.h>
inherit WEAPONLESS;

void create()
{
    object ob;
    ::create();
    set_name("peryton");
    set_short("Peryton");
    set_id(({ "monster", "peryton", "magical beast" }));
    set_long(
        "This twisted creature is surely the stuff of nightmares.  " +
        "Seemingly a giant, %^BOLD%^%^GREEN%^dark green %^RESET%^%^CYAN%^eagle with a " +
        "twenty foot wingspan, she has the head of a %^BLUE%^blue-black %^CYAN%^stag.  Her " +
        "unearthly eyes glow an empty %^BOLD%^%^RED%^red-orange%^RESET%^%^CYAN%^, while her " +
        "wickedly sharp horns glitter %^BOLD%^%^BLACK%^black %^RESET%^%^CYAN%^as the abyss.  " +
        "Contrasting sharply with the dark body, her chest is covered with %^ORANGE%^dull " +
        "brown feathers%^CYAN%^, and her sharp claws are %^BOLD%^%^WHITE%^bone " +
        "white%^RESET%^%^CYAN%^.  Strangely, the beast seems to cast a shadow of a " +
        "humanoid figure rather than her own shape."
        );
    set_gender("female");
    set_race("peryton");
    set_body_type("fowl");
    add_limb("mouth", "head", 0, 0, 0);
    add_limb("right horn", "head", 0, 0, 0);
    add_limb("left horn", "head", 0, 0, 0);
    remove_limb("beak");
    set_attack_limbs(({ "right claw", "left claw", "mouth", "right horn", "left horn" }));
    set_size(2);
    set_alignment(9);
    set_overall_ac(5);
    set_hd(8, 6);
    set_level(8);
    set_class("fighter");
    set_mlevel("fighter", 8);
    set_hp(random(20) + 60);
    set_max_hp(query_hp());
    set_damage(1, 6);
    set_attacks_num(2);
    set_base_damage_type("slashing");
    set_property("swarm", 1);
    set("aggressive", 18);
    set_stats("strength", 14);
    set_exp(2600);
    set_max_level(15); // added by *Styx* 9/24/06
    set_funcs(({ "rend" }));
    set_func_chance(20);
    set_achats(7, ({
        "%^BOLD%^%^RED%^The peryton circles low in the air before striking again!",
        "%^BOLD%^%^YELLOW%^The peryton screeches and roars in rage!",
    }));
    if (!random(10)) {
        ob = new("/d/common/obj/brewing/herb_special_inherit");
        ob->set_herb_name("peryton talon");
        ob->move(TO);
    }
}

int rend(object victim)
{
    if (!objectp(TO)) {
        return 1;
    }
    if (!objectp(ETO)) {
        return 1;
    }
    if (!objectp(victim)) {
        return 1;
    }
    if (!random(2)) {
        tell_object(victim, "%^BOLD%^%^GREEN%^The peryton's %^RED%^eyes %^GREEN%^flash as she " +
                    "tears into you with both claws!%^RESET%^");
        tell_room(ETO, "%^BOLD%^%^GREEN%^The peryton's %^RED%^eyes %^GREEN%^flash " +
                  "as she tears into " + victim->query_cap_name() + " with both claws!%^RESET%^", ({ victim }));
        victim->do_damage("torso", random(5) + 5);
        return 0;
    }else {
        return 0;
    }
}
