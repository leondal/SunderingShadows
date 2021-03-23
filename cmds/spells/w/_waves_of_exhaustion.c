#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>


inherit SPELL;

void create() {
    ::create();
    set_spell_name("waves of exhaustion");
    set_spell_level(([ "mage" : 7, "cleric" : 7 ]));
    set_mystery("bones");
    set_domains(({"repose"}));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS waves of exhaustion");
    set_damage_desc("living creatures become exhausted");
    set_description("This spell sends waves of necrotic energy at everyone living in sight, exhausting them.");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(3);
}

string query_cast_string() {
    return "%^BLUE%^"+caster->QCN+" spells an incantation in an eldritch tongue.";
}

void spell_effect(int prof){
    object *attackers;
    int i,admg;
    attackers = target_selector();

    tell_room(place, "%^BOLD%^%^BLACK%^" + caster->QCN + " raises a hand and releases waves of darkness!%^RESET%^");
    if (!sizeof(attackers)) {
        tell_object(caster, "%^BOLD%^%^BLACK%^The area is washed in fell waves but nothing else happens.%^RESET%^");
        dest_effect();
        return;
    }

    for (i = 0; i < sizeof(attackers); i++) {
        if (!objectp(attackers[i])) {
            continue;
        }
        "/std/effect/status/exhausted"->apply_effect(attackers[i], clevel / 14 + 1);
    }
    spell_successful();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
