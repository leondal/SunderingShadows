#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("HellfireWarlock");
    feat_name("hellfire blast");
    feat_prereq("Hellfire warlock L7, Infernal practitioner");
    feat_desc("With this feat, the hellfire warlock gains the ability to infuse his direct eldritch shapes with the power of hellfire itself. The blast, chain and burst eldritch shapes gain additional hellfire damage, which is not subject to normal fire resistances or immunities.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("hellfire_warlock") < 7 || !FEATS_D->usable_feat(ob,"infernal practitioner"))
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

