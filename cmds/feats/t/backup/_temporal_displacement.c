#include <std.h>
#include <daemons.h>

inherit FEAT;

object* allies = ({}), * enemies = ({});


void create()
{
    ::create();
    feat_type("instant");
    feat_category("Chronicler");
    feat_name("temporal displacement");
    feat_prereq("Chronicler L7");
    feat_syntax("temporal_displacement");
    feat_desc("The temporal displacement feat allows the chronicler to project an aura of manipulated time about herself. The time bubble will speed up any allies who enter it as well as slow down any enemies. The bubble covers a limited distance near the chronicler and the chronicler is able to direct it in a manner such that the negative effects will only hamper her enemies.");
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

    if ((int)ob->query_class_level("chronicler") < 7) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_temporal_displacement(string str)
{
    object feat;
    if (!objectp(TP)) {
        return 0;
    }
    feat = new(base_name(TO));
    feat->setup_feat(TP, str);
    return 1;
}

void execute_feat()
{
    object obj;

    if (!objectp(caster)) {
        dest_effect();
        return;
    }

    if (FEATS_D->is_active(caster, "temporal displacement")) {
        obj = query_active_feat("temporal displacement");
        obj->dest_effect();
        caster = 0;
        dest_effect();
        dest_effect();
        return;
    }

    ::execute_feat();
    tell_object(caster, "%^RESET%^%^BOLD%^You pull on the strands of fate, manipulating the flow of time.%^RESET%^");
    caster->set_property("active_feats", ({ TO }));
    return;
}

varargs void remove_effects(int ending)
{
    object myplace, * removing = ({});
    int i;

    if (!objectp(caster)) {
        place = 0;
    }

    for (i = 0; sizeof(enemies), i < sizeof(enemies); i++) {
        if (!objectp(enemies[i])) {
            continue;
        }
        myplace = environment(enemies[i]);
        if (!objectp(caster) || !objectp(place) || !objectp(myplace) || (myplace != place) || ending) {
            enemies[i]->set_property("fighter_attacks_mod", 2);
            enemies[i]->add_attack_bonus(4);
            enemies[i]->add_ac_bonus(4);
            enemies[i]->add_saving_bonus("reflex", 2);
            enemies[i]->remove_property_value("added short", ({ "%^BOLD%^%^CYAN%^ (inside a wavering time bubble)%^RESET%^" }));
            tell_object(enemies[i], "%^MAGENTA%^You leave the area of distorted time and shudder as you regain your senses!%^RESET%^");
            removing += ({ enemies[i] });
        }
    }

    enemies -= removing;
    removing = ({});

    for (i = 0; sizeof(allies), i < sizeof(allies); i++) {
        if (!objectp(allies[i])) {
            continue;
        }
        myplace = environment(allies[i]);
        if (!objectp(caster) || !objectp(place) || !objectp(myplace) || (myplace != place) || ending) {
            allies[i]->set_property("fighter_attacks_mod", -2);
            allies[i]->add_attack_bonus(-4);
            allies[i]->add_ac_bonus(-4);
            allies[i]->add_saving_bonus("reflex", -2);
            allies[i]->remove_property_value("added short", ({ "%^BOLD%^%^CYAN%^ (inside a wavering time bubble)%^RESET%^" }));
            tell_object(allies[i], "%^MAGENTA%^You feel very sluggish after leaving the area of distorted time!%^RESET%^");
            removing += ({ allies[i] });
        }
    }

    allies -= removing;
}

void add_effects(object* party, object* attackers)
{
    object myplace;
    int i;

    place = environment(caster);

    for (i = 0; sizeof(party), i < sizeof(party); i++) {
        if (!objectp(party[i])) {
            continue;
        }
        if (member_array(party[i], allies) != -1) {
            continue;
        }
        myplace = environment(party[i]);
        if (myplace != place) {
            continue;
        }
        party[i]->set_property("fighter_attacks_mod", 2);
        party[i]->add_attack_bonus(4);
        party[i]->add_ac_bonus(4);
        party[i]->add_saving_bonus("reflex", 2);
        party[i]->set_property("added short", ({ "%^BOLD%^%^CYAN%^ (inside a wavering time bubble)%^RESET%^" }));
        tell_object(party[i], "%^RESET%^%^BOLD%^%^GREEN%^You enter a field of distorted time and feel the world around you slow down, "
                    "allowing you to move much faster!%^RESET%^");
        allies += ({ party[i] });
    }

    for (i = 0; sizeof(attackers), i < sizeof(attackers); i++) {
        if (!objectp(attackers[i])) {
            continue;
        }
        if (member_array(attackers[i], enemies) != -1) {
            continue;
        }
        myplace = environment(attackers[i]);
        if (myplace != place) {
            continue;
        }
        attackers[i]->set_property("fighter_attacks_mod", -2);
        attackers[i]->add_attack_bonus(-4);
        attackers[i]->add_ac_bonus(-4);
        attackers[i]->add_saving_bonus("reflex", -2);
        attackers[i]->set_property("added short", ({ "%^BOLD%^%^CYAN%^ (inside a wavering time bubble)%^RESET%^" }));
        tell_object(attackers[i], "%^RESET%^%^BOLD%^%^RED%^You step into a field of distorted time and suddenly feel very sluggish!%^RESET%^");
        enemies += ({ attackers[i] });
    }
}

void execute_attack()
{
    object* party = ({}), * attackers = ({});
    int i;

    enemies -= ({ 0 });
    allies -= ({ 0 });

    remove_effects();

    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (caster->query_ghost() || caster->query_unconscious()) {
        dest_effect();
        return;
    }

    place = environment(caster);
    party = ob_party(caster);
    attackers = caster->query_attackers();
    add_effects(party, attackers);

    if (!random(20)) {
        tell_room(place, "%^RESET%^%^BOLD%^%^CYAN%^The bubble around " + caster->QCN + " tumbles and shimmers, tumbling and undulating and "
                  "distorting the world inside of it.%^RESET%^", enemies + allies);
    }

    if (objectp(place)) {
        place->addObjectToCombatCycle(TO, 1);
    }else {
        dest_effect();
    }
}

void dest_effect()
{
    remove_effects(1);
    if (objectp(caster)) {
        tell_object(caster, "%^B_BLUE%^Your control over time dissipates.");
        caster->remove_property_value("active_feats", ({ TO }));
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}
