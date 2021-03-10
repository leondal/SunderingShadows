// --==** /cmds/priest/_create_food.c **==--
// Modified by Pator@ShadowGate
// August 25 1995, 11/2/95

#include <priest.h>
inherit SPELL;

object food;
create() {
    ::create();
    set_author("pator");
    set_spell_name("create food");
    set_spell_level(([ "cleric" : 3, "paladin" : 2, "inquisitor" : 1 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS create food");
    set_description("This spell creates a pile of edible food. You can eat some if you wish. The higher level the caster, "
"the more food will be created.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell() {
    if (present("pile of food", PLACE)) {
        tell_object(CASTER, "There is already a pile of food here.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    object  where;
    int duration, amount;

    if (interactive(CASTER)) {
        tell_object(CASTER, "You create a pile of edible food.");
        tell_room(PLACE, YOU+" makes a pile of edible food.", ({ CASTER}) );
        food = new("/cmds/priest/obj/food.c");
        where = environment(CASTER);
    } else {
        tell_room(PLACE, YOU+" conjures a pile of edible food.", ({ CASTER}) );
        food = new("/cmds/priest/obj/food.c");
        where = place;
    }

    amount = clevel/2;
    amount++;
    food->set_eats(amount);
    food->move(where);
    food->set_property("spelled", ({TO}) );

    duration = clevel * 60;

    spell_successful();
    addSpellToCaster();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect() {
    if (objectp(food)) {
        food->remove();
        tell_room(HERE,"The pile of food vanishes into nothingness!");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
