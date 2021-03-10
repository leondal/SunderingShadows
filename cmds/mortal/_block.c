//_block

#include <std.h>

inherit DAEMON;

int cmd_block(string str){
    int i;
    if(!str) return notify_fail("Block what?\n");

    if (TP->query_bound()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }
    if(!(i = ETP->set_blocked(str, TP))){
       write(""+i);
       return notify_fail("No such exit.\n");
    }

    if(i == -1)
       return notify_fail("You are already blocking an exit.\n");
     if(i == -2)
    return notify_fail("Someone has already positioned themselves to block that exit.\n");

    write("You start blocking the "+str+" exit.");
    TP->remove_property("posed");
    TP->set_property("posed", "blocking the "+str+" exit");
    if(!TP->query_invis()) {
       tell_room(ETP,TPQCN+" positions "+TP->query_objective()+"self to block the "+str+" exit", TP);

    }
    return 1;
}

int help(){
   write(
       "
%^CYAN%^NAME%^RESET%^

block - block an exit

%^CYAN%^SYNOPSIS%^RESET%^

block %^ORANGE%^%^ULINE%^EXIT%^RESET%^ 

%^CYAN%^DESCRIPTION%^RESET%^

Blocks an exit, preventing others from going through it. They might be able to %^ORANGE%^<sneak>%^RESET%^ past you though.

%^CYAN%^SEE ALSO%^RESET%^

sneak, unblock
"
 );
  return 1;
}
