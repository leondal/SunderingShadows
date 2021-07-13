#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("Metamind");
    feat_name("mind partition");
    feat_desc("The mind partition feat grants the ability to repel mind-controlling affects often through sheer will. While the Metamind is focused, he will gain an extra layer of protection against mind control effects. When such an attempt is made, if the Metamind would normally succumb to the mind control, they instead lose their focus and resist the attempt instead.");
    feat_prereq("Metamind L1");
    permanent(1);
    set_required_for(({"mental fortress","perfect manifestation"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("metamind") < 1)
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
