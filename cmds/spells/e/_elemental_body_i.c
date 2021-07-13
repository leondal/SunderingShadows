#include <spell.h>
#include <daemons.h>
#include <magic.h>
inherit SPELL;

string element;
mapping elementmap;
elementmap = ([
                  "fire":"%^RESET%^%^RED%^f%^YELLOW%^i%^RED%^r%^RESET%^%^RED%^e",
                  "air":"%^RESET%^%^CYAN%^a%^BOLD%^%^WHITE%^i%^RESET%^%^CYAN%^r%^RESET%^",
                  "earth":"%^RESET%^%^ORANGE%^e%^RESET%^a%^ORANGE%^r%^YELLOW%^t%^RESET%^%^ORANGE%^h%^RESET%^",
                  "water":"%^BOLD%^%^BLUE%^w%^CYAN%^a%^WHITE%^t%^CYAN%^e%^BLUE%^r%^RESET%^"
                  ]);

string query_element()
{
    return element;
}

void effect(int direction)
{
    /*
    if(direction>0)
        caster->set_property("augmentation");
    else
        caster->remove_property("augmentation");
    */

    switch(query_element())
    {
        case "air":
            caster->add_stat_bonus("dexterity",2*direction);
            caster->add_ac_bonus(2*direction);
            break;
        case "earth":
            caster->add_stat_bonus("strength",2*direction);
            caster->add_ac_bonus(4*direction);
            break;
        case "fire":
            caster->add_stat_bonus("dexterity",2*direction);
            caster->add_ac_bonus(2*direction);
            break;
        case "water":
            caster->add_stat_bonus("constitution",2*direction);
            caster->add_ac_bonus(4*direction);
            break;
    }
    return;
}


string *valid_forms()
{
    return ({"fire","air","earth","water"});
}

void create()
{
    ::create();
    set_spell_name("elemental body i");
    set_spell_level(([ "mage" : 4, "oracle" : 4 ]));
    set_mystery("elemental");
    set_spell_sphere("alteration");
    set_bonus_type(({ "size", "natural armor" }));
    set_syntax("cast CLASS "+query_spell_name()+" on fire|air|earth|water");
    set_description("When you cast this spell, you infuse yourself with the power of the element. Infusions give the next effects as follows:

  fire:  +2 dexterity,     +2 armor class
  air:   +2 dexterity,     +2 armor class
  earth: +2 strength,      +4 armor class
  water: +2 constitution,  +4 armor class");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

int preSpell()
{
    object shape;
    if (objectp(shape = caster->query_property("shapeshifted")) ||
        objectp(shape = caster->query_property("altered"))) {
        tell_object(caster, "You are already in an alternative form!");
        return 0;
    }
    if (member_array(arg, valid_forms()) == -1) {
        tell_object(caster, "Invalid form, valid forms are: " + implode(valid_forms(), ", "));
        return 0;
    }
    /*
    if (caster->query_property("augmentation")) {
        tell_object(caster, "%^YELLOW%^You are already under the influence of a similar spell.");
        return 0;
    }
    */
    if(spell_type == "innate" && FEATS_D->usable_feat(caster,"command the stone") && arg != "earth") {
        tell_object(caster,"You can only take on the form of an EARTH elemental!");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    object shape;
    if (!objectp(caster)) {
        TO->remove();
        return;
    }
    element = arg;

    tell_object(caster, "You bow your head, concentrating and infusing your body with the power of " + elementmap[element] + ".");
    tell_room(place, caster->QCN + "'s body turns into " + elementmap[element] + "!", caster);

    new("/std/races/shapeshifted_races/mage_elemental.c")->init_shape(caster, "elemental");

    shape = caster->query_property("shapeshifted");
    shape->set_clevel(clevel);
    caster->set_property("spelled", ({ TO }));
    //caster->set_property("augmentation", 1);

    effect(1);
    addSpellToCaster();
    spell_successful();
}

void dest_effect()
{
    object shape;
    if (objectp(caster)) {
        if (objectp(shape = caster->query_property("shapeshifted"))) {
            shape->reverse_shape(caster);
        }
        tell_object(caster, "You feel loss and weakness as your body looses infusion of " + elementmap[element] + ".");
        effect(-1);
        //caster->remove_property("augmentation");
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
