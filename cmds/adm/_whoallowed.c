//      /bin/adm/_whoallowed.c
//      from the Nightmare Mudlib
//      shows who can get in from registered sites
//      created by Shadowwolf@Nightmare 93????
//      rewritten for the new security system by Descartes of Borg 930812

#include <std.h>
#include <daemons.h>
#include <security.h>

inherit DAEMON;

int cmd_whoallowed(string str) {
    string *noms;

    if(!archp(previous_object())) return 0;
    seteuid(UID_BANISH);
    if(!sizeof(noms = (string *)BANISH_D->query_allowed())) {
        write("No one is currently allowed to login from a restricted site.\n");
        seteuid(getuid());
        return 1;
    }
    seteuid(getuid());
    if(str) {
        if(member_array(lower_case(str), noms) != -1)
          write("You have already allowed "+capitalize(str)+" in.\n");
        else write("That name is not currently setup for registration login.\n");
    }
    else {
        write("These names may be used by people from restricted sites:\n");
        write(format_page(noms, 5)+"\n");
    }
    return 1;
}
void help() {
    write("Syntax: <whoallowed ([name])>\n\n"
      "Lists the names of players who may be allowed into the game\n"
      "from sites which must register characters in order to play.\n"
    );
}
