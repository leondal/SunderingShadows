#include <std.h>
#include <clock.h>
#include <magic.h>

#define WTROB "/d/magic/obj/breathob.c"

inherit SPELL;
object breathob;

void create(){
    ::create();
    set_spell_name("water breathing");
    set_spell_level(([ "mage" : 3, "cleric" : 3, "oracle" : 3, "druid" : 3, "psywarrior" : 1, "psion" : 1, "magus" : 3 ]));
    set_mystery("waves");
    set_spell_sphere("alteration");
    set_syntax("cast CLASS water breathing on TARGET");
    set_description("This spell allows the target to breathe water for a limited period of time.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
	set_helpful_spell(1);
}

int preSpell(){
    if(present("underwtr_breath_ob", target)){
      tell_object(caster, target->QCN+" can already breathe water.");
      return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    if (environment(target)!=place) {
      tell_object(caster,"%^BOLD%^Your target has left the area!");
      TO->remove();
      return;
    }

    spell_successful();
    tell_room(environment(caster), "%^BOLD%^%^CYAN%^"+caster->QCN+" touches "+target->QCN+"'s nose and mouth lightly.", ({caster, target}) );
    tell_object(caster, "%^BOLD%^%^CYAN%^You give "+target->QCN+" the ability to breathe water.");
    tell_object(target, "%^BOLD%^%^CYAN%^"+caster->QCN+" gives you the power to breathe water.");

    breathob = new(WTROB);
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    breathob->set_maxtime(spell_duration);
    breathob->set_property("spell", TO);
    breathob->set_property("spelled", ({TO}));
    addSpellToCaster();
    breathob->move(target);
}

void dest_effect(){
    tell_object(target, "%^BOLD%^%^CYAN%^You feel the power to breathe water leave you.");
    if(objectp(breathob))
      breathob->remove();
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}

void reverse_spell(){
    spell_effect(-100);
}
