#include <std.h>
#include <daemons.h>
#include "/daemon/nwps_d.h"

inherit DAEMON;

int cmd_addnwp(string str){
    int i;
    string nwps;
    string what, whom;
    object player;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

    nwps = keys(NWPS_MAP);
    if (!str) {
        write("The following NWPs are currently supported.");
        for (i=0;i<sizeof(nwps);i++) {
            write(nwps[i]);
        }
        return 1;
    }
    if (sscanf(str, "%s to %s", what, whom) != 2) {
        what = str;
        player = TP;
    } else {
        player = find_player(whom);
        
    }
    if (!objectp(player)) {
        return notify_fail("Player not found.\n");
    }

    if (member_array(what, nwps) == -1) {
        return notify_fail("Please use only nwps that exist. Review the list by using \"addnwp\".\n");
    }

    NWP_D->add_nwp(player,what);

    write("Check to ensure the proficiency was added correctly.");
    return 1;


}

int help(){
    write(
@OLI
    Will list the current nwps, or will add one of those nwps to a player. To be
used mostly on test characters or personas. 

addnwp -> will list the nwps

addnwp <nwp> to <player> will add the nwp to the player.

OLI
    );
    return 1;
}
