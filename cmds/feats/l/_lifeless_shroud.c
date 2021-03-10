#include <std.h>
#include <daemons.h>

inherit FEAT;

object* exclude = ({});

void create()
{
    ::create();
    feat_type("instant");
    feat_category("Gravecaller");
    feat_name("lifeless shroud");
    feat_prereq("Gravecaller L7");
    feat_syntax("lifeless_shroud");
    feat_desc("Lifeless shroud is a powerful swift ritual that surrounds caster in streams of negative energy they can direct at their will. This shroud of lifeless energy will aid unliving allies, healing them, and will harm all enemies, causing them to be blinded, sickened, shaken or harmed.");
}

int allow_shifted()
{
    return 1;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }

    if ((int)ob->query_class_level("gravecaller") < 7) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_lifeless_shroud(string str)
{
    object feat;
    if (!objectp(TP)) {
        return 0;
    }
    feat = new(base_name(TO));
    feat->setup_feat(TP, str);
    return 1;
}

string cm(string str)
{
    return CRAYON_D->color_string(str, "flat black");
}

void execute_feat()
{
    string YOU, YOUS;
    object obj;

    if (!objectp(caster)) {
        dest_effect();
        return;
    }

    if (FEATS_D->is_active(caster, "lifeless shroud")) {
        obj = query_active_feat("lifeless shroud");
        tell_object(caster, cm("With a swift thought you release the cold within."));
        tell_room(place, cm("" + caster->QCN + "'s eyes briefly turn to glass as the air around looses its coldness."), caster);
        obj->dest_effect();
        dest_effect();
        return;
    }

    tell_object(caster, cm("You close your eyes and concentrate on channeling negative energy."));
    tell_object(caster, cm("Fell powers rise from below the ground through you in a cold stream of lifeless energy."));
    tell_object(caster, cm("The cold becomes the one with you."));

    tell_room(place, cm("" + caster->QCN + "'s eyes glass over and " + caster->QS + " stares blankly at nothing."), caster);
    tell_room(place, cm("The air around " + caster->QCN + " grows chill."), caster);

    caster->set_property("active_feats", ({ TO }));

    ::execute_feat();
    return;
}

void execute_attack()
{
    object* attackers = ({});
    object* allies = ({});
    int i;

    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (caster->query_ghost() ||
        caster->query_unconscious()) {
        dest_effect();
        return;
    }

    place = environment(caster);
    attackers = caster->query_attackers();

    if (sizeof(attackers)) {
        tell_object(caster, cm("The cold within aids you in combat."));
        for (i = 0; i < sizeof(attackers); i++) {
            if (!objectp(attackers[i])) {
                continue;
            }
            if (place != environment(attackers[i])) {
                continue;
            }
            if (attackers[i]->query_unconscious()) {
                continue;
            }
            negative_effects(attackers[i]);
        }
    }

    allies = ob_party(caster) + (caster->query_followers() - attackers) + ({ caster });
    allies = filter_array(allies, (: $1->query_property("negative energy affinity") :));
    allies = distinct_array(allies);

    for (i = 0; i < sizeof(allies); i++) {
        if (!objectp(allies[i])) {
            continue;
        }
        if (place != environment(allies[i])) {
            continue;
        }
        if (allies[i]->query_unconscious()) {
            continue;
        }
        positive_effects(allies[i]);
    }

    if (!sizeof(attackers) && !random(300)) {
        tell_object(caster, cm("The cold intensifies as energies within you beam."));
        tell_room(place, cm("Your very soul gets cold as the chill casts off the air."), caster);
    }

    if (objectp(place)) {
        place->addObjectToCombatCycle(TO, 1);
    }else {
        dest_effect();
    }
}

//The original version has buffs, we just heal
/**
 * Applies healing and other positive effects to allies
 */
void positive_effects(object obj)
{
    int damage;

    damage = roll_dice(clevel, 2);

    if (obj->query_hp() > (obj->query_max_hp() * 9 / 10)) {
        return;
    }

    if (userp(obj)) {
        tell_object(obj, cm("Fell energies emanating from " + caster->QCN + " repair your wounds."));
    }

    tell_room(place, cm(obj->QCN + "'s wounds seems to heal!"), obj);

    obj->cause_typed_damage(obj, obj->return_target_limb(), damage, "negative energy");

    return;
}

/**
 * Applies negative effects to enemies
 */
void negative_effects(object obj)
{
    int damage;

    if (!objectp(obj)) {
        return;
    }

    // damage, blind, fatigue, sickened
    switch (random(20)) {
    case 0..3:
        if (!obj->will_save(clevel) && !obj->query_property("no blind")) {
            tell_object(obj, cm("You feel unnaturally cold as you vision becomes hazy and the world around you fades!"));
            tell_room(place, cm(obj->QCN + " blinks and stares around sightlessly."), obj);
            obj->set_temporary_blinded(clevel / 18 + 1);
        }
        break;

    case 4..15:
        damage = roll_dice(1, clevel) * 3 / 2;
        if (obj->fort_save(clevel)) {
            damage = damage / 2;
        }

        if (obj->query_property("negative energy affinity")) {
            tell_object(obj, cm("Energies emanating from " + caster->QCN + " wither your putrid flesh!"));
            obj->cause_typed_damage(obj, obj->return_target_limb(), damage, "positive energy");
        }else {
            tell_object(obj, cm("The cold ebbing from " + caster->QCN + " chills your very existence!"));
            obj->cause_typed_damage(obj, obj->return_target_limb(), damage, "negative energy");
        }
        tell_object(caster, cm("You sense lifeless currents you control harming " + obj->QCN + "!"));

        break;

    case 16..17:
        if (!obj->reflex_save(clevel)) {
            tell_object(obj, cm("You feel tired as the cold envelops you."));
            "/std/effect/status/fatigued"->apply_effect(obj, clevel / 25 + 1);
        }
        break;

    case 18..19:
        if (!obj->reflex_save(clevel)) {
            tell_object(obj, cm("You feel sickened as the cold reaches your internals."));
            "/std/effect/status/sickened"->apply_effect(obj, clevel / 25 + 1);
        }
        break;
    }
    return;
}

void dest_effect()
{
    if (objectp(caster)) {
        tell_object(caster, cm("Your lifeless shroud fades."));
        caster->remove_property_value("active_feats", ({ TO }));
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}
