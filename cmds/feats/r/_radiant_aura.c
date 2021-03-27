#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit FEAT;


void create()
{
    ::create();
    feat_type("instant");
    feat_category("RadiantServant");
    feat_name("radiant aura");
    feat_syntax("radiant_aura");
    feat_prereq("Radiant Servant L4");
    feat_classes("base_class");
    feat_desc("The radiant aura feat projects an aura of healing positive energy around the caster, healing the caster and all of her allies. As the aura projects positive energy, it is dangerous to undead that have been summoned by members of the party. Unlike the aura of healing spell, radiant aura requires no spell slots to use and will remain active until the caster is killed or logs off.");
    set_target_required(0);
    set_required_for(({"supreme healer"}));
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

    if (ob->query_class_level("radiant_servant") < 4) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_radiant_aura(string str)
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

    if (FEATS_D->is_active(caster, "radiant aura")) {
        obj = query_active_feat("radiant aura");
        obj->dest_effect();
        caster = 0;
        dest_effect();
        return;
    }
    ::execute_feat();

    tell_object(caster,"%^RESET%^%^BOLD%^%^BLUE%^You close your eyes and open your mind, channeling energy directly from "+capitalize(caster->query_diety()));
    caster->set_property("active_feats",({TO}));

    return;
}


void execute_attack()
{
    object *party=({}),healed=({});
    string party_name;
    int i, damage;

    if(!objectp(caster) || caster->query_ghost())
    {
        dest_effect();
        return;
    }

    place = environment(caster);
    party = ob_party(caster,"all");
    party += caster->query_followers() - caster->query_attackers();
    party = distinct_array(party);

    if (!sizeof(party)) {
        party = ({ caster });
    }

    for (i = 0; i < sizeof(party); i++) {
        if (!objectp(caster) || caster->query_ghost()) {
            dest_effect();
            return;
        }
        if (caster->query_unconscious()) {
            continue;
        }
        if (!objectp(party[i])) {
            continue;
        }
        if (environment(party[i]) != environment(caster)) {
            continue;
        }
        if (party[i]->query_hp_percent() >= 100) {
            continue;
        }

        if (party[i]->query_property("negative energy affinity")) {
            continue;
        }

        damage = roll_dice(flevel, 4);

        party[i]->cause_typed_damage(party[i], party[i]->return_target_limb(), damage, "positive energy");
        if (party[i] != caster) {
            tell_object(party[i], "%^RESET%^%^BOLD%^%^BLUE%^A wave of %^RESET%^%^BOLD%^p%^CYAN%^o%^BLUE%^s%^RESET%^i%^BLUE%^t%^RESET%^%^BOLD%^i%^CYAN%^v%^YELLOW%^e "
                        "%^RESET%^%^BOLD%^%^BLUE%^energy %^CYAN%^radiates%^RESET%^%^BOLD%^%^BLUE%^ outwards from " + caster->QCN + " and bathes you "
                        "in %^YELLOW%^heal%^RESET%^i%^BOLD%^%^YELLOW%^ng %^RESET%^%^BOLD%^%^BLUE%^energy.%^RESET%^", caster);
        }
    }

    /* if (sizeof(healed)) { */
    /*     tell_object(caster, "%^RESET%^%^BOLD%^%^BLUE%^A wave of %^RESET%^%^BOLD%^p%^CYAN%^o%^BLUE%^s%^RESET%^i%^BLUE%^t%^RESET%^%^BOLD%^i%^CYAN%^v%^YELLOW%^e " */
    /*                 "%^RESET%^%^BOLD%^%^BLUE%^energy %^CYAN%^radiates%^RESET%^%^BOLD%^%^BLUE%^ outwards from you and bathes your allies " */
    /*                 "in %^YELLOW%^heal%^RESET%^i%^BOLD%^%^YELLOW%^ng %^RESET%^%^BOLD%^%^BLUE%^energy.%^RESET%^"); */
    /* } */

    if (objectp(place)) {
        place->addObjectToCombatCycle(TO, 1);
    }else {
        dest_effect();
    }
    return;
}


void dest_effect()
{
    if(objectp(caster))
    {
        tell_object(caster,"%^B_BLUE%^Your radiant aura deactivates.");
        caster->remove_property_value("active_feats",({TO}));
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}
