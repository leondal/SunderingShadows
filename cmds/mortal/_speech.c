//_speech.c

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_speech(string str)
{
    object desc;
   string speech, describe;

   desc = new(DESC_D);

   if(!str || str == ""){
      TP->set("speech string",0);
      TP->set("describe string",0);

      desc->set_profile_stuff(0,"speech string",TP);
      desc->set_profile_stuff(0,"describe string",TP);


      tell_object(TP,"Your speech has been reset to <say>");
      return 1;
   }

   if(sscanf(str, "%s %s",speech,describe) != 2){
      speech = str;
   }

    TP->set("speech string",speech);
    TP->set("describe string",describe);

    desc->set_profile_stuff(speech,"speech string",TP);
    desc->set_profile_stuff(describe,"describe string",TP);

   tell_object(TP,"Your speech is now set to <"+str+">.");
   return 1;
}

int help(){
   write("
%^CYAN%^NAME%^RESET%^

speech - set your speech verb

%^CYAN%^SYNOPSIS%^RESET%^

speech %^ORANGE%^%^ULINE%^DESCRIPTION%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This will set your speech verb. For example, if you use %^ORANGE%^<speech proclaim>%^RESET%^, everyone in the same room with you will see 'proclaims' after your name each time you speak.

N.B. 's' is always added for others after the first word in description when they see your speech.

%^CYAN%^SEE ALSO%^RESET%^

message, describe, adjective, colors, emote, emoteat, set
");
   return 1;
}
