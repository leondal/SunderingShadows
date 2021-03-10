#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    set_author("wedex");
    feat_type("permanent");
    feat_category("Steel&Magic");
    feat_name("fighter training");
    feat_prereq("Magus L10");
    feat_classes("magus");
    feat_desc("Starting at 10th level, a magus counts 1/2 his total magus level as his fighter level for the purpose of qualifying for feats. If he has levels in fighter, these levels stack.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (ob->query_class_level("magus") < 10) {
        dest_effect();
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
