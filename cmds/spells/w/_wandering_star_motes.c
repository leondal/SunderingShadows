#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit SPELL;

int bonus;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("wandering star motes");
    set_spell_level(([ "bard" : 4 ]));
    set_spell_sphere("illusion");
    set_syntax("cast CLASS wandering star motes on TARGET");
    set_description("This spell creates a swarm of sparkling motes of light, that shoot towards the target and swirl around "
"it in a complex pattern.  It makes the target easier to hit with melee combat, and also makes it impossible for the target "
"to hide by magical or other means until the spell expires or is dispelled.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_heart_beat(1);
}

void heart_beat()
{
    if(!objectp(target)) { dest_effect(); return; }
    if(!objectp(caster)) { return; }
    if(target->query_invis())
    {
        tell_object(target,"%^BOLD%^%^WHITE%^The brilliant motes of light give away your position!");
        target->set_invis(0);
        return;
    }
    return;
}

string query_cast_string()
{
    tell_object(caster,"%^YELLOW%^Sparkling motes of light gather"+
		" in your hands as you lift your voice in song.");
    tell_room(place,"%^YELLOW%^Sparkling motes of light gather"+
		" in "+caster->QCN+"'s hands as "+caster->QS+" chants in a"+
		" singsong voice.",caster);
    return "display";
}

int preSpell()
{
    if(!objectp(target))
    {
        tell_object(caster,"You need a target for this spell.");
        return 0;
    }
    if((int)target->query_property("faerie fire"))
    {
        tell_object(caster,"%^MAGENTA%^The target is already outlined in light!");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    int duration;
    if(sizeof(caster->query_classes()) == 1)
    {
        duration = (ROUND_LENGTH * 10) * clevel;
        bonus = clevel/5;
    }
    else
    {
        duration = (ROUND_LENGTH * 5) * clevel;
        bonus = clevel/10;
    }

    if(!present(target,place))
    {
        tell_object(caster,"Your target has left the area.");
        dest_effect();
        return;
    }
    tell_object(caster,"%^BOLD%^%^WHITE%^You gesture towards "+target->QCN+""+
                " engulfing "+target->QO+" in a swarm of bright, swirling motes!%^RESET%^");
    tell_object(target,"%^BOLD%^%^WHITE%^With a simple gesture towards you, "+caster->QCN+""
                " engulfs you in a swarm of bright, swirling motes!%^RESET%^");
    tell_room(place,"%^BOLD%^%^WHITE%^With a simple gesture "+caster->QCN+" "+
		"engulfs "+target->QCN+" in a swarm of bright, swirling motes!%^RESET%^",({target,caster}));
     spell_successful();
    target->add_ac_bonus(-1*bonus);
    target->set_property("faerie fire",1);
    target->set_property("spelled",({TO}));
    target->set_property("added short",({"%^BOLD%^%^WHITE%^ (glowing)%^RESET%^"}));
    addSpellToCaster();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",duration);

}

void dest_effect()
{
    if(objectp(target))
    {
	    tell_room(place,"%^YELLOW%^The gleaming motes of light "+
		    "around "+target->QCN+" fade away.");
	    tell_object(target,"%^YELLOW%^The gleaming motes of "+
		    "light around you fade away.");
	    target->remove_property("faerie fire");
	    target->remove_property_value("added short",({"%^BOLD%^%^WHITE%^ (glowing)%^RESET%^"}));
        target->add_ac_bonus(bonus);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
