#include <std.h>

inherit "/cmds/spells/h/_heal";

void create()
{
    ::create();
    set_author("pator");
    set_spell_name("cure serious wounds");
    set_spell_level(([ "cleric" : 3, "bard" : 3, "paladin" : 4, "ranger" : 4,"druid" : 4,"inquisitor":3 ]));
    set_domains(({}));
    set_mystery(({}));
    set_affixed_spell_level(3);
    set_spell_sphere("healing");
    set_syntax("cast CLASS cure serious wounds on TARGET");
    set_description("This spell cures a large amount of wounds on one of "
        "the target's limbs.  It won't revive dead limbs.  The spell's "
        "power will increase as the caster continues to gain strength.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_non_living_ok(1);
    set_helpful_spell(1);
}
