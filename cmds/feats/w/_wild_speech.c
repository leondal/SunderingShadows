#include <std.h>

inherit FEAT;

int help();

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("WildernessLore");
    feat_name("wild speech");
    feat_prereq("Druid L11");
    feat_desc("This feat allows the character to magically speak to other people while shapeshifted. With this feat, the user can speak any language that he or she would ordinarily be able to speak if he or she was not shapeshifted.");
    permanent(1);
    set_required_for(({"wild spellcraft"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if(!ob->is_class("druid"))
    {
        dest_effect();
        return 0;
    }

    if((int)ob->query_class_level("druid") < 11)
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

