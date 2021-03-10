// changed the prices and included a new weapon - serpentpike
// (polearm)per talk with Circe - Cythera 4/05
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
	remove_dbs(({"armors"}));
	remove_random_act_dbs(({"armorsrandom"}));
	set_name("Trendamas");
	set_short("Trendamas, the armourer");
	set_id(({"Trendamas","trendamas","armourer","armorer"}));
	set_long(
	"Trendamas is a giant of a man. He is close to seven feet in height"+
	" with buldging muscles. His curly black hair has grown a little long,"+
	" probably been ignored for his armor shop, which seems to be his pride"+
	" and joy. He is a rather young man, in his early twenties. His emerald"+
	" eyes sparkle with life. He is well groomed, with a blue shirt on and"+
	" black trousers with high black leather boots. He's probably one of the"+
	" more eligible bachelors in town."
	);
	set_items_allowed("armor");
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
	set_stats("charisma",17);
	set_stats("wisdom",8);
	set_stats("intelligence",12);
	set_exp(100);
	set("aggressive",0);
	set_storage_room(ROOMDIR+"armor");
	add_money("gold",random(50));
	command("speech speak in a pleasant tone");
	current_price = 79000+random(1000);
	current_price2 = random(5000)+25000;
}

void catch_say(string message)
{
     ::catch_say(message);
	if(strsrch(message,"gold") != -1 && strsrch(message,"armor") != -1) {
		call_out("sell_armor",1,TP,message);
		return;
	}
	if(strsrch(message,"gold") != -1 && strsrch(message,"shield") != -1) {
		call_out("sell_shield",1,TP,message);
		return;
	}
	if(strsrch(message,"scale") != -1 || strsrch(message,"armor") != -1) {
		call_out("do_talk",1,TP,message);
		return;
	}
	if(strsrch(message,"shield") != -1) {
		call_out("do_shield_talk",1,TP,message);
		return;
	}
	else if(strsrch(message,"gold") != -1) {
		call_out("gold_talk",1,TP,message);
		return;
	}
}

void do_talk(object ob, string message)
{
	set_spoken(ob->query_spoken());
	if(strsrch(message,"armor") != -1 || strsrch(message,"scale") != -1) {
		if(!present("serpent_scales",ob)) {
			force_me("say Perhaps if you had something for me to work with, I"+
			" could create you some armor or a shield. Come back if you find"+
			" something interesting.");
			return;
		}
		if(objectp(current_haggler) && present(current_haggler,ETO)) {
			if(current_haggler == ob) {
				if((int)ob->query_size() > 2) {
					if(!present("serpent_scales 2",ob)) {
						force_me("say I'm sorry, but for someone of your size I"+
						" will need two sets of these scales to be able to craft"+
						" them into armor that would fit you. With only one set I"+
						" would only be able to make you a shield.");
						return;
					}
					else {
						force_me("say I will have to use both sets of your scales"+
						" for one piece of armor for a person of your size.");
					}
				}
				force_me("emote exams the scales.");
				force_me("say I believe I could make these scales into a suit of"+
				" scale mail for you. Make me an offer in %^BOLD%^gold for the armor%^RESET%^.");
				current_haggler = ob;
				current_price = 100000+random(10000);
				return;
			}
			force_me("say I'm sorry "+TP->query_cap_name()+", I'm busy with"+
			" "+current_haggler->query_cap_name()+" right now, talk to me when"+
			" we are done.");
			return;
		}
		current_haggler = ob;
		current_price = 79000+random(1000);
	}
}

void gold_talk(object ob, string message)
{
	if(objectp(current_haggler) && present(current_haggler,ETO)) {
		if(current_haggler != ob) {
			force_me("say I'm sorry "+TP->query_cap_name()+", I'm busy with"+
			" "+current_haggler->query_cap_name()+" right now, talk to me when"+
			" we are done.");
			return;
		}
	}
	else {
		force_me("say Make me an offer in %^BOLD%^gold for the item%^RESET%^ be it"+
		" the shield or the armor, whichever you decide.");
		return;
	}
}

void sell_armor(object ob, string message)
{	
	if(strsrch(message,"gold") != -1) {
		if(objectp(current_haggler) && present(current_haggler,ETO)) {
			if(current_haggler != ob) {
				force_me("say I'm sorry "+TP->query_cap_name()+", I'm busy with"+
				" "+current_haggler->query_cap_name()+" right now, talk to me when"+
				" we are done.");
				return;
			}
		}
		else {
			force_me("say I'm sorry, what is it you want me to make, a shield"+
			" or scale mail?");
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
				if(TP->query_size() > 2 && !present("serpent_scales 2",ob)) {
					force_me("say Hmm, what did you do with those scales? You"+
					" had them earlier, but I cannot make you armor without them.");
					current_haggler = 0;
					return;
				}
				if(!present("serpent_scales",ob)) {
					force_me("say Hmm, what did you do with those scales? You"+
					" had them earlier, but I cannot make you armor without them.");
					current_haggler = 0;
					return;
				}
				ob->use_funds("gold",amount);
				if(TP->query_size() > 2) {
					present("serpent_scales",ob)->remove();
					present("serpent_scales",ob)->remove();
				}
				else {
					present("serpent_scales",ob)->remove();
				}
				force_me("emote collects the serpent scales.");
				force_me("say Now give me a while to create the armor.");
				call_out("create_armor",1,TP);
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

void do_shield_talk(object ob, string message)
{
	set_spoken(ob->query_spoken());
	if(strsrch(message,"shield") != -1) {
		if(!present("serpent_scales",ob)) {
			force_me("say Perhaps if you had something for me to work with, I"+
			" could create you some armor or a shield. Come back if you find"+
			" something interesting.");
			return;
		}
		if(objectp(current_haggler) && present(current_haggler,ETO)) {
			if(current_haggler == ob) {
				force_me("say Yes, I could craft these scales into a fine shield."+
				" Make me an offer in %^BOLD%^gold for the shield%^RESET%^.");
				current_haggler = ob;
				current_price2 = random(5000)+25000;
				return;
			}
			force_me("say I'm sorry "+ob->query_cap_name()+", but I'm currently"+
			" busy with "+current_haggler->query_cap_name()+". Please come back"+
			" when our business is done.");
			return;
		}
		current_haggler = ob;
		current_price2 = random(500)+25000;
	}
}

void sell_shield(object ob, string message)
{
	if(strsrch(message,"gold" != -1)) {
		if(objectp(current_haggler) && present(current_haggler,ETO)) {
			if(current_haggler != ob) {
				force_me("say I'm sorry "+ob->query_cap_name()+", but I'm currently"+
				" busy with "+current_haggler->query_cap_name()+". Talk with me"+
				" after we're done.");
				return;
			}
		}
		else {
			force_me("say I'm sorry, am I making you a shield or some armor?");
			return;
		}
		if(sscanf(message,"%s%d silver",before,amount) !=2) {
			force_me("say I'm sorry, I didn't understand what you offered me"+
			" in gold.");
			return 1;
		}
		if(amount >= current_price2) {
			force_me("say Yes, I can make the shield for that price. Do you"+
			" have the money with you?");
			if(ob->query_funds("gold",amount)) {
				force_me("say You have the money with you now, excellent.");
				if(!present("serpent_scales",ob)) {
					force_me("say Hmm, what did you do with those scales? You"+
					" had them earlier, but I cannot make you armor without them.");
					current_haggler = 0;
					return;
				}
				ob->use_funds("gold",amount);
				present("serpent_scales",ob)->remove();
				force_me("emote collects the serpent scales.");
				force_me("say I will get to work on that shield for you now.");
				call_out("create_shield",1,TP);
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

void create_armor(object ob, string message)
{
	object obj2;
	int TSIZE;

	TSIZE = (int)TP->query_size();
	force_me("emote seems to work tirelessly to turn the scales into a nice suit of scale armor.");
	force_me("say At last, it is done.");
	force_me("emote holds up a suit of scale mail proudly.");
	obj2 = new("/d/antioch/ruins/obj/serpent_scales.c");
	obj2->set_owner(TPQN);
	obj2->set_size(TSIZE);
	if((int)obj2->move(TP) != 0) {
		force_me("say Hmm, you can't seem to carry it.");
		force_me("emote drops the scale mail on the ground.");
		obj2->move(ETO);
		force_me("say Don't worry, no one else can use it, I've fitted it precisely to you."+
		" Pick it up when you can.");
		return;
	}
	else {
		tell_object(TP,"Trendamas gives you the serpent scale mail.");
		tell_room(ETP,"Trendamas gives "+TPQCN+" the serpent scale mail.",TP);
		force_me("say If you find anything else, I'll be happy to try and work it for you.");
		obj2->move(TP);
		return;
	}
	return;
}

void create_shield(object ob, string message)
{
	object obj2;

	force_me("emote tirelessly crafts the scales into a fine shield.");
	force_me("emote holds the shield up proudly as he admires the craftsmanship.");
	obj2 = new("/d/antioch/ruins/obj/shield+2.c");
	obj2->set_owner(TPQN);
	if(TP->query_size() < 2) {
		obj2->set_size(1);
	}
	else if(TP->query_size() > 1) {
		obj2->set_size(2);
	}
	if((int)obj2->move(TP) != 0) {
		force_me("say Hmm, you can't seem to carry it.");
		force_me("emote drops the serpent shield on the ground.");
		obj2->move(ETO);
		force_me("say Don't worry, no one else can use it, I've fitted it precisely to you."+
		" Pick it up when you can.");
		return;
	}
	else {
		tell_object(TP,"Trendamas gives you the serpent shield.");
		tell_room(ETP,"Trendamas gives "+TPQCN+" the serpent shield.",TP);
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
			force_me("say I make some of the finest armor around these parts.");
			force_me("emote smiles proudly.");
			break;
		case 1:
			force_me("say I can turn almost anything into armor for you.");
			break;
		case 2:
			force_me("say If you find something that suits you, you should get it.");
			force_me("say It's dangerous times in these lands after all.");
			break;
		case 3:
			force_me("say Make sure the armor feels right to you. It's no use trudging"+
			" around in full plate if you get chafed and sick from the heat.");
			force_me("say Always better to fight in armor that you're comfortable in.");
			force_me("emote nods wisely.");
			break;
		case 4:
			force_me("say I'm always looking for new materials to work with.");
			force_me("say If you come across some new metal or something else, keep"+
			" me in mind, will ya?");
			break;
		case 5:
			force_me("say I can outfit you with some great armor.");
			force_me("say Of course, nothing lasts forever unless it's magical.");
			force_me("say Then again, if all armor lasted forever I'd be out of a job!");
			force_me("laugh");
			break;
	}
	talking = 0;
	return;
}
