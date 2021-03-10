/*
  _wall_walker.c

  From PF SRD. Behaves like spider climb.

  -- Tlaloc --
*/

#include <priest.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("wall walker");
    set_spell_level( ([ "psywarrior" : 2 ]) );
    set_spell_sphere("alteration");
    set_syntax("cast CLASS wall walker");
    set_description("With this power, the caster becomes able to walk on walls and even ceilings and greatly enhances their ability to climb.");
    set_helpful_spell(1);
}

int preSpell()
{
    if(caster->query_property("spider climb"))
    {
        tell_object(caster, "You are already affected by a similar spell.");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
    tell_object(caster, "%^CYAN%^BOLD%^You focus inwardly with your mind and begin to change your body.%^RESET%^");
    tell_room(place, "%^CYAN%^BOLD%^" + caster->query_cap_name() + " focuses inwardly with " + caster->query_possessive() + " mind.%^RESET%^");
    return "display";
}

void spell_effect(int prof)
{
    tell_object(caster, "%^BOLD%^You change the makeup of your body to adhere to surfaces. You can now climb with superhuman ability!%^RESET%^");
    tell_room(place, "%^BOLD%^" + caster->query_cap_name() + " seems to change the very makeup of their body.%^RESET%^");
    caster->set_property("spider climb", 1);
    spell_successful();
    addSpellToCaster();
    spell_duration = 900 + (clevel + roll_dice(1, 20)) * 10;
    set_end_time();
    call_out("dest_effect", spell_duration);
}

void dest_effect()
{
    if(objectp(caster))
    {
        caster->remove_property("spider climb");
        tell_object(caster, "%^CYAN%^The ability to walk on walls fades from you.%^RESET%^");
    }
    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}
