#include <config.h>
#include <std.h>
#define PRISON_D ("/adm/daemon/prison_d")
#define JAIL ("/d/shadowgate/jail")
void check_my_inventory();
void clean_inventory();
inherit "/std/room";

void create()
{
    ::create();
    set("short", "The void");
    set("long",
        "You're in the void, stuck here for reasons unknown.\n"
        "To get out, simply %^WHITE%^<break free>%^WHITE%^.");
    set_property("light", 1);
    call_out("check_my_inventory", 20);
    set_property("no teleport", 1);
    set_no_clean(1);
    return;
}

init()
{
    ::init();
    add_action("break_free", "break");
}

int break_free(string str)
{
    if (!str) {
        return 0;
    }
    if (str != "free") {
        return 0;
    }
    TP->move_player("/d/shadow/room/forest/road30");
    return 1;
}

void handle_player_object(object ob)
{
    string start;
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ob) || !userp(ob)) {
        return;
    }
    if (PRISON_D->is_imprisoned(ob->query_true_name())) {
        ob->move_player(JAIL);
        return;
    }
    ob->set_property("voided", 1);
    if (stringp(start == ob->getenv("start"))) {
        ob->move_player(start);
        return;
    }else {
        ob->move_player("/d/shadow/room/forest/road30");
        return;
    }
    return;
}

void clean_inventory()
{
    object * players;
    object ob;

    if (!objectp(TO)) {
        return;
    }

    players = filter_array(all_inventory(TO), (:userp($1):));
    if (sizeof(players)) {
        foreach(ob in players) {
            handle_player_object(ob);
        }
        return;
    }

    foreach(ob in deep_inventory(TO))
    {
        if (!objectp(ob)) {
            continue;
        }
        if (userp(ob)) {
            handle_player_object(ob);
            continue;
        }
        ob->remove();
        if (objectp(ob)) {
            destruct(ob);
        }
        continue;
    }
    return;
}

void check_my_inventory()
{
    if (!objectp(TO)) {
        return;
    }
    if (clonep(TO)) {
        clean_inventory();
        reclaim_objects();
        TO->remove();
        return;
    }
    clean_inventory();
    reclaim_objects();
    call_out("check_my_inventory", 30);
    return;
}
