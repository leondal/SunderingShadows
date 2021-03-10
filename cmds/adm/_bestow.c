//	Bestow Command (Allows Admins to give out new magic books
//	or Components Bags in case users need to be reinbursed for
//	a bug.)
//	Thorn@Shadowgate
//	12/7/94
//	Admin Commands
//	_bestow.c

#include <security.h>
#include <std.h>

string player_name;

int bestow_book(string str) {
	object ob, book;
	seteuid(getuid());
	ob=find_player(str);
	book=new("/d/magic/magic_book");
	if(present("bookx", ob)) {
		write("This player already has a spellbook!\n");
		return 0;
	}
	book->seteuid(getuid());
	book->set_book_id(str);
	book->move(ob);
	write("You bestow a spellbook on "+str+".\n");
	seteuid(UID_LOG);
	write_file("/log/magic/adm", TPQCN+" bestowed a spellbook on "+ob->query_cap_name()+" at "+ctime(time())+".\n");
	seteuid(getuid());
	return 1;
}

int bestow_bag(string str) {
	object ob, bag;
	seteuid(getuid());
	ob=find_player(str);
	bag=new("/d/magic/comp_bag");
	if(present("compx", ob)) {
		write("This player already has a components bag!\n");
		return 0;
	}
	bag->seteuid(getuid());
	bag->set_comp_id(str);
	bag->move(ob);
	write("You bestow a components bag on "+str+".\n");
	seteuid(UID_LOG);
	write_file("/log/magic/adm", TPQCN+" bestowed a comp bag on "+ob->query_cap_name()+" at "+ctime(time())+".\n");
	seteuid(getuid());
	return 1;
}

int cmd_bestow(string str) {
	string who, what;
	if(!archp(this_player())) return 0;
	if(!str) {
		notify_fail("Bestow what on who?\n");
		return 0;
	}
	if(sscanf(str, "%s on %s", what, who) != 2) return 0;
	if(!find_player(who)) {
		notify_fail("Can't find '"+who+"'.\n");
		return 0;
	}
	if(what == "book") { 
		bestow_book(who);
		return 1;
	}
	if(what == "bag") {
		bestow_bag(who);
		return 1;
	}
	notify_fail("You can only bestow a book or a bag on a player.\n");
	return 0;
}
	
void help() {
	write(
@BESTOW
	
Usage: bestow bag/book on <playername>
	
	Use this command to place a spellbook or a components bag
on a user.  This command should only be used by an admin when
a user needs a new bag or book due to a bug or other such
occurences.  If there are problems with such items, contact
the Master of Wizards or a magic coder.

BESTOW
	);
}
		
