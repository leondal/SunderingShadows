#include <std.h>
#include <daemons.h>
inherit FEAT;

int help();

void create() {
    ::create();
    feat_type("premanent");
    feat_category("SavageCombat");
    feat_name("wild spellcraft");
    feat_prereq("Druid L11");
    feat_desc("Some of the more adaptable druids are able to sufficiently duplicate the semantic components of spells so that they can cast them while they are shapeshifted. Only druidic and innate racial spells work in this manner, and only if they are non-offensive spells. For targetted spells, the caster may only target themselves.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

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

