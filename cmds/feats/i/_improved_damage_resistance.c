#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("DamageResistance");
    feat_prereq("Damage resistance");
    feat_desc("Improved Damage Resistance is a passive feat that when taken will further increase the character's resistance to damage beyond that of Damage Resistance.");
    feat_name("improved damage resistance");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if(!FEATS_D->has_feat(ob,"damage resistance"))
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
