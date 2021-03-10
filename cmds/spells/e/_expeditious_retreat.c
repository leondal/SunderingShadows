#include <std.h>
#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("expeditious retreat");
    set_spell_level(([ "bard" : 1, "mage" : 1, "inquisitor":1, "magus" : 1 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS expeditious retreat on <direction>");
    set_description("By means of this spell, the caster increases their movement speed dramatically for a few seconds, in "
"an attempt to escape combat.  Despite this speed, all normal impediments to leaving an area (traps and obstacles) will "
"still prevent or otherwise delay the caster in leaving.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_components(([
      "mage" : ([ "feather" : 1, "water": 1,])
    ]));
	set_helpful_spell(1);
}

string query_casting_string() {
    return "%^CYAN%^"+caster->QCN+" mumbles a series of words in quick succession, as "+caster->QP+" movements seem to grow faster.";
}

int preSpell() {
   if(!arg) {
       tell_object(caster, "%^BOLD%^%^WHITE%^You must specify what direction you want to flee in!");
       return 0;
   }
   return 1;
}

void spell_effect(int prof) {
    string exits;

    exits = (string *)place->query_exits();
    if((member_array(arg, exits) == -1)) {
        tell_object(caster,"%^BOLD%^%^WHITE%^You find yourself with no way to flee further in that direction, and the spell fizzles harmlessly!");
        dest_effect();
        return;
    }

    spell_successful();
    tell_object(caster,"%^BOLD%^%^WHITE%^You mumble matching consonants that tumble over each other in rapid succession, and your movements quic%^YELLOW%^k%^WHITE%^en even as the recited words do, your feet carrying you with s%^YELLOW%^p%^WHITE%^eed towards the "+arg+".");
    tell_room(place,"%^BOLD%^%^WHITE%^"+caster->QCN+"'s feet carry "+caster->QO+" with s%^YELLOW%^p%^WHITE%^eed towards "
"the "+arg+".",caster);
    caster->set_property("true moving",arg);
    caster->set_property("running away",1);
    caster->force_me(arg);
    caster->remove_property("running away");
    caster->remove_property("true moving");
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
