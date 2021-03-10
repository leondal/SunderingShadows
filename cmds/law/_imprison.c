#include <std.h>
#include <security.h>
#include <bank.h>
#include <dirs.h>
#define TIME 86400
#define JAIL "/adm/daemon/prison_d.c"
#define JAIL_FILE "/d/shadowgate/jail"
inherit DAEMON;
do_imprison(string who,int duration,string reason,string bywho);
mapping units;

create() {
  ::create();
  units=(["mins"  :  60, "hours" : 3600, "days" : 86400, "weeks" : 604800,
               "min" : 60, "hour" : 3600, "day" : 86400, "week" : 604800]);
}

int cmd_imprison(string str) {
    string who,why,unit;
    int duration,howlong;


//    if (!archp(previous_object())) return 0;
if(!member_group(geteuid(previous_object()),"law_c")) return 0;

    if (!str || sscanf(str,"%s %d %s %s",who,duration,unit,why) !=4) {
       notify_fail("Imprison: <player> <duration> <unit> <reason>\n");
       return 0;
       }
    if (!units[unit]) {
       return notify_fail(unit + " is not a valid unit.\n");
    }
  if(member_group(who,"superuser"))
    {
	notify_fail("You can't imprison and arch!\n");
	return 0;
    }
    howlong=duration*units[unit];
    write ("unit = "+unit);
    write ("units[unit] = " + units[unit]);
    write ("howlong = "+howlong);
    write ("duration = "+duration);
/******************
    if (!archp(this_player()) )
       {
       do_imprison(this_player()->query_name(),"trying to imprison "
                   +who+" illegally.","internal security");
       }
********************************/
     do_imprison(lower_case(who), howlong, why,
                     this_player()->query_name());
    write(who+" has been imprisoned.");
    return 1;
    }

private do_imprison(string who,int duration,string why,string bywho) {
     object ob;
     int i;
     seteuid(UID_LOG);
     log_file("adm/jail",capitalize(who)+" at "+ctime(time())+" by "+
               capitalize(bywho)+" for "+why+"\n");
     seteuid(getuid());
    JAIL->add_player(who,duration,why,bywho);
    if (ob = find_player(who))
      {
      tell_object(ob,"A squad of guards enter the room and drag "+
                 "you off by your heels to ShadowGate Prison.");
      tell_room(environment(ob),"A squad of guards enter the room and drag "+
                ob->query_cap_name()+" off to prison.",ob);
      i = ob->move(JAIL_FILE);
     write("ret="+i);
      }
   return 1;
   }

int help() {
  write ("Format: Imprison <player> <duration> <unit> <reason>.\n"+
  "the duration is how long you want them imprisoned. They will be "+
  "automatically released when their time is up. Use 0 for unlimited "+
  "time. Unit can be from min,hour,day or week. It can be singular or "+
 "plural.  All imprisonments must have a reason.\n  See also:  pardon");
  return 1;
}
