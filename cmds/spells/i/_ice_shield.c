// ice shield
//Moved down to the low level Cold domain spell in place of
//Frost Breath, which was way too good.  ~Circe~ 5/5/08
//Rebalancing domains
#include <std.h>
#include <priest.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;

void create() {
    ::create();
    set_author("ares");
    set_spell_name("ice shield");
    set_spell_level(([ "cleric" : 4 ]));
    set_spell_sphere("invocation_evocation");
    set_damage_desc("cold, 2 AC");
    set_syntax("cast CLASS ice shield");
    set_description("This spell will protect the caster in a field of bitter cold actic air.  It gives a slight bonus to "
"the caster's armor, additionally, any enemies attacking the caster must make a saving throw or suffer damage from the "
"bitter cold.");
    set_verbal_comp();
    set_save("fort");
    traveling_aoe_spell(1);
    set_helpful_spell(1);
}

int preSpell(){
    if(caster->query_property("ice shield")){
        tell_object(caster,"You are already protected by a shield of ice.");
        return 0;
    }
    return 1;
}

string query_cast_string(){
    tell_object(caster,"%^BOLD%^%^CYAN%^%^Circling your hands before "+
        "you, you begin to chant a frigid prayer.");
    tell_room(place,"%^BOLD%^%^CYAN%^Circling "+caster->QP+" hands "+
        "before "+caster->QO+", "+caster->QCN+" begins to chant "+
        "a frigid prayer.",caster);
    return "display";
}

void spell_effect(int prof){
    int duration;
    duration = (ROUND_LENGTH * 3) * clevel;
    tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" completes "+caster->QP+" prayer and is "
        "encased in a haze of arctic air.",caster);
    tell_object(caster,"%^BOLD%^%^CYAN%^You complete your prayer and are encased in the ice "
        "cold air of the arctic.");
    caster->set_property("ice shield",1);
    caster->set_property("spelled", ({TO}) );
    caster->add_ac_bonus(2);
    caster->add_property("added short",({"%^BOLD%^%^CYAN%^ (enfolded in frost)"}));
    addSpellToCaster();
    spell_successful();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void execute_attack(){
    object *attackers,room;
    int i;

    ::execute_attack();
    if(!objectp(caster)){
        dest_effect();
        return;
    }
    room      = environment(caster);
    attackers = caster->query_attackers();
    attackers = filter_array(attackers,"is_non_immortal",FILTERS_D);
    if(!sizeof(attackers)){
        room->addObjectToCombatCycle(TO,1);
        return;
    }
    for(i=0;i<sizeof(attackers);i++){
        if(!objectp(attackers[i])) { continue; }
        if(do_save(attackers[i],0)) { continue; }
        //if(SAVING_D->saving_throw(attackers[i],"spell",0)) { continue; }
        tell_room(room,"%^BOLD%^"+attackers[i]->QCN+" is chilled by the bitter cold as "
            ""+attackers[i]->QS+" strikes "+caster->QCN+"'s ice shield!",({caster,target}));
        tell_object(caster,"%^BOLD%^"+attackers[i]->QCN+" is chilled by the bitter "
            "cold of the ice shield as "+attackers[i]->QS+" attacks you!");
        tell_object(target,"%^BOLD%^You are chilled by the bitter cold of the ice "
            "shield as you attack "+caster->QCN+"!");
        define_base_damage(0);
        damage_targ(attackers[i],attackers[i]->return_target_limb(),sdamage,"cold");
    }
    room->addObjectToCombatCycle(TO,1);
}

void dest_effect(){
    if(objectp(caster)){
        tell_object(caster,"%^BOLD%^%^CYAN%^The shield of bitter cold air fades away, leaving "
            "you vulnerable once again.");
        tell_room(environment(caster),"%^BOLD%^%^CYAN%^The shield of bitter cold air surrounding "
            ""+caster->QCN+" fades away, leaving "+caster->QP+" vulnerable once "
            "again.",caster);
        caster->remove_property("ice shield");
        caster->add_ac_bonus(-2);
	    caster->remove_property_value("added short",({"%^BOLD%^%^CYAN%^ (enfolded in frost)"}));
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
