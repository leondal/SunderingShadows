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
    set_spell_name("dimension door");
    set_spell_level(([ "bard" : 4, "mage" : 4, "oracle" : 4, "magus" : 4, "psion" : 4 ]));
    set_domains("travel");
    set_mystery("solar");
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS dimension door on LOCATION");
    set_description("Through this spell the caster opens a 'door' in the fabric of reality, attuned only to themselves.  "
"They can use this to step through to a location of their choice, only one that they have previously visited and found to "
"resonate with their soul.  A great deal of concentration is required to enact such a spell, so the spell can be easily "
"disrupted by others.  Teleport warding effects that are of greater strength than the caster, will thwart the spell "
"entirely.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_peace_needed(1);
    set_helpful_spell(1);
}

string query_cast_string(){
    return "%^RESET%^%^MAGENTA%^"+caster->QCN+" steps back, making some space.%^RESET%^";
}

void spell_effect(int prof){
    string name, tempstr, a, file;
    int mypower, startpower, endpower, bonus;
    mapping tmp;

    tempstr = arg;

    if(!objectp(caster)) return 0;
    if(objectp(place)) place = environment(caster);
    name = caster->QCN;

    spell_successful();

    if(!tempstr) tempstr = "";
    if(!sscanf(tempstr,"%s",a)){
        tell_object(caster,"%^CYAN%^You hum the first note of the spell, but break off as you fail to concentrate upon a destination.%^RESET%^");
        tell_room(place, "%^CYAN%^"+caster->QCN+"%^RESET%^%^CYAN%^ hums a %^RESET%^soft %^CYAN%^note, then stops.%^RESET%^", caster);
        dest_effect();
        return;
    }
    if(!pointerp(caster->query_rem_rooms_sort()))
    {
        tell_object(caster,"%^CYAN%^You hum the first note of the spell, but break off as you realise you know no destination such as "+a+".%^RESET%^");
        tell_room(place, "%^CYAN%^"+caster->QCN+"%^RESET%^%^CYAN%^ hums a %^RESET%^soft %^CYAN%^note, then stops.%^RESET%^", caster);
        dest_effect();
        return;
    }
    if(member_array(a,caster->query_rem_rooms_sort())<0){
        tell_object(caster,"%^CYAN%^You hum the first note of the spell, but break off as you realise you know no destination such as "+a+".%^RESET%^");
        tell_room(place, "%^CYAN%^"+caster->QCN+"%^RESET%^%^CYAN%^ hums a %^RESET%^soft %^CYAN%^note, then stops.%^RESET%^", caster);
        dest_effect();
        return;
    }
    tmp = caster->query_rem_rooms();
    file = tmp[a];

    if(!file || !stringp(file)){
        tell_object(caster,"%^CYAN%^You hum the first note of the spell, but break off as you realise you know no destination such as "+a+".%^RESET%^");
        tell_room(place, "%^CYAN%^"+caster->QCN+"%^RESET%^%^CYAN%^ hums a %^RESET%^soft %^CYAN%^note, then stops.%^RESET%^", caster);
        dest_effect();
        return;
    }
    if(!(endplace = find_object_or_load(file))) file = 0;

    if (environment(caster)->query_property("no teleport")||
        endplace->query_property("no teleport")) {
        tell_object(caster,"%^CYAN%^You hum the first note of the spell, but break off as you sense an interference.%^RESET%^");
        tell_room(place, "%^CYAN%^"+caster->QCN+"%^RESET%^%^CYAN%^ hums a %^RESET%^soft %^CYAN%^note, then stops.%^RESET%^", caster);
        dest_effect();
        return;
    }
    if(endplace &&
      (endplace->query_property("teleport proof")||
      place->query_property("teleport proof")||
      !endplace->is_room()||
       endplace->query_property("no teleport"))){
      startpower = place->query_property("teleport proof");
      endpower = endplace->query_property("teleport proof");

      mypower = CLEVEL + random(6);
      if((mypower < startpower) || (mypower < endpower)){
        tell_object(caster,"%^CYAN%^You hum the first note of the spell, but break off as you sense an interference.%^RESET%^");
        tell_room(place, "%^CYAN%^"+caster->QCN+"%^RESET%^%^CYAN%^ hums a %^RESET%^soft %^CYAN%^note, then stops.%^RESET%^", caster);
        dest_effect();
        return;
      }
    }

    if(!file){
        tell_object(caster,"%^CYAN%^You hum the first note of the spell, but break off as you sense an interference.%^RESET%^");
        tell_room(place, "%^CYAN%^"+caster->QCN+"%^RESET%^%^CYAN%^ hums a %^RESET%^soft %^CYAN%^note, then stops.%^RESET%^", caster);
        dest_effect();
        return;
    }
    if(endplace->is_flight_room()) {
        tell_object(caster,"%^CYAN%^You hum the first note of the spell, but break off as you sense an interference.%^RESET%^");
        tell_room(place, "%^CYAN%^"+caster->QCN+"%^RESET%^%^CYAN%^ hums a %^RESET%^soft %^CYAN%^note, then stops.%^RESET%^", caster);
        dest_effect();
        return;
    }
    if (sizeof(caster->query_attackers()) > 0) {
        tell_object(caster,"%^CYAN%^You hum the first note of the spell, but your concentration is broken by the attack!%^RESET%^");
        tell_room(place, "%^CYAN%^"+caster->QCN+"%^RESET%^%^CYAN%^ hums a %^RESET%^soft %^CYAN%^note, but loses "+caster->QP+" concentration on being attacked!%^RESET%^", caster);
        dest_effect();
        return;
    }

    tell_room(place, "%^RESET%^%^CYAN%^"+caster->QCN+"%^RESET%^%^CYAN%^ hums softly as "+caster->QS+" reaches up, "
"bringing both index fingers together and then spreading "+caster->QP+" arms out and down.  Gl%^BOLD%^e%^RESET%^%^CYAN%^"
"ami%^BOLD%^n%^RESET%^%^CYAN%^g lines appear in the air trailing "+caster->QP+" fingertips to form a tall rectangle"
".%^RESET%^", caster);
    tell_object(caster, "%^RESET%^%^CYAN%^You hum softly as you reach up, bringing both index fingers together and then "
"spreading your arms out and down.  Gl%^BOLD%^e%^RESET%^%^CYAN%^ami%^BOLD%^n%^RESET%^%^CYAN%^g lines appear in the air "
"trailing your fingertips to form a tall rectangle.%^RESET%^");
    caster->set_paralyzed(25, "You are focusing upon the spell!");
    call_out("part2", 5);
}

void part2(){
    string name;

    name = caster->QCN;
    if(!objectp(caster)) return 0;
    if(environment(caster) != place) {
        tell_object(caster,"%^CYAN%^Your concentration is broken by the sudden movement!%^RESET%^");
        tell_room(place, "%^CYAN%^"+caster->QCN+"%^RESET%^%^CYAN%^'s concentration is broken by the sudden movement!%^RESET%^", caster);
        dest_effect();
        return;
    }
    if (sizeof(caster->query_attackers()) > 0) {
        tell_object(caster,"%^CYAN%^Your concentration is broken by the attack!%^RESET%^");
        tell_room(place, "%^CYAN%^"+caster->QCN+"%^RESET%^%^CYAN%^ loses "+caster->QP+" concentration on being attacked!%^RESET%^", caster);
        caster->set_paralyzed(0);
        caster->set_paralyzed(5, "You are regaining your senses.");
        dest_effect();
        return;
    }

    tell_room(place, "%^RESET%^%^CYAN%^You watch as "+caster->QCN+"%^RESET%^%^CYAN%^ pushes lightly on the centre of the "
"rectangle, and it swings ajar!%^RESET%^", caster);
    tell_object(caster, "%^RESET%^%^CYAN%^You push lightly on the centre of the rectangle, and it swings ajar!%^RESET%^");
    caster->set_paralyzed(25, "You are focussing upon the spell!");
    call_out("part3", 5);
}

void part3(){
    string name, mydestination;
    object destination;

    name = caster->QCN;
    if(!objectp(caster)) return 0;
    if(environment(caster) != place) {
        tell_object(caster,"%^CYAN%^Your concentration is broken by the sudden movement!%^RESET%^");
        tell_room(place, "%^CYAN%^"+caster->QCN+"%^RESET%^%^CYAN%^'s concentration is broken by the sudden movement!%^RESET%^", caster);
        dest_effect();
        return;
    }
    if (sizeof(caster->query_attackers()) > 0) {
        tell_object(caster,"%^CYAN%^Your concentration is broken by the attack!%^RESET%^");
        tell_room(place, "%^CYAN%^"+caster->QCN+"%^RESET%^%^CYAN%^ loses "+caster->QP+" concentration on being attacked!%^RESET%^", caster);
        caster->set_paralyzed(0);
        caster->set_paralyzed(5, "You are regaining your senses.");
        dest_effect();
        return;
    }
    if(!objectp(endplace)){
        tell_object(caster,"%^CYAN%^You break off the spell as you sense an interference.%^RESET%^");
        tell_room(place, "%^CYAN%^"+caster->QCN+"%^RESET%^%^CYAN%^ suddenly stops casting.%^RESET%^", caster);
        dest_effect();
        return;
    }

    tell_room(place, "%^RESET%^%^CYAN%^The aperture swings far enough open that you catch a glimpse of "
+endplace->query_short()+" as "+caster->QCN+"%^RESET%^%^CYAN%^ steps through, and disappears from sight as the door "
"swings shut and vanishes entirely!%^RESET%^", caster);
    tell_object(caster, "%^RESET%^%^CYAN%^The aperture swings far enough open for you to step through, and swings shut "
"behind you to vanish entirely!%^RESET%^");
    caster->clear_followers();
    TELEPORT->teleport_object(caster,caster,endplace,clevel);
    caster->set_casting(0);
    caster->set_paralyzed(0);
    dest_effect();
    return;
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
