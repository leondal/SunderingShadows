//TO loop through a class and send a message... cuz I'm too
//lazy to figure out how to use CHAT_D

#include <std.h>

void class_news(string myclass, string mess)
{
   object *who,*who_to;
   int i;
   who = ({});
   who_to = ({});
   for(i=0;i<sizeof(who = users());i++){
      if(((string)who[i]->query_class() == myclass) || (wizardp(who[i])))
        who_to += ({ who[i] });
   }
   for(i=0;i<sizeof(who_to);i++)
   message("combat","%^BOLD%^"+capitalize(myclass)+" News: "+mess,who_to[i]);
}
