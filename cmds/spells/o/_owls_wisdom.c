#include <spell.h>
#include <magic.h>
#include <daemons.h>
#include <clock.h>
inherit SPELL;

int mydiff;

void create() {
    ::create();
    set_spell_name("owls wisdom");
    set_spell_level(([ "ranger" : 2, "paladin" : 2, "cleric" : 2,"druid" : 2, "mage" : 2 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS owls wisdom on TARGET");
    set_description("This spell allows the caster to infuse their target with the wisdom of an owl, granting them "
"improved insight.  This spell doesn't stack with similarly powerful spells of enhancement.");
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
    if((int)target->query_property("augmentation")){
      tell_object(caster,"%^YELLOW%^"+target->QCN+" is already under the influence of a similar spell.");
      dest_effect();
      return;
    }
    if(prof == -100) { // hack for potions. Cuz lib doesn't seem to call reverse spell anymore, and I'm lazy. N, 6/15.
      reverse_spell();
      return;
    }
    if((string)TO->query_spell_type() == "potion")
      tell_object(caster,"%^CYAN%^As the potion warms your stomach, you feel your wits sharpen.%^RESET%^");
    else {
      if(target == caster) {
        tell_object(caster,"%^YELLOW%^You intone the spell of transformation upon yourself, and feel your insight and "
"alertness grow!%^RESET%^");
        tell_room(place,"%^YELLOW%^"+caster->QCN+" intones a spell over "+caster->QO+"self.%^RESET%^",caster);
      }
      else {
        tell_object(caster,"%^YELLOW%^You intone the spell of transformation over "+target->QCN+"!%^RESET%^");
        tell_object(target,"%^YELLOW%^"+caster->QCN+" intones a spell over you, and you feel your insight and alertness "
"grow!%^RESET%^");
        tell_room(place,"%^YELLOW%^"+caster->QCN+" intones a spell over "+target->QCN+".%^RESET%^",({caster,target}));
      }
    }
    mydiff = 2;
    if(target->query_stats("wisdom") > 28) mydiff = 1;
    if(target->query_stats("wisdom") > 29) mydiff = 0;
    if(mydiff) {
      target->add_stat_bonus("wisdom",mydiff);
      target->set_property("augmentation",1);
    }
    spell_successful();
    addSpellToTarget();
}

void dest_effect(){
    if(objectp(target) && mydiff) {
      if((string)TO->query_spell_type() == "potion") tell_object(target,"%^RESET%^%^RED%^The potion's enhancement fades from you.%^RESET%^");
      else tell_object(target,"%^RESET%^%^RED%^The spell's enhancement fades from you.%^RESET%^");
      target->add_stat_bonus("wisdom",(-1)*mydiff);
      target->set_property("augmentation",-1);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}

void reverse_spell(){
    // adding in backfires for potions! Can't find where lib actually calls this anymore.
    tell_object(caster,"%^CYAN%^A queasy feeling runs through you, leaving you dazed.%^RESET%^");

    mydiff = -2;
    if(target->query_stats("wisdom") < 4) mydiff = -1;
    if(target->query_stats("wisdom") < 3) mydiff = 0;
    if(mydiff) {
      target->add_stat_bonus("wisdom",mydiff);
      target->set_property("augmentation",1);
    }
    spell_successful();
    call_out("dest_effect",clevel);
}
