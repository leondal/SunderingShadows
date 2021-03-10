#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;

#include <langs.h>

int theProf;

void create() {
    ::create();
    set_spell_name("speak with animals");
    set_spell_level(([ "druid" : 1, "bard" : 3, "ranger" : 1 ]));
    set_spell_sphere("divination");
    set_syntax("cast CLASS speak with animals [on TARGET]");
    set_description("This will give the caster the ability to understand, and speak sylvan tongue.");
    set_verbal_comp();
    set_components(([
      "mage" : ([ "clay model ziggurat" : 1, ]),
    ]));
	set_helpful_spell(1);
}

string query_cast_string() {
   return caster->QCN+" starts to mouth out syllables.\n";
}

void spell_effect(int prof) {
    int i;
    string what, arg;
    object ob;

    if (!objectp(target)) {
        target = caster;
    }

    theProf = prof;
    tell_object(caster,"%^CYAN%^You start to feel knowledge enter your mind that you lacked before.");
    spell_successful();

    for (i =0;i<sizeof(ANIMAL_LANGS);i++) {
      if(member_array(ANIMAL_LANGS[i],OLD_LANGS) == -1) target->add_lang_overload(ANIMAL_LANGS[i],prof);
    }
    addSpellToCaster();
    spell_successful();
    caster->set_property("spelled",({TO}));
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 12;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect() {
    int i;
    if (objectp(target)) {
      for (i =0;i<sizeof(ANIMAL_LANGS);i++) {
        if(member_array(ANIMAL_LANGS[i],OLD_LANGS) == -1) target->subtract_lang_overload(ANIMAL_LANGS[i],theProf);
      }
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

void do_spell_blowup(int prof){ MAGIC_D->fizzile(TO); }
