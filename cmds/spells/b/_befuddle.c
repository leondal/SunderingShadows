// Invisibility - Coded by Vashkar@shadowgate
//Adapted by ~Circe~ for Befuddle, a new trickery
//domain spell with the rebalancing of domains 4/26/08

#include <spell.h>
#include <magic.h>
#include <rooms.h>

inherit SPELL;

object invisob;

void create() {
    ::create();
    set_spell_name("befuddle");
    set_spell_level(([ "classless" : 5 ]));
    set_spell_sphere("alteration");
    set_spell_domain("trickery");
    set_syntax("cast CLASS befuddle");
    set_description("This spell will confuse the minds of onlookers, allowing the priest to wander among them without "
"being seen.  To end the spell, the priest may type <appear> or become involved in a fight, and at times, the spell will "
"simply wear off on its own due to time.  Some creatures and spells may be able to penetrate the befuddlement, but most "
"will not.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string() {
    return "%^BOLD%^%^BLACK%^With a devious %^RED%^grin%^BLACK%^, "+
       ""+caster->QCN+" begins to whisper a chant.%^RESET%^";
}

void spell_effect(int prof) {
   tell_object(caster,"%^BOLD%^%^BLACK%^Your devious chant and powerful "+
      "plea to your deity allows you to %^RED%^befuddle %^BLACK%^the "+
      "minds of onlookers, erasing you from their sight.%^RESET%^");
   tell_room(place,"%^BOLD%^%^BLACK%^A faint chuckle is heard as "+
      ""+caster->QCN+" %^RED%^vanishes %^BLACK%^from sight.%^RESET%^",caster);
    call_out("targ_vanish",2, prof);
    return;
}

void targ_vanish(int prof) {
    if (caster->query_invis()) {
        tell_object(caster,"You are already invisible!");
        dest_effect();
        return;
    }
    if(caster->query_property("visible")){
        tell_object(caster,"Strangely, the spell fails utterly on you.");
        dest_effect();
        return;
    }
    spell_successful();
    invisob=new("/d/magic/obj/trick_invisob.c");
    invisob->set_property("spell",TO);
    invisob->set_property("spelled", ({TO}) );
    invisob->move_is_ok(1);
    invisob->move(caster);
    invisob->set_prof(prof);
    invisob->move_is_ok(0);
    addSpellToCaster();
    return;
}

void dest_effect() {
    if (objectp(invisob)) {
        invisob->show_up();
    }
    if(objectp(caster))
	caster->remove_property("visible");
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}


void reverse_spell(){
    target->set_property("visible",1);
    call_out("dest_effect",clevel*8);
}
