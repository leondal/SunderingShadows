#include <spell.h>
#include <daemons.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("glacier");
    set_spell_level(([ "mage" : 9, "druid":9 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS glacier on TARGET");
    set_damage_desc("half cold, half bludgeoning. Half damage on successful save.");
    set_description("With this spell functions exactly like serac, but the platform is humongous.");
    set_verbal_comp();
    set_save("reflex");
    set_somatic_comp();
    set_target_required(1);
}

spell_effect()
{
    int dam = sdamage;
    spell_successful();
    if (interactive(caster)) {
        tell_object(caster, "%^BOLD%^%^CYAN%^A humongous pl%^CYAN%^a%^BLUE%^t%^WHITE%^f%^CYAN%^o%^BLUE%^r%^CYAN%^m %^BLUE%^o%^WHITE%^f i%^CYAN%^c%^BLUE%^e%^WHITE%^ appears by your side and propels towards " + target->QCN + " with force.%^RESET%^");
        tell_object(target, "%^BOLD%^%^CYAN%^A humongous pl%^CYAN%^a%^BLUE%^t%^WHITE%^f%^CYAN%^o%^BLUE%^r%^CYAN%^m %^BLUE%^o%^WHITE%^f i%^CYAN%^c%^BLUE%^e%^WHITE%^ appears by " + caster->QCN + "'s side and propels towards you with force.%^RESET%^");
        tell_object(target, "%^BOLD%^%^CYAN%^A humongous pl%^CYAN%^a%^BLUE%^t%^WHITE%^f%^CYAN%^o%^BLUE%^r%^CYAN%^m %^BLUE%^o%^WHITE%^f i%^CYAN%^c%^BLUE%^e%^WHITE%^ appears by " + caster->QCN + "'s side and propels towards " + target->QCN + " with force.%^RESET%^", ({ caster, target }));
    }
    define_base_damage(2);
    
    if(do_save(target, 0))
    {
        tell_object(target, "%^YELLOW%^You scramble out of the way of the way and avoid some of the damage!%^RESET%^");
        tell_room(place, "%^YELLOW%^" + target->QCN + " barely scrambles out of the way, avoiding some of the damage!%^RESET%^");
        if(FEATS_D->usable_feat(target, "evasion"))
            sdamage = 0;
        else
            sdamage /= 2;
    }
    
    damage_targ(target, target->return_target_limb(), sdamage / 2, "cold");
    damage_targ(target, target->return_target_limb(), sdamage / 2, "bludgeoning");
    dest_effect();
}
