// --==** /cmds/priest/_invisibility_purge.c **==--
// Created by Garrett@ShadowGate
// Jan 12, 2001
#include <priest.h>
inherit SPELL ;

int value;
object where;

void create() {
    ::create();
    set_author("garrett");
    set_spell_name("invisibility purge");
    set_spell_level(([ "cleric" : 3, "inquisitor" : 3 ]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS invisibility purge");
    set_description("This spell reveals all invisible and hiding beings in the room where the caster has cast his spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

void spell_effect(int prof)
{
    int duration, amount, clevel;
    where = PLACE;

    tell_object(CASTER,"%^CYAN%^This room is purged of invisibility!");
    tell_room(PLACE,"%^CYAN%^"+YOU+" raises "+MINE+" hands and chants in a voice filled with power!", ({ CASTER}) );

    amount = clevel/4;
    amount++;
    where->set_property("no invis", 1);
    where->set_property("spelled", ({TO}) );
    // The time the room will be purged of invisibility...
    duration = ( amount * 30);
    if (duration < 250) duration = 250;
    spell_successful();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    addSpellToCaster();
}

void dest_effect()
{
    if (objectp(PLACE)){
      PLACE->set_property("no invis", -1);
      if (!PLACE->query_property("no invis")) PLACE->remove_property("no invis");
      PLACE->remove_property_value("spelled", ({TO}) );
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
