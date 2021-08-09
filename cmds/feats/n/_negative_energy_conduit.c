#include <std.h>
#include <daemons.h>

inherit FEAT;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("Gravecaller");
    feat_name("negative energy conduit");
    feat_prereq("Gravecaller L4");
    feat_desc("With this feat the gravecaller becomes infused with the powers of the grave. They gain negative energy affinity and an unholy fortitude, granting them bonus hit points equal to their prestige level.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("gravecaller") < 4)
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
