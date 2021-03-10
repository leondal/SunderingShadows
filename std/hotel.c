#include <std.h>
inherit ROOM;

mapping bedrooms;
nosave string ob_file;
int bedcost;

int add_tenant(string tenant, string room);
int query_inn(){ return 1; }

void create(){
  string *temp;
    ::create();
	temp = explode(file_name(),"/");
	ob_file = "/tmp/hotel/"+geteuid()+temp[sizeof(temp)-2]+temp[sizeof(temp)-1];
}
void set_rooms(mapping room){
	int inc,temp,size;
	string *tmp;
	bedrooms = ([]);
	tmp = keys(room);
	for(inc = 0;inc < sizeof(tmp); inc ++){
		bedrooms[tmp[inc]] = ({"-- empty -- "});
		size = room[tmp[inc]];
		if(size > 5) size = 5;
	    for(temp = 1;temp <  size;temp++){
		bedrooms[tmp[inc]] += ({"-- empty -- "});
	    }
	}
}

void remove_tenant(string str){
    int inc,inc2;
    string *room;
	room = keys(bedrooms);
	for(inc = 0; inc < sizeof(room); inc ++){
	    for(inc2 = 0; inc2 < sizeof(bedrooms[room[inc]]); inc2++){
		if(bedrooms[room[inc]][inc2] == str){
		    bedrooms[room[inc]][inc2] = "-- empty -- ";
			TP->add_stuffed(50);
			TP->add_quenched(50);
			TP->add_hp(random(TP->query_level()));
			save_object(ob_file);
		    return;
		}
	    }
	}
}
int add_tenant(string tenant, string room){
	int inc,temp;
	temp = sizeof(bedrooms[room]);
	for(inc = 0;inc < temp;inc ++)
	    if(bedrooms[room][inc] == "-- empty -- "){
		bedrooms[room][inc] = tenant;
		save_object(ob_file);
		return temp;
	    }
	return 0;
}
remove(str){
	::remove(str);
	rm(ob_file+".o");
}
void set_cost(int cost){
	bedcost = 0;
	bedcost = cost*5;
}
int query_cost(){ return bedcost; }
void init(){
	::init();
	add_action("__Rent","rent");
	add_action("__Rooms","read");
	add_action("__Costs","cost");
	add_action("__Help","help");
	if(file_size(ob_file+".o") != -1);
//		restore_object(ob_file);
	else
		save_object(ob_file);
}

int __Rent(string str){
    int cost;
	if(!str) return notify_fail("Rent what?\n");
	if(member_array(str,keys(bedrooms))== -1)
		return notify_fail("That room doesn't exist!\n");
	cost = bedcost / (sizeof(bedrooms[str]));
	tell_object(TP,"%^BOLD%^%^CYAN%^So, "+TPQCN+", you want to rent a bed in the %^YELLOW%^"+str+"%^CYAN%^ room, eh?");
	tell_object(TP,"%^BOLD%^%^CYAN%^This bed will cost you "+cost+" gold to rent.");
	tell_object(TP,"%^BOLD%^%^CYAN%^Note: Renting a room, will log you out of ShadowGate.\n%^YELLOW%^Are you sure? %^WHITE%^< y / n >");
	input_to("get_yn",0,str);
	return 1;
}
get_yn(string str,string roomnum){
    int cost,temp;
	if(!str) {
		input_to("get_yn",roomnum);
		return;
	}
	if((str[0..0] != "y") && (str[0..0] != "n")) {
		input_to("get_yn",roomnum);
		return;
	}
	if(str[0..0] == "n") return;

	if(!temp = add_tenant((string)TPQN,roomnum)){
		tell_object(TP,"%^ORANGE%^Sorry, those beds are all taken.");
		return;
	}
	cost = (bedcost / temp);
	if((int)TP->query_money("gold") < cost){
		remove_tenant(TPQN);
		tell_object(TP,"%^YELLOW%^You seem to be short on gold.\nCome back when you have more gold.");
	} else{
		TP->add_money("gold",-cost);
		TP->quit();
	}
	return;
}

int __Rooms(){
	int inc,inc2;
	string *temp,melnmarn;
	tell_object(TP,"%^BOLD%^%^GREEN%^                             The Register");
	tell_object(TP,"%^BOLD%^%^BLACK%^-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-");
	tell_object(TP,       "%^YELLOW%^ Room Name     Bed #1      Bed #2      Bed #3      Bed #4      Bed #5");
	temp = keys(bedrooms);
	temp = sort_array(temp,"sort_em",TO);
	for(inc = 0;inc < sizeof(temp); inc ++){
		melnmarn = "%^BOLD%^%^CYAN%^"+sprintf("%-12s",capitalize(temp[inc]));
		for(inc2 = 0;inc2 < sizeof(bedrooms[temp[inc]]);inc2 ++){
			melnmarn += (bedrooms[temp[inc]][inc2] == "-- empty -- ") ? "%^BLUE%^" : "%^GREEN%^";
			melnmarn += capitalize(sprintf("%-12s",bedrooms[temp[inc]][inc2]));
		}
		for(inc2 = 0;inc2 < (5 - sizeof(bedrooms[temp[inc]]));inc2 ++)
			melnmarn += "%^BLACK%^----------- ";
		tell_object(TP,melnmarn);
	}
	tell_object(TP,"%^BOLD%^%^BLACK%^-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-");
	return 1;
}
int sort_em(string a,string b){
	if(sizeof(bedrooms[a]) > sizeof(bedrooms[b])) return 1;
	else if(sizeof(bedrooms[a]) == sizeof(bedrooms[b])) return 0;
	else return -1;
}
int __Help(string str){
    if((!str) || (str != "hotel")) return 0;
	write(
@HELP
%^YELLOW%^				Hotel Help
%^ORANGE%^Commands:
%^BOLD%^%^RED%^Read
%^GREEN%^  syntax:  read
%^CYAN%^	The read command will show a list of rooms with the occupants
	of the beds. You can RENT a bed in any room that has empty beds.

%^BOLD%^%^RED%^Rent
%^GREEN%^  syntax: rent <roomname>
%^CYAN%^	The rent command will allow you to rent a bed in the room
	<roomname>. This will Log you off of Shadowgate.

%^BOLD%^%^RED%^Cost
%^GREEN%^  syntax: cost
%^CYAN%^	This command will give you a price list for the beds in each
	room. The more beds in the room, the lower the price.
%^BOLD%^%^RED%^Help
%^GREEN%^  syntax:  help hotel
%^CYAN%^	Gets this screen...
HELP
);
return 1;
}

int __Costs(string str){
    int cost,inc;
    string *room;
	room = keys(bedrooms);
	room = sort_array(room,"sort_em",TO);
	tell_object(TP,"%^BOLD%^%^GREEN%^           Price List");
	tell_object(TP,"%^BOLD%^%^BLACK%^-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-");
	tell_object(TP,"%^YELLOW%^     Room Name       Bed Cost");
	for(inc = 0;inc < sizeof(room); inc ++){
	    cost = bedcost / (sizeof(bedrooms[room[inc]]));
	    tell_object(TP,sprintf("%%^BOLD%%^%%^CYAN%%^     %-12s %%^WHITE%%^%5d %%^CYAN%%^gold", capitalize(room[inc]),cost));
	}
	tell_object(TP,"%^BOLD%^%^BLACK%^-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-");
	return 1;
}
