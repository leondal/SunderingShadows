//_nwpbonus

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int help(){
    write(
@OLI
    nwpbonus player nwp amount || nwpbonus player nwp || nwpbonus player
    
    This will add a bonus nwp experience to the player specified. If no 
amount is specified then it will display the current bonus.

See nwps
OLI
        );
}

int cmd_nwpbonus(string str){
    string who, what, *nwps;
    int how,i;
    object ob;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

    if (!str) {
        return help();
    }

    if (sscanf(str, "%s %s %d",who,what,how) != 3) {
        if (sscanf(str, "%s %s",who,what) != 2) {
            who = str;
        }

    }

    ob = find_player(who);
    if (!how) {
        if (!user_exists(who)) {
            return notify_fail("That player does not exist.\n");
        }
        if (what) {
            write(capitalize(who)+" has a bonus of "+(string)USERCALL->user_call(who,"query_nwp_bonus",what)+" in "+what+".");

            return 1;

        }
        nwps =  (string*)USERCALL->user_call(who,"query_nwps");
        for (i=0;i<sizeof(nwps);i++) {
            write(capitalize(who)+" has a bonus of "+(string)USERCALL->user_call(who,"query_nwp_bonus",nwps[i])+" in "+nwps[i]+".");


        }
        return 1;

    }
    if (!objectp(ob)) {
        return notify_fail(capitalize(who)+" isn't currently online.\n");
    }
    if (!ob->has_nwp(what)) {
        write(capitalize(who)+"does not have that nwp, you can not apply a bonus to an nwp "+ob->query_subjective()+" does not have.");
        return 1;
    }

    ob->set_nwp_bonus(what,how);
    "/cmds/avatar/_note.c"->cmd_note("ckpt "+who+" was given a bonus of "+how+" in "+what+".");
    write(capitalize(who)+" currently has a bonus of "+ob->query_nwp_bonus(what)+" in "+what+".");
    return 1;

}

