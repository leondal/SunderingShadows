//      /bin/user/_deaths.c
//      gives a player's deaths
//      created by Descartes of Borg 30 march 1993
#include <daemons.h>

#include <std.h>

inherit DAEMON;

string safe_cap(string str) {
  if(stringp(str)) return capitalize(str);
   else return capitalize(identify(str));
}

int cmd_listdeaths(string str) {
    int *pk;
    int i, max;
//    string *kills, *quests;
    mixed *deaths;
    string borg, tmp;
//    string check;
//    mapping minis;
//    string *lines,*test;
    object ob;

   string posxxx;
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());

  if (!stringp(str)) return 0;
    ob=find_player(lower_case(str));
    if (!objectp(ob))
     {
      if (!user_exists(lower_case(str)))
       return notify_fail("Suck, no player like that connected.\n");
     else
    deaths=(mixed *) USERCALL->user_call(str,"query_deaths");
  }
  else
   deaths = (mixed *) ob->query_deaths();

    if(!(deaths) || !(max = sizeof(deaths))) {
        borg = "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
        borg += "\n%^CYAN%^"+capitalize(ob->query_name())+" has never experienced the pain of death.\n\n";
    }
    else {
        borg = "%^BOLD%^%^GREEN%^"+capitalize(str)+" has died %^RESET%^%^BOLD%^"+max+" %^GREEN%^times.\n";
        borg += "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
	borg += "%^CYAN%^"+capitalize(str)+" has been brought into the grasp of death by:\n";
   borg += sprintf("%-20s%-24s%-26s\n","Enemy","IC Date","RL DateTime");

  write(borg);
  borg = "";

        for(i=0; i<max; i++) {
            borg += "%^BOLD%^%^RED%^"+arrange_string(safe_cap(deaths[i][0]), 20);
            tmp = "%^MAGENTA%^"+date(deaths[i][1])+" "+month(deaths[i][1])+
              " "+year(deaths[i][1])+" SG";
            borg += arrange_string(tmp, 24);
            borg += arrange_string(ctime(deaths[i][1]),26);
//            borg += "\n";
  write(borg);
  borg = "";
        }
    }

    borg += "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
    this_player()->more(explode(borg, "\n"));
    return 1;
}

void help() {
   write(@FNORD
This lists the deaths that a player has experienced, along with RL timestamps,
to help sort out things like multikills and such.
FNORD
);
}
