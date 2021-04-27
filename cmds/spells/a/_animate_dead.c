#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit SPELL;

int num_mon;

#define UNDEADDIR "/d/magic/mon/create_undead/"

void fail();

void create()
{
    ::create();
    set_spell_name("animate dead");
    set_spell_level(([ "mage" : 4, "cleric" : 3, "paladin" : 3, "inquisitor" : 3, "oracle" : 3 ]));
    set_mystery("bones");
    set_spell_sphere("necromancy");

    set_syntax("cast CLASS animate dead [on TARGET]");
    set_damage_desc("raises no more than three skeletal champions at a time");
    set_description("%^RESET%^With this spell, the caster uses remnants of the negative energy released upon a recent death in order to summon an undead skeleton. Many faiths and cultures condemn this spell and similar powers as it serves the caster's selfish, often evil, motives. Frequent users of this spell are known to be inherently evil." + extra_help());
    set_verbal_comp();
    set_somatic_comp();
    set_non_living_ok(1);
    evil_spell(1);
    set_components(([
                        "mage" : ([ "drop of blood" : 1, "bit of bone" : 1, ]),
                        ]));
    set_helpful_spell(1);
}

string extra_help(){

    return "

Each undead will use one pool slot, with five pool slot maximum.
Undead pool is shared across similar spells.
To remove undead use %^ORANGE%^<dismiss undead>%^RESET%^
To command undead use %^ORANGE%^<command undead to %^ORANGE%^%^ULINE%^ACTION%^RESET%^%^ORANGE%^>%^RESET%^
To force lost undead to follow use %^ORANGE%^<command undead to follow>%^RESET%^
To check how many undead you have rised use %^ORANGE%^<poolsize>%^RESET%^";
}


void spell_effect(int prof)
{
    object* targs = ({}), * temp = ({}), * inven = ({}), undead, controller;
    int i, j, lvl, flag;

    if (target && objectp(target) && !target->is_room()) {
        if (!target->is_corpse()) {
            fail();
            return;
        }
        targs = ({ target });
    }else {
        targs = all_inventory(environment(caster));

        for (i = 0; i < sizeof(targs); i++) {
            if (!targs[i]->is_corpse()) {
                continue;
            }
            temp += ({ targs[i] });
        }
        targs = temp;

        if (!sizeof(targs)) {
            tell_object(caster, "%^RESET%^%^BOLD%^%^BLACK%^LIFE'S PUTRID FIRE %^WHITE%^MUS%^BLACK%^T %^WHITE%^BE%^BLACK%^ SNUFFED OUT FIRST!%^RESET%^");
            TO->remove();
            return;
        }
    }

    if (present("undead_controller", caster)) {
        controller = present("undead_controller", caster);
    }else {
        controller = new("/d/magic/obj/undead_controller");
        controller->set_caster(caster);
        controller->move(caster);
    }

    num_mon = (int)caster->query_property("raised");
    if (!intp(num_mon)) {
        num_mon = 0;
    }
    if (num_mon >= 5) {
        tell_object(caster, "%^RESET%^%^BOLD%^%^BLACK%^YOU ARE %^WHITE%^NOT %^WHITE%^WORTHY%^BLACK%^ TO RAISE MORE!%^RESET%^%^RESET%^");
        tell_room(environment(caster), "%^CYAN%^" + caster->QCN + " seems to strain doing something.%^RESET%^", caster);
        TO->remove();
        return;
    }

    spell_successful();

    for (i = 0; i < sizeof(targs) && i < 2; i++) {
        undead = new(UNDEADDIR + "skeleton");
        lvl = 1;

        if (num_mon > 4) {
            undead->remove();
            tell_object(caster, "%^RESET%^%^BOLD%^%^BLACK%^RAISING MORE IS %^WHITE%^BEYOND%^BLACK%^ YOUR PATHETIC %^BLACK%^M%^WHITE%^ASTERY!%^RESET%^%^RESET%^");
            tell_room(environment(caster), "%^CYAN%^" + caster->QCN + " seems to strain doing something.%^RESET%^", caster);
            TO->remove();
            return;
        }

        inven = all_inventory(targs[i]);
        inven->move(undead);

        targs[i]->remove();
        num_mon += lvl;

        undead->set_property("raised", 1);
        undead->set_property("minion", caster);
        undead->move(environment(caster));

        undead->set_guild_level("fighter", clevel);
        undead->set_weap_enchant(clevel / 12);
        undead->set_skill("athletics", clevel);
        undead->set_skill("perception", clevel);
        undead->set_level(clevel);
        undead->set_hd(clevel, 4);

        undead->set_max_hp(clevel * 10);
        undead->set_hp(undead->query_max_hp());
        undead->set_overall_ac(5 - clevel);
        undead->control(caster);
        caster->add_follower(undead);

        undead->add_id("summoned monster");
        undead->set_property("spell", TO);
        undead->set_property("spell_creature", TO);
        undead->set_property("minion", caster);
        controller->add_monster(undead);
        caster->set_property("raised", 1);

    }
    tell_object(caster, "%^BLUE%^You let your arms drop limply after completing the spell.");
    tell_room(place, "%^BOLD%^" + caster->QCN + " lets " + caster->QP + " arms drop limply.", caster);
    dest_effect();
    spell_successful();
    return;
}

void fail()
{
    tell_object(caster, "%^RESET%^%^BOLD%^%^BLACK%^YOU FAIL, %^WHITE%^PA%^BLACK%^T%^WHITE%^HETIC %^WHITE%^WEAKLING!%^RESET%^%^RESET%^");
    tell_room(environment(caster), "%^CYAN%^" + caster->QCN + " seems disappointed.", caster);
    TO->remove();
    return;
}

void reverse_spell()
{
    spell_effect(200);
}

void dest_effect()
{
    if (objectp(TO)) {
        TO->remove();
    }
}

string query_cast_string()
{
    return "%^BOLD%^%^BLUE%^" + caster->QCN + " steps " +
           "into the shadows, then mixes something in his hands while " +
           "chanting in a deep, dark tone.";
}
