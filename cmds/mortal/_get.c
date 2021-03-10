#include "move.h"
#include <std.h>
#include <daemons.h>

inherit DAEMON;

int help();

int cmd_get(string str)
{
    object ob, *inv;
    int res, i, flag, silly, ammount;
    string tmp, type;

    if(!objectp(TP) || !objectp(ETP)) { return 0; }

    if (TP->query_ghost())
    {
        notify_fail("You cannot do that in your immaterial state.\n");
        return 0;
    }

    if (TP->query_bound())
    {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    if (!str) {
        return help();
    }
    if (TP->query_blind()) {
        notify_fail("You are blind and cannot see anything to get it.\n");
        return 0;
    }
    if (silly=TP->light_blind(0)) {
        notify_fail(TP->light_blind_fail_message(silly)+"\n");
        return 0;
    }
    if (sscanf(str, "%d %s %s", ammount, type, tmp) != 3)
        if (sscanf(str, "%d %s", ammount, type) != 2)
        {
            if(str == "all coins")
            {
                if (TP->is_in_combat())
                {
                  tell_object(TP, "You're too busy to get everything off the ground!\n");
                  return 1;
                }
                flag = 0;
                inv = all_inventory(ETP);
                for(i=0;i<sizeof(inv);i++)
                {
                    if(!objectp(inv[i])) { continue; }
                    if(base_name(inv[i]) != "/std/obj/coins") { continue; }

                    res = (int)inv[i]->move(TP);

                    if (res == MOVE_OK)
                    {
                        write("You take " + inv[i]->query_short() + ".");
                        tell_room(ETP,TPQCN+" takes "+inv[i]->query_short() + ".",TP);
                        flag++;
                    }
                    else if (res == MOVE_NO_ROOM)
                    {
                        write(inv[i]->query_short() + ": You cannot carry that much.");
                        flag++;
                    }
                }
                if(!flag)
                {
                    tell_object(TP, "There are no coins here.");
                }
                return 1;
            }

            if (str == "all")
            {
                if (TP->is_in_combat())
                {
                  tell_object(TP, "You're too busy to get everything off the ground!\n");
                  return 1;
                }
                inv = all_inventory(ETP);
                for (i=0;i<sizeof(inv); i++)
                {
                    if (!inv[i]->query_short()) continue;
                    if (!inv[i]->get())
                    {
                        if (inv[i]->query_hidden()) continue;
                        if (inv[i]->query_magic_hidden()) continue;
                        write("You can't get " + inv[i]->query_short() + "!");
                        if (inv[i]->query_property("monsterweapon"))
                            inv[i]->remove();

                    }
                    else
                    {
                        res = (int)inv[i]->move(TP);
                        if (res == MOVE_OK)
                        {
                            write("You take " + inv[i]->query_short() + ".");
                            tell_room(ETP,TPQCN+" takes "+inv[i]->query_short() + ".",TP);
                        }
                        else
                            if (res == MOVE_NO_ROOM)
                        {
                            write(inv[i]->query_short() + ": You cannot carry that much.");
                        }
                    }
                }
                return 1;
            }
            ob = present(str,ETP);
            if (!ob || !ob->query_short()) {
                if (living(ob)) {
                    notify_fail("What " + str + "?\n");
                    return 0;
                }

                if ((int)ETP->is(str)) {
                    notify_fail("You can't take that!\n");
                    return 0;
                }
                notify_fail("What " + str + "?\n");
                return 0;
            }
            if (living(ob) && avatarp(ob)) {
                notify_fail("What " + str + "?\n");
                return 0;
            }
            if ((ob->query_hidden() || ob->query_magic_hidden()) && !TP->detecting_invis()) {
                notify_fail("What " + str + "?\n");
                return 0;
            }
            if (!ob->get()) {
                write("You can't get that!");
                return 1;
            }
            res = (int)ob->move(TP);
            if (res == MOVE_OK) {
                write("You take " + ob->query_short() + ".");
                tell_room(ETP,TPQCN+" takes "+(string)ob->query_short()+".",TP);
                if(TP->is_in_combat())
                {
                    TP->set_paralyzed(1, "You are getting back into position after taking "+ob->query_short()+".");
                }
                return 1;
            }
            if (res == MOVE_NOT_ALLOWED)
                notify_fail("You can't do that.\n");
            else if (res == MOVE_NO_ROOM)
                notify_fail("You cannot carry that much.\n");
            return 0;
        }
    type = lower_case(type);
    if (ammount < 1) {
        notify_fail("You can only take positive ammounts of coins.\n");
        return 0;
    }
    if (TP->query_money(type) < 0)
        return 0;
    ob = present("pile",ETP);
    if (!ob || ob->query_money(type) < ammount) {
        notify_fail("I don't see that much "+type+" here.\n");
        return 0;
    }
    if (TP->add_money(type,ammount)) {
        notify_fail("Your purse cannot hold that much.\n");
        return 1;
    }
    ob->add_money(type, -ammount);
    if (!ob->query_funds("copper",1))
        destruct(ob);
    write("You put " + ammount + " " + type + " pieces into your purse.");
    tell_room(ETP,TPQCN+" takes some "+type+".", TP);
    return 1;
}

void help() {
    write("
%^CYAN%^NAME%^RESET%^

get - get stuff

%^CYAN%^SYNOPSIS%^RESET%^

get %^ORANGE%^%^ULINE%^ITEM%^RESET%^ [%^ULINE%^%^ORANGE%^%^ORANGE%^%^ULINE%^NUMBER%^RESET%^%^RESET%^] [from %^ORANGE%^%^ULINE%^OBJECT%^RESET%^ [%^ORANGE%^%^ULINE%^NUMBER%^RESET%^%^RESET%^]]
get all [from %^ORANGE%^%^ULINE%^OBJECT%^RESET%^ [%^ORANGE%^%^ULINE%^NUMBER%^RESET%^%^RESET%^]]
get all [coins]

%^CYAN%^DESCRIPTION%^RESET%^

You will attempt to move %^ORANGE%^%^ULINE%^ITEM%^RESET%^ from room or another %^ORANGE%^%^ULINE%^OBJECT%^RESET%^ into your inventory. If there are several %^ORANGE%^%^ULINE%^ITEMS%^RESET%^ or %^ORANGE%^%^ULINE%^OBJECTS%^RESET%^ of the same name, you can append optional %^ORANGE%^%^ULINE%^NUMBER%^RESET%^ suffix to command to get needed %^ORANGE%^%^ULINE%^ITEM%^RESET%^ from desired %^ORANGE%^%^ULINE%^OBJECT%^RESET%^. For example, %^ORANGE%^<get vial 3 from sack 2>%^RESET%^ will give you 3rd vial in sack 2 of your environment.

You can get only one item for a turn in combat.

To get all items in the room use %^ORANGE%^<get all>%^RESET%^

%^CYAN%^SEE ALSO%^RESET%^

put, offer, offerall, look
");
}
