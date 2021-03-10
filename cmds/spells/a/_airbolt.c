// Airbolt
//Cleaned up a bit and brought into balance with other 5th level
//bolt spells by ~Circe~ 4/24/08 during the rebalancing of domains
#include <std.h>
#include <daemons.h>
#include <magic.h>


inherit SPELL;


void create()
{
    ::create();
    set_spell_name("airbolt");
    set_spell_level(([ "cleric" : 5 ]));
    set_spell_sphere("invocation_evocation");
    set_domains("air");
    set_syntax("cast CLASS airbolt on TARGET");
    set_damage_desc("bludgeoning");
    set_description("This spell enables a priest to concentrate the air around him into a powerful gust of wind. The "
        "priest chooses the target of the spell, and there is a chance that the target is knocked off balance and will drop what "
        "he or she is holding.  In addition, the gale force winds may hit others who are standing near the target.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("reflex");
    splash_spell(1);
}


int preSpell()
{
    if(!objectp(target))
    {
        tell_object(caster,"That spell requires a target.");
        return 0;
    }
    return 1;
}


string query_cast_string()
{
    tell_object(caster,"%^BOLD%^%^BLUE%^Blowing on your hands, you call forth a howling gale behind you.%^RESET%^");
    tell_room(place,"%^BOLD%^%^BLUE%^Blowing on "+caster->QP+" hands, "+caster->QCN+" calls forth a howling gale behind "+caster->QO+".%^RESET%^",caster);
    return "display";
}


void spell_effect(int prof)
{
    int dam,i;
    string *ids;
    object *weapons,*attackers;

    if(!present(target,place))
    {
        tell_object(caster,"Your target has left the area.");
        dest_effect();
        return;
    }

    dam = sdamage;


   tell_object(caster,"%^BOLD%^%^BLUE%^You point your finger at "+target->QCN+", unleashing the gale.%^RESET%^");

    attackers = target_selector();
    attackers += ({ target });

    attackers = distinct_array(attackers);

    if(sizeof(attackers))
    {
        for(i=0;i<sizeof(attackers);i++)
        {
            if(!objectp(attackers[i])) { continue; }

            if(attackers[i] == target)
            {
                tell_object(target,"%^BOLD%^%^BLUE%^The gale conjured "+
                    "by "+caster->QCN+" tears into you!%^RESET%^");
                tell_room(environment(target),"%^BOLD%^%^BLUE%^"+
                    ""+target->QCN+" is knocked backwards with the "+
                    "gale force wind.%^RESET%^",target);

                spell_kill(attackers[i],caster);

                if(!do_save(target))
                {
                    if(!random(2))
                    {
                        weapons = target->query_wielded();
                        if(sizeof(weapons) && !target->query_property("no disarm"))
                        {
                            tell_object(target,"%^BOLD%^%^BLUE%^The "+
                                "blast of air hits you so hard that "+
                                "you fall to the ground!%^RESET%^");
                            tell_room(environment(target),"%^BOLD%^%^BLUE%^"+
                                "The gale force blast makes "+target->QCN+" "+
                                "drop to the ground!%^RESET%^",target);
                            for (i=0;i<sizeof(weapons);i++)
                            {
                                ids = weapons[i]->query_id();
                                target->force_me("unwield "+ids[0]+"");
                                target->remove_property("disarm time");
                                target->set_property("disarm time",time()+(ROUND_LENGTH*roll_dice(1,4)));
                            }
                        }
                        target->set_tripped(random(2)+1,"%^BOLD%^"+
                            "%^BLUE%^You are knocked flat by the gale winds.");
                    }
                    if(objectp(attackers[i])) damage_targ(attackers[i],"torso",dam,"bludgeoning");
                }
                else
                {
                    tell_object(target,"%^BOLD%^%^BLUE%^You are able to "+
                        "retain your footing amidst the gale blast.%^RESET%^");
                    tell_room(environment(target),"%^BOLD%^%^BLUE%^"+
                        ""+target->QCN+" is able to retrain "+
                        ""+target->QP+" footing amidst the gale "+
                        "blast.%^RESET%^",target);
                    if(objectp(attackers[i])) damage_targ(attackers[i],"torso",dam/2,"bludgeoning");
                }
            }
            else
            {
                spell_kill(attackers[i],caster);
                if(!do_save(attackers[i]))
                {
                    tell_object(attackers[i],"%^BOLD%^%^CYAN%^The winds "+
                        "sheer into you as they pass by.%^RESET%^");
                    tell_room(environment(attackers[i]),"%^BOLD%^%^CYAN%^"+
                        ""+attackers[i]->QCN+" is sheered by the winds!%^RESET%^",attackers[i]);
                    damage_targ(attackers[i],"torso",dam,"bludgeoning");
                }
                else
                {
                    tell_object(attackers[i],"%^CYAN%^You avoid some of "+
                        "the gale force winds as they speed by.%^RESET%^");
                    tell_room(environment(attackers[i]),"%^CYAN%^Twisting, "+
                        ""+attackers[i]->QCN+" avoids the brunct of the "+
                        "winds.%^RESET%^");
                    damage_targ(attackers[i],"torso",dam/2,"bludgeoning");
                }
            }
        }
    }
    else
    {
       dest_effect();
    }
    spell_successful();
    return;
}


void dest_effect()
{
     ::dest_effect();
    if(objectp(TO)) TO->remove();
}
