#include <std.h>
#include "titles.h"

inherit DAEMON;

string get_new_title(object ob){
    string myclass;
    int level;

	if(!ob) return notify_fail("not an object.\n");
    	if(!interactive(ob)) return notify_fail("not an interactive.\n");
    	myclass = ob->query_class();
	level = ob->query_level();
	if(level > 20) return 0;
	switch(myclass){
		case "fighter":
			return MALE_FIGHTER[level-1];			
		case "ranger":
			return MALE_RANGER[level-1];			
		case "paladin":
			return MALE_PALADIN[level-1];			
		case "mage":
		{
		    if((string)ob->query_gender() == "female")
			return FEMALE_MAGE[level-1];
		    else
			return MALE_MAGE[level-1];			
		}
		case "cleric":
		{
		    if((string)ob->query_gender() == "female")
			return FEMALE_CLERIC[level-1];			
		    else
			return MALE_CLERIC[level-1];			
		}
		case "druid":
		{
		    if((string)ob->query_gender() == "female")
			return FEMALE_DRUID[level-1];
		    else
			return MALE_DRUID[level-1];			
		}
		case "thief":
			return MALE_THIEF[level-1];			
		case "bard":
			return MALE_BARD[level-1];
		default: return 0;
	}
	return 0;
}
