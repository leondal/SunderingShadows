//modified HEAVILY to allow for players to pay for multiple people in the room with them/ 
//sneaking around the toll/lifting it yourself when the guard is killed/just walking 
//around it if the guard isn't there.... people have to pay per person and it'll only give
//them a certain amount of time to get through without having to pay it again.  Last change
//was 10/19/01 - Saide 11/10/03
#include <std.h>
#include "/d/dagger/road/short.h"
inherit ROOM;
string *payed;

query_payed() {
	return payed;
}

int check_payed(string str) {
	int x, i;
	for(x = 0;x < sizeof(payed);x++) {
		if(payed[x] == str) {
			i = 1;
		}
	}
	return i;
}

void clear_payed() {
	payed = ({});
}

void add_payed(string str) {
	payed += ({str});
}

void remove_payed(string str) {
	payed -= ({str});
}

void create()
{
    ::create();
    set_terrain(VILLAGE);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("Outside the Tollbooth.");
	set_long("%^CYAN%^You are standing near the %^RED%^tollbooth%^CYAN%^ to the Dagger Reaches.  "+
    "It is of obvious gnomish design, but has fallen into disrepair.  The %^RED%^tollbooth "+
    "%^CYAN%^rest on the east side of the %^RED%^road%^CYAN%^ and the entrance to it is an "+
    "%^BLUE%^open doorway%^CYAN%^, approximately the size which would a allow a human or "+
    "smaller creature comfortable access.  A %^MAGENTA%^wood pole%^CYAN%^ stretches across "+
    "part of the road, extending out from the %^RED%^tollbooth%^CYAN%^, you think that you "+
    "could easily lift it if something was not preventing you from doing so.  You could "+
    "probably even sneak around it without being noticed if you were careful enough.  A "+
    "%^RED%^sign%^CYAN%^ has been planted in the ground near the %^RED%^tollbooth%^CYAN%^"+
    ", you feel like you should probably read it.%^RESET%^\n");
//updated smell and sound once the tollbooth was destroyed ~Circe~ 4/1/08			
//    set_smell("default", "%^BOLD%^%^GREEN%^You can smell the scent of dirty socks.");
//    set_listen("default", "%^YELLOW%^You can hear a guy snoring loudly inside the tollbooth.");
    set_smell("default","A charred smell of death lingers in the air here.");
    set_listen("default","Faint sounds of travel along the road reach your ears.");

    set_items(([
    ({"doorway","door","open door","open doorway"}) : "This open doorway leads into the "+
    "tollbooth, it is big enough to allow a human or smaller creature to enter comfortably.",
    "road" : "Looks rather dusty and rarely used. Kinda makes you wonder what the heck your doing here.",
    "sea" : "You can see the surf over 50 feet below you over the cliffs to the east.",
    "cliffs" : "They are formed from granite and worn deep by the action of the surf.",
    ({"wood pole","wooden pole","pole"}) : "This wood pole extends out from the tollbooth, in "+
    "an attempt to block access to the road.  It was obviously a feeble attempt as it only "+
    "extends half way across the road and you could easily lift it if something wasn't nearby "+
    "to stop you or you could probably even sneak around it.",
    "sign" : "It is made of a thick oak, that has been planted into the ground near the "+
    "tollbooth.  An inscription has been burned into it, you should probably try to read it.",
    "tollbooth" : "This building is big enough for probably half a dozen humans to fit in "+
    "comfortably.  The outside is in poor condition and the open doorway which leads into it "+
    "does little to tell you of its internal condition.",
    ]));
    payed = ({ });
}

void reset(){
    ::reset();
    clear_payed();	
}

void init()
{
    ::init();
    add_action("readsign","read");
    add_action("pay","pay");
    add_action("lift","lift");
}

int readsign(string str)
{
    if ((str=="sign")) {
        write("%^BOLD%^You are passing into the Dagger Reaches, now under the governage of the Duke "+
        "of Tonovi.  To pay for our glorious leaders works, you will be expected to pay a toll of "+
        "20 gold to pass, if you desire, you may pay for more than one person, but understand that "+
        "our guards will use their own discretion as to who they'll let pass.  You'll have a "+
        "limited amount of time to get through, so don't take all day.");
        return 1;
    }
    return 0;
}

//new pre_exit_function() for going northeast - permits invis people and people who have 
//payed or mobs to go through

int go_through_toll() {
    object ob;
    if(check_payed((string)TPQN) == 1 || !interactive(TP)) {
        return 1;
    }
    if(ob = present("human guard") || ob = present("half-elven tollbooth guard")) {
        if(!TP->query_invis()) {    
            ob->force_me("speech growl");
		    ob->force_me("emoteat "+TPQN+" glares at $N");
		    ob->force_me("say you need to pay the toll!");
            return 0;
        }
 	    if(TP->query_invis()) {
            tell_object(TP,"You sneak around the pole.");
            return 1;
        }
    }
    return 1;
}

//This is function that's called when a player pays for more than one person - or gives
//the guard more than 20 gold - doesn't exactly mean that more than one player will be
//able to get through - but that the guard will pocket more gold :-) - Saide

int do_multiple_pass(object who,int amount,object paid_person) {
    int how_many,x, i, temp_amount,y;
    string how_many_string;
    object *people;
    if(who = present("human guard") || who = present("half-elven tollbooth guard")) {
        who->force_me("speech say");
        temp_amount = amount - 20;
        for(i = 0;i < temp_amount;i++) {
	        if(temp_amount - 20 >= 0) {
            temp_amount = temp_amount - 20;
            how_many++;
            continue;
            }
            break;
        }
        if(how_many >= 2) {
            how_many_string = how_many +" other people that are here now pass.";
        }
        if(how_many == 1) {
            how_many_string = "one other person here now pass.";
        }
		if(how_many >= 1) {
            who->force_me("say okay I'll let "+how_many_string+"  Get through quickly or you're paying "+
            "again.");	
		}

        if(check_payed((string)paid_person->query_name()) != 1) {
            add_payed((string)paid_person->query_name());
            call_out("remove_payed",30,(string)paid_person->query_name());
        }
        tell_object(paid_person,"The guard motions for you to pass.");
        amount -= 20;
        people = all_living(environment(paid_person));
        people -= ({paid_person});
        for(x = 0;x < sizeof(people);x++) {
            if(!interactive(people[x])) continue;
            if(!check_payed((string)people[x]->query_name())) {
                if(people[x]->query_invis()) continue;
                if(amount - 20 >= 0) {
                    tell_object(people[x],"The guard motions for you to pass.");
                    add_payed((string)people[x]->query_name());
                    call_out("remove_payed",30,(string)people[x]->query_name());
                    y++;
                    continue;
                }
            break;
            }
	    }
        if(how_many > y) {
            who->force_me("smirk");
            who->force_me("laugh "+paid_person->query_name());
            if(y == 0) {
                how_many_string = "no other people";
            }
            else { 
                how_many_string = "only "+y+" people";
            }
            who->force_me("say well, there's "+how_many_string+" here "+
            "but since you've payed, for "+(how_many-y)+" more than "+
            "that, you can pretend they go through and I'll keep "+
            "the gold.");
        }
    }
}

//The function that is called when a player or the guard lifts the toll - so I could 
//tell who payed the guard and who lifted the toll - Saide

int lift_toll(object who,object let_pass) {
    if(who = present("human guard") || who = present("half-elven tollbooth guard")) {
        who->force_me("speech say");
        who->force_me("say get through the toll quickly or you're gonna pay again.");
        tell_room(environment(who),"The guard lifts the pole and motions for "+
        let_pass->query_cap_name() +" to pass.",who);
        if(!check_payed((string)let_pass->query_name())) {
            add_payed((string)let_pass->query_name());
            call_out("remove_payed",30,(string)TPQN);
        }
        tell_object(who,"The guard lifts the pole and motions for you to pass.");
        return 1;
	}
    tell_object(who,"You lift the pole.\n");
    tell_room(TO,let_pass->query_cap_name() + " lifts the pole.\n",let_pass);
    return 1;
}

//This function was modified to let the player pay for more than one person - 
//randomly chooses the ones that the guard will let pass from the visible people in 
//the room.  

int pay(string str){
    object ob;
    int amount;
    string coin;
    if(!str) {
        tell_object(TP,"Try pay 20 gold - or pay 20 gold per person if you want the guard "+
        "to let more than one person through.");
        return 1;
    }

    if(sscanf(str,"%d %s",amount,coin) == 2) {
        if(coin == "gold") {
            if(ob = present("human guard") || ob = present("half-elven tollbooth guard")) {
                if(!TP->query_funds("gold",amount)) {
                    tell_object(TP,"You haven't the money!");
                    return 1;
                }
                if(amount < 20) {
                    tell_object(TP,"It'll cost you 20 gold pieces per person.");
                    return 1;
                }
                TP->use_funds("gold",amount);
                tell_object(TP,"You hand the guard "+amount+" gold pieces.");
                tell_room(ETP,TPQCN+" hands some gold to the guard.",TP);
                if(amount > 19 && amount < 40) {
                    call_out("lift_toll",0,ob,TP);
                }
                if(amount >= 40) {
                    call_out("do_multiple_pass",0,ob,amount,TP);
                }
                return 1;
            }
            tell_object(TP,"The guard is not here you could lift the pole yourself!");
            return 1;
        }
	}
    tell_object(TP,"Try pay 20 gold - or pay 20 gold per person if you want the guard "+
    "to let more than one person through.");
    return 1;  
}

//function was added to let players lift the toll if the guard was not in the area 
//this is NOT needed to get around the toll - it's assumed that they just walk around it 
//if the guard isn't there to watch them and make them pay OR if the guard doesn't know 
//they are there, then, well, he can't make them pay - Saide 

int lift(string str) {
    object ob;
    if(!str) {
        write("Lift the toll?");
        return 1;
    }
    if((str == "toll") || (str == "pole")) {
        if(ob = present("human guard") || ob = present("half-elven tollbooth guard")) {
            ob->force_me("speech snarl");
            ob->force_me("emoteat "+TPQN+" growls at $N");
            ob->force_me("say don't even think about it, it'll cost you 20 gold pieces.");
            return 1;
        }
    }
    call_out("lift_toll",0,TP,TP);
    return 1;
}
