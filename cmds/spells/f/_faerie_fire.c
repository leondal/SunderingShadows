// faerie fire
#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;

int bonus;

void create() {
    ::create();
    set_author("ares");
    set_spell_name("faerie fire");
    set_spell_level(([ "druid" : 1,"oracle":1 ]));
    set_spell_sphere("combat");
    set_mystery(({"whimsy","solar"}));
    set_syntax("cast CLASS faerie fire on TARGET");
    set_description("This spell will outline the target in harmless violet flames.  It makes the target easier to hit "
"with melee combat, and also makes it impossible for the target to hide by magical or other means until the spell expires "
"or is dispelled.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_heart_beat(1);
}

void heart_beat()
{
    if(!objectp(target)) { dest_effect(); return; }
    if(!objectp(caster)) { return; }
    if(target->query_invis()) {
        if((string)TO->query_spell_type() == "potion") tell_object(target,"%^YELLOW%^Your glowing skin gives you away!%^RESET%^");
        else tell_object(target,"%^BOLD%^%^MAGENTA%^The faerie fire gives away your position!%^RESET%^");
        target->set_invis(0);
        return;
    }
    return;
}

string query_cast_string()
{
    tell_object(caster,"%^BOLD%^%^MAGENTA%^Twinkling motes of light gather"+
		" in your hands as you sing your prayer.");
    tell_room(place,"%^BOLD%^%^MAGENTA%^Twinkling motes of light gather"+
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

void spell_effect(int prof) {
    int duration;
// SC/MC separation removed; no point on 3e system as it will simply scale with class levels.
    duration = (ROUND_LENGTH * 3/2) * clevel;
    bonus = clevel/10;

    if(!present(target,place)) {
        tell_object(caster,"Your target has left the area.");
        if(objectp(TO)) TO->remove();
        return;
    }
    if((string)TO->query_spell_type() == "potion") {
      if((int)target->query_property("faerie fire")) {
        tell_object(caster,"Your skin's glow intensifies momentarily.");
        if(objectp(TO)) TO->remove();
        return;
      }
      tell_object(target,"%^MAGENTA%^Instead of fading away, your skin starts to sparkle with light!");
      tell_room(place,"%^MAGENTA%^"+target->QCN+"'s skin starts to sparkle with light!",target);
    }
    else {
      tell_object(caster,"%^MAGENTA%^You gesture towards "+target->QCN+""+
                " engulfing "+target->QO+" with the twinkling motes!");
      tell_object(target,"%^MAGENTA%^With a simple gesture towards you, "+caster->QCN+" " +
        	"engulfs you in twinkling motes of light!");
      tell_room(place,"%^MAGENTA%^With a simple gesture "+caster->QCN+" "+
		"engulfs "+target->QCN+" in twinkling motes of light!",({target,caster}));
    }
    spell_successful();
    target->add_ac_bonus(-1*bonus);
    target->set_property("faerie fire",1);
    target->set_property("spelled",({TO}));
    target->set_property("added short",({"%^MAGENTA%^ (glowing)%^RESET%^"}));
    addSpellToCaster();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);

}

void dest_effect(){
    if(objectp(target)) {
	    tell_room(place,"%^BOLD%^%^MAGENTA%^The twinkling motes of light "+
		    "around "+target->QCN+" fade away.");
	    tell_object(target,"%^MAGENTA%^%^BOLD%^The twinkling motes of "+
		    "light around you fade away.");
	    target->remove_property("faerie fire");
	    target->remove_property_value("added short",({"%^MAGENTA%^ (glowing)%^RESET%^"}));
        target->add_ac_bonus(bonus);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
