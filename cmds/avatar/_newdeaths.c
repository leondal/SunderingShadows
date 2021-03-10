//      /bin/user/_deaths.c
//      gives a player's deaths
//      created by Descartes of Borg 30 march 1993
// newdeaths command adapted from listdeaths by Circe 1/27/04
#include <daemons.h>

#include <std.h>

inherit DAEMON;

string safe_cap(string str) {
  if(stringp(str)) return capitalize(str);
   else return str;
}

int cmd_newdeaths(string str) {
    int *pk;
    int i, max, thenew;
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
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

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
    thenew = sizeof(deaths)-10;
    if(thenew < 0) thenew = 0;
        borg = "%^BOLD%^%^GREEN%^"+capitalize(str)+" has died %^RESET%^%^BOLD%^"+max+" %^GREEN%^times.\n";
        borg += "%^BOLD%^%^MAGENTA%^The most recent deaths are:\n";
        borg += "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
	  borg += "%^CYAN%^"+capitalize(str)+" has been brought into the grasp of death by:\n";
        borg += sprintf("%-20s%-24s%-26s\n","Enemy","IC Date","RL DateTime");

  write(borg);
  borg = "";

        for(i=thenew; i<max; i++) {
            borg += "%^BOLD%^%^RED%^"+arrange_string(safe_cap(identify(deaths[i][0])), 20);
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
   write(
@CIRCE
This lists the last ten deaths that a player has experienced, along with RL timestamps,
to help sort out things like multikills and such.
CIRCE
);
}
