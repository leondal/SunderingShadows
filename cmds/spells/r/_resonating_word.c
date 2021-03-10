#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>
inherit SPELL;

void second_hit();
void last_hit();

void create(){
    ::create();
    set_author("nienne");
    set_spell_name("resonating word");
    set_spell_level(([ "bard" : 5, "mage" : 7 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS resonating word on TARGET");
    set_damage_desc("sonic");
    set_description("The caster uses a word of power to cause potentially lethal vibrations in the chosen target. Its effects "
"are only subtle to begin with, but quickly become destructive. Those with a greater degree of fortitude may be able to "
"withstand the worst of its effects.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("fort");
    set_target_required(1);
}

string query_cast_string(){
   tell_object(caster,"%^BOLD%^%^CYAN%^You give voice to a word of power, sending a faint tremor through the air.");
   tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" gives voice to a word of power, and you feel a faint tremor "
"touch the air around you.",caster);
   return "display";
}

void spell_effect(int prof){

   if (!present(target,environment(caster))) {
       tell_object(caster,"%^BOLD%^%^WHITE%^Your target is not in this area.");
       TO->remove();
       return;
   }

   tell_object(target,"%^BOLD%^%^GREEN%^The word rings painfully in your ears, and your body quivers!%^RESET%^");
   tell_room(place,"%^BOLD%^%^GREEN%^"+target->QCN+" quivers as "+target->QS+" is hit with the power of the word!%^RESET%^",target);

   if(!do_save(target))
       damage_targ(target, target->return_target_limb(), sdamage, "sonic");
   else {
       tell_object(target,"%^GREEN%^You steel yourself and shrug off the worst of the pain.%^RESET%^");
       damage_targ(target, target->return_target_limb(), sdamage/2, "sonic");
   }
   spell_successful();
   spell_kill(target,caster);
   if (!target) dest_effect();
   else call_out("second_hit",ROUND_LENGTH);
}

void second_hit() {
    define_base_damage(-1);
   if(!objectp(target)) {
       dest_effect();
       return;
   }
   tell_object(target,"%^BOLD%^%^GREEN%^Another surge of pain runs through you as the word resonates in your ears and echoes through your limbs.%^RESET%^");
   tell_object(environment(target),"%^BOLD%^%^GREEN%^"+target->QCN+" trembles as the sound continues to wrack "+target->QP+" frame.%^RESET%^",target);
   if(!do_save(target))
       damage_targ(target, target->return_target_limb(), sdamage, "sonic");
   else {
       tell_object(target,"%^GREEN%^You steel yourself and shrug off the worst of the pain.%^RESET%^");
       damage_targ(target, target->return_target_limb(), sdamage/2, "sonic");
   }
   if (!target && objectp(TO)) {
       dest_effect();
       return;
   }
   call_out("last_hit", ROUND_LENGTH);
}

void last_hit() {
   define_base_damage(-3);
   if(!objectp(target)) {
       dest_effect();
       return;
   }
   tell_object(target,"%^BOLD%^%^GREEN%^The sound grows to an unbearable pitch, sending a wracking pain through you before it finally fades!%^RESET%^");
   tell_object(environment(target),"%^BOLD%^%^GREEN%^"+target->QCN+" is shaken by a wracking pain, before finally the echoes of the word fade.%^RESET%^",target);
   if(!do_save(target))
       damage_targ(target, target->return_target_limb(), sdamage, "sonic");
   else {
       tell_object(target,"%^GREEN%^You steel yourself and shrug off the worst of the pain.%^RESET%^");
       damage_targ(target, target->return_target_limb(), sdamage/2, "sonic");
   }
   dest_effect();
}

void dest_effect(){
    if (find_call_out("second_hit") != -1) remove_call_out("second_hit");
    if (find_call_out("last_hit") != -1) remove_call_out("last_hit");
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
