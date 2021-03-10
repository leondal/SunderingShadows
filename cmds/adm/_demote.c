//
//	Written by Melnmarn@ShadowGate on 23 feb 1995.
//	
//

#include <std.h>
#include <objects.h>
#include <dirs.h>
#include <daemons.h>
#include <security.h>
#include <config.h>

inherit OB_USER;
int check_position(string str,int level);


void create(){
	seteuid(getuid());
}

int cmd_demote(string str) {
    object ob;
    string who,pos,name;
    int lev;
//	if(((string)TP->query_position() != "god") && 
//((string)TP->query_name() != "tristan"))
//		return 0;
    	if(!str) 
      	 return notify_fail("Usage: <demote [player] [level] [position]>\n");
    	if(sscanf(str,"%s %d %s",name,lev,pos) != 3) 
      	 return notify_fail("Usage: <demote [player] [level] [position]>\n");
	if(!check_position(pos,lev)) return 0;
	who = sprintf("%s/%s/%s", "/adm/save/users", name[0..0], name);
	ob = find_player(name);
	restore_object(who);
    if(ob){
	write(sprintf("You have changed %s's level to %d and position to %s",name,lev,pos));
	tell_object(ob,sprintf("Your level and position have been changed to level %d and position %s by the Gods...",lev,pos));
	seteuid(UID_ADVANCE);
    	ob->set_position(pos);
	seteuid(getuid());
     if (lev)
     set_level(lev);
    	seteuid(UID_USERSAVE);
	ob->save_player();	
    } else { 
	write(sprintf("%s has been demoted to level %d and position %s",name,lev,pos));
	seteuid(UID_ADVANCE);
    	set_position(pos);
	seteuid(getuid());
     if (lev)
     set_level(lev);
    	seteuid(UID_USERSAVE);
	save_object(who);
    }
   return 1;
}

void help() {
    message("help", 
@MELNMARN
Syntax: <demote [player] ([level]) ([position])>\n\n"
Changes the level and position of a player.
Valid positions are: 
god, arch, developer, creator, builder, high mortal, and player.
in that order. 
MELNMARN
, this_player());
}
int check_position(string str, int level){
    mapping valid_pos;
	valid_pos = (([ 
	"god": 2001,
	"arch": 1750,
	"elder":1500,
"overseer": 1350,
	"developer":1250,
	"creator":1000,
	"apprentice":500,
	"builder": 250,
   "avatar":150,
	"high mortal":55,
	"player": 40,
        "newbie": 1,
	]));

	if( member_array(str,keys(valid_pos)) == -1) 
		return notify_fail("'"+str+" is not a valid position!\n");
	if(( str == "player" ) && ( level <= 20 )) return 1;
	if( valid_pos[str] != level)
		return notify_fail("Level "+level+" is not valid for "+capitalize(str)+". \nValid level for this position is "+valid_pos[str]+"!\n");

	return 1;

}

