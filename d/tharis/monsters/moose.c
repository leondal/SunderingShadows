#include "std.h"

inherit VENDOR;

int count;

void create() {
   ::create();
   count = 0;
   set_name("Moose");
   set_id( ({ "Moose", "moose", "clerk", "shop keeper", "shopkeeper"}) );
   set_short("Moose,  the mighty seller of weapons.");
   set("aggressive", 0);
   set_level(19);
   set_long("He buys and sells weapons.\n"+
        "<help shop> will get you a list of shop commands.\n"
         "He wonders about the bet.\n"
         "<agree> to bet.");
   set_gender("male");
   set_alignment(4);
   set_race("human");
   add_money("gold", random(500));
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(19,3);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
   set_storage_room("/d/tharis/Tharis/storage/weapon_storage");
   set_items_allowed("weapon");
  set_exp(10);
   remove_std_db();
}
 void init(){
	::init();
	add_action("bet_time","agree");
}
int bet_time(){
	int str;
	int cash;
if(count!=1){
		tell_room(ETO, "'Good, good,' he laughs",TO);
		tell_room(ETO,"He hands the great bow to "+TPQCN,TP);
		write("He hands the great bow to you");
		tell_room(ETO,TPQCN+" starts attempting to draw the bow.",TP);
		write("You start your attempt.");
		str = TP->query_stats("strength");
		if(str >16){
			tell_room(ETO,TPQCN+" starts to slowly draw back the bow.",TP);
			write("You slowly start to draw back the bow.");
			tell_room(ETO,"Moose cheers enthusiastically, 'you got it kid, you got it.",TO);
         tell_room(ETO,TPQCN+" draws the bow string back to "+possessive(TPQCN)+" ear",TP);
			write("You pull the string back to your ear.");
         tell_room(ETO,"'You did it, I don't believe it, You did it");
         tell_room(ETO,"'Well here now, we had a bet didn't we?'");
			tell_room(ETO,"Moose hands the sword to "+TPQCN,TP);
			write("He hands you the sword.");
         new("/d/tharis/obj/psword.c")->move(TP);
			count = 1;
			tell_room(ETO,"'Now what can I get for youns.");
			return 1;	
		} else {
			cash = TP->query_money("gold");
			tell_room(ETO,TPQCN+" struggles at the bow.",TP);
			write("You struggle with the bow");
			tell_room(ETO,"Despite all the efforts, it would not bend.");
			tell_room(ETO,"You'd better stop before you hurt yourself there.");
			tell_room(ETO,"He takes the bow from "+TPQCN,TP);
			write("He takes the bow from you.");
         tell_room(ETO,"Sorry there lad.");
			tell_room(ETO,"He takes the money from "+TPQCN,TP);
	   	write("Moose takes the money from you");
         TP->add_money("gold",(-cash));
         tell_room(ETO,"Now what can I do for you young uns?");
			return 1;
	}
} else {
tell_room(ETO,"Sorry, I can't agree to the bet cause I already gived it away.");
}
return 1;
}
