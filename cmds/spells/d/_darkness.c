// darkness
#include <spell.h>
#include <magic.h>
#include <std.h>

inherit SPELL;
object ob;

void create()
{
    ::create();
    set_spell_name("darkness");
    set_spell_level(([ "mage" : 2, "bard" : 2, "cleric" : 2, "monk" : 3, "assassin" : 2, "paladin" : 2, "inquisitor" : 1, "monk" : 5, "magus" : 2 ]));
    set_spell_sphere("invocation_evocation");
    set_monk_way("way of the shadow");
    set_monk_way("way of the shadow");
    set_syntax("cast CLASS darkness");
    set_description("This will create a globe of darkness, which will overcome normal light sources. You can only possess one globe of darkness at a time.");
    set_verbal_comp();
    set_non_living_ok(1);
    set_helpful_spell(1);
}

string query_cast_string()
{
    return "%^YELLOW%^" + CASTER->QCN + " closes " +
        CASTER->QP + " eyes and reaches out " +
        CASTER->QP + " hands, gathering in energy.";
}

int set_darkness_power()
{
    return 1;
}

void spell_effect(int prof)
{
    int level;
    int power = set_darkness_power();
    int duration;

    level = clevel;
    
    if(present("globe of darkness", caster))
    {
        tell_object(caster, "You already have a globe of darkness.");
        return;
    }
    
    tell_object(caster, "You create a darkness around you.");
    tell_room(place, caster->QCN + " causes the room to darken.", ({ caster, target }));

    ob = new("/d/magic/obj/darkness");
    duration = 60 * clevel + 180;
    duration = duration > 540 ? 540 : duration;
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    if (objectp(ob)) {
        ob->set_property("spell", TO);
        ob->set_property("spelled", ({ TO }));
    }
    
    ob->move(caster, power);

    spell_successful();
}

void dest_effect()
{
    if (find_call_out("dest_effect") != -1) {
        remove_call_out("dest_effect");
    }
    if (objectp(ob)) {
        ob->remove();
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
