#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("MeleeDamage");
    feat_name("cleave");
    feat_prereq("Powerattack, Strength 15");
    feat_desc("This feat gives the ability to hit an additional enemy upon a successful hit. This will happen once per round. This feat requires a weapon to function");
    permanent(1);
    set_target_required(0);
    set_required_for(({ "great cleave","improved cleave" }));
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
    if (!FEATS_D->has_feat(ob, "powerattack") || ob->query_stats("strength") < 15) {
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
