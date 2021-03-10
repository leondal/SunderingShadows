//_lore.c

#include <std.h>

inherit DAEMON;

int help();

int cmd_lore(string str) {
   string who, what, how, type, hide, hide2;
   string *list;
   int i,j;

   if(!str) {
      return help();
   }
   if(sscanf(str, "%s %s %s to %s", how, type, what, who) != 4) {
      if(sscanf(str, "%s %s %s", how, type, what) != 3) {
         if(sscanf(str,"%s %s", how, type) != 2) {
            if(sscanf(str,"%s",how) != 1){
               return help();
            }
         }
      }
   }
   mkdir("/d/save/stories/"+TPQN);
   mkdir("/d/save/stories/"+TPQN+"/story");
   mkdir("/d/save/stories/"+TPQN+"/songs");

   if(how == "teach") {

   } else if(how == "recite") {
      if(type == "song") {

//         tell_room(ETP,"%^BOLD%^"+TPQCN+" starts to tune "+TP->query_possessive()+" instrument.",TP);
//         tell_object(TP,"%^BOLD%^You start to tune your instrument.\n");
         "daemon/recite_d"->sing_song(what,TP);
         return 1;
      } else if(type == "story") {
//         TP->force_me("emote clears "+TP->query_possessive()+" throat and looks over the gathering crowd.");
         "daemon/recite_d"->tell_story(what,TP);
         return 1;
      } else {
         return help();
      }
   } else if(how == "list") {
      if(type == "song") {
         type= "songs";
      } else if(type == "story") {

      } else {
         return help();
      }
      list = get_dir("/d/save/stories/"+TPQN+"/"+type+"/");
      if(!pointerp(list) || !sizeof(list)) {
         return notify_fail("You know no "+type+".\n");
      }

      j = sizeof(list);
      for(i=0;i<j;i+=2) {
         sscanf(list[i],"%s",hide);
         if(i+1 <j) {
            sscanf(list[i+1],"%s",hide2);  
            tell_object(TP,"%^GREEN%^ "+arrange_string(hide,15)+arrange_string(hide2,15));
         } else {
            tell_object(TP,"%^GREEN%^ "+arrange_string(hide,15));
         }

      }
      return 1;
   } else if(how == "stop"){
      tell_object(TP,"You stop reciting.");
      tell_room(ETP,TPQCN+" stops reciting ShadowGate lore.",TP);
      TP->set_property("stop recite",1);
      return 1;
   } else if(how == "delete"){
      tell_object(TP,"You delete "+what);
      if(type == "song")
         "daemon/recite_d"->delete_song(what, TP);
      else 
         "daemon/recite_d"->delete_story(what,TP);
      return 1;
   } else if (how == "review") {
     if (type == "song")
       "daemon/recite_d"->review_song(what, TP);
     else
       "daemon/recite_d"->review_story(what,TP);
     return 1;
   } else if (how = "edit") {
       if(type == "songs" || type == "song")
           "daemon/recite_d"->edit_song(what,TP);
       else
           "daemon/recite_d"->edit_story(what,TP);
       return 1;
   } else {
      help();
   }

}

int help(){
   write(
"
%^CYAN%^NAME%^RESET%^

lore - manage stories

%^CYAN%^SYNTAX%^RESET%^

lore recite|teach|list|stop|review|edit story|song %^ORANGE%^%^ULINE%^NAME%^RESET%^ [%^ORANGE%^%^ULINE%^PLAYER%^RESET%^]

%^CYAN%^DESCRIPTION%^RESET%^

Lore is the bard command that allows you to work with stories and songs you have written.
      
%^ORANGE%^<lore recite story|song %^ORANGE%^%^ULINE%^NAME%^RESET%^%^ORANGE%^>%^RESET%^
  You recite songs or stories of a particular %^ORANGE%^%^ULINE%^NAME%^RESET%^ when you wish to to perform them. 

%^ORANGE%^<lore list story|song>%^RESET%^
  You list the types of songs or stories you know.

%^ORANGE%^<lore teach story|song %^ORANGE%^%^ULINE%^NAME%^RESET%^ %^ORANGE%^%^ULINE%^PLAYER%^RESET%^%^ORANGE%^>%^RESET%^
  You may teach a story or song to another bard.

%^ORANGE%^<lore stop>%^RESET%^
  You may stop reciting.

%^ORANGE%^<lore review story|song %^ORANGE%^%^ULINE%^NAME%^RESET%^%^ORANGE%^>%^RESET%^
  You can review stories or songs already written.

%^ORANGE%^<lore delete story|song %^ORANGE%^%^ULINE%^NAME%^RESET%^%^ORANGE%^>%^RESET%^
  You can delete stories or songs.

%^ORANGE%^<lore edit stories|songs %^ORANGE%^%^ULINE%^NAME%^RESET%^%^ORANGE%^>%^RESET%^
  You can edit stories or songs.

%^CYAN%^SEE ALSO%^RESET%^

story, song, languages, say, emoteat, pose
"
      );
   return 1;
}
