//modified for multiclass by ~Circe~ 9/27/05 after observations
//by testers that the extra attacks were too powerful for 
//multiclass psions
//prescience
//~Circe~ 7/25/05

#include <spell.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;

int mybonus;


void create() 
{
    ::create();
    set_spell_name("prescience");
    set_spell_level(([ "psion" : 7 ]));
    set_spell_sphere("combat");
    set_bonus_type("insight");
    set_syntax("cast CLASS prescience");
    set_description("This power will allow the psion foreknowledge, granting him additional prowess in battle.  The power "
        "gives the psion a bonus to hit and damage his opponents for a time, as well as a chance for an extra attack. "
        "This power grants +1/per 5 levels. It grants +4 minimum and +8 maximum. This bonus applies "
        "to both attack and damage rolls.");
    set_verbal_comp();
    set_property("keywords", ({ "targeted", "personal" }));
    set_helpful_spell(1);
}


string query_cast_string() { return "%^RED%^"+caster->QCN+" closes "+caster->QP+" eyes and clinches "+caster->QP+" fists!"; }


int preSpell() 
{
    if (caster->query_property("prescienced"))
    {
        tell_object(caster,"You are already under the effects "+
           "of a prescience or haste power.");
        return 0;
    }
    return 1;
}


void spell_effect(int prof)
{
    target = caster;
    tell_room(place,"%^ORANGE%^"+caster->QCN+"'s muscles tense "+
        "in anticipation!",target);
    tell_object(target, "%^ORANGE%^You seem to see complex formulae and "+
        "equations in the air around you, giving you foresight in battle!");

    mybonus = clevel - BONUS_D->new_bab(caster->query_base_level(), caster);

    //Without improved, gets you to 3/4 BAB, otherwise full
    if(!FEATS_D->usable_feat(caster,"improved prescience"))
        mybonus /= 2;
    
    if(mybonus < 2)
        mybonus = 2;

    target->add_attack_bonus(mybonus);
    target->add_damage_bonus(mybonus);
    
    target->set_property("prescienced",1);
    target->set_property("spelled", ({TO}) );
    addSpellToCaster();
    spell_successful();
    call_out("do_extra",ROUND_LENGTH);
}


void do_extra() 
{
    int i,extra,chance;
    
    if(!objectp(target))
    {
        dest_effect();
        return;
    }
    
    if(sizeof(target->query_attackers()))
    {
        extra = mybonus / 3;
        if(!extra) { extra = 1; }
        
        chance = mybonus * 6;
        
        for(i=0;i<extra;i++)
        {
            if(chance > roll_dice(1,100) && !target->query_paralyzed())
            {
                tell_object(target,"%^BOLD%^%^RED%^You see an opening and strike!");
                target->execute_attack();
                chance = chance / 2; // chance for next attack is halved each time
            }
        }
    }
    
    call_out("do_extra",ROUND_LENGTH);
}


void dest_effect() 
{
    if(objectp(target)) 
    {
        tell_object(target,"%^RED%^The equations jumble together and "+
            "fade away.");
        tell_room(environment(target),"%^RED%^"+target->QCN+" "+
            "looks perplexed and then relaxes.",target);
        target->add_attack_bonus(-1*mybonus);
        target->add_damage_bonus(-1*mybonus);
        target->remove_property("prescienced");
        target->remove_property_value("spelled", ({TO}) );
        remove_call_out("do_extra");
    }
    
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

