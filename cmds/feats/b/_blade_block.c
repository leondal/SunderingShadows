#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

int MAX;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("TwoHandedWeapons");
    feat_name("blade block");
    feat_prereq("Sweepingblow");
    feat_desc("The Blade Block feat will give you a chance based on your athletics skill to parry all attacks that are directed your way  Note you must be wielding a two-handed melee weapon in your main hand for this feat to work.

%^BOLD%^N.B.%^RESET%^ Parry, unassailable parry, unarmed parry and blade block feats do not stack. Just one will work at a time.");
    permanent(1);
    set_required_for(({"impale","light weapon","strength of arm"}));
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    object *weapons;
    if(!objectp(ob)) { return 0; }
    if(!FEATS_D->has_feat(ob,"sweepingblow"))
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
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
