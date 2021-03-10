#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("UnarmedCombat");
    feat_name("unarmed parry");
    feat_prereq("Improved rapid strikes");
    feat_desc("Unarmed parry is a passive feat that allows a chance to parry attacks based on your athletics skill. A character with this feat has learned to use her limbs in such a way at parry attacks against herself without being wounded.

%^BOLD%^N.B.%^RESET%^ This feat is not subsituting parry family of feats, as it works only when you're unarmed.");
    permanent(1);
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob)) {return 0; }
    if(!FEATS_D->has_feat(ob,"improved rapid strikes"))
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
