#include <std.h>
#include <daemons.h>
inherit MONSTER;

string reason;

void create()
{
    ::create();
    set_name("voidhuntress");
    set_id(({ "outsider", "assassin", "voidhuntress" }));
    set_short("%^BOLD%^%^BLACK%^A%^RESET%^%^MAGENTA%^s%^BOLD%^%^BLACK%^sa%^RESET%^%^MAGENTA%^s%^MAGENTA%^s%^BOLD%^%^BLACK%^in%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This slim %^MAGENTA%^f%^RESET%^%^MAGENTA%^e%^BOLD%^%^MAGENTA%^mi%^RESET%^%^MAGENTA%^n%^BOLD%^%^MAGENTA%^ine %^RESET%^%^MAGENTA%^f%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^g%^BOLD%^%^MAGENTA%^ur%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^ is dressed from head to toe in black outfit, with only her gloving %^MAGENTA%^viol%^RESET%^%^MAGENTA%^e%^BOLD%^%^MAGENTA%^t%^BLACK%^ eyes %^MAGENTA%^piercing%^BLACK%^ through black head bands. She carries an assortment of tools and weapons in numerous leather sheaths and pouches over her clothing.%^RESET%^
");
    set_race("outsider");
    set_gender("female");
    set_class("fighter");
    set_mlevel("fighter", 50);
    set("base_class", "fighter");
    set_mlevel("assassin", 10);
    add_search_path("/cmds/feats");
    set_hd(60, 10);
    set_level(60);
    set_hp(random(1000) + 1000);
    set_overall_ac(-40);
    set_alignment(6);
    set_stats("intelligence", 18);
    set_stats("wisdom", 12);
    set_stats("strength", 26);
    set_stats("charisma", 12);
    set_stats("dexterity", 26);
    set_stats("constitution", 18);
    add_money("platinum", random(2000));
    set_property("full attacks", 1);
    set_monster_feats(({ "dodge", "evasion", "knockdown", "expertise", "mobility", "powerattack", "rush", "dodge", "evasion", "scramble", "spring attack", "crit", "hide in plain sight", "void stalker", "penetrating strike", "greater penetrating strike", "weapon focus", "weapon specialization", "greater weapon focus", "greater weapon specialization", "epic weapon focus", "epic weapon specialization", "lethal strikes" }));
    set_spells(({ "horrid wilthing",
                  "fear",
                  "weird", }));
    set_property("cast and attack", 1);
    set_spell_chance(13);
    set_funcs(({ "strike" }));
    set_func_chance(30);
    set_scrambling(1);
    set_parrying(1);
    set_attacks_num(8);
    set_damage(4, 20);
    set_new_exp(60, "boss");
    set_max_level(35);
    set_base_damage_type("silver");
    reason = "";
    new("/d/atoyatl/tecqumin/obj/seal.c")->move(TO);
}

void strike(object targ)
{
    int x;
    if (!objectp(TO)) {
        return 1;
    }
    if (!objectp(ETO)) {
        return 1;
    }


    tell_object(targ, "%^BOLD%^%^BLACK%^The assassin %^BLACK%^p%^RESET%^%^MAGENTA%^h%^BOLD%^%^BLACK%^ases%^BLACK%^ through your defenses, unleashing fierce %^BLACK%^fl%^RESET%^%^MAGENTA%^u%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^r%^MAGENTA%^y%^BOLD%^ %^BLACK%^of %^BLACK%^bl%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^w%^RESET%^%^MAGENTA%^s%^MAGENTA%^!");
    tell_room(ETO, "%^BOLD%^%^BLACK%^The assassin %^BLACK%^phase%^RESET%^%^MAGENTA%^s%^BOLD%^%^BLACK%^ through%^RESET%^ " + targ->QCN + "'%^BOLD%^%^BLACK%^s defenses unleashing fierce %^BLACK%^f%^RESET%^%^MAGENTA%^l%^BOLD%^%^BLACK%^urr%^RESET%^%^MAGENTA%^y%^BOLD%^ %^BLACK%^of %^RESET%^%^MAGENTA%^b%^MAGENTA%^l%^BOLD%^%^BLACK%^o%^RESET%^%^MAGENTA%^w%^MAGENTA%^s%^BOLD%^%^BLACK%^!%^RESET%^", targ);

    targ->cause_typed_damage(targ, 0, roll_dice(10, 8), "slashing");

    if (!targ->reflex_save(40)) {
        targ->set_paralyzed(roll_dice(1, 2) * 8, "%^BOLD%^%^BLACK%^You re %^BLACK%^re%^RESET%^%^MAGENTA%^c%^BOLD%^%^BLACK%^ov%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^ring%^BLACK%^ from %^BLACK%^fi%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^c%^BOLD%^%^BLACK%^e %^BLACK%^at%^RESET%^%^MAGENTA%^t%^MAGENTA%^a%^BOLD%^%^BLACK%^c%^RESET%^%^MAGENTA%^k%^BOLD%^%^BLACK%^!%^RESET%^");
    }

    return 1;
}

void set_paralyzed(int time, string message)
{
    say("%^BOLD%^%^BLACK%^The %^MAGENTA%^A%^BOLD%^%^BLACK%^ssassin%^BLACK%^ flexes her muscles, and continues.%^RESET%^");
    execute_attack();
    return 0;
}

void set_tripped(int time, string message)
{
    say("%^BOLD%^%^BLACK%^The %^MAGENTA%^A%^BOLD%^%^BLACK%^ssassin%^BLACK%^ flexes her muscles, and continues.%^RESET%^");
    execute_attack();
    execute_attack();
    return 0;
}

void set_reason(string why)
{
    reason = why;
}

void heart_beat()
{
    object* ppl, targ;
    int i;

    ::heart_beat();

    if (!objectp(TO) || !objectp(ETO)) {
        return;
    }

    ppl = filter_array(all_living(ETO), "is_non_immortal_player", FILTERS_D);

    for (i = 0; sizeof(ppl), i < sizeof(ppl); i++) {
        int j;
        object* stuff;

        if (!objectp(ppl[i])) {
            continue;
        }
        if (ppl[i]->query_unconscious()) {
            tell_room(ETO, "%^BOLD%^%^BLACK%^The assassin lands a %^BLACK%^fi%^RESET%^%^MAGENTA%^n%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^l%^BOLD%^%^BLACK%^ blow at%^RESET%^ " + ppl[i]->QCN);

            ppl[i]->die();
            if (strlen(reason)) {
                tell_object(ppl[i], "%^BOLD%^%^CYAN%^OOC - This assassin was sent to kill because of the following reason:\n" + reason + "\n");
            }
            stuff = all_inventory(ppl[i]);
            for (j = 0; j < sizeof(stuff); j++) { //remove all assassin marks
                if (stuff[j]->id("mark999")) {
                    stuff[j]->remove();
                }
            }
        }
    }

    if (!sizeof(TO->query_attackers())) {
        tell_room(ETO, "%^BOLD%^%^MAGENTA%^The %^RESET%^%^MAGENTA%^a%^BOLD%^%^MAGENTA%^s%^RESET%^%^MAGENTA%^s%^BOLD%^%^MAGENTA%^assi%^RESET%^%^MAGENTA%^n%^BOLD%^%^MAGENTA%^ steps into shadows and %^MAGENTA%^d%^RESET%^%^MAGENTA%^i%^BOLD%^%^MAGENTA%^sappea%^RESET%^%^MAGENTA%^r%^BOLD%^%^MAGENTA%^s%^RESET%^%^MAGENTA%^.");
        TO->move("/d/shadowgate/void");
        TO->remove();
        return;
    }

    targ = TO->query_current_attacker();
    if (!objectp(targ)) {
        return;
    }
    return;
}
