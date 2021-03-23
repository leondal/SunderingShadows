#include <std.h>
#include <daemons.h>
#include <spell.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("slay living");
    set_spell_level(([ "cleric" : 5, ]));
    set_spell_sphere("necromancy");
    set_mystery(({ "reaper", "bones" }));
    set_syntax("cast CLASS slay living on TARGET");
    set_description("This spell is necromantic in nature and allows the caster to call forth beings from the land of the "
                    "dead to take the caster's target back with them to their homeland. If the beings are successful, this transition will "
                    "result in the target's instant death.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("fort");
}

string query_cast_string()
{
    return "%^BOLD%^%^RED%^" + caster->QCN + " begins to chant in a mournful tone while swaying back\nand forth with " + caster->QP + " hands raised into the air!%^RESET%^";
}

void spell_effect(int prof)
{
    int x, damage;

    if (!objectp(target) || !objectp(caster)) {
        if (objectp(TO)) {
            TO->remove();
        }
        return;
    }

    place = environment(caster);

    spell_successful();

    if (combat_death_save(target, 6)) {
        tell_object(target, "%^BOLD%^The struggle is won, yet at a price.");
        tell_room(place, "%^BOLD%^The soul survives, yet at a price.", target);
        damage = roll_dice(clevel, 6);
        damage_targ(target, target->return_target_limb(), damage, "negative energy");
        target->set_property("no_slay", ({ caster->query_name() }));
    } else {
        tell_room(place, "%^BOLD%^%^BLUE%^The soul is cleaved from its body and left to drift homelessly!");
        tell_room(place, "%^BOLD%^%^MAGENTA%^The lifeless, soulless, body of " + target->QCN + " drops to the ground!", target);
        tell_object(target, "%^BOLD%^%^RED%^You sense a few last things as your soul is ripped from you body!\n");
        spell_kill(target, caster);
        target->die();
    }
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
