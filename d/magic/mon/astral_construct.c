#include <std.h>

inherit WEAPONLESS;

void set_mylevel(int x);

int mylevel;
object caster;
void save_me(string file)
{
    return 1;
}

void create()
{
    int num;
    ::create();
    set_name("astral construct");
    set_id(({ "construct", "astral construct", "greater summon" }));
    set_short("%^BOLD%^%^CYAN%^Astral Construct%^RESET%^");

    set_long("%^RESET%^%^CYAN%^Crafted from some sort of transluscent material, " +
             "this creature seems to be an impressive mass of crystal given humanoid " +
             "shape.  Its shoulders are wide enough for any blacksmith, and its " +
             "hulking form seems to be perfectly balanced.  Its legs are thick and " +
             "strong, and raised ridges along its forearms appear almost like " +
             "blades.  A thick, curving horn rises from its forehead, completing " +
             "the menacing image.%^RESET%^");
    set_exp(1);
    set_stats("strength", 20);
    set_stats("constitution", 20);
    set_stats("dexterity", 5);
    set_race("elemental");
    set_body_type("human");
    set_attack_limbs(({ "right hand", "left hand" }));
    set_base_damage_type("bludgeoning");
    set_hit_funcs((["right hand" : (: TO, "gore" :), "left hand" : (: TO, "gore" :)]));
    set_funcs(({ "gore" }));
    set_func_chance(20);
}

int isMagic()
{
    return 5;
}

set_caster(object ob)
{
    if (objectp(ob)) {
        caster = ob;
    }else {
        remove();
    }
}

object query_caster()
{
    return caster;
}

void set_mylevel(int x)
{
    mylevel = x;
    set_hd(mylevel, 10);
    set_mlevel("fighter", mylevel);
    set_max_hp(mylevel * 20);
    set_hp((int)TO->query_max_hp());
    set_attacks_num((mylevel / 13) + 1);
    set_damage(1, mylevel);
    set_overall_ac(10 - mylevel);
    set_stats("strength", 20);
    set_stats("constitution", 20);
    set_stats("dexterity", 5);
    set_property("effective_enchantment", (mylevel / 7) + 1);
}

int gore(object victim)
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
    if (!random(4)) {
        tell_object(victim, "%^RESET%^%^CYAN%^The astral construct lowers its " +
                    "head and charges into you head first, %^BOLD%^goring %^RESET%^" +
                    "%^CYAN%^you with its horn!%^RESET%^");
        tell_room(ETO, "%^RESET%^%^CYAN%^The astral construct lowers its " +
                  "head and charges into " + victim->QCN + " head first, %^BOLD%^goring %^RESET%^" +
                  "%^CYAN%^" + victim->QO + " with its horn!%^RESET%^", ({ victim }));
        victim->do_damage("torso", random(10) + 5);
        return 1;
    }else {
        return 1;
    }
}

void defend()
{
    int num, numfoes, i, j;
    object* tmp;

    tmp = ({});
    numfoes = sizeof(tmp = caster->query_attackers());
    for (num = 0; num < numfoes; num++) {
        if (!objectp(tmp[num])) {
            continue;
        }
        if (member_array(tmp[num], (object*)TO->query_attackers()) != -1) {
            continue;
        }
        if (!objectp(TO)) {
            continue;
        }
        TO->kill_ob(tmp[num], 1);
        tell_room(ETO, "%^BOLD%^%^RED%^The astral construct attacks " + tmp[num]->QCN + "!");
    }
    return;
}

void heart_beat()
{
    string party;
    ::heart_beat();
    if (!objectp(caster)) {
        remove();
    }
    if (!objectp(TO)) {
        remove();
    }
    if ((object*)caster->query_attackers() != ({})) {
        defend();
    }
    TO->remove_attacker(0);

    if (query_hp() < query_max_hp()) {
        add_hp(query_max_hp() / 25);
    }
}

void die(object obj)
{
    if (objectp(caster)) {
        caster->remove_property("has_elemental");
    }
    tell_room(ETO, "%^BOLD%^%^CYAN%^Unable to maintain corporeal form, the construct returns to the astral plane.%^RESET%^");

    remove();
}
