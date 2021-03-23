#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

int thac0, AC, roll, hp_before, hp_after;
int num;
string target_limb;
object env;
void dest_effect();

create() {
    ::create();
    set_spell_name("ghoul touch");
    set_spell_level(([ "mage" : 2, "magus" : 2, "cleric" : 2 ]));
    set_domains("undeath");
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS ghoul touch on TARGET");
    set_damage_desc("sickened on living, or paralyzed on living and sickened on everyone");
    set_description("Imbuing you with negative energy, this spell allows you to paralyze a single living humanoid for the duration of the spell with a successful melee touch attack.

Additionally, the paralyzed subject exudes a carrion stench that causes all living creatures (except you) in an area become sickened (Fortitude negates). A neutralize poison spell removes the effect from a sickened creature, and creatures immune to poison are unaffected by the stench.");
    set_save("fort");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(3);
    mental_spell(1);
    set_target_required(1);
}

spell_effect(int prof) {

    spell_successful();
    target_limb = target->return_target_limb();

    //No need to check for undead, this is mind affecting spell and will be rebuked

    if(mind_immunity_damage(target))
    {
        spell_successful();
        dest_effect();
        return;
    }

    tell_object(target,"%^BOLD%^%^BLUE%^"+caster->QCN+" cackles evilly and attempts to touch you!");
    tell_room(place,"%^BOLD%^%^BLUE%^"+caster->QCN+" cackles evilly and attempts to touch "+target->QCN+"!", target);

    env = environment(caster);

    roll = BONUS_D->process_hit(caster, target, 1, 0, 0, 1);
    if (!roll || roll == -1 && ! caster->query_property("spectral_hand"))
    {
        tell_object(target,"%^BOLD%^%^CYAN%^"+caster->QCN+" fails to touch you!");
        tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" fails to touch "+target->QCN+"!", ({target, caster}));
        tell_object(caster,"%^BOLD%^%^CYAN%^You fail to touch "+target->QCN+"!");
        spell_kill(target, caster);
        dest_effect();
        return;
    }

    spell_kill(target, caster);
    tell_object(target,"%^BOLD%^%^CYAN%^"+caster->QCN+" reaches out and touches your "+target_limb+" imbuing you with fell power!");
    tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" reaches out and touches "+target->QCN+" on the "+target_limb+" imbuing them with fell power!", ({target, caster}));
    tell_object(caster,"%^BOLD%^%^CYAN%^You touch "+target->QCN+"'s "+target_limb+" imbuing them with the fell power!");
    if(do_save(target))
    {
        object eff = "/std/effect/status/sickened"->apply_effect(target,roll_dice(1,6));
        if(objectp(eff))
            eff->set_poison();
        tell_object(target,"%^BOLD%^%^CYAN%^You manage to will off some of the effects!");
    }
    else
    {
        object attacker, * attackers;

        target->set_paralyzed(roll_dice(1,6)*8,"The force of the spell has left you stunned.");


        tell_room(place,"%^BOLD%^%^CYAN%^"+target->QCN+" recks of rot.");
        //This spell must be evil.
        attackers = target_selector();
        foreach(attacker in attackers)
        {
            if(!(do_save(attacker,0)||
                 POISON_D->can_be_poisoned(attacker)))
            {
                object eff = "/std/effect/status/sickened"->apply_effect(attacker,roll_dice(1,6));
                tell_object(attacker,"%^BLUE%^You sense contents of your stomach desire to leave it.");
                if(objectp(eff))
                    eff->set_poison();
            }
        }

    }
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

string query_cast_string() {
    return caster->QCN+" mutters a few words and "+caster->QP+" right hand begins to glow a blood red.";
}
