#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit FEAT;

object *exclude = ({});

void create()
{
    ::create();
    feat_type("instant");
    feat_category("RadiantServant");
    feat_name("contingent healing");
    feat_syntax("contingent_healing");
    feat_prereq("Radiant Servant L1");
    feat_classes("base_class");
    feat_desc("The Contingent Healing feat will allow the user to automatically cast a heal spell on whichever party member is hurt the most if they are sufficiently injured. This healing happens in addition to any other actions that the user takes in the round, including casting another spell or using a feat or attacking.");
    set_target_required(0);
    set_required_for(({"radiant aura","supreme healer"}));
}


int allow_shifted() { return 1; }


int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if(ob->query_class_level("radiant_servant") < 1)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}


int cmd_contingent_healing(string str)
{
    object feat;
    if(!objectp(TP)) { return 0; }
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}


void execute_feat()
{
    object obj;

    if(FEATS_D->is_active(caster,"contingent healing"))
    {
        obj = query_active_feat("contingent healing");
        obj->dest_effect();
        caster = 0;
        dest_effect();
        return;
    }
    ::execute_feat();

    tell_object(caster,"%^RESET%^%^BOLD%^%^CYAN%^You take a deep breath and focus, preparing to heal any ally who is "
        "badly hurt.%^RESET%^");

    caster->set_property("active_feats",({TO}));

    return;
}


void execute_attack()
{
    object *party=({}), targ;
    int i, percent,casting;

    if(!objectp(caster) || caster->query_ghost())
    {
        dest_effect();
        return;
    }

    party = ob_party(caster);
    place = environment(caster);

    if(!sizeof(party)) { party = ({ caster }); }

    for (i = 0; i < sizeof(party); i++) {
        if (!objectp(caster) || caster->query_ghost()) {
            dest_effect();
            return;
        }
        if (caster->query_unconscious() || caster->query_paralyzed() || (caster->query_blind() && !FEATS_D->usable_feat(caster, "blindfight"))) {
            continue;
        }
        if (!objectp(party[i])) {
            continue;
        }
        if (party[i]->query_property("negative energy affinity")) {
            continue;
        }
        if (environment(party[i]) != environment(caster)) {
            continue;
        }
        if (party[i]->query_hp_percent() > 60) {
            continue;
        }
        if (percent && party[i]->query_hp_percent() > percent) {
            continue;
        }
        percent = party[i]->query_hp_percent();
        targ = party[i];
    }

    if(objectp(targ))
    {
        casting = caster->query_casting();
        caster->set_casting(0);
        new("/cmds/spells/h/_heal.c")->use_spell(caster, targ, flevel, 100, "cleric");
        caster->set_casting(casting);
    }

    if(objectp(place)) { place->addObjectToCombatCycle(TO,1); }
    else { dest_effect(); }
    return;
}


void dest_effect()
{
    if(objectp(caster))
    {
        tell_object(caster,"%^B_RED%^You release your focus, your contingent healing deactivates.");
        caster->remove_property_value("active_feats",({TO}));
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}
