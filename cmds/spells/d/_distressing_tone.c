#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>


inherit SPELL;

void create() {
    ::create();
    set_spell_name("distressing tone");
    set_spell_level(([ "bard" : 2, "inquisitor" : 2,]));
    set_domains("strength");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS distressing tone");
    set_damage_desc("mass sickening");
    set_description("You hum a low tone that makes everyone present briefly sickened.");
    set_save("fort");
    splash_spell(3);
}

void spell_effect(int prof){
    object *attackers;
    int i,admg;
    attackers = target_selector();


    if(!sizeof(attackers)){
        tell_object(caster,"%^CYAN%^The tonal vibrations do not affect anyone.%^RESET%^");
        dest_effect();
        return;
    }

    tell_room(place,"%^CYAN%^A sickening low tone hits everyone present.%^RESET%^");

    for(i=0;i<sizeof(attackers);i++)
    {
        if(!objectp(attackers[i]))
            continue;
        if(!do_save(attackers[i],2))
            "/std/effect/status/sickened"->apply_effect(attackers[i],clevel/6 + 1);
    }
    spell_successful();
}
