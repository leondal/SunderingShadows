#include "/d/islands/dallyh/fways.h"

inherit MONSTER;

void create()
{
    ::create();
    set_name("demon footman");
    set_id(({ "demon", "footman", "demon footman", "dallyhallyevil" }));

    set_short("%^BOLD%^%^BLACK%^D%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^m%^RESET%^%^RED%^o" +
              "%^BOLD%^%^BLACK%^n F%^RESET%^%^RED%^oo%^BOLD%^%^BLACK%^tm%^RESET%^%^RED%^a%^BOLD%^" +
              "%^BLACK%^n%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^This twisted created towers over ten feet tall. " +
             "It has a massive round head that is inlaid with two %^BOLD%^%^RED%^blazing red" +
             "%^RESET%^%^ORANGE%^ eyes, which reflect an intense hatred and an amazing intellect. " +
             "It's body resembles a gargoyle except for its skin, which is a dark brown and covered " +
             "with strange %^RESET%^%^CYAN%^glowing runes%^RESET%^%^ORANGE%^ which continually shift " +
             "positions. You expect that the %^RESET%^%^CYAN%^runes%^RESET%^%^ORANGE%^ are actually " +
             "binding the creature to the will of someone or something, but whatever that might be is " +
             "unknown. The wings of this creature extend to approximately eight feet on either side of it, " +
             "but you realize that the tips of them have been clipped, and a series of %^BOLD%^%^BLACK%^deep black" +
             "%^RESET%^%^ORANGE%^ rings pierce the length of them. The majority of its body ripples with " +
             "muscles which heave continually.%^RESET%^");

    set_race("demon");
    set_body_type("arachnid");
    set_property("swarm", 1);
    set_overall_ac(-44);
    set_hd(48);
    set_size(4);
    set_wielding_limbs(({ "left front claw", "right rear claw" }));
    set_attacks_num(6);
    set_attack_limbs(({ "left wing", "right wing", "tail",
                        "left rear claw", "right rear claw", "left front claw",
                        "right front claw", "head" }));
    set_base_damage_type("bludgeoning");
    set_damage(4, 20);
    set_moving(1);
    set_speed(20);
    set_max_hp(2000 + random(1000));
    set_hp(query_max_hp());
    set_mob_magic_resistance("average");

    switch (random(4)) {
    case 0:
        set_all_stats(({ 30, 30, 30, 12, 12, 12 }));
        set_class("fighter", 48);
        set_funcs(({ "stuns", "slashes" }));
        set_func_chance(35);
        break;

    case 1:
        ({ "strength", "dexterity", "constitution", "intelligence", "wisdom", "charisma" });
        set_all_stats(({ 20, 20, 30, 30, 12, 12 }));
        set_class("mage", 48);
        set_spells(({
            "magic missile",
            "fireball",
            "lightning bolt",
            "hideous laughter",
            "cone of cold",
            "meteor swarm",
        }));

        set_spell_chance(110);
        break;

    case 2:
        set_all_stats(({ 20, 20, 30, 12, 12, 30 }));
        set_class("sorcerer", 48);
        set_spells(({
            "horrid wilting",
            "weird",
            "wail of the banshee",
            "shadow nova",
        }));
        set_spell_chance(45);
        set_funcs(({ "obliterate" }));
        set_func_chance(45);
        break;

    case 3:
        set_all_stats(({ 30, 30, 30, 12, 12, 12 }));
        set_class("barbarian", 48);
        set_funcs(({ "stuns", "slashes" }));
        set_func_chance(110);
        break;
    }
    set("aggressive", 100);
    set_alignment(9);

    set_new_exp(48, "high");

    set_funcs(({ "stuns" }));
    set_func_chance(50);

    add_money("platinum", 500 + random(1000));
}

void stuns(object targ)
{
    string me;
    int mod;
    if (!objectp(TO) || !objectp(targ)) {
        return;
    }
    me = TO->query_short();
    if (!intp(mod = TO->query("damage mod")) || mod < 1) {
        mod = 1;
    }
    if (roll_dice(2, 20) > targ->query_stats("wisdom") &&
        !targ->query_property("no paralyze")) {
        tell_room(ETO, me + "%^RESET%^%^BLUE%^'s eyes glow an " +
                  "intense%^BOLD%^%^RED%^ RED %^RESET%^%^BLUE%^hypnotizing"
                  + targ->query_cap_name() + "!", targ);

        tell_object(targ, me + "%^RESET%^%^BLUE%^'s eyes glow an" +
                    " intense%^BOLD%^%^RED%^ RED %^RESET%^%^BLUE%^hypnotizing you!");
        targ->do_damage("torso", (roll_dice(1, 100) * mod));
        targ->set_paralyzed(roll_dice(3, 2),
                            "%^RESET%^%^RED%^You can't take your gaze off the burning red eyes!");
        return;
    }else {
        tell_object(targ, me + "%^RESET%^%^BLUE%^'s eyes glow an" +
                    " intense%^BOLD%^%^RED%^ RED %^RESET%^%^BLUE%^but you look away!");
    }
}

void slashes(object targ)
{
    string me, * alimbs, limb;
    int mod, dam, x;
    object* ats;
    if (!objectp(TO) || !objectp(targ)) {
        return;
    }
    me = TO->query_short();
    if (!intp(mod = TO->query("damage mod")) || mod < 1) {
        mod = 1;
    }
    alimbs = TO->query_attack_limbs();
    for (x = 0; x < sizeof(alimbs); x++) {
        if (!objectp(TO)) {
            return;
        }
        if (!objectp(targ)) {
            if (!sizeof(ats = TO->query_attackers())) {
                return;
            }
            targ = ats[random(sizeof(ats))];
            if (!objectp(targ)) {
                return;
            }
        }
        limb = targ->return_target_limb();
        tell_object(targ, me + "%^BOLD%^%^BLACK%^ slams into your " + limb + " with its " + alimbs[x] + "!%^RESET%^");

        tell_room(TO, me + "%^BOLD%^%^BLACK%^ slams into " + targ->QCN + "%^BOLD%^%^BLACK%^'s " +
                  limb + " with its " + alimbs[x] + "!%^RESET%^", targ);

        targ->do_damage(limb, roll_dice(4, 4) * mod);
        continue;
    }
    return;
}

void obliterate(object targ)
{
    string me, mySpells = ({ "/cmds/spells/f/_fireball", "/cmds/spells/p/_powerword_stun", "/cmds/spells/p/_powerword_kill" });
    string* myPhrases = ({ "je oep dnl!", "eghrblii znbhro njilsh!", "ezz he hrl mfoii nhr oep!",
                           "wglwmgl he wlgnir, amvveh!", "wlgnir, aeghmb!", "n iwnh ej oep, aeghmb!",
                           "oep smjjeh ihmjd mvmnjih al, wpjo ejl!", "je oep ipzzlg!" });
    string mySpell, myPhrase;
    int mod, x;
    object* ats;
    if (!objectp(TO) || !objectp(targ)) {
        return;
    }
    me = TO->query_short();
    if (!intp(mod = TO->query("damage mod")) || mod < 1) {
        mod = 1;
    }
    for (x = 0; x < sizeof(mySpells); x++) {
        if (!objectp(TO)) {
            return;
        }
        if (!objectp(targ)) {
            if (!sizeof(ats = TO->query_attackers())) {
                return;
            }
            targ = ats[random(sizeof(ats))];
            if (!objectp(targ)) {
                return;
            }
        }
        mySpell = mySpells[x];
        myPhrase = myPhrases[random(sizeof(myPhrases))];

        tell_object(targ, me + "%^BOLD%^%^WHITE%^ turns to you and growls: \n%^BOLD%^%^BLACK%^%^FLASH%^" + myPhrase + "\n%^RESET%^");

        tell_room(ETO, me + "%^BOLD%^%^WHITE%^ faces " + targ->QCN + "%^BOLD%^%^WHITE%^ and growls: \n%^BOLD%^%^BLACK%^%^FLASH%^" +
                  myPhrase + "\n%^RESET%^", targ);

        new(mySpell)->use_spell(TO, targ, (10 + random(TO->query_highest_level() * mod)), 100, "mage");
        continue;
    }
    return;
}

void heart_beat()
{
    ::heart_beat();
    if (!objectp(TO)) {
        return;
    }
    DYN_UP_D->dynamic_update(TO);
    return;
}
