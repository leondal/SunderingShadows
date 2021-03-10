#include <std.h>
#include <magic.h>
#include <party.h>
#include <daemons.h>

inherit SPELL;


void create()
{
    ::create();
    set_spell_name("mass repair undead");
    set_spell_level(([ "mage" : 5 ]));
    set_affixed_spell_level(2);
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS mass repair undead on TARGET");
    set_damage_desc("negative energy");
    set_description("This spell acts as repair undead spell but affects multiple targets. It should properly ideintify party members that can be healed with this spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_helpful_spell(1);
}


int preSpell()
{
    if(!objectp(target))
    {
        tell_object(caster,"You must specify a target for this spell.");
        return 0;
    }
    return 1;
}


string query_cast_string()
{
    tell_object(caster,"%^BOLD%^%^BLACK%^Your voice rings out as you begin to "+
        "chant a powerful spell, gathering divine energy into your hands.");
    tell_room(place,"%^BOLD%^%^BLACK%^"+caster->QCN+"'s voice rings out as they"+
        " begin to chant a powerful spell. Cupping "+caster->QP+" hands, "+
        ""+caster->QS+" starts to gather energy.",caster);
    return "display";
}


void spell_effect(int prof)
{
    int i;
    object *party_members = ({}),*attackers = ({}),*living = ({}),*targets = ({}), *followers = ({});

    set_helpful_spell(1);
    party_members = ob_party(caster);
    attackers = caster->query_attackers();
    followers = caster->query_followers();
    living = all_living(place);

    if(!objectp(target)) { target = caster; }

    if(target == caster ||
       member_array(target,party_members) != -1 ||
       member_array(target,followers) != -1)
    {
        targets = filter_array(distinct_array(party_members+(followers-attackers))+({caster}),
                               (:!!$1->query_property("negative energy affinity"):));
    }
    else
    {
        targets = ({target});
    }

    targets = distinct_array(targets);

    tell_room(place,"%^BOLD%^%^BLACK%^"+caster->QCN+" opens "+
        ""+caster->QP+" hands, releasing a fell wave of"+
        " energy as "+caster->QS+" shouts out the final words "+
        "of the prayer.",caster);

    if(sizeof(targets))
    {
        int healamnt = calculate_healing();
        for(i=0;i<sizeof(targets);i++)
        {
            if(!objectp(targets[i]))
                continue;
            if(!present(targets[i], place))
                continue;
            if(!target->query_property("negative energy affinity"))
                continue;

            if(targets[i] == caster)
            {
                tell_object(targets[i],"%^BOLD%^%^BLACK%^A fell "+
                    "wave moves through you, carrying with it the essence of death.");
            }
            else
            {
                tell_room(place,"%^BOLD%^%^BLACK%^A fell wave moves through"+
                    " "+targets[i]->QCN+" carrying with it the essence of "+
                    "death, as "+caster->QCN+" voice rings out.",({ targets[i],caster }));
                tell_object(caster,"%^BOLD%^%^BLACK%^A fell "+
                    "wave moves through "+targets[i]->QCN+", carrying with it the essence of death.");
                tell_object(targets[i],"%^BOLD%^%^BLACK%^A fell "+
                    "wave moves through you, carrying with it the essence of death.");
            }
            set_helpful_spell(1);
            damage_targ(targets[i], targets[i]->return_target_limb(), healamnt, "negative energy");
        }
    }

    spell_successful();
    dest_effect();
    return;
}

int calculate_healing(object targ)
{
    return sdamage;
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
