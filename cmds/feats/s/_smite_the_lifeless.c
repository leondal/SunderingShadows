#include <std.h>
#include <daemons.h>
inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("CryptStalker");
    feat_name("smite the lifeless");
    feat_prereq("Crypt Stalker L7");
    feat_desc(""
"A Crypt Stalker who is true to his aim can learn how to channels positive energy "
"into their attacks, separating the necromantic magics from the walking corpse and "
"utterly destroying the undead creature. This feat gives the Crypt Stalker's critical "
"hits the ability to cause a death effect on their undead enemies unless a fortitude "
"save is made.");
    permanent(1);
    set_required_for(({}));
}

int prerequisites(object ob)
{
    if (!objectp(ob))
    {
        return 0;
    }

    if ((int)ob->query_class_level("crypt_stalker") < 7)
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