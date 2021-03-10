//      /bin/adm/_unbanish.c
//      from the Nightmare Mudlib
//      unbanishes a previously banished name
//      created by Shadowwolf@Nightmare
//      rewritten for new security system by Descartes of Borg 930809

#include <std.h>
#include <security.h>
#include <daemons.h>

inherit DAEMON;

int cmd_unbanish(string str) {
   int flag;
    if(!archp(previous_object())) return 0;

    if (!str) {
       return TO->help();
    }
    if (str[0..0] == "*") {
       str= str[1..strlen(str)-1];
       flag = 1;
    }
    write(capitalize(str = lower_case(str))+" is no longer banished.\n");
    seteuid(UID_BANISH);
    if (flag) {
       BANISH_D->remove_illegal_substring(str);
    } else {
      catch(call_other(BANISH_D, "unbanish_name", str));
    }
    seteuid(getuid());
    return 1;
}

void help() {
    write("Syntax: <unbanish [name]>\n\n"
      "Removes a name from the list of banished names.\n"
    );
}

