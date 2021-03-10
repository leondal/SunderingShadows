
#include <std.h>
#include <standards.h>
#include <daemons.h>


inherit "/cmds/mortal/obj/genObj.c";


void finish_object(mapping keyMap, string template){
    int percent,i, weight, ac, newAc;
    string l;

    keyMap["~TYPE~"] = ARMOURS[type]["type"];
    keyMap["~LIMBS~"] = ARMOURS[type]["limbs"];

/* this was making numbers too high too early, changing to use roll_dice to give more of natural bell curve that creeps up *Styx*  9/27/03, last change was 7/6/03
    percent = prof*10 - (random(40)-20);
*/
    percent = roll_dice(prof+1, roll_dice(1,prof)) + (prof*5);
// was *10 for reduction for lower quality, changing to be *15 *Styx* 9/27/03
    percent = percent - (10 - (int)materialObj[0]->query_quality_type())*15;
    if (percent < 0) {
        percent = 0;
    }
    ac = ARMOURS[type]["ac"];

    if (ac) {
        newAc = ARMOURS[type]["ac"] * percent/100;
        if (newAc > ac + ac/2) {
            keyMap["~AC~"] = ac + ac/2;
        } else {
            keyMap["~AC~"] = newAc;
        }
    } else {
        keyMap["~AC~"] = 0;
    }

    keyMap["~QUALITY~"] = percent;

    keyMap["~VALUE~"] = ARMOURS[type]["price"] * percent/100;
/* Was letting weight go to 1 for 100 or better roll on quality percent.  I'm sure T didn't mean that drastic of an effect since only magic could take all the natural weight out of something.  Adding () to be sure division occurs at the right place.  Leaving else case out entirely because over 100% would reduce weight below normal in the first function and I believe that's what was actually intended.  *Styx*  4/18/03
    if (percent <100) {
        weight = ARMOURS[type]["weight"]+(ARMOURS[type]["weight"]-ARMOURS[type]["weight"] * percent/100);
    } else {
        weight = ARMOURS[type]["weight"]-(ARMOURS[type]["weight"] * percent/100);
    }
*/
    weight = ARMOURS[type]["weight"]+ARMOURS[type]["weight"]-(ARMOURS[type]["weight"] * percent/100);
// fixing this so it can't go under 1/2 normal weight *Styx* 9/27/03

    if(weight <= (ARMOURS[type]["weight"] / 3)*2)
	weight = (ARMOURS[type]["weight"] / 3)*2;
    if (weight <= 0)
        weight = 1;

    keyMap["~WEIGHT~"] = weight;

    NWP_D->perform_nwp(TP,"armorsmithing");
    NWP_D->perform_nwp(TP,"armorsmithing");

    l = keyMap["~LONG~"];
    switch(percent){
    case 0..49:
        l+="\nVery poor quality";
        break;
    case 50..75:
        l += "\nLow quality";
        break;
    case 76..90:
        l += "\nBelow average quality";
        break;
    case 91..109:
        l += "\nAverage quality";
        break;
    case 110..124:
        l += "\nAbove average quality";
        break;
    case 125..151:
        l += "\nHigh quality";
        break;
    default:
        l += "\nExcellent quality";
        break;
    }

    keyMap["~LONG~"] = l;

     for (i=0;i<sizeof(materialObj);i++) {
         materialObj[i]->use(size*(int)ARMOURS[type]["units"]);
     }
    ETO->remove_property("working");
    tell_room(environment(ETO), ETO->query_cap_name()+" pauses from working on the new armor.", ETO);
    tell_object(ETO,"You pause from working on the new armor.");
    ::finish_object(keyMap,"/cmds/mortal/templates/armor.tpl");
}
