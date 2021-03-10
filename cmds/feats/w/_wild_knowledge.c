#include <std.h>

inherit FEAT;

int help();

void create() 
{
    ::create();
    feat_type("premanent");
    feat_category("WildernessLore");
    feat_name("wild knowledge");
    feat_prereq("Druid L16");
    feat_desc("This feat will allow the user to retain knowledge and access to his or her inventory while shapeshifted. Ordinarily the inventory is merged with the essence of the wearer while transformed, but a druid who has learned this feat will be able to seperate him or herself from the items carried. This also allows gathering things from the environment or dropping them.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("druid") < 16)
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

