#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("RagePower");
    feat_name("sharpened accuracy");
    feat_prereq("Surprise Accuracy");
    feat_desc("With this feat, the barbarian's accurate attacks ignore miss chance from concealment effects.");
    permanent(1);
}

int allow_shifted()
{
    return 1;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!ob->is_class("barbarian")) {
        dest_effect();
        return 0;
    }
    
    if(!FEATS_D->has_feat(ob, "surprise accuracy"))
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
