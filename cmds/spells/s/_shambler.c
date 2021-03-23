#include <magic.h>
#include <std.h>
#include <spell.h>
inherit SPELL;

object* animated, * monsters, control;
string arg;
int amount;

void create()
{
    ::create();
    set_spell_name("shambler");
    set_spell_level(([ "druid" : 9,"oracle":9, "cleric" : 9]));
    set_domains("plant");
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS shambler");
    set_description("Call to shambling mound to aid you in combat.

This is a greater summons, and cannot be used simultaneously with other greater summons.
To remove shambler use %^ORANGE%^<dismiss shambler>%^RESET%^
To command shambler use %^ORANGE%^<command shambler to %^ORANGE%^%^ULINE%^ACTION%^RESET%^%^ORANGE%^>%^RESET%^
To force lost shambler to follow use %^ORANGE%^<command shambler to follow>%^RESET%^");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}
int preSpell()
{
    if (caster->query_property("mages_sword") || caster->query_property("has_elemental")) {
        tell_object(caster, "You already have a powerful summoned creature under your control.");
        return 0;
    }
    return 1;
}
void spell_effect(int prof)
{
    if (!objectp(environment(caster))) {
        dest_effect();
        return;
    }
    place = environment(caster);
    summon_servant();
}
void summon_servant()
{
    object ob, thing;

    tell_object(caster, "%^GREEN%^%^BOLD%^Small plant breaks through the floor and quickly grows into a shambling mound to stand before you and obey your commands.%^RESET%^");
    tell_room(place, "%^GREEN%^%^BOLD%^Small plant breaks through the floor and quickly grows into a shambling mound.%^RESET%^", caster);

    ob = new("/d/magic/mon/shambler.c");
    ob->setup_servant(caster, clevel);

    control = new("/d/magic/obj/holder");
    control->set_caster(caster);
    control->move(caster);
    control->set_elemental(ob);
    control->set_property("spell", TO);
    control->set_property("spelled", ({ TO }));


    caster->add_follower(ob);

    ob->move(environment(caster));

    ob->set_property("spell", TO);
    ob->set_property("spell", ({ TO }));
    ob->set_property("spell_creature", TO);
    ob->set_property("minion", caster);

    addSpellToCaster();

    caster->set_property("has_elemental", ob);
    return;
}
void dest_effect()
{
    object sword;

    if (objectp(caster)) {
        tell_object(caster, "%^GREEN%^Shambling mound shambles away.%^RESET%^");
    }

    if (objectp(control)) {
        if (objectp(sword = control->query_mon())) {
            sword->remove();
            destruct(control);
        }
    }
    if (objectp(caster)) {
        caster->remove_property("has_elemental");
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
