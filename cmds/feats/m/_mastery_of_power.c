#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("Hierophant");
    feat_name("mastery of power");
    feat_prereq("Hierophant L1");
    feat_desc("Reflecting on her knowledge, hierophant gains extended powers, able to imbue her spells with increased potency. This feats grants additional caster levels to any cast spells.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if((int)ob->query_class_level("hierophant") < 1)
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

