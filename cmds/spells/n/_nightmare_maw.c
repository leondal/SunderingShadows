#include <spell.h>
#include <magic.h>
inherit SPELL;

int num;

void create()
{
    ::create();
    set_spell_name("nightmare maw");
    set_spell_level(([ "innate" : 8 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS nightmare maw on TARGET");
    set_damage_desc("slashing");
    set_description("This spell summons a Nightmare Maw, one of mindless demons from the seas of Shadow Plane. It will bite into target, continuously tearing their being apart.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("fort");
}

string query_cast_string()
{
    return "%^BOLD%^%^BLACK%^As "+caster->QCN+" chants, a giant black maw forms behind"+caster->QS+".%^RESET%^";
}

spell_effect(int prof)
{
    spell_successful();

    tell_room(place,"%^BOLD%^%^BLACK%^As "+caster->QCN+" completes the chant, giant maw floats towards "+target->QCN+" and plunges its teeth into them.",target);
    tell_object(target,"%^BOLD%^%^BLACK%^As "+caster->QCN+" completes the chant, giant maw floats towards you and plunges its teeth into them.",target);
    damage_targ(target, target->return_target_limb(), sdamage,"slashing");
    num = clevel / 8 + 1;
    if(do_save(target,0))
        num/=2;
    call_out("bite_again",ROUND_LENGTH);
}

void bite_again()
{

    if(!objectp(target))
    {
        dest_effect();
        return;
    }

    if(target->query_hp()<0)
    {
        dest_effect();
        return;
    }

    define_base_damage(0);
    tell_room(ENV(target),"%^BOLD%^%^BLACK%^The maw continues to nibble on "+target->QCN+"!%^RESET%^",target);
    tell_object(target,"%^BOLD%^%^BLACK%^The maw nibbles on you!%^RESET%^");
    damage_targ(target, target->return_target_limb(), sdamage/6,"slashing");

    if(num-- < 0)
    {
        dest_effect();
        return;
    }
    else
    {
        call_out("bite_again",ROUND_LENGTH);
    }
}

dest_effect()
{
    if(find_call_out("bite_again") != -1)
        remove_call_out("bite_again");

    if(objectp(target))
    {
        tell_room(ENV(target),"%^BOLD%^%^BLACK%^The maw was nibbling on "+target->QCN+" vanishes.%^RESET%^",target);
        tell_object(target,"%^BOLD%^%^BLACK%^The maw vanishes!%^RESET%^");
    }

    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}
