#include <spell.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;

int storm_effects(object obj);
int trip_em(object obj);

object storm_room, mycaster;
int mylevel, count;

void create()
{
    ::create();
    set_spell_name("greater stomp");
    set_spell_level(([ "psywarrior" : 5 ]));
    set_spell_sphere("psychokinesis");
    set_syntax("cast CLASS greater stomp");
    set_description("The psionic character releases a torrent of psychic "
                    "energy as she stomps upon the earth, causing tremors to ripple "
                    "throughout the area. She uses her energy to feed the power, tripping "
                    "and damaging her foes for several rounds, provided she stays in the "
                    "area. All those attacking the character are subject to the effects of "
                    "the stomp, though they do receive saving throws.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
    aoe_spell(1);
    set_aoe_message("%^RESET%^%^MAGENTA%^(shaken by earth tremors)%^RESET%^");
}

string query_cast_string()
{
    tell_object(caster, "%^RESET%^%^RED%^You gather your psychic reserves, "
                "preparing for your attack.%^RESET%^");
    tell_room(place, "%^RESET%^%^RED%^" + caster->QCN + " raises " + caster->QP + " foot "
              "as " + caster->QS + " releases a low psychic growl.%^RESET%^%^RESET%^", caster);
    return "display";
}

void spell_effect(int prof)
{
    mycaster = caster;

    mylevel = clevel;

    tell_room(PLACE, "%^BOLD%^%^RED%^" + caster->QCN + " stomps " + caster->QP + " " +
              "foot, and the rumble of the %^BLACK%^ground%^RED%^ is matched by the "
              "psychic growl in your mind!%^RESET%^", caster);
    tell_object(caster, "%^BOLD%^%^RED%^With a mighty growl, you stomp your foot, and the " +
                "%^BLACK%^ground %^BOLD%^%^RED%^rumbles ominously!%^RESET%^");
    caster->set_property("spelled", ({ TO }));
    storm_room = PLACE;
    addSpellToCaster();
    spell_successful();
}

void execute_attack()
{
    object* foes = ({});
    int i;

    ::execute_attack();
    if (!objectp(mycaster) || !objectp(environment(mycaster)) || mycaster->query_unconscious()) {
        dest_effect();
        return;
    }
    if (count > 2) {
        dest_effect();
    }
    if (environment(mycaster) != storm_room) {
        tell_object(mycaster, "%^RESET%^%^GREEN%^The earth ceases its quaking as you leave the area.%^RESET%^");
        tell_room(storm_room, "%^RESET%^%^GREEN%^The earth ceases its quaking " +
                  "as " + mycaster->QCN + " leaves the area.%^RESET%^");
        dest_effect();
        return;
    }

    foes = target_selector();
    if (sizeof(foes)) {
        tell_room(storm_room, "%^YELLOW%^The earth ripples beneath you, throwing "
                  "up debris and making footing treacherous!%^RESET%^");
        for (i = 0; i < sizeof(foes); i++) {
            if (foes[i] == mycaster) {
                continue;
            }
            if (!storm_effects(foes[i])) {
                continue;
            }
        }
        if (count == 0) {
            for (i = 0; i < sizeof(foes); i++) {
                if (foes[i] == mycaster) {
                    continue;
                }
                if (!random(2)) {
                    if (!trip_em(foes[i])) {
                        continue;
                    }
                }
                continue;
            }
        }
        count++;
    }else {
        dest_effect();
        return;
    }
    place->addObjectToCombatCycle(TO, 1);
}

int storm_effects(object obj)
{
    object room;
    if (!objectp(obj)) {
        return 0;
    }
    if (!objectp(environment(obj))) {
        return 0;
    }
    if (environment(mycaster) != environment(obj)) {
        return 0;
    }
    room = environment(obj);

    tell_object(obj, "%^YELLOW%^The earth ripples beneath you, making " +
                "footing treacherous!%^RESET%^");
    define_base_damage(0);
    if (do_save(obj, 0)) {
        tell_object(obj, "%^ORANGE%^The debris grazes you, but you " +
                    "avoid the worst of it!%^RESET%^");
        tell_room(room, "%^ORANGE%^" + obj->QCN + " dodges the worst of " +
                  "the debris!%^RESET%^", obj);
        damage_targ(obj, obj->return_target_limb(), sdamage / 2, "bludgeoning");
    }else {
        tell_object(obj, "%^BOLD%^%^RED%^The debris from the unsettled earth " +
                    "tears at your flesh!%^RESET%^");
        tell_room(room, "%^BOLD%^%^RED%^" + obj->QCN + " is shredded by the " +
                  "debris!%^RESET%^", obj);
        damage_targ(obj, obj->return_target_limb(), sdamage, "bludgeoning");
    }
    return 1;
}

int trip_em(object obj)
{
    object room;
    if (!objectp(obj)) {
        return 0;
    }
    if (!objectp(environment(obj))) {
        return 0;
    }
    if (environment(mycaster) != environment(obj)) {
        return 0;
    }
    room = environment(obj);

    if (!do_save(obj), 4) {
        tell_object(obj, "%^RED%^You land hard, and the earth roils "
                    "as you struggle to stand!%^RESET%^");
        tell_room(room, "%^RED%^" + obj->QCN + " falls to the ground and "
                  "staggers around helplessly!%^%^RESET%^", obj);
        obj->set_tripped(1, "%^BOLD%^You are struggling " +
                         "to regain your footing!%^RESET%^", 4);
    }
    return 1;
}

void dest_effect()
{
    if (objectp(mycaster)) {
        tell_room(environment(mycaster), "%^CYAN%^The psychic grumbling subsides as the earth grows still.%^RESET%^");
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
