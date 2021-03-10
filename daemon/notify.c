// notify.c daemon
// notify's players of player logins.


#include <std.h>
#include <daemons.h>

inherit DAEMON;

void logon_notify(string str, object target) {
  int i,max,x;
  string s1,s2;

  object *who;
  who = filter_array(users(), "which_users", this_object(), target);
  max = sizeof(who);

    message("notify","%^YELLOW%^<< "+str+"%^YELLOW%^ >>\n%^RESET%^",who);
  return;
  if(max)
    for(i=0; i<max; i++) {
     message("notify","%^YELLOW%^<< "+str+"%^YELLOW%^ >>\n%^RESET%^",who[i]);
    }
}

varargs void mud_notify(string str, object target, string extra) {
  object *imms, *players;

  if (!extra) extra="";
  imms = filter_array(users(), "imm_users", this_object(), target);
  players = filter_array(users(), "player_users", this_object(), target);

  if(str == "disconnects from" || str == "disconnected from")
      message("notify","%^YELLOW%^<< A player has "+str+""+extra+"%^YELLOW%^ >>\n%^RESET%^",imms);
  else
      message("notify","%^YELLOW%^<< "+target->query_vis_cap_name()+" has "+str+" "+extra+"%^YELLOW%^ >>\n%^RESET%^",imms);
  message("notify","%^YELLOW%^<< Someone has "+str+"%^YELLOW%^ >>\n%^RESET%^",players);
  return;
}

int which_users(object who, object target) {
    if(!interactive(who)) return 0;
    if(!who->query_name()) return 0;
    if(target->query_name() == who->query_name()) return 0;
    if(!who->query_logon_notify()) return 0;
    if(avatarp(target) && !avatarp(who)) return 0;
    if(avatarp(who)){
      if((int)target->query_level() > (int)who->query_level()) return 0;
    }
    if(environment(target) == environment(who)) return 0;
    return 1;
}

int imm_users(object who, object target) {
    if(!interactive(who)) return 0;
    if(!who->query_name()) return 0;
    if(!objectp(target)) return 0;
    if(target->query_name() == who->query_name()) return 0;
    if(!who->query_logon_notify()) return 0;
    if(!avatarp(who)) return 0;
    if(environment(target) == environment(who)) return 0;
    return 1;
}

int player_users(object who, object target) {
    if(!interactive(who)) return 0;
    if(!who->query_name()) return 0;
    if(!objectp(target)) return 0;
    if(target->query_name() == who->query_name()) return 0;
    if(!who->query_logon_notify()) return 0;
    if(avatarp(target)) return 0;
    if(avatarp(who)) return 0;
    if(environment(target) == environment(who)) return 0;
    return 1;
}
