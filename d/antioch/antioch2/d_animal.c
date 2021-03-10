#include <std.h>
inherit WEAPONLESS;

string myname="";
string orig_short;
object owner;
string enter_room, exit_room;

void set_enter_room(string str);
void set_exit_room(string str);

void movement(object tp)
{
	TO->move(environment(tp));
}

void create()
{
	::create();
}

void init()
{
	::init();
	add_action("give_me_away","give");
	add_action("get_off","quit");
	add_action("rangers","handle");
	add_action("rename","name");
}

void set_enter_room(string str) {enter_room = str;}
void set_exit_room(string str) {exit_room = str;}

object query_owner() {return owner;}

int is_animal() {return 1;}

int set_owner(object new_owner)
{
	owner = new_owner;
	add_id(owner->query_name()+"'s "+query_name());
	return 1;
}

void set_short(string str)
{
	orig_short = str;
	::set_short(str);
}

string query_short()
{
	string hold;

	if(myname != "")
		hold = capitalize(myname);
	else
		hold = ::query_short();
}

int give_me_away(string str)
{
	string what, who;
	object new_owner;

	if(sscanf(str,"%s to %s",what,who) != 2) {
		notify_fail("Give what to who?\n");
		return 0;
	}
	if(!id(what)) return 0;
	if(owner != TP) {
		notify_fail("You can't give away an animal that you don't"+
		" own!\n");
		return 0;
	}
	new_owner = present(who);
	if(!new_owner) {
		notify_fail("That person is not here!\n");
		return 0;
	}
	if(!set_owner(new_owner)) {
		write(new_owner->query_cap_name()+" is unable to accept your gift.");
		tell_object(new_owner,""+TP->query_cap_name()+" tries to give"+
		" "+TP->query_possessive()+" "+orig_short+" to you.\n");
		return 0;
	}
	else {
		write("You give the "+orig_short+" to "+new_owner->query_cap_name()+".");
		TP->remove_pet(TO);
		new_owner->add_pet(TO);
		tell_object(new_owner,""+TP->query_cap_name()+" gives you"+
		" "+TP->query_possessive()+" "+orig_short+".\n");
		return 1;
	}
}

int rangers(string str)
{
	if(!TP->is_class("ranger")) {
		notify_fail("You can't do that!\n");
		return 0;
	}
	if(!present(str,ETP)) {
		notify_fail("There is no "+str+" here.");
		return 0;
	}
	if(owner) {
		if(TP->query_name() != owner->query_name()) {
			if(present((string)owner->query_name(), ETO)) {
				notify_fail("You may not want to do that with the"+
				" owner around.\n");
				return 0;
			}
		}
	}
	TO->set_owner(TP);
	TP->add_pet(TO);
	write("%^GREEN%^You hand the "+TO->query_cap_name()+" a small"+
	" bit of food and speak warm words to "+TO->query_objective()+"."+
	" "+TO->query_subjective()+" seems to like you.");
	return 1;
}

int rename(string str)
{
	string myid, newname, *orig_ids;
	int num;

	if(!str) {
		notify_fail("Name what?\n");
		return 0;
	}
	if(sscanf(str,"%s %d %s", myid, num, newname) == 3) {
		myid = myid+" "+num;
	}
	else
		if(sscanf(str,"%s %s",myid, newname) != 2) return 0;
	if(!present(myid,ETO) == TO) return 0;
	if(TP != owner) {
		notify_fail("You can only name your own pets.\n");
		return 0;
	}
	orig_ids = query_id();
	if(myname != "") {
		orig_ids = orig_ids - ({capitalize(myname)});
		orig_ids = orig_ids - ({lower_case(myname)});
	}
	TO->set_id(orig_ids);
	TO->add_id(lower_case(newname));
	TO->add_id(capitalize(newname));
	myname = newname;
	return 1;
}
