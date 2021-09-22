#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

int help();

void create()
{
    ::create();
    feat_type("instant");
    feat_category("Assassin");
    feat_name("hide in plain sight");
    feat_syntax("hide_in_plain_sight");
    feat_prereq("Assassin L4");
    feat_desc("With this feat an assassin can hide in combat, while being observed, in high light setting, instantaneously.");
    set_target_required(0);
}

int allow_shifted()
{
    return 1;
}

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }

    if ((int)ob->query_class_level("assassin") < 4) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_hide_in_plain_sight(string str)
{
    object obj;
    object* attackers, attacker;
    if (!objectp(TP)) {
        return;
    }

    if (!FEATS_D->usable_feat(TP, query_feat_name())) {
        return 0;
    }

    if(this_player()->cooldown("hide in plain sight"))
    {
        tell_object(this_player(), "You need to wait to use hide in plain sight.");
        dest_effect();
        return 1;
    }
    
    /*
    if (TP->query_property("hide_in_plain_sight") > time()) {
        tell_object(TP, "Hide in plain sight only once per round.");
        dest_effect();
        return 1;
    }
    */
    TP->set_hidden(1);
    attackers = TP->query_attackers();
    attackers->remove_attacker(TP);
    foreach(attacker in attackers)
    {
        TP->remove_attacker(attacker);
    }
    tell_object(TP, "You disappear.");
    obj = new("/cmds/mortal/hide.c");
    obj->set_player(TP);
    obj->move(TP);
    if (TP->query_property("hide_in_plain_sight")) {
        TP->remove_property("hide_in_plain_sight");
    }
    this_player()->add_cooldown("hide in plain sight", 30);
    //TP->set_property("hide_in_plain_sight", time() + ROUND_LENGTH);
    dest_effect();
    return 1;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
