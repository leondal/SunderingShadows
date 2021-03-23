#include <spell.h>
inherit "/cmds/spells/m/_magic_mirror";

void create()
{
    ::create();
    set_spell_name("ice mirror");
    set_spell_level(([ "druid" : 8, "cleric" : 8]));
    set_mystery("winter");
    set_spell_sphere("divination");
    set_syntax("cast CLASS ice mirror on TARGET");
    set_description("This spells functions exactly like magic mirror, and requires a mirror to use.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}
