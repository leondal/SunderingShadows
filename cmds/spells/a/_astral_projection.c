#include <magic.h>
#include <std.h>
#include <spell.h>
#include <daemons.h>

inherit SPELL;

object *animated, *monsters, control;
string arg;
int amount;

void create() {
    ::create();
    set_spell_name("astral projection");
    set_spell_level((["oracle":9, "mage":9,"cleric":9, "psion":8 ]));
    set_discipline("nomad");
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS astral projection");
    set_mystery("ancestor");
    set_description("By freeing your spirit from your physical body, this spell allows you to project an astral body. The new body will look mostly like you, but will be invisible to others. Your new body will obey your commands and will convey everything that is happening around it into your mind. The death of your second body will send you into a brief shock and will slightly harm you.

This is a greater summons, and cannot be used simultaneously with other greater summons.
To remove projection use %^ORANGE%^<dismiss projection>%^RESET%^
To command projection use %^ORANGE%^<command projection to %^ORANGE%^%^ULINE%^ACTION%^RESET%^%^ORANGE%^>%^RESET%^
To force lost projection to follow use %^ORANGE%^<command projection to follow>%^RESET%^
To look around simply use %^ORANGE%^<command projection to look>%^RESET%^");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell()
{
    if (caster->query_property("has_elemental")) {
        tell_object(caster, "This is a greater summon, and you already have one!");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    object ob, thing;
    int bonus, power;

    tell_object(caster, "%^CYAN%^%^BOLD%^You feel dizzy as your senses bifurcate, you stand to the side and look upon yourself from another body.%^RESET%^");

    ob = new("/d/magic/mon/astral_projection.c");
    ob->set_alignment(caster->query_alignment());
    ob->setup_servant(caster, clevel);

    control = new("/d/magic/obj/holder");
    control->set_caster(caster);
    control->move(caster);
    control->set_elemental(ob);
    control->set_property("spell",TO);
    control->set_property("spelled", ({TO}) );

    caster->add_follower(ob);

    ob->move(environment(caster));

    ob->set_property("spell",TO);
    ob->set_property("spell", ({TO}) );
    ob->set_property("spell_creature", TO);
    ob->set_property("minion", caster);
    ob->set_race(caster->query_visual_race());
    ob->set_gender((string)caster->query_gender());
    ob->set_short(cm(caster->getWholeDescriptivePhrase()));
    ob->set_long(cm(caster->getWholeDescriptivePhrase() + " " +(string)caster->query_description()));
    ob->set("speech string",cm(caster->query("speech string")));
    ob->set("describe string",cm(caster->query("describe string")));

    addSpellToCaster();

    return;
}

void dest_effect()
{
    object sword;

    if (objectp(control)) {
        if (objectp(sword = control->query_mon())) {
            sword->remove();
            destruct(control);
        }
    }
    if (objectp(caster)) {
        tell_object(caster,"%^BOLD%^Your concentration on another body fades.");
        caster->remove_property("has_elemental");
    }
    ::dest_effect();
    if (objectp(TO))
        TO->remove();
}

string cm(string str)
{
    return CRAYON_D->color_string(strip_colors(str),"grey");
}
