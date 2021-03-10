//      /bin/user/_yell.c
//      from the Nightmare mudlib
//      yells to adjacent rooms, good for muds who want to axe shout
//      created by Descartes of Borg 20 april 1993

#include <std.h>

inherit DAEMON;

void do_yell(object env, string prompt, string str, string lang);

int cmd_yell(string str) {
   string *primary, *secondary, *tmp_arr;
   string char_arr, lang;
   int i, j, tmp, tmp2;
   object env;

   if(TP->query_ghost()) {
      write("You howl pitifully.\n");
      tell_room(ETP,"You hear the howling of a ghost.\n",TP);
      return 1;
   }
   if(!str) {
      notify_fail("Sore throat?\n");
      return 0;
   }
   if (TP->query_gagged()) {
      return notify_fail("You've been gagged and can't yell.\n");
   }
   env = ETP;
   primary = (string *)env->query_destinations();
   lang = TP->query_spoken();
   //str= "daemon/language_d"->translate(str,lang, TP);
   tell_object(TP,"%^MAGENTA%^You yell: %^RESET%^"+str+"\n");
   do_yell(env, TPQCN+" yells: ", str, lang);
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
      do_yell(env, "You hear a "+TP->query_gender()+" "+TP->query_race()+" yell: ", str, lang);
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
      do_yell(env, "You hear a voice yell from nearby.","",lang);
   }
   return 1;
}

void do_yell(object env, string prompt, string str, string lang) {
   object *inv;
   int i, tmp;

   for(i=0, tmp=(sizeof(inv=all_inventory(env))); i<tmp; i++) {
      if(!living(inv[i])) continue;
      if(!inv[i]->query_short() || (string)inv[i]->query_short() == "") continue;
      if(inv[i] == TP) continue;
      //if(!wizardp(inv[i]) && !inv[i]->query_property("understand_all_langs"))
      //str = "daemon/language_d"->translate(str,lang,inv[i]);
        message("yell","%^MAGENTA%^"+prompt+"%^RESET%^"+str+"\n",inv[i]);
   }
}

void help() {
   write(
"
%^CYAN%^NAME%^RESET%^

yell - convey a message to nearby rooms

%^CYAN%^SYNOPSIS%^RESET%^

yell %^ORANGE%^%^ULINE%^MESSAGE%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This command yells a message to nearby rooms.

%^CYAN%^SEE ALSO%^RESET%^

say, whisper, emote, emoteat, tell, reply, line use
"
);
}
