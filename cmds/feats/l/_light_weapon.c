#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

int MAX;

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("TwoHandedWeapons");
    feat_name("light weapon");
    feat_prereq("impale");
    feat_desc("The Light Weapon feat will allow the character to maneuver a two handed weapon much more quickly than normal. This effects things like initiative rolls and the amount of stamina that it drains to heft the large weapons around.");
    permanent(1);
    set_target_required(0);
    set_required_for(({"strength of arm"}));
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }
    if(!FEATS_D->has_feat(ob,"impale"))
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
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
