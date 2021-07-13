#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("Chronicler");
    feat_name("timeweaver");
    feat_prereq("Chronicler L1");
    feat_desc("A chronicler extends their aptitude in manipulating the past and the future. Their rally ability's duration is increased by a factor of five. Furthermore, they gain the use of several new spells which they will always have mastered and will always be able to cast:\n\ndoom, sands of time, spiritual ally, foresight, timeless body, timestop");
    permanent(1);

}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("chronicler")<1)
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
