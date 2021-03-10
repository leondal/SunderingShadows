#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit SPELL;

int check(mixed *arg);
void dest_effect();
void defend(object caster);

object mon;

void create()
{
    ::create();
    set_spell_sphere("conjuration_summoning");
    set_description("This spell will allow the caster to summon an animal from the nearby surrounds.  It will react "
                    "aggressively to anyone attempting to harm the caster.  It will fight to the death, and when the spell's time is up, "
                    "it will return to its business.  Such creatures can only be summoned within the wilderness they call home. If this creature looses you it will return to home, and you'll have to recast this spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string()
{
    return "%^BOLD%^" + caster->QCN + " lets out a cry to the wilds!";
}

int preSpell()
{
    string terrain;
    terrain = place->query_terrain();
    if (!terrain || terrain == "" || isCivilization(terrain)) {
        tell_object(caster, "You couldn't call for a wild creature here!");
        return 0;
    }
    if (present(caster->query_name() + "'s ally", place)) {
        tell_object(caster, "You have an animal under your control already.");
        return 0;
    }
    return 1;
}

object createMon()
{
    error("Called function that never meant to be called.");
}

spell_effect(int prof)
{
    int i, j, numfoes;
    object* foes;

    spell_successful();
    foes = caster->query_attackers();
    numfoes = (sizeof(foes));

    if (clevel > 70) {
        clevel = 70;
    }
    mon = createMon();
    if (!objectp(mon)) {
        tell_object(caster, "Error: minion not initialized.");
        dest_effect();
        return;
    }
    mon->set("aggressive", 1);
    mon->add_id(caster->query_name() + "'s ally");
    mon->add_id("summoned monster");
    if (interactive(caster)) {
        mon->set_exp(0);
    }
    mon->remove_property("swarm");
    mon->set_property("spelled", ({ TO }));
    mon->set_property("spell", TO);
    mon->set_property("spell_creature", TO);
    setup_beastie(mon);
    mon->set_mylevel(clevel);
    mon->move(place);
    caster->add_protector(mon);
    caster->add_follower(mon);
    mon->set_property("minion", caster);
    if (caster->is_class("druid")) {
        mon->set_hp(mon->query_hp() + ((clevel + 10) * 2));
    }
    tell_room(place, mon->query_short() + " approaches at " + caster->QCN + "'s call.", caster);
    tell_object(caster, mon->query_short() + " appears at your call.");
    if (foes != ({}) && target != caster) {
        for (j = 0; j < numfoes; j++) {
            spell_kill(mon, foes[j]);
            tell_object(foes[j], "%^BOLD%^%^YELLOW%^...and it attacks you!");
        }
    }
    if (target == caster) {
        spell_kill(mon, caster);
        tell_object(caster, "%^BOLD%^%^YELLOW%^...and it attacks you!");
    }
    if (target != caster) {
        // adding additional 5 minute minimum
        spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH + 600;
        set_end_time();
        call_out("check", 1, ({ 0, spell_duration, caster, foes }));
    }
    addSpellToCaster();
}

int check(mixed* args)
{
    int i, j, timetowait, wherefound, tracker, timer;
    object* foes, * newfoes;

    timer = args[0];
    timetowait = args[1];
    caster = args[2];
    foes = args[3];
    if (!caster || !objectp(caster)) {
        dest_effect();
        return 1;
    }
    j = sizeof(newfoes = caster->query_attackers());
    tracker = 0;
    for (i = 0; i < j; i++) {
        wherefound = member_array(newfoes[i], foes, 0);
        if (wherefound == -1) {
            if (tracker == 0) {
                tell_object(caster, "%^BOLD%^%^YELLOW%^Your minion comes to your aid and attacks your enemies!");
                tell_room(place, "%^BOLD%^%^YELLOW%^" + caster->QCN + "'s minion comes to " +
                          caster->QP + " aid and attacks " + caster->QP + " enemies!", caster);
                tracker = 1;
            }
        }
    }
    if (tracker == 1) {
        foes = newfoes;
        defend(caster);
    }

    if (objectp(mon) && objectp(caster)) {
        if (environment(mon) != environment(caster)) {
            tell_object(caster,"%^BOLD%^%^GREEN%^You sense movement in the corner of your eye as your ally rejoins you.");
            mon->move(ENV(caster));
            caster->add_follower(mon);
            caster->add_protector(mon);
        }
    }

    if (timer++ < timetowait) {
        call_out("check", 1, ({ timer, timetowait, caster, foes }));
    } else {
        dest_effect();
    }
}

void defend(object caster)
{
    int i, numfoes;
    object* foes;

    foes = caster->query_attackers();
    numfoes = sizeof(foes);
    if (!numfoes) {
        return;
    }
    if (mon && objectp(mon)) {
        for (i = 0; i < numfoes; i++) {
            spell_kill(mon, foes[i]);
        }
    }
    return;
}

void dest_effect()
{
    if (find_call_out("check") != -1) {
        remove_call_out("check");
    }
    if (objectp(mon)) {
        tell_room(environment(mon), "%^BOLD%^%^YELLOW%^The creature departs back to its home!");
        if (objectp(caster)) {
            caster->remove_follower(mon);
        }
        mon->move("/d/shadowgate/void.c");
        mon->remove();
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}

void setup_beastie(object mymon)
{
}                                    // called from level-specific spells to empower beastie
