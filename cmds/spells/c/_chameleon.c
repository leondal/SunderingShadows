//based on stalk
//~Circe~ 7/28/05
#include <spell.h>
#include <magic.h>
#include <rooms.h>

inherit SPELL;

object invisob;

void create() {
    ::create();
    set_spell_name("chameleon");
    set_spell_level(([ "psion" : 3 ]));
    set_discipline("egoist");
    set_spell_sphere("illusion");
    set_syntax("cast CLASS chameleon");
    set_description("Chameleon allows an egoist to cover himself with a thin sheen of ectoplasm that he then wills to "
"blend in perfectly with his surroundings.  This renders the egoist invisible to all eyes (except those enchanted to see "
"invisible beings, of course).  Because of the nature of the power, the egoist may attack while in this state, though the "
"power has a chance to drain from him every time he moves.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

void spell_effect(int prof) {

    tell_object(caster,"%^ORANGE%^You manifest a thin sheen of "+
       "e%^GREEN%^c%^ORANGE%^t%^GREEN%^o%^ORANGE%^p%^GREEN%^l"+
       "%^ORANGE%^a%^GREEN%^s%^ORANGE%^m to cover you from "+
       "head to toe, then will the e%^GREEN%^c%^ORANGE%^t"+
       "%^GREEN%^o%^ORANGE%^p%^GREEN%^l%^ORANGE%^a%^GREEN%^"+
       "s%^ORANGE%^m to take on the hues surrounding you!");
    tell_room(place,"%^ORANGE%^A thin sheen seems to cover "+caster->QCN+" "+
       "before it b%^GREEN%^l%^ORANGE%^e%^GREEN%^n%^ORANGE%^d"+
       "%^GREEN%^s %^ORANGE%^in perfectly with "+caster->QP+" "+
       "surroundings!",caster);
    call_out("targ_vanish",2);
}

void targ_vanish() {
    int num;
    num = (clevel/2);
    spell_successful();
    invisob=new("/d/magic/obj/invisobgreater.c");
    invisob->set_property("spell",TO);
    invisob->set_property("spell",({TO}) );
    invisob->set_player_name(caster->query_name());
    invisob->set_mychance(num);
    invisob->move(caster);
    return;
}

void dest_effect() {
    if(objectp(caster)){
       tell_object(caster,"%^GREEN%^The ectoplasmic sheen loses its "+
          "power, revealing you to the world.");
       tell_room(environment(caster),"GREEN%^With a slight shimmer, "+
          ""+caster->QCN+" is revealed to view.",caster);
    }
    if(objectp(invisob)) invisob->show_me();
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

string query_cast_string() {
    return "%^GREEN%^"+caster->QCN+" slips back quietly and stands "+
       "perfectly still.";
}
