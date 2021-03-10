#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
#include <skills.h>
inherit SPELL;

int bonus, i;

void create()
{
    ::create();
    set_spell_name("true form");
    set_spell_level(([ "druid" : 4, "mage" : 4, "oracle" : 4 ]));
    set_mystery("spellscar");
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS true form on TARGET");
    set_damage_desc("reverts alternative shape");
    set_description("You will the unmaking of polymorph form of the target. If their will is weak, they will revert to their true self. This spell will works on any shapechange ability, including that of supernatural origin such as werewolves or vampires. This spell won't affect alter self and glamer forms, and it won't rever werewolf's hybrid form.");
    set_save("will");
    set_target_required(1);
}

void spell_effect()
{
    object shape;

    if (do_save(target, 0)) {
        tell_object(caster, "%^BOLD%^You will the true form of " + target->QCN + ", but nothing happens.%^RESET%^");
    }
    else if (objectp(shape = target->query_property("shapeshifted"))) {
        shape->reverse_shape(target);
    }

    spell_successful();
}
