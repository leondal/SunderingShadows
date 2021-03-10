#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>
#include <teleport.h>
inherit SPELL;

object ob, endplace;

void create(){
    ::create();
    set_author("nienne");
    set_spell_name("shadow travel");
    set_spell_level(([ "innate" : 1, "assassin": 4, "monk": 15, "oracle" : 6 ]));
    set_mystery(({"darkness","shadow"}));
    set_domains("darkness");
    set_spell_sphere("alteration");
    set_monk_way("way of the shadow");
    set_syntax("cast CLASS shadow travel to <location>");
    set_description("Through this spell the caster attunes themselves with a nearby shadow and steps into it, allowing "
"near instantaneous travel to another destination of their choice. A great deal of concentration is required to enact "
"such a spell, so the spell can be easily disrupted by others. Teleport warding effects that are of greater strength "
"than the caster, will thwart the spell entirely.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_peace_needed(1);
    set_helpful_spell(1);
}

void spell_effect(int prof){
    string name, tempstr, a, file;
    int mypower, startpower, endpower, bonus;
    mapping tmp;

    tempstr = ARG;

    if(!objectp(caster)) return 0;
    if(objectp(place)) place = environment(caster);
    name = caster->QCN;

    if(!tempstr) tempstr = "";
    if(!sscanf(tempstr,"%s",a)){
        tell_object(caster,"%^BLUE%^You cast your gaze out in search of a suitable patch of shadows, but pause as you realise you have no destination in mind.%^RESET%^");
        tell_room(place, "%^BLUE%^"+caster->QCN+"%^RESET%^%^BLUE%^ glances around.%^RESET%^", caster);
        dest_effect();
        return;
    }
    if(member_array(a,caster->query_rem_rooms_sort())<0){
        tell_object(caster,"%^BLUE%^You cast your gaze out in search of a suitable patch of shadows, but pause as you realise you know no destination such as "+a+".%^RESET%^");
        tell_room(place, "%^BLUE%^"+caster->QCN+"%^RESET%^%^BLUE%^ glances around.%^RESET%^", caster);
        dest_effect();
        return;
    }
    tmp = caster->query_rem_rooms();
    file = tmp[a];

    if(!file || !stringp(file)){
        tell_object(caster,"%^BLUE%^You cast your gaze out in search of a suitable patch of shadows, but pause as you realise you know no destination such as "+a+".%^RESET%^");
        tell_room(place, "%^BLUE%^"+caster->QCN+"%^RESET%^%^BLUE%^ glances around.%^RESET%^", caster);
        dest_effect();
        return;
    }
    if(!(endplace = find_object_or_load(file))) file = 0;

    if (environment(caster)->query_property("no teleport")||
        endplace->query_property("no teleport")) {
        tell_object(caster,"%^BLUE%^You cast your gaze out in search of a suitable patch of shadows, but pause as you sense an interference.%^RESET%^");
        tell_room(place, "%^BLUE%^"+caster->QCN+"%^RESET%^%^BLUE%^ glances around.%^RESET%^", caster);
        dest_effect();
        return;
    }
    if(endplace &&
      (endplace->query_property("teleport proof") ||
      place->query_property("teleport proof") ||
      !endplace->is_room())){
      startpower = place->query_property("teleport proof");
      endpower = endplace->query_property("teleport proof");
      bonus = caster->query_stats("charisma");
      bonus = bonus -10;
      mypower = CLEVEL + bonus + random(6);
      if((mypower < startpower) || (mypower < endpower)){
        tell_object(caster,"%^BLUE%^You cast your gaze out in search of a suitable patch of shadows, but pause as you sense an interference.%^RESET%^");
        tell_room(place, "%^BLUE%^"+caster->QCN+"%^RESET%^%^BLUE%^ glances around.%^RESET%^", caster);
        dest_effect();
        return;
      }
    }

    if(!file){
        tell_object(caster,"%^BLUE%^You cast your gaze out in search of a suitable patch of shadows, but pause as you sense an interference.%^RESET%^");
        tell_room(place, "%^BLUE%^"+caster->QCN+"%^RESET%^%^BLUE%^ glances around.%^RESET%^", caster);
        dest_effect();
        return;
    }
    if(endplace->is_flight_room()) {
        tell_object(caster,"%^BLUE%^You cast your gaze out in search of a suitable patch of shadows, but pause as you sense an interference.%^RESET%^");
        tell_room(place, "%^BLUE%^"+caster->QCN+"%^RESET%^%^BLUE%^ glances around.%^RESET%^", caster);
        dest_effect();
        return;
    }
    if (sizeof(caster->query_attackers()) > 0) {
        tell_object(caster,"%^BLUE%^You cast your gaze out in search of a suitable patch of shadow, but you can't concentrate enough while being attacked!%^RESET%^");
        tell_room(place, "%^BLUE%^"+caster->QCN+"%^RESET%^%^BLUE%^ glances around, but loses "+caster->QP+" concentration on being attacked!%^RESET%^", caster);
        dest_effect();
        return;
    }

    tell_room(place, "%^RESET%^%^BLUE%^"+caster->QCN+"%^RESET%^%^BLUE%^ glances around, "+caster->QP+" gaze falling upon a "
"darker patch of shadows.%^RESET%^", caster);
    tell_object(caster, "%^RESET%^%^BLUE%^You cast your gaze out in search of a suitable patch of shadow.%^RESET%^");
    caster->set_paralyzed(25, "Your senses are attuned to the shadows!");
    call_out("part2", 5);
}

void part2(){
    string name;

    name = caster->QCN;
    if(!objectp(caster)) return 0;
    if(environment(caster) != place) {
        tell_object(caster,"%^BLUE%^Your concentration is broken by the sudden movement!%^RESET%^");
        tell_room(place, "%^BLUE%^"+caster->QCN+"%^RESET%^%^BLUE%^'s concentration is broken by the sudden movement!%^RESET%^", caster);
        dest_effect();
        return;
    }
    if (sizeof(caster->query_attackers()) > 0) {
        tell_object(caster,"%^BLUE%^Your concentration is broken by the attack!%^RESET%^");
        tell_room(place, "%^BLUE%^"+caster->QCN+"%^RESET%^%^BLUE%^ loses "+caster->QP+" concentration on being attacked!%^RESET%^", caster);
        caster->set_paralyzed(0);
        caster->set_paralyzed(5, "You are regaining your senses.");
        dest_effect();
        return;
    }

    tell_room(place, "%^RESET%^%^BLUE%^Even as you watch, "+caster->QCN+"%^RESET%^%^BLUE%^ takes a step towards the darkened "
"spot, starting to fade before your very eyes!%^RESET%^", caster);
    tell_object(caster, "%^RESET%^%^BLUE%^You espy a suitably dark spot and move towards it, attuning your senses to the "
"shadows as you start to merge with them!%^RESET%^");
    call_out("part3", 5);
}

void part3(){
    string name, mydestination;
    object destination;

    name = caster->QCN;
    if(!objectp(caster)) return 0;
    if(environment(caster) != place) {
        tell_object(caster,"%^BLUE%^Your concentration is broken by the sudden movement!%^RESET%^");
        tell_room(place, "%^BLUE%^"+caster->QCN+"%^RESET%^%^BLUE%^'s concentration is broken by the sudden movement!%^RESET%^", caster);
        dest_effect();
        return;
    }
    if (sizeof(caster->query_attackers()) > 0) {
        tell_object(caster,"%^BLUE%^Your concentration is broken by the attack!%^RESET%^");
        tell_room(place, "%^BLUE%^"+caster->QCN+"%^RESET%^%^BLUE%^ loses "+caster->QP+" concentration on being attacked!%^RESET%^", caster);
        caster->set_paralyzed(0);
        caster->set_paralyzed(5, "You are regaining your senses.");
        dest_effect();
        return;
    }
    if(!objectp(endplace)){
        tell_object(caster,"%^BLUE%^You break off the spell as you sense an interference.%^RESET%^");
        tell_room(place, "%^BLUE%^"+caster->QCN+"%^RESET%^%^BLUE%^ suddenly stops casting.%^RESET%^", caster);
        dest_effect();
        return;
    }

    tell_room(place, "%^RESET%^%^BLUE%^You blink just as "+caster->QCN+"%^RESET%^%^BLUE%^ merges fully into the shadows, "
"and within that split second "+caster->QS+" has vanished!%^RESET%^", caster);
    tell_object(caster, "%^RESET%^%^BLUE%^A welcoming chill runs through you as you become one with the darkness, and "
"uncounted miles race past in an instant. As fast as you can think it, you emerge from the shadows in a completely "
"different location!%^RESET%^");
    caster->clear_followers();
    TELEPORT->teleport_object(caster,caster,endplace,clevel);
    caster->set_casting(0);
    dest_effect();
    return;
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
