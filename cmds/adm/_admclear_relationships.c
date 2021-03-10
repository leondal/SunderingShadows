//
//	Written by Melnmarn@ShadowGate on 23 feb 1995.
//	
//  cleaned up per T to allow to all super users and fix the copied stuff *Styx* 12/5/04

#include <std.h>
#include <objects.h>
#include <dirs.h>
#include <daemons.h>
#include <security.h>
#include <config.h>

inherit OB_USER;
int check_position(string str,int level);
void help();

int clean_relationships(object player) {
    mapping relationships;
    string *names;
    int i, count, startwith;
    relationships = player->getRelationships();
    if(!mapp(relationships)) { return 0; }
    names = keys(relationships);
    count = 0;
    startwith = sizeof(names);
    if(startwith)
    {
        for(i=0;i<startwith;i++)
        {
            if(user_exists(names[i])) { continue; }
            tell_object(TP,"Cleaning... "+names[i]);
            player->remove_relationship(names[i]);
	    count++;
        }
        player->force_me("save");
        tell_object(TP,"Cleaned "+startwith+" names and removed "+count+".");
        return 1;
    }
    tell_object(TP,"Cleaned 0 names.");
    return 1;
}


void create(){
	seteuid(getuid());
}

int cmd_admclear_relationships(string str) {
    object ob;
    string who,pos,name;
    int lev;
    if(!member_group(TPQN,"superuser"))
	return 0;
/*
      if(((string)TP->query_position() != "god") &&
((string)TP->query_position() != "arch") &
((string)TP->query_name() != "tristan"))
              return 0;
*/
     if(!str) 
      	 return help();
//     if(sscanf(str,"%s %s", name, pos) != 2)
//      	 return help();
	who = sprintf("%s/%s/%s", "/adm/save/users", str[0..0], str);
	ob = find_player(str);
	restore_object(who);
      if(ob){
//	write(sprintf("You have changed %s's password to %s",name,pos));
//	tell_object(ob,sprintf("Your password has been changed to %s by the Gods...",pos));
//	seteuid(UID_ADVANCE);
//    	ob->set_position(pos);
//       ob->set_password("*LK*");
	seteuid(getuid());
//    	ob->set_level(lev);
    	seteuid(UID_USERSAVE);
        clean_relationships(ob);
	ob->save_player();	
    } else { 
//	write(sprintf("You have changed %s's password to %s",name,pos));
    seteuid(UID_ROOT);
//    set_password("*LK*");
    seteuid(getuid());
//    seteuid(UID_USERSAVE);
        clean_relationships(TO);
     seteuid(UID_USERSAVE);
    save_object(who);
      seteuid(getuid());
     seteuid(UID_USERSAVE);
    }
   return 1;
}

void help() {
   write("Syntax: <admclear_relationships [player] >\n\n"
             "Clears off the old relationships a person may have had.");
   return 1;
}

/*
int check_position(string str, int level){
    mapping valid_pos;
	valid_pos = (([ 
	"god": 2000,
	"arch": 1750,
	"elder":1500,
"overseer": 1350,
	"developer":1250,
	"creator":1000,
	"apprentice":500,
	"builder": 250,
	"high mortal":100,
	"player": 20,
	]));

	if( member_array(str,keys(valid_pos)) == -1) 
		return notify_fail("'"+str+" is not a valid position!\n");
	if(( str == "player" ) && ( level <= 20 )) return 1;
	if( valid_pos[str] != level)
		return notify_fail("Level "+level+" is not valid for "+capitalize(str)+". \nValid level for this position is "+valid_pos[str]+"!\n");

	return 1;
}
*/

