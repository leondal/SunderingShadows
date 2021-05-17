//adapted from rope trick by
//~Circe~ for use with psions

#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>

inherit SPELL;

int mylevel;
object portal;
string roomName;

void create() {
    ::create();
    set_spell_name("genesis");
    set_spell_level(([ "psion" : 2 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS genesis");
    set_description("Manifesting the unusual power genesis allows the psion to create a small demiplane for a time.  This "
"plane exists only for the caster and those invited in, or those who can find the original entry point.  Because of the "
"lesser nature of the power, the demiplane will not last forever, though it can be held for longer as the psion gains in "
"strength.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

void spell_effect(int prof)
{
    if(!objectp(caster) || !objectp(place))
    {
        dest_effect();
        return;
    }
    if (place->query_property("no pocket space")) {
        tell_object(caster, "Something is interferring with your power.");
        if(objectp(TO)) TO->remove();
        return 0;
    }

    mylevel = clevel;

    //caster = CASTER;
    //place = PLACE;
    portal = new(SPELL_OBJ_DIR+"genesis_portal");
    tell_object(caster, "%^BLUE%^You toss a piece of malachite, causing it "+
       "to spin rapidly in the air!");
    tell_room(place, "%^BLUE%^"+caster->QCN+" tosses a piece of malachite "+
       "and it floats in midair, spinning!", caster);
    spell_successful();
    roomName = base_name(place);
    portal->move(place);
    portal->set_property("spell", TO );
    portal->set_property("spelled", ({TO}) );
    portal->set_spellobj(TO);
    portal->start_magic(place, prof, roomName);
    tell_room(place, "%^BOLD%^%^BLUE%^The gem seems to grow, opening into "+
       "a small portal before it stops spinning!");
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 10;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect() {
    if (find_call_out("dest_effect"))
        remove_call_out("dest_effect");
	if(!objectp(portal))
	{
		::dest_effect();
            if(objectp(TO)) TO->remove();
		return;
	}
    portal->end_magic();
    if(!objectp(place))
	place = find_object_or_load(roomName);
    tell_room(place, "%^BLUE%^The energy sustaining the portal ends, and it vanishes!");
    portal->move(ROOM_VOID);
    portal->remove();
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
