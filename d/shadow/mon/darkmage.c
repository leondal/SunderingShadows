#include "./melnmarn.h";

inherit MONSTER;
int step;

create() {
    ::create();
	set_name("darkmage");
	set_id( ({ "darkmage","mage" }) );
	set("race", "human");
	set_gender("male");
	set_short("A human mage");
	set_long(
   "He is a human mage. He has dark piercing eyes and long, "
	"black hair. He is wearing a black robe, and wielding a quarter staff in "
	"one hand. He looks at you, sending chills down your spine. You can feel"
   " evil emanating from him. "
	);
	set_level(15);
	enable_commands();   
	set_body_type("human");
  	set("aggressive",5);
  	set_alignment(9);
  	set_size(2);
   	set_stats("intelligence",18);
   	set_stats("wisdom",18);
   	set_stats("strength",13);
   	set_stats("charisma",3);
   	set_stats("dexterity",16);
   	set_stats("constitution",13);
   	set_max_mp(0);
   	set_mp(query_max_mp());
	set_hd(5, 1);
	set_class("mage");
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
        new(WEAPONDIR+"quarter_staff")->move(this_object());
      	command("wield staff in right hand");
        new(ARMORDIR+"robe")->move(this_object());
      	command("wear armor");
	add_money("silver",random(10));
	add_money("copper",random(20));
	step = 0;
}

void catch_tell(string str){
	if((strsrch(str,"hello") != -1) && (step == 0)){ 
		call_out("reply_back",2,"What is it!"); 
		call_out("reply_back",4,"Who are you?"); 
		call_out("reply_back",6,"What are you doing here?"); 
		call_out("reply_back",8,"Why are you bothering me?"); 
		call_out("reply_back",10,"Don't bother answering. Just go away."); 
		step = 1;
		return;
	}
	if((strsrch(str,"sword") != -1) && (step == 1)){ 
		call_out("reply_back",2,"What about it!"); 
		call_out("reply_back",4,"You just don't worry about it."); 
		call_out("reply_back",6,"And stay away from that case!"); 
		call_out("reply_back",8,"It isn't anything you need concern yourself with.");
		call_out("reply_back",10,"Don't bother it. Just go away."); 
		step = 2;
		return;	
	}
	if((strsrch(str,"case") != -1) && (step == 2)){ 
		call_out("reply_back",2,"What about it!"); 
		call_out("reply_back",4,"You just don't worry about it."); 
		call_out("reply_back",6,"And stay away from that case!"); 
		call_out("reply_back",8,"It isn't anything you need concern yourself with.");
		call_out("reply_back",10,"Don't bother it. Just go away."); 
		step = 3;
		return;	
	}
	if((strsrch(str,"open") != -1) && (step == 3)){ 
		call_out("reply_back",2,"What!"); 
		call_out("reply_back",4,"You want me to open it?"); 
		call_out("reply_back",6,"And why should I do that?"); 
		call_out("reply_back",8,"Do you think you will be able to wield that sword?");
		call_out("reply_back",10,"Ha ha ha!!!"); 
		step = 4;
		return;	
	}
	if((strsrch(str,"wield") != -1) && (step == 4)){ 
		call_out("reply_back",2,"Ha Ha Ha.."); 
		call_out("reply_back",4,"So you think you are tough enough huh?"); 
		call_out("reply_back",6,"From looking at you, I doubt it!"); 
		call_out("reply_back",8,"If you say the magic word, maybe I'll open it for you.");
		call_out("reply_back",10,"Ha ha ha!!!"); 
		step = 5;
		return;	
	}
	if((strsrch(str,"please") != -1) && (step == 5)){ 
		call_out("reply_back",2,"Ha Ha Ha.."); 
		call_out("reply_back",4,"Well, since you begged."); 
		call_out("reply_back",6,"And me, being a man of my word."); 
		call_out("reply_back",8,"I'll open it for you.");
		call_out("reply_back",10,"Ha ha ha!!!"); 
		call_out("re_close_it",60);
		step = 0;
		present("glass case",environment(TO))->open_case();
		return;	
	}

	return;

}

void reply_back(string str){
	tell_room(environment(TO),"%^MAGENTA%^The Darkmage Says:%^WHITE%^ "+str,TO);
}
void re_close_it(){
		present("glass case",environment(TO))->close_case();
}
