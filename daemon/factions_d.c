//NOT ACTIVELY USED

// System to track player status in cities and regions, for smarter guard/NPC interaction.
// Nienne, 08/08.
//  be SURE to change the SAVE_FILE

#include <std.h>
#include <security.h>
#include <daemons.h>
#define SAVE_FILE "/d/avatars/nienne/dragonlair/factions"
#define REGIONS ({ "shadow", "tabor", "meadowlands" })
inherit DAEMON;

mapping pFactions;

void SAVE();
void clean_up_gone();

void create(){
	::create();
	seteuid(UID_DAEMONSAVE);
	restore_object(SAVE_FILE);
	seteuid(getuid());
}

void SAVE(){
	seteuid(UID_DAEMONSAVE);
	save_object(SAVE_FILE);
	seteuid(getuid());
}

int clean_up(){return 1;}

int query_reputations(string name) {
   int amount, i, j;
   string *which, region, replevel;
   if(!pFactions)        pFactions = ([]);
   if(!pFactions[name])  pFactions[name] = ([]);
   if(!pFactions[name][region])  pFactions[name][region] = 0;
/*   which = keys(pFactions[name]);
   amount = pFactions[name][region];
   j = sizeof(which);
   if(!pFactions[name] || !j)	{
     write(capitalize(name)+" doesn't hold status in any regions.");
     return 0;
   }
   if(j == 1 && which[i] == 0) {
     write(capitalize(name)+" doesn't hold status in any regions.");
     return 0;
   }
   write(capitalize(name)+" holds status in the following regions:\n");
   for(i=0;i < j;i++) {
      region = which[i];
      switch(which[i]) {
        case -49..49: replevel = "neutral"; break;
        case 50..149: replevel = "friendly"; break;
        case 150..249: replevel = "respected"; break;
        case 250: replevel = "revered"; break;
        case -149..-50: replevel = "unfriendly"; break;
        case -249..-150: replevel = "hated"; break;
        case -250: replevel = "hunted"; break;
        default: replevel = "broken"; break;
      }
      write("%^YELLOW%^"+capitalize(region)+":  %^WHITE%^"+pFactions[name][region]+"%^RESET%^");
   }
   return 1; */
   if(!pFactions[name])
	return(capitalize(name)+" doesn't hold status in any regions.");
   return pFactions[name];
}

int query_reputation(string name, string region) {
   int amount, i, j;
   string *which, replevel;
   region = lower_case(region);
   if(!pFactions)        pFactions = ([]);
   if(!pFactions[name])  pFactions[name] = ([]);
   if(!pFactions[name][region])  pFactions[name][region] = 0;
   if(!pFactions[name][region]) return(capitalize(name)+" doesn't hold status in "+region+".");
   return pFactions[name][region];
}

void adjust_faction(string name, string region, int amount) {
   log_file("factions",capitalize(name)+" adjusted "+amount+" in "
+capitalize(region)+" on "+ctime(time())+".\n");
   region = lower_case(region);
   if(!pFactions)                 pFactions = ([]);
   if(!pFactions[name])           pFactions[name] = ([]);
   if(!pFactions[name][region])   pFactions[name][region] = 0;
    
   pFactions[name][region] += amount;
   SAVE();
}
