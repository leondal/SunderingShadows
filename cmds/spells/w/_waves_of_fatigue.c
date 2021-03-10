#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>


inherit SPELL;

void create() {
    ::create();
    set_spell_name("waves of fatigue");
    set_spell_level(([ "mage" : 5,"cleric":5,"warlock" : 3 ]));
    set_domains("renewal");
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS waves of fatigue");
    set_damage_desc("living creatures become fatigued");
    set_description("This spell sends waves of necrotic energy at everyone living in sight, fatiguing them.");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(3);
    set_feats_required(([ "warlock" : "tome of ancient secrets"]));
}

string query_cast_string() {
    return "%^BLUE%^"+caster->QCN+" spells an incantation in eldritch tongue.";
}

void spell_effect(int prof){
    object *attackers;
    int i,admg;
    attackers = target_selector();

    tell_room(place,"%^BOLD%^%^BLACK%^"+caster->QCN+" raises hand and releases waves of darkness!%^RESET%^");
    if(!sizeof(attackers)){
        tell_object(caster,"%^BOLD%^%^BLACK%^The area is washed in fell waves but nothing else happens.%^RESET%^");
        dest_effect();
        return;
    }

    for(i=0;i<sizeof(attackers);i++)
    {
        if(!objectp(attackers[i]))
            continue;
        "/std/effect/status/fatigued"->apply_effect(attackers[i],clevel/14+1);
    }
    spell_successful();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
