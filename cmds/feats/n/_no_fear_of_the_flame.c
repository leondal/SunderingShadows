#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("HellfireWarlock");
    feat_name("no fear of the flame");
    feat_prereq("Hellfire warlock L1");
    feat_desc("This feat encompasses the hardening of the warlock's  soul, upon exposure to the powers of hellfire. It affords a greater resistance to fire, as well as an immunity to fear effects.");
    permanent(1);
    set_required_for(({"infernal practitioner", "hellfire blast"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("hellfire_warlock") < 1)
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

