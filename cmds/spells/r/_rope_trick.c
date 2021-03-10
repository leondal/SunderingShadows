// Rope Trick
// fixed typos - problem with the spell ending must be with the object *Styx*  3/15/03
// added roomName variable to prevent bugs where the room object from has been dested by clean_up to try to fix bugs  *Styx*  3/23/03

// Changed to recognize no pocket space for certain boss rooms. Dinji 10/30/2007

#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>

inherit SPELL;

object rope;
string roomName;

object o_rope;

create() {
    ::create();
    set_spell_name("rope trick");
    set_spell_level(([ "mage" : 2, "innate" : 2, "warlock" : 1, "magus" : 2 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS rope trick");
    set_description("When rope trick is cast, a rope will leap up and stiffen, leading to a magic room in a pocket of "
"another dimension.  Any may climb the rope and enter the room.  The rope may be pulled into the room making the room "
"inaccessible.  And the room will exist for quite a long time, varying with the caster's spell-casting level.  To cast "
"this spell, the caster must drop a rope before them which will not be consumed by the casting.

Inside rope trick room you can:

%^ORANGE%^<pull rope>%^RESET%^
  Pulls up the access rope so that no one else can gain entry to this space.

%^ORANGE%^<lower rope>%^RESET%^
  Lowers the access rope to the outside room allowing access to this space.

%^ORANGE%^<peer out>%^RESET%^
  Allows you to look into the outside room.

%^ORANGE%^<out>%^RESET%^
  This is the exit to the outside world which is available as long as the rope is down.
");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
    set_feats_required(([ "warlock" : "book of shadows"]));
}

int preSpell(){

    o_rope = present("rope", caster);
    if (!objectp(o_rope))
        o_rope = present("rope", place);
    if (!objectp(o_rope)) {
        tell_object(caster, "Your spell fizzles away!");
        tell_room(place, caster->QCN+"'s spell fizzles away!");
//        TO->remove();
        return 0;
    }
    return 1;
}


void spell_effect(int prof) {

    ::spell_effect();
    if (place->query_property("no pocket space")) {
        tell_object(caster, "The rope hangs listlessly in your hands as something blocks your power.");
        tell_room(place, caster->QCN+"'s spell fizzles away!");
        TO->remove();
        return 0;
    }
    rope = new(SPELL_OBJ_DIR+"rt_rope");
    tell_object(caster, "You raise your arms upward while chanting.\nThe rope begins to spasmodically twitch in response!");
    tell_room(place, "You see a piece of rope spasmodically twitch on the ground as "+caster->QCN+" raises "+caster->QP+" arms and chants!", caster);
    o_rope->move(ROOM_VOID);
    spell_successful();
    roomName = base_name(place);
    rope->set_property("spell", TO );
    rope->set_property("spelled", ({TO}) );
    rope->set_spellobj(TO);
    rope->move(place);
    rope->start_magic(place, prof, roomName);
    tell_room(place, "The rope leaps up and stands straight in mid-air!");
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 12;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect() {
    if (find_call_out("dest_effect"))
        remove_call_out("dest_effect");
    if(!objectp(place)) place = find_object_or_load(roomName);
    tell_room(place, "The rope falls to the ground, limp.");
    if(objectp(rope)) {
      rope->end_magic();
      rope->move(ROOM_VOID);
      rope->remove();
    }
    new("/d/common/obj/misc/rope")->move(place);
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

void reverse_spell(){
    tell_object(caster,"The rope snakes about a bit.");
    tell_object(caster,"The rope binds you in a wild mis-cast.");
    tell_room(place,"The rope "+caster->QCN+" was trying to control binds "+caster->QO+".",caster);
    caster->set_bound(random(15+5));
    if (objectp(o_rope)) {
        o_rope->remove();
    }
}
