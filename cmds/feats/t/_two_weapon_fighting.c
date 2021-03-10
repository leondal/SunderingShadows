#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("TwoWeapons");
    feat_name("two weapon fighting");
    feat_prereq("Whirl");
    feat_desc("Two Weapon Fighting is a passive feat that gives an extra attack. You must be wielding a second weapon before receiving the bonus.");
    permanent(1);
    set_required_for(({"improved two weapon fighting","unassailable parry"}));
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob)) {return 0; }

    if(!FEATS_D->has_feat(ob,"whirl"))
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
