#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("ImmortalDefender");
    feat_name("shield master");
    feat_prereq("Immortal defender L7, Must be wearing a shield");
    feat_desc("Immortal defenders are the undisputed masters when it comes to the use of a shield. They are able to use the shieldwall feat to full effect without sacrificing any of their melee attacks and while they are wearing a shield they are extremely resistant to being knocked down.");
    permanent(1);
}

int allow_shifted() { return 0; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("immortal_defender") < 7 || !ob->is_wearing_type("shield"))
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

