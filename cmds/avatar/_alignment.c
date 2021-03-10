//_alignment

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int help();

int cmd_alignment(string str){
    string who;
    object ob;
    int howMuch;

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

    if (sscanf(str, "%s %d", who, howMuch) != 2) {
        if (sscanf(str, "%s", who) != 1) {
            return help();
        }
    }
    ob = find_player(who);

    if (!objectp(ob)) {
        return notify_fail("Can not find +"+who+".\n");
    }
    if (!howMuch) {                                    
        write("The current alignment adjustment for the "+ob->query_al_title(ob->query_alignment())+" character "+capitalize(who)+" is "+ob->query_align_adjust()+".");
        return 1;
    }

    ob->add_align_adjust(howMuch);
    KILLING_D->check_bounty(ob);

    write("The current alignment adjustment for the "+ob->query_al_title(ob->query_alignment())+" character "+capitalize(who)+" is now "+ob->query_align_adjust()+".");

    return 1;
}

int help(){
    write(
@OLI
alignment
 
   Usage:  alignment <player> | alignment <player> <added adjustment>

   This will allow an avatar to adjust the action rating of a player. 
This is a basis for the mycause/bounty system, wherein if they gain 
sufficient renown they will show up as a reward.

   Players begin at 0 after a PKill death, and shift based on their 
actions, until they hit the renown point of 200. Then, depending on 
their alignment flag:
      over +65 will get a good mycause (doing good acts)
      under -65 will get an evil mycause (doing evil acts)
      -66 to +66 will give a neutral mycause (reputation as an active 
and powerful character, but not alignment biased)

   Normally adjustments should be in the 5-20 point range and you should 
be sure they realize they did something that affected their alignment.  
Severe actions may rate a higher adjustment. A standard attack on another 
PC awards 10-20 points, for a ballpark figure.
   Note that this command does not physically change the player's alignment, 
to do so requires coder intervention and should not be done except in the 
case of permanent character changes. Temporary plot alignment shifts should 
be done by way of align-masking items.

See also: <help renown>
       
OLI
    );
    return 1;
}