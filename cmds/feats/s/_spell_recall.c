#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    set_author("wedex");
    feat_type("instant");
    feat_category("Steel&Magic");
    feat_name("spell recall");
    feat_prereq("Magus L4");
    feat_syntax("spell_recall");
    feat_desc("The next spell you cast will use your arcana pool instead of a spell slot.");
    set_required_for(({ "improved spell recall" }));
}


int allow_shifted() { return 1; }


int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if(ob->query_class_level("magus") < 4)
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_spell_recall(string str)
{
    object feat;
    if(!objectp(TP)) { return 0; }
    
    feat = new(base_name(TO));
    feat->setup_feat(TP, str);
    return 1;
}


void execute_feat()
{
    object obj;
    string * elements;
    int i;

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    ::execute_feat();

    tell_object(caster, "You ready your inner arcana to become magic.");
    caster->set_property("spell recall", 1);
    
    return;
}

void dest_effect()
{
    if(objectp(caster))
    {
        caster->remove_property("spell recall");
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}
