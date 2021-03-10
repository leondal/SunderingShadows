#include <std.h>
#include <daemons.h>
#include "/daemon/nwps_d.h"

#define VALID_STATS ({"strength","intelligence","wisdom","dexterity","constitution","charisma","exceptional_strength"})

#define USAGE "Usage: setatt <weight|height|age|fakerace|hp|level|stat|nwp> <[argument]> <value>\n"

mapping  units =  ([
		    "second" : 1, "seconds": 1,
		    "minute" : 60, "minutes"  :  60,
		    "hour" : 3600, "hours" : 3600,
		    "day" : 86400, "days" : 86400,
		    "week" : 604800, "weeks" : 604800,
		    "month": 2592000, "months": 2592000,
		    "year": 3075800, "years": 3075800   ]);


int tweak_playtime(string what, string str) {
  string unit;
  int duration,howlong;

  if (!str || sscanf(str,what+" %d %s",duration,unit) !=2) {
    notify_fail("setatt: <"+what+"> <duration> <unit>\n");
    return 0;
  }
  if (!units[unit]) {
    return notify_fail(unit + " is not a valid unit.\n");
  }

  howlong=duration*units[unit];
  write ("Unit = "+unit);
  write ("Units[unit] = " + units[unit]);
  write ("Time = "+duration);
  write ("Original Playtime: "+(int)TP->query_age());

  switch (what) { 
  case "droptime":
    howlong = -1 * howlong;
    // fall through!
  case "addtime":
    write ("Adjustment = "+howlong);
    howlong += (int)TP->query_age();
    // fall through #2!
  case "settime":
    TP->set_age(howlong);
    write("Final Playtime = "+howlong);
    return 1;
  }
  return notify_fail("Setatt: unknown argument. Aborted.");
}

int cmd_setatt(string str){
  
  string what, which;
  int how; 
  if(!str) return notify_fail(USAGE);
  if(sscanf(str,"%s %d",what,how) != 2){
    if((what == "level" || what == "stat"|| what == "nwp") && (sscanf(str,"%s %s %d",what,which,how) != 3)) {
	return notify_fail(USAGE);
    }
    if(what != "level" && what != "stat" && what != "nwp") {
	return notify_fail(USAGE);
    }
  }
  if(stringp(which)) { which = replace_string(which,"_"," "); }
  switch (what){
  case "height":
    TP->set_player_height(how);
    break;
  case "weight":
    TP->set_player_weight(how);
    break;
  case "age":
    TP->setPlayerAgeCat(how);
    break;
  case "hp":
    if(!wizardp(TP) && (how <= 0 || how > 100000)){
      return notify_fail("Wrong value, try again.\n");
      break;
    }
    TP->set_max_hp(how);
    TP->set_hp(how);
    break;
    case "fakerace":
      TP->set("race_mask",how);
      break;
  case "level":
    if(!wizardp(TP) && how > 150){
      return notify_fail("Maximum value exceeded!\n");
      break;
    }
    TP->set_mlevel(which,how);
    TP->set_guild_level(which,how);
    if (which == "bard" && TP->query_guild_level("mage"))
      TP->set_guild_level("mage", 0);
    if (which == "paladin" || which == "antipaladin") {
      if ((how) > 8) {
	TP->set_guild_level("cleric",(how)-8);
      }
    }
    if (which == "ranger") {
      if ((how) > 7) {
	TP->set_guild_level("cleric",(how)-7);
      }
    }
    NWP_D->advance_player(TP,which,how);
    break;
  case "stat":
    if(member_array(which,VALID_STATS,1) == -1){
      return notify_fail("Wrong stat, try again.\n");
      break;
    }
    which = VALID_STATS[member_array(which,VALID_STATS,1)];
    if(which != "exceptional_strength"){
      if(how > 25) how = 25;
      if(how < 1) how = 1;
    }
    else{
      if(how > 99) how = 99;
      if(how < -1) how = -1;
    }
    TP->set_stats(which,how);
    break;
  case "nwp":
    if(member_array(which,keys(NWPS_MAP)) == -1){
      return notify_fail("That is not a valid nwp.\n");
      if (how < 0) {
	how = 0;
      }
    }
    if (how > 20) {
      write("You are setting your nwp "+which+" to "+how+". This is considered a very high value. Please ensure you train properly with it.");
    }
    TP->set_nwp(which,how);
    break;
  case "addtime":
  case "droptime":
  case "settime":
    if(member_array(what, ({ "addtime","droptime","settime"}) ) != -1)
      return tweak_playtime(what, str);
    
  default:
    return notify_fail(USAGE);
  }
  
  write("Attribute "+what+" set to "+how+".");
  return 1;
}

int help(){
    write(
@OLI
        Usage: setatt <attribute> <[arguement, if any]> <value>

        This will set the numeric attribute of your persona.
OLI
    );
    write(
@OBS
        All numbers are still subject to adjustments due to stats and whatnot.
	currently you can set:
        [height] in inches
        [weight] in pounds
        [age] in percentage
            > this allows -20% to 500% of the start age of your current race.
            > if you are using a non standard race this will error badly.
        [hp] in integral value
            > value ranges from 1 to 100000 (avatar restriction).
            > will change your max hp and hp simultanously.
        [level] in integral value
            > please make sure you type in the correct class.
            > maximum allowed value is 150 (avatar restriction).
            > syntax: <setatt level [class] [value]>
        [stat] in integral value
            > valid arguement is any number of leading letters, e.g. st, wisd.
            > possible stat value range is 1 to 25.
            > exceptional_strength values are -1 (none), 0 (100), and 1 to 99.
            > syntax: <setatt stat [stat] [value]>
        [nwp] in integral value
            > please make sure it is a valid nwp
            > be careful to make sure if you train someone your not off the scale
            > syntax: <setatt nwp [nwp] [level]>
   [fakerace] (race)
            >  If you are a "with" this will replace your race.
            > Set to '0' and it should set you back to a 'with'. I think.
OBS
    );
    write(
@GAR
        [addtime] in integer and units
        [droptime] in integer and units
        [settime] in integer and units
             > units are: seconds, minutes, hours, days, months, years.
             > addtime adjusts up, droptime adjusts down.
             > settime resets your playtime.
             > syntax: <setatt <addtime|droptime|settime> <int> <units>
GAR
    );
    return 1;
}
