#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

int MAX;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("GeneralCombat");
    feat_name("bravery");
    feat_desc("Bravery increases your chance to withstand fear effects.");
    permanent(1);
}

int allow_shifted()
{
    return 1;
}

int prerequisites(object ob)
{
    object* weapons;
    if (!objectp(ob)) {
        return 0;
    }
    return ::prerequisites(ob);
}

void execute_feat()
{
    ::execute_feat();
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
