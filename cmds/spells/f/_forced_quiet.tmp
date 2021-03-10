#include <std.h>
#include <spell.h>
#include <magic.h>

inherit SPELL;

#define FORCED_QUIET "/d/magic/obj/forced_quiet"

object quiet_ob;

void create()
{
    ::create();
    set_spell_name("forced quiet");
    set_spell_level(([ "bard" : 1, "inquisitor" : 1, "mage" : 1, "psion" : 1 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS forced quiet on TARGET");
    set_description("Not yet in. With a gesture, you muffle sound around the target's mouth, making them less talkative.");
    set_save("will");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

void dest_effect()
{
    if(objectp(quiet_ob))
        quiet_ob->remove();
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}
