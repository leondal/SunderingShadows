//

#include <std.h>
#include <spell.h>
#include <magic.h>

inherit SPELL;

int oldstr;

create()
{
    ::create();
    set_spell_name("ray of enfeeblement");
    set_spell_level(2);
    set_spell_type("wizard");
    set_spell_sphere("enchantment_charm");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_xp_bonus(10);
}

spell_effect()
{
    object caster, target;
    int clevel;

    ::spell_effect();
    caster = CASTER;
    target = TARGET;
    place = PLACE;
    clevel = caster->query_level();
    if(do_saving_throw(target, "spell"))
    {
        tell_object(target, wrap("You are narrowly missed by "+
            "a ray emanating from "+caster->query_cap_name()+
            ".\n"));
        tell_room(place, wrap(target->query_cap_name()+
            "is narrowly missed by a ray emanating from "+
            caster->query_cap_name()+".\n"),
            ({ caster, target }));
        tell_object(caster, "Your ray of enfeeblement missed.\n");
        destruct(TO);
        return 1;
    }
    else
    {
        TO->spell_successful();
        tell_object(target, wrap("You are hit by a ray emanating "+
            "from "+caster->query_cap_name()+".\n"));
        tell_object(target, "You suddenly feel very weak.\n");
        tell_room(place, wrap(target->query_cap_name()+
            "is hit by a ray emanating from "+
            caster->query_cap_name()+".\n"), ({ caster, target }));
        tell_object(caster, "Your ray of enfeeblement hit!.\n");
    }
    target->set_attack_bonus(-2);
    target->set_damage_bonus(-1);
    oldstr = target->query_stats("strength");
    target->set_stats("strength", 5);
    call_out("dest_effect", ROUND_LENGTH * clevel);
}

void dest_effect()
{
    object target;

    target=TARGET;
    remove_call_out("dest_effect");
    if(!target)
    {
        TO->remove();
        return;
    }
    tell_object(target, "You recover your strength.\n");
    target->set_attack_bonus(2);
    target->set_damage_bonus(1);
    target->set_stats("strength", oldstr);
}

help()
{
    write(
@HELP
Ray of Enfeeblement
--------------------------
Usage: cast ray of enfeeblement on <target>

Range: same room as caster
Components: V, S
Duration: 1 round/level
Casting time: 2
Area of Effect: 1 creature
Saving Throw: Neg.

    This spell has the effect of enfeebling or weakening a creature.
In game mechanics, this means that their strength is lowered to 5 and 
they recieve a -2 to their attack roll and a -1 to damage rolls while 
the spell is in effect.  If a saving throw vs. spell is made, it is 
assumed that the target was able to somehow get out of the way of the
ray.

HELP
    );
}
