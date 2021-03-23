//      Chill Touch
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

string target_limb, element;


create()
{
    ::create();
    set_spell_name("touch of sickening");
    set_spell_level(([ "mage" : 1, "cleric":1, "druid":1, "magus" : 1 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS touch of sickening on TARGET");
    set_damage_desc("sickened for clevel/4+1 rounds");
    set_description("With this spell you touch the victim, channeling negative energy through your hand and sickening them.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}


string query_cast_string() { return "%^BLUE%^"+caster->QCN+" utters a chant."; }


spell_effect(int prof)
{
    string mycolor, myhue, myhue2, myfeeling;
    int bonus, roll;

    if(!objectp(caster) || !objectp(target))
    {
        target = 0;
        dest_effect();
        return;
    }

    target_limb = target->return_target_limb();

    bonus = 0;

    if (!present(target,environment(caster)))
    {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        target = 0;
        dest_effect();
        return;
    }

    roll = BONUS_D->process_hit(caster, target, 1, bonus, 0, 1);

    if(!roll || roll == -1 && ! caster->query_property("spectral_hand"))
    {
        tell_object(caster,""+mycolor+"You try and touch "+target->QCN+"'s "+target_limb+" with a "+myhue+" hand, but miss!");
        tell_object(target,""+mycolor+caster->QCN+"'s "+myhue+" hand gropes for your "+target_limb+" unsuccessfully.");
        tell_room(place,""+mycolor+caster->QCN+" reaches out for "+target->QCN+"'s "+target_limb+" with a "+myhue+" hand and misses!", ({ caster, target}) );
        target = 0;
        dest_effect();
        return;
    }

    if(!"/daemon/combat_d.c"->extra_hit_calcs(caster, target))
    {
        target = 0;
        dest_effect();
        return;
    }

    tell_object(caster,"%^BLUE%^You reach out and touch "+target->QCN+"'s "+target_limb+" with your hand.");
    tell_object(target,"%^BLUE%^"+caster->QCN+" touches your "+target_limb+".\n%^WHITE%^A feeling of tiredness runs through you...");
    tell_room(place,"%^BLUE%^"+caster->QCN+" reaches out and touches "+target->QCN+"'s "+target_limb+"...",({ caster, target}) );
    spell_successful();

    "/std/effect/status/sickened"->apply_effect(target,clevel/4+1);

    target->use_stamina(sdamage/6);
    dest_effect();

}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
