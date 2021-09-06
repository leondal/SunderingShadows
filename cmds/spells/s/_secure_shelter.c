#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>

inherit SPELL;

object portal;
string roomName;


void create()
{
    ::create();
    set_spell_name("secure shelter");
    set_spell_level(([ "bard" : 4 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS secure shelter");
    set_description("When this spell is cast, it conjures a small pocket dimension under the guise of a little house, "
        "secure and impervious to outside forces.  It offers temporary safety from the outside world.  To cast, a narrative "
        "reciting details of the cottage you are trying to summon, is required.

Inside the shelter you can:

%^ORANGE%^<lock cottage>%^RESET%^
  This locks the door to the cottage, preventing anyone outside from entering.

%^ORANGE%^<unlock cottage>%^RESET%^
  This unlocks the cottage door, allowing people to enter or leave.

%^ORANGE%^<out>%^RESET%^
  This is the exit to the Prime Material plane, so long as the cottage door is unlocked.

");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}


void spell_effect(int prof)
{

    if(place->query_property("no pocket space"))
    {
        tell_object(caster, "%^RESET%^%^CYAN%^Something is interfering with your spell, and it fizzles uselessly.");
        TO->remove();
        return 0;
    }
    tell_object(caster,"%^ORANGE%^You recite a long section of prose, describing the cottage in detail to call it into being.");
    tell_room(place, "%^ORANGE%^"+caster->QCN+" recites a long section of prose.", caster);
    spell_successful();
    roomName = base_name(place);
    portal = new(SPELL_OBJ_DIR+"secure_shelter");
    portal->set_property("spell", TO );
    portal->set_property("spelled", ({TO}) );
    portal->set_spellobj(TO);
    portal->move(place);
    portal->start_magic(place, prof, roomName);
    tell_room(place,"%^ORANGE%^The air ripples and wobbles as if through a %^BOLD%^%^BLACK%^smo%^RESET%^k"
        "%^BOLD%^%^BLACK%^y haze%^RESET%^%^ORANGE%^, and a small cottage phases into view.");
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 12;
    set_end_time();
    call_out("dest_effect",spell_duration);
}


void dest_effect()
{
    if (find_call_out("dest_effect")) remove_call_out("dest_effect");
    if(!objectp(place)) place = find_object_or_load(roomName);
    if (objectp(portal))
    {
        portal->end_magic();
        tell_room(place,"%^ORANGE%^The little cottage wobbles as if through a %^BOLD%^%^BLACK%^smo%^RESET%^k"
            "%^BOLD%^%^BLACK%^y haze%^RESET%^%^ORANGE%^, and then winks out of existance.");
        portal->move(ROOM_VOID);
        portal->remove();
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
