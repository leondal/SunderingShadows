#include <std.h>
#include <daemons.h>
inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("Presence");
    feat_name("improved channel");
    feat_prereq("Channel");
    feat_desc("This feat allows the channeler to more effectively channel their energies. " +
    "This adds two caster levels to their channel and channel smite features. Note: This is not a free feat.");
    permanent(1);
    feat_classes(({"cleric", "paladin"}));
    set_required_for(({}));
}

int prerequisites(object ob)
{
    if (!objectp(ob))
    {
        return 0;
    }
    
    if(!FEATS_D->usable_feat(ob, "channel"))
    {
        dest_effect();
        return;
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