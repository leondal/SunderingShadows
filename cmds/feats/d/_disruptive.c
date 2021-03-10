#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("MagicResistance");
    feat_name("disruptive");
    feat_prereq("Fighter L6");
    feat_desc("By warding yourself, this feat increases your chance to avoid negative spell effects, granting you +4 to all your saving throws against spells.

%^BOLD%^N.B.%^RESET%^ Magus can select disruptive as one of his arcana feats from level 6.");
    permanent(1);
    allow_blind(1);
}

int allow_shifted()
{
    return 1;
}

void execute_feat()
{
    ::execute_feat();
    dest_effect();
}

int prerequisites(object ob)
{
    int magus = 0;
    if (!objectp(ob)) {
        return 0;
    }
    if (ob->is_class("magus") && file_exists("/std/class/magus.c")) {
        magus = (int)"/std/class/magus.c"->fighter_training(ob);
    }
    if (!(ob->query_class_level("fighter") + magus >= 6 ||
        ob->query_class_level("magus") >= 6)) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
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
