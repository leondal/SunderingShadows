//Changed it where it won't set axes, hammers, and spears
//size profs - Cythera 9/07
#include <std.h>
#include <standards.h>
#include <daemons.h>

inherit "/cmds/mortal/obj/genObj.c";

void finish_object(mapping keyMap, string template){
    int percent,i, base_weight, weight;
    string l;

    keyMap["~TYPE~"] = WEAPON_BASICS[type]["type"];
    if (WEAPON_BASICS[type]["prof"]) {
     //   if (member_array(WEAPON_BASICS[type]["prof"], ({"axe","hammer","spear", "blades", "clublike"})) != -1 ) {
	if (member_array(WEAPON_BASICS[type]["prof"], ({"blades"})) != -1 ) {
            switch(size){
            case 1:
                keyMap["~PROF~"] = "small "+WEAPON_BASICS[type]["prof"];

                break;
            case 2:
                keyMap["~PROF~"] = "medium "+WEAPON_BASICS[type]["prof"];
                break;
            case 3:
                keyMap["~PROF~"] = "large "+WEAPON_BASICS[type]["prof"];
                break;
            case 4:
                keyMap["~PROF~"] = "giant "+WEAPON_BASICS[type]["prof"];
                break;
            }
        } else {
            keyMap["~PROF~"] = WEAPON_BASICS[type]["prof"];
        }
    }

    percent = prof*10 - (random(40)-20);
    if (sizeof(materialObj) > 1) {
        percent = percent - (10 - (int)materialObj[1]->query_quality_type())*5;
    } else {
        percent = percent - (10 - (int)materialObj[0]->query_quality_type())*5;
    }
    keyMap["~QUALITY~"] = percent;
    if (percent < 1) {
        percent = 1;
    }
    keyMap["~WC~"] = (WEAPONS[type]["wcdice"]+size - WEAPONS[type]["size"][0])* percent/100;
    keyMap["~LWC~"] = (WEAPONS[type]["lwcdice"]+size - WEAPONS[type]["size"][0])* percent/100;
    keyMap["~WC#~"] = WEAPONS[type]["wc#"];
    keyMap["~LWC#~"] = WEAPONS[type]["lwc#"];
    keyMap["~VALUE~"] = WEAPON_BASICS[type]["price"] * percent/100;

/* Was letting weight go to 1 for all 100 or better rolls on quality percent.  I'm sure T didn't mean that drastic of an effect since only magic could take all the natural weight out of something.  Adding () to be sure division occurs at the right place.  Changing else case to only allow it to go to half of base weight at lowest after discussion with other immortals .
    if (percent <100) {
    keyMap["~WEIGHT~"] = WEAPON_BASICS[type]["weight"]+(WEAPON_BASICS[type]["weight"]-WEAPON_BASICS[type]["weight"] * percent/100);
    } else {
        keyMap["~WEIGHT~"] = WEAPON_BASICS[type]["weight"]-(WEAPON_BASICS[type]["weight"] * percent/100);
    }
*/
    base_weight = WEAPON_BASICS[type]["weight"];
    weight = (base_weight*2) - (base_weight * percent/100);
    if(weight < base_weight/2)  weight = base_weight/2;
    if(weight < 1)  		weight = 1;

    keyMap["~WEIGHT~"] = weight;

    NWP_D->perform_nwp(TP,"weaponsmithing");
    NWP_D->perform_nwp(TP,"weaponsmithing");

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
         materialObj[i]->use(size*(int)WEAPON_MATERIALS[type]["units"][i]);
     }
    ETO->remove_property("working");
    tell_room(environment(ETO), ETO->query_cap_name()+" pauses from working on the new weapon.", ETO);
    tell_object(ETO,"You pause from working on the new weapon.");
    ::finish_object(keyMap,"/cmds/mortal/templates/weapon.tpl");
}
