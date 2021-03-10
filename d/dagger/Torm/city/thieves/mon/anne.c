//based off void assassin -H "cleaner" for vethor's place -H 12/29/20
#include <std.h>
#include <daemons.h>
inherit MONSTER;

void create()
{
    ::create();
    set_name("anne");
    set_id(({ "outsider", "assassin", "anne" }));
    set_short("Anne, a maid");
    set_long("This maid joined up with vethor later on "+
    "in his career.   She often is involved in various "+
    "'cleaning' acts.   She wears a black and white maid"+
    " outfit with her hair back in a pony tail.");
    set_race("outsider");
    set_gender("female");
    set_class("fighter");
    set_mlevel("fighter", 50);
    set("base_class", "fighter");
    set_mlevel("assassin", 10);
    add_search_path("/cmds/feats");
    set_hd(60, 10);
    set_level(60);
    set_hp(random(2000) + 1000);
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
    set_spells(({ "hellball",
                  "animus blizzard",
                  "fiery body", }));
    set_property("cast and attack", 1);
    set_spell_chance(13);
    set_funcs(({ "strike" }));
    set_func_chance(30);
    set_scrambling(1);
  
    set_attacks_num(5);
    set_damage(5, 20);
    set_new_exp(60, "boss");
    set_max_level(35);
    set_base_damage_type("silver");
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
            tell_room(ETO, "%^BOLD%^%^BLACK%^The assassin lands a %^BLACK%^fi%^RESET%^%^MAGENTA%^n%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^l%^BOLD%^%^BLACK%^ blow at%^RESET%^ ");

            ppl[i]->die();
            tell_object(ppl[i], "%^BOLD%^%^CYAN%^OOC - This maid killed you for breaking Vethor's trophy case.");
            ppl[i]->set_mini_quest("Achieved: Gracefully slain by Anne for messing with Vethor's trophy case");
            stuff = all_inventory(ppl[i]);
            for (j = 0; j < sizeof(stuff); j++) { //remove all assassin marks
                if (stuff[j]->id("mark999")) 
                    stuff[j]->remove();
                
            }
        }
    }

    if (!sizeof(TO->query_attackers())) {
        tell_room(ETO, "%^BOLD%^%^MAGENTA%^Anne steps into shadows and %^MAGENTA%^d%^RESET%^%^MAGENTA%^i%^BOLD%^%^MAGENTA%^sappea%^RESET%^%^MAGENTA%^r%^BOLD%^%^MAGENTA%^s%^RESET%^%^MAGENTA%^.");
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