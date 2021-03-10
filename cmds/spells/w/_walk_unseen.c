#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit SPELL;

/*object invisob, caster, target, place; Removing due to the weirdness with the new driver - Octothorpe 3/15/17 */
object invisob;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("walk unseen");
    set_spell_level(([ "warlock" : 2 ]));
    set_spell_sphere("illusion");
    set_syntax("cast CLASS walk unseen");
    set_description("This invocation places illusory spellcraft around the warlock, deceiving the "
"eyes of those around so as to effectively disappear from view. While minor, a small degree of "
"concentration is required to maintain the effect, so it can become wearying over time. Becoming "
"engaged in combat is sufficiently distracting to lose control of the concealment; also, falling "
"unconscious will cause the invocation to fail. Of course, the warlock can simply forgo the "
"concentration to <appear> at any time.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string() {
    tell_object(caster,"%^MAGENTA%^Your fingers trace the pattern of a lesser invocation.%^RESET%^");
    tell_room(place,"%^MAGENTA%^"+caster->QCN+"'s fingers trace the pattern of an invocation.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof) {
    tell_object(caster,"%^MAGENTA%^Colors run like %^GREEN%^l%^CYAN%^i%^BLUE%^q%^MAGENTA%^u%^RED%^i%^ORANGE%^d %^MAGENTA%^across your skin, aligning with the world around you so that you disappear from view.%^RESET%^");
    tell_room(place,"%^MAGENTA%^Colors run like %^GREEN%^l%^CYAN%^i%^BLUE%^q%^MAGENTA%^u%^RED%^i%^ORANGE%^d %^MAGENTA%^across "+caster->QCN+"'s skin, aligning with the world around you until "+caster->QS+" disappears from view.%^RESET%^",caster);
    call_out("targ_vanish",2);
}

void targ_vanish() {
    if (caster->query_invis()) {
        tell_object(caster,"You're already invisible!");
        TO->remove();
        return;
    }
    if(caster->query_property("visible")){
        tell_object(caster,"The invocation fails utterly.");
        TO->remove();
        return;
    }
    spell_successful();
    invisob=new("/d/magic/obj/trick_invisob.c");
    invisob->set_property("spell",TO);
    invisob->set_property("spelled", ({TO}) );
    invisob->move_is_ok(1);
    invisob->move(caster);
    invisob->set_prof(100);
    invisob->move_is_ok(0);
    addSpellToCaster();
}

void dest_effect() {
    if(objectp(caster)) {
      tell_object(caster,"%^MAGENTA%^You release concentration upon the invocation and reappear.%^RESET%^");
      tell_room(environment(caster),"%^MAGENTA%^A section of the world blurs, before resolving into the form of "+caster->QCN+".%^RESET%^",caster);
    }
    if (objectp(invisob)) invisob->show_up();
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
