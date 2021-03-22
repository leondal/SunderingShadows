// sunburst equiv for shadow adept (since sunburst is very clearly not appropriate to use with this feat)
#include <std.h>
#include <daemons.h>

inherit SPELL;


void create()
{
    ::create();
    set_author("nienne");
    set_spell_name("shadow nova");
    set_spell_level(([ "mage" : 9 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS shadow nova");
    set_damage_desc("untyped");
    set_description("This spell will send a burst of pure darkness out in a circle from the caster.  Any enemies "
        "caught in the area will suffer damage from the shadowy energy.  Those creatures who fail their save will find that "
        "the darkness also steals away their vision temporarily.

%^BOLD%^%^RED%^See also:%^RESET%^ status effects");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(2);
    set_save("reflex");
    set_feats_required(([ "mage" : "gift of the shadows"]));
}


string query_cast_string()
{
    tell_object(caster,"%^BOLD%^%^CYAN%^You can feel a chill growing in the air as you chant.");
    tell_room(place,"%^BOLD%^%^CYAN%^A chilling aura surrounds "+caster->QCN+" as "+caster->QS+" begins to chant.",caster);
    return "display";
}


void spell_effect(int prof)
{
    object *attackers;
    int i;

    attackers = target_selector();

    if(!sizeof(attackers))
    {
        tell_object(caster,"%^MAGENTA%^The area is plunged momentarily into darkness, but nothing else happens.");
        dest_effect();
        return;
    }

    tell_room(place,"%^MAGENTA%^The area is plunged momentarily into utter darkness!%^RESET%^");

    for(i=0;i<sizeof(attackers);i++)
    {
        if(!objectp(attackers[i])) continue;
        if(!do_save(attackers[i],0))
        {
            tell_object(attackers[i],"%^BOLD%^You blink several times, but complete darkness remains across your vision!%^RESET%^");
            attackers[i]->set_temporary_blinded(1);
        }
        tell_object(attackers[i],"%^BOLD%^%^CYAN%^The darkness burns with an unnatural chill as it passes over and through you!%^RESET%^");
        damage_targ(attackers[i],attackers[i]->return_target_limb(),sdamage,"untyped");
    }

    spell_successful();
    dest_effect();
}


void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
