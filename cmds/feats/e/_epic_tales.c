#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("Chronicler");
    feat_name("epic tales");
    feat_prereq("Chronicler L4");
    feat_desc("A chronicler can spin a tale so evocative and so moving that it conveys the effects of bardic music through written word. This feat increases the effects of the bard's inspirations by +2. The chronicler also gains the 'doom' and 'spiritual ally' spells.");
    permanent(1);
    set_required_for(({"lay of the exalted dead"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("chronicler") < 4)
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
