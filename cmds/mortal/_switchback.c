#include <std.h>
#include <security.h>
#include <objects.h>
#include <rooms.h>

inherit DAEMON;

int cmd_switchback(string str)
{
    object user, ob, location, hold_room;

    user = TP->query_property("switched from");
    if (!objectp(user) || interactive(user)) {
        return 0;
    }

    ob = TP;

    if (stringp(str) && objectp(ob->query("switch location"))) {
        location = (object)ob->query("switch location");
    } else {
        location = environment(ob);
    }

    seteuid(UID_EXEC);
    ob->force_me("save");
    tell_object(ob, "Good luck.");
    exec(user, TP);
    seteuid(getuid());

    if (!interactive(user)) {
        tell_object(ob, "The transition failed for some reason. The user was found but not loaded. Ensure that the Object wasn't already loaded.");
        seteuid(UID_ROOT);
        user->remove();
        seteuid(getuid());
        return 1;
    }
    ob->set_primary_start(file_name(environment(ob)));

    seteuid(UID_EXEC);
//  ob->move(hold_room=new(base_name(environment(ob))));
    if (objectp(hold_room = new(ROOM_VOID))) {
        ob->move(hold_room);
    }
    seteuid(getuid());

    user->move(location);
    tell_object(user, "You are now " + capitalize(user->query_name()) + ".");

    seteuid(UID_EXEC);
    seteuid(UID_ROOT);
    ob->remove();
    seteuid(getuid());
    call_out("dest_room", 0, hold_room);

    return 1;
}

void dest_room(object ob)
{
    if (!sizeof(all_inventory(ob))) {
        ob->remove();
    } else {
        call_out("dest_room", 0, ob);
    }
}
