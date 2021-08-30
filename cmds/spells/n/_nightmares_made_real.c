// parity with earthquake/windstorm for balance; upper AOE effect with trip option
#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

int nightmare_effects(object obj);
int duration;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("nightmares made real");
    set_spell_level(([ "warlock" : 3 ]));
    set_spell_sphere("illusion");
    set_syntax("cast CLASS nightmares made real");
    set_damage_desc("negative energy");
    set_description("By means of this invocation, the warlock cloaks the surrounding area in a horrific dreamscape "
"interwoven with planar energy, making any terrain look, sound and smell like something out of a nightmare. Writhing "
"vegetation, disembodied limbs, animated corpses, smoking pits, miasmic vapors, vile stenches, or anything else that "
"may spring from the caster's imagination. Those in the affected area that are strong of will may realise that these "
"are only illusions, and in doing so resist part of the harm they can cause; those fleet of foot may manage to avoid "
"the ensnaring grasp of the illusionary phantasms.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("varied");
    aoe_spell(1);
    set_aoe_message("%^RESET%^%^GREEN%^(warped by horrifying %^CYAN%^phantasms%^GREEN%^)%^RESET%^");
}

string query_cast_string(){
   tell_object(caster,"%^GREEN%^You wave your arms, and the air around you sh%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^mmers and rip%^CYAN%^pl%^GREEN%^es.%^RESET%^");
   tell_room(place,"%^GREEN%^"+caster->QCN+" waves "+caster->QP+" arms, and the air around you sh%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^mmers and rip%^CYAN%^pl%^GREEN%^es.%^RESET%^",caster);
   return "display";
}

void spell_effect(int prof){
   duration = (ROUND_LENGTH * clevel) * 2;
   tell_object(caster,"%^GREEN%^Weaving threads of planar energy into the illusion, you shape a terrifying d%^CYAN%^re%^GREEN%^am%^CYAN%^sc%^GREEN%^ap%^CYAN%^e%^GREEN%^ and interpose it upon reality!%^RESET%^");
   tell_room(PLACE,"%^GREEN%^"+caster->QCN+" completes "+caster->QP+" spell, as the world around you suddenly descends into a state of %^BLUE%^n%^CYAN%^ig%^BLUE%^htm%^MAGENTA%^a%^BLUE%^re%^GREEN%^!%^RESET%^",caster);
   caster->set_property("spelled", ({TO}));
   addSpellToCaster();
   spell_successful();
   spell_duration = duration;
   set_end_time();
   call_out("dest_effect",spell_duration);
}

void execute_attack(){
   object *attackers = ({});
   int i;

   ::execute_attack();
   if(!objectp(caster) || !objectp(environment(caster)) || caster->query_unconscious()){
      dest_effect();
      return;
   }
   if(environment(caster) != place){
      tell_object(caster,"%^GREEN%^The illusion fades as you leave the area.%^RESET%^");
      tell_room(place,"%^GREEN%^The illusion fades as "+caster->QCN+" leaves the area.%^RESET%^");
      dest_effect();
      return;
   }
//   attackers = caster->query_attackers();
   attackers = target_selector();


// let's see about this just going regardless of present attackers? else can't be pre-cast.
//   if(sizeof(attackers)){
      tell_room(place,"%^BLUE%^A horrific dreamscape shifts around you, filled with %^CYAN%^pha%^RESET%^n%^CYAN%^tasmal figures %^BLUE%^that reach out for the living!%^RESET%^");
      for(i=0;i<sizeof(attackers);i++) {
         if(!nightmare_effects(attackers[i])) continue;
      }
/*   }
   else{
      dest_effect();
      return;
   } */
   if(present(caster,place) && caster != target && !caster->query_unconscious()) {
       place->addObjectToCombatCycle(TO,1);
   }
   else {
       dest_effect();
   }
}

int nightmare_effects(object obj){
   int damage;
   object room;
   if(!objectp(obj))               { return 0; }
   if(!objectp(environment(obj)))  { return 0; }
   if(environment(caster) != environment(obj)) { return 0; }
   if(obj == caster) return 0;
   room = environment(obj);

   damage = sdamage;

   set_save("will");
   if(do_save(obj,0)){
      tell_object(obj,"%^GREEN%^You will away the illusion, though the planar energy still tears at your body!%^RESET%^");
      tell_room(room,"%^GREEN%^"+obj->QCN+" seems to see past the worst of the nightmarish visions!%^RESET%^",obj);
      damage_targ(obj,obj->return_target_limb(),damage/2,"negative energy");
   }
   else{
      tell_object(obj,"%^BOLD%^%^GREEN%^The nightmarish apparitions rend and tear your flesh!%^RESET%^");
      tell_room(room,"%^BOLD%^%^GREEN%^"+obj->QCN+" is tormented by the nightmarish apparitions!%^RESET%^",obj);
      damage_targ(obj,obj->return_target_limb(),damage,"negative energy");
      set_save("reflex");
      if(!do_save(obj,0)){
        tell_object(obj,"%^CYAN%^Writhing %^GREEN%^ve%^CYAN%^g%^GREEN%^etation %^CYAN%^and inc%^RESET%^o%^CYAN%^rpo%^RESET%^re%^CYAN%^al beings grasp at you, knocking you from your feet!%^RESET%^");
        tell_room(room,"%^CYAN%^"+obj->QCN+" is knocked from "+obj->QP+" feet by the grasping ph%^RESET%^a%^CYAN%^nt%^RESET%^as%^CYAN%^ms and writhing %^GREEN%^ve%^CYAN%^g%^GREEN%^etation%^CYAN%^!%^RESET%^",obj);
        obj->set_tripped(roll_dice(1,2),"%^BOLD%^You are struggling to get back to your feet!%^RESET%^",2);
      }
   }
   return 1;
}

void dest_effect(){
    if(objectp(place)) tell_room(place,"%^GREEN%^The nightmare finally ends as reality reasserts itself over the d%^CYAN%^re%^GREEN%^am%^CYAN%^sc%^GREEN%^ap%^CYAN%^e%^GREEN%^.%^RESET%^");
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
