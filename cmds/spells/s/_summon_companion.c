// Spell to setup the calling of an animal companion for a mage. Nienne, 10/04. //
// requires RACES as a defined array of creatures in include.h or something.

#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>
#include <clock.h>

inherit SPELL;

void create() {
    ::create();
    set_spell_name("summon companion");
    set_spell_level(([ "mage" : 1, "bard" : 1, "warlock" : 1 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS summon companion");
    set_description("This spell allows a caster to manifest a creature as a permanent companion. Upon casting, the caster must select what sort of creature she wishes to call, which is dependent on the power of the caster.

You will have the next commands available:

%^ORANGE%^<call companion>%^RESET%^       will call it, at any time, if you have completed a
summoning ritual.
%^ORANGE%^<dismiss companion>%^RESET%^    will send it away again, to await your next calling.
%^ORANGE%^<release companion>%^RESET%^    will permanently send the creature away.
%^ORANGE%^<help companion>%^RESET%^       will give you more available creature commands, when it is
present. ");
    set_verbal_comp();
    set_somatic_comp();
    set_components(([
      "mage" : ([ "charcoal":1, "incense stick":1, "ivory portal":1, ]),
    ]));
    set_casting_time(2);
}

string query_cast_string() {
    return "%^ORANGE%^"+caster->QCN+" produces a handful of charcoal and a stick of incense.  Lighting the "
"incense, "+caster->QS+" begins chanting softly.";
}

int preSpell() {
    if (present("summoned companion",caster)) {
        tell_object(caster,"You have already summoned a companion, simply <call companion> to call them to "
"you.\n");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
   mapping tmp;
   object ob;

   ob = new("/d/magic/obj/scompanion")->move(caster);
   dest_effect();
}

void dest_effect() {
   ::dest_effect();
    if(objectp(TO)) TO->remove();
}
