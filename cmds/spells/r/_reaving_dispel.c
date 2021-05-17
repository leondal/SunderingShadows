// Psywarrior dispel - tries to dispel 1 effect per round
//updated by ~Circe~ 10/26/19 to fix bugs and use current code
#include <std.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

object marked,rune;
int charges;

void create(){
    ::create();
    set_author("circe");
    set_spell_name("reaving dispel");
    set_spell_level(([ "psywarrior" : 6, "psion" : 8 ]));
    set_spell_sphere("psychokinesis");
    set_syntax("cast CLASS reaving dispel on TARGET");
    set_description("This power will create a mark on the target that will attempt to dispel one magical effect per round for the duration, causing damage with each succcessful dispel. The duration and power are both based on the psionic character's level.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

int preSpell(){
    if(!objectp(target)){
        tell_object(caster,"This spell requires a target.");
        return 0;
    }
    if(target->query_property("reaving dispel")){
        tell_object(caster,"That target is already under the effect of this power!");
        return 0;
    }
    return 1;
}

void spell_effect(int prof){
   int mylevel;
   if(!present(target,place)){
      tell_object(caster,"Your target has left the area.");
      dest_effect();
      return;
   }
   if(!caster->ok_to_kill(target)) {
      dest_effect();
      return;
   }
   mylevel = clevel;

   tell_object(caster,"%^BOLD%^%^BLUE%^You focus your %^CYAN%^gaze %^BLUE%^on "+target->QCN+" and seek to unravel the m%^CYAN%^a%^BLUE%^gi%^RESET%^c%^BOLD%^%^BLUE%^al pr%^RESET%^o%^BOLD%^%^BLUE%^te%^CYAN%^c%^BLUE%^ti%^RESET%^%^CYAN%^o%^BOLD%^%^BLUE%^ns surrounding "+target->QO+".%^RESET%^");
   tell_object(target,"%^BOLD%^%^BLUE%^"+caster->QCN+"'s eyes flash %^RESET%^s%^BOLD%^i%^RESET%^%^CYAN%^lv%^BOLD%^e%^RESET%^%^CYAN%^r%^RESET%^y %^CYAN%^bl%^BOLD%^u%^RESET%^%^CYAN%^e %^BOLD%^%^BLUE%^as "+caster->QS+" focuses "+caster->QP+" %^CYAN%^gaze %^BLUE%^on you.%^RESET%^");
   tell_room(place,"%^BOLD%^%^BLUE%^"+caster->QCN+"'s eyes flash %^RESET%^s%^BOLD%^i%^RESET%^%^CYAN%^lv%^BOLD%^e%^RESET%^%^CYAN%^r%^RESET%^y %^CYAN%^bl%^BOLD%^u%^RESET%^%^CYAN%^e %^BOLD%^%^BLUE%^as "+caster->QS+" focuses "+caster->QP+" %^CYAN%^gaze %^BLUE%^on "+target->QCN+".%^RESET%^",({caster,target}));
   rune = new("/d/magic/obj/reaving_dispeller.c");
   rune->move(target);
   rune->set_caster(caster);
   rune->set_casting_spell(TO);
   rune->set_clevel(mylevel);
   rune->set_target(target);
   charges = mylevel/8;
   if(charges < 1) charges = 1;
   if(charges > 5) charges = 5;
   rune->set_charges(charges);
   target->set_property("reaving dispel",1);
   rune->dispel_em(target);
   spell_successful();
   spell_kill(target,caster);
   dest_effect();
   return;
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
