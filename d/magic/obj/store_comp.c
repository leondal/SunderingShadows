//	A Material Component from a Store
//	Thorn@Shadowgate
//	10/11/94
//	General Wizard Class Items
//	store_comp.c
//      Modified a bit by Vashkar  12/6/95
// Patched to include all class components under a single inherit. N, 5/14.

#include <std.h>
#include <move.h>
inherit "/std/Object";

int quantity;

int is_component() { return 1; }

void create() {
    ::create();
    set_name("component");
    set_id(({"component"}));
    set_short("A Generic Store Component [If found, alert an immortal ASAP]");
    set_weight(1);
    set_value(0);
}

void init() {
    ::init();
    add_action("assimilate", "put");
	add_action("take_from", "take");
	add_action("join_with", "join");
}

int join_with(string str) {
	string cur_name, targ_name;
	int new_amt;
	object cur_comp, targ_comp;

	if(!str) return 0;
	if(sscanf(str, "%s with %s", cur_name, targ_name) != 2) return 0;
	if(!objectp(cur_comp = present(cur_name, ETO))) return 0;
	if(!objectp(targ_comp = present(targ_name, ETO))) return 0;
	if(cur_comp == targ_comp) return notify_fail("You are trying to join the same component with itself!\n");
	if(identify(cur_comp->query_id()) != identify(targ_comp->query_id())) return 0;
	if(identify(cur_comp->query_id()) == identify(targ_comp->query_id())) {
		new_amt = cur_comp->query_comp_quantity();
		new_amt += targ_comp->query_comp_quantity();
		targ_comp->set_comp_quantity(new_amt);
		write("Your combine the spell components into one bundle of "+new_amt+".");	
		cur_comp->remove();
		return 1;
	}
}

int take_from(string str){
	string comp_name;
	int comp_amt, amt, cur_quantity;
	object new_comp, cur_comp;

	if(!str)return 0;
	if(sscanf(str, "%d from %s", comp_amt, comp_name) != 2) return 0;
	if(!objectp(cur_comp = present(comp_name, ETO))) return 0;

	cur_quantity = cur_comp->query_comp_quantity();
	if(comp_amt > cur_quantity) return notify_fail("Sorry, there are only "+cur_quantity+" of the "+comp_name+ " to take!\n");

	amt = cur_quantity - comp_amt;
	if(amt < 1) return notify_fail("Sorry, you must leave at least 1 component in each bundle.\n");
	if(comp_amt < 0) return notify_fail("You cannot take less than 1 component!\n");

	cur_comp->set_comp_quantity(amt);
	new_comp = new("/d/magic/store_comp");

   	write("You divide your "+comp_name+" into two.  Leaving the original bundle with "+amt+" and creating a new bundle with "+comp_amt+".");

      new_comp->set_name(cur_comp->query_name());
	new_comp->set_id(cur_comp->query_id());
      new_comp->set_short(cur_comp->query_short());
      new_comp->set_comp_quantity(comp_amt);
      if( (int)(new_comp->move(ETO)) != MOVE_OK ) {
         	write("You dropped the component as you cannot carry anymore.");
         	new_comp->move(EETO);
      }
	return 1;
}

void set_comp_quantity(int i) 
{ 
   quantity = i; 
   set_long("     "+quantity+" "+query_name()+
"\n        This is a material component required for casting\n"
"        a certain spell.  To be able to cast the spell with\n"
"        this component you must:\n"
"        <put "+TO->query_name()+" into components bag>\n"
"        You may also:\n"
"	   <take [amt] from ["+TO->query_name()+"]>\n"
"        <join [component 1] with [component 2]>\n"
    );
}

int query_comp_quantity() { return quantity; }

int assimilate(string inputted) {
    object ob;
    string str, comp, bag, bagnum, theshort;
    int prev, after; 

    if(sscanf(inputted, "%s into %s", comp, bag) != 2) return 0;
    if(sscanf(bag+" |", "components bag %s", bagnum) != 1 && sscanf(bag+" |", "garment %s", bagnum) != 1) return 0;
    if(present(comp, TP) != TO) return 0;
    if(bagnum == "|") bagnum = "1";
    else bagnum = to_int(bagnum);

    ob = present("componenter "+bagnum, TP);
    if(!ob) {
        notify_fail("You aren't holding anything you can put components into!\n");
        return 0;
    }
    str = TO->query_name();
    theshort = ob->query_name();
    if(!ob->id("compx")) {
        write("You cannot store your "+str+" in "+theshort+"!");
        return 1;
    }
    prev = ob->query_comp(str);
    after = prev + quantity;
    write("You put "+str+" into your "+theshort+".\n");
    ob->set_comp(str, after);
    TO->remove();
    return 1;
}

void set_name(string str)
{
    ::set_name(str);
    set_long(
"\n        This is a material component required for casting"
"\n        a certain spell.  To be able to cast the spell with"
"\n        this component you must:"
"\n        <put "+TO->query_name()+" into components bag>\n"
    );
    return 1;
}