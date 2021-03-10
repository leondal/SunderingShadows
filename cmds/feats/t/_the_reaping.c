#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("Warmaster");
    feat_name("the reaping");
    feat_prereq("Warmaster L7");
    feat_desc("The warmaster is so deadly with two handed weapons that enemies are knocked down if they fail a saving throw when he uses sweeping blow. He has also grown so accustomed to wielding the mighty weapons that sweeping blow and impale do more damage and the carnage inspires the wielder to be more vigorous in battle.");
    permanent(1);
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("warmaster") < 7)
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

