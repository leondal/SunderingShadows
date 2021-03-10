#include <priest.h>
inherit SPELL;

create()
{
    ::create();
    set_spell_name("neutralize poison");
    set_spell_level(([ "cleric" : 4, "bard" : 4, "paladin" : 4, "ranger" : 3, "druid" : 3, "inquisitor" : 4, "oracle" : 4 ]));
    set_mystery("life");
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS neutralize poison on TARGET");
    set_description("This spell will attempt to remove any poisons on the target. The power of " +
                    "the caster has an impact on how successful the attempt will be.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_non_living_ok(1);
    set_helpful_spell(1);
}

string query_cast_string()
{
    string cast;
    if (interactive(CASTER)) {
        cast = YOU + " prays for a divine spell!\n";
    }else {
        cast = YOU + " calls for divine influence!\n";
    }
    return cast;
}

spell_effect(int prof)
{
    mixed tmp;
    int duration, level;
    //giving a bonus of 1d20, for now - Saide
    level = CASTER->query_level();
    level += roll_dice(1, 20);
    //level = CASTER->query_level() + (CASTER->query_level()/7);


    if (interactive(CASTER)) {
        set_cast_string(YOU + " prays for a divine spell !\n");

        tell_object(CASTER, "You cast neutralize poison on " + HIM + ".");
        tell_room(PLACE, YOU + " casts a spell on " + HIM + ".", ({ CASTER, TARGET }));
        if (!POISON_D->is_poisoned(TARGET)) {
            if (CASTER != TARGET) {
                tell_object(CASTER, HIM + " is not poisoned!");
                tell_object(TARGET, "You are not poisoned, " + YOU + "'s spell fails " +
                            "to neutralize anything.");
            }else {
                tell_object(CASTER, "You are not poisoned!");
            }
        }else {
            tmp = POISON_D->clear_poisons_by_dc(TARGET, level, 0);
            if (!tmp) {
                if (CASTER != TARGET) {
                    tell_object(CASTER, "You are unable to neutralize the " +
                                "poison affecting " + HIM + "!");
                    if (interactive(TARGET)) {
                        tell_object(TARGET, YOU + " is unable to neutralize the " +
                                    "poison affecting you!");
                    }
                }else {
                    tell_object(CASTER, "You are unable to neutralize the " +
                                "poison affecting you!");
                }
            }
            if (tmp) {
                if (CASTER != TARGET) {
                    tell_object(CASTER, "You neutralize the following from " + HIM + ". " +
                                tmp);
                    if (interactive(TARGET)) {
                        tell_object(TARGET, YOU + " neutralizes the following poison " +
                                    "affecting you. " + tmp);
                    }
                }else {
                    tell_object(CASTER, "You neutralize the following that were " +
                                "affecting you. " + tmp);
                }
            }
        }
    }   else {
        tell_room(PLACE, YOU + " casts a spell on " + HIM + ".", ({ CASTER }));
        if (interactive(TARGET)) {
            if (!POISON_D->is_poisoned(TARGET)) {
                tell_object(TARGET, "You are not poisoned, " + YOU + "'s spell fails " +
                            "to neutralize anything.");
            }else {
                tmp = POISON_D->clear_poisons_by_dc(TARGET, level, 0);
                if (!tmp) {
                    tell_object(TARGET, YOU + " is unable to neutralize the " +
                                "poison affecting you!");
                }else {
                    tell_object(TARGET, YOU + " neutralizes the following poison " +
                                "affecting you. " + tmp);
                }
            }
        }
    }
    //TARGET->add_poisoning(-TARGET->query_poisoning());
    spell_successful();
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
