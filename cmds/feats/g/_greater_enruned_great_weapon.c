#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    set_author("wedex");
    feat_type("permanent");
    feat_category("MagusArcana");
    feat_name("greater enruned great weapon");
    feat_prereq("Enruned Great Weapon");
    feat_classes("magus");
    feat_desc("The duration of a rune inscribed in the two handed weapon increases to 1 hour per level.");
    permanent(1);
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!ob->is_class("magus")) {
        dest_effect();
        return 0;
    }
    if (!FEATS_D->has_feat(ob, "enruned great weapon")) {
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