#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

void create()
{
    ::create();
    set_author("wedex");
    feat_type("permanent");
    feat_category("DivineBond");
    feat_name("armor bond");
    feat_classes("paladin");
    feat_desc("The paladin can expend a point from the grace pool to grant enhancement bonuses or properties to a worn body armor. The paladin has the following properties available: fortification (light, moderate, heavy), energy resistance and improved energy resistance. The enhancement bonus is 1 at 5th and one additional point for every 6 additional levels.

%^BOLD%^N.B.%^RESET%^ This is a divine feat, use <feats divinebond armor bond> to gain the feat.
See also : enhance, enhancements");
    permanent(1);
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (ob->query_class_level("paladin") < 5) {
        dest_effect();
        return 0;
    }
    /*
    if (FEATS_D->has_feat(ob, "weapon bond")) {
        dest_effect();
        return 0;
    }
    */
    return ::prerequisites(ob);
}

void execute_feat()
{
    ::execute_feat();
    dest_effect();
    return;
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