#include <std.h>
#include <daemons.h>
#include "/daemon/nwps_d.h"

inherit DAEMON;
int help(){
    write(
@SAIDE
Usage:  fixnwps <player> <class>
This will fix the <class> based nwps of the <player> you target.
Example:  fixnwps saide thief
SAIDE
    );
    return 1;
} 

int cmd_fixnwps(string str){
  int i;
  string *nwps;
  string whom,theclass;
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
   help();
   return 1;
  }
  if(sscanf(str, "%s %s", whom, theclass) == 2) {
    player = find_player(whom);    
    if (!objectp(player)) {
        return notify_fail("Player not found.\n");
    }
    if(!player->is_class(theclass)) {
        return notify_fail("That player is not a member of the "+theclass+" class!\n");
    }    
    else {
      for(i = 0;i < sizeof(nwps);i++) {
        if (NWPS_MAP[nwps[i]]["free classes"]) {
           if (member_array(theclass, NWPS_MAP[nwps[i]]["free classes"]) != -1) {
              if (player->has_nwp(nwps[i])){
                player->remove_nwp(nwps[i]);
              }
            }
           }
         }
       NWP_D->advance_player(player,theclass,player->query_level(theclass));
       write(player->QCN+"'s nwps for the "+theclass+" class should now be fixed.  Please check to make sure.");
       return 1;
      }
    return 1;
   }
   else {
     help();
     return 1;
   }
}


