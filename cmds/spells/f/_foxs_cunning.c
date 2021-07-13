#include <spell.h>
#include <magic.h>
#include <daemons.h>
#include <clock.h>
inherit SPELL;

int mydiff;

void create() {
    ::create();
    set_spell_name("foxs cunning");
    set_spell_level(([ "bard" : 2, "assassin" : 2, "mage" : 2, "magus" : 2 ]));
    set_spell_sphere("alteration");
    set_bonus_type("enhancement");
    set_syntax("cast CLASS foxs cunning on TARGET");
    set_description("This spell allows the caster to infuse their target with the slyness of a fox, granting them a +4 enhancement bonus to intelligence.");
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
      return;
    }
    */
    if(prof == -100) { // hack for potions. Cuz lib doesn't seem to call reverse spell anymore, and I'm lazy. N, 6/15.
      reverse_spell();
      return;
    }
    if((string)TO->query_spell_type() == "potion")
      tell_object(caster,"%^CYAN%^As the potion warms your stomach, you feel your wits sharpen.%^RESET%^");
    else {
      if(target == caster) {
        tell_object(caster,"%^YELLOW%^You intone the spell of transformation upon yourself, and feel your wits suddenly "
"sharpen!%^RESET%^");
        tell_room(place,"%^YELLOW%^"+caster->QCN+" intones a spell over "+caster->QO+"self.%^RESET%^",caster);
      }
      else {
        tell_object(caster,"%^YELLOW%^You intone the spell of transformation over "+target->QCN+"!%^RESET%^");
        tell_object(target,"%^YELLOW%^"+caster->QCN+" intones a spell over you, and you feel your wits suddenly "
"sharpen!%^RESET%^");
        tell_room(place,"%^YELLOW%^"+caster->QCN+" intones a spell over "+target->QCN+".%^RESET%^",({caster,target}));
      }
    }
    mydiff = 4;
    mydiff = min(({ mydiff, (30 - target->query_stats("intelligence")) }));
    //if(target->query_stats("intelligence") > 28) mydiff = 1;
    //if(target->query_stats("intelligence") > 29) mydiff = 0;
    if(mydiff) {
      target->add_stat_bonus("intelligence",mydiff);
      //target->set_property("augmentation",1);
    }
    spell_successful();
    addSpellToTarget();
}

void dest_effect(){
    if(objectp(target) && mydiff) {
      if((string)TO->query_spell_type() == "potion") tell_object(target,"%^RESET%^%^RED%^The potion's enhancement fades from you.%^RESET%^");
      else tell_object(target,"%^RESET%^%^RED%^The spell's enhancement fades from you.%^RESET%^");
      target->add_stat_bonus("intelligence",(-1)*mydiff);
      //target->set_property("augmentation",-1);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}

void reverse_spell(){
    // adding in backfires for potions! Can't find where lib actually calls this anymore.
    tell_object(caster,"%^CYAN%^A queasy feeling runs through you, and your wits dull.%^RESET%^");

    mydiff *= -1;
    //if(target->query_stats("intelligence") < 4) mydiff = -1;
    //if(target->query_stats("intelligence") < 3) mydiff = 0;
    if(mydiff) {
      target->add_stat_bonus("intelligence",mydiff);
      //target->set_property("augmentation",1);
    }
    spell_successful();
    call_out("dest_effect",clevel);
}
