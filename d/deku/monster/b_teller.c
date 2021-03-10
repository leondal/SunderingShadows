#include "/d/shadow/mon/melnmarn.h";
#include <daemons.h>
inherit MONSTER;
void create() {
    ::create();
   set_name("teller");
   set_id( ({ "teller"  }) );
   set_race("human");
   set_gender("male");
   set_short("Bank Teller");
   set_long("This is the teller. He is waiting to help you with your vouchers.\n"
   "<buy voucher> , <sell voucher>\n");
			set_class("fighter");
   set_mlevel("fighter",6);
			set_guild_level("fighter",6);
   set_body_type("human");
   set("aggressive", 0);
   set_alignment(3);
   set_size(2);
   set_stats("intelligence",16);
   set_stats("wisdom",4);
   set_stats("strength",13);
   set_stats("charisma",15);
   set_stats("dexterity",8);
   set_stats("constitution",7);
   set_max_hp(query_hp());
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
             tell_room(environment(TO), "He says: You haven't enough gold. It's 50 gold pieces.");
		return 1;
}
	else{
	TP->add_money("gold",-50);
     tell_room(environment(TO),"He says: The cost is 50 gp.");
	tell_room(environment(TO),"He takes the money from "+TPQCN+".",TP);
	write("He takes your money.");
	tell_room(environment(TO),"He hands a piece of paper to "+TPQCN+".",TP);
	write("He hands you the voucher.");
	new("/d/tharis/obj/voucher.c")->move(TP);
	return 1;
}
}
int sell_vou(string str){
	object ob;
	int worth;
	if(str!="voucher") return 0;
     tell_room(environment(TO),"He says: Please give me the voucher.");
return 1;
}
int process(string str){
int worth;
object ob;
if(str!="voucher to teller") return 0;
  if(ob = present("voucher",TP)){  
 	worth = random(91) + 10;
             tell_room(environment(TO),"He says: Yes, yes...");
		tell_room(environment(TO),"He takes the voucher and goes into the
office.");
		tell_room(environment(TO),"He quickly returns and hands "+TPQCN+"
the money.",TP);
		write("He hands you the money.");
          tell_room(environment(TO), "He announces that the voucher was worth "+worth+" gold.");
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
