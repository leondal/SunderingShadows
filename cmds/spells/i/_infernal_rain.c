// infernal rain - port of earthquake spell for hellfire warlock.
#include <spell.h>
#include <daemons.h>
#include <magic.h>
inherit SPELL;

int storm_effects(object obj);

object storm_room;
int duration;

void create(){
    ::create();
    set_spell_name("infernal rain");
    set_spell_level(([ "warlock" : 4 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS infernal rain");
    set_description("This invocation unleashes a storm of hellfire, raining down the wrath of infernal energies upon the "
"warlock's foes.  The invocation will last several rounds depending upon the level of the warlock, and the warlock must "
"remain present for the storm to continue.  All those attacking the warlock are subject to the effects of the infernal rain"
", though they do receive saving throws. Only one area spell or invocation may be maintained by a caster at a time!\n\n"
"Only a hellfire warlock may harness this invocation.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
    aoe_spell(1);
    set_aoe_message("%^BOLD%^%^BLACK%^(%^RESET%^%^RED%^aglow %^BOLD%^%^BLACK%^with %^BOLD%^%^RED%^hellfire%^BOLD%^%^BLACK%^)%^RESET%^");
    set_feats_required(([ "warlock" : "infernal practitioner"]));
}

string query_cast_string(){
   tell_object(caster,"%^RED%^You extend your power outwards, seeking weaknesses between the planes.%^RESET%^");
   tell_room(place,"%^RED%^"+caster->QCN+" falls into a state of momentary concentration.%^RESET%^",caster);
   return "display";
}

void spell_effect(int prof){
   duration = (ROUND_LENGTH * clevel) * 3;
   tell_object(caster,"%^RESET%^%^RED%^You find the flaw in reality you seek and reach past it, and the air around you takes on an ominous %^BOLD%^%^RED%^glow%^RESET%^%^RED%^!%^RESET%^");
   tell_room(PLACE,"%^RESET%^%^RED%^"+caster->QCN+"'s attention snaps sharply back to reality, and the air around you takes on an ominous %^BOLD%^%^RED%^glow%^RESET%^%^RED%^!%^RESET%^",caster);
    PLACE->set_property("spelled", ({TO}));
    storm_room = PLACE;
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
   if(environment(caster) != storm_room){
      tell_object(caster,"%^ORANGE%^The malignant glow fades from the air as you depart.%^RESET%^");
      tell_room(storm_room,"%^ORANGE%^The malignant glow fades from the air as "+caster->QCN+" departs.%^RESET%^");
      dest_effect();
      return;
   }
   attackers = CASTER->query_attackers();
   attackers = filter_array(attackers,"is_non_immortal",FILTERS_D);

   if(sizeof(attackers))
   {
      tell_room(storm_room,"%^BOLD%^%^BLACK%^Searing h%^BOLD%^%^RED%^e%^BOLD%^%^BLACK%^llfire tears through reality and lashes the area!%^RESET%^");
      for(i=0;i<sizeof(attackers);i++)
      {
         if(!objectp(attackers[i])) { continue; }
         if(!storm_effects(attackers[i])) { continue; }
      }
      place->addObjectToCombatCycle(TO,1);
      return;
   }
   else
   {
       dest_effect();
       return;
   }
}

int storm_effects(object obj){
   int damage;
   object room;
   if(!objectp(obj))               { return 0; }
   if(!objectp(environment(obj)))  { return 0; }
   if(environment(caster) != environment(obj)) { return 0; }
   room = environment(obj);

   define_base_damage(0);//lazy re-roll
   damage = sdamage;

   if(do_save(obj,0)){
      if(!evade_splash(obj)) {
        tell_object(obj,"%^RED%^You scramble clear of the worst of the baleful firestorm!%^RESET%^");
        tell_room(room,"%^RED%^"+obj->QCN+" scrambles clear of the worst of the baleful firestorm!%^RESET%^",obj);
        damage_targ(obj,obj->return_target_limb(),damage/2,"untyped"); // all damage is hellfire, and thus untyped. N, 4/17.
      }
   }else{
      tell_object(obj,"%^BOLD%^%^RED%^The infernal flames scorch and blister your skin!%^RESET%^");
      tell_room(room,"%^BOLD%^%^RED%^The infernal flames scorch and blister "+obj->QCN+"!%^RESET%^",obj);
      damage_targ(obj,obj->return_target_limb(),damage,"untyped"); // all damage is hellfire, and thus untyped. N, 4/17.
   }

   if(!do_save(obj,4)){
      tell_object(obj,"%^YELLOW%^Blazing fragments rupture the earth, knocking you from your feet!%^RESET%^");
      tell_room(room,"%^YELLOW%^Blazing fragments rupture the earth, and "+obj->QCN+" is knocked from "+obj->QP+" feet!%^RESET%^",obj);
      obj->set_tripped(roll_dice(1,2),"%^BOLD%^You are struggling to get back to your feet!%^RESET%^",2);
   }
    return 1;
}

void dest_effect(){
    if(objectp(place)) tell_room(place,"%^ORANGE%^The malignant glow fades from the air.%^RESET%^");
    ::dest_effect();
    if(objectp(TO)) { TO->remove(); }
}
