//   /adm/daemon/calc_stuff_d.c
//   created by Styx @ Shadowgate for easier maintenance of calculations for various checks
//  not exactly finished to do all I wanted but I left the in-process stuff for reference

#include <rooms.h>
#include <daemons.h>
#include <titles.h>
#include "/daemon/nwps_d.h"

#define MINLEN 60
#define HRLEN 3600
#define DAYLEN 86400

void create(){
    seteuid(getuid());
}

int calc_age_days(object who) {
   int i, totage, days, temp;

   totage = who->query_age();
   days = totage/DAYLEN;
//   temp = totage%DAYLEN;
//   hours = temp/HRLEN;
   return days;
}

// For nwp use


int is_free_class(object who, string prof) {
// to check if an nwp is free for one of a player's classes
    int i, j;
    string *keyy, *classes;
    keyy = keys(NWPS_MAP);
    classes = who->query_classes();
    if(member_array(prof, keyy) == -1) {
	log_file("Misc_Errors", "/adm/daemon/calc_stuff_d.c was passed an undefined nwp prof of "+prof+" on "+who->query_cap_name()+" on "+ctime(time())+".\n");
	write("Sorry, the prof of "+prof+" is not found in the master file, please contact a wiz.");
	return 0;
    }
    if (NWPS_MAP[prof]["free classes"]) {
        for (j=0;j<sizeof(classes);j++) {
          if (member_array(classes[j], NWPS_MAP[prof]["free classes"]) != -1) 
	     return 1;
        }
    }
    return 0;
}

int num_nwp_levels(object who) {
    int i, j, levels;
    string *profs, *keyy, *classes, *free;

    keyy = keys(NWPS_MAP);
    classes = who->query_classes();
    profs = who->query_nwps();

    for(i = 0;i<sizeof(profs);i++) {
      if(is_free_class(who, profs[i]))
	 continue;
 /*     
      if (NWPS_MAP[keyy[j]]["free classes"]) {  // don't add it in if it's free
        for (j=0;j<sizeof(classes);j++) {
          if (member_array(classes[j], NWPS_MAP[keyy[j]]["free classes"]) != -1)
	      continue;
        }
*/
      levels += who->query_nwp(profs[i]);
    }
    return levels;
}


int calc_age_to_levels(object who) {
   int i, totage, sumlevels, numclass, days, temp, hours, ratio, factor;
   string *classes;

   if(!objectp(who))  return 0;

   totage = who->query_age();
   days = totage/DAYLEN;
   temp = totage%DAYLEN;
   hours = temp/HRLEN;

   classes = who->query_classes();
   numclass = sizeof(classes);
   sumlevels = who->query_class_level(classes[0]);
   for(i=1;i<sizeof(classes);i++) {
      sumlevels += who->query_class_level(classes[i]);
   }

/* not sure what to do with this yet but here's my first thought
   if (who->query("is_assassin")) {
      numclass++;
      sumlevels = sumlevels + (int)(sumlevels/numlevels);
   }
*/
// adjust for multi's relative power
   switch(numclass) {
      case 2:  sumlevels = (sumlevels * 2)/3;	break;
      case 3:  sumlevels = (sumlevels * 3)/4;	break;
      case 4:  sumlevels = (sumlevels * 4)/5;	break;
      default:  break;
   }
	
/* ok, here's where we calc. a factor (based on days/level) to use for various things like spell transcription success, exp. % rewarded, nwp level maxes, whatever
      ratio = sumlevels/(days + (hours/24)))*100);
      switch(sumlevels) {
	case 0..5:   factor = ratio

   else ratio = sumlevels/days;
unfinished section.....
*/
   return sumlevels;
}
