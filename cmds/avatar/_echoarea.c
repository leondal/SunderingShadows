#include <std.h>
#include <security.h>

inherit DAEMON;

void do_echoarea(object env, string str);

int cmd_echoarea(string str) {
   string *primary, *secondary, *tmp_arr;
   string char_arr;
   int i, j, tmp, tmp2;
   object env;

   string posxxx;
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

	if(!str) {
		notify_fail("Echoarea what?\n");
		return 0;
	}
	env = ETP;
   primary = (string *)env->query_destinations();
	seteuid(UID_LOG);
	seteuid(getuid());
	message("echo", str, ETP);
   for(i=0, tmp_arr = ({}), secondary=({}), tmp=sizeof(primary);i<tmp;i++) {
      char_arr = (string)env->query_direction(primary[i]);
      if(char_arr) {
         if(env->query_door(char_arr)) secondary += ({primary[i]});
         else tmp_arr += ({ primary[i]});
      }
   }
   primary = tmp_arr;
   for(i=0, tmp=sizeof(primary); i<tmp; i++) {
      if(!(env = find_object(primary[i]))) continue;
      if(env == ETP) continue;
		do_echoarea(env, str);
      tmp_arr = (string *)env->query_destinations();
      for(j=0, tmp2 = sizeof(tmp_arr); j<tmp2; j++) {
         if(!(char_arr = (string)env->query_direction(tmp_arr[j])))
            continue;
         if(env->query_door(char_arr)) continue;
         secondary += ({ tmp_arr[j]});
      }
   }
   secondary = distinct_array(secondary);
   for(i=0, tmp=sizeof(secondary); i<tmp; i++) {
      if(member_array(secondary[i], primary) != -1) continue;
      if(!(env = find_object(secondary[i]))) continue;
      if(env == ETP) continue;
		do_echoarea(env, str);
	}
	return 1;
}

void do_echoarea(object env, string str) {
   object *inv;
   int i, tmp;

   for(i=0, tmp=(sizeof(inv=all_inventory(env))); i<tmp; i++) {
      if(!living(inv[i])) continue;
      if(inv[i] == TP) continue;
		tell_object(inv[i],str);
	}
}

void help() {
	message("help",
		"Syntax: <echoarea [message]>\n\n"
		"Echoes the message to everyone in your environment and to those"+
		" within yelling distance. Do not abuse this power or you will"+
		" have to deal with law.",TP);
}
