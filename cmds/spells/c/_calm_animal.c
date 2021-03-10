#include <daemons.h>
#include <spell.h>
#include <magic.h>
inherit SPELL;

#define VALIDTYPES ({ "arachnid","dragon","equine","fowl","insectoid","insectoid-winged","quadruped","reptile","snake" })

void create() {
    ::create();
    set_spell_name("calm animal");
    set_spell_level(([ "ranger" : 1 ]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS calm animal on TARGET");
    set_description("This will pacify an animal that is engaged in combat.  Once tried, the creature will not be "
"fooled by further attempts.");
    mental_spell();
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("fort");
}

string query_cast_string() {
    return caster->QCN+" murmurs soft, soothing words.";
}

void spell_effect(int prof) {
    object *inv;
    int i;


    if(!present(target,environment(caster))) {
      tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
      dest_effect();
      return;
    }
    if (!sizeof(target->query_attackers())) {
      tell_object(caster,"%^YELLOW%^That target does not need to be calmed.\n");
      dest_effect();
      return;
    }
    if(userp(target)) {
      tell_object(caster, "Your spell is harmlessly dispersed.");
      dest_effect();
      return;
    }
    if(member_array((string)target->query_body_type(),VALIDTYPES) == -1) {
      tell_object(caster, "Your spell is harmlessly dispersed.");
      dest_effect();
      return;
    }
    if (target->query_property("no hold") || target->query_property("no paralyze") || target->query_property("no calm")) {
      tell_object(caster,"%^YELLOW%^You spell disperses futilely around "+target->QCN+".\n");
      dest_effect();
      return;
    }
    if(pointerp(target->query_property("calmed")) && member_array(caster,target->query_property("calmed")) != -1){
      tell_object(target,"%^BOLD%^"+caster->QCN+" is trying to calm you again, and you turn upon them in a rage!");
      tell_object(caster,"%^BOLD%^You've already tried that and "+target->QCN+" is ready for it this time!");
      spell_kill(target,caster);
      dest_effect();
      return;
    }
    spell_successful();
    if(do_save(target,0)||mind_immunity_damage(target)) {
      tell_object(caster,"%^BOLD%^"+target->QCN+" pays no heed to your attempt, and instead turns upon you!\n");
      tell_object(target,"%^BOLD%^You feel a spell attempt to influence you, and turn upon "+caster->QCN+" in a rage!\n");
      spell_kill(target,caster);
      dest_effect();
      return;
    }
    tell_object(target,"%^BOLD%^You feel a sense of strangeness come over you as "+caster->QCN+" looks at you.");
    tell_object(target,"%^BOLD%^%^GREEN%^You suddenly feel unusually calm, and you cease your fighting.");
    tell_room(place,"%^BOLD%^%^GREEN%^You see a transformation take place in "+target->QCN+" as "+target->QS+" %^BOLD%^"
"%^GREEN%^calms down.",target);
    target->cease_all_attacks();
    inv = all_inventory(environment(target));
    for(i = 0;i<sizeof(inv);i++){
        if(!living(inv[i])) continue;
        if(target == inv[i]) continue;
        inv[i]->remove_attacker(target);
    }
    target->set("aggressive",0);
    target->set_property("calmed",({caster}));
    TO->remove();
}

void dest_effect(){
   ::dest_effect();
   if(objectp(TO)) TO->remove();
}
