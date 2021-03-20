#include <std.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("shadow stream");
    set_spell_level(([ "mage" : 1, "oracle" : 1 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS shadow stream on TARGET");
    set_mystery("darkness");
    set_damage_desc("cold");
    set_description("A twisting stream of inky darkness sprays from your outstretched hand. Any creature caught in the area of the shadows takes cold damage. A Reflex save halves the damage.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    splash_spell(1);
    set_save("reflex");
}


string query_cast_string()
{
    tell_object(caster,"%^BOLD%^%^BLACK%^You can feel a chill growing in the air as you chant.");
    tell_room(place,"%^BOLD%^%^BLACK%^A chilling aura surrounds "+caster->QCN+" as "+caster->QS+" begins to chant.",caster);
    return "display";
}


void spell_effect(int prof)
{
    object *attackers;
    int i, dam;

    attackers = target_selector();

    if(!sizeof(attackers))
    {
        tell_object(caster,"%^BOLD%^%^BLACK%^The area is plunged momentarily into darkness, but nothing else happens.");
        dest_effect();
        return;
    }

    tell_room(place,"%^BOLD%^%^BLACK%^The area is plunged momentarily into utter darkness!%^RESET%^");

    for(i=0;i<sizeof(attackers);i++)
    {
        if(!objectp(attackers[i])) continue;
        tell_object(attackers[i],"%^BOLD%^%^BLACK%^%^The darkness burns with an unnatural chill as it passes over and through you!%^RESET%^");

        dam = sdamage;

        if (do_save(attackers[i], 0)) {
            dam /= 2;
        }

        damage_targ(attackers[i],attackers[i]->return_target_limb(),dam,"cold");
    }

    spell_successful();
    dest_effect();
}


void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
