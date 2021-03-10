#include <std.h>
#include <daemons.h>
#include "../antioch.h"

inherit OBJECT;

void create()
{
   ::create();
   set_name("sign");
   set_property("no animate",1);
   set_weight(20000000);
   set_short("A sign");
   set_long("This sign has pictures and descriptions of those who are"+
   " no longer welcome in Antioch for their crimes against the citizens. You may read it for more information.");
}

void init()
{
   ::init();
   add_action("read","read");
   add_action("addname","addname");
   add_action("removename","removename");
}

int removename(string str) 
{
    int x;
    string *descrips;
    if(!avatarp(TP)) return 0;
    if(!str) {
        write("Try <removename> <name>.");
        return 1;
    }
    lower_case(str);
    if(member_array(str,SAVE_D->query_array(ABANNED)) == -1) {
        write(str + " is not on the banned list.");
        return 1;
    }
    x = member_array(str,SAVE_D->query_array(ABANNED));
    descrips = SAVE_D->query_array(ABDESCRIP);
    SAVE_D->remove_name_from_array(ABANNED,str);
    SAVE_D->remove_name_from_array(ABDESCRIP,descrips[x]);
    write(capitalize(str) + " has been removed from the "+
    "Antioch banned list.");
    return 1;
}

int addname(string str) 
{
    string who, describe;
    if(!avatarp(TP)) return 0;
    if(!str) {
        write("Try <add> <name> <description>.");
        return 1;
    }
    if(sscanf(str,"%s %s",who,describe) != 2) {
        write("Try <add> <name> <description>.");
        return 1;
    }
    SAVE_D->set_value(ABANNED,lower_case(who));
    SAVE_D->set_value(ABDESCRIP,describe);
    write(capitalize(who) + " has been added to the banned list "+
    "with the description "+describe+".");
    return 1;
}

int read(string str)
{
   string tmp, *names, *descrips;
   int x;
   if(str != "sign") {
   tell_object(TP,"There's not much to read here besides the sign.");
      return 1;
   }
   tell_room(ETP,""+TP->query_cap_name()+" reads over the sign.",TP);
   tell_object(TP,"%^BOLD%^%^WHITE%^The following people are no longer welcome in this fair town:\n\n");
   names = SAVE_D->query_array(ABANNED);
   descrips = SAVE_D->query_array(ABDESCRIP);
   tmp = "";
   for(x = 0;x < sizeof(names);x++) {
        tmp += "\t"+capitalize(names[x])+", "+descrips[x]+"\n";
   }
    tell_object(TP,"%^YELLOW%^"+tmp+"%^RESET%^");
    if(avatarp(TP)) { 
        tell_object(TP,"%^RED%^You may <addname> or <removename> a name from "+
       "the list.%^RESET%^");
    }
    return 1;
}
