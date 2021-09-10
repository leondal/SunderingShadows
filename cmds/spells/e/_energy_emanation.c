#include <std.h>
#include <priest.h>

inherit SPELL;
int counter, extra, flag;
string myenergy, mycolor;

void create() {
    ::create();
    set_spell_name("energy emanation");
    set_spell_level( ([ "psywarrior" : 2, "psion" : 2 ]) );
    set_spell_sphere("psychokinesis");
    set_discipline("kineticist");
    set_syntax("cast CLASS energy emanation [on cold|electricity|fire|sonic]");
    set_description("This power surrounds the psionic character in a glowing "
       "halo of energy that lashes out at all those nearby. The amount of damage "
       "grows with the manifester, and she can learn to control it better through "
       "feats like Perfect Caster. Upon manifesting the power, the psionic character "
       "chooses the energy type - cold, electricity, fire, or sonic. If no type is "
       "designated, one will be chosen randomly.");
    set_verbal_comp();
    set_arg_needed();
    traveling_aoe_spell(1);
}

string query_cast_string() {
   return "%^BOLD%^%^WHITE%^The air around "+caster->QCN+" %^BOLD%^%^WHITE%^begins to glow faintly.%^RESET%^";

}

int preSpell() {
    if (caster->query_property("energy_emanated")) {
      tell_object(caster,"You are already under the effects of this power!");
        return 0;
    }
    return 1;
}


void spell_effect(int prof){
   if(!objectp(caster)){
      dest_effect();
      return;
   }
   if(!arg){
      switch(random(4)){
         case 0: arg = "cold";
                 break;
         case 1: arg = "electricity";
                 break;
         case 2: arg = "fire";
                 break;
         default: arg = "sonic";
                  break;
      }
   }
   switch(arg){
      case "cold": myenergy = "%^RESET%^%^CYAN%^c%^BOLD%^o%^RESET%^%^CYAN%^ld";
                   mycolor = "an %^RESET%^%^CYAN%^i%^BOLD%^c%^RESET%^%^CYAN%^y "
                      "bl%^BOLD%^u%^RESET%^%^CYAN%^e";
                   break;
      case "electricity": myenergy = "%^YELLOW%^el%^WHITE%^e%^YELLOW%^ctr"
                             "%^RESET%^%^ORANGE%^i%^YELLOW%^city";
                          mycolor = "a %^YELLOW%^go%^RESET%^%^ORANGE%^l%^YELLOW%^d"
                             "%^WHITE%^e%^YELLOW%^n y%^WHITE%^e%^YELLOW%^ll"
                             "%^RESET%^%^ORANGE%^o%^YELLOW%^w";
                          break;
      case "fire": myenergy = "%^RESET%^%^RED%^fi%^BOLD%^r%^RESET%^%^RED%^e";
                   mycolor = "a %^RESET%^%^RED%^sm%^BOLD%^o%^RESET%^%^RED%^lde"
                      "%^BOLD%^r%^RESET%^%^RED%^ing r%^BOLD%^e%^RESET%^%^RED%^d";
                   break;
      default: myenergy = "%^BOLD%^%^WHITE%^s%^CYAN%^o%^WHITE%^n%^BLUE%^i%^WHITE%^c";
                    mycolor = "an %^BOLD%^%^WHITE%^i%^CYAN%^r%^WHITE%^ide%^BLUE%^s"
                       "%^WHITE%^ce%^MAGENTA%^n%^WHITE%^t";
                    break;
   }
   tell_room(place,"%^BOLD%^%^WHITE%^The aura surrounding "+caster->QCN+" %^BOLD%^"
      "%^WHITE%^brightens and takes on "+mycolor+" hue %^BOLD%^%^WHITE%^as it emanates "
      ""+myenergy+" energy%^BOLD%^%^WHITE%^!%^RESET%^",caster);
   tell_object(caster,"%^BOLD%^%^WHITE%^The aura surrounding you brightens and takes "
      "on "+mycolor+" hue %^BOLD%^%^WHITE%^as it emanates "+myenergy+" energy%^BOLD%^%^WHITE%^!%^RESET%^");
   caster->set_property("energy_emanated",1);
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
   int i, done;
   object *ppl = ({}), *enemies = ({});
   if(!flag) {
      ::execute_attack();
      flag = 1;
      return;
   }
   if(!objectp(caster)) {
      dest_effect();
      return;
   }
   ppl = caster->query_attackers();
   ppl = filter_array(ppl, "is_non_immortal",FILTERS_D);
   if(member_array(caster,ppl) != -1){
      ppl -= ({caster});
   }
   ppl = target_filter(ppl);

   ppl = distinct_array(ppl);
   enemies += caster->query_attackers();
   enemies = distinct_array(enemies);
   if(sizeof(ppl))
   {
      done = 0;
      define_base_damage(0);

      tell_object(caster,"%^BOLD%^%^WHITE%^The halo of "+myenergy+" energy "
                  "%^BOLD%^%^WHITE%^surrounding you lashes out at your enemies!%^RESET%^");
      tell_room(place,"%^BOLD%^%^WHITE%^The halo of "+myenergy+" energy "
                "%^BOLD%^%^WHITE%^surrounding "+caster->QCN+" lashes out at "+caster->QP+" enemies!%^RESET%^",({caster,ppl[i]}));

      for(i=0;i<sizeof(ppl);i++)
      {

         if(!objectp(ppl[i])) continue;
         tell_object(ppl[i],"%^BOLD%^%^WHITE%^The halo of "+myenergy+" energy "
            "%^BOLD%^%^WHITE%^surrounding "+caster->QCN+" lashes out at you!%^RESET%^");
         do_spell_damage(ppl[i],ppl[i]->return_target_limb(),sdamage,arg);
         if(member_array(ppl[i],enemies) == -1)
         {
            spell_kill(ppl[i],caster);
         }
         done++;
      }
   }
   else
   {
       tell_object(caster,"%^BOLD%^%^WHITE%^The halo of "+myenergy+" energy "
       "%^BOLD%^%^WHITE%^surrounding you crackles as if seeking out a target!%^RESET%^");
   }
   counter++;
   if (counter > (clevel * 6))
   {
        dest_effect();
        return;
   }
   else
       environment(caster)->addObjectToCombatCycle(TO,1);
}

void dest_effect(){
    remove_call_out("room_check");
    if(objectp(caster)){
       tell_object(caster,"%^ORANGE%^You feel the energy drain from you.");
       tell_room(environment(caster),"%^ORANGE%^The field of energy "+
          "surrounding "+caster->QCN+" fades away.",caster);
       caster->remove_property("energy_emanated");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
