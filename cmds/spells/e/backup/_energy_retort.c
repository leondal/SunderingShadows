#include <std.h>
#include <priest.h>

inherit SPELL;
int counter;
int flag=0;

void create() {
    ::create();
    set_spell_name("energy retort");
    set_spell_level(([ "psion" : 3 ]));
    set_spell_sphere("psychokinesis");
    set_syntax("cast CLASS energy retort");
    set_description("This power will generate psychic energy around the psion, enveloping him in a crackling field that "
"can harm attackers.  Once each round, the psion automatically lashes out at one of his foes, striking him with energy.  "
"The duration of this power grows with the psion.");
    set_verbal_comp();
    set_helpful_spell(1);
    traveling_aoe_spell(1);
}

string query_cast_string() {
   return "%^ORANGE%^"+caster->QCN+" focuses, causing the area "+
      "to crackle with energy.";

}

int preSpell() {
    if (caster->query_property("energy_retorted")) {
      tell_object(caster,"You are already under the effects of this power!");
        return 0;
    }
    return 1;
}


void spell_effect(int prof) {
   tell_room(place,"%^YELLOW%^"+caster->QCN+" suddenly glows within "+
      "a field of energy!",caster);
   tell_object(caster,"%^YELLOW%^You feel electrified as your skin "+
      "crackles with energy!");
   caster->set_property("energy_retorted",1);
   caster->set_property("spelled", ({TO}) );
   addSpellToCaster();
   spell_successful();
   execute_attack();
    call_out("room_check",ROUND_LENGTH);
}

void room_check()
{
    if(!objectp(caster) || !objectp(ENV(caster)))
    {
        dest_effect();
        return;
    }

    prepend_to_combat_cycle(ENV(caster));

    call_out("room_check",ROUND_LENGTH*2);
    return;
}

void execute_attack(){
   object ppl;
   string baddie;
   int mylevel;
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
    if (ppl && objectp(ppl)){
      baddie = ppl->QCN;
      if(!objectp(ppl)) return;
      tell_room(environment(caster),"%^YELLOW%^"+caster->QCN+" suddenly surges with "+
         "energy, lashing out at "+baddie+"",({caster,ppl}));
      tell_object(caster,"%^YELLOW%^A sudden surge of your psychic "+
         "energy lashes out at "+baddie+"!");
      tell_object(ppl,"%^YELLOW%^A sudden surge of energy from "+
         ""+caster->QCN+" lashes out at you!");
      damage_targ(ppl,ppl->return_target_limb(),sdamage,"mental");
      counter++;
      if (counter > clevel * 6) {
          dest_effect();
          return;
      }
    }
    environment(caster)->addObjectToCombatCycle(TO,1);
}

void dest_effect(){
    remove_call_out("room_check");
    if(objectp(caster)){
       tell_object(caster,"%^ORANGE%^You feel the energy drain from you.");
       tell_room(environment(caster),"%^ORANGE%^The field of energy "+
          "surrounding "+caster->QCN+" fades away.",caster);
       caster->remove_property("energy_retorted");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
