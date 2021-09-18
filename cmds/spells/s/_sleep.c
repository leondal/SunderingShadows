// Sleep
// skip newbies from room effect added by Styx 10/17/02

#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

int x,time;
int max_hd, counter;
object this_target,*party,*prospective,*targets;
void dest_effect();
int check();

create()
{
    ::create();
    set_spell_name("sleep");
    set_spell_level(([ "mage" : 1, "bard" : 1, "psion" : 1, "oracle" : 1 ]));
    set_mystery("lunar");
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS sleep on TARGET");
    set_description("This spell will force your target or everyone in the room, excluding your party, to fall asleep. Attacks on the sleepers will awaken them; normal noise won't, however. Successful save will negate the effect. Immunity to mental attacks will cause damage instead. This is an agressive spell and victims will respond violently.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}



spell_effect(int prof)
{
    int success, rounds, resisted;
    string myrace;


    success = 0;

    rounds = (prof / 100) * (roll_dice(1, 6) + (clevel / 10));
    if (rounds < 1) {
        rounds = 1;
    }
    if (rounds > 15) {
        rounds = 15;
    }
    time = rounds * ROUND_LENGTH;

    max_hd = clevel / 2;

    //validate additional targets in the room
    prospective = target_filter(all_living(environment(caster)));
    prospective = target_filter(prospective);
    prospective += ({target});
    prospective = distinct_array(prospective);
    if (target != caster) {
        prospective -= ({caster});
    }

    counter = 0;
    targets = ({ target });

    for (x=0;x < sizeof(prospective);x++)
    {
        if (!objectp(prospective[x])) {
            continue;
        }

        if (counter >= max_hd) {
            break;
        }
        if (!caster->ok_to_kill(prospective[x])) {
            continue;
        }
        this_target = prospective[x];
        resisted = 0;

        if (do_save(this_target, 0) == 1 ) {
            resisted = 1;
        }
        if (PLAYER_D->immunity_check(this_target, "sleep") == 1) {
            resisted = 1;
        }
        if (mind_immunity_check(this_target, "default") == 1) {
            resisted = 1;
        }
        if (this_target == caster) {
            resisted = 0;
        }

        if (resisted == 1 && this_target != caster) {
           tell_room(environment(this_target),
               "%^YELLOW%^Outraged at "+caster->QCN+" for "+caster->QP+" mind control, "+
               target->QCN+" attacks "+caster->QO+"!", ({target, caster}) );
           tell_object(this_target,
               "%^YELLOW%^Outraged at "+caster->QCN+" for "+caster->QP+
               " mind control, you attack "+caster->QO+"!");
           tell_object(caster,"%^YELLOW%^"+target->QCN+" attacks you,"+
               " outraged at you for your attempted mind control!" );
           spell_kill(this_target,caster);
           continue;
        }

        counter += this_target->query_level();
        tell_room(environment(this_target),
           "%^CYAN%^%^BOLD%^"+this_target->QCN+
           " wavers for a bit, then falls to the ground in a deep slumber.", this_target);
        tell_object(this_target,"%^BOLD%^%^CYAN%^"+caster->QCN+" tries to control "+
           "your mind!\nYou try to fight "+caster->QO+" off, but "+caster->QP+" "
           "will is too strong for you!\nYou suddenly become drowsy and fall asleep.");
        tell_object(caster,"%^GREEN%^You break into "+this_target->QCN+"'s mind and "
           "overcome "+target->QP+" willpower!");
        this_target->set_asleep(time, "You are having a nap.");
        this_target->set_property("spelled", ({TO}) );
        this_target->remove_attacker(caster);
        caster->remove_attacker(this_target);
        spell_successful();
        success = 1; // this indicates whether the spell works on anything
    }
    if (!success) {
        tell_object(caster, "%^CYAN%^%^BOLD%^Your sleep attempt fails to affect anything.%^RESET%^");
        dest_effect();
        return;
    }
    return;
}

string query_cast_string()
{
    return caster->QCN + " throws some rose petals in the air!";
}
