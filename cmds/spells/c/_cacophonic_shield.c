#include <std.h>
#include <priest.h>

inherit SPELL;
int counter;

void create() {
    ::create();
    set_spell_name("cacophonic shield");
    set_spell_level(([ "bard" : 5 ]));
    set_spell_sphere("combat");
    set_syntax("cast CLASS cacophonic shield");
    set_description("This spell amplifies the caster's voice into an independently resonating wall of sound.  Any foes attempting to get close enough to harm the caster will find themselves buffeted by the sonic vibrations.");
    set_verbal_comp();
    set_helpful_spell(1);
    traveling_aoe_spell(1);
}

string query_cast_string() {
   return "%^ORANGE%^"+caster->QCN+" starts to hum a single low note.";
}

int preSpell() {
    if (caster->query_property("energy_retorted")) {
      tell_object(caster,"You are already under the effects of a similar spell!");
      return 0;
    }
    return 1;
}

void spell_effect(int prof) {
   tell_room(place,"%^YELLOW%^The soft note grows of its own accord as "+caster->QCN+" ceases humming, and the air around "+caster->QO+" ripples visibly!",caster);
   tell_object(caster,"%^YELLOW%^You hum a single low note, and the sound grows of its own accord until the air around you is filled with the resonating energy!");
   caster->set_property("energy_retorted",1);
   caster->set_property("spelled", ({TO}) );
   addSpellToCaster();
   spell_successful();
   environment(caster)->addObjectToCombatCycle(TO,1);
}

int extra,flag;

void execute_attack(){
   object ppl;
   string baddie;
    if (!flag) {
        ::execute_attack();
        flag = 1;
        return;
    }
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
   ppl = caster->query_current_attacker();
   define_base_damage(0);
   if (ppl && objectp(ppl)){
      baddie = ppl->QCN;
      extra = sdamage;
      if(!objectp(ppl)) return;
      tell_room(environment(caster),"%^YELLOW%^"+baddie+" gets a little too close and is knocked aside by the rippling barrier of sound surrounding "+caster->QCN+"!",({caster,ppl}));
      tell_object(caster,"%^YELLOW%^"+baddie+" gets a little too close to you, and is knocked aside by your defensive barrier of sonic!");
      tell_object(ppl,"%^YELLOW%^You get a little too close to "+caster->QCN+", and the rippling barrier of sound surrounding "+caster->QO+" knocks you aside!");
      damage_targ(ppl,ppl->return_target_limb(),extra,"sonic");
      counter++;
      if (counter > clevel) {
          dest_effect();
          return;
      }
    }
    environment(caster)->addObjectToCombatCycle(TO,1);
}

void dest_effect(){
    if(objectp(caster)){
       tell_object(caster,"%^ORANGE%^The humming barrier around you fades away to nothing.");
       tell_room(environment(caster),"%^ORANGE%^The humming barrier of sonic surrounding "+caster->QCN+" fades away to silence.",caster);
       caster->remove_property("energy_retorted");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
