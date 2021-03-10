#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("feast of ashes");
    set_spell_level(([ "druid" : 2,  ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS feast of ashes on TARGET");
    set_description("You curse the target with a hunger no food can assuage. They become immediately hungry.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("fort");
    set_target_required(1);
}

spell_effect(int prof)
{
    int dam = sdamage;
    spell_successful();
    if (interactive(caster)) {
        tell_object(caster,"%^BOLD%^%^BLACK%^You extend you hand in direction of "+target->QCN+" and proclaim the curse!");
        tell_room(place,"%^BOLD%^%^BLACK%^"+caster->QCN+" extends "+caster->QP+" hand in direction of "+target->QCN+" and proclaims the curse!", ({caster}) );
    }

    if(do_save(target, -10))
    {
        tell_object(caster,"%^BOLD%^%^BLACK%^You feel your curse is forcefully endured.");
        tell_object(target,"%^BOLD%^%^BLACK%^You endure the curse and shrug it off.");
    }else {
        tell_object(caster,"%^BOLD%^%^BLACK%^You feel your curse sinking into " +target->QCN + ".");
        tell_room(place, "%^BOLD%^%^WHITE%^" + target->QCN + "'s tummy growls loudly.");
        target->set_stuffed(0);
        target->set_quenched(0);
    }

    dest_effect();
}
