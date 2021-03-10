// Rusting Grasp
// Coded for druids by ~Circe~ 3/23/13
// Based on Disintigrate by Ares
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

void damage_stuff(object target);
int object_save(object obj);

void create() {
    ::create();
    set_author("circe");
    set_spell_name("rusting grasp");
    set_spell_level(([ "druid" : 4 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS rusting grasp on TARGET");
    set_description("The caster of this spell invokes the power of "
       "nature to rust metal and cause some damage to the target.  "
       "If the target resists, then he is able to avoid most of the "
       "damage, but if the spell hits successfully, then the target "
       "suffers some damage and any metal objects in his inventory "
       "may also be damaged.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("fort");
}

string query_cast_string(){
    tell_object(caster,"%^CYAN%^You feel the unyielding power of nature "
       "as you murmur your incantation.%^RESET%^");
    tell_room(place,"%^CYAN%^"+caster->QCN+"'s eyes flash %^GREEN%^green%^CYAN%^ "
       "as "+caster->QS+" murmurs an incantation.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof){
    int check, damage;

    if(!present(target,place)){
        tell_object(caster,""+target->QCN+" has left the area!");
        dest_effect();
        return;
    }

    tell_object(caster,"%^GREEN%^Your fingertips tingle with the unbound energy "
       "of the elements as you unleash nature's fury on "+target->QCN+"!%^RESET%^");
    tell_object(target,"%^GREEN%^A wave of natural energy blasts into you as "
       ""+caster->QCN+" completes "+caster->QP+" incantation!%^RESET%^");
    tell_room(place,"%^GREEN%^A wave of natural energy blasts into "+target->QCN+" as "
       ""+caster->QCN+" completes "+caster->QP+" incantation!%^RESET%^",({caster,target}));

    if(random((int)target->query_stats("dexterity") + 1) < roll_dice(1,20)) { check = 1; }
    else { check = 0; }

    if(!do_save(target)){
        tell_object(caster,"%^BOLD%^%^GREEN%^"+target->QCN+" is blasted by the full force of nature's wrath!%^RESET%^");
        tell_object(target,"%^BOLD%^%^GREEN%^The full force of nature's wrath unleashed by "+caster->QCN+" slams into you!%^RESET%^");
        tell_room(place,"%^BOLD%^%^GREEN%^"+target->QCN+" is unable to move in time and is hit with the "
            "full destructive power of "+caster->QCN+"'s spell!%^RESET%^",({target,caster}));
        damage_stuff(target);
        damage = sdamage;
    }else{
        tell_object(caster,"%^CYAN%^"+target->QCN+" dodges at the last "
            "second, narrowly avoiding the full power of your spell!%^RESET%^");
        tell_object(target,"%^CYAN%^You manage to dodge aside at the last instant, avoiding the "
            "full power of the destructive spell!%^RESET%^");
        tell_room(place,"%^CYAN%^"+target->QCN+" manages to dodge aside at the last instant, "
            "avoiding the full power of the destructive spell!%^RESET%^",({target,caster}));
        damage = sdamage/2;
    }
    damage_targ(target,target->return_target_limb(),damage,"acid");
    spell_kill(target,caster);
    spell_successful();
    dest_effect();
}

void damage_stuff(object target){
    object *stuff;
    int i;

    if(!objectp(target)) { return; }
    stuff = all_inventory(target);
    if(!sizeof(stuff)) { return; }
    
    for(i=0;i<sizeof(stuff);i++){
        if(object_save(stuff[i])) { continue; }
        if(!stuff[i]->is_metal()) { continue; }
        tell_object(target,"%^ORANGE%^"+(string)stuff[i]->query_short()+" "
           "begins to rust as it is struck by the destructive spell!%^RESET%^");
        stuff[i]->repairMe(roll_dice(1,6));
    }
}

// gives the stuff in inventory a save based on enchantment
int object_save(object obj)
{
    int enchantment;
    if(!objectp(obj)) { return 1; }
    enchantment = (int)obj->query_property("enchantment");
    if(!enchantment) { enchantment = obj->isMagic(); }
    if((roll_dice(1,20) + enchantment) < roll_dice(1,20)) { return 0;}
    return 1;
}

void dest_effect() 
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
