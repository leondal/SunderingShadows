// repose sphere, summons a spectral mount. Nienne, 04/07
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

object ob;

void create(){
    ::create();
    set_author("nienne");
    set_spell_name("treestride");
    set_spell_level(([ "ranger" : 4,"druid" : 5 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS treestride");
    set_description("By means of this spell, a ranger attunes themselves so closely with a tree that they are able to "
"step into it, using its connection with nature to travel to the World Tree - the heart of the wilderness.\n\nAny "
"distractions will cause the spell to fail, as it requires deep concentration from the caster.  This spell can only be "
"cast while at peace.");
    set_verbal_comp();
    set_somatic_comp();
    set_peace_needed(1);
	set_helpful_spell(1);
}

string query_cast_string(){
    return "%^RESET%^%^GREEN%^"+caster->QCN+"%^RESET%^%^GREEN%^ approaches a nearby tree.%^RESET%^";
}

int preSpell(){
    string myterrain;
    object locale;
    locale = environment(caster);
    myterrain = locale->query_terrain();
    if(locale->query_property("treestride_possible")) return 1;
    if(myterrain != "heavy forest" && myterrain != "light forest" && myterrain != "jungle" && myterrain != "dense jungle" && myterrain != "branches" && myterrain != "swamp" && myterrain != "marsh" && myterrain != "scrub lands" && myterrain != "savannah") {
      tell_object(caster,"%^BOLD%^%^GREEN%^You cannot see any suitable trees nearby, how could you use this spell?");
      return 0;
    }
    return 1;
}

void spell_effect(int prof){
    string name;
    int mypower,startpower,endpower,bonus;
    object endplace;

    if(!objectp(caster)) return 0;
    if(objectp(place)) place = environment(caster);
    name = caster->QCN;

    if (environment(caster)->query_property("no teleport")) {
        tell_object(caster,"%^BOLD%^%^GREEN%^You reach out to the tree, but find something is blocking your "
"ability to merge with it.%^RESET%^");
    tell_room(place, "%^RESET%^%^GREEN%^"+caster->QCN+"%^RESET%^%^GREEN%^ reaches out to touch the tree, but "
"then shakes "+caster->QP+" head.%^RESET%^", caster);
        dest_effect();
        return;
    }
//teleport proof stuff by ~Circe~ 6/20/08
//new property to be used for areas protected from teleport
//but not foolproof
   endplace = "/d/shadow/room/city/cguild/ranger/rooms/hall1";
   if(endplace &&
      (endplace->query_property("teleport proof") ||
      place->query_property("teleport proof") ||
      !endplace->is_room())){
      startpower = place->query_property("teleport proof");
      endpower = endplace->query_property("teleport proof");
      bonus = caster->query_stats("wisdom");
      bonus = bonus -10;
      mypower = CLEVEL + bonus + random(6);
      if((mypower < startpower) || (mypower < endpower)){
        tell_object(caster,"%^BOLD%^%^GREEN%^You reach out to the tree, but find something is blocking your "
"ability to merge with it.%^RESET%^");
    tell_room(place, "%^RESET%^%^GREEN%^"+caster->QCN+"%^RESET%^%^GREEN%^ reaches out to touch the tree, but "
"then shakes "+caster->QP+" head.%^RESET%^", caster);
        dest_effect();
        return;
      }
   }
    if (sizeof(caster->query_attackers()) > 0) {
        tell_object(caster,"%^BOLD%^%^GREEN%^You are jolted out of your concentration by the attack!%^RESET%^");
    tell_room(place, "%^RESET%^%^GREEN%^"+caster->QCN+"%^RESET%^%^GREEN%^ is jolted from "+caster->QP+
"concentration.%^RESET%^", caster);
        dest_effect();
        return;
    }

    tell_room(place, "%^RESET%^%^GREEN%^"+caster->QCN+"%^RESET%^%^GREEN%^ extends "+caster->QP+" hands towards "
"the tree, bringing them to rest upon its woody surface.  Closing "+caster->QP+" eyes, "+caster->QS+" takes on "
"a look of concentraton.%^RESET%^", caster);
    tell_object(caster, "%^RESET%^%^GREEN%^You extend your hands, bringing them to rest against the woody "
"surface of the tree.  Closing your eyes, you focus upon essence of nature within it, that flows through all "
"wild things.%^RESET%^");
    caster->set_paralyzed(20, "You are focussing upon the tree!");
    call_out("part2", 5);
}

void part2(){
    string name;

    name = caster->QCN;
    if(!objectp(caster)) return 0;
    if(environment(caster) != place) {
        tell_object(caster,"%^BOLD%^%^GREEN%^The abrupt movement jolts you out of your concentration, and your "
"spell fails.%^RESET%^");
    tell_room(place, "%^RESET%^%^GREEN%^"+caster->QCN+"%^RESET%^%^GREEN%^ is jolted out of "+caster->QP+
" concentration.%^RESET%^", caster);
        dest_effect();
        return;
    }
    if (sizeof(caster->query_attackers()) > 0) {
        tell_object(caster,"%^BOLD%^%^GREEN%^You are jolted out of your concentration by the attack!%^RESET%^");
    tell_room(place, "%^RESET%^%^GREEN%^"+caster->QCN+"%^RESET%^%^GREEN%^ is jolted from "+caster->QP+
"concentration.%^RESET%^", caster);
        caster->set_paralyzed(0);
        caster->set_paralyzed(5, "You are regaining your senses.");
        dest_effect();
        return;
    }

    tell_room(place, "%^RESET%^%^GREEN%^You watch as "+caster->QCN+"%^RESET%^%^GREEN%^'s hands slowly pass "
"forward into the tree!%^RESET%^", caster);
    tell_object(caster, "%^RESET%^%^GREEN%^You attune your spirit to the wilderness around you, and your hands "
"slowly pass forward into the tree!%^RESET%^");
    caster->set_paralyzed(25, "You are focussing upon the tree!");
    call_out("part3", 5);
}

void part3(){
    string name, mydestination;
    object destination;

    name = caster->QCN;
    if(!objectp(caster)) return 0;
    if(environment(caster) != place) {
        tell_object(caster,"%^BOLD%^%^GREEN%^The abrupt movement jolts you out of your concentration, and your "
"spell fails.%^RESET%^");
    tell_room(place, "%^RESET%^%^GREEN%^"+caster->QCN+"%^RESET%^%^GREEN%^ is jolted out of "+caster->QP+
" concentration.%^RESET%^", caster);
        dest_effect();
        return;
    }
    if (sizeof(caster->query_attackers()) > 0) {
        tell_object(caster,"%^BOLD%^%^GREEN%^You are jolted out of your concentration by the attack!%^RESET%^");
    tell_room(place, "%^RESET%^%^GREEN%^"+caster->QCN+"%^RESET%^%^GREEN%^ is jolted from "+caster->QP+
"concentration.%^RESET%^", caster);
        caster->set_paralyzed(0);
        caster->set_paralyzed(5, "You are regaining your senses.");
        dest_effect();
        return;
    }

    tell_room(place, "%^RESET%^%^GREEN%^First "+caster->QCN+"%^RESET%^%^GREEN%^'s arms, and then the rest of "
+caster->QO+", merge into the tree and "+caster->QS+" disappears!%^RESET%^", caster);
    tell_object(caster, "%^RESET%^%^GREEN%^First your arms, and then the rest of you, merges into the tree and "
"you pass through it!%^RESET%^");

    mydestination = "/d/shadow/room/city/cguild/ranger/rooms/hall1";
    destination = find_object_or_load(mydestination);
    tell_object(caster, "%^BOLD%^%^GREEN%^You step back out of the tree that surrounds you, and find instead "
"that you have just emerged from the inner walls of the World Tree.%^RESET%^");
    tell_room(destination, "%^BOLD%^%^GREEN%^"+caster->QCN+" emerges from the wall of the World Tree."
"%^RESET%^");
    caster->move_player(mydestination);
    caster->set_casting(0);
    dest_effect();
    return;
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
