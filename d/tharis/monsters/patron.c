// /d/tharis/mon/patron.c   // 

#include "std.h"

inherit MONSTER;

int flag;

void create() {
    ::create();
set_name("patron");
        set_id(({"patron"}));
        set_race("human");
        set_gender("male");
        set_short("Patron of this bar");
        set_long(
@OLI
	This patron is quite drunk. He looks at you greedily.
 He is obviously out of money because he keeps staring
 at the empty glass in front of him.
OLI
);
        set_level(6);
        enable_commands();
        set_body_type("human");
        set("aggressive",5);
        set_alignment(3);
        set_size(2);
        set_stats("intelligence",13);
        set_stats("wisdom",10);
        set_stats("strength",13);
        set_stats("charisma",13);
        set_stats("dexterity",9);
        set_stats("constitution",10);
        set_hd(6, 5);
        set_class("fighter");
        set_hp(50+random(25));
        set_max_hp(query_hp());
          }
void init(){
  ::init();
    add_action("buy_me","buy");
    add_action("say_me","say");
  }
     int buy_me(string str){
       int num;
       int ques;
       num = random(9);
       if(num < 5){
	 tell_room(ETO,"The patron lurches toward "+TPQCN,TP);
	 write("The patron lurches toward you.");
	 tell_room(ETO,"He says: Buy me a drink too.",TO);
	 flag= 1;
       }
       return 0;
     }
     
     int say_me(string str){
       string name;
       if(strsrch(str,"yes")!=-1){
	 if(flag){
	 tell_room(ETO,TPQCN+" says yes.",TP);
	 write("You say, Yes");
	 TO->say("Thank yououou,");
	 TP->add_money("gold",-3);
	 tell_room(ETO,TPQCN+" buys ale.",TP);
	 write("You buy ale for the patron.");
	 tell_room(ETO,"The Patron quaffs the drink in a gulp.",TO);
	 flag = 0;
	 return 1;
       }
       }
       if(strsrch(str,"no")!=-1){
	 if(flag){
	 tell_room(ETO,TPQCN+" says No.",TP);
	 write("You say No.");
	 tell_room(ETO,"ohhh, That'sss  Thhhe waay itss gonnnaa beee, huhn.");
	 name = TPQCN;
	 
	 TO->force_me("kill "+name);
	 flag = 0;
	 return 1;
       }
       }
       return 0;
     }


