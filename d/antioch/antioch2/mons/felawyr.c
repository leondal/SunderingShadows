//Changed prices per discussion with Circe - Cythera 4/05
//added option to create a pike as well
#include <std.h>
#include "../antioch.h"
inherit INTERACTIVE;

void say_stuff();
int current_price;
int current_price2;
int current_haggler;
string before;
int amount;
int flag = 0;
int talking;

void create()
{
	::create();
	remove_std_db();
	remove_dbs(({"weapons"}));
	set_name("Felawyr");
	set_short("Felawyr, the weapons smith");
	set_id(({"black smith","weaponsmith","weapon smith","Felawyr","felawyr"}));
	set_long(
	"Felawyr is a renowned blacksmith in the Charu Mountains. He has been"+
	" practicing for years, even before Antioch was taken over by evil. He"+
	" was kept prisoner during those troubled times before being freed. "
      "Now he is once again back to the anvil and forge,"+
	" creating weapons for the town's protection. He personally handcrafted"+
	" all the weapons for the town guards. The quality of his weapons is"+
	" always high. His clothing and hands are stained black from his work"+
	" at the forge, and sweat trickles down his forehead. Brown curly hair"+
	" has been cropped short to keep it out of his face, and his brown eyes"+
	" seem a bit tired, but warm. He keeps his beard carefully trimmed, and"+
	" you notice that specks of gray have begun creeping into it."
	);
   set_items_allowed("weapon");
	set_gender("male");
	set_race("human");
	set_body_type("human");
	set_hd(30,8);
	set_alignment(1);
	set_max_hp(300+random(50));
	set_hp(query_max_hp());
	set_level(30);
	set_overall_ac(-15);
	set_class("fighter");
	set_mlevel("fighter",30);
	set_stats("strength",20);
	set_stats("consitution",18);
	set_stats("dexterity",14);
	set_stats("charisma",12);
	set_stats("wisdom",8);
	set_exp(100);
	set("aggressive",0);
	set_storage_room(ROOMDIR+"weapon");
	add_money("gold",random(50));
	command("speech speak in a gravely voice");
	current_price = 30000+random(10000);
	current_price2 = random(10000)+30000;

}

void catch_say(string message)
{
     ::catch_say(message);
	if(strsrch(message,"gold") != -1 && strsrch(message,"sword") != -1) {
		call_out("sell_sword",1,TP,message);
		return;
	}
	if(strsrch(message,"gold") != -1 && strsrch(message,"rapier") != -1) {
		call_out("sell_sword",1,TP,message);
		return;
	}
	if(strsrch(message,"gold") != -1 && strsrch(message,"pike") != -1) {
		call_out("sell_pike",1,TP,message);
		return;
	}
	if(strsrch(message,"tooth") != -1 || strsrch(message,"sword") != -1) {
		call_out("do_talk",1,TP,message);
		return;
	}
	if(strsrch(message,"tooth") != -1 || strsrch(message,"rapier") != -1) {
		call_out("do_talk",1,TP,message);
		return;
	}
	if(strsrch(message,"sword") != -1) {
		call_out("do_sword_talk",1,TP,message);
		return;
	}
	if(strsrch(message,"rapier") != -1) {
		call_out("do_sword_talk",1,TP,message);
		return;
	}
	else if(strsrch(message,"pike") != -1) {
		call_out("gold_talk",1,TP,message);
		return;
	}
}

void do_talk(object ob, string message)
{
	set_spoken(ob->query_spoken());
	if(strsrch(message,"sword") != -1 || strsrch(message,"tooth") != -1) {
		if(!present("serpent_tooth",ob)) {
			force_me("say Perhaps if you had something for me to work with, I"+
			" could create you a rapier or a pike. Come back if you find"+
			" something interesting.");
			return;
		}
		if(objectp(current_haggler) && present(current_haggler,ETO)) {
			if(current_haggler == ob) {
				force_me("emote exams the tooth.");
				force_me("say I believe I could make this tooth into a weapon for"+
					" you. Make me an offer in %^BOLD%^gold for the rapier or the pike%^RESET%^.");
				current_haggler = ob;
				current_price = 30000+random(10000);
				return;
			}
			force_me("say I'm sorry "+TP->QCN+", I'm busy with"+
			" "+current_haggler->QCN+" right now, talk to me when"+
			" we are done.");
			return;
		}
		current_haggler = ob;
		current_price = 30000+random(10000);
	}
}

void gold_talk(object ob, string message)
{
	if(objectp(current_haggler) && present(current_haggler,ETO)) {
		if(current_haggler != ob) {
			force_me("say I'm sorry "+TP->QCN+", I'm busy with"+
			" "+current_haggler->QCN+" right now, talk to me when"+
			" we are done.");
			return;
		}
	}
	else {
		force_me("say Make me an offer in %^BOLD%^gold for the item%^RESET%^ be it"+
		" the rapier or the pike, whichever you decide.");
		return;
	}
}

void sell_pike(object ob, string message)
{
	if(strsrch(message,"gold") != -1) {
		if(objectp(current_haggler) && present(current_haggler,ETO)) {
			if(current_haggler != ob) {
				force_me("say I'm sorry "+TP->QCN+", I'm busy with"+
				" "+current_haggler->QCN+" right now, talk to me when"+
				" we are done.");
				return;
			}
		}
		else {
			force_me("say I'm sorry, what is it you want me to make, a rapier"+
			" or a pike?");
			return;
		}
		if(sscanf(message,"%s%d gold",before,amount) != 2) {
			force_me("say I'm sorry, I didn't understand what you offered"+
			" me in gold.");
			return 1;
		}
		if(amount >= current_price) {
			force_me("say I think that will do just fine. Now, do you have"+
			" the money with you?");
			if(ob->query_funds("gold",amount)) {
				force_me("say You do, excellent.");
                                if(!present("serpent_tooth",ob)){
					force_me("say Hmm, what did you do with that tooth? You"+
					" had them earlier, but I cannot make you a weapon without them.");
					current_haggler = 0;
					return;
				}
				ob->use_funds("gold",amount);
					present("serpent_tooth",ob)->remove();
				force_me("emote collects the serpent tooth.");
				force_me("say Now give me a while to create the weapon.");
				call_out("create_pike",1,TP);
			}
			else {
				force_me("say Hmm, don't have the money on you. Well there is"+
				" a bank nearby, you can come back when you have the money.");
				current_haggler = 0;
			}
		}
		else {
			force_me("snort");
			force_me("say I am sorry, but my work is worth much more than that.");
		}
	}
}

void do_sword_talk(object ob, string message)
{
	set_spoken(ob->query_spoken());
	if(strsrch(message,"sword") != -1) {
		if(!present("serpent_tooth",ob)) {
			force_me("say Perhaps if you had something for me to work with, I"+
			" could create you some a rapier or a pike. Come back if you find"+
			" something interesting.");
			return;
		}
		if(objectp(current_haggler) && present(current_haggler,ETO)) {
			if(current_haggler == ob) {
				force_me("say Yes, I could craft this tooth into a fine rapier."+
				" Make me an offer in %^BOLD%^gold for the rapier or pike%^RESET%^.");
				current_haggler = ob;
				current_price = 30000+random(10000);
				return;
			}
			force_me("say I'm sorry "+ob->QCN+", but I'm currently"+
			" busy with "+current_haggler->QCN+". Please come back"+
			" when our business is done.");
			return;
		}
		current_haggler = ob;
		current_price2 = random(5000)+30000;
	}
}

void sell_sword(object ob, string message)
{
	if(strsrch(message,"gold" != -1)) {
		if(objectp(current_haggler) && present(current_haggler,ETO)) {
			if(current_haggler != ob) {
				force_me("say I'm sorry "+ob->QCN+", but I'm currently"+
				" busy with "+current_haggler->QCN+". Talk with me"+
				" after we're done.");
				return;
			}
		}
		else {
			force_me("say I'm sorry, am I making you a rapier or a pike?");
			return;
		}
		if(sscanf(message,"%s%d silver",before,amount) !=2) {
			force_me("say I'm sorry, I didn't understand what you offered me"+
			" in gold.");
			return 1;
		}
		if(amount >= current_price2) {
			force_me("say Yes, I can make the rapier for that price. Do you"+
			" have the money with you?");
			if(ob->query_funds("gold",amount)) {
				force_me("say You have the money with you now, excellent.");
				if(!present("serpent_tooth",ob)) {
					force_me("say Hmm, what did you do with that tooth? You"+
					" had them earlier, but I cannot make you rapier without them.");
					current_haggler = 0;
					return;
				}
				ob->use_funds("gold",amount);
				present("serpent_tooth",ob)->remove();
				force_me("emote collects the serpent tooth.");
				force_me("say I will get to work on that rapier for you now.");
				call_out("create_sword",1,TP);
				current_haggler = 0;
			}
			else {
			force_me("say There is a bank nearby, come back when you have the money.");
			}
		}
		else {
			force_me("snort");
			force_me("say That is hardly enough money for my time and effort.");
		}
	}
}

void create_pike(object ob, string message)
{
	object obj2;
	int TSIZE;

	TSIZE = (int)TP->query_size();
	force_me("emote seems to work tirelessly to turn the tooth into a fine pike.");
	force_me("say At last, it is done.");
	force_me("emote holds up an ivory pike proudly.");
	obj2 = new("/d/antioch/ruins/obj/serpentpike.c");
	obj2->set_owner(TPQN);
		if((int)obj2->move(TP) != 0) {
		force_me("say Hmm, you can't seem to carry it.");
		force_me("emote drops the pike on the ground.");
		obj2->move(ETO);
		force_me("say Don't worry, no one else can use it, I've fitted it precisely to you."+
		" Pick it up when you can.");
		return;
	}
	else {
		tell_object(TP,"Trendamas gives you the ivory pike.");
		tell_room(ETP,"Trendamas gives "+TPQCN+" the ivory pike.",TP);
		force_me("say If you find anything else, I'll be happy to try and work it for you.");
		obj2->move(TP);
		return;
	}
	return;
}

void create_sword(object ob, string message)
{
	object obj2;

	force_me("emote tirelessly crafts the tooth into a fine rapier.");
	force_me("emote holds the rapier up proudly as he admires the craftsmanship.");
	obj2 = new("/d/antioch/ruins/obj/serpent_tooth.c");
	obj2->set_owner(TPQN);
	if(TP->query_size() < 2) {
		obj2->set_size(1);
	}
	else if(TP->query_size() > 1) {
		obj2->set_size(2);
	}
	if((int)obj2->move(TP) != 0) {
		force_me("say Hmm, you can't seem to carry it.");
		force_me("emote drops the ivory rapier on the ground.");
		obj2->move(ETO);
		force_me("say Don't worry, no one else can use it, I've fitted it precisely to you."+
		" Pick it up when you can.");
		return;
	}
	else {
		tell_object(TP,"Trendamas gives you the ivory rapier.");
		tell_room(ETP,"Trendamas gives "+TPQCN+" the ivory rapier.",TP);
		force_me("say If you find anything else, I'll be happy to try and work it for you.");
		obj2->move(TP);
		return;
	}
	return;
}

void heart_beat()
{
	::heart_beat();
	if(!objectp(TO)) return;
   if(sizeof(query_attackers())) return;

   if(talking) return;
	if(query_night() != 1) {
		if(!random(200)) {
			say_stuff();
			return;
		}
	}
}

void say_stuff()
{
	talking = 1;
	switch(random(5)) {
		case 0:
			force_me("say A sharp blade can save yer life. Tis always best to keep"+
			" yer weapons in good shape, ne'er can tell when ye'll have to use it.");
			break;
		case 1:
			force_me("say I sell the sharpest weapons north o' Shadow!");
			force_me("emote smiles broadly.");
			break;
		case 2:
			force_me("say Tis not wise to walk around these parts without a good"+
			" weapon in hand.");
			force_me("emote glances around.");
			force_me("say Especially at night. I've heard strange sounds coming from"+
			" them ruins. Ye won't catch me goin anywhere near there again!");
			break;
		case 3:
			force_me("say Ye know, don't always have to be metal things that make"+
			" good weapons.");
			force_me("say Why, I once used a mace that was studded with shark's teeth."+
			" Best darn mace I ever had, too bad some good fer nothin thief stole it"+
			" one night.");
			force_me("emote grumbles about thieves.");
			break;
		case 4:
			force_me("say If ye ever find somethin that ye want made into a weapon,"+
			" just bring it to me and I'll fix it up nice for ye.");
			force_me("emote grins at you.");
			break;
	}
	talking = 0;
	return;
}
