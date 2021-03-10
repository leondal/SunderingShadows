#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() 
{
    ::create();
    set_author("wedex");
    feat_type("permanent");
    feat_category("Steel&Magic");
    feat_name("arcane pool");
    feat_prereq("Magus L1");
    feat_classes("magus");
    feat_desc("The magus gains a reservoir of mystical arcane energy that he can draw upon to fuel his powers or grant enhancement bonuses or properties to his weapon, the bonuses and properties last for 1 minute. The magus has the following properties available: flaming, flaming burst, frost, icy burst, shock, shocking burst.
The arcane pool size is half your magus level plus your intelligence modifier.
The enhancement bonus is 1 at 1st and one additional point for every 8 additional levels.

See also: enhance, enhancements");
    set_required_for(({ "enduring arcana", "greater arcane pool", "corrosive arcana", "thundering arcana", "devoted arcana", "warding", "augment physical prowess" }));
    permanent(1);
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!ob->is_class("magus")) {
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
    remove_feat(this_object());
    return;
}