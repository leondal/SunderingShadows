#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("WeaponAndShield");
    feat_name("deflection");
    feat_prereq("Shieldwall");
    feat_desc("The Deflection feat will increase the chance to block attacks when you are wearing a shield.");
    permanent(1);
    set_target_required(0);
    set_required_for(({"reflection","counter"}));
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }
    if(!FEATS_D->has_feat(ob,"shieldwall"))
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
