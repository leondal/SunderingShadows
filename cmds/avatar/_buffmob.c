#include <std.h>

inherit DAEMON;

int help(){
    write(
"
%^CYAN%^NAME%^RESET%^

buffmob - converts a mob to a champion version with increased stats and damage

%^CYAN%^SYNTAX%^RESET%^

buffmob %^ORANGE%^%^ULINE%^MOB%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

Convert %^ORANGE%^%^ULINE%^MOB%^RESET%^ to be a champion version of itself with increased stats and damage.

%^CYAN%^SEE ALSO%^RESET%^


"
    );
    return 1;
}

int cmd_buffmob(string str){
    string who;
    object mob;

    string posxxx;
    if(!objectp(TP)) return 0;
    posxxx = lower_case((string)TP->query_position());
    if(posxxx == "builder" || posxxx == "apprentice") {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
    }

    if (!str) return help();

    if (sscanf(str, "%s", who) != 1) return help();

    mob = present(who,ETP);
    if(!objectp(mob)) return notify_fail("That isn't here.\n");
    if(interactive(mob)) return notify_fail("This command does not work on players or personas.\n");


    write("%^BOLD%^You apply a serious buff to "+capitalize(who)+"\n");
    tell_room(ETP,"%^BOLD%^%^RED%^" + mob->QCN + " flexes and strikes a serious pose!%^RESET%^");

    "/daemon/champion_d"->create_champion(mob,1);
    return 1;
}
