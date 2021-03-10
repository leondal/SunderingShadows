#include <std.h>
#include "/daemon/nwps_d.h"
inherit DAEMON;

int help(){
int i;
    write(
@SAIDE
knockdown <player> <type> <duration> <msg>

The <player> must be present with you.

<type> can be either "trip" or "stun"
Trip uses triped - IE - a missed rush.  Stun is
just normal paralyzation.  Tripped, with a big number,
will last a lot longer.

<duration> is the amount of time/rounds you want it to last,
tripped is longer than paralyzed.

<msg> is the message they will see whenever they try to move
for triped or try to do anything with paralyed.

NOTE - This command is logged, so use it appropriately.

SAIDE
);

    return 1;

}


int cmd_knockdown(string str){

    string type, msg;
    object who;
    int dur;

   string posxxx;
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

    if (!str || str == "") {
        return help();
    }

    if (sscanf(str,"%s %s %d %s",who, type, dur,msg) != 4) {
        return help();
    }
    if (!who = present(who,ETP)) return notify_fail("Player must be "+
    "present in the room with you.");
    if(wizardp(who)) return notify_fail("Nope... Not today :P");
    if(type != "trip" && type != "stun") {
        return help();
    }
    if(!intp(dur)) return help();
    if(!stringp(msg)) return help();
    switch(type) {
        case "trip":
            who->set_tripped(dur,msg);
            write("%^CYAN%^"+who->QCN+"%^RESET%^ has been %^RED%^"+
            "tripped%^RESET%^ for %^YELLOW%^"+dur+"%^RESET%^ and "+
            "will see the message %^RED%^'"+msg+"%^RED%^'%^RESET%^.");
            return 1;
        case "stun":
            who->set_paralyzed(dur,msg);
            write("%^CYAN%^"+who->QCN+"%^RESET%^ has been %^BLUE%^"+
            "paralyzed%^RESET%^ for %^YELLOW%^"+dur+"%^RESET%^ and "+
            "will see the message %^RED%^'"+msg+"%^RED%^'%^RESET%^.");
            return 1;
    }

    return 1;
}
