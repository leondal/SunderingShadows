#include <spell.h>
#include <daemons.h>
inherit SPELL;
int bonus;

int feattracker;

string *valid_forms()
{
    return ({"wererat","rat",});
}

void create()
{
    ::create();
    set_spell_name("wererat shape");
    set_spell_level(([ "innate" : 1 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS wererat shape on wererat|rat");
    set_description("With this power, those infected with the wererat plague can morph at will into a powerful form that resembles a larger, more powerful, version of a ratkin, or into the form of a dire rat.

%^BOLD%^%^RED%^N.B.%^RESET%^ You can set an alternative description, speech string and adjective for these forms.

%^BOLD%^%^RED%^See also:%^RESET%^ wererat, ratkin");
    set_arg_needed();
    set_helpful_spell(1);
}

int preSpell()
{
    object shape;
    if(objectp(shape = caster->query_property("shapeshifted")) ||
       objectp(shape = caster->query_property("altered")))
    {
        tell_object(caster,"You are already in an alternative form!");
        return 0;
    }
    if(member_array(arg,valid_forms())==-1)
    {
        tell_object(caster,"Invalid form, valid forms are: "+implode(valid_forms(),", "));
        return;
    }
    return 1;
}

void spell_effect(int prof)
{
    object shape;
    if (!objectp(caster)){
        TO->remove();
        return;
    }
    new("/std/races/shapeshifted_races/wererat_"+arg+".c")->init_shape(caster,arg);

    if(caster->query_property("shapeshifted"))
        shape = caster->query_property("shapeshifted");
    else
        shape = caster->query_property("altered");

    spell_successful();
    addSpellToCaster();
}

void dest_effect()
{
    object shape;
    if (objectp(caster)) {

        if (caster->query_property("shapeshifted")) {
            shape = caster->query_property("shapeshifted");
        } else {
            shape = caster->query_property("altered");
        }
        if (objectp(shape)) {
            shape->reverse_shape(caster);
        }
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
