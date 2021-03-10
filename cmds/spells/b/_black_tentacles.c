// lowlevel conjuration school specialty spell. Nienne, 11/09.
#include <std.h>
#include <magic.h>
#include <daemons.h>
#include <priest.h>
inherit SPELL;

object* inven, * caught;
int worked, duration, mydam;
void do_tentacles();

void create()
{
    ::create();
    set_author("nienne");
    set_spell_name("black tentacles");
    set_spell_level(([ "mage" : 4, "warlock" : 3, "magus" : 4 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS black tentacles");
    set_description("This spell summons up a mass of writhing black " +
                    "tentacles from the earth at your feet. These will " +
                    "ensnare anything nearby to slow their escape, and attempt to " +
                    "knock them from their feet.");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(3);
    // school specific mage spell
    set_components(([
                        "mage" : ([ "carbon" : 1, ]),
                        ]));
    set_feats_required(([ "warlock" : "tome of ancient secrets"]));
}

int preSpell()
{
    if ((int)CASTER->query_property("black tentacles")) {
        tell_object(CASTER, "%^CYAN%^You are already maintaining such a spell!%^RESET%^");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
    tell_object(caster, "%^BLUE%^You kneel down, whispering your " +
                "summons through the earth.%^RESET%^");
    tell_room(place, "%^BLUE%^Kneeling, " + caster->QCN + " whispers a summoning " +
              "through the earth.%^RESET%^", caster);
    return "display";
}

void spell_effect(int prof)
{
    int i;

    caught = ({});
    inven = target_selector();
    inven -= ({ caster });

    if (!sizeof(inven)) {
        tell_object(caster, "%^CYAN%^From just beneath the earth " +
                    "at your feet, you feel the shiver of the tentacles as "
                    "they find no target to ensnare, and simply fade away.%^RESET%^");
        dest_effect();
        return;
    }
    worked = 1;
    CASTER->set_property("black tentacles", 1);
    mydam = 4 + (clevel / 2);

    tell_room(environment(caster), "%^BOLD%^%^BLUE%^Rubbery black tentacles " +
              "writhe up out of the earth, coiling and "
              "grasping at anything within reach!%^RESET%^");

    for (i = 0; i < sizeof(inven); i++) {
        if (!objectp(inven[i])) {
            continue;
        }
        if (random((int)inven[i]->query_stats("strength") +
                   roll_dice(1, 20)) < random(clevel + 8)) {
            tell_object(inven[i], "%^CYAN%^One manages to wrap about your " +
                        "leg and ensnare you!");

            tell_room(place, "%^CYAN%^One manages to wrap about " +
                      inven[i]->QCN + "'s leg and ensnare " +
                      inven[i]->QO + "!", inven[i]);

            inven[i]->set_property("added short",
                                   ({ "%^GREEN%^ (entangled)%^RESET%^%^CYAN%^" }));
            caught += ({ inven[i] });
            continue;
        }
        if (random((int)inven[i]->query_stats("dexterity") +
                   1) < roll_dice(1, 25) && random(2)) {
            tell_object(inven[i], "%^CYAN%^You stumble as one of the " +
                        "tentacles almost knocks you from your feet!");

            tell_room(place, "%^CYAN%^" + inven[i]->QCN +
                      " stumbles as a tentacle knocks " + inven[i]->QO + " from " +
                      inven[i]->QP + " feet!", inven[i]);

            inven[i]->set_tripped(1, "%^BOLD%^%^CYAN%^You're regaining your " +
                                  "balance!%^RESET%^", 1);
            continue;
        }
    }
    addSpellToCaster();
    spell_successful();
    duration = clevel / 10 + 3;
    call_out("do_tentacles", ROUND_LENGTH);
}

void do_tentacles()
{
    object* removing;
    int i;
    //tell_object(caster, "PLACE = "+identify(PLACE));
    if (!present(caster, PLACE)) {
        dest_effect();
        return;
    }
    if (caster->query_unconscious()) {
        dest_effect();
        return;
    }
    if (!sizeof(inven)) {
        dest_effect();
        return;
    }
    if (worked >= duration) {
        dest_effect();
        return;
    }
    worked++;
    removing = ({});
    for (i = 0; i < sizeof(inven); i++) {
        if (!objectp(inven[i])) {
            continue;
        }
        if (!present(inven[i], PLACE)) {
            inven[i]->remove_property_value("added short",
                                            ({ "%^GREEN%^ (entangled)%^RESET%^%^CYAN%^" }));
            removing += ({ inven[i] });
        }
    }
    inven -= removing;
    caught -= removing;

    if (!sizeof(inven)) {
        dest_effect();
        return;
    }
    removing = ({});
    if (sizeof(caught)) {
        for (i = 0; sizeof(caught) > 0, i < sizeof(caught); i++) {
            if (!objectp(caught[i])) {
                continue;
            }
            if (random(caught[i]->query_stats("strength") + roll_dice(1, 20)) < random(clevel + 8)) {
                tell_object(caught[i], "%^CYAN%^The tentacle squeezes the life from you!");
                tell_room(place, "%^CYAN%^The tentacle squeezes around " + caught[i]->QCN + "!", caught[i]);
                damage_targ(caught[i], caught[i]->return_target_limb(), mydam, "bludgeoning");
            }else {
                tell_object(caught[i], "%^CYAN%^You rip free of the tentacle!");
                tell_room(place, "%^CYAN%^" + caught[i]->QCN +
                          " rips free of the tentacle!", caught[i]);
                caught[i]->remove_property_value("added short", ({ "%^GREEN%^ (entangled)%^RESET%^%^CYAN%^" }));
                removing += ({ caught[i] });
            }
        }
    }
    caught -= removing;
    for (i = 0; i < sizeof(inven); i++) {
        if (!objectp(inven[i])) {
            continue;
        }
        if (inven[i]->query_tripped()) {
            continue;
        }
        if (random((int)inven[i]->query_stats("dexterity") + 1) < roll_dice(1, 25) && random(2)) {
            tell_object(inven[i], "%^CYAN%^You stumble as one of the " +
                        "tentacles almost knocks you from your feet!");
            tell_room(place, "%^CYAN%^" + inven[i]->QCN +
                      " stumbles as a tentacle knocks " + inven[i]->QO + " from " +
                      inven[i]->QP + " feet!", inven[i]);
            inven[i]->set_tripped(1, "%^BOLD%^%^CYAN%^You're regaining your " +
                                  "balance!%^RESET%^", 1);
        }
    }
    call_out("do_tentacles", ROUND_LENGTH);
}

void dest_effect()
{
    int i;
    if (worked) {
        tell_room(place, "%^CYAN%^The writhing tentacles shiver " +
                  "and crumble into dust, fading before your eyes.%^RESET%^");
        for (i = 0; i < sizeof(inven); i++) {
            if (!objectp(inven[i])) {
                continue;
            }
            inven[i]->remove_property_value("added short",
                                            ({ "%^GREEN%^ (entangled)%^RESET%^%^CYAN%^" }));
        }
        if (objectp(CASTER)) {
            CASTER->set_property("black tentacles", -1);
        }
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
