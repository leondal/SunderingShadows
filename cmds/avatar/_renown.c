// renown command to flag people to mycauses. Nienne, 07/10.
#include <std.h>
#include <daemons.h>
inherit DAEMON;

int help();

int cmd_renown(string str){
    string who;
    object ob;
    int howMuch, adj;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice") {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

    if (!str) return help();
    if (sscanf(str, "%s %d", who, howMuch) != 2) {
        if (sscanf(str, "%s", who) != 1) return help();
    }
    ob = find_player(who);
    if (!objectp(ob)) return notify_fail("Can not find +"+who+".\n");
    adj = (int)ob->query("renown");

    if (!howMuch) {                                    
        write("The current renown for the "+ob->query_al_title(ob->query_alignment())+" character "+capitalize(who)+" is "+adj+". Their alignment is currently "+ob->query_align_adjust()+" (please use the <alignment> command if you need to bump their good/evil actions).");
        return 1;
    }

    adj = adj+howMuch;
    if(adj < 0) adj = 0;
    if(adj > 200) adj = 200;
    ob->delete("renown");
    ob->set("renown",adj);
//    KILLING_D->check_align(ob); // don't think this is needed anymoar?
    KILLING_D->check_bounty(ob);

    write("The current renown for the "+ob->query_al_title(ob->query_alignment())+" character "+capitalize(who)+" has been set to "+adj+".");

    return 1;
}

int help(){
    write(
@OLI
renown
 
   Usage:  renown <player> | renown <player> <added adjustment>

   This will allow an avatar to check the renown of a player, or adjust 
it up or down. The range is 0 (no renown) to 200 (mycause/bounty).

   Please use the <alignment> command to ensure they show up on the correct 
list (evil, neutral or good).

   Normally adjustments should be in the 5-20 point range, depending on 
severity of the action and the reputation it may gain them. Attacking another 
player, for example, awards 20 points of renown. World-shaking events may 
bump them straight to a bounty, but these would have to be vast. Likewise, you 
can award negative renown for people acting by subterfuge (or to revoke a PK 
hit if it was done quietly).
       
OLI
    );
    return 1;
}