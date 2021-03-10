#include <std.h>
#include "/daemon/nwps_d.h"
#define TS_D "/daemon/treesave_d.c"
#define CMD_NOTE "/cmds/avatar/_note.c"
inherit DAEMON;

int help(){
int i;
    write(
@SAIDE
nwpcap <player> <nwp> <level>

This will prevent a player from advancing a NWP past the level 
that you enter.  Note that 0 will remove the cap.

Just as in a levelcap, it's best to talk to the player first
and let them know they are getting an nwp cap and why.

Valid NWPs
SAIDE
);
    for (i = 0;i<sizeof(keys(NWPS_MAP));i++) {
        write("\t"+keys(NWPS_MAP)[i]);
    }

    return 1;

}


int cmd_nwpcap(string str){

    string prof,temp, who;
    int level;
    object ob;
    mapping nwp_cap;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

    if (!str || str == "") {
        return help(); 
    }

    if (sscanf(str,"%s %s %d",who, prof, level) != 3) {
        if (sscanf(str, "%s %s",who, prof) != 2) return help();
        level = -1;
    }
    if (!ob = find_player(who)) return notify_fail("Failed to find player "+who+"\n");
    
    if(member_array(prof,keys(NWPS_MAP)) == -1) {
        write("%^RED%^Invalid NWP%^RESET%^");
        return help();
    }

    //write(prof);
    //write(who);
    //write(identify(level));
    
    nwp_cap = ob->query("nwp_cap");
    if(!nwp_cap) nwp_cap = ([]);
    //write(identify(nwp_cap));
    //return 1;
    
    if (level == -1) {
        write("%^BOLD%^"+capitalize(who)+" is currently nwp capped in "+prof+" at "+nwp_cap[prof]+".");
        return 1;
    }
    
    if(member_array(prof,keys(nwp_cap)) != -1) {
        map_delete(nwp_cap,prof);
    }
    
    if(level != 0) {
        nwp_cap = nwp_cap + ([prof:level]);
    }
    
    ob->set("nwp_cap",nwp_cap);
    
    temp = CMD_NOTE->format_checkpoint(who,"%^ORANGE%^Nwp capped at " + level +" in nwp "+prof+".%^RESET%^");
    TS_D->add_value_to_array("notes",ob->query_name(), capitalize(TP->query_name()) + ", " + ctime(time()) + " - "+ temp);
    write("%^BOLD%^"+capitalize(who)+" is now nwp capped at "+level+" in nwp "+prof+".");
    
    return 1;
}



