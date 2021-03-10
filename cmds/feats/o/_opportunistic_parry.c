#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("Duelist");
    feat_name("opportunistic parry");
    feat_prereq("Positioning");
    feat_desc("This feat will give you a chance based on your athletics skill to parry all attacks that are directed your way. This feat doesn't stack with Parry, you don't need it if you're fighter or paladin.

%^BOLD%^N.B.%^RESET%^ This feat doesn't stack with parry feat.");
    permanent(1);
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    object *weapons;
    if(!objectp(ob)) { return 0; }
    if(!FEATS_D->has_feat(ob,"positioning"))
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
