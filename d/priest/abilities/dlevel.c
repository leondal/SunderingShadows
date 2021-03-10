// Pator@ShadowGate
// April 11 1996
// Decide the druidlevel name of who

#include <std.h>
#include <druids.h>

inherit ABILITIES_DIR+"is_allowed.c";
inherit ABILITIES_DIR+"is_druid.c";
inherit ABILITIES_DIR+"max_allowed_rank.c";

string dlevel(object who);

string dlevel(object who) {
     int level, rank, found, unallowed;
     string desc, name;

     if (!(is_druidic(who)) && (is_allowed_wizard(who))) 
          { return RANK_STRING[0]; }
       
     level = who->query_level();
	// Initially the rank is 0
     rank = 1;
	// The level till which unallowed druids can reach
	    unallowed = max_unallowed_rank();
	 rank = unallowed;
         found = unallowed;
     for (found ;found >= 0;found-- )
	  {
	    if ( level < LEVELS[found] ) { rank--;}
	  }
     name = (string)who->query_true_name();
     desc = RANK_STRING[rank];

     if ( !(member_array(name, keys(DRUID_LEVELS)) == -1) )
          {  desc = DRUID_LEVELS[name]; }
     return desc; 
	}

