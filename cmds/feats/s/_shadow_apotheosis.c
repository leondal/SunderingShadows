#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

object* exclude = ({});

void create()
{
    ::create();
    feat_type("instant");
    feat_category("ShadowAdept");
    feat_name("shadow apotheosis");
    feat_prereq("Shadow adept L7");
    feat_syntax("shadow_apotheosis");
    feat_desc("A shadow adept with shadow apotheosis is able to project an aura of shadows about himself that will lash out at nearby enemies. The shadows will sometimes inflict damage on his enemies and sometimes harm them in other ways.");
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

    if ((int)ob->query_class_level("shadow_adept") < 7) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_shadow_apotheosis(string str)
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
    return CRAYON_D->color_string(str, "very black");
}

void execute_feat()
{
    string YOU, YOUS;
    object obj;

    if (!objectp(caster)) {
        dest_effect();
        return;
    }

    if (FEATS_D->is_active(caster, "shadow apotheosis")) {
        obj = query_active_feat("shadow apotheosis");
        tell_object(caster, cm("You release your connection to the shadows around you and they slither away into the world."));
        tell_room(place, cm("" + caster->QCN + " releases " + caster->QP + " connection to the shadows around " + caster->QO + " and the shadows slither out into the world!"), caster);
        caster = 0;
        obj->dest_effect();
        dest_effect();
        return;
    }

    tell_object(caster, cm("You focus on the darkness inside your soul, letting it seep into your very pores"));
    tell_object(caster, cm("You feel a torrent of shadows roll outwards from your body, blanketing the area in darkness."));
    tell_object(caster, cm("A vortex of smoky blackness spins slowly around you."));

    tell_room(place, cm("" + caster->QCN + "'s eyes glass over and " + caster->QS + " stares blankly at nothing."), caster);
    tell_room(place, cm("A torrent of shadows roll outwards from " + caster->QCN + "'s body, blanketing the area in darkness!"), caster);
    tell_room(place, cm("A vortex of smoky blackness spins slowly around " + caster->QCN + "."), caster);

    caster->remove_property_value("added short", ({ "%^RESET%^%^BOLD%^%^BLACK%^ (surrounded by a vortex of shadows)%^RESET%^" }));
    caster->set_property("added short", ({ "%^RESET%^%^BOLD%^%^BLACK%^ (surrounded by a vortex of shadows)%^RESET%^" }));

    caster->set_property("active_feats", ({ TO }));

    ::execute_feat();
    return;
}

void execute_attack()
{
    object* attackers = ({});
    int i;

    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (caster->query_ghost() || caster->query_unconscious()) {
        dest_effect();
        return;
    }

    place = environment(caster);
    attackers = caster->query_attackers();

    if (sizeof(attackers)) {
        tell_object(caster, cm("A shadowy tendril lashes out at your enemies from vortex of shadows !"));
        tell_room(place, cm("A shadowy tendril lashes out from " + caster->QCN + "'s vortex of shadows and lashes out!"), ({ caster }));
    }

    for (i = 0; sizeof(attackers), i < sizeof(attackers); i++) {
        if (!objectp(attackers[i])) {
            continue;
        }
        if (place != environment(attackers[i])) {
            continue;
        }
        if (attackers[i]->query_unconscious()) {
            continue;
        }

        shadow_effects(attackers[i]);
    }

    if (!sizeof(attackers) && !random(100)) {
        tell_object(caster, cm("The shadow vortex stirs with eagerness!"));
        tell_room(place, cm("You can see twisted humanoid shapes clawing at the vortex surrounding ") + caster->QCN + cm(", as "
                                                                                                                         "if they were trying to escape into the world!"), caster);
    }

    if (objectp(place)) {
        place->addObjectToCombatCycle(TO, 1);
    }else {
        dest_effect();
    }
}

void shadow_effects(object obj)
{
    int damage;

    if (!objectp(obj)) {
        return;
    }

    // damage, stun, trip, blind
    switch (random(15)) {
    case 0: // trip

        tell_object(obj, cm("A shadowy tendril lashes out from " + caster->QCN + "'s vortex of shadows and tries to grasp you!"));
        if (!obj->reflex_save(clevel) && !obj->query_property("no trip")) {
            tell_object(obj, cm("The shadowy tendril wraps around your ankle and pulls you from your feet!"));
        }else {
            tell_object(obj, cm("You managed to sidestep the grasping tendril!"));
        }
        break;

    case 1..3: // stun

        tell_object(obj, cm("A streak of darkness flies from " + caster->QCN + "'s shadow vortex and flies towards your head!"));
        if (!obj->reflex_save(clevel) && !obj->query_property("no stun")) {
            tell_object(obj, cm("You try to dodge but to no avail, the streak of darkness hits you in the head, staggering you with intense pain!"));
            obj->set_paralyzed(roll_dice(1, 4) * 4, cm("You are trying to recover your senses!"));
        }else {
            tell_object(obj, cm("You duck to the side, avoiding the streak of darkness at the last instant."));
        }
        break;

    case 4..7: // blind

        tell_object(obj, cm("An inky black shadow flies towards you, threatening to envelop you!"));
        if (!obj->will_save(clevel) && !obj->query_property("no blind")) {
            tell_object(obj, cm("The shadowy figure wraps about you like a dense blanket of smoke, making it impossible to see!"));
            obj->set_temporary_blinded(clevel / 20 + 1);
        }else {
            tell_object(obj, cm("The shadowy figure tries to wrap around you but you shrug it off!"));
        }
        break;

    case 8..14: //damage

        damage = roll_dice(clevel, 4);
        if (obj->fort_save(clevel)) {
            damage = damage / 2;
        }

        tell_object(obj, cm("A bolt of black lightning strikes out from the vortex surrounding " + caster->QCN + " striking you painfully!"));
        obj->cause_typed_damage(obj, obj->return_target_limb(), damage, "untyped");
        caster->add_hp(damage / 5);
        break;
    }
    return;
}

void dest_effect()
{
    if (objectp(caster)) {
        tell_object(caster, "%^B_BLUE%^Your vortex of shadows dissipates.");
        caster->remove_property_value("added short", ({ "%^RESET%^%^BOLD%^%^BLACK%^ (surrounded by a vortex of shadows)%^RESET%^" }));
        caster->remove_property_value("active_feats", ({ TO }));
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}
