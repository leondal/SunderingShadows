#include <std.h>
#include <domination.h>
inherit OBJECT;

object master, remote, mastercn, slave, spell;
int move_ok, disabled;

void create()
{
    ::create();
    set_name("clothes");
    set("id", ({ "clothesx999" }));
    set("short", "");
    set("long", "");
    set_weight(0);
    set_property("monsterweapon", 1);
    disabled = 0;
}

void init()
{
    ::init();
    if (living(environment(TO)) && master) {
        add_action("possess", "");
        slave = TP;
    }
}

int possess(string str)
{
    if (disabled) {
        return 0;
    }
    if (query_verb() == "quit") {
        move_ok = 1;
        spell->set_quitting();
        spell->dest_effect();
    }
    if (query_verb() == "inform" || query_verb() == "informemote" || query_verb() == "thought") {
        return 0;
    }
    if (query_verb() == "say") {
        tell_object(slave, "%^MAGENTA%^You say%^RESET%^: " + str);
        tell_room(environment(slave), "%^MAGENTA%^" + TPQCN +
                  " says%^RESET%^: " + str, TP);
    }
    if (objectp(master)) {
        TO->remove();
    }else {
        tell_object(slave, "You can only do what " + mastercn +
                    " commands you to do.");
    }
    return 1;
}

void move(mixed dest)
{
    if (objectp(dest) && dest->query_ghost()) {
        return 0;
    }
    if (!move_ok) {
        return 1;
    } else {
        return ::move(dest);
    }
}

void move_is_ok(int a)
{
    move_ok = a;
    return 1;
}

void set_master(object ob)
{
    master = ob;
    mastercn = master->query_cap_name();
}

object query_master()
{
    return master;
}

void action(string command)
{
    string temp, temp2;

    if (!command) {
        return 0;
    }
    if (sscanf(command, "%s %s", temp, temp2) != 2) {
        temp = command;
    }

    //This is a spot to check against whitelist. Last dangerous
    //command that used no confirmations should have been modded so
    //this might be not necessary. Whitelist stored in domination.h

    disabled = 1;
    if (slave) {
        slave->set_property("dominated", 1);
    }

    if (command == "follow") {
        master->add_follower(slave);
        tell_object(master, "The " + slave->query_short() + " is now following you.");
    } else {
        slave->force_me(command);
    }

    slave->remove_property("dominated");
    disabled = 0;
    return 1;
}

set_spell(object ob)
{
    spell = ob;
    return 1;
}
