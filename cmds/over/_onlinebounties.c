// GRENDEL
#include <std.h>
#define KILLING_D "/daemon/killing_d.c"

inherit DAEMON;

int cmd_onlinebounties(){
    // Nice long list of variables
    object *peo;
    string *names_list, *evil_list, *good_list, *law_list, *personal_list;
    string *evil_on_list, *good_on_list, *law_on_list, *personal_on_list;
    string str;
    int i;

    // Have to initialize them all now
    peo = users();
    names_list = ({});
    evil_on_list = ({});
    good_on_list = ({});
    law_on_list = ({});
    personal_on_list = ({});
    str = "";

    //  Well, we need a list of the names of online players.  This does just that.
    for(i=0;i<sizeof(peo);i++){
      if(!wizardp(peo[i]))
        names_list += ({peo[i]->query_name()});
    }

    // This returns if nobody's on the list (hard to do, but you never know)
    if(!sizeof(names_list)){
      tell_object(TP, "Ummmm  nobody's here.");
      return 1;
    }

    // This gets all types of bounties into variables for later use.
    evil_list = KILLING_D->query_evil_bounties();
    good_list = KILLING_D->query_good_bounties();
    law_list = KILLING_D->query_bounties();
    personal_list = KILLING_D->query_personals();

    // Using the list of names of people online, we compare it to the lists of people
    //    having bounties.  If someone has one type of bounty, it adds their name to the list.
    for(i=0;i<sizeof(names_list);i++){

      if(member_array(names_list[i], evil_list) != -1)
        evil_on_list += ({names_list[i]});
      if(member_array(names_list[i], good_list) != -1)
        good_on_list += ({names_list[i]});
      if(member_array(names_list[i], law_list) != -1)
        law_on_list += ({names_list[i]});
      if(member_array(names_list[i], personal_list) != -1)
        personal_on_list += ({names_list[i]});
    }


    //And this last section just makes the output look nice, and, well, outputs it.
   if(sizeof(law_on_list)){
    for(i=0;i<sizeof(law_on_list);i++){
      str += " ";
      str += arrange_string(law_on_list[i], 12);
    }
    tell_object(TP, "People online with law bounties are: ");
    tell_object(TP, str);
   } else {
    tell_object(TP, "%^BOLD%^There is nobody online with a law bounty.");
   }
    str = "";

   if(sizeof(personal_on_list)){
    for(i=0;i<sizeof(personal_on_list);i++){
      str += " ";
      str += arrange_string(personal_on_list[i], 12);
    }
    tell_object(TP, "People online with personal bounties are: ");
    tell_object(TP, str);
   } else {
    tell_object(TP, "%^BOLD%^There is nobody online with a personal bounty.");
   }
    str = "";

   if(sizeof(evil_on_list)){
    for(i=0;i<sizeof(evil_on_list);i++){
      str += " ";
      str += arrange_string(evil_on_list[i], 12);
    }
    tell_object(TP, "People online with evil bounties are: ");
    tell_object(TP, str);
   } else {
    tell_object(TP, "%^BOLD%^There is nobody online with an evil bounty.");
   }
    str = "";

   if(sizeof(good_on_list)){
    for(i=0;i<sizeof(good_on_list);i++){
      str += " ";
      str += arrange_string(good_on_list[i], 12);
    }
    tell_object(TP, "People online with good bounties are: ");
    tell_object(TP, str);
   } else {
    tell_object(TP, "%^BOLD%^There is nobody online with a good bounty.");
   }
        
    return 1;
}
