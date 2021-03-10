#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("MagicResistance");
    feat_name("improved resistance");
    feat_prereq("Increased resistance");
    feat_desc("Improved Resistance is a passive feat that when taken will further boost a character's magic resistance beyond that of Increased Resistance and add even more spell damage resistance.");
    permanent(1);
    set_required_for(({"death ward","spell reflection"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }
    if(!FEATS_D->has_feat(ob,"increased resistance"))
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
 
