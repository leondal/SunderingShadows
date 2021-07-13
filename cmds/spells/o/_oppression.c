// oppression
#include <std.h>
#include <magic.h>
#include <party.h>
#include <daemons.h>

inherit SPELL;

object* party_members = ({}), * oppressed = ({});
int bonus, counter;

void create()
{
    ::create();
    set_author("ares");
    set_spell_name("oppression");
    set_spell_level(([ "cleric" : 2 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS oppression");
    set_description("This spell will surround the caster with a dark aura of oppression.  Any creature caught in the aura "
                    "that is not in the caster's party must make a saving throw or cower in fear from the caster.  Targets that are so "
                    "effected will have their ability to hit and do damage in combat reduced until either the aura expires or they leave the "
                    "presence of the caster.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("will");
}

string query_cast_string()
{
    tell_object(caster, "%^BOLD%^%^BLACK%^Clenching your fists, " +
                "you begin to growl the words of a prayer in a fearsome tone.");
    tell_room(place, "%^BOLD%^%^BLACK%^" + caster->QCN + " clenches " +
              "" + caster->QP + " fits, growing the words of a prayer in a" +
              " fearsome tone.", caster);
    return "display";
}

void spell_effect(int prof)
{
    int duration;
    duration = (ROUND_LENGTH * 10) * clevel;

    bonus = clevel / 10 + 1;
    bonus = bonus > 4 ? 4 : bonus;

    tell_object(caster, "%^BOLD%^%^BLACK%^You begin to glow with a dark aura as you complete "
                "your chant!");
    tell_room(place, "%^BOLD%^%^BLACK%^" + caster->QCN + " begins to glow with a dark aura as "
              "" + caster->QS + " completes " + caster->QP + " chant!", caster);

    spell_duration = duration;
    set_end_time();
    call_out("dest_effect", spell_duration);
    addSpellToCaster();
    spell_successful();
}

int party_filter(object obj)
{
    if (!objectp(obj)) {
        return 0;
    }
    if (member_array(obj, party_members) != -1) {
        return 0;
    }
    return 1;
}

void execute_attack()
{
    object* inven, room, * tmp;
    string party;
    int i;

    ::execute_attack();


    if (!objectp(caster) || !objectp(ENV(caster))) {
        dest_effect();
        return;
    }

    counter = 0;
    room = environment(caster);
    party = (string)caster->query_party();
    if (party) {
        party_members = (object*)PARTY_OB->query_party_members(party);
    }
    inven = all_living(room);
    inven = filter_array(inven, (:$1->is_living():));
    inven -= ({ caster });
    inven = target_filter(inven);
    inven = filter_array(inven, "party_filter", TO);

    if (caster->query_followers()) {
        inven -= caster->query_followers();
    }

    if (sizeof(oppressed)) { // So they don't stay under the influence of the aura if they leave the room -Ares
        tmp = oppressed;
        for (i = 0; i < sizeof(tmp); i++) {
            if (!objectp(tmp[i])) {
                continue;
            }
            if (!present(tmp[i], room)) {
                tell_object(tmp[i], "%^RED%^You feel an incredible relief as you leave "
                            "" + caster->QCN + "'s presence!");
                tmp[i]->remove_property("oppressed");
                tmp[i]->add_attack_bonus(bonus);
                tmp[i]->add_damage_bonus(bonus);
                oppressed -= ({ tmp[i] });
            }
        }
    }

    if (!sizeof(inven)) {
        room->addObjectToCombatCycle(TO, 1);
        return;
    }

    for (i = 0; i < sizeof(inven); i++) {
        if (!objectp(inven[i])) {
            continue;
        }
        if (inven[i]->query_property("oppressed")) {
            continue;
        }
        tell_object(inven[i], "%^RED%^You feel the oppressive force of the aura surrounding "
                    "" + caster->QCN + ".");
        if (!do_save(inven[i], 0) && !PLAYER_D->immunity_check(inven[i], "fear") && !inven[i]->query("no pk")) {
            //if(!SAVING_D->saving_throw(inven[i],"spell",0)){
            tell_object(inven[i], "%^GREEN%^You cower away from " + caster->QCN + "!");
            tell_object(caster, "%^GREEN%^" + inven[i]->QCN + " cowers in fear of your "
                        "mighty presence!");
            tell_room(room, "%^GREEN%^" + inven[i]->QCN + " cowers in fear of " + caster->QCN + "!", ({ caster, inven[i] }));
            oppressed += ({ inven[i] });
            inven[i]->set_property("oppressed", 1);
            inven[i]->add_attack_bonus(-1 * bonus);
            inven[i]->add_damage_bonus(-1 * bonus);
        }
    }
    room->addObjectToCombatCycle(TO, 1);
    return;
}

void dest_effect()
{
    object* tmp = ({});
    int i;
    if (sizeof(oppressed)) {
        tmp = oppressed;
        for (i = 0; i < sizeof(tmp); i++) {
            if (!objectp(tmp[i])) {
                continue;
            }
            tell_object(tmp[i], "%^RED%^You sag with relief as the aura fades away "
                        "from " + caster->QCN + ".");
            tmp[i]->remove_property("oppressed");
            tmp[i]->add_attack_bonus(bonus);
            tmp[i]->add_damage_bonus(bonus);
            oppressed -= ({ tmp[i] });
        }
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
