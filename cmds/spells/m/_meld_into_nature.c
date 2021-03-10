// Invisibility - Coded by Vashkar@shadowgate
// Made to a 4th lvl spell and changed diety to all, intended for rangers only- Dinji 3/21/05

#include <spell.h>
#include <magic.h>
#include <rooms.h>

inherit SPELL;

object invisob;


create()
{
    ::create();
    set_spell_name("meld into nature");
    set_spell_level((["ranger" : 4, "druid" : 3 ]));
    set_spell_sphere("illusion");
    set_syntax("cast CLASS meld into nature");
    set_description("This spell will allow you to hide yourself in the land around you magically. It will not function within urban areas.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}


string query_cast_string()
{
    if(objectp(caster)) { return "%^GREEN%^"+caster->QCN+" begins to pull the nature of the world around "+caster->QO; }
    return "";
}


int preSpell()
{
    if(lower_case((string)PLACE->query_terrain()) == "city" || lower_case((string)PLACE->query_terrain()) == "village")
    {
        tell_object(CASTER,"You need to be within the wilds to wrap yourself in the nature you love so much.");
        return 0;
    }
    return 1;
}


spell_effect(int prof)
{
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    if (!target) { target = caster; }
    tell_object(caster,"%^GREEN%^Your words and prayers begin to fold nature around you.");
    tell_room(place,"%^GREEN%^"+caster->QCN+" prays as "+caster->QCN+" pulls nature and "
        "shrouds "+caster->QO+"self.",caster);
    call_out("targ_vanish",2);
}


void targ_vanish()
{
    if(!objectp(target))
    {
        dest_effect();
        return;
    }
    spell_successful();
    invisob=new("/d/magic/obj/invisobcl.c");
    invisob->set_property("spell",TO);
    invisob->set_property("spelled", ({TO}) );
    invisob->move_is_ok(1);
    invisob->move(target);
    if(!objectp(invisob))
    {
        dest_effect();
        return;
    }
    invisob->move_is_ok(0);
    addSpellToCaster();
}


void dest_effect()
{
   // putting in safeguard to prevent further player bugs. Nienne, 03/09
    if(objectp(invisob)) invisob->show_up();
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
