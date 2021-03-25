#include <spell.h>
#include <magic.h>
#include <daemons.h>
#include <clock.h>
inherit SPELL;

#define OKTYPES ({ "acid", "cold", "electricity", "fire", "sonic" })
int didbuff, reversed, resistanceamount;
string myelement;

void create()
{
    ::create();
    set_spell_name("resist energy");
    set_spell_level(([ "paladin" : 2, "ranger" : 1, "druid" : 2, "mage" : 2, "paladin" : 3, "inquisitor" : 2, "cleric" : 3]));
    set_mystery(({ "dragon", "flame", "elemental" }));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS resist energy on <element>");
    set_description("This spell bestows the caster with a small amount of damage resistance against a selected element, increasing with the caster's level. Elements that can be chosen are acid, cold, electricity, fire, or sonic.

%^BOLD%^%^RED%^See also:%^RESET%^ status effects");
    set_verbal_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

int preSpell()
{
    if (caster->query_property("castspellresist")) {
        tell_object(caster, "%^YELLOW%^You are already under the influence of a similar spell.");
        return 0;
    }
    resistanceamount = clevel * 3 / 2;
    return 1;
}

void spell_effect(int prof)
{
    if (!objectp(caster)) {
        TO->remove();
        return;
    }
    if (!ARG) {
        tell_object(caster, "%^YELLOW%^The spell fizzles as you fail to concentrate on an element. Only acid, cold, electricity, fire, or sonic can be resisted.%^RESET%^");
        dest_effect();
        return;
    }

    if (member_array(ARG, OKTYPES) == -1) {
        tell_object(caster, "%^YELLOW%^The spell fizzles as you fail to concentrate on an element. Only acid, cold, electricity, fire, or sonic can be resisted.%^RESET%^");
        dest_effect();
        return;
    }

    if (objectp(place)) {
        place = environment(caster);
    }
    if ((string)TO->query_spell_type() == "potion") {
        if (caster->query_property("castspellresist")) {
            tell_object(caster, "%^YELLOW%^You are already under the influence of a similar affect.");
            TO->remove();
            return;
        }
        if (prof == -100) {
            reversed = 1;
            tell_object(caster, "%^CYAN%^You feel a protective ward spring to life around you, but something feels... wrong.%^RESET%^");
        }
        tell_object(caster, "%^CYAN%^You feel a protective ward spring to life around you.%^RESET%^");
    }else {
        tell_object(caster, "%^CYAN%^You invoke a protective ward around yourself.%^RESET%^");
        tell_room(place, "%^CYAN%^" + caster->QCN + " invokes a protective ward about " + caster->QO + "self.%^RESET%^", caster);
    }
    caster->set_resistance(ARG, resistanceamount);
    caster->set_property("castspellresist", 1);
    didbuff = 1;
    spell_successful();
    addSpellToCaster();
}

void dest_effect()
{
    if (objectp(caster) && didbuff) {
        tell_object(caster, "%^CYAN%^You feel the protective ward fade from you.%^RESET%^");
        caster->set_resistance(ARG, -resistanceamount);
        caster->set_property("castspellresist", -1);
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
