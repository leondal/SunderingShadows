#include <std.h>
#include "../marsh.h"

inherit MONSTER;

int level;

void create()
{
    object ob;
    :: create();
    set_name("reaver");
    set_id(({ "reaver", "demon reaver" }));
    set_short("%^RESET%^%^RED%^Reaver%^RESET%^");
    set_long("%^RESET%^%^RED%^" "The humanoid which stands before you is one of an extremly "
             "vile nature. Pure worshippers of evil and the (un)dead, the "
             "have adopted a cult like magical craft of immense power. This "
             "power has long often been sought after by users of magic across "
             "the land but only those willing to cross over to the vile side "
             "ever can tame it. Even then it is the power which controls the reaver, "
             "not the reaver who controls the craft. Loyal servants to demons, however "
             "they have been known to serve greater apparitions which dwell in "
             "the darkness of our lands. Their skin is rotted and matted in an array "
             "of scalding from unknown burns and festered with disease. The one "
             "before you wears a long robe stained with ancient blood of power."
             "%^RESET%^");

    set_gender("male");
    set_class("fighter");

    level = roll_dice(1, 10) + 25;

    set_guild_level("fighter", level);
    set_mlevel("fighter", level);
    set_hd(level, 12);
    set_max_hp(level * 18);
    set_hp(level * 18);
    set_size(2);

    set_property("magic", 1);
    set_wielding_limbs(({ "right hand", "left hand" }));
    set_overall_ac(10 - level);
    set_mob_magic_resistance("average");
    set_new_exp(level + 10, "high");
    set_body_type("humanoid");
    set_race("human");
    set("aggressive", 50);

    set_alignment(9);
    ob = new(OPATH "greater_scythe");
    if (random(3)) {
        ob->set_property("monsterweapon", 1);
    }
    ob->move(TO);
    call_out("wieldem", 1);
    set_property("full attacks", 1);
    new(OPATH "robe")->move(TO);
    command("wear robe");
    ob->move(TO);

    add_money("gold", random(2000) + 400);
    set_emotes(3, ({ "%^RED%^Visions of bloodlust fill your mind!%^RESET%^",
                     "%^RED%^The reaver attempts to possess you!%^RESET%^",
                     "%^RED%^The reaver utters a guttural chant of abomination!%^RESET%^",
                     "The reaver fails to gate.",
                     "%^BOLD%^%^BLUE%^The reaver hurls a %^MAGENTA%^bolt%^BLUE%^ "
                     "of pure evil at you!%^RESET%^", }), 1);

    set_property("no paralyze", 1);
    set_property("no tripped", 1);
    set_speed(50);
    set_moving(1);
    set_nogo(({ ROOMS "m44", ROOMS "m44.c" }));
    set_property("add kits", 10);
    set_property("magic", 1);
    set_max_level(36);
    set_stats("strength", 25);
    set_stats("dexterity", 25);
    set_stats("constitution", 25);
    set_stats("intelligence", 25);
    set_stats("wisdom", 25);
    set_stats("charisma", 25);
    add_attack_bonus(roll_dice(1, 6));
    add_damage_bonus(roll_dice(1, 6));
    set_monster_feats(({
        "rush",
        "sweepingblow",
        "blade block",
        "impale",
        "light weapon",
        "strength of arm",
        "knockdown",
        "powerattack",
        "expertise",
        "daze",
        "shatter",
        "sunder"
    }));
    set_funcs(({
        "moves",
        "impaleit",
        "sweepit",
        "rushit",
        "dazeit",
        "shatterit",
        "sunderit"
    }));
    set_func_chance(50);
}

void wieldem()
{
    if (!objectp(TO)) {
        return;
    }
    TO->force_me("wield scythe");
    set_property("full attacks", 1);
}

void moves(object targ)
{
    object storm;
    int i;

    if (!objectp(TO)) {
        return;
    }
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }

    switch (roll_dice(1, 4)) {
    case 1:

        tell_room(ETO, "%^BOLD%^%^BLUE%^The reaver invokes a spell of hatred to his masters!\n"
                  "%^RESET%^%^BLUE%^An Demonstorm brews in the area!%^RESET%^");
        storm = new(DSOBJ);
        storm->move(ETO);
        storm->start_obj();
        return 1;

    case 2:

        tell_room(ETO, "%^BOLD%^%^RED%^The earth opens and a host of demonic beings flow from the "
                  "depths below. ", targ);
        tell_object(targ, "%^BOLD%^%^RED%^Cackling demons appear all around you! "
                    "Before you can run, they dive into your body burning "
                    "you to your soul!%^RESET%^");
        tell_room(ETO, "%^CYAN%^%^BOLD%^" + targ->QCN + " screams in agony as flaming spirits leap "
                  "into " + targ->QP + " body. ", targ);
        tell_object(targ, "%^RESET%^%^RED%^You scream in terror as shadowy forms rip bits of "
                    "your essence from your soul!%^RESET%^");

        for (i = 0; i < 10; i++) {
            tell_room(ETO, "%^GREEN%^%^BOLD%^" + targ->QCN + " screams in agony "
                      "as " + targ->QP + " soul is torn!", targ);
            tell_object(targ, "%^RESET%^%^GREEN%^Your soul is %^RED%^burned%^GREEN%^ and "
                        "%^RED%^torn%^GREEN%^!%^RESET%^");
            "/std/effect/status/shaken"->apply_effect(targ, roll_dice(1, 6));
            targ->cause_typed_damage(targ, targ->return_target_limb(),roll_dice(1, (level / 2)),"divine");
        }
        return 1;

    case 3:

        if ((int)TO->query_hp() < 200) {
            for (i = 0; i < 10; i++) {
                tell_room(ETO, "%^CYAN%^The reaver mutters a demonic plea for health!%^RESET%^");
                TO->add_hp(level);
            }
        }else {
            tell_object(targ, "%^BOLD%^%^BLUE%^The reaver hurls a %^MAGENTA%^bolt%^BLUE%^ "
                        "of pure evil at you!%^RESET%^");
            tell_room(ETO, "%^BOLD%^%^BLUE%^The reaver hurls a %^MAGENTA%^bolt%^BLUE%^ "
                      "of pure evil at " + targ->QCN + "!%^RESET%^", targ);
            if (REFLEX(targ, -1 * (level - 15))) {
                tell_object(targ, "%^BOLD%^You duck out of the way at the last instant, "
                            "avoiding the bolt!");
                tell_room(ETO, "%^BOLD%^" + targ->QCN + " ducks at the last instant, "
                          "avoiding the bolt!", targ);
            }else {

                targ->cause_typed_damage(targ, "head",roll_dice(8, 8),"divine");
                
            }
            return 1;
        }

    case 4:

        if (present("krykoth 3", ETO)) {
            return 1;
        }
        tell_object(targ, "%^GREEN%^The reaver chants the ancient and demonic oath of "
                    "the gate!%^RESET%^");
        tell_room(ETO, "%^GREEN%^ The reaver chants the ancient and demonic oath of "
                  "the gate!%^RESET%^", targ);
        tell_room(ETO, "%^BOLD%^%^RED%^A krykoth fades into view!%^RESET%^");

        new("/d/dagger/marsh/tower/mon/krykoth.c")->move(ETO);
        TO->set_exp(10000);

        if (objectp(present("krykoth", ETO))) {
            present("krykoth", ETO)->force_me("kill " + targ->query_name() + "");
        }
        return 1;
    }
}
