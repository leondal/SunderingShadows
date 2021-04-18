#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>


inherit SPELL;

void create() {
    ::create();
    set_spell_name("waves of ecstasy");
    set_spell_level(([ "mage" : 7, "cleric" : 7, "bard" : 6 ]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS waves of ecstasy");
    set_damage_desc("living creatures are stunned on failed save. staggered on successful save.");
    set_description("This spell sends waves of intense pleasure that causes all within range to falter. Affected creatures are stunned rounds on a failed save, or staggered for one round on a successful save.");
    set_save("will");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(3);
}

string query_cast_string() {
    return "%^BLUE%^"+caster->QCN+" spells an incantation in an eldritch tongue.";
}

void spell_effect(int prof){
    object *attackers;
    object stun, stagger;
    int i,admg;
    attackers = target_selector();

    tell_room(place, "%^BOLD%^%^MAGENTA%^" + caster->QCN + " raises a hand and releases waves of pure ecstasy!%^RESET%^");
    if (!sizeof(attackers)) {
        tell_object(caster, "%^BOLD%^%^MAGENTA%^The area is washed in waves of ecstasy, but nothing happens.%^RESET%^");
        dest_effect();
        return;
    }
    
    stagger = find_object("/std/effect/status/staggered.c");
    
    foreach(object ob in attackers)
    {
        if(do_save(ob, 0))
        {
            if(objectp(stagger))
            {
                stagger->apply_effect(ob, 1);
                tell_object(ob, "You manage to shrug off the majority of the wave of ecstasy.");
                tell_object(caster, ob->QCN + " manages to shrug off the majority of the wave of ecstasy.");
            }
        }
        else
        {
            ob->set_paralyzed(roll_dice(4, 6), "%^MAGENTA%^BOLD%^You are too overcome with ecstasy!%^RESET%^");
            tell_room(place, "%^MAGENTA%^BOLD%^" + ob->QCN + " is overcome with ecstasy!%^RESET%^", ({ ob }));
            tell_object(ob, "%^MAGENTA%^BOLD%^You are overcome with ecstasy!%^RESET%^");
        }
    }

    spell_successful();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
