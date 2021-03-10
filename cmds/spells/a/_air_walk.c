#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
inherit SPELL;


string message_out,message_in;


void create()
{
    ::create();
    set_author("ares");
    set_spell_name("air walk");
    set_spell_level(([ "druid" : 4, "cleric":4, "ranger" : 2, "oracle" : 4 ]));
    set_mystery("wind");
    set_domains("air");
    set_spell_sphere("alteration");
    set_syntax("cast CLASS air walk on TARGET");
    set_description("This spell will allow the target to walk on the air as if it were perfectly level ground.  "
        "This makes traveling over long distances almost effortless.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
	set_helpful_spell(1);
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
        tell_object(caster,"Your target is already walking on air!");
        return 0;
    }
    return 1;
}


string query_cast_string()
{
    tell_object(caster,"%^BOLD%^%^CYAN%^You feel the wind flow all around you as you call on the elements.");
    tell_room(place,"%^BOLD%^%^CYAN%^The wind begins to pick up all around "+caster->QCN+".",caster);
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
        tell_object(target, "%^BOLD%^%^BLUE%^You feel the wind grow firm enough to support your weight and you take a few tentative steps up into the air.");
        tell_room(place,"%^BOLD%^%^BLUE%^"+target->QCN+" takes a few tentative steps up into the air as if "+target->QS+" were walking up stairs!",target);
    }
    else
    {
        tell_object(caster,"%^BOLD%^%^BLUE%^As you finish calling on the wind, "+target->QCN+" takes a few tentative steps into the air as if "+target->QS+" were walking up stairs.");
        tell_object(target,"%^BOLD%^%^BLUE%^When "+caster->QCN+" finishes calling to the wind, you feel the air lift you slightly from the ground and you take a few tentative steps up!");
        tell_room(place,"%^BOLD%^%^BLUE%^"+target->QCN+" takes a few tentative steps up into the air as if "+target->QS+" were walking up stairs.",({caster,target}));
    }

    target->set_property("flying",1);
    target->set_property("spelled", ({TO}) );
    target->set_property("endurance",(clevel/10));
    message_in  = target->query_message_in();
    message_out = target->query_message_out();
    target->set_property("MIN", "$N walks in on a cushion of air");
    target->set_property("MOUT", "$N walks $D on a cushion of air");
    target->set_property("added short",({"%^BOLD%^%^CYAN%^ (Walking on Air)%^RESET%^"}));
    addSpellToCaster();
    spell_successful();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect()
{
    if(objectp(target))
    {
        tell_object(target,"%^BOLD%^%^CYAN%^The strength of the air supporting you begins to lessen and you are slowly lowered back to the ground.");
        tell_room(environment(target),"%^BOLD%^%^CYAN%^The strength of the air supporting "+target->QCN+" begins to lessen and "+target->QS+" lowers slowly back to the ground.",target);
        target->set_property("flying", -1);
        target->set_property("endurance",(-1*(clevel/10)));
        //if(message_in) { target->force_me("message "+message_in); }
        //else { target->force_me("message in enters"); }
        //if(message_out) { target->force_me("message "+message_out); }
        //else { target->force_me("message out leaves"); }
        target->remove_property("MIN");
        target->remove_property("MOUT");
	    target->remove_property_value("added short",({"%^BOLD%^%^CYAN%^ (Walking on Air)%^RESET%^"}));
    }
     ::dest_effect();
    if(objectp(TO)) TO->remove();
}
