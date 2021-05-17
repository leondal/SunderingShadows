#include <std.h>
#include <magic.h>
inherit SPELL;

int lower;

void create() {
    ::create();
    set_spell_name("power resistance");
    set_spell_level(([ "psion" : 5, "psywarrior" : 5 ]));
    set_spell_sphere("psychokinesis");
    set_syntax("cast CLASS power resistance on TARGET");
    set_description("Using this power will allow a psion to temporarily raise the power resistance of "
"the target.  After a time, the power will reverse, restoring the creature to its original resistance.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_helpful_spell(1);
}

string query_cast_string() {
    return "%^GREEN%^"+caster->QCN+" focuses on a prism of jade, seeming "+
       "to look through it.";
}

int preSpell(){
    if(!target){
        tell_object(caster,"You have no target.");
        return 0;
    }
    if(target->query_property("raised spell damage resistance")){
        tell_object(caster,"%^BOLD%^The power is repelled forcibly.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    if (!objectp(caster)) return;
    if(!objectp(target))
    {
        tell_object(caster,"You don't see that target here!");
        return;
    }
    tell_room(place,"%^BOLD%^%^GREEN%^The jade held by "+
        ""+caster->QCN+" begins to glow before a power "+
        "suddenly spreads from it, blanketing "+target->QCN+"!",({caster,target}));
    if(target == caster){
        tell_object(caster,"%^BOLD%^%^GREEN%^The jade in "+
        "your hand begins to glow with power before "+
        "it suddenly spreads over you!");
    }
    else{
        tell_object(caster,"%^BOLD%^%^GREEN%^The jade in "+
            "your hand begins to glow with power before "+
            "it suddenly spreads over "+target->QCN+"!");
        tell_object(target,"%^BOLD%^%^GREEN%^The jade "+
            "held by "+caster->QCN+" begins to glow "+
            "before the power suddenly spreads over "+
            "you, wrapping you in warmth!");
    }
    lower = clevel / 3;
    target->set_property("spell damage resistance",lower);
    target->set_property("raised spell damage resistance",1);
    addSpellToCaster();
    spell_successful();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 2;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect(){
    if(objectp(target))
    {
        target->set_property("spell damage resistance",(-1*lower));
        target->remove_property("raised spell damage resistance");
        tell_room(environment(target),"%^GREEN%^A wave of energy suddenly "+
        "rushes out from "+target->QCN+".",target);
        tell_object(target,"%^GREEN%^A wave of power suddenly leaves you!");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
