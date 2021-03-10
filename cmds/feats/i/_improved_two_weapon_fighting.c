#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("TwoWeapons");
    feat_name("improved two weapon fighting");
    feat_prereq("Two weapon fighting");
    feat_desc("Improved Two Weapon Fighting is a passive feat that gives extra a second extra attack with your offhand weapon.");
    permanent(1);
    set_required_for(({"unassailable parry"}));
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob)) {return 0; }
    if(!FEATS_D->has_feat(ob,"two weapon fighting"))
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
