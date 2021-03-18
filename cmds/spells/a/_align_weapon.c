#include <std.h>
#include <magic.h>
inherit SPELL;

int lower;
object weap;

void create()
{
    ::create();
    set_spell_name("align weapon");
    set_spell_level(([ "inquisitor" : 2, "cleric" : 2 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS align weapon on good|evil|chaos|law");
    set_description("Align weapon makes you able to bypass physical damage reduction of creatures with opposing alignment. You must belong to opposing group to be able to use this spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed(1);
}

void spell_effect()
{
    string poisonf, weapstr, alignstr;

    alignstr = arg;

    if (!regexp(alignstr, "good|evil|chaos|law")) {
        tell_object(caster,"Syntax:" + query_syntax());
        TO->remove();
        return;
    }

    switch (alignstr) {
    case "good":
        if (member_array(caster->query_true_align(), ({ 3, 6, 9 })) == -1) {
            wrong_align();
            return;
        }
        break;
    case "evil":
        if (member_array(caster->query_true_align(), ({ 1, 4, 7 })) == -1) {
            wrong_align();
            return;
        }
        break;
    case "law":
        if (member_array(caster->query_true_align(), ({ 7, 8, 9 })) == -1) {
            wrong_align();
            return;
        }
        break;
    case "chaos":
        if (member_array(caster->query_true_align(), ({ 1, 2, 3 })) == -1) {
            wrong_align();
            return;
        }
        break;
    }

    if (objectp(caster)) {

        switch (alignstr) {
        case "good":
            caster->set_property("aligned_weapon", ({ 3, 6, 9 }));
            break;
        case "evil":
            caster->set_property("aligned_weapon", ({ 1, 4, 7 }));
            break;
        case "law":
            caster->set_property("aligned_weapon", ({ 7, 8, 9 }));
            break;
        case "chaos":
            caster->set_property("aligned_weapon", ({ 1, 2, 3 }));
            break;
        }

        tell_object(caster, "%^CYAN%^Chanting in low undertones you attune yourself to bypass opposing auras.");

        caster->set_property("spelled",({TO}));
        spell_successful();
        addSpellToCaster();
        spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 10;
        set_end_time();
        call_out("dest_effect",spell_duration);
    }
}

void wrong_align()
{
    tell_object(caster,"You're not of appropriate alignment to use this argument!");
}


void dest_effect()
{
    if (objectp(caster)) {
        caster->remove_property("aligned_weapon");
        tell_object(caster, "%^CYAN%^You sense your ability to bypass opposing auras fades.");
    }
    ::dest_effect();
}
