#include <magic.h>
#include <std.h>
#include <spell.h>
#include <daemons.h>

inherit SPELL;

object elemental;
string* elements = ({ "fire", "air", "earth", "water" });
string element;

void create_elemental();

void create()
{
    ::create();
    set_spell_name("elemental swarm");
    set_spell_level(([ "druid" : 9, "oracle" : 9 ]));
    set_mystery("elemental");
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS elemental swarm on TARGET");
    set_description("This spell will unleash the fury of the elemental planes on the caster's foes.  A portal will open to a random "
                    "elemental plane and an elder elemental will come forth to aid the caster.  The elemental will fight until it is slain or until "
                    "the caster's enemies are killed.  If the elemental is slain, another portal will open to a different elemental plane.  "
                    "This will continue until the caster is dead, until his or her foes are all dead, or until an elemental has been called "
                    "forth from each of the planes of earth, air, fire, and water.");
    set_verbal_comp();
    set_target_required(1);
    set_helpful_spell(1);
}

string query_cast_string()
{
    tell_room(place, "%^B_RED%^%^BOLD%^%^GREEN%^" + caster->QCN + " throws " + caster->QP + " head back and calls out to the elements!%^RESET%^", caster);
    tell_object(caster, "%^B_RED%^%^BOLD%^%^GREEN%^You throw your head back and call out to the elements!%^RESET%^");
    return "display";
}

string c(string str)
{
    switch (str) {
    case "fire":    return "%^BOLD%^%^RED%^F%^MAGENTA%^I%^RESET%^R%^BOLD%^%^RED%^E%^RESET%^";

    case "air":     return "%^CYAN%^A%^RESET%^%^BOLD%^I%^CYAN%^R%^RESET%^";

    case "earth":   return "%^YELLOW%^E%^RESET%^%^ORANGE%^A%^BOLD%^%^BLACK%^R%^RESET%^%^ORANGE%^T%^YELLOW%^H%^RESET%^";

    case "water":   return "%^BOLD%^%^BLUE%^W%^RESET%^%^CYAN%^A%^RESET%^%^BOLD%^T%^RESET%^E%^BOLD%^%^BLUE%^R%^RESET%^";
    }
}

void spell_effect(int prof)
{
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (caster->query_property("elemental swarm")) {
        tell_object(caster, "%^YELLOW%^You can't summon another elemental swarm right now.");
        dest_effect();
        return;
    }

    element = elements[random(sizeof(elements))];
    elements -= ({ element });

    tell_object(caster, "%^BOLD%^%^GREEN%^Your voice is amplified to thunderous "
                "volume as you call out to the plane of %^RESET%^" + c(element) + "%^BOLD%^%^GREEN%^!%^RESET%^");
    tell_room(place, "%^BOLD%^%^GREEN%^" + caster->QCN + "'s voice is amplified to "
              "thunderous volume as " + caster->QS + " calls out to the plane of "
              "%^RESET%^" + c(element) + "%^BOLD%^%^GREEN%^!%^RESET%^", caster);

    spell_kill(target, caster);

    call_out("swarm", 5, "begin");

    return;
}

void swarm(string stage)
{
    if (!objectp(caster)) {
        dest_effect(); return;
    }
    if (!objectp(TO)) {
        dest_effect(); return;
    }
    if (!objectp(place)) {
        dest_effect(); return;
    }
    if (!sizeof(caster->query_attackers())) {
        dest_effect(); return;
    }
    if (!present(caster, place)) {
        dest_effect(); return;
    }

    switch (stage) {
    case "begin":

        tell_object(caster, "%^RESET%^%^ORANGE%^You can feel the earth rumble underneath you as the plane of " + c(element) + " "
                    "%^RESET%^%^ORANGE%^responds to the power of your call!%^RESET%^");
        tell_room(place, "%^RESET%^%^ORANGE%^You can feel the earth starting to rumble beneath your feet!%^RESET%^", caster);
        call_out("swarm", 5, "portal");
        return;

    case "portal":

        tell_object(caster, "%^RESET%^%^CYAN%^A portal opens before you, "
                    "leading directly into the plane of " + c(element) + "%^RESET%^%^CYAN%^!%^RESET%^");
        tell_object(caster, "%^RESET%^%^CYAN%^An ancient " + c(element) + " "
                    "%^RESET%^%^CYAN%^elemental steps forth from the portal and attacks your foes!%^RESET%^");

        tell_room(place, "%^RESET%^%^CYAN%^A portal opens before " + caster->QCN + ", "
                  "leading directly into the plane of " + c(element) + "%^RESET%^%^CYAN%^!%^RESET%^", caster);
        tell_room(place, "%^RESET%^%^CYAN%^An ancient " + c(element) + " %^RESET%^%^CYAN%^"
                  "elemental steps forth from the portal and attacks " + caster->QCN + "'s foes!%^RESET%^", caster);

        caster->set_property("elemental swarm", 1);
        create_elemental();
        call_out("swarm", 5, "check");
        return;

    case "new elemental":

        if (!sizeof(elements)) {
            dest_effect();
            return;
        }
        element = elements[random(sizeof(elements))];
        elements -= ({ element });
        call_out("swarm", 5, "begin"); // summon another elemental
        return;

    case "check":

        if (!sizeof(caster->query_attackers())) {
            dest_effect();
            return;
        }
        call_out("swarm", 5, "check");
    }

    return;
}

void create_elemental()
{
    object* att;
    int i;

    if (!objectp(caster) || !objectp(TO) || !objectp(place) || !sizeof(caster->query_attackers())) {
        dest_effect();
        return;
    }

    elemental = new("/d/magic/mon/swarm_elemental.c");

    elemental->setup_elemental(element, TO); // description stuff, according to element
    elemental->set_resistance_percent(element, 200); // the elemental is healed by damage type from its own element

    elemental->set_guild_level("fighter", clevel);
    elemental->set_mlevel("fighter", clevel);
    elemental->set_hp(clevel * 15);
    elemental->set_stats("strength", 15 + (clevel / 4));
    elemental->set_stats("constitution", 15 + (clevel / 4));
    elemental->set_stats("dexterity", 15 + (clevel / 4));
    elemental->set_ac(10 + (-clevel));
    elemental->set_attacks_num(clevel / 7);
    elemental->set_damage_bonus(clevel / 5);
    elemental->set_attack_bonus(clevel / 2);
    elemental->set_hd(clevel, 12);
    elemental->set_property("effective_enchantment", clevel / 6);

    elemental->set_property("spelled", ({ TO }));
    elemental->set_property("spell_creature", TO);
    elemental->set_property("spell", TO);
    elemental->add_id("summoned monster");
    elemental->add_id(caster->query_name() + "monster");

    elemental->move(place);

    caster->add_protector(elemental);
    caster->add_follower(elemental);
    elemental->force_me("protect " + caster->query_name()); // purely for looks, it's already protecting
    elemental->force_me("protect " + caster->query_name());
    elemental->force_me("protect " + caster->query_name());
    elemental->force_me("protect " + caster->query_name());

    att = caster->query_attackers();

    for (i = 0; i < sizeof(att); i++) {
        if (!objectp(att[i]) || !present(att[i], place)) {
            continue;
        }
        elemental->kill_ob(att[i], 0);
    }
    return;
}

void dest_effect()
{
    int i;
    if (objectp(TO)) {
        for (i = 0; i < 10; i++) {
            remove_call_out("swarm");
        }

        if (objectp(caster)) {
            caster->remove_property("elemental swarm");

            if (sizeof(elements)) {
                tell_object(caster, "%^BOLD%^%^BLUE%^The last of your foes has perished, and the force of the elements subside!%^RESET%^");
            }else {
                tell_object(caster, "%^BOLD%^%^RED%^As your final elemental is slain, the force of the elements subsides!%^RESET%^");
            }

            if (objectp(elemental)) {
                elemental->move("/d/shadowgate/void");
                elemental->remove();
            }
            if (objectp(place)) {
                tell_room(place, "%^YELLOW%^The fury of the elements subsides as the final elemental vanishes to its home plane!", caster);
            }
        }

        ::dest_effect();
    }
    if (objectp(TO)) {
        TO->remove();
    }
}
