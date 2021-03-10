/*    /cmds/adm/_fixlevels.c
 *    from the Nightmare Mudlib 3.2
 *    a promote/demote style command for use with the Nightmare system
 *    created by Descartes of Borg 940124
 */

#define DISCARDED_CLASSES {("druid","barbarian","assassin","sage")}
#define LEGAL_CLASSES {( "fighter", "mage", "ranger", "bard", "paladin", "antipaladin",  "cavalier", "cleric", "ranger", "thief" )} 
#include <std.h>
#include <security.h>

inherit DAEMON;

int fix_all_levels(object victim, int level) {
    string * classes, *reset_classes;
  int towhatlevel;
 string * possible_classes, *discarded_classes;



    towhatlevel = victim->query_highest_level();
    classes = victim->query_classes();
  write(identify(classes));
    reset_classes = possible_classes - classes + discarded_classes;

    write(identify(classes));
    write(identify(reset_classes));
    if (!level) {
	while (classes) {
	    victim->set_mlevel(classes[0], level);
	    classes -= classes[0];
	}

	while(reset_classes) {
	    victim->set_mlevel(reset_classes[0],0);
	    victim->remove_class(reset_classes[0]);
	      reset_classes -= reset_classes[0];
	  }
	} else {
	    while (classes) {
		victim->set_mlevel(classes[0], towhatlevel);
		classes -= classes[0];
	    }

	    while(reset_classes) {
		victim->set_mlevel(reset_classes[0],0);
		victim->remove_class(reset_classes[0]);
		  reset_classes -= reset_classes[0];
	      }
	    }
	    return 1;
	}

	int cmd_fixlevels(string str) {
	    string pos, nom;
	    object ob;
	    int lev,ulvl;

	    if(!archp(previous_object())) return 0;
	    if(!str) 
		return notify_fail("Usage: <fixlevels [player] ([level]) ([position])>\n");
	    if(sscanf(str, "%s %s", nom, str) != 2)
		return notify_fail("Usage: <fixlevels [player] ([level]) ([position])>\n");
	    if(!(ob = find_player(nom = lower_case(nom))))
		return notify_fail(sprintf("Cannot find %s anywhere.\n",capitalize(nom)));
	    if(sscanf(str, "%d %s", lev, pos) != 2) {
		if(!sscanf(str, "%d", lev)) {
		    /*
				if(( (string)this_player()->query_position() != "god" ) &&
				    ( lower_case(str) == "god" )) {
				    seteuid(UID_LOG);
				    log_file("xmote", sprintf("%s attempted to raise %s to position %s  %s.\n", 
				    (string)this_player()->query_name(),nom, str,ctime(time())));
				    return 0;
				}
		    */
		    seteuid(UID_LOG);
		    log_file("xmote", sprintf("%s went to position %s thanks to "
			"%s on %s.\n", nom, str, (string)previous_object()->query_name(),
			ctime(time())));

		    seteuid(UID_ADVANCE);
		    ob->set_position(str);
		    ob->save_player();
		    seteuid(getuid());
		    message("info", sprintf("%s is now position %s", capitalize(nom),
			str), this_player());
		    message("info", sprintf("You have been xmoted to %s", str), ob);
		    return 1;
		}
		if(( (string)this_player()->query_position() != "god" ) &&
		  ( lev >= 1751)) {
		    seteuid(UID_LOG);
		    log_file("xmote", sprintf("%s attempted to raise %s to level %d  %s.\n", 
			(string)this_player()->query_name(),nom, lev,ctime(time())));
		    return 0;
		}
		if(( (string)this_player()->query_position() != "god" ||
		    (string)this_player()->query_position() != "arch" && (ob->query_level() >
		      lev))) return 0;
		seteuid(UID_LOG);
		log_file("xmote", sprintf("%s went to level %d thanks to %s on %s.\n",
		    nom, lev, (string)previous_object()->query_name(), ctime(time())));
		seteuid(getuid());
		ob->set_level(lev);
		fix_all_levels(ob,lev);
		message("info", sprintf("%s is now level %d.", capitalize(nom), lev),
		  this_player());
		message("info", sprintf("You have been xmoted to level %d.\n",lev),ob);
		return 1;
	    }
	    if(( (string)this_player()->query_position() != "god" ) &&
	      ( lev >= 1751) || (pos == "god")) {
		seteuid(UID_LOG);
		log_file("xmote", sprintf("%s attempted to raise %s to level %d and position %s  %s.\n", 
		    (string)previous_object()->query_name(),nom, lev,pos,ctime(time())));
		return 0;
	    }
	    if(( (string)this_player()->query_position() != "god" &&
		(string)this_player()->query_position() != "arch" && (ob->query_level() >
		  lev))) return 0;
	    seteuid(UID_LOG);
	    log_file("xmote", sprintf("%s went to position %s and level %d thanks to "
		"%s on %s.\n", nom, pos, lev, (string)previous_object()->query_name(),
		ctime(time())));
	    seteuid(getuid());
	    seteuid(UID_ADVANCE);
	    ob->set_position(pos);
	    seteuid(getuid());
	    ob->set_level(lev);
	    fix_all_levels(ob,lev);
	    message("info", sprintf("%s is now level %d and position %s.\n",
		capitalize(nom), lev, pos), this_player());
	    message("info", sprintf("You are now level %d %s.\n", lev, pos), ob);
	    return 1;
	}

	void help() {
	    message("help", "Syntax: <fixlevels [player] ([level]) ([position])>\n\n"
	      "Changes the level, position, or both of a player.", this_player());
	}
