#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("quench");
    set_spell_level(([ "druid" : 3 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS quench on TARGET");
    set_description("This spell creates a large sphere of water that smashes into targets in the area.  The force of the "
        "impact accounts for half of the destruction in the target area, water damage accounts for the other half.  ");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_immunities( ({"water"}) );
    set_save("reflex");
    splash_spell(1);
}

string query_cast_string()
{
    return "%^RESET%^%^BOLD%^"+caster->QCN+" raises an outstretched hand towards "+target->QCN+" and begins to growl under "+caster->QP+" breath.%^RESET%^";
}

spell_effect(int prof)
{
    object etp,*foes=({});
    int i;

    if(!objectp(etp = environment(caster)))
    {
        dest_effect();
        return;
    }

    if(!present(target,etp))
    {
        tell_object(caster,"%^RESET%^%^YELLOW%^Your target has left the area.%^RESET%^");
        dest_effect();
        return;
    }

    spell_successful();

    foes = target_selector();
    foes -= ({ caster });

    tell_object(caster,"%^BOLD%^%^BLUE%^You release the energy of your spell and send a huge ball of water hurling at "+target->QCN+"!%^RESET%^");
    tell_object(target,"%^BOLD%^%^BLUE%^"+caster->QCN+" releases the energy of "+caster->QP+" spell and sends a huge ball of water hurling at you!%^RESET%^");
    tell_room(etp,"%^BOLD%^%^BLUE%^"+caster->QCN+" releases the energy of "+caster->QP+" spell and sends a huge ball of water hurling at "+target->QCN+"!%^RESET%^",({target,caster}));

    tell_object(caster,"%^CYAN%^Your ball of water explodes in a torrent as it %^RESET%^%^BOLD%^smashes%^RESET%^%^CYAN%^ into "+target->QCN+"!%^RESET%^");
    tell_object(target,"%^CYAN%^"+caster->QCN+"'s ball of water explodes in a torrent as it %^RESET%^%^BOLD%^smashes%^RESET%^%^CYAN%^ into you!%^RESET%^");
    tell_room(etp,"%^CYAN%^"+caster->QCN+"'s ball of water explodes in a torrent as it %^RESET%^%^BOLD%^smashes%^RESET%^%^CYAN%^ into "+target->QCN+"!%^RESET%^",({target,caster}));

    damage_targ(target,target->return_target_limb(),sdamage/2,"cold");
    damage_targ(target,target->return_target_limb(),sdamage/2,"bludgeoning");

    if(sizeof(foes))
    {
        for(i=0;i<sizeof(foes);i++)
        {
            if(!objectp(foes[i])) { continue; }
            if(objectp(target))
            {
                if(foes[i] == target) { continue; }
            }

            if(!do_save(foes[i]))
            {
                tell_object(caster,"%^RESET%^%^BOLD%^%^CYAN%^The force of the exploding torrent of water %^RESET%^%^BOLD%^smashes%^RESET%^%^BOLD%^%^CYAN%^ into "+foes[i]->QCN+"!");
                tell_object(foes[i],"%^RESET%^%^BOLD%^%^CYAN%^The force of the exploding torrent of water %^RESET%^%^BOLD%^smashes%^RESET%^%^BOLD%^%^CYAN%^ into you!");
                tell_room(etp,"%^RESET%^%^BOLD%^%^CYAN%^The force of the exploding torrent of water %^RESET%^%^BOLD%^smashes%^RESET%^%^BOLD%^%^CYAN%^ into "+foes[i]->QCN+"!",({caster,foes[i]}));

                damage_targ(foes[i],target->return_target_limb(),sdamage/2,"cold");
                damage_targ(foes[i],target->return_target_limb(),sdamage/2,"bludgeoning");
            }
            else
            {
                tell_object(caster,"%^RESET%^%^BOLD%^"+foes[i]->QCN+" manages to avoid most of the water!");
                tell_object(foes[i],"%^RESET%^%^BOLD%^You manage to avoid most of the water!");
                tell_room(etp,"%^RESET%^%^BOLD%^"+foes[i]->QCN+" manages to avoid most of the water!",({foes[i],caster}));

                damage_targ(foes[i],target->return_target_limb(),sdamage/4,"cold");
                damage_targ(foes[i],target->return_target_limb(),sdamage/4,"bludgeoning");
            }
        }
    }

    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
