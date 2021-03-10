#include "Pepitom.h"
inherit "/std/vendor";

void have_drink();
void goto_bar();
void goto_work();
void go_home();
int at_shop();

int count;
int drink;

void create() {
   ::create();
   set_name("Stella");
   set_id( ({ "stella", "clerk", "shop keeper", "shopkeeper"}) );
   set_short("Stella, the clerk of Pepitom's Weapon Store.");
   set("aggressive", 0);
   set_level(19);
   set_long("She buys and sells weapons.\n"+
	"<help shop> will get you a list of shop commands.\n");
   set_gender("female");
   set_alignment(2);
   set("race", "human");
   add_money("silver", random(500));
   set_body_type("human");
   set_storage_room(ROOMS+"weapon_storage");
   set_property("no attack", 1);
   set_hd(19,3);
   set_exp(10);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
   set_items_allowed("weapon");
   count = 0;

}

int test_heart(){ return 1;}

void heart_beat(){

	::heart_beat();

   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
if((hour(time()) >= 17) && (hour(time()) <= 18) && (base_name(ETO) != ROOMS+"bar")) {
	goto_bar();
	
   }
if((hour(time()) >= 19) || (hour(time()) <= 5) && (base_name(ETO) != ROOMS+"weaponhome")) {
	go_home();
   }
if((hour(time()) >= 6) && (hour(time()) <=16) && (base_name(ETO) != ROOMS+"weapon")) {
goto_work();
   }
if((hour(time()) >= 17) && (hour(time()) <= 18) && (base_name(ETO) == ROOMS+"bar")) {
have_drink();
}
}
void have_drink(){
	if (drink < 30 ){
		drink++;
		return;
	}
	force_me("buy ale");
	force_me("drink ale");
	drink = 0;
}
void goto_bar(){
	string thisroom;
	if (count <5 ){
		count++;
		return;
	}

	thisroom = base_name(ETO);
	switch (thisroom){
		case ROOMS+"weapon":
			say("Sorry folks, Shop is CLOSED.");
			force_me("wave");	
			force_me("east");
			count = 0;
			break;
		case ROOMS+"wroad11":
			force_me("south");
			count = 0;
			break;
		case ROOMS+"wroad10":
			force_me("east");
			count = 0;
			break;
		case ROOMS+"wroad09":
			force_me("east");
			count = 0;
			break;
		case ROOMS+"wroad08":
			force_me("east");
			count = 0;
			break;
		case ROOMS+"wroad07":
			force_me("east");
			count = 0;
			break;
		case ROOMS+"wroad06":
			force_me("east");
			count = 0;
			break;
		case ROOMS+"wroad05":
			force_me("north");
			count = 0;
			break;
		default:
			move(ROOMS+"bar.c");
			count = 0;
			break;
		}


}

void go_home(){
	string thisroom;
	if (count <5 ){
		count++;
		return;
	}

	thisroom = base_name(ETO);
	switch (thisroom){
		case ROOMS+"weapon":
			say("Bye folks, It is my bed time.");
			force_me("wave");	
			force_me("south");
			count = 0;
			break;
		case ROOMS+"wroad05":
			force_me("west");
			count = 0;
			break;
		case ROOMS+"wroad06":
			force_me("west");
			count = 0;
			break;
		case ROOMS+"wroad07":
			force_me("west");
			count = 0;
			break;
		case ROOMS+"wroad08":
			force_me("west");
			count = 0;
			break;
		case ROOMS+"wroad09":
			force_me("west");
			count = 0;
			break;
		case ROOMS+"wroad10":
			force_me("north");
			count = 0;
			break;
		case ROOMS+"wroad11":
			force_me("north");
			count = 0;
			break;
		case ROOMS+"wroad12":
			force_me("north");
			count = 0;
			break;
		case ROOMS+"wroad13":
			force_me("east");
			count = 0;
			break;
		default:
			move(ROOMS+"weaponhome.c");
			count = 0;
			break;
		}
}
void goto_work(){
	string thisroom;
	if (count <5 ){
		count++;
		return;
	}

	thisroom = base_name(ETO);
	switch (thisroom){
		case ROOMS+"weaponhome":
			say("Sorry folks, I must go to work.");
			force_me("wave");	
			force_me("west");
			count = 0;
			break;
		case ROOMS+"wroad13":
			force_me("south");
			count = 0;
			break;
		case ROOMS+"wroad12":
			force_me("south");
			count = 0;
			break;
		case ROOMS+"wroad11":
			force_me("west");
			count = 0;
			break;
		default:
			move(ROOMS+"weapon.c");
			count = 0;
			break;
		}

}

__List(str){
        if(!at_shop()) return 1;
        return ::__List(str);   
}
__Buy(str){
        if(!at_shop()) return 1;
        return ::__Buy(str);    
}
__Sell(str){
        if(!at_shop()) return 1;
	  return ::__Sell(str);   
}
__Show(str){
        if(!at_shop()) return 1;
        return ::__Show(str);   
}
__Value(str){
        if(!at_shop()) return 1;
        return ::__Value(str);  
}
int at_shop(){
        if(base_name(ETO) != ROOMS+"weapon"){
                command("say Come see me in my shop!!\n");
                return 0;
        }
        return 1;
}


