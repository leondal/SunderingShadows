//Added set_max_level to retard cycling - Octothorpe 6/4/09
//monk.c

#include <std.h>

inherit MONSTER;

void create()
{
    ::create();

    set_name("old monk");
    set_id(({ "monk", "old monk", "Monk" }));
    set_short("An old monk");
    set_long("This old man spends his life sitting quitely in meditation or walking quietly communing with the nature that surrounds him here. His bald head is shadowed with a slight stubble. His calm eyes look over you with a a loving embrace.");
    set_race("human");
    set_body_type("human");
    set_property("no random money", 1);
    set_speed(30);
    set_base_damage_type("bludgeoning");
    set_hd(17 + random(20), 8);
    set_hp(query_hd() * 20);
    if (!random(3)) {
        set_property("garlic_scent", 1);
    }
    set_exp(700 * query_hd());
    set_new_exp(25, "normal");
    set_max_level(31);
    set_damage(1, 4);
    if (random(2)) {
        set_property("no stab", 1);
    }
    if (random(2)) {
        set_property("no rush", 1);
    }
    set_property("no death", 1);
    set_scrambling(1);
    set_attack_limbs(({ "right hand", "left hand", "left foot", "right foot" }));
    set_attacks_num(query_hd() / 10 + 2);
    set_hit_funcs((["right hand" : (: TO, "martial" :), "left hand" : (: TO, "martial" :), "right foot" : (: TO, "martial" :), "left foot" : (: TO, "martial" :)]));
    set_gender("male");
    set_class("fighter");
    set_property("swarm", 1);
    set_funcs(({ "groove" }));
    set_func_chance(30);
    set_stats("strength", 19);
    set_overall_ac(-10);
    set_alignment(5);
    set_class("thief");
    set_thief_skill("move silently", 95);
    set_thief_skill("hide in shadows", 95);
    set_mlevel("thief", 26);
    set_mlevel("fighter", query_hd());
    add_search_path("/cmds/thief");
}

int query_watched()
{
    return 65 + query_hd();
}

int martial(object targ)
{
    string limb, * limbs;

    limbs = (string*)TO->query_attack_limbs();

    limb = limbs[random(sizeof(limbs))];

    if (!objectp(targ)) {
        return 13;
    }
    switch (limb) {
    case "right hand":
        switch (random(12)) {
        case 0..5:
            tell_object(targ, "%^BOLD%^%^BLUE%^The monk hits you with tremendous force with an elbow smash.");
            tell_room(ETO, "%^BOLD%^%^BLUE%^The monk hits " + targ->query_cap_name() + " with a tremendous elbow smash.", targ);
            return random(6);

        case 6..8:
            tell_object(targ, "%^BOLD%^%^RED%^The monk crouches down for a second then leaps up with an uppercut hitting you in the stomach.");
            tell_room(ETO, "%^BOLD%^%^RED%^The monk crouches down for a second then leaps up hitting " + targ->query_cap_name() + " in the stomach with an uppercut.", targ);
            return random(8);

        case 9:
            tell_object(targ, "%^BOLD%^%^YELLOW%^The monk spins around and you are hit in the jaw with his fist as the monk completes his spinning back fist.");
            tell_room(ETO, "%^BOLD%^%^YELLOW%^The monk spins around and hits " + targ->query_cap_name() + " in the jaw with his fist as he completes his spinning back fist.", targ);
            return random(10);

        case 11..12:
            tell_object(targ, "%^BOLD%^%^GREEN%^The monk successfully gets you with a pressure point blow that stuns you slightly,");
            tell_room(ETO, "%^BOLD%^%^GREEN%^The monk successfully lands a pressure point blow stunning " + targ->query_cap_name() + "!", targ);
            targ->set_paralyzed(6 + random(24), "%^GREEN%^You are stunned.");
            return random(5);
        }

    case "left hand":
        switch (random(12)) {
        case 0..5:
            tell_object(targ, "%^BLUE%^The monk lunges foward, grabs your blocking arm, pulls it out of the way and delivers a powerful punch with his free hand.");
            tell_room(ETO, "%^BLUE%^The monk lunges toward " + targ->query_cap_name() + " and grabs his blocking arm, pulls it out of the way and delivers a powerful punch with his free hand.", targ);
            return random(6);

        case 6..8:
            tell_object(targ, "%^RED%^The monk flattens his hand and strikes you with the fingertips, driving his hand into your body.");
            tell_room(ETO, "%^RED%^The monk flattens his hand and strikes " + targ->query_cap_name() + " with the fingertips, driving his hand into the body.", targ);
            return random(8);

        case 9:
            tell_object(targ, "%^YELLOW%^The monk leans sideways and thrusts both fists into your chest and knocks all the air out of you.");
            tell_room(ETO, "%^YELLOW%^The monk leans sideways and thrusts both fist forcefully into " + targ->query_cap_name() + ".", targ);
            return random(10);

        case 10..12:
            tell_object(targ, "%^BOLD%^%^GREEN%^The monk successfully gets you with a pressure point blow that stuns you slightly,");
            tell_room(ETO, "%^BOLD%^%^GREEN%^The monk successfully lands a pressure point blow stunning " + targ->query_cap_name() + "!", targ);
            targ->set_paralyzed(6 + random(24), "%^GREEN%^You are stunned.");
            return random(5);
        }

    case "left foot":
        switch (random(10)) {
        case 0..5:
            tell_object(targ, "%^BOLD%^%^GREEN%^The monk leaps into the air and stretches his leg high above his head. As he comes down, he slams his leg into you with his axe kick.");
            tell_room(ETO, "%^BOLD%^%^GREEN%^The monk leaps into the air and stretches his leg high above his head. As he comes down, he slams his leg into " + targ->query_cap_name() + " with his axe kick.", targ);
            return random(8);

        case 6..8:
            tell_object(targ, "%^BOLD%^%^MAGENTA%^The monk launches himself feet-first in the air toward you. He lands a powerful flying kick into you.");
            tell_room(ETO, "%^BOLD%^%^MAGENTA%^The monk launches himself feet-first in the air toward " + targ->query_cap_name() + " and lands a powerful flying kick.", targ);
            return random(10);

        case 9:
            tell_object(targ, "%^BOLD%^%^CYAN%^The monk launches a feint kick past your head, and then quickly reverse it with a sharp snapping motion, driving his heel into the back of your head with his reverse front kick.");
            tell_room(ETO, "%^BOLD%^%^CYAN%^The monk launches a fient kick past " + targ->query_cap_name() + "'s head, then quickly reverses it with a sharp snapping motion, driving his heel into the back of the head with his reverse front kick.", targ);
            return random(12);
        }

    case "right foot":
        switch (random(10)) {
        case 0..5:
            tell_object(targ, "%^GREEN%^The monk faces you squarely, then pivots and kicks you perfectly with this roundhouse kick.");
            tell_room(ETO, "%^GREEN%^The monk faces " + targ->query_cap_name() + " squarely, then pivots and kicks, landing the roundhouse kick perfectly.", targ);
            return random(8);

        case 6..8:
            tell_object(targ, "%^MAGENTA%^The monk leaps up and knees you in the chest with this vicious knee strike.");
            tell_room(ETO, "%^MAGENTA%^The monk leaps up and knees " + targ->query_cap_name() + " in the chest with this vicious knee strike.", targ);
            return random(10);

        case 9:
            tell_object(targ, "%^CYAN%^The monk spins around and then thrust-kicks you. The force of the spinning thrust kick knocks you back.");
            tell_room(ETO, "%^CYAN%^The monk spins around and then thrust-kicks " + targ->query_cap_name() + ". The force of the spinning thrust kick knocks " + targ->query_cap_name() + " back.", targ);
            return random(12);
        }
    }
}

int groove(object targ)
{
    tell_room(ETO, "A sudden placidness comes over the monk. His body and the nature about him become one and he moves with quickness and control");
    set_func_chance(0);
    execute_attack();
    execute_attack();
    set_func_chance(30);
}

void init()
{
    string* str;
    int i;
    ::init();
    str = ETO->query_exits();

    for (i = 0; i < sizeof(str); i++) {
        if (!wizardp(TP)) {
            add_action("push", str[i]);
        }
    }
}

int push()
{
    if (member_array(TP, query_attackers()) != -1) {
        tell_object(TP, "The old monk blocks your attempt to flee easily with his dexterity and speed.");
        return 1;
    } else {
        return 0;
    }
}
