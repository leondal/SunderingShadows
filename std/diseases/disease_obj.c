#include <std.h>
#include <daemons.h>

#pragma strict_types
#pragma strong_types
#pragma save_types

inherit OBJECT;

int clevel;
int stage = 1;

int force_fail = 0;

string description;
string incubation_desc;
string damage_desc;
string infection_desc;

// Diseases persist across logins by moving into player's inventory.

void create()
{
    ::create();
    set_name("disease_obj");
}

/**
 * Description you'll see in the helpfile
 */
void set_description(string arg)
{
    description = arg;
}

/**
 * Incubation period, if disease has one
 */
void set_incubation(string arg)
{
    incubation_desc = arg;
}

/**
 * Short description on what disease does, similar to spells
 */
void set_damage_desc(string arg)
{
    damage_desc = arg;
}

/**
 * Flavour text on ways of infection
 */
void set_infection(string arg)
{
    infection_desc = arg;
}

/**
 * Some methods of infection (spells lige greater contagion)
 * explicitly state they cause fort saves to always fail. This setting
 * to disease object, after it had been spawned, enforces this
 * behavior.
 */
void set_force_fail()
{
    force_fail = 1;
}

/**
 * Reverts disease one stage back with power check
 */
int reverse_stage(int power)
{
    if (power <= clevel) {
        return 0;
    }
    stage -= 2;
    advance_disease();
    return 1;
}

int is_disease()
{
    return 1;
}

/**
 * First thing to be called after infection. Inherited diseases might
 * rewrite it, but setting of clevel is required.
 */
void init_disease(int dc)
{
    clevel = dc;
    return;
}

/**
 * Usually the same as spell_effect in spells. Here the magic of the disease happens.
 */
void advance_disease()
{
    return;
}

/**
 * Shared fort save for some common diseases.
 */
int do_save(int disease_bonus)
{
    if (force_fail) {
        return 0;
    }
    if (!disease_bonus) {
        disease_bonus = 0;
    }
    if ("/daemon/saving_throw_d"->fort_save(ETO, -(clevel + disease_bonus))) {
        return 1;
    }
    return 0;
}

/**
 * Default curing function. You may override it in your disease.
 */
int cure_disease(int power)
{
    if (power <= clevel) {
        return 0;
    }
    if (objectp(TO)) {
        TO->remove();
        return 1;
    }
}

/**
 * Default infection function.
 *
 * Makes a copy of this object and moves it into target's inventory, performs a check.
 *
 * If you're to overwrite it it must return disease's object on success and 0 on fail.
 */
object infect(object victim, int dc)
{
    object tmp;
    object * diseases;

    if (is_immune(victim)) {
        return 0;
    }

    diseases = filter_array(all_inventory(victim), (:$1->is_disease():));
    if (sizeof(diseases)) {
        return 0;
    }

    tmp = new(file_name(TO));
    tmp->move(victim);
    tmp->init_disease(dc);
    return tmp;
}

/**
 * Default immunity check.
 */
int is_immune(object victim)
{
    if (victim->is_undead()) {
        return 1;
    }
    if (FEATS_D->usable_feat(victim, "purity of body") ||
        FEATS_D->usable_feat(victim, "divine health")) {
        return 1;
    }
    if(member_array("plague", victim->query_divine_domain()) >= 0)
        return 1;
    
    return 0;
}

void help()
{
    write("%^GREEN%^%^BOLD%^Name: %^RESET%^" + query_name());

    if (infection_desc) {
        write("%^GREEN%^%^BOLD%^Infection: %^RESET%^" + infection_desc);
    }
    if (incubation_desc) {
        write("%^GREEN%^%^BOLD%^Incubation: %^RESET%^" + incubation_desc);
    }
    if (damage_desc) {
        write("%^GREEN%^%^BOLD%^Damage: %^RESET%^" + damage_desc);
    }
    write("%^GREEN%^%^BOLD%^Description: %^RESET%^" + description);
}
