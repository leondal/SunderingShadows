//Per discussion with circe - lowered prices - Cythera 4/05
#include <std.h>
#include "../antioch.h"
inherit INTERACTIVE;

int current_price;
int current_price2;
int current_haggler;
string before;
int amount;
int flag = 0;
int talking;
void say_stuff();

void create()
{
	::create();
	remove_std_db();
	remove_dbs(({"tailor"}));
	remove_random_act_dbs(({"tailorrandom"}));
	set_name("Mydan");
	set_short("Mydan, the leather shop owner");
	set_id(({"Mydan","mydan","shop owner","shop keeper"}));
	set_long(
	"Mydan is the owner of the leather shop here in Antioch. He is in his late"+
	" twenties. Rumor has it he took over from his father, who ran the shop"+
	" in the good days of Antioch, but he doesn't want to talk about such"+
	" sorrowful things. He is dressed in a pair of his own leather boots with"+
	" a brown leather jacket, a gray shirt and trousers complete his outfit."+
	" Straight black hair frames his heart-shaped face, and his eyes are a"+
	" pretty hazel."
	);
   set_items_allowed("clothing");
	set_gender("male");
	set_race("human");
	set_body_type("human");
	set_hd(25,5);
	set_max_hp(150+random(50));
	set_hp(query_max_hp());
	set_class("mage");
	set_mlevel("mage",25);
	set_level(25);
	set_alignment(1);
	set_overall_ac(-10);
	set_stats("intelligence",18);
	set_stats("wisdom",12);
	set_stats("charisma",15);
	set_stats("dexterity",14);
	set_stats("constitution",8);
	set_stats("strength",10);
	set_exp(100);
	set("aggressive",0);
	set_storage_room(ROOMDIR+"leather");
	add_money("silver",random(100));
	current_price = 20000+random(1000);
	current_price2 = 60000+random(10000);
}

void catch_say(string message)
{
	if(strsrch(message,"gold") != -1 && strsrch(message,"shield") != -1) {
		call_out("sell_leather",1,TP,message);
		return;
	}
	if(strsrch(message,"gold") != -1 && strsrch(message,"hide") != -1) {
		call_out("sell_hide",1,TP,message);
		return;
	}
	if(strsrch(message,"shield") != -1) {
		call_out("do_talk",1,TP,message);
		return;
	}
	if(strsrch(message,"hide") != -1 || strsrch(message,"scale") != -1) {
		call_out("do_hide_talk",1,TP,message);
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
	if(strsrch(message,"shield") != -1) {
		if(!present("serpent_scales",ob)) {
			force_me("say Maybe if you had something for me to look at,"+
			" I might be able to tell you if I could craft it into a shield"+
			" or work it into a nice suit of hide.");
			return;
		}
		if(objectp(current_haggler) && present(current_haggler,ETO)) {
			if(current_haggler == ob) {
				force_me("emote carefully inspects the scales.");
				force_me("say Yes, I believe I could craft these scales into a nice"+
				" shield for you. Make me an offer in %^BOLD%^gold for the shield%^RESET%^.");
				current_haggler = ob;
				current_price = 20000+random(1000);
				return;
			}
			force_me("say Sorry "+TP->query_cap_name()+", I'm dealing with"+
			" "+current_haggler->query_cap_name()+" right now, talk to me when we're through.");
			return;
		}
		current_haggler = ob;
		current_price = 20000+random(1000);
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
		" the shield or the hide, whichever you decide on.");
		return;
	}
}

void sell_leather(object ob, string message)
{
	if(strsrch(message,"gold") != -1) {
		if(objectp(current_haggler) && present(current_haggler,ETO)) {
			if(current_haggler != ob) {
				force_me("say Sorry "+TP->query_cap_name()+", I'm dealing with"+
			" "+current_haggler->query_cap_name()+" right now, talk to me when we're through.");
				return;
			}
		}
		else {
			force_me("say I'm sorry, did you want me to make you a shield or a suit of hide?");
			return;
		}
		if(sscanf(message,"%s%d gold",before,amount) != 2) {
			force_me("say I'm sorry, I didn't understand what you offered"+
			" me in gold.");
			return;
		}
		if(amount >= current_price) {
			force_me("say That seems like a fair price to me. Now, do you have"+
			" the money with you?");
			if(ob->query_funds("gold",amount)) {
				force_me("say Excellent, I see that you do!");
				if(!present("serpent_scales",ob)) {
					force_me("say Hmm, what did you do with those scales? You"+
					" had them just a bit ago, and I can't exactly make the shield without them, now can I?");
					current_haggler = 0;
					return;
				}
				ob->use_funds("gold",amount);
				present("serpent_scales",ob)->remove();
				force_me("say Now give me a little bit of time to create the shield.");
				call_out("create_leather",1,TP);
				return;
			}
			else {
				force_me("say I see you don't have the money on you. There's a bank on the"+
				" main street through town, you can come back when you have the money.");
				current_haggler = 0;
				return;
			}
		}
		else {
			force_me("smirk");
			force_me("say My work is worth much more than that, please don't waste my time.");
			return;
		}
	}
}

void do_hide_talk(object ob, string message)
{
	set_spoken(ob->query_spoken());
	if(strsrch(message,"hide") != -1 || strsrch(message,"scale") != -1) {
		if(!present("serpent_scales",ob)) {
			force_me("say Maybe if you had something for me to look at,"+
			" I might be able to tell you if I could craft it into a shield"+
			" or work it into a nice suit of hide.");
			return;
		}
		if(objectp(current_haggler) && present(current_haggler,ETO)) {
			if(current_haggler == ob) {
				if((int)ob->query_size() > 2) {
					if(!present("serpent_scales 2",ob)) {
						force_me("say Sorry, but for someone of your large stature"+
						" I'm going to need two sets of these scales to be able to make something"+
						" that would fit you.");
						return;
					}
					else {
						force_me("say I'll have to use both sets of these scales"+
						" to make some armor for someone of your size.");
					}
				}
				force_me("emote carefully inspects the scales.");
				force_me("say Yes, I believe I could craft these scales into a nice suit of"+
				" hide armor for you. Make me an offer in %^BOLD%^gold for the hide%^RESET%^.");
				current_haggler = ob;
				current_price2 = 60000+random(10000);
				return;
			}
			force_me("say Sorry "+TP->query_cap_name()+", I'm dealing with"+
			" "+current_haggler->query_cap_name()+" right now, talk to me when we're through.");
			return;
		}
		current_haggler = ob;
		current_price2 = 60000+random(10000);
	}
}

void sell_hide(object ob, string message)
{
	if(strsrch(message,"gold") != -1) {
		if(objectp(current_haggler) && present(current_haggler,ETO)) {
			if(current_haggler != ob) {
				force_me("say Sorry "+TP->query_cap_name()+", I'm dealing with"+
			" "+current_haggler->query_cap_name()+" right now, talk to me when we're through.");
				return;
			}
		}
		else {
			force_me("say I'm sorry, did you want me to make you a shield"+
			" or a suit of hide?");
			return;
		}
		if(sscanf(message,"%s%d gold",before,amount) != 2) {
			force_me("say I'm sorry, I didn't understand what you offered"+
			" me in gold.");
			return;
		}
		if(amount >= current_price2) {
			force_me("say That seems like a fair price to me. Now, do you have"+
			" the money with you?");
			if(ob->query_funds("gold",amount)) {
				force_me("say Excellent, I see that you do!");
				if(TP->query_size() > 2 && !present("serpent_scales 2",ob)) {
					force_me("say Hmm, what did you do with those scales? You"+
					" had them just a bit ago, and I can't exactly make the armor without them, now can I?");
					current_haggler = 0;
					return;
				}
				if(!present("serpent_scales",ob)) {
					force_me("say Hmm, what did you do with those scales? You"+
					" had them just a bit ago, and I can't exactly make the armor without them, now can I?");
					current_haggler = 0;
					return;
				}
				ob->use_funds("gold",amount);
				if(TP->query_size() > 2) {
					present("serpent_scales 2",ob)->remove();
					present("serpent_scales",ob)->remove();
				}
				else if (TP->query_size() < 3) {
					present("serpent_scales",ob)->remove();
				}
				force_me("say Now give me a little bit of time to create the hide.");
				call_out("create_hide",1,TP);
				return;
			}
			else {
				force_me("say I see you don't have the money on you. There's a bank on the"+
				" main street through town, you can come back when you have the money.");
				current_haggler = 0;
				return;
			}
		}
		else {
			force_me("smirk");
			force_me("say My work is worth much more than that, please don't waste my time.");
			return;
		}
	}
}

void create_leather(object ob, string message)
{
	object obj2;

	force_me("emote works meticulously to create a strong shield from the serpent scales.");
	force_me("emote wipes the sweat from his brow as he finishes.");
	obj2 = new("/d/antioch/ruins/obj/shield+1");
	obj2->set_owner(TPQN);
	if(TP->query_size() > 1) {
		obj2->set_size(2);
	}
	else if(TP->query_size() < 2) {
		obj2->set_size(1);
	}
	if((int)obj2->move(TP) != 0) {
		force_me("frown");
		force_me("say Well, since you can't seem to carry it right now, I'll just set"+
		" it down here so you can grab it when you've made room.");
		obj2->move(ETO);
		return;
	}
	else {
		tell_object(TP,"Mydan hands you a serpent scale shield.");
		tell_room(ETP,"Mydan hands "+TPQCN+" a serpent scale shield.",TP);
		force_me("say It was a pleasure doing business with you. Come back soon!");
		obj2->move(TP);
		return;
	}
	return;
}

void create_hide(object ob, string message)
{
	object obj2;
	int TSIZE;

	TSIZE = TP->query_size();
	force_me("emote works hard to craft the scales into a supple suite of hide armor.");
	force_me("emote relaxes and smiles as he finally finishes.");
	obj2 = new("/d/antioch/ruins/obj/serpent_hide");
	obj2->set_size(TSIZE);
	obj2->set_owner(TPQN);
	if((int)obj2->move(TP) != 0) {
		force_me("say You can't seem to carry it. Make some room in your inventory"+
		" and pick it up when you can.");
		force_me("emote drops the serpent hide.");
		obj2->move(ETO);
		return;
	}
	else {
		force_me("say I've never made a suit of hide armor out of such soft, flexible"+
		" material before. I hope you like it.");
		force_me("smile "+TPQN);
		tell_object(TP,"Mydan hands you a suit of serpent hide armor.");
		tell_room(ETP,"Mydan hands "+TPQCN+" a suit of serpent hide armor.",TP);
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
			force_me("say You know, I'm always interested in finding different types"+
			" of hide that I can tan.");
			break;
		case 1:
			force_me("say If you ever come across some unusual hide, bring it to me"+
			" and I'll see if I can't make something from it.");
			force_me("smile");
			break;
		case 2:
			force_me("say You know, I once was brought some dragon scales that I turned"+
			" into a nice set of armor for a ranger.");
			force_me("say Boy would I like to get my hands on something like that again!");
			force_me("emote reminisces about the good times.");
			break;
		case 3:
			force_me("say You better steer clear of the old ruins. That place still"+
			" isn't safe, but it's not as bad as it used to be.");
			force_me("shudder");
			break;
		case 4:
			force_me("say I love to tan things. Working with leather is just such a"+
			" relaxing feeling.");
			break;
	}
	talking = 0;
	return;
}
