#include <std.h>

inherit "/cmds/spells/h/_heal";

create()
{
    ::create();
    set_author("pator");
    set_spell_name("greater heal");
    set_spell_level(([ "cleric" : 7, "druid" : 7 ]));
    set_affixed_spell_level(7);
    set_domains(({ "renewal" }));
    set_mystery(({}));
    set_spell_sphere("healing");
    set_syntax("cast CLASS greater heal on TARGET");
    set_description("This spell will heal large amounts of damage and wounds on the target. As the caster's power grows, "
                    "he will find he is able to heal more damage.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_non_living_ok(1);
    set_helpful_spell(1);
}
