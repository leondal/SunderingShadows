#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("MeleeDamage");
    feat_name("great cleave");
    feat_prereq("Cleave, Strength 18");
    feat_desc("This feat gives your cleave strikes two additional damage dice.");
    permanent(1);
    set_target_required(0);
    set_required_for(({}));
}

int allow_shifted()
{
    return 0;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!FEATS_D->has_feat(ob, "cleave") || ob->query_stats("strength") < 18) {
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
