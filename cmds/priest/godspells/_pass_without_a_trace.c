#include <std.h>
#include <priest.h>
inherit SPELL;

void create() {
   ::create();
   set_spell_name("pass without a trace");
   set_spell_level(4);
   set_spell_type("priest");
    set_diety("mielikki");
   set_spell_sphere("alteration");
   set_restricted_to_class(({"cleric"}));
   set_verbal_comp();
   set_somatic_comp();
}

string query_cast_string() {
    return "%^GREEN%^"+caster->QCN+" murmurs a few quiet words over the ground before "+caster->QO+"!%^RESET%^";
}

void spell_effect(int prof) {
   int clevel;
   clevel = CLEVEL;
   if ((int)caster->query_property("untrackable")) {
     tell_object(caster,"%^GREEN%^Your footsteps are already untrackable!%^RESET%^");
     TO->remove();
     return;
   }
   tell_room(place,"%^GREEN%^An %^BOLD%^emerald glow %^RESET%^%^GREEN%^appears briefly over the ground at "+caster->QCN+"'s feet!%^RESET%^",caster);
   tell_object(caster,"%^GREEN%^You call upon the Lady to hide your steps, and an emerald glow appears briefly over the ground at your feet!%^RESET%^");
   caster->set_property("untrackable",1);
   addSpellToCaster();
   spell_successful();
   call_out("dest_effect",(clevel*2)+10);
}

void dest_effect(){
   ::dest_effect();
   if (!objectp(TO)) return;
   if (!objectp(caster)) {
     TO->remove();
     return;
   }
   if((int)caster->query_property("untrackable")) caster->set_property("untrackable",-1);
   TO->remove();
}

int help() {
    write(
@OLI
Spell  : Pass without a trace
Level  : 4th Level
Sphere : Alteration
Deity  : Mielikki
Syntax : chant pass without a trace

The caster can move through any type of terrain and leave neither scent 
nor footprints. Tracking the subjects is impossible by nonmagical means.

OLI
);
    return 1;
}
