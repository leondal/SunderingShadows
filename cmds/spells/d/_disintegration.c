// Disintegrate
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

void damage_stuff(object target);
int object_save(object obj);

void create() {
    ::create();
    set_spell_name("disintegration");
    set_spell_level(([ "psion" : 6 ]));
    set_spell_sphere("psychoportation");
    set_syntax("cast CLASS disintegration on TARGET");
    set_damage_desc("Ranged touch attack to do force damage");
    set_description("This power uses psychoportation offensively, seeking to teleport millions of tiny pieces of your opponent away in the hope of completely destroying them. This spell does force damage on a ranged touch attack, with additional bleeding for several rounds afterward.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

string query_cast_string()
{
    return "%^CYAN%^" + caster->QCN + " grows still, concentrating carefully.";
}

void spell_effect(int prof)
{
    int check;

    if(!present(target,place))
    {
        tell_object(caster,""+target->QCN+" has left the area!");
        dest_effect();
        return;
    }
    
    tell_object(caster, "%^RED%^You concentrate on the internal structure of your opponent's body, seeking to annihilate them from within.%^RESET%^");
    tell_object(target, "%^RED%^" + caster->QCN + " concentrates on you, seeking to annihilate you from within.%^RESET%^");
    tell_room(place, caster->QCN + " concentrates on " + target->QCN + ", seeking to annihilate " + target->query_objective() + " from within.", ({ caster, target }));

    if(random((int)target->query_stats("dexterity") + 1) < roll_dice(1,20)) { check = 1; }
    else { check = 0; }

    if(BONUS_D->process_hit(caster, target, 1, 0, 0, 1))
    {
        tell_object(caster,"%^BOLD%^%^RED%^"+target->QCN+" fails to escape the path of your "
            "terrible power and pieces of " + target->query_possessive() + " body simply disappear!");
        tell_object(target,"%^BOLD%^%^RED%^You are unable to avoid "+caster->QCN+"'s power "
            "and pieces of your body simply disappear!");
        tell_room(place,""+target->QCN+" is unable to move in time, and is hit with the "
            "full destructive force of "+caster->QCN+"'s power!",({target,caster}));
        target->set_property("rend", 2);
        target->cause_typed_damage(target, target->return_target_limb(), sdamage, "force");
    }
    else
    {
        tell_object(caster,"%^ORANGE%^"+target->QCN+" manages to dodge to the side at the last "
            "second, narrowly avoiding the full power of the destructive energy!");
        tell_object(target,"%^ORANGE%^You manage to duck aside at the last instant, dodging the "
            "power of the destructive energy!");
        tell_room(place,"%^ORANGE%^"+target->QCN+" manages to duck aside at the last instant, dodging the power of the destructive energy.", ({ caster, target }));
    }

    spell_kill(target,caster);
    spell_successful();
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
