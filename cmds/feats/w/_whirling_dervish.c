#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("Bladeweaver");
    feat_name("whirling dervish");
    feat_prereq("Bladeweaver L1");
    feat_desc("With this feat, the Bladeweaver no longer has to wait between attempts at using the whirl feat. His skill with two weapons is so great that he can use whirl every round if he desires.");
    permanent(1);
    set_required_for(({"shield of whirling steel","masters parry"}));
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("bladeweaver") < 1)
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

