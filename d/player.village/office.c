#include "pvillage.h"
inherit ROOM;

void door(string str);
void item(string str);

void create(){
    ::create();
	set_property("light",2);
	set_property("indoors",1);
	set_short("The Player Village Housing Office");
	set_long(
		"The Player Village Housing Office\n"
		"There is a sign hanging against the wall.\n"
		"You see a huge book placed on the desk.\n"
	);
	set_exits(([
		"south":VILLAGE+"nroad1.c"
	]));

}

void init(){
    ::init();
	add_action("buy","buy");
	add_action("modify","modify");
	add_action("read","read");
}

void reset(){
	::reset();
	if(!present("book"))
		new(MAIN+"housebook")->move(MAIN+"office");

}

int buy(string str) {
    object obj;
	if (!(str == "house" || str == "item" || str == "door")) 
		return notify_fail("Buy what??\n");
	if (present("architect") || present("doormaker") || present("toymaker")) 
		return notify_fail("You have to wait, someone is just getting help with his/hers house.\n"); 
	if (file_size(VILLAGE+TPQN+".c") != -1){
		if (str == "item" ) return item(str);
		if (str == "door") return door(str);
		return notify_fail("You already have a house!\n");
	}
	if (str != "house") return notify_fail("You need a house before you can get items.\n");
	tell_object(TP,"The salesman tells you: So you want to buy a house, do you.");
	tell_object(TP,"The salesman tells you: Please show our architect, where you want your house.");
	obj = new(MAIN+"architect");
	obj->set_player(this_player());
	obj->move(this_object());
	obj->start_heart();
	tell_room(this_object(),"An architect arrives.");
	tell_object(this_player(),"The salesman tells you: He is a litle stupid, so he just follow certain commands.\n"+"He gives you a note.");
	new(MAIN+"housenote")->move(TP);
	return 1;
}

int modify(string str) {
	object obj;
	if (str != "house") return notify_fail("Try 'modify house'!!\n");
	if (file_size(VILLAGE+TPQN+".c") == -1){
		return notify_fail("You don't have a house!\n");
	}
	if (present("architect") || present("doormaker") || present("toymaker"))
		return notify_fail("You have to wait, someone is just getting help with his/hers house.\n"); 
	if (file_size(VILLAGE+TPQN+".c") == -1) return notify_fail("You don't have a house.\n"); 
	tell_object(TP,"The salesman tells you: So you want to modify your house, do you.");
	tell_object(TP,"The salesman tells you: Please show our architect, what you want to modify.");
	obj = new(MAIN+"architect");
	obj->set_player(this_player());
	obj->move(this_object());
	obj->start_heart();
	tell_room(this_object(),"An architect arrives.");
	tell_object(this_player(),"The salesman tells you: He is a litle stupid, so he just follow certain commands.\n"+"He gives you a note.");
	if(!present("housenote",TP))
		new(MAIN+"housenote")->move(TP);
	return 1;
}

void door(string str){
    object obj;

	tell_object(TP,"The salesman tells you: So you want to buy some doors, do you.");
	tell_object(TP,"The salesman tells you: Please show our doormaker, where you want your doors.");
	obj = new(MAIN+"doorwizard");
	obj->set_player(this_player());
	obj->move(this_object());
	obj->start_heart();
	tell_room(this_object(),"A Door Wizard arrives.");
	tell_object(this_player(),"The salesman tells you: He is a litle stupid, so he just follow certain commands.\n"+"He gives you a note.");
	if(!present("doornote",TP))
		new(MAIN+"doornote")->move(TP);
	return 1;
}
void item(string str){
    object obj;

	tell_object(TP,"The salesman tells you: So you want to buy some items, do you.\n");
	tell_object(TP,"The salesman tells you: Please show our doormaker, where you want your items.");
	obj = new(MAIN+"itemwizard");
	obj->set_player(this_player());
	obj->move(this_object());
	obj->start_heart();
	tell_room(this_object(),"An Item Wizard arrives.");
	tell_object(this_player(),"The salesman tells you: He is a litle stupid, so he just follow certain commands.\n"+"He gives you a note.");
	if(!present("itemnote",TP))
		new(MAIN+"itemnote")->move(TP);
	return 1;
}

int read(string str){
	if(str != "sign") return notify_fail("Read what??\n");

	write("\n\n\n%^YELLOW%^Welcome, here you can buy or modify a house or buy items to add to it.");
	write("%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^");	
	write("\n%^CYAN%^ House           %^WHITE%^(%^GREEN%^Costs %^YELLOW%^"+HOUSECOST+" %^RESET%^%^GREEN%^gold%^WHITE%^)");
	write("%^MAGENTA%^         You get to own your own house in the playervillage.");
	write("\n%^CYAN%^ Item            %^WHITE%^(%^GREEN%^Costs %^YELLOW%^"+ITEMCOST+" %^RESET%^%^GREEN%^gold%^WHITE%^)");
	write("%^MAGENTA%^         You can buy an item with no extra features.");
	write("\n%^CYAN%^ Door            %^WHITE%^(%^GREEN%^Costs %^YELLOW%^"+DOORCOST+" %^RESET%^%^GREEN%^gold%^WHITE%^)");
	write("%^MAGENTA%^         You can buy a door to place somewhere in your house.");
	write("\n%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^");	
	write("\n%^YELLOW%^To buy any of type: buy <what you want>");
	write("\n%^CYAN%^You can also modify your house(adding rooms, changing room descriptions \netc. by typing: modify house (costs can be varying).\n");
	return 1;
}







