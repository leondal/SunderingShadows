#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("KiOffense");
    feat_name("unchained");
    feat_prereq("Monk L31");
    feat_desc("A monk who has dedicated their life and absolute focus to self-perfection will eventually reach a threshold in their power. Once surpassed, their latent Ki becomes unchained, making the monk into a formidable fighting machine. With this feat, the monk gains full BAB and their hit die increases to d10. They also gain +2 to their base unarmed damage.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob))
    {
        dest_effect();
        return 0;
    }
    
    if(ob->query_class_level("monk") < 31)
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
