// Chill Metal
// Coded by ~Circe~ 3/21/13 for druids
// Code based in part on Disintegrate

#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

int object_save(object obj);

void create() {
    ::create();
    set_author("circe");
    set_spell_name("chill metal");
    set_spell_level(([ "druid" : 2 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS chill metal on TARGET");
    set_description("Upon casting this spell, the caster sends forth "
       "a blasting cold, chilling any metal worn by the target.  For "
       "each item that fails its saving throw, the target takes damage "
       "based on the weight of the object.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

string query_cast_string(){
    tell_object(caster,"%^RESET%^%^CYAN%^You reach out your hand, "
       "feeling the %^BOLD%^chill %^RESET%^%^CYAN%^of winter in your fingertips.%^RESET%^");
    tell_room(place,"%^RESET%^%^CYAN%^"+caster->QCN+" reaches out "
       ""+caster->QP+" hand as a %^BOLD%^chill breeze %^RESET%^%^CYAN%^"
       "whips the air.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof){
    int check, damage, objdamage, i;
    object *stuff;

    if(!present(target,place)){
        tell_object(caster,""+target->QCN+" has left the area!");
        dest_effect();
        return;
    }

    tell_object(caster,"%^BOLD%^%^CYAN%^The fury of winter bursts forth as you point at "
       ""+target->QCN+", attempting to freeze "+target->QO+"!%^RESET%^");
    tell_object(target,"%^BOLD%^%^CYAN%^"+caster->QCN+" points at you, and "
       "a burst of freezing wind blasts into you!%^RESET%^");
    tell_room(place,"%^BOLD%^%^CYAN%^A frigid wind blasts the area as "+caster->QCN+" "
        "points at "+target->QCN+"!%^RESET%^",({caster,target}));
    stuff = all_inventory(target);
    if(!sizeof(stuff)) {
       tell_object(target,"%^BOLD%^The wind chills you but otherwise has no effect!%^RESET%^");
       dest_effect();
       return; 
    }
    for(i=0;i<sizeof(stuff);i++){
        if(object_save(stuff[i])) { continue; }
        if(!stuff[i]->is_metal()) { continue; }
        objdamage = ((int)stuff[i]->query_weight()/5)+2;
        damage += roll_dice(objdamage,(clevel/2));
        check++;
    }
    if(check){
        tell_object(target,"%^BOLD%^%^WHITE%^The metal you are wearing "
           "freezes your skin, chilling you to the bone!%^RESET%^");
        tell_object(caster,"%^BOLD%^%^WHITE%^"+target->QCN+" shivers "
           "under the force of your spell!%^RESET%^");
        damage_targ(target,target->return_target_limb(),damage,"cold");
    }else{
       tell_object(target,"%^BOLD%^The wind chills you but otherwise has no effect!%^RESET%^");
    }
    spell_kill(target,caster);
    spell_successful();
    dest_effect();
}

int object_save(object obj){
    int enchantment;
    if(!objectp(obj)) { return 1; }
    enchantment = (int)obj->query_property("enchantment");
    if(!enchantment) { enchantment = obj->isMagic(); }
    if((roll_dice(1,20) + enchantment) < roll_dice(1,20)) { return 0;}
    return 1;
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}