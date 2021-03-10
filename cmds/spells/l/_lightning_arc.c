#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>


inherit SPELL;

void create() {
    ::create();
    set_spell_name("lightning arc");
    set_spell_level(([ "mage" : 5, "magus" : 5 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS lightning arc");
    set_damage_desc("electricity");
    set_description("You generate an arc of lightning between at least two targets. It connects between them and causes damage to everything in its path. This spell requires at least two opponents to work. An agile opponent might step out of its way and avoid some of the energy.");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(2);
    set_save("reflex");
}

string query_cast_string() {
    return "%^BOLD%^%^ORANGE%^"+caster->QCN+" points two fingers outwards, an arc of lightning forms between them.";
}

void spell_effect(int prof){
    object *attackers;
    int i,admg;
    attackers = target_selector();

    tell_room(place,"%^BOLD%^%^ORANGE%^"+caster->QCN+" waves hand and releases an arc of electricity!%^RESET%^");
    if(sizeof(attackers)<2)
    {
        tell_object(caster,"%^ORANGE%^The arc flies off but fails to connect to anything.%^RESET%^");
        dest_effect();
        return;
    }

    for(i=0;i<sizeof(attackers);i++)
    {
        if(!objectp(attackers[i]))
            continue;
        admg=sdamage;
        if(do_save(attackers[i]))
        {
            admg/=2;
        }
        tell_object(attackers[i],"%^ORANGE%^%^BOLD%^The %^WHITE%^lightning%^ORANGE%^ burns you!%^RESET%^");
        tell_room(place,"%^ORANGE%^%^BOLD%^The %^WHITE%^lightning%^ORANGE%^ burns "+attackers[i]->QCN+"!%^RESET%^",attackers[i]);
        damage_targ(attackers[i],attackers[i]->return_target_limb(),admg,"electricity");
    }
    spell_successful();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
