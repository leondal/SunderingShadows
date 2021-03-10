// light
//Giving paladins light after discussions with other Imms ~Circe~ 2/20/13
//When/if daylight changes, they may lose light again

#include <spell.h>
#include <magic.h>
#include <std.h>

inherit SPELL;
object ob;

create()
{
    ::create();
    set_spell_name("light");
    set_spell_level(([ "mage" : 1, "cleric" : 1, "paladin" : 1, "assassin" : 1, "inquisitor" : 1, "magus" : 1 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS light on TARGET");
    set_description("This will create a small ball of light, which will light your way. You can cast it on an object or "
                    "player which it will follow, instead of the caster.");
    set_non_living_ok();
    set_target_required(1);
    set_helpful_spell(1);
}

string query_cast_string()
{
    return "%^YELLOW%^" + CASTER->QCN + " closes " +
        CASTER->QP + " eyes and reaches out " +
        CASTER->QP + " hands, gathering in energy.";
}

spell_effect(int prof)
{
    int level;
    int duration;

    if (interactive(caster)) {
        tell_object(caster, "You create a mystical light source.");
        tell_room(place, caster->QCN + " makes a mystical light source.", ({ caster, target }));
        if (interactive(target) && !(caster == target)) {
            tell_object(target, caster->QCN + " touches you and a light appears.\n");
        }
    } else {
        tell_room(place, caster->QCN + " creates a mystical light source.", caster);
    }
    level = clevel;

    ob = new("/d/magic/obj/light");
    duration = 60 * clevel + 180;
    duration = duration > 540 ? 540 : duration;
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    ob->set_property("spell", TO);
    ob->set_property("spelled", ({ TO }));

    if (!target) {
        ob->move((TP));
    }else {
        ob->move((target));
    }
    spell_successful();
}

void dest_effect()
{
    if (find_call_out("dest_effect") != -1) {
        remove_call_out("dest_effect");
    }
    tell_room(place, "%^YELLOW%^The room is suddenly darker.");
    if (objectp(ob)) {
        ob->remove();
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
