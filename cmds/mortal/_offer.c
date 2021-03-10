#include <std.h>
#include <dieties.h>

inherit DAEMON;

int help();

int cmd_offer(string str) {
    object ob;
    string wht, god;
    if (!str) {
        return help();
    }


    god = "";
    wht = "";

    if (TP->query_bound()) {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }

    if (sscanf(str, "%s to %s", wht, god) == 2) {
        if (member_array(lower_case(god), keys(DIETIES)) != -1) {
            str = wht;
            god = capitalize(god);
        } else {
            return notify_fail("You can't offer that to a non-existant god.\n");
        }
    }
    if (!(ob = present(str,this_player()))) {
        write("The "+str+" %^RESET%^must be within your inventory.");
        return 1;
    }
    if (str=="coins") {
        write("%^RED%^The gods are rich enough already!");
        tell_room(ETP,TPQCN+" is trying desperately to throw their money away...  mabye you should ask for some..",TP);
        return 1;
    }
    if (ob->query_worn())
        return notify_fail("Please remove that before offering it\n");
    if (ob->query_wielded())
        return notify_fail("Please unwield that first.\n");
    if (ob->query_property("plot_item") || ob->query_property("soulbound"))
        return notify_fail("The gods do not want that.\n");
    if (ob->query_property("no offer"))
        return notify_fail("The gods will not accept your offering at this time.\n");
    if ((time() - (int)ob->query_property("died time") < 600) && !TP->query_property("monsteroffer")) {
        return notify_fail("That object has recently been through a player death. You can not offer it yet.\n");
    }
    if (ob && objectp(ob)) {
        if (TP->query_verbose_combat()) {
            if (god != "") {
                write("You raise "+ob->query_short()+" %^RESET%^high in the air and a bolt of lightning crashes down upon it, sending it to "+god+".");

                tell_room(ETP,TPQCN+" offers "+ob->query_short()+" to "+god+".", TP);
            } else {
                write("You raise "+ob->query_short()+" %^RESET%^high in the air and a bolt of lightning crashes down upon it, destroying it.");
                tell_room(ETP,TPQCN+" offers "+ob->query_short()+".",TP);
            }
        } else {
            if (god != "") {
                write("You offer "+ob->query_short()+" to "+god+".");
                tell_room(ETP,TPQCN+" offers "+ob->query_short()+" to "+god+".", TP);
            } else {
                write("You offer "+ob->query_short()+".");
                tell_room(ETP,TPQCN+" offers "+ob->query_short()+".",TP);
            }
        }
        if (ob->query_value()) {
            ob->remove();
            TP->add_hp(random(5));
        } else
            ob->remove();
        return 1;
    }
}

int help() {
    write(
"
%^CYAN%^NAME%^RESET%^

offer - dispose of something

%^CYAN%^SYNOPSIS%^RESET%^

offer %^ORANGE%^%^ULINE%^OBJECT%^RESET%^ [to %^ORANGE%^%^ULINE%^GOD%^RESET%^]

%^CYAN%^DESCRIPTION%^RESET%^

This will destroy %^ORANGE%^%^ULINE%^OBJECT%^RESET%^ in your inventory displaying a fancy message. Destroying objects heals 1d5 hp. You can specify a %^ORANGE%^%^ULINE%^GOD%^RESET%^ if you wish so, but it gives no mechanical benefits.

%^CYAN%^SEE ALSO%^RESET%^

offerall, drop, get, inventory
"
        );
    return 1;
}
