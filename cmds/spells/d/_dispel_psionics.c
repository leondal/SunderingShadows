#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit "/cmds/spells/g/_greater_dispel_magic";

void create() {
    ::create();
    set_spell_name("dispel psionics");
    set_spell_level(([ "psion" : 3 ]));
    set_spell_sphere("psychokinesis");
    set_syntax("cast CLASS dispel psionics [on TARGET]");
    set_description("Despite the name, dispel psionics will dispel effects created by both psionics and magic, whether it "
"be divine or arcane in nature.  The chance to dispel a particular effect depends upon the ability of the psion versus "
"the ability of the effect's caster.  A psion may manifest this item on a room or on a particular target.");
    set_arg_needed();
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string() {
    return CASTER->QCN+" casts "+CASTER->QP+" gaze about, and the "+
       "area shimmers briefly with a translucent substance!";
}
