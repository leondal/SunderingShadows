#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

int MAX;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("WeaponAndShield");
    feat_name("reflection");
    feat_prereq("Deflection");
    feat_desc("The Reflection feat will give a chance to cast any spells cast at you back at the caster. This should only affect harmful spells. Percentile of the success is quarter of your athletics. It does not stack with the 'spell reflection' feat. The chance to reflect depends on your athletic skill.");
    permanent(1);
    set_target_required(0);
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
    if (!FEATS_D->has_feat(ob, "deflection")) {
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
