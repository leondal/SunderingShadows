// stone body
#include <std.h>
#include <priest.h>

inherit SPELL;

string message_out,message_in;

void create() 
{
    ::create();
    set_author("ares");
    set_spell_name("fly");
    set_spell_type("priest");
    set_spell_level(3);
    set_spell_sphere("combat");
    set_spell_domain("travel");
    set_target_required(1);
    set_verbal_comp();
}

int preSpell() 
{
    if(!objectp(target))
    {
        tell_object(caster,"This spell requires a target.");
        return 0;
    }
	if(target->query_in_vehicle())
	{
		tell_object(caster,"You can't cast this on a mounted target.");
		return 0;
	}
    if((int)target->query_property("flying")) 
    {
        tell_object(caster,"Your target is already flying!");
        return 0;
    }
    return 1;
}

string query_cast_string() 
{
     tell_object(caster,"%^BOLD%^%^BLUE%^%^You hair begins to stir around"+
        " in a light breeze as you begin to chant.");
    tell_room(place,"%^BOLD%^%^BLUE%^"+caster->QCN+"'s hair begins to "+
        "stir around in a light breeze as "+caster->QS+" begins "
        "to cast.",caster);
    return "display";
}

void spell_effect(int prof) 
{
    int duration;
    duration = (ROUND_LENGTH * 10) * clevel;
    if(!present(target,place))
    {
        tell_object(caster,"Your target has left the area.");
        dest_effect();
        return;
    }
	if(target == caster)
    {
        tell_room(place,"%^BOLD%^%^CYAN%^Rising up off the ground,"+
		    " "+caster->QCN+" floats into the air.",target);
        tell_object(target, "%^BOLD%^%^CYAN%^Rising up off the ground,"+
		    " you float into the air.");
    }
    else
    {
        tell_room(place,"%^BOLD%^%^BLUE%^"+target->QCN+" begins to float up into the air "
            "as "+caster->QCN+" gives "+target->QO+" the power to fly.",({caster,target}));
        tell_object(caster,"%^BOLD%^%^BLUE%^As you finish your prayer, "+target->QCN+" begins "
            "to fly!");
        tell_object(target,"%^BOLD%^%^BLUE%^As "+caster->QCN+" finishes "+caster->QP+" spell, you "
            "can feel yourself floating up into the air!");
    }
    target->set_property("flying",1);
    target->set_property("spelled", ({TO}) );
    target->set_property("endurance",(clevel/10));
    message_in  = target->query_min(target);
    message_out = target->query_mout("$D",target);
    message_in  = replace_string(message_in,capitalize(target->query_true_name()),"",1);
    message_out = replace_string(message_out,capitalize(target->query_true_name()),"",1);
    target->setenv("MIN","$N flies in");
    target->setenv("MOUT","$N flies to the $D");
    target->set_property("added short",({"%^BOLD%^%^BLUE%^ (flying)"}));
    addSpellToCaster();
    spell_successful();
    call_out("dest_effect",duration);
}

void dest_effect()
{
    if(objectp(target))
    {
        tell_object(target,"%^BOLD%^%^BLUE%^The magic fades from you and you rapidly"+
		    " descend back to the ground!");
        tell_room(environment(target),"%^BOLD%^%^BLUE%^As the magic fades from"+
		    " "+target->QCN+", "+target->QS+" rapidly descends back to the ground!", target);
        target->remove_property("flying");
        target->set_property("endurance",(-1*(clevel/10)));
        target->setenv("MIN"," "+message_in+"");
        target->setenv("MOUT"," "+message_out+"");
	    target->remove_property_value("added short",({"%^BOLD%^%^BLUE%^ (flying)"}));
    }
    ::dest_effect();
    TO->remove();
}

int help() 
{
    write(
@HELP
Power  : Fly
Level  : 3rd Level
Domain : Travel
Syntax : chant fly on <target>

This spell will give the target the ability to fly.
The target will find traveling over long distances
to be very easy when under the influence of this spell, 
and will use very little stamina to travel.

HELP
);
    return 1;
}
