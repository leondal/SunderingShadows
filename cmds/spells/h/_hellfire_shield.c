// hellfire warlock port of blade barrier
#include <priest.h>
#include <magic.h>
#include <spell.h>
inherit SPELL;

int timer,flag,stage,toggle,counter;

void create(){
    ::create();
    set_spell_name("hellfire shield");
    set_spell_level(([ "warlock" : 3 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS hellfire shield");
    set_description("This spell surrounds the warlock with a searing barrier of hellfire, which will move with the "
"caster and harm any foes that get too close.  The strength of the flames depends on the level of the caster.\n\n"
"Only a hellfire warlock may harness this invocation.");
    set_property("magic",1);
    set_casting_time(1);
    set_helpful_spell(1);
    traveling_aoe_spell(1);
    set_feats_required(([ "warlock" : "infernal practitioner"]));
}

string query_cast_string(){
    tell_object(caster,"%^BOLD%^%^RED%^Blazing heat floods your veins as you invoke the infernal arts.");
    tell_room(place,"%^BOLD%^%^RED%^"+caster->QCN+"'s eyes blaze with inner fire.",caster);
    return "display";
}

int preSpell(){
    if(caster->query_property("blade barrier")){
        tell_object(caster,"You are already protected by a barrier.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof){
     tell_room(place,"%^BOLD%^%^BLACK%^A sphere of b%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^leful fla%^BOLD%^%^RED%^m%^BOLD%^%^BLACK%^e roars to life around "+caster->QCN+", heat radiating against your skin!%^RESET%^",caster);
    tell_object(caster,"%^BOLD%^%^BLACK%^B%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^leful fla%^BOLD%^%^RED%^m%^BOLD%^%^BLACK%^es roar to life around you, their fury focussed outwards!%^RESET%^");
    caster->set_property("spelled", ({TO}));
    caster->set_property("blade barrier",1);
    caster->set_property("added short",({"%^RED%^ (wreathed in ominous flames)%^RESET%^"}));
    addSpellToCaster();
    spell_successful();
    execute_attack();
    counter = 10 * clevel;
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

    object *attackers,room;
    int i;

    if(!flag)
    {
        flag = 1;
        ::execute_attack();
        return;
    }

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    if(!objectp(ENV(caster)))
    {
        dest_effect();
        return;
    }

    place = ENV(caster);

    if(!objectp(place) || counter<0)
    {
        dest_effect();
        return;
    }

    attackers = caster->query_attackers();

    if(!random(10)){
        tell_room(place,"%^RESET%^%^RED%^"+caster->QCN+"'s blazing shield pulses and surges with radiant energy!",caster);
        tell_object(caster,"%^RESET%^%^RED%^Your blazing shield pulses and surges with radiant energy!");
    }
    if(sizeof(attackers))
    {
        define_base_damage(0);//lazy re-roll
        for(i=0;i<sizeof(attackers);i++){
            if(!objectp(attackers[i])) { continue; }
            tell_object(caster,"%^BOLD%^%^RED%^"+attackers[i]->QCN+" gets a little too close to you, and your hellish shield burns "+attackers[i]->QO+" horribly!");
            tell_room(place,"%^BOLD%^%^RED%^"+attackers[i]->QCN+" gets a little too close to "+caster->QCN+", and the hellish shield burns "+attackers[i]->QO+" horribly!",caster);
            damage_targ(attackers[i],attackers[i]->return_target_limb(),sdamage,"untyped");
        }
    }
    prepend_to_combat_cycle(place);
    counter--;
}

void dest_effect(){
    if(objectp(caster)){
        tell_room(environment(caster),"%^RED%^The infernal shield flickers and vanishes from around "+caster->QCN+".",caster);
        tell_object(caster,"%^RED%^Your infernal shield flickers and then vanishes.");
        caster->remove_property("blade barrier");
	    caster->remove_property_value("added short",({"%^RED%^ (wreathed in ominous flames)%^RESET%^"}));
    }
   ::dest_effect();
   if(objectp(TO)) TO->remove();
}
