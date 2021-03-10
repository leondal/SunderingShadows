#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("sympathetic vibration");
    set_spell_level(([ "bard" : 6 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS sympathetic vibration on TARGET");
    set_description("By attuning yourself to a target you can create damaging vibrations within it, that will last several rounds.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("will");
    set_target_required(1);
}

string query_cast_string()
{
   tell_object(caster,"%^BOLD%^%^MAGENTA%^You spell out a song, sending a faint tremor through the air.");
   tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" spells out a song, and you feel a faint tremor inside you.",caster);
   return "display";
}

void spell_effect(int prof)
{
   tell_object(target,"%^BOLD%^%^MAGENTA%^The song rings inside you with pain!%^RESET%^");
   tell_room(place,"%^BOLD%^%^MAGENTA%^"+target->QCN+" quivers as "+target->QS+" is hit with the song!%^RESET%^",target);

   if(!do_save(target))
       damage_targ(target, target->return_target_limb(), sdamage, "sonic");
   else
   {
       tell_object(target,"%^GREEN%^You steel yourself and shrug off the worst of the pain.%^RESET%^");
       damage_targ(target, target->return_target_limb(), sdamage/2, "sonic");
   }
   spell_successful();
   spell_kill(target,caster);
   if (!target) dest_effect();
   else call_out("second_hit",ROUND_LENGTH);
}

void second_hit()
{
    define_base_damage(-1);
    if(!objectp(target))
    {
        dest_effect();
        return;
    }
    tell_object(target,"%^BOLD%^%^MAGENTA%^Another surge of pain runs through you as the word resonates in your limbs.%^RESET%^");
    tell_object(environment(target),"%^BOLD%^%^MAGENTA%^"+target->QCN+" trembles as the sound continues to wrack "+target->QP+" frame.%^RESET%^",target);
    if(!do_save(target))
        damage_targ(target, target->return_target_limb(), sdamage, "sonic");
    else
    {
        tell_object(target,"%^GREEN%^You steel yourself and shrug off the worst of the pain.%^RESET%^");
        damage_targ(target, target->return_target_limb(), sdamage/2, "sonic");
    }
    if (!target && objectp(TO))
    {
        dest_effect();
        return;
    }
    call_out("last_hit", ROUND_LENGTH);
}

void last_hit()
{
   define_base_damage(-2);    
   if(!objectp(target))
   {
       dest_effect();
       return;
   }
   tell_object(target,"%^BOLD%^%^MAGENTA%^The sound grows to an unbearable pitch, sending a wracking pain through you before it finally fades!%^RESET%^");
   tell_object(environment(target),"%^BOLD%^%^MAGENTA%^"+target->QCN+" is shaken by a wracking pain, before finally the echoes of the word fade.%^RESET%^",target);
   if(!do_save(target))
       damage_targ(target, target->return_target_limb(), sdamage, "sonic");
   else
   {
       tell_object(target,"%^GREEN%^You steel yourself and shrug off the worst of the pain.%^RESET%^");
       damage_targ(target, target->return_target_limb(), sdamage/2, "sonic");
   }
   dest_effect();
}

void dest_effect()
{
    if (find_call_out("second_hit") != -1)
        remove_call_out("second_hit");
    if (find_call_out("last_hit") != -1)
        remove_call_out("last_hit");
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

