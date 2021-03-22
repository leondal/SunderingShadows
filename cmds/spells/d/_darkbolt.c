#include <std.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("darkbolt");
    set_spell_level(([ "mage" : 5, "cleric" : 5 ]));
    set_spell_sphere("necromancy");
    set_domains("darkness");
    set_syntax("cast CLASS darkbolt on TARGET");
    set_damage_desc("half cold, half electricity");
    set_description("This spell will hurl a bolt of pure evil at the target.  If the target is able to move in time, then "
                    "they will only suffer some of the damage.  This spell may also hit some of those who are standing near the target.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    splash_spell(1);
    set_save("reflex");
    set_feats_required(([ "mage" : "gift of the shadows"]));
}

int preSpell()
{
    if (!objectp(target)) {
        tell_object(caster, "This spell requires a target.");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
    tell_object(caster, "%^BOLD%^%^BLACK%^%^You chant in a secretive whisper," +
                " and the shadows swirl around you, congregating in your palms.");
    tell_room(place, "%^BOLD%^%^BLACK%^The shadows swirl around " + caster->QCN + "," +
              " congregating in " + caster->QP + " palms.", ({ caster }));
    return "display";
}

void spell_effect(int prof)
{
    object* targets,
        room;

    int dam;

    targets = distinct_array(target_selector() + ({ target }));

    if (!sizeof(targets)) {
        tell_object(caster, "With no targets, your spell fizzles.");
        return;
    }

    room = environment(caster);

    tell_object(caster, "%^BOLD%^%^BLACK%^You hurl your fist towards " + target->QCN + " and a beam of "
                "darkness flows forth towards your enemies.");
    tell_room(place, "%^BOLD%^%^BLACK%^" + caster->QCN + " hurls " + caster->QP + " fist forth and a beam "
              "of darkness flows towards " + target->QP + " enemies!", ({ caster }));


    foreach(object ob in targets)
    {
        dam = sdamage;

        if (objectp(ob) && environment(ob) == room) {
            if (do_save(ob, 0)) {
                dam /= 2;
                tell_room(room, "%^BLUE%^" + sprintf("The beam of darkness grazes %s.", ob->QCN));
            }else {
                tell_room(room, "%^BLUE%^" + sprintf("The beam of darkness strikes %s!", ob->QCN));
            }

            damage_targ(ob, ob->return_target_limb(), dam / 2, "cold");
            damage_targ(ob, ob->return_target_limb(), dam / 2, "electricity");
        }
    }

    spell_successful();
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
