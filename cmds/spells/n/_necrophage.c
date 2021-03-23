#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

int num;
int undeadt;

void create()
{
    ::create();
    set_spell_name("necrophage");
    set_spell_level(([ "mage" : 2, "cleric" : 2 ]));
    set_domains("undeath");
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS necrophage on TARGET");
    set_damage_desc("acid");
    set_description("You create a pale yellow slime on the target. The slime begins to devour the target rapidly, causing them to suffer. An undead creature may attempt to save from the damage to reduce it, but if it dies while the spell is in affect, it may explode with acid. If it is already a corpse, it will explode immediately");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_non_living_ok(1);
    set_save("fort");
    splash_spell(3);
}

string query_cast_string()
{
    return "%^BOLD%^%^GREEN%^As "+caster->QCN+" utters a curse, making strange passes.%^RESET%^";
}

spell_effect(int prof)
{
    spell_successful();

    if (target->is_living()) {
        tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+" completes the spell and releases acidic slime at "+target->QCN+".",target);
        tell_object(target,"%^BOLD%^%^GREEN%^"+caster->QCN+" and releases the acidic slime at you.",target);
    } else {
        tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+" completes the spell and releases acidic slime at "+target->query_short()+".");
    }

    if (target->is_living()) {
        damage_targ(target, target->return_target_limb(), sdamage,"acid");
    }

    if (target->is_corpse()) {
        TO->explode();
        TO->remove();
        return;
    }

    if (target->is_undead()) {
        undeadt = 1;
    }
    num = clevel / 8 + 1;
    call_out("rot_again",ROUND_LENGTH - 1);
}

void explode()
{
    object* attackers;
    int i;

    attackers = target_selector();
    tell_room(place, "%^BOLD%^%^GREEN%^As acidic slime finally destroys the corpse it explodes, spreading acid around.");

    for (i = 0; i < sizeof(attackers); i++) {
        if (!objectp(attackers[i])) {
            continue;
        }
        tell_object(attackers[i], "%^GREEN%^%^BOLD%^Youre scorched by the acid!%^RESET%^");
        damage_targ(attackers[i], attackers[i]->return_target_limb(), sdamage * 3 / 4, "acid");
    }
}

void rot_again()
{

    int dam;

    if (!objectp(target)) {
        if (undeadt) {
            TO->explode();
        }
        dest_effect();
        return;
    }

    if (target->query_hp() < 0) {
        if (undeadt) {
            TO->explode();
        }
        dest_effect();
        return;
    }

    dam = sdamage / 6;

    if (target->is_undead()) {
        if (do_save(target, -4)) {
            dam /= 2;
        }
    }

    place = ENV(target);

    define_base_damage(0);
    tell_room(ENV(target),"%^BOLD%^%^GREEN%^The acidic slime continues to rot away "+target->QCN+"'s essence!%^RESET%^",target);
    tell_object(target,"%^BOLD%^%^GREEN%^The acidic slime burns through you!%^RESET%^");
    damage_targ(target, target->return_target_limb(), dam,"acid");

    if(num-- < 0)
    {
        dest_effect();
        return;
    }
    else
    {
        call_out("rot_again",ROUND_LENGTH);
    }
}

dest_effect()
{
    if(find_call_out("rot_again") != -1)
        remove_call_out("rot_again");

    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}
