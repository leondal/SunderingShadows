#include <spell.h>
#include <magic.h>
#include <daemons.h>
#include <clock.h>
inherit SPELL;

int mydiff;

void create() {
    ::create();
    set_spell_name("eagles splendor");
    set_spell_level(([ "paladin" : 2, "bard" : 2, "cleric" : 2, "mage" : 2,"paladin":2 ]));
    set_spell_sphere("alteration");
    set_bonus_type("enhancement");
    set_syntax("cast CLASS eagles splendor on TARGET");
    set_description("This spell allows the caster to infuse their target with the presence of an eagle, enhancing their force of personality.  This spell doesn't stack with similarly powerful spells of enhancement.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
	set_helpful_spell(1);
}

void spell_effect(int prof) {
    if (!objectp(caster)){
        TO->remove();
        return;
    }
    if (objectp(place)) place = environment(caster);
    /*
    if((int)target->query_property("augmentation")){
      tell_object(caster,"%^YELLOW%^"+target->QCN+" is already under the influence of a similar spell.");
      dest_effect();
      return;
    }
    */
    if(prof == -100) { // hack for potions. Cuz lib doesn't seem to call reverse spell anymore, and I'm lazy. N, 6/15.
      reverse_spell();
      return;
    }
    if((string)TO->query_spell_type() == "potion")
      tell_object(caster,"%^CYAN%^As the potion warms your stomach, you feel your confidence grow.%^RESET%^");
    else {
      if(target == caster) {
        tell_object(caster,"%^YELLOW%^You intone the spell of transformation upon yourself, and feel immediately more "
"confident and poised!%^RESET%^");
        tell_room(place,"%^YELLOW%^"+caster->QCN+" intones a spell over "+caster->QO+"self.%^RESET%^",caster);
      }
      else {
        tell_object(caster,"%^YELLOW%^You intone the spell of transformation over "+target->QCN+"!%^RESET%^");
        tell_object(target,"%^YELLOW%^"+caster->QCN+" intones a spell over you, and you feel immediately more confident "
"and poised!%^RESET%^");
        tell_room(place,"%^YELLOW%^"+caster->QCN+" intones a spell over "+target->QCN+".%^RESET%^",({caster,target}));
      }
    }
    mydiff = 4;
    mydiff = min(({ mydiff, (30 - target->query_stats("charisma")) }));
    //if(target->query_stats("charisma") > 28) mydiff = 1;
    //if(target->query_stats("charisma") > 29) mydiff = 0;
    if(mydiff) {
      target->add_stat_bonus("charisma",mydiff);
      target->set_property("augmentation",1);
    }
    spell_successful();
    addSpellToTarget();
}

void dest_effect(){
    if(objectp(target) && mydiff) {
      if((string)TO->query_spell_type() == "potion") tell_object(target,"%^RESET%^%^RED%^The potion's enhancement fades from you.%^RESET%^");
      else tell_object(target,"%^RESET%^%^RED%^The spell's enhancement fades from you.%^RESET%^");
      target->add_stat_bonus("charisma",(-1)*mydiff);
      target->set_property("augmentation",-1);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

void reverse_spell(){
    // adding in backfires for potions! Can't find where lib actually calls this anymore.
    tell_object(caster,"%^CYAN%^A queasy feeling runs through you, leaving you self-conscious.%^RESET%^");

    mydiff *= -1;
    if(target->query_stats("charisma") < 4) mydiff = -1;
    if(target->query_stats("charisma") < 3) mydiff = 0;
    if(mydiff) {
      target->add_stat_bonus("charisma",mydiff);
      target->set_property("augmentation",1);
    }
    spell_successful();
    call_out("dest_effect",clevel);
}
