#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit "/cmds/spells/a/_animate_dead";

void fail();
int num_mon;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("the dead walk");
    set_spell_level(([ "warlock" : 2 ]));
    set_syntax("cast CLASS the dead walk [on TARGET]");
    set_description("This invocation infuses the recently dead with negative energy to reanimate their bodies as undead. You can raise a total number of hit dice worth of zombies and skeletons up to your casting level. They will follow you and defend you from your enemies. Unlike most common summoning spells, these monsters will not go away unless the caster quits. They are undead, so they can be turned, and so forth, but they cannot be dispelled. Many faiths and cultures condemn this spell and alike powers as it serves caster's selfish, often evil, motives and frequent users of the spell are known to be inherently evil."  + ("/cmds/spells/a/_animate_dead"->extra_help()));
    set_verbal_comp();
    set_somatic_comp();
    set_non_living_ok(1);
    set_helpful_spell(1);
    evil_spell(1);
}

string query_cast_string() {
    tell_object(caster,"%^CYAN%^A %^RESET%^stillness %^CYAN%^falls upon the area as you sway gently, drawing negative energy from your surroundings.%^RESET%^");
    tell_room(place,"%^CYAN%^A %^RESET%^stillness %^CYAN%^falls upon the area as "+caster->QCN+" sways gently.%^RESET%^",caster);
    return "display";
}
