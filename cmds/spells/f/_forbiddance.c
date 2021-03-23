//Forbiddance, adapted from Teleportation ward for
//Tyranny domain ~Circe~ 4/26/08 rebalancing the domains
#include <std.h>
#include <daemons.h>
#include <magic.h>
#include <spell.h>

inherit SPELL;

object room;

void create(){
    ::create();
    set_spell_name("forbiddance");
    set_spell_level(([ "cleric" : 6, "inquisitor" : 6]));
    set_spell_sphere("abjuration");
    set_domains("law");
    set_syntax("cast CLASS forbiddance");
    set_description("This spell creates an oppressive aura of protection throughout the area, forbidding anyone from "
"teleporting into or out of it.  The magic will last for a short time, until the caster leaves the area, or until it is "
"dispelled.");
    set_verbal_comp();
    set_somatic_comp();
    set_heart_beat(1);
    set_helpful_spell(1);
}

void heart_beat(){
    if(!objectp(TO)) { return; }
    if(!objectp(caster)) { return; }
    if(!objectp(room)) { return; }
    if(!present(caster,room))    {
        tell_room(room,"%^BOLD%^%^BLACK%^The cold aura of protection "+
           "drains away as "+caster->QCN+" leaves the room.%^RESET%^",caster);
        tell_object(caster,"%^BOLD%^%^BLACK%^Your cold aura of "+
           "protection drains away as you leave the room.%^RESET%^");
        dest_effect();
        return;
    }
}

int preSpell(){
    if(place->query_property("no teleport")){
        tell_object(caster,"This room is already protected against teleportation.");
        return 0;
    }
    return 1;
}

string query_cast_string(){
    tell_object(caster,"%^GREEN%^At your command, a nearly opaque "+
       "%^BOLD%^%^BLACK%^dome%^RESET%^%^GREEN%^ begins to form over "+
       "the area.%^RESET%^");
    tell_room(place,"%^GREEN%^"+caster->QCN+" barks a command, and "+
       "a nearly opaque %^BOLD%^%^BLACK%^dome%^RESET%^%^GREEN%^ "+
       "begins to coalesce over the area.%^RESET%^",caster);
	return "display";
}

void spell_effect(int prof){
    int duration,strength,bonus,fail;
    duration = clevel * ROUND_LENGTH;
    room     = environment(caster);
//    room->set_property("no teleport",1);
//Changing to use teleport proof rather than no teleport
//by ~Circe~ 6/20/08 to make it less foolproof
    bonus = caster->query_stats("wisdom");
    bonus = bonus - 10;
    strength = CLEVEL + bonus + random(6);
    if(room->query_property("no teleport")){
       fail = 1;
    }
    if(room->query_property("teleport proof")){
       if((int)room->query_property("teleport proof") > strength){
          fail = 1;
       }
    }
    if(fail){
       tell_object(caster,"There is a greater magic already protecting this room!");
       return 1;
    }
    room->remove_property("teleport proof");
    room->set_property("teleport proof",strength);
//End of new additions
    tell_room(room,"%^BOLD%^%^GREEN%^The opaque %^BLACK%^dome %^GREEN%^"+
       "over "+caster->QCN+" strengthens before fading out of sight, "+
       "leaving the area encased in a protective field!%^RESET%^",caster);
    tell_object(caster,"%^BOLD%^%^GREEN%^The opaque %^BLACK%^dome %^GREEN%^"+
       "over you strengthens before fading out of sight, "+
       "leaving the area encased in a protective field!%^RESET%^");
    addSpellToCaster();
    spell_successful();
    caster->set_property("spelled",({TO}));
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect(){
    tell_room(room,"%^BOLD%^%^BLACK%^The oppressive aura of protection "+
       "s%^RESET%^h%^BOLD%^%^BLACK%^i%^RESET%^m%^BOLD%^%^BLACK%^m"+
       "%^RESET%^e%^BOLD%^%^BLACK%^r%^RESET%^s %^BOLD%^%^BLACK%^and "+
       "disappears, leaving the air feeling light.%^RESET%^");
//    room->set_property("no teleport",-1);
    room->remove_property("teleport proof");
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
