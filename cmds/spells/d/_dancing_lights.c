#include <spell.h>
#include <magic.h>
#include <std.h>

inherit SPELL;
object ob;

void create()
{
    ::create();
    set_spell_name("dancing lights");
    set_spell_level(([ "cantrip" : 1 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS dancing lights");
    set_description("This will create a small gathering of swirling lights, which will illuminate your way.");
    set_helpful_spell(1);
}

string query_cast_string()
{
    return "%^YELLOW%^" + CASTER->QCN + " swirls " + CASTER->QP + " fingers in the air.";
}

void spell_effect(int prof)
{
    int level;
    int duration;
    
    if(present("dancing lights", caster))
    {
        tell_object(caster, "You already have dancing lights on you.");
        return;
    }

    tell_object(caster, "%^BOLD%^%^WHITE%^Gleaming trails of l%^CYAN%^i%^WHITE%^gh%^YELLOW%^t %^WHITE%^spring into existance, following the motion of your fingertips!");
    tell_room(place, "%^BOLD%^%^WHITE%^Gleaming trails of l%^CYAN%^i%^WHITE%^gh%^YELLOW%^t %^WHITE%^spring into existance, following the motion of " + caster->QCN + "'s fingertips!", caster);

    level = clevel;
    ob = new("/d/magic/obj/dancinglights");
    duration = 60 * clevel + 180;
    duration = duration > 540 ? 540 : duration;
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    ob->set_property("spell", TO);
    ob->set_property("spelled", ({ TO }));
    ob->move(caster);
    spell_successful();
}

void dest_effect()
{
    if (find_call_out("dest_effect") != -1) {
        remove_call_out("dest_effect");
    }
    tell_room(place, "%^BOLD%^%^WHITE%^The bright lights suddenly snuff out, and the room grows a little darker.");
    if (objectp(ob)) {
        ob->remove();
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
