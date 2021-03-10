#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

#define HORSE "/d/magic/mon/mounts/"
inherit SPELL;

object ob;

void create()
{
    ::create();
    set_author("nienne");
    set_spell_name("bonded steed");
    set_spell_level(([ "paladin" : 2 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS bonded steed");
    set_description("By means of this spell, the caster beseeches their god to send a noble steed to their aid.\n\nThis spell will not work if you are already mounted.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string()
{
    return "%^ORANGE%^" + caster->QCN + " brings both hands forward, "
        "and then raises one upwards to pause above " + caster->QP +
        " head, and the other downwards to rest at leg-height.%^RESET%^";
}

int preSpell()
{
    if (caster->query_in_vehicle()) {
        tell_object(caster, "A steed will not come if you are already mounted.");
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

    tell_room(place, "%^ORANGE%^Just in front of " + caster->QCN +
              " along the path of " + caster->QP + " arms, a thin %^BLUE%^tear "
              "%^ORANGE%^becomes apparent in the air!%^RESET%^", caster);
    tell_object(caster, "%^ORANGE%^Just in front of you along the path of your "
                "arms, a thin %^BLUE%^tear %^ORANGE%^becomes apparent in the air!%^RESET%^");
    call_out("mount", 2);
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

    tell_object(caster, "%^ORANGE%^The tear widens as a narrow hooved leg "
                "emerges from it, followed by the rest of a proud %^RED%^equine %^ORANGE%^creature. "
                "You blink, and the tear in the air has already disappeared behind it.%^RESET%^");
    ob = new(HORSE + "bonded_steed");
    ob->set_property("spell", TO);
    ob->set_property("spell_creature", TO);
    ob->set_property("minion", caster);
    ob->set_owner(caster);
    ob->set_level(clevel);
    ob->set_max_hp(clevel * 10);
    ob->set_hp(ob->query_max_hp());
    ob->move(place);
    switch ((int)caster->query_alignment() % 3) {
    case 1:
        ob->set_short("%^BOLD%^%^WHITE%^A mag%^RESET%^ni%^BOLD%^%^BLACK%^f%^RESET%^ic%^BOLD%^%^WHITE%^ent steed trained for battle%^RESET%^");
        ob->set_long("%^BOLD%^%^WHITE%^This is a powerfully built, well trained destrier.  Its glossy ebon-black coat covers "
                     "toned muscles accustomed to the demands of combat, and its dark eyes gleam with the dangerous nature trained into such "
                     "steeds.  Polished barding offers a shell of protection to the fine beast, with specially fitted plates to protect its "
                     "flanks and rear, and chainmail draped across areas accustomed to greater motion.  A fine sheet of cloth has been draped "
                     "down from the saddle, emblazoned with the symbol of " + caster->query_diety() + ".  Clearly this horse belongs to someone "
                     "very well trained and it would be dangerous for anyone lesser to try and ride it.");
        ob->set_vehicle_short("%^BOLD%^%^BLACK%^A mag%^RESET%^ni%^BOLD%^f%^RESET%^ic%^BOLD%^%^BLACK%^ent steed trained for battle%^RESET%^");
        break;
    case 3:
        ob->set_short("%^BOLD%^%^WHITE%^A mag%^RESET%^ni%^BOLD%^f%^RESET%^ic%^BOLD%^%^WHITE%^ent steed trained for battle%^RESET%^");
        ob->set_long("%^BOLD%^%^BLACK%^This is a powerfully built, well trained destrier.  Its glossy ebon-black coat covers "
                     "toned muscles accustomed to the demands of combat, and its dark eyes gleam with the dangerous nature trained into such "
                     "steeds.  Polished barding offers a shell of protection to the fine beast, with specially fitted plates to protect its "
                     "flanks and rear, and chainmail draped across areas accustomed to greater motion.  A fine sheet of cloth has been draped "
                     "down from the saddle, emblazoned with the symbol of " + caster->query_diety() + ".  Clearly this horse belongs to someone "
                     "very well trained and it would be dangerous for anyone lesser to try and ride it.");
        ob->set_vehicle_short("%^BOLD%^%^BLACK%^A mag%^RESET%^ni%^BOLD%^f%^RESET%^ic%^BOLD%^%^BLACK%^ent steed trained for battle%^RESET%^");
        break;
    default:
        ob->set_short("%^RESET%^%^ORANGE%^A mag%^RESET%^ni%^BOLD%^f%^RESET%^ic%^ORANGE%^ent steed trained for battle%^RESET%^");
        ob->set_long("%^RESET%^%^ORANGE%^This is a powerfully built, well trained destrier.  Its glossy ebon-black coat covers "
                     "toned muscles accustomed to the demands of combat, and its dark eyes gleam with the dangerous nature trained into such "
                     "steeds.  Polished barding offers a shell of protection to the fine beast, with specially fitted plates to protect its "
                     "flanks and rear, and chainmail draped across areas accustomed to greater motion.  A fine sheet of cloth has been draped "
                     "down from the saddle, emblazoned with the symbol of " + caster->query_diety() + ".  Clearly this horse belongs to someone "
                     "very well trained and it would be dangerous for anyone lesser to try and ride it.");
        ob->set_vehicle_short("%^RESET%^%^ORANGE%^A mag%^RESET%^ni%^BOLD%^f%^RESET%^ic%^ORANGE%^ent steed trained for battle%^RESET%^");
        break;
    }
    caster->force_me("mount bonded steed");
    return;
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
