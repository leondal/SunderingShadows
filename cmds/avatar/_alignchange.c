#include <std.h>
#include "/realms/grendel/grendel.h"

inherit DAEMON;

int cmd_alignchange(string str){
    int newal, oldal;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

    if(!str) return notify_fail("You need to choose an alignment.\n");
    if(member_array(str, VALID_ALIGN_SHORTS) == -1)
      return notify_fail("That is not a valid choice.  Think LG, CE, TN, etc...\n");

    newal = align_to_num(str);
    oldal = TP->query_alignment();
    TP->set_alignment(newal);
    tell_object(TP, "Your alignment is going from "+align_abbrev(oldal)+" to "+align_abbrev(newal)+".");
    return 1;
}

int help(){
    write(
      "Syntax: alignchange <newalign> where newalign is in the form LG, CE, TN, LN,  etc...\n"
     +"\nAllows you to change your alignment to the one specified."
    );
    return 1;
}
