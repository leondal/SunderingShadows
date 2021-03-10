//Maw of Stone - based on stormwinds
//new Cavern domain spell by ~Circe~
//Rebalancing domains 5/20/08
#include <std.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int count;

void create(){
    ::create();
    set_spell_name("maw of stone");
    set_spell_level(([ "cleric" : 5 ]));
    set_spell_sphere("elemental earth");
    set_syntax("cast CLASS maw of stone on TARGET");
    set_description("This spell conjures stone from the earth to surround the target, causing damage to all those "
"attacking the caster initially.  Afterwards, it continues to gnaw on the target for a limited time.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("reflex");
}

string query_cast_string()
{
    string diety;
    diety = (string)caster->query_diety();
    if(!diety) { diety = "pan"; }

   tell_object(caster,"%^BOLD%^You draw a wide arc upon the "+
      "ground with your toe, calling forth "+
      ""+capitalize(diety)+"'s power!%^RESET%^");
   tell_room(place,"%^BOLD%^"+caster->QCN+" chants a spell of power "+
      "as "+caster->QS+" draws a wide arc upon the ground with "+
      ""+caster->QP+" toe!%^RESET%^",caster);
   return "display";
}

int preSpell(){
   if(!objectp(target)){
      tell_object(caster,"This spell requires a target.");
      return 0;
   }
   if (caster->query_property("stone_maw")){
      tell_object(caster,"%^BOLD%^You cannot control a second maw of stone.");
      return 0;
   }
   return 1;
}

void spell_effect(int prof){
   int i;
   object *who;

   if(!objectp(target) || !objectp(caster) || !objectp(place)){
      dest_effect();
      return;
   }
   if(!present(target,place)){
      tell_object(caster,"%^BOLD%^Your target has left the area.");
      dest_effect();
      return;
   }
//FIX FROM HERE
   caster->set_property("stone_maw",1);
   tell_object(place,"%^BOLD%^%^BLACK%^The ground suddenly rises "+
      "up, forming itself into a giant gaping maw!%^RESET%^");
   who = caster->query_attackers();

   for(i=0;i<sizeof(who);i++){
      if(!objectp(who[i])) continue;
      if(who[i] == caster) continue;
      if(!do_save(who[i])) {
      //if(!(SAVING_D->saving_throw(who[i], "spell",0))){
         tell_object(who[i],"%^YELLOW%^The maw of stone strikes you "+
            "as it rises!%^RESET%^");
         tell_object(place,"%^YELLOW%^"+who[i]->QCN+" is struck by "+
            "the maw of stone as it rises!%^RESET%^",who[i]);
         damage_targ(who[i],"torso",sdamage,"bludgeoning");
      }
   }
   count = 0;
   call_out("do_gnaw",ROUND_LENGTH);
}

void do_gnaw() {
   int dam,i;

   if(!objectp(target) || !objectp(caster) || !objectp(environment(target))){
      dest_effect();
      return;
   }
   if(target->query_ghost() || caster->query_ghost()){
      dest_effect();
      return;
   }
   if(environment(caster) != environment(target)){
      tell_object(environment(target),"%^BOLD%^The maw of stone "+
         "ceases moving and fades back into the ground.%^RESET%^",caster);
      tell_object(caster,"%^BOLD%^The maw of stone ceases moving "+
         "and fades back into the ground.%^RESET%^");
      dest_effect();
      return;
   }
   define_base_damage(-2);
   dam = sdamage;
//   if(dam > 150) dam = 150; //changed from clevel,4, capped at 150. If needs rebalancing.
   tell_object(target,"%^BOLD%^%^BLACK%^The maw of stone gnaws on "+
      "you, crushing you in its gaping jaws!%^RESET%^");
   tell_room(environment(target),"%^BOLD%^%^BLACK%^The maw of stone "+
      "crushes "+target->QCN+" in its gaping jaws!%^RESET%^",target);
   //if(!(SAVING_D->saving_throw(target, "spell",-4))){
   if(!do_save(target,0)){
      damage_targ(target,"torso",dam,"bludgeoning");
   }else{
      damage_targ(target,"torso",dam/2,"bludgeoning");
   }
   count++;
   if(!objectp(target)) {
      dest_effect();
      return;
   }
   if(count == (clevel/5)){
      tell_object(environment(target),"%^BOLD%^The maw of stone "+
         "ceases moving and fades back into the ground.%^RESET%^");
      dest_effect();
      return;
   }else{
      call_out("do_gnaw",ROUND_LENGTH);
   }
}

void dest_effect()
{
    if(objectp(caster)) { caster->remove_property("stone_maw"); }
    remove_call_out("do_gnaw");
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
