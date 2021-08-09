#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("Gravecaller");
    feat_name("inspired necromancy");
    feat_prereq("Gravecaller L1");
    feat_desc("The gravecaller is singular specialized in the arts of necromancy. With this feat, the gravecaller gains +3 to caster level when casting spells of the necromancy school. Additionally, they have a chance to preserve cast necromancy spells in memory.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("gravecaller") < 1)
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
