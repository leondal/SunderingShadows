#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("Duelist");
    feat_name("opportunity strikes");
    feat_desc("This will allow character to position themself better in combat, and to strike with greater strength. It will increase damage done if they wield one one-handed weapon.

%^BOLD%^N.B.%^RESET%^ This feat tree won't work with shield worn.");
    permanent(1);
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

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
