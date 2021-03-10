#include "std.h"
#include <daemons.h>

inherit MONSTER;
void create() {
    ::create();
        set_name("teller");
        set_id( ({ "teller"  }) );
        set("race", "human");
        set_gender("male");
        set("short", "teller");
        set("long", "This is the teller. He is waiting to help you with your vouchers.\n"
"<buy voucher> , <sell voucher>\n");
        set_level(6);
        set_body_type("human");
        set_class("fighter");
        set("aggressive", 0);
        set_alignment(3);
        set_size(2);
        set_stats("intelligence",6);
        set_stats("wisdom",4);
        set_stats("strength",13);
        set_stats("charisma",3);
        set_stats("dexterity",8);
        set_stats("constitution",7);
        set_max_mp(0);
        set_mp(query_max_mp());
        set_hd(15,1);
        set_max_hp(query_hp());
        set_max_sp(query_hp());
        set_sp(query_max_sp());
        add_money("silver",random(10));
        add_money("gold",random(5));
        add_money("copper",random(20));
}
void init(){
	::init();
	add_action("buy_vou","buy");
	add_action("sell_vou","sell");
 	add_action("process","give");
}
int buy_vou(string str){
	int money;
	if(str!="voucher") return 0;
 	money = TP->query_money("gold");
	if(money < 50 ){
		tell_room(ETO, "He says, you haven't enough gold, 50 gp.");
		return 1;
}
	else{
	TP->add_money("gold",-50);
	tell_room(ETO,"He says that the cost is 50 gp.");
	tell_room(ETO,"He takes the money from "+TPQCN+".",TP);
	write("He takes your money.");
	tell_room(ETO,"He hands a piece of paper to "+TPQCN+".",TP);
	write("He hands you the voucher.");
	new("/d/tharis/obj/voucher.c")->move(TP);
	return 1;
}
}
int sell_vou(string str){
	object ob;
	int worth;
	if(str!="voucher") return 0;
 	tell_room(ETO,"He says Please give me the voucher.");
return 1;
}
int process(string str){
int worth;
object ob;
if(str!="voucher to teller") return 0;
  if(ob = present("voucher",TP)){  
 	worth = random(100);
		tell_room(ETO,"He says yes yes.");
		tell_room(ETO,"He takes the voucher and goes into the office.");
		tell_room(ETO,"He quickly returns and hands "+TPQCN+" the money.",TP);
		write("He hands you the money.");
      tell_room(ETO, "He announces that the voucher was worth "+worth+" gold.");
		TP->add_money("gold",worth);
     ob->remove();
   return 1;
   }
return 0;
}

void reset(){
 	object ob;
 	::reset();
      if(ob = present("voucher",TO)) ob->remove();
}
