//adapted by ~Circe~ for psionics 7/21/05
// --==** /cmds/priest/_invisibility_purge.c **==--
// Created by Garrett@ShadowGate
// Jan 12, 2001

#include <priest.h>
inherit SPELL;

int value;
object where;

void create() {
    ::create();
    set_spell_name("eradicate invisibility");
    set_spell_level(([ "psion" : 3 ]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS eradicate invisibility");
    set_description("By manifesting this power, the psion creates a shimmering translucent dome that prevents anyone from "
"being masked by invisibility or simply hiding.  The nature of the manifestation is to create tiny motes in the air that "
"respond to disturbances by hidden creatures, revealing them to all in the area.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string() {
    return "%^ORANGE%^"+caster->QCN+" makes a gesture of dismissal across "+
       "the ground.";
}


void spell_effect(int prof) {
    int duration, amount, mylevel;

    mylevel = clevel;
    where = PLACE;

    tell_object(CASTER,"%^BOLD%^%^BLUE%^A translucent wave of energy "+
       "encircles you, radiating outward in a shower of %^YELLOW%^"+
       "motes %^BLUE%^to form a dome that fades away!");
    tell_room(PLACE,"%^BOLD%^%^BLUE%^A translucent wave of energy "+
       "encircles "+CASTER->QCN+", radiating outward in a shower of %^YELLOW%^"+
       "motes %^BLUE%^to form a dome that fades away!",CASTER);
    amount = mylevel/4;
    amount++;
    where->set_property("no invis", 1);
    where->set_property("spelled", ({TO}) );
    duration = (amount * 30);
    spell_successful();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    addSpellToCaster();
}

void dest_effect() {
    if (objectp(PLACE)){
      tell_room(PLACE,"%^BOLD%^%^BLUE%^A translucent dome shimmers into "+
         "effect, then dissipates in a few %^YELLOW%^shimmering motes"+
         "%^BLUE%^.");
      PLACE->set_property("no invis", -1);
      if (!PLACE->query_property("no invis"));
        PLACE->remove_property("no invis");
      PLACE->remove_property_value("spelled", ({TO}) );
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
