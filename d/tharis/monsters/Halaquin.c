// /d/tharis/mon/Halaquin.c   // 

#include "/d/common/common.h"
#include "std.h"

inherit MONSTER;
string name;

void create() {
    ::create();
        set_name("Halaquin");
        set_id(({"Halaquin","recruiter","halaquin"}));
        set_race("human");
        set_gender("male");
        set_short("Halaquin, a recruiter in Tharis");
        set_long(
                "This is Halaquin. He is a recruiter for the city of Tharis.");
        set_level(15);
        enable_commands();
        set_body_type("human");
        set("aggressive",0);
        set_alignment(2);
        set_size(2);
        set_stats("intelligence",13);
        set_stats("wisdom",9);
        set_stats("strength",18);
        set_stats("charisma",9);
        set_stats("dexterity",17);
        set_stats("constitution",17);
        set_max_mp(0);
        set_mp(query_max_mp());
        set_hd(15, 5);
        set_class("fighter");
        set_max_hp(query_hp());
        set_max_sp(query_hp());
        set_sp(query_max_sp());
        set_wielding_limbs( ({ "right hand", "left hand" }) );
        new(CWEAP"longsword.c")->move(TO);
        command("wield sword in right hand");
        new(CARMOR"chain.c")->move(TO);
        command("wear armor");
	new("/d/tharis/obj/notice.c")->move(TO);
        add_money("gold",random(50));
        add_money("silver",random(10));
        add_money("copper",random(20));
   }
void init(){
	::init();
		add_action("catch_name","say");
	}
int catch_name(string str){
	name = TPQCN;
	tell_room(ETP,TPQCN+" says "+str,TP);
	write("You say "+str);
	if((strsrch(str,"greetings")!=-1)  ||  (strsrch(str,"hello")!=-1) ||(strsrch(str,"excuse")!=-1)){
	tell_room(ETO,"Halaquin says: Yes, yes you want adventure.",TO);
	tell_room(ETO,"I need your names",TO);
	}
	
	else{
	
	if(str == name){	
		tell_room(ETO,"Good, good. ",TO);
		tell_room(ETO,name+" is an excellent name.",TO);
		tell_room(ETO,"He writes something into a book.",TO);
		write("He gives you a notice.");
		tell_room(ETO,"He hands "+TPQCN+" a notice",TP,TO);
          command("give notice to "+TPQN);
		tell_room(ETO,"He says:  Take this to the security building",TO);
		write("and he pushes you out");
	TP->move("/d/tharis/Tharis/street1.c");
	}	
else    tell_room(ETO, "I need your name. No fooling around rookie.",TO); 
}
	
}
