#include <std.h>
#include <daemons.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("mytherceria");
    set_spell_level(([ "innate" : 5 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS mytherceria");
    set_description("You extend your senses beyond your body to observe presence of the blood.");
    set_blood_magic(1);
    set_verbal_comp();
    set_helpful_spell(1);
    set_silent_casting(1);
}

void spell_effect(int prof)
{
    string myloc, * exploded, mydir;
    object* peo, * targets;
    int i;

    if (!objectp(place)) {
        dest_effect();
        return;
    }

    myloc = base_name(place);
    exploded = explode(myloc, "/");
    if (!sizeof(exploded)) {
        dest_effect();
        return;
    }

    exploded -= ({ exploded[(sizeof(exploded)) - 1] });

    if (!sizeof(exploded)) {
        dest_effect();
        return;
    }

    mydir = "/" + implode(exploded, "/") + "/";

    spell_successful();

    caster->add_bloodlust(-500);

    peo = ({});
    peo += collapse_array(map(map(place->query_exits(), (: $2->query_exit($1) :), place) + ({ ENV(caster) }), (: all_living(find_object_or_load($1)) :)));
    peo = filter_array(peo, (:RACE_D->is_valid_blooddrain_target($1, $2):), caster);
    peo = filter_array(peo, (:!avatarp($1):));

    if (!sizeof(peo)) {
        tell_object(caster, "%^BOLD%^%^RED%^You can sense no blood nearby.%^RESET%^");
        dest_effect();
        return;
    }

    tell_object(caster, "%^BOLD%^%^RED%^You can sense the presence of blood nearby.%^RESET%^");

    for (i = 0; i < sizeof(peo); i++) {
        tell_object(caster, "" + peo[i]->query_short() + "%^RESET%^ is near " + (environment(peo[i]))->query_short() + "%^RESET%^.");
    }

    dest_effect();
    return;
}
