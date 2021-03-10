#include <std.h>
#include <daemons.h>
#include <spell.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("detect the faithful");
    set_spell_level(([ "inquisitor" : 1, "cleric" : 1, "druid" : 1, "inquisitor" : 1, "paladin" : 1, "ranger" : 1 ]));
    set_spell_sphere("divination");
    set_syntax("cast CLASS detect the faithful");
    set_damage_desc("reveals presence of members of your faith");
    set_description("You can detect the presence of other worshippers of your deity.");
    set_verbal_comp();
    set_somatic_comp();
}

void spell_effect(int prof)
{
    object *peeps;
    string mygod = caster->query_diety();

    peeps = all_living(place);
    peeps = filter_array(peeps, "is_non_immortal",FILTERS_D);
    peeps = filter_array(peeps,(:$1->query_diety()==$2:),mygod);
    peeps -=({caster});

    if(sizeof(peeps))
        tell_object(caster,"%^RED%^There are faithful present.%^RESET%^");
    else
        tell_object(caster,"%^RED%^No faithful are currently present.%^RESET%^");

    spell_successful();
    dest_effect();
}
