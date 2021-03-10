//Updated description and mechanics - Octothorpe 11/7/09
//Coded by Bane for invasions...hordling monster that makes itself//
// adding id of laeradmon *Styx* 12/20/03, last change 3/27/01

#include <std.h>
inherit WEAPONLESS;

void make_me();
void create()
{
    ::create();
    set_id(({ "hordling", "Hordling", "laeradmon","aberration" }));
    set_name("hordling");
    set_short("%^RESET%^%^CYAN%^horrifying hordling%^RESET%^");
    set_long("%^RESET%^%^CYAN%^Each hordling is an intrinsically unique " +
             "creature, for better or worse.  They are nothing more than a " +
             "disgusting mass of body parts and assorted limbs.  Some are " +
             "little more than amorphous blobs, or an assortment of random " +
             "eyes and snouts.  The one constant thread found throughout " +
             "their kind is their incredible depravity and unagreeable " +
             "nature.  This evidence of infinity, the twist of the known, " +
             "has surely come about from the procreation of the " +
             "wicked.%^RESET%^");
    set_body_type("human");
    set_race("hordling");
    set_size(random(3) + 1);
    set_alignment(6);
    set_mob_magic_resistance("average");
    set_property("swarm", 1);
    set_attack_bonus(2);
    set_moving(1);
    set_speed(20);
    set_nogo(({ "/d/laerad/wasteland/waste1" }));
    make_me();
}

void init()
{
    if ((string)TP->query_level() > 12 && interactive(TP) && !wizardp(TP) &&
        !TP->query_true_invis()) {
        force_me("kill " + TPQN);
        TO->kill_ob(TP, 1);
    }
}

void make_me()
{
    object ob;
    int i, j, k;
    string theclass, short, ac, hd;
    i = random(5);
    switch (i) {
    case (0): hd = 15;
        break;

    case (1): hd = 17;
        break;

    case (2): hd = 19;
        break;

    case (3): hd = 21;
        break;

    case (4): hd = 23;
    }
    switch (i) {
    case (0): theclass = "fighter";
        break;

    case (1): theclass = "thief";
        break;

    case (2): theclass = "mage";
        break;

    case (3): theclass = "cleric";
        break;

    case (4): theclass = "antipaladin";
    }
    set_class(theclass);
    set_mlevel(theclass, hd);
    set_hd(hd, 10);
    if (theclass != "antipaladin") {
        set_guild_level(theclass, hd);
    }else {
        set_guild_level("cleric", hd + (-8));
    }
    set_max_hp(200);
    set_hp(TP->query_max_hp());
    set_exp(13600);
    switch (theclass) {
    case "fighter":
        set_base_damage_type("slashing");
        set_attack_limbs(({ "right hand", "left hand", "head" }));
        set_attacks_num(4);
        set_damage(3, 6);
        set_stats("strength", 23);
        set_funcs(({ "terror_me", "stab_me" }));
        set_func_chance(25);
        break;

    case "thief":
        set_base_damage_type("slashing");
        set_attack_limbs(({ "right hand", "left hand" }));
        set_attacks_num(2);
        set_damage(2, 8);
        set_stats("strength", 22);
        set_funcs(({ "stab_me", "terror_me" }));
        set_func_chance(30);
        break;

    case "mage":
        set_base_damage_type("slashing");
        set_attack_limbs(({ "right hand", "left hand" }));
        set_attacks_num(1);
        set_damage(1, 20);
        set_stats("strength", 20);
        set_spells(({
            "magic missile",
            "vampiric touch",
            "fireball",
            "lightning bolt",
            "hold person",
            "cone of cold",
            "meteor swarm",
            "incendiary cloud",
            "chain lightning"
        }));
        set_spell_chance(75);
        set_funcs(({ "terror_me", "stab_me" }));
        set_func_chance(25);
        break;

    case "cleric":
        set_base_damage_type("slashing");
        set_attack_limbs(({ "right hand", "left hand" }));
        set_attacks_num(2);
        set_damage(3, 6);
        set_stats("strength", 20);
        set_spells(({
            "limb attack",
            "call lightning",
            "cause critical wounds",
            "cause serious wounds",
            "flame strike",
            "earthquake",
            "dispel good",
            "fire storm"
        }));
        set_spell_chance(50);
        set_funcs(({ "terror_me", "stab_me" }));
        set_func_chance(25);
        break;

    case "antipaladin":
        set_base_damage_type("slashing");
        set_attack_limbs(({ "right hand", "left hand", "head" }));
        set_attacks_num(4);
        set_damage(3, 8);
        set_stats("strength", 23);
        set_spells(({
            "limb attack",
            "call lightning",
            "cause serious wounds"
        }));
        set_spell_chance(25);
        set_funcs(({ "terror_me", "stab_me" }));
        set_func_chance(25);
    }
    switch (i) {
    case (0): ac = 2;
        break;

    case (1): ac = 0;
        break;

    case (2): ac = -2;
        break;

    case (3): ac = -4;
        break;

    case (4): ac = -6;
    }
    set_overall_ac(ac);
}

void stab_me(object targ)
{
    if ("/daemon/saving_throw_d.c"->fort_save(targ, -11)) {
        tell_object(targ, "%^BOLD%^The hordling sheers you with a ragged " +
                    "claw!%^RESET%^");
        tell_room(ETO, "%^BOLD%^The hordling sheers " + targ->QCN + " with a " +
                  "ragged claw!%^RESET%^", targ);
        targ->do_damage(targ->return_target_limb(), roll_dice(8, 8));
        add_attack_bonus(query_attack_bonus() + 1);
        return;
    }
}

void terror_me(object targ)
{
    tell_object(targ, "%^BOLD%^%^BLUE%^The hordling stares at you.%^RESET%^");
    tell_room(ETO, "%^BOLD%^%^BLUE%^The hordling stares at " +
              "" + targ->QCN + ".", targ);
    if ("/daemon/saving_throw_d.c"->will_save(targ, -15)) {
        tell_object(targ, "%^BOLD%^BLUE%^An immense feeling of terror " +
                    "overcomes you!");
        tell_room(ETO, "%^BOLD%^BLUE%^" + targ->QCN + " starts to shake " +
                  "and quiver!", targ);
        add_attack_bonus(query_attack_bonus() + 1);
        targ->run_away();
        targ->run_away();
        targ->run_away();
        targ->run_away();
        targ->run_away();
        targ->run_away();
        return;
    }
    targ->set_paralyzed(random(6), "%^BOLD%^%^BLUE%^You are scared shitless.%^RESET%^");
    add_attack_bonus(query_attack_bonus() + 1);
    return;
}
