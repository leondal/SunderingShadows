// Reskin of Web

#include <spell.h>
#include <magic.h>

inherit SPELL;

object oldenv, web, mass;
int waittime;

void dest_effect();
void waiter(int num);

create() {
    ::create();
    set_spell_name("cocoon of refuse");
    set_spell_level(([ "warlock" : 1 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS cocoon of refuse on TARGET");
    set_damage_desc("tripped for 1d8 rounds");
    set_description("With this spell, the caster causes all loose material in the area to cling to the target, hampering their movement greatly and causing them to trip.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("reflex");
    set_feats_required(([ "warlock" : "tome of ancient secrets"]));
}

string query_cast_string() {
    return caster->QCN+" %^BOLD%^%^BLACK%^puts their hands together where e%^RESET%^%^GREEN%^l%^BOLD%^d%^RESET%^r%^BOLD%^i%^BLACK%^tch e%^RESET%^%^GREEN%^n%^BOLD%^e%^RESET%^r%^BOLD%^g%^BLACK%^y f%^RESET%^%^GREEN%^o%^BOLD%^r%^RESET%^m%^BOLD%^s%^BLACK%^.%^RESET%^.";
}

spell_effect(int prof) {
    int save, neededroll, power;
    string strength;
    tell_object(caster,"You release the e%^RESET%^%^GREEN%^n%^BOLD%^e%^RESET%^r%^BOLD%^g%^BLACK%^y and the loose material around you begins to swirl around%^RESET%^ "+target->QCN+"!");
    tell_object(target,"%^YELLOW%^"+caster->QCN+" releases "+caster->QP+" dark energy and the loose debris in the area begins to swirl around you!");
    tell_room(place,"%^YELLOW%^"+caster->QCN+" releases "+caster->QP+" dark energy and the loose debris in the area begins to spin around "+target->QCN+"!", ({caster, target}) );
    if ( do_save(target,-2)) {
        tell_object(caster,"%^BOLD%^%^RED%^"+target->QCN+" manages to slip away from your cocoon of refuse!");
        tell_object(target,"%^BOLD%^%^RED%^You manage to slip away from the swirling material!");
        tell_room(environment(caster),"%^BOLD%^%^RED%^"+target->QCN+" manages to slip away from the swirling material!",({caster, target}) );
        dest_effect();
        return;
    } else {
        strength="heavily encase";
        spell_successful();
        tell_object(caster,"%^BOLD%^%^RED%^Your cocoon of refuse "+strength+" "+target->QCN+" trapping "+target->QP+" body!");
        tell_object(target,"%^BOLD%^%^RED%^"+caster->QCN+"'s cocoon of debris "+strength+" you, trapping your body!");
        tell_room(place,"%^BOLD%^%^RED%^"+caster->QCN+"'s cocoon of debris "+strength+" "+target->QCN+" trapping "+target->QP+" body!", ({caster,target}) );
        target->set_tripped(roll_dice(1,8));
    }
}
