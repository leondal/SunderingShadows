#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("VersatileArcanist");
    feat_name("master of elements");
    feat_prereq("Versatile Arcanist L4");
    feat_desc("A versatile arcanist can cast certain spells of a particular element as a different element of their choosing. Affected spells include: chill touch, burning hands, scorcher, fireball, ice storm, cone of cold, ball lightning, chain lightning, incendiary cloud, polar ray, meteor swarm, ride the lightning. In addition, the Versatile Arcanist gains +3 to caster level when casting spells that use the chosen element. Finally, the Versatile Arcanist gains 30% resistance to the chosen element.

%^BOLD%^See also:%^RESET%^help elementalist.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("versatile_arcanist") < 4)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

void execute_feat()
{
    ::execute_feat();
    dest_effect();
}

void permanent_effects(object ob)
{
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob)
{
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
