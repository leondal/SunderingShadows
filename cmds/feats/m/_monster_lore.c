#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() 
{
    ::create();
    set_author("wedex");
    feat_type("permanent");
    feat_category("Inquisition");
    feat_name("monster lore");
    feat_prereq("Inquisitor L1");
    feat_desc("The inquisitor adds her Wisdom modifier in addition to her Intelligence modifier, when studyng creatures. The inquisitor might use her wisdom instead of her intelligence for the amount of foes he can remember");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }
    if (ob->query_class_level("inquisitor") < 1) {
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
