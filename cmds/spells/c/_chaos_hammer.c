#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
inherit SPELL;

string element;
void dest_effect();
void paralysis(mixed* arg2);

void create()
{
    ::create();
    set_spell_name("chaos hammer");
    set_spell_level(([ "inquisitor" : 4, "cleric" : 4]));
    set_domains("chaos");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS chaos hammer on TARGET");
    set_damage_desc("divine");
    set_description("You unleash chaotic power to smite your enemies. The power takes the form of a multicolored explosion of leaping, ricocheting energy.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    splash_spell(1);
    set_save("will");
}

string query_cast_string()
{
    element = "divine";
    tell_object(caster, "%^YELLOW%^You start to carefully spell out a chaotic invocation!");
    tell_room(place, "%^YELLOW%^" + caster->QCN + " spells out words in an apparent disorder!", caster);
    return "display";
}

void spell_effect(int prof)
{
    object* inven, * hits;
    int damage, i, j, number, level, bonus;
    string cname, tname;

    bonus = prof / 10 - 10;

    cname = caster->QCN;
    tname = target->QCN;

    level = clevel;
    number = level;

    number = clevel;

    hits = ({});
    inven = ({});

    inven = target_selector();
    inven -= ({ target });
    inven -= ({ caster });


    tell_object(target, "%^YELLOW%^After " + cname + " releases chaotic power that leaps toward you!");
    tell_room(place, "%^YELLOW%^A surge of chaotic power leaps toward " + tname + "!", target);

    if (do_save(target, 0)) {
        damage_targ(target, target->return_target_limb(), sdamage / 2, element);
    }else {
        damage_targ(target, target->return_target_limb(), sdamage, element);
    }

    spell_kill(target, caster);

    tell_room(place, "%^BOLD%^%^WHITE%^The surge having been freed chooses its own path!");


    while (number > 0 && sizeof(inven) != 0) {
        number -= 1;
        i = random(sizeof(inven));

        if (!objectp(inven[i])) {
            inven -= ({ inven[i] });
            continue;
        }

        if (inven[i]->is_invincible()) {
            inven -= ({ inven[i] });
            continue;
        }

        if (!userp(inven[i])) {
            spell_kill(inven[i], caster);
        }

        if (do_save(inven[i], 0)) {
            damage_targ(inven[i], "torso", damage / 2, element);
        }else {
            damage_targ(inven[i], "torso", damage, element);
        }

        tell_object(inven[i], "%^YELLOW%^The surge leaps toward you, smiting you with its power!");
        tell_room(place, "%^BOLD%^%^RED%^The surge of power leaps toward " + inven[i]->QCN + "!", inven[i]);

        if (!objectp(caster)) {
            dest_effect();
            return;
        }
        inven -= ({ inven[i] }); // each target can only be hit once!
    }

    tell_room(place, "%^BOLD%^%^GREEN%^The surge disperses itself, the last of its energy spent!");

    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
