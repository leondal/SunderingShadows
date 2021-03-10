#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("sonic orb");
    set_spell_level(([ "mage" : 3 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS sonic orb on TARGET");
    set_description("This spell allows a mage to to create an orb of pure sonic energy.  Once the orb is launched into the air, the first thing it strikes will cause it to burst "
        "open, releasing cacaphonic sounds on the mage's foes.  Though care should be taken as it is possible to accidently catch the "
        "mages allies in the blast.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    splash_spell(1);
    set_save("reflex");
    set_immunities( ({"sound"}) );
}


string query_cast_string() { return "%^BOLD%^%^CYAN%^"+caster->QCN+" chants rapidly, creating a sound orb in "+caster->QP+" hand."; }


spell_effect(int prof)
{
    object *foes = ({});
    string YOU,HIM,tmp = "";
    int i;

    if(!present(target, (caster->is_room()) ? (caster) : (place) ))
    {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        dest_effect();
        return;
    }

    spell_successful();

    YOU=caster->QCN;
    HIM=target->QCN;

    foes = target_selector();

    foes -= ({ target });

    if(interactive(caster)) { tmp="'s finger"; }

    tell_object(target,"%^BOLD%^%^CYAN%^An orb of sound speeds through the air from "+YOU+tmp+", heading straight for you!");
    tell_object(caster,"%^BOLD%^%^CYAN%^An orb of sound speeds through the air from your hand, heading straight for "+HIM+"!");
    tell_room(place, "%^BOLD%^%^CYAN%^An orb of sound speeds through the air from "+YOU+tmp+", heading straight for "+HIM+"!",({ caster, target}) );

    tell_object(target,"%^BOLD%^%^WHITE%^The sonic orb explodes as it hits you!",target);
    tell_room(environment(target),"%^BOLD%^%^WHITE%^The sonic orb explodes as it hits "+target->QCN+"!",target);

    if(!do_save(target)) { damage_targ(target, "torso", sdamage / 2, "sonic" ); }
    else { damage_targ(target, "torso", sdamage / 2, "acid" ); }

    for(i=0;sizeof(foes),i<sizeof(foes);i++)
    {
        if(!objectp(foes[i])) { continue; }

        if(!do_save(foes[i]))
        {
            tell_room(environment(foes[i]),"%^BOLD%^%^BLUE%^Sound catches "+foes[i]->QCN+"!",foes[i]);
            tell_object(foes[i],"%^BOLD%^%^BLUE%^Your flesh is resonating with the sound!");
            damage_targ(foes[i], "torso", sdamage, "sonic" );
            continue;
        }

        tell_room(environment(foes[i]),"%^BOLD%^%^GREEN%^Sound catches "+foes[i]->QCN+"!",foes[i]);
        tell_object(foes[i],"%^BOLD%^%^GREEN%^Your flesh is resonating with the sound!");
        damage_targ(foes[i], "torso", sdamage / 2, "sonic");
    }

    dest_effect();
    return;
}


void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
