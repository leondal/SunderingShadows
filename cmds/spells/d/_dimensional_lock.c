// Altered from "proof from teleportation" by Thorn, for mage school spells. Nienne, 11/09.
#include <spell.h>
#include <magic.h>
inherit SPELL;

int power, oldstrength;


void create() {
    ::create();
    set_author("nienne");
    set_spell_name("dimensional lock");
    set_spell_level(([ "mage" : 6, "cleric" : 6,]));
    set_domains("vigilance");
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS dimensional lock");
    set_description("By means of this spell, the wizard blocks all teleportation attempts both into and out of the area, "
"including but not limited to the teleportation wizard spells, the cleric's Word of Power spell, psionic attempts to fold "
"space, and object-generated effects such as riftgates. It will also foil specialized magical attempts to summon the "
"ward's caster out of the protected area. The target of this spell is the room that the spell is cast within.");
    set_verbal_comp();
    set_somatic_comp();
    set_peace_needed(1);
     // school specific mage spell
    set_components(([
      "mage" : ([ "sack of salt" : 1, ]),
    ]));
    set_helpful_spell(1);
}

void heart_beat() {
    if(!objectp(TO)) { return; }
    if(!objectp(caster)) { return; }
    if(!objectp(target)) { return; }
    if(!present(caster,target)) {
        tell_room(target,"The magical field of protection fades away when "+caster->QCN+" "
            "leaves the area.",caster);
        tell_object(caster,"Your magical field of protection fades away as you leave.");
        dest_effect();
        return;
    }
}

int preSpell() {
    if(place->query_property("no teleport")) {
        tell_object(caster,"This room is already protected against teleportation.");
        return 0;
    }
    return 1;
}

string query_cast_string() {
	return "%^BOLD%^%^CYAN%^"+caster->QCN+" drops a sack of salt "+
		"to the ground with a thump!";
}

void spell_effect(int prof) {
    int num, bonus, duration, strength;
    mixed temp;

    ::spell_effect();

    target = environment(caster);

    if(!objectp(target)) {
        tell_room(place,"%^BOLD%^%^RED%^"+caster->QCN+" abruptly "
            "stops casting and gets a confused look.",caster);
        tell_object(caster,"%^BOLD%^%^RED%^This spell just bugged.  Notify a coder.");
        if(objectp(TO)) TO->remove();
        return;
    }

    strength = clevel;

    oldstrength = (int)target->query_property("teleport proof");
    if(oldstrength > strength) {
       tell_object(caster,"There is a greater magic already protecting this room!");
       return 1;
    }
    target->remove_property("teleport proof");
    target->set_property("teleport proof",strength);

    tell_room(place,"%^BOLD%^%^GREEN%^The sack breaks open and the salt "+
        "flies into the air, becoming so many insubstantial sparkles "+
        "of energy!");

    addSpellToCaster();
    spell_successful();
    target->set_property("spelled",({TO}));
    duration = 30 * (int)CLEVEL;
    if(duration > 900 && !avatarp(caster)) duration = 900;
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    return;
}

void dest_effect() {
    if (!objectp(target)) {
        if(objectp(TO)) TO->remove();
        return;
    }
    tell_room(target,"The magical field of protection shimmers and then dissipates.");
    target->remove_property("teleport proof");
    if(oldstrength) target->set_property("teleport proof",oldstrength);
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
