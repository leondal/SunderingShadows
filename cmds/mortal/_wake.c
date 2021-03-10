#include <std.h>

inherit DAEMON;

int help();

int cmd_wake(string str){
    object who;

    if (!str) {
        return help();
    }

    if (TP->query_bound() || TP->query_unconscious()) {
        return TP->send_paralyzed_message("info",TP);
    }

    who = present(str, ETP);
    if (!objectp(who)) {
        return notify_fail(capitalize(str)+" is no here.\n");
    }

    if (who->query_magic_hidden()) {
        return notify_fail(capitalize(str)+" is no here.\n");
    }

    if (!who->query_asleep()) {
        return notify_fail("That person is not asleep");
    }

    who->set_asleep(0,0);

    tell_object(who,TPQCN+" shakes you awake.");
    tell_room(ETP,TPQCN+" shakes "+who->query_cap_name()+" awake.",({TP,who}));
    write("You shake "+who->query_cap_name()+" awake");
    return 1;



}

int help(){
    write(
"
%^CYAN%^NAME%^RESET%^

wake - wake someone up

%^CYAN%^SYNOPSIS%^RESET%^

wake %^ORANGE%^%^ULINE%^TARGET%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This command mages the %^ORANGE%^%^ULINE%^TARGET%^RESET%^ less asleep.

%^CYAN%^SEE ALSO%^RESET%^

sleep, souls, cast
"        
    );
    return 1;
}
