#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

#define HORSE "/d/magic/mon/mounts/skelehorse"
inherit SPELL;

object ob;

void create()
{
    ::create();
    set_spell_name("undead steed");
    set_spell_level(([ "paladin" : 3, "mage" : 3, "cleric" : 3, "magus" : 3 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS undead steed");
    set_description("This spell summons an undead skeletal horse.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string()
{
    return "%^BLUE%^" + caster->QCN + " brings both hands forward, "
        "and then beckons them together towards " + caster->QO +
        "self%^RESET%^.";
}

int preSpell()
{
    if (caster->query_in_vehicle()) {
        tell_object(caster, "A mount will not come if you are already mounted.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    string name;

    if (!objectp(caster)) {
        return 0;
    }
    if (objectp(place)) {
        place = environment(caster);
    }
    name = caster->QCN;

    tell_room(place, "%^BLUE%^A faint, translucent %^RESET%^m%^CYAN%^i%^RESET%^s%^CYAN%^t %^BLUE%^becomes apparent in the air before you, forming the outline of an undead!%^RESET%^");
    call_out("mount", 5);
}

void mount()
{
    string name;

    name = caster->QCN;
    if (!objectp(caster)) {
        return 0;
    }
    if (objectp(place)) {
        place = environment(caster);
    }

    tell_object(caster, "%^BLUE%^The skeletal horse slowly becomes material enough to discern the undead form of skeletal horse. It paws the ground with perfectly %^BLUE%^silent %^WHITE%^hooves.%^RESET%^");
    ob = new(HORSE);
    ob->set_property("spell", TO);
    ob->set_property("spell_creature", TO);
    ob->set_owner(caster);
    ob->move(place);
    caster->force_me("mount skeletal horse");
    return;
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
