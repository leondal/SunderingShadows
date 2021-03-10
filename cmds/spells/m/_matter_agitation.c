//Matter Agitation - low level damage over time spell for psions ~Circe~ 3/19/16
#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

void dest_effect();
void damage(object mytarg);
int counter,dam,mylevel;

void create() {
    ::create();
    set_spell_name("matter agitation");
    set_spell_level(([ "psion" : 1 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS matter agitation on TARGET");
    set_description("This power allows the psion to alter the structure "
       "of matter, exciting atoms to the point that they generate intense "
       "heat, scorching the target. The power does damage over time, "
       "growing in intensity before the matter settles once again.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("fort");
}

int preSpell(){
   if(target->query_property(""+caster->QCN+" agitated")){
      tell_object(caster,"You have already inflicted this power on that target!");
      return 0;
   }
   return 1;
}

void spell_effect(int prof) {

   mylevel = clevel;
   if(!present(target,environment(caster))) {
      tell_object(caster,"%^BOLD%^Your target is not in this area.");
      dest_effect();
      return;
   }
   target->set_property(""+caster->QCN+" agitated",1);
   tell_object(target,"%^RESET%^%^ORANGE%^The scent of %^YELLOW%^sulfur "
      "%^RESET%^%^ORANGE%^fills the air as "+caster->QCN+" points a finger at you.%^RESET%^");
   tell_object(caster,"%^RESET%^%^ORANGE%^As you focus on the atoms "
      "surrounding "+target->QCN+", the scent of %^YELLOW%^sulfur %^RESET%^%^ORANGE%^fills the air.%^RESET%^");
   tell_room(place,"%^RESET%^%^ORANGE%^The scent of %^YELLOW%^sulfur "
      "%^RESET%^%^ORANGE%^fills the air as "+caster->QCN+" points a "
      "finger at "+target->QCN+".%^RESET%^",({caster, target}));
   spell_kill(target,caster);
   counter = 0;
   damage(target);
   spell_successful();
   return;
}

void damage(object mytarg)
{
   if(!objectp(mytarg) || !objectp(environment(mytarg)))
   {
       dest_effect();
       return;
   }
   if(counter == 0){
      dam = mylevel+random(mylevel);
      if(do_save(mytarg,0)) {
         tell_object(mytarg,"%^YELLOW%^The air around you buzzes with excess "
            "energy, but you manage to withstand some of the heat!%^RESET%^");
         tell_room(environment(mytarg),"%^YELLOW%^The air surrounding "
            ""+mytarg->QCN+" buzzes with excess energy, emitting heat!%^RESET%^",mytarg);
         damage_targ(mytarg, "torso", to_int(dam / 2),"fire");
      }else{
         tell_object(mytarg,"%^YELLOW%^Your body vibrates as the matter surrounding "
            "you buzzes with excess energy, heating your skin!%^RESET%^");
         tell_room(environment(mytarg),"%^YELLOW%^"+mytarg->QCN+" seems to blur "
            "around the edges as the air vibrates with energy, burning "+mytarg->QO+"!%^RESET%^",mytarg);
         damage_targ(mytarg, "torso", dam,"fire");
      }
      counter++;
      call_out("damage",ROUND_LENGTH,mytarg);
      return;
   }else if(counter == 1){
      dam = mylevel*2;
      if(do_save(mytarg,0)) {
         tell_object(mytarg,"%^RESET%^%^RED%^A strange buzzing noise fills your ears "
            "as the height grows stronger, though you try to fight it off!%^RESET%^");
         tell_room(environment(mytarg),"%^RESET%^%^RED%^The buzzing becomes audible as "
            "the air around "+mytarg->QCN+" vibrates, bathing you in ambient heat!%^RESET%^",mytarg);
         damage_targ(mytarg, "torso", to_int(dam / 2),"fire");
      }else{
         tell_object(mytarg,"%^RESET%^%^RED%^The heat grows more intense as the "
            "air around you vibrates, nearly obscuring your vision. You smell something "
            "burning!%^RESET%^");
         tell_room(environment(mytarg),"%^RESET%^%^RED%^The acrid smell of something "
            "burning accompanies a vibrating haze that surrounds "+mytarg->QCN+"!%^RESET%^",mytarg);
         damage_targ(mytarg, "torso", dam,"fire");
      }
      counter++;
      call_out("damage",ROUND_LENGTH,mytarg);
      return;
   }else if(counter == 2){
      dam = mylevel*2+random(mylevel);
      if(do_save(mytarg,0)) {
         tell_object(mytarg,"%^BOLD%^%^RED%^Combustible matter around you bursts "
            "into flames, but you avoid the worst of the fire!%^RESET%^");
         tell_room(environment(mytarg),"%^BOLD%^%^RED%^Small flames erupt all around "
            ""+mytarg->QCN+", who seems to avoid the worst of it!%^RESET%^",mytarg);
         damage_targ(mytarg, "torso", to_int(dam / 2),"fire");
      }else{
         tell_object(mytarg,"%^BOLD%^%^RED%^Your lungs are scorched as the very air "
            "around you bursts into flame, burning your body!%^RESET%^");
         tell_room(environment(mytarg),"%^BOLD%^%^RED%^Flames engulf "+mytarg->QCN+", "
            "obscuring "+mytarg->QO+" in a haze of smoke!%^RESET%^",mytarg);
         damage_targ(mytarg, "torso", dam,"fire");
      }
      call_out("dest_effect",ROUND_LENGTH,mytarg);
      return;
   }else{
      dest_effect();
   }
   return;
}

void dest_effect(){
    if(objectp(target)){
       target->remove_property(""+caster->QCN+" agitated");
       tell_object(target,"%^RESET%^%^CYAN%^The matter around you "
          "stills, bringing blessed relief from the heat!%^RESET%^");
       tell_room(environment(target),"%^RESET%^%^CYAN%^The matter "
          "surrounding "+target->QCN+" stills, bringing a rush of cool air.%^RESET%^",target);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
