//New version of Incendiary Cloud to fix the old buggy version
//based on Earthquake
//~Circe~ 7/20/13

#include <spell.h>
#include <daemons.h>
#include <magic.h>
inherit SPELL;

int storm_effects(object obj);

object storm_room;
int duration,flag;
string element;

void create(){
    ::create();
    set_spell_name("incendiary cloud");
    set_spell_level(([ "mage" : 8, "oracle" : 8, "cleric":8, "druid" : 8]));
    set_domains("fire");
    set_mystery(({"flame","apocalypse"}));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS incendiary cloud");
    set_damage_desc("fire or versatile arcanist");
    set_description("Upon casting this spell, the mage conjures "
       "a heaving mass of smoke and flames that blankets the area, "
       "scorching those who dare attack the caster. Like most fires, "
       "this one requires a brief time to build to a raging inferno "
       "before it fizzles out again, leaving devastation in its wake.  "
       "If the caster leaves the area, the cloud will dissipate. A "
       "versatile arcanist can manipulate the base element of this spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_components(([
      "mage" : ([ "flint":1, "dung scrapings":1, ]),
    ]));
    set_immunities( ({"fire"}) );
    set_save("varied");
    aoe_spell(1);
    set_aoe_message("%^BOLD%^%^BLACK%^(filled with %^RESET%^smoke %^BOLD%^%^BLACK%^and %^RESET%^%^RED%^flames%^BOLD%^%^BLACK%^)%^RESET%^");
}

void spell_effect(int prof){
    element = (string)caster->query("elementalist");
    switch(element) {
      case "acid":
        tell_object(caster,"%^RESET%^%^GREEN%^As you chant, a deafening %^BOLD%^%^BLACK%^hiss %^RESET%^%^GREEN%^encompasses the area, as a cloud of %^BOLD%^%^GREEN%^t%^YELLOW%^o%^BLACK%^x%^YELLOW%^i%^GREEN%^c %^RESET%^%^GREEN%^gas explodes outward from you!");
        tell_room(place,"%^GREEN%^"+caster->QCN+" chants a spell, and a deafening %^BOLD%^%^BLACK%^hiss %^RESET%^%^GREEN%^encompasses the area, as a cloud of %^BOLD%^%^GREEN%^t%^YELLOW%^o%^BLACK%^x%^YELLOW%^i%^GREEN%^c %^RESET%^%^GREEN%^gas explodes outward from you!",caster);
        set_aoe_message("%^BOLD%^%^BLACK%^(filled with %^RESET%^%^GREEN%^choking gas%^BOLD%^%^BLACK%^)%^RESET%^");
      break;
      case "cold":
        tell_object(caster,"%^CYAN%^As you chant the spell, the air explodes into a brittle cloud of frost and smoke!%^RESET%^");
        tell_room(place,"%^CYAN%^"+caster->QCN+" chants a spell, and the air explodes into a brittle cloud of frost and smoke!%^RESET%^",caster);
        set_aoe_message("%^BOLD%^%^BLACK%^(filled with %^RESET%^smoke %^BOLD%^%^BLACK%^and %^RESET%^%^CYAN%^frost%^BOLD%^%^BLACK%^)%^RESET%^");
      break;
      case "electricity":
        tell_object(caster,"%^ORANGE%^As you chant the spell, the air explodes into a cloud of smoke and static!%^RESET%^");
        tell_room(place,"%^ORANGE%^"+caster->QCN+" chants a spell, and the air explodes into a cloud of smoke and static!%^RESET%^",caster);
        set_aoe_message("%^BOLD%^%^BLACK%^(filled with %^RESET%^smoke %^BOLD%^%^BLACK%^and %^YELLOW%^static%^BOLD%^%^BLACK%^)%^RESET%^");
      break;
      case "sonic":
        tell_object(caster,"%^CYAN%^As you chants the spell, a %^BOLD%^%^BLACK%^r%^RESET%^e%^BOLD%^v%^BLACK%^e%^CYAN%^r%^RESET%^%^CYAN%^b%^BOLD%^%^BLACK%^e%^RESET%^%^CYAN%^r%^BOLD%^a%^BLACK%^t%^WHITE%^i%^RESET%^n%^BOLD%^%^BLACK%^g %^RESET%^h%^BOLD%^%^BLACK%^a%^RESET%^ze %^CYAN%^settles over the area, growing in intensity!");
        tell_room(place,"%^MAGENTA%^"+caster->QCN+" %^CYAN%^chants a spell, and a %^BOLD%^%^BLACK%^r%^RESET%^e%^BOLD%^v%^BLACK%^e%^CYAN%^r%^RESET%^%^CYAN%^b%^BOLD%^%^BLACK%^e%^RESET%^%^CYAN%^r%^BOLD%^a%^BLACK%^t%^WHITE%^i%^RESET%^n%^BOLD%^%^BLACK%^g %^RESET%^h%^BOLD%^%^BLACK%^a%^RESET%^ze %^CYAN%^settles over the area, growing in intensity!%^RESET%^",caster);
        set_aoe_message("%^BOLD%^%^BLACK%^(filled with a %^RESET%^%^CYAN%^reverberating %^RESET%^haze%^BOLD%^%^BLACK%^)%^RESET%^");
      break;
      default:
        element = "fire";
        tell_object(caster,"%^RED%^As you chant the spell, a massive flare consumes the room, exploding into a cloud of smoke!%^RESET%^");
        tell_room(place,"%^RED%^"+caster->QCN+" chants a spell, and a massive flare consumes the room, exploding into a cloud of smoke!%^RESET%^",caster);
      break;
    }
    caster->set_property("spelled", ({TO}));
    storm_room = place;
    duration = 0;
    addSpellToCaster();
    spell_successful();
    call_out("do_incendiary",1);
}

void do_incendiary() {
   object *attackers = ({});
   int i;

   if(!objectp(caster) || !objectp(environment(caster)) || caster->query_unconscious()){
      dest_effect();
      return;
   }
   if(duration > clevel * 3){
      dest_effect();
      return;
   }
   if(environment(caster) != place){
      tell_object(caster,"%^BOLD%^%^BLACK%^As you leave the area, the cloud dissipates into harmless smoke.%^RESET%^");
      tell_room(storm_room,"%^BOLD%^%^BLACK%^The cloud dissipates into harmless smoke as "+caster->QCN+" leaves the area.%^RESET%^",caster);
      dest_effect();
      return;
   }
   attackers = target_selector();


   attackers -= ({caster});
   if(sizeof(attackers)){
      switch(element) {
        case "acid":
          tell_room(place,"%^GREEN%^The %^BOLD%^%^GREEN%^t%^YELLOW%^o%^BLACK%^x%^YELLOW%^i%^GREEN%^c %^RESET%^%^GREEN%^gas seeps through the area, blistering anything it touches!%^RESET%^");
        break;
        case "cold":
          tell_room(place,"%^CYAN%^The cloud of frost drifts through the area, chilling everything it touches!%^RESET%^");
        break;
        case "electricity":
          tell_room(place,"%^ORANGE%^The static cloud drifts through the area, crackling with energy and jolting anything it touches!%^RESET%^");
        break;
        case "sonic":
          tell_room(place,"%^CYAN%^The %^RESET%^h%^BOLD%^%^BLACK%^a%^RESET%^ze %^CYAN%^drifts through the area, causing anything it approaches to tremble!");
        break;
        default:
          tell_room(place,"%^RED%^The cloud of smoke drifts through the area, %^BOLD%^%^RED%^glowing%^RESET%^%^RED%^ with radiant heat and searing anything it touches!%^RESET%^");
        break;
      }
      for(i=0;i<sizeof(attackers);i++){
         if(!storm_effects(attackers[i])) { continue; }
      }
   }
   duration ++;
   call_out("do_incendiary",ROUND_LENGTH);
}

int storm_effects(object obj){
   object room;
   string my_mess, your_mess;
   if(!objectp(obj))               { return 0; }
   if(!objectp(environment(obj)))  { return 0; }
   if(environment(caster) != environment(obj)) { return 0; }
   room = environment(obj);

   switch(random(3)){
      case 0:
        set_save("reflex");

        if(!do_save(obj)) {
          tell_object(obj,"%^BOLD%^%^BLACK%^You inhale some of the smoke, and it burns your lungs!");
          damage_targ(obj,obj->return_target_limb(),sdamage,element);
        }
        else {
            tell_object(obj,"%^BOLD%^%^BLACK%^You can't avoid inhaling some of the smoke, but you try and avoid the worst of it!");
            damage_targ(obj,obj->return_target_limb(),sdamage/2,element);
        }

        set_save("fort");
        if(do_save(obj,0)) tell_object(obj,"%^BOLD%^%^WHITE%^You cough and wave away the worst of the smoke!%^RESET%^");
        else {
          tell_object(obj,"%^BOLD%^%^BLACK%^The smoke makes it difficult to see or breathe!%^RESET%^");
          obj->set_paralyzed(roll_dice(1,2),"You are too dazed and choked by the cloud of smoke!");
        }
      break;
      case 1:
        set_save("reflex");
        if(do_save(obj,0)){
             tell_object(obj,"%^BOLD%^%^WHITE%^You manage to escape the worst of the cloud's effects!%^RESET%^");
             damage_targ(obj,obj->return_target_limb(),sdamage/2,element);
        }
        else {
          switch(element) {
            case "acid": tell_object(obj,"%^RESET%^%^GREEN%^You are %^RED%^burned %^GREEN%^by the a%^MAGENTA%^c%^GREEN%^id%^YELLOW%^i%^GREEN%^c %^RESET%^%^CYAN%^vapor%^GREEN%^!%^RESET%^"); break;
            case "cold": tell_object(obj,"%^CYAN%^The chilling smoke bites into your skin, burning at your flesh!%^RESET%^"); break;
            case "electricity": tell_object(obj,"%^ORANGE%^A bolt of lightning arcs from the hazy cloud, jolting you!%^RESET%^"); break;
            case "sonic": tell_object(obj,"%^CYAN%^You are %^BOLD%^%^BLACK%^b%^RESET%^u%^BOLD%^ffet%^RESET%^e%^BOLD%^%^BLACK%^d %^RESET%^%^CYAN%^by the reverberations!%^RESET%^"); break;
            default: tell_object(obj,"%^RED%^The flames scorch your flesh, raising blisters and singeing your hair!%^RESET%^"); break;
          }
          damage_targ(obj,obj->return_target_limb(),sdamage,element);
        }
      break;
      default:
        set_save("reflex");
        if(do_save(obj,0)){
             tell_object(obj,"%^BOLD%^%^WHITE%^You manage to escape the worst of the cloud's effects!%^RESET%^");
             damage_targ(obj,obj->return_target_limb(),sdamage/2,element);
        }
        else {
          switch(element) {
            case "acid": tell_object(obj,"%^BOLD%^%^GREEN%^The sphere of a%^RESET%^%^GREEN%^c%^BOLD%^%^GREEN%^id bursts, splashing you in the %^RESET%^%^GREEN%^se%^BLUE%^a%^GREEN%^ri%^RED%^n%^GREEN%^g %^BOLD%^%^GREEN%^liquid!%^RESET%^"); break;
            case "cold": tell_object(obj,"%^CYAN%^The cloud leaves a rime of frost across your skin, which fragments and snaps painfully!%^RESET%^"); break;
            case "electricity": tell_object(obj,"%^ORANGE%^The cloud emits bursts of static that zap you from every side!%^RESET%^"); break;
            case "sonic": tell_object(obj,"%^BOLD%^%^CYAN%^The %^RESET%^h%^BOLD%^%^BLACK%^a%^RESET%^ze %^BOLD%^%^CYAN%^releases a %^RESET%^%^CYAN%^t%^BOLD%^e%^WHITE%^rrib%^CYAN%^l%^RESET%^%^CYAN%^e s%^BOLD%^c%^WHITE%^ree%^CYAN%^c%^RESET%^%^CYAN%^h%^BOLD%^, %^RED%^r%^BLACK%^i%^WHITE%^p%^RED%^p%^BLACK%^i%^WHITE%^n%^RED%^g %^CYAN%^through you!%^RESET%^"); break;
            default: tell_object(obj,"%^BOLD%^%^RED%^The ball of fl%^YELLOW%^a%^RED%^me%^WHITE%^s%^RED%^ erupts with a horrific %^BLACK%^whoosh%^RED%^, trying to melt the flesh from your bones!%^RESET%^"); break;
          }
          damage_targ(obj,obj->return_target_limb(),sdamage,element);
        }
      break;
   }
   return 1;
}

void dest_effect(){
    if(objectp(place)) tell_room(place,"%^BOLD%^%^BLACK%^The smoke breaks up and disperses.%^RESET%^");
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
