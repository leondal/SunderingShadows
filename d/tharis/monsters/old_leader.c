//old_leader.c

#include <std.h>

inherit MONSTER;

string *encountered;
string *bencountered;
string *waiting;
int flag;

void create(){
	::create();
	set_name("old leader");
	set_id(({"old","old leader","man","old man","leader"}));
	set_short("An older leader");
	set_long(
@OLI
	This old man wears the scars of battle. A wisened look is countered
only by a look of benevolence. A mass of silver hair covers his head.
You notice that it carrys a slight %^CYAN%^tint%^RESET%^ to it. He
strides with wide strong steps. The wirey muscles tense and release 
as he moves. You notice a great sense of confidence about him. Who
is this mysterious leader of the good fighting here in this forest?
OLI
	);
	set_class("fighter");
	set_hd(23,10);
	set_hp(260);
	set_guild_level("mage",15);
	set_stats("strength",25);
	set_stats("intelligence",25);
	set_stats("wisdom",25);
	set_stats("charisma",25);
	set_stats("constitution",25);
	set_stats("dexterity",25);
	set_race("half-elf");
	set_body_type("human");
	bencountered = ({});
	encountered = ({});
	waiting = ({});
	set_gender("male");
	set_overall_ac(-8);
	set_mob_magic_resistance("average");
	set_exp(30000);
	set_spells(({"lightening bolt","cone of cold","magic missile","scorcher","fireball"}));
	set_spell_chance(90);
	set_alignment(1);
	}
	
void init(){
	::init();
	if(member_array(TPQN,bencountered) != -1)
		kill_ob(TP,1);
	if(member_array(TPQN,encountered) != -1)
		call_out("do_inquiries",1,TP);
	else {
		add_action("yes_em","yes");
		add_action("yes_em","no");
		if(!present("steel dragon",ETO))
		call_out("do_greetings",1,TP);
	}
}

void do_greetings(object ob){
	
	
	if(ALIGN->is_good(ob)){
			tell_object(ob,"The old man sees you and booms:\n");
			tell_object(ob,
@OLI
%^BOLD%^Friend, it is good to see good entering the forest.
All good must gather together to keep evil from 
gaining such a strong hold such as this! We must get 
to the evil strong hold and conquor the Rakshasa and 
forest Dragon sent here! If you will please join in 
the effort to reach the strong hold toward the north 
of the forest
GO, and may all good be with you!
Having said such, the old man returns to his work!
OLI
			);
			encountered += ({ob->query_name()});
			return;
		}
			
	if(ALIGN->is_neutral(ob)){
		tell_object(ob,"The old man sees you and booms:\n");
		tell_object(ob,
@OLI
%^BOLD%^Ahh, I see one who can not see is here. Allow me to 
try to explain. In a battle such as this you can not
straddle the fence. You must choose a side. Life will 
not allow you to remain on the sidelines. The evil will
consume you as it does all. You must pick!
Will you join us? <yes> or <no>
OLI
		);
		waiting += ({(string)ob->query_name()});
		return;
		}
	
	if(ALIGN->is_evil(ob)){
		tell_object(ob,"%^BOLD%^As you stride into the room, a low rumbling\n");
		tell_object(ob,
@OLI
%^BOLD%^seems to shake the room. The old man explodes in anger. How dare you
who hast chosen badly come into my presence. Leave at once before
before I return you to your devil father. I give you only 5 seconds
then I will revoke my grant of life!
OLI
			);
		call_out("kill_em",5,ob->query_name());
		return;
	}
}

void do_inquiries(object ob){
	
	tell_object(ob,"Ahh yes coming in for a rest. Well evil shant rest and neither shall\n");
	tell_object(ob,"we. Good job out there. Now go help save this haven of good!\n");
}
		

int yes_em(){

	string verb;
	
	if(member_array(TPQN,waiting) == -1) return 0;
	
	verb = query_verb();
	
	if(verb == "yes"){
		tell_object(TP,"Yes I see you have chosen well.GOOD\n");
		tell_object(TP,
@OLI
%^BOLD%^All good must gather together to keep evil from gaining such 
a strong hold such as this! We must get to the evil strong 
hold and conquor the Rakshasa and forest Dragon sent here!
If you will please join in the effort to reach the strong
hold toward the north of the forest. GO, and may all good 
be with you! Having said such, the old man returns to his 
work!
OLI
		);
		encountered += ({TPQN});
		return 1;
	}
	tell_object(TP,
@OLI
%^BOLD%^EVIL will eat your children. You will sit back and watch!
No you will join them to halt the horrors. Well note me as enemy.
The old man explodes in anger. How dare you who hast chosen 
badly come into my presence. Leave at once before before I
return you to your devil father. I give you only 5 seconds
then I will revoke my grant of life!
OLI
				);
	call_out("kill_em",5,TP->query_name());
	return 1;
}

void kill_em(string name){
	object ob;
	if(ob = present(name,ETO)){
		tell_room(ETO,"%^BOLD%^%^RED%^I WARNED YOU EVIL DOER!\n");
		kill_ob(ob,1);
	}
}

int kill_ob(object victim, int which){
	call_out("pain",1,victim);
	return ::kill_ob(victim,which);
}

void pain(object victim){
	object ob;

	bencountered += ({(string)victim->query_name()});
	tell_room(ETO,"%^BOLD%^%^B_CYAN%^Suddenly the air starts to shift!\n");
	tell_room(ETO,"%^BOLD%^%^B_CYAN%^Smoke forms.\n");
	tell_room(ETO,"%^BOLD%^%^B_CYAN%^Space seems to contort.\n");
	tell_room(ETO,"%^BOLD%^%^B_CYAN%^Standing in front of you is a grand steel dragon!\n");
	ob=new("/d/tharis/monsters/steeldragon");
	ob->move(ETO);
	ob->set_encountered(encountered);
	ob->set_bencountered(bencountered);
	ob->set_hp(query_hp());
	ob->kill_ob(victim,1);
	remove();
}

void set_encountered(string *input){
	encountered = input;
	}

void set_bencountered(string *input){
	bencountered = input;
	}
