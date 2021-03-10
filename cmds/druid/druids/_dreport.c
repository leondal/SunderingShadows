// Pator@Shadowgate
// _dreport.c :	Prints a report of the druidic status of a druid
//		Only for Council members
// Oct 16th 1996
#include <std.h>
#include <ansi.h>
#include <druids.h>

// Define the command
int cmd_dreport(string who);

private string OWNER;
private object CouncilMember;

int cmd_dreport(string who) {
object druid, item;
int allowed_cmd, is_druid, *value;
mixed *spell_values;

	if (!who)
	   { tell_object(TP,
		RED+"%^BOLD%^You have to state the name of a druid !");
	     return 1;
	   }

	OWNER = (string)this_player()->query_true_name();
	druid = find_player(who);

	if ( member_array(OWNER,keys(DRUID_LEVELS)) != -1 ) 
	   { allowed_cmd = 1; 
	     CouncilMember = TP;
	     tell_object( CouncilMember,
	         "%^BOLD%^%^CYAN%^Nature is about to execute thy command !");
	   }
	else
	   { tell_object(TP,
		RED+"%^BOLD%^You aren't allowed to use this command!");
	     allowed_cmd = 0;
	     return 1;
	   }

	if (!druid) 
	   { tell_object( CouncilMember,
		YEL+"%^BOLD%^No such druid in thy reality!!!");
	     return allowed_cmd;
	   }
	else 
	  { 	is_druid = ( (string)druid->query_class() == "druid" );
		if (!is_druid) {
		tell_object( CouncilMember,
		RED+"%^BOLD%^This being isn't a druid !!!!");
		return 1;
		}
	  }

	item = present("mistletoe", druid);
	
	if (!item)
		{ tell_object( CouncilMember,
		     "This druid has NO mistletoe !!");
		  return 1; }

		// Get values from the mistletoe
	spell_values = 
             (mixed *)item->query_spell_values();

		// values from the mistletoe
//	value[1] = (object)spell_values[1];
//	value[2] = (mapping)spell_values[2];
//	value[3] = (mapping)spell_values[3];
//	value[4] = (mapping)spell_values[4];
			
	value[5] = (int)item->query_worship();
	value[6] = (int)item->query_interval();

	write("Worship  : "+value[5]);
        write("Interval : "+value[6]);

	return 1;
}

	
