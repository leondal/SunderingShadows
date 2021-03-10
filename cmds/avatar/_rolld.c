#include <std.h>
#include <daemons.h>
#include "/realms/grendel/include/savetypes.h"

inherit DAEMON;

#define SAVES_3D ({ "reflex", "will", "fort" })


int cmd_rolld(string str){
    string type, targname, rolltype;
    string str2;
    object ob;
    int bonus, roll, x, y,save;

    if(!str) return 0;
    //if(!str) return notify_fail("Roll what?\n");

    if(sscanf(str, "%s %s", type, str2) != 2) return notify_fail("Bad syntax (1)\n");

    switch(type){
      case "save":
        if(sscanf(str2, "%s %s %d", targname, rolltype, bonus) != 3) return notify_fail("Incorrect syntax(2)\n");

        if(!ob = find_player(targname)) return notify_fail("Can't locate player.\n");
        if(wizardp(ob) && (ob->query_level() > TP->query_level()) ) return notify_fail("Can't locate player.\n");

        if(member_array(rolltype, SAVE_SHORTS) == -1)
        {
            if(member_array(rolltype, SAVES_3D) != -1)
            {
                switch(rolltype)
                {
                case "fort":
                    save = "/daemon/saving_throw_d"->fort_save(ob,bonus);
                    break;
                case "reflex":
                    save = "/daemon/saving_throw_d"->reflex_save(ob,bonus);
                    break;
                case "will":
                    save = "/daemon/saving_throw_d"->will_save(ob,bonus);
                    break;
                }
            }
            else
            {                    
                return notify_fail("Invalid save type.\n");
            }
        }
        if(member_array(rolltype,SAVES_3D) == -1) { rolltype = SAVE_MAP[rolltype]; }

        if(SAVING_D->saving_throw(ob, rolltype, bonus)){ save = 1; }

        if(save)
        {
          tell_object(TP, targname+" made "+ob->query_possessive()+" saving throw against "+rolltype);
          return 1;
        } else {
          tell_object(TP, targname+" DID NOT make "+ob->query_possessive()+" saving throw vs "+rolltype);
          return 1;
        }

        break;

      case "stat":
        if(sscanf(str2, "%s %s %d", targname, rolltype, bonus) != 3) return notify_fail("Incorrect syntax(2)\n");
        if(!ob = find_player(targname)) return notify_fail("Can't locate player.\n");
        if(wizardp(ob) && (ob->query_level() > TP->query_level()) ) return notify_fail("Can't locate player.\n");

        if(member_array(rolltype, STAT_SHORTS) == -1) return notify_fail("Invalid stat type.\n");
        rolltype = STAT_MAP[rolltype];

        roll = random(20)+1;

        if( ( (roll-bonus > ob->query_stats(rolltype)) || (roll == 1) ) && (roll != 20) ){
          tell_object(TP, targname+" FAILED "+ob->query_possessive()+" stat test.");
          return 1;
        } else {
          tell_object(TP, targname+" passed "+ob->query_possessive()+" stat test.");
          return 1;
        }

        break;
      case "dice":
        if(sscanf(str2, "%dD%d", x, y) != 2) return notify_fail("Bad dice type.\n");
        if(x == 0 || y == 0) return notify_fail("zero is an invalid value.\n");

        roll = 0;

        for(bonus = 0;bonus < x;bonus++){
          roll += random(y);
          roll += 1;
        }
        tell_object(TP, "Total = "+roll);
        return 1;

        break;
      default:

        return notify_fail("Incorrect syntax(BREAK)\n");
        break;
    }
    return 1;
}

int help(){
write(
@GRE
    Syntax: roll save <target's name> <saving throw> <bonus>
            roll stat <target's name> <stat name> <bonus>
            roll dice xDx

Examples:
    roll save grendel bw 0  :  roll's grendel's saving throw vs breath weapon at a bonus of 0
    roll stat grendel int -2  :  rolls a stat check for grendel with a 2 PENALTY
    roll dice 2D6  :  returns a dice roll between 2 and 12, 2D6

Other Data:
    <bonus> is required.  If you don't want one, put a 0
    a negative bonus (-5) is ALWAYS a penalty to the player.
    valid stats are str, con, dex, int, wis, cha.  long names won't work
 
for saving throws:
    ppd = paralyzation poison death
    rsw = rod staff wand
    petpoly = petrification polymorph
     bw = breath weapon
    sp = spell
    will = willpower
    fort = fortitude
    reflex = reflex

    The long bersions of the names will NOT Work.
    For the 3rd edition saves, you have to pass all 
    opposing modifiers in the form of the bonus.  All 
    the player's modifiers are already added during the
    save, but the opponent's modifiers will have to be 
    added up by you.
GRE
);
}
