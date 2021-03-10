//      _drop.c
//      Mostly the _drop.c from the TMI distribution mudlib
//      Originally written by Brian Leet
//      Adapted 12.13.91 by Sulam
//      Help added by Brian 1.28.92
//      Messages improved by Brian 2.5.92
//      Money handling added by Descartes of Borg Halloween 1992

#include "move.h"
#include <std.h>
#include <objects.h>
#include <daemons.h>
#include <security.h>

inherit DAEMON;

int help();

int cmd_drop(string str)
{
    object ob;
    int res, i;
    string tmp, type;
    int ammount;

    if(!str)
    {
        return help();
    }
    seteuid(getuid(previous_object()));

    if(TP->query_bound())
    {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }

    if(sscanf(str, "%d %s %s", ammount, type, tmp) != 3)
        if(sscanf(str, "%d %s", ammount, type) != 2)
        {
            if(str == "all")
            {
                object *inv;
                if (TP && TP->query_forced()) {
                    seteuid(UID_ROOT);
                    return notify_fail("Someone tried to force you to drop all!\n");
                }
                inv = all_inventory(TP);
                if(sizeof(TP->query_attackers()))
                {
                    tell_object(TP, "You are unable to drop your entire inventory while in combat!");
                    return 1;
                }
                if(sizeof(inv) == 0)
                {
                    tell_object(TP, "Nothing to drop!");
                    return 1;
                }
                tell_object(TP, "You drop your whole inventory on the ground.");
                for(i=0;i<sizeof(inv); i++ )
                {
                    ob = present(inv[i], TP);
                    tmp = (string)ob->query_short();
                    if(ob->drop()) continue;
                    res = (int)ob->move(environment(TP));
                    if(res == MOVE_OK)
                    {
                        tell_room(ETP,TPQCN+" drops "+tmp+".",TP);
                    }
                }
                return 1;
            }
            ob = present(str, TP);
            if (!objectp(ob)) {
                ob = present(str, ETP);
                if (!objectp(ob)) {
                    notify_fail("What " + str + "?\n");
                    return 1;
                } else if (ob == TP->query_draggee()) {
                    TP->set_draggee(0);
                    ob->remove_property("draggee");
                    tell_room(ETP, TPQCN + " drops a body.\n", TP);
                    tell_object(TP, "You drop a body.");
                    return 1;
                } else {
                    notify_fail("You can't drop what is already on the ground.\n");
                    return 1;
                }
            }

            tmp = (string)ob->query_short();

            if (ob->drop()) {
                if (ob->query_worn() == TP && sizeof(TP->query_attackers()) > 0) {
                    tell_object(TP, "You cannot drop a worn item in combat!");
                }
                return 1;
            }

            res = (int)ob->move(ETP);
            if (res == MOVE_OK) {
                tell_room(ETP, TPQCN + " drops " + tmp + ".\n", TP);
                tell_object(TP, "You drop " + tmp + ".");
                if (sizeof(TP->query_attackers()) > 0) {
                    TP->set_paralyzed(1, "You are getting back into position after dropping " + tmp + ".");
                }
                return 1;
            }
            if (res == MOVE_NOT_ALLOWED) {
                notify_fail("You can't do that.\n");
            } else
                if (res == MOVE_NO_ROOM) {
                    notify_fail("Not enough room.\n");
                }
            return 0;
        }

    type = lower_case(type);

    if (ammount < 1) {
        notify_fail("You can only drop positive ammounts of money.\n");
        return 0;
    }
    if ((int)TP->query_money(type) < 0) {
        notify_fail("That type of currency doesn't exist.\n");
        return 0;
    }
    if (TP->query_money(type) < ammount) {
        notify_fail("There is not that much " + type + " in your purse.\n");
        return 0;
    }
    if(ammount > 1000)
        seteuid(getuid());
        seteuid(getuid(previous_object()));
        ob = present("pile of coins", ETP);
        if(!ob)
        {
            ob = new(OB_COINS);
        }

    ob->add_money(type, ammount);
    TP->add_money(type, -ammount);
    write("You drop "+ammount+" "+type+" pieces.");
    tell_room(ETP,TPQCN+" drops some "+type+".",TP);
    ob->move(ETP);
    return 1;
}

void help()
{
    write(
"
%^CYAN%^NAME%^RESET%^

drop - put things on the ground

%^CYAN%^SYNOPSIS%^RESET%^

drop %^ORANGE%^%^ULINE%^ITEM%^RESET%^
drop all

%^CYAN%^DESCRIPTION%^RESET%^

This makes you try to drop the specified item. If all is used then your character drops all items carried.

%^CYAN%^SEE ALSO%^RESET%^

drag, get, give, look, offer, inventory, eq, set
"
        );

}
/* EOF */
