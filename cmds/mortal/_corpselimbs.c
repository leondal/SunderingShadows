// _corpselimbs - to see what limbs a corpse has available 
// for rending.  By Circe 9/5/04
#include <std.h>

int cmd_corpselimbs();

int cmd_corpselimbs() {
string *limb;
object corpse;
int size, count;
    set_author("circe");
    if(corpse = present("corpse",ETP)){
       limb = present("corpse",ETP)->query_limbs();
       size = sizeof(limb);
       if (!size) {
         tell_object(TP,
	   	  "%^RED%^%^BOLD%^That corpse has no limbs left!%^RESET%^"); }
       else {
         tell_object(this_player(),
	   	  "%^CYAN%^%^BOLD%^The corpse has the following physical limbs:");
       }
       printf("\n");
       for (count=0; count < size; count++)
         { printf("%-20s",limb[count]); }
           printf("\n");
       return 1;
   }else{
      tell_object(TP,"There is no corpse here!");
      return 1;
   }
}

void help() {
    write(
"
%^CYAN%^NAME%^RESET%^

corpselimbs - list corpse limbs

%^CYAN%^SYNOPSIS%^RESET%^

corpselimbs %^ORANGE%^%^ULINE%^CORPS%^RESET%^E

%^CYAN%^DESCRIPTION%^RESET%^

You can use this command to find out what limbs the first corpse in an area has.

%^CYAN%^SEE ALSO%^RESET%^

rend, bury

"
        );
 
}
