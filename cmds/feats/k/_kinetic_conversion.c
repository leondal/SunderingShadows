#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("Archpsion");
    feat_name("kinetic conversion");
    feat_prereq("Archpsion L4, Power Surge");
    feat_desc("When the archpsion is damaged by kinetic objects it will restore a small amount of lost power points.");
    permanent(1);
    set_required_for(({"perfect manifesting"}));
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("archpsion") < 4 || !FEATS_D->usable_feat(ob,"power surge"))
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

