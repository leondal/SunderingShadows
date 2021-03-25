//Treant for the Liveoak druid spell
//Coded by ~Circe~ 3/19/13
//adapted from /d/magic/obj/astral_construct.c

#include <std.h>

inherit WEAPONLESS;

void set_mylevel(int x);
void set_mylong();

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
    set_name("lumbering treant");
    set_id(({ "treant", "lumbering treant" }));
    set_short("%^RESET%^L%^BOLD%^u%^RESET%^m%^BOLD%^b%^RESET%^e%^BOLD%^"
              "r%^RESET%^i%^BOLD%^n%^RESET%^g %^BOLD%^Treant%^RESET%^");
    set_long("%^RESET%^The very image of strength in the depths of winter, this "
             "massive treant takes the form of an oak with %^BOLD%^s%^RESET%^i"
             "%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r%^BOLD%^y bark%^RESET%^ and "
             "sparse %^BOLD%^l%^RESET%^%^GREEN%^e%^ORANGE%^a%^RED%^v%^YELLOW%^e"
             "%^WHITE%^s%^RESET%^ clinging to the colors of fall.  The treant "
             "stands well over thirty feet tall in the open air, though it "
             "seems to be able to shrink to fit into smaller places.  "
             "Eyes the size of saucers peer out from beneath the leafy "
             "canopy, regarding the world with quiet wisdom.");
    set_exp(1);
    set_stats("strength", 18);
    set_stats("intelligence", 7);
    set_stats("dexterity", 25);
    set_race("treant");
    add_limb("trunk", "trunk", 0, 0, 0);
    add_limb("right limb", "trunk", 0, 0, 0);
    add_limb("foliage", "trunk", 0, 0, 0);
    add_limb("root", "trunk", 0, 0, 0);
    add_limb("left limb", "trunk", 0, 0, 0);
    set_attack_limbs(({ "right limb", "left limb" }));
    set_base_damage_type("bludgeoning");
    set_funcs(({ "tangle" }));
    set_func_chance(10);
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
    set_attacks_num((mylevel / 13) + 1);
    set_damage(2, (mylevel / 4));
    set_overall_ac(10 - mylevel);
    set_stats("strength", 18);
    set_stats("intelligence", 7);
    set_stats("dexterity", 25);
    set_property("effective_enchantment", mylevel / 7);
}

int tangle(object victim)
{
    int tangleDC = query_hd();
    tangleDC = (tangleDC / 2) + 20; //DC 20 + level-based bonus. May need to adjust.
    if (!objectp(TO)) {
        return 1;
    }
    if (!objectp(ETO)) {
        return 1;
    }
    if (!objectp(victim)) {
        return 1;
    }
    tell_object(victim, "%^RESET%^%^GREEN%^The %^ORANGE%^roots "
                "%^GREEN%^of the treant spring forth, attempting to trap you!%^RESET%^");
    tell_room(ETO, "%^RESET%^%^GREEN%^The %^ORANGE%^roots %^GREEN%^"
              "of the treant spring forth, attempting to trap " + victim->QCN + "!%^RESET%^", ({ victim }));
    victim->do_damage("torso", random(10) + 5);
    if (!victim->reflex_save(tangleDC)) {
        tell_object(victim, "%^BOLD%^%^GREEN%^The roots trap you and attempt to strangle you!%^RESET%^");
        victim->set_paralyzed(random(tangleDC), "You are trapped in the roots of the treant!");
        return 1;
    }
    return 1;
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
        tell_room(ETO, "%^BOLD%^%^RED%^The treant attacks " + tmp[num]->QCN + "!");
    }
    return;
}

void heart_beat()
{
    object* tmp;
    int i, j;
    tmp = ({});
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
}
