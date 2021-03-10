#include <std.h>
#include <security.h>
#define JAIL "/adm/daemon/prison_d.c"
inherit DAEMON;
int cmd_pardon(string str) {
    string who,reason;
    object player;
    if (!str || sscanf(str,"%s %s",who,reason) !=2) {
       notify_fail("Pardon <player> <reason>\n");
       return 0;
       }
    if (!archp(previous_object())) return 0;
    if (!member_group(geteuid(previous_object()), "law")) return 0;

    if (find_player(who))     find_player(who)->tell("You have been pardoned
and released for: "+reason);
    JAIL->remove_player(who);
    who=capitalize(who);
    write(who+" has been pardoned.");
    seteuid(UID_LOG);
    log_file("adm/jail",who+" was pardoned at "+ctime(time())+" by "+
             this_player()->query_true_name()+" for "+reason+"\n");
    seteuid(getuid());
    return 1;
    }

int help() {
  if (!archp(this_player())) return 0;
  write ("Format: Pardon <player> <reason>.\n"+
  "To allow the premature release of a player in good standing. All pardons "+
  "must have a reason. For less than perfect players or those you wish to "+
  "keep tabs on, see the parole command.");
  return 1;
  }
