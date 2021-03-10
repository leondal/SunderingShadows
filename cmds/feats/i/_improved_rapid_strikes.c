#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("UnarmedCombat");
    feat_name("improved rapid strikes");
    feat_prereq("Rapid strikes");
    feat_desc("Improved Rapid Strikes is a passive feat that gives extra unarmed.");
    permanent(1);
    set_required_for(({"unarmed parry","precise strikes"}));
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob)) {return 0; }
    if(!FEATS_D->has_feat(ob,"rapid strikes"))
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
