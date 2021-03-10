#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("TwoWeapons");
    feat_name("unassailable parry");
    feat_prereq("Improved two weapon fighting");
    feat_desc("Unassailable parry is a passive feat that allows a chance at parrying attacks based on your athletics skill. You must be wielding a second weapon before receiving the parry chance.  Note both weapons must be weapons in your main hand for this feat to work

%^BOLD%^N.B.%^RESET%^ Parry, unassailable parry, unarmed parry and blade block feats do not stack. Just one will work at a time.");
    permanent(1);
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob)) {return 0; }
    if(!FEATS_D->has_feat(ob,"improved two weapon fighting"))
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
