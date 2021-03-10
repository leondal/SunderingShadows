//water_elem.c - New monster for Koenig area; adapted from steam mephits in newbie keep.  Circe 11/22/03
#include <std.h>
inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("water elemental");
    set_short("A small water elemental");
    set_id(({ "elemental", "monster", "water elemental", "whirlpool" }));
    set_long(
        "This swirling water elemental is difficult to make out in the " +
        "surrounding river.  The only indication it's there is the occasional " +
        "movement against the current and a slight bubbling from time to time.  " +
        "You can barely see a vague outline of a whirlpool."
        );
    set_gender("neuter");
    set_race("elemental");
    set_body_type("humanoid");
    set_size(1);
    set_hd(8, 6);
    set_level(8);
    set_class("fighter");
    set_mlevel("fighter", 8);
    set_alignment(5);
    set_overall_ac(6);
    set_hp(random(30) + 55);
    set_damage(1, 8);
    set_attacks_num(2);
    set_base_damage_type("bludgeoning");
    add_limb("right wave", "right arm", 0, 0, 0);
    add_limb("left wave", "left arm", 0, 0, 0);
    set_attack_limbs(({ "left wave", "right wave" }));
    set_property("swarm", 1);
    set_hit_funcs((["right wave" : (: TO, "slam" :), "left wave" : (: TO, "slam" :)]));
    set("aggressive", 25);
//   set_exp(450);
//   set_exp(1000);
    set_new_exp(8, "high");
    set_funcs(({ "whirlpool" }));
    set_func_chance(15);
    set_max_level(7);
}

void init()
{
    ::init();
}

int slam(object targ)
{
    if (!random(4)) {
        tell_object(targ, "%^BOLD%^%^CYAN%^The elemental slams into you, making you lose your breath!");
        tell_room(ETO, "%^BOLD%^%^CYAN%^The elemental slams into " + targ->query_cap_name() + "!", targ);
        if (!random(2)) {
            targ->set_paralyzed(2, "You're catching your breath!");
        }
    }
    return 3;
}

void whirlpool(object targ)
{
    int i, j;
    object* inven;

    inven = all_living(ETO);
    j = sizeof(inven);

    tell_room(ETO, "%^BOLD%^%^CYAN%^The elemental dives down and creates a swirling whirlpool!");
    for (i = 0; i < j; i++) {
        if (!objectp(inven[i])) {
            continue;
        }
        if (inven[i] == TO) {
            continue;
        }
        if ((string)inven[i]->query_name() == "water elemental") {
            continue;
        }
        if ((int)inven[i]->query_true_invis()) {
            continue;
        }
        tell_object(inven[i], "%^CYAN%^The pool tries to drown you!");
        inven[i]->do_damage("torso", random(15) + 3);
        return;
    }
    return;
}

void die(mixed ob)
{
    switch (random(4)) {
    case 0..2:  tell_room(ETO, "%^CYAN%^The water elemental swirls wildly, then disappears beneath the river.");
        break;

    case 3:  tell_room(ETO, "%^BOLD%^%^CYAN%^A spout rises into the air as the elemental dies, " +
                       "sending something into the air!");
        new("/d/koenig/obj/water_earrings")->move(TO);
        break;
    }
    ::die(ob);
}
