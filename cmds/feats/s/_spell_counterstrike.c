#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    set_author("wedex");
    feat_type("permanent");
    feat_category("Steel&Magic");
    feat_name("spell counterstrike");
    feat_prereq("Magus L16");
    feat_classes("magus");
    feat_desc("At 16th level, whenever an enemy of the magus successfully casts a spell, that enemy provokes an attack of opportunity from the magus, sometimes two.

If a character has both the spell counterstrike feat and the spellbreaker feat they will perform three attacks of opportunity.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (ob->query_class_level("magus") < 16) {
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
