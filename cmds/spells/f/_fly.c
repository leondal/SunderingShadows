// moved from "fly" to "levitate" to avoid confusion & lower level casting. N, 4/14.
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
inherit SPELL;

string message_out,message_in;

void create() {
    ::create();
    set_author("ares");
    set_spell_name("fly");
    set_spell_level(([ "classless" : 3]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS fly on TARGET");
    set_description("This spell is used by mobiles only. See new spell: levitate.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
	set_helpful_spell(1);
}

int preSpell()
{
    if(spell_type == "monk") target = caster;
    if(!objectp(target))
    {
        tell_object(caster,"This spell requires a target.");
        return 0;
    }
	if(target->query_in_vehicle()) {
		tell_object(caster,"You can't cast this on a mounted target.");
		return 0;
	}
    if((int)target->query_property("flying"))
    {
        tell_object(caster,"Your target is already levitating!");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
     tell_object(caster,"%^BOLD%^%^BLUE%^%^You hair begins to stir around"+
        " in a light breeze.");
    tell_room(place,"%^BOLD%^%^BLUE%^"+caster->QCN+"'s hair begins to "+
        "stir around in a light breeze as "+caster->QS+" draws upon a spell.",caster);
//fixed by Circe 12/1/07 - used to end at "+caster->QS+" :)
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
            "as "+caster->QCN+" gives "+target->QO+" the power to levitate.",({caster,target}));
        tell_object(caster,"%^BOLD%^%^BLUE%^As you finish your spell, "+target->QCN+" begins "
            "to levitate!");
        tell_object(target,"%^BOLD%^%^BLUE%^As "+caster->QCN+" finishes "+caster->QP+" spell, you "
            "can feel yourself floating up into the air!");
    }
    target->set_property("flying",1);
    target->set_property("spelled", ({TO}) );
    target->set_property("endurance",(clevel/10));
    message_in  = target->query_message_in();
    message_out = target->query_message_out();
    target->set_property("MIN","$N floats in.");
    target->set_property("MOUT","$N drifts to the $D.");
    target->set_property("added short",({"%^BOLD%^%^BLUE%^ (levitating)%^RESET%^"}));
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
        tell_object(target,"%^BOLD%^%^BLUE%^The magic fades from you and you rapidly"+
		    " descend back to the ground!");
        tell_room(environment(target),"%^BOLD%^%^BLUE%^As the magic fades from"+
		    " "+target->QCN+", "+target->QS+" rapidly descends back to the ground!", target);
        target->set_property("flying", -1);
        target->set_property("endurance",(-1*(clevel/10)));
        //if(message_in) { target->force_me("message "+message_in); }
        //else { target->force_me("message in enters"); }
        //if(message_out) { target->force_me("message "+message_out); }
        //else { target->force_me("message out leaves"); }
        target->remove_property("MIN");
        target->remove_property("MOUT");
            target->remove_property_value("added short",({"%^BOLD%^%^BLUE%^ (levitating)%^RESET%^"}));
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
