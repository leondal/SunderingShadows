#include <priest.h>
#include <magic.h>
#include <spell.h>

inherit SPELL;

int timer, flag, stage, toggle, counter;

void create()
{
    ::create();
    set_author("ares");
    set_spell_name("call lightning storm");
    set_spell_level(([ "druid" : 5 ]));
    set_spell_sphere("combat");
    set_save("reflex");
    set_syntax("cast CLASS call lightning storm");
    set_description("This spell will cause the caster to become charged with static electricity.  The electricity will occasionally "
        "discharge at one of the caster's enemies, hitting him or her with a powerful blast of lightning.");
    set_property("magic",1);
    set_casting_time(1);
    set_helpful_spell(1);
    traveling_aoe_spell(1);
}

void spell_effect(int prof)
{
    int duration;
    duration = (ROUND_LENGTH * 6) * clevel;
    tell_object(caster,"%^YELLOW%^Your eyes suddenly snap open wide as you feel the cr%^RESET%^a%^BOLD%^c%^YELLOW%^k%^RESET%^%^YELLOW%^le of static energy fill your body!");
    tell_room(place,"%^YELLOW%^"+caster->QCN+"'s eyes suddenly snap open wide and you can see electricity dancing dangerously in them!",caster);

    caster->set_property("spelled", ({ TO }));
    caster->set_property("call lightning storm",1);
    caster->set_property("added short",({"%^YELLOW%^ (crackling with electrical energy)%^RESET%^"}));
    addSpellToCaster();
    spell_successful();
    counter = 2 * clevel;
    execute_attack();
    call_out("room_check", ROUND_LENGTH);
}

void room_check()
{
    if (!objectp(caster) || !objectp(ENV(caster))) {
        dest_effect();
        return;
    }

    prepend_to_combat_cycle(ENV(caster));

    call_out("room_check", ROUND_LENGTH * 2);
    return;
}

void execute_attack(){
    object *foes=({}),targ;
    int i;

    if (!flag) {
        flag = 1;
        ::execute_attack();
        return;
    }

    place = ENV(caster);

    if (!objectp(caster) || !objectp(place) || counter < 0) {
        dest_effect();
        return;
    }

    if (!random(100)) {
        tell_room(place, "%^YELLOW%^Electricity pops and crackles, dancing in the air around " + caster->QCN + "!", caster);
        tell_object(caster, "%^YELLOW%^Electricity pops and crackles, dancing in the air around you!");
    }

    foes = caster->query_attackers();

    if (sizeof(foes)) {
        define_base_damage(0);         //reroll each turn
        tell_room(place, "%^BOLD%^%^ORANGE%^Electricity around " + caster->QCN + " zaps " + caster->QP + " enemies!", ({ caster, target }));
        tell_object(caster, "%^BOLD%^%^ORANGE%^Electricity zaps your enemies!");

        define_base_damage(0);
        for (i = 0; i < sizeof(foes); i++) {
            if (do_save(foes[i], 0)) {
                tell_object(foes[i],"%^BOLD%^%^YELLOW%^A bolt of electricity leaps out from "+caster->QCN+"'s body and zaps you square in the chest!");
                damage_targ(foes[i],foes[i]->return_target_limb(),sdamage/2,"electricity");
            } else {
                tell_object(foes[i],"%^RESET%^%^BOLD%^A bolt of electricity leaps out from "+caster->QCN+"'s body and you barely turn aside at the last instant, avoiding most of the damage!");
                foes[i] && damage_targ(foes[i],foes[i]->return_target_limb(),sdamage,"electricity");
            }
        }
    }
    prepend_to_combat_cycle(place);
    counter--;
}

void dest_effect()
{
    remove_call_out("room_check");
    if (objectp(caster)) {
        tell_object(caster,"%^RESET%^%^BOLD%^With a final loud pop, the electrical energy coursing through your body dissipates in an instant.");
        tell_room(environment(caster),"%^RESET%^%^BOLD%^With a final loud pop, the electrical energy coursing through " +caster->QCN+"'s body dissipates in an instant.",caster);
	    caster->remove_property_value("added short",({"%^YELLOW%^ (crackling with electrical energy)%^RESET%^"}));
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
