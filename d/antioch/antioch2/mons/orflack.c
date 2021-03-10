#include <std.h>
#include "../antioch.h"
inherit "/std/comp_vend.c";

void say_stuff();
int current_price;
int current_haggler;
string before;
int amount;
int flag = 0;
int talking;
int CALL;

void create()
{
	::create();
	CALL = 0;
	remove_std_db();
	remove_dbs(({ "alchemist" }));
	remove_random_act_dbs(({ "alchemistrandom" }));
	set_name("Orflack");
	set_id(({ "Orflack", "mage", "orflack", "alchemist" }));
	set_short("Orflack, the palace alchemist");
	set_long(
		"Orflack is the alchemist of the palace, favored by the king. It is rumored" +
		" that the two of them used to fight side by side on campaigns together" +
		" before Antioch was taken over, and that it was only Orflack's magic" +
		" that kept the two of them free from evil control during that horrible" +
		" period. He is dressed in white mage robes, denoting him as a good mage." +
		" He is getting older in age, but then most great mages are. His black" +
		" hair has gray streaks in it, but he still appears quite robust and" +
		" capable of handling himself."
		);
	set_components(100);
	set_race("human");
	set_gender("male");
	set_body_type("human");
	set_hd(30, 8);
	set_class("fighter");
	set_class("mage");
	set_mlevel("mage", 30);
	set_mlevel("fighter", 30);
	set_level(30);
	set_max_hp(250 + random(50));
	set_hp(query_max_hp());
	set_overall_ac(-15);
	set_alignment(1);
	set("aggressive", 0);
	set_stats("intelligence", 25);
	set_stats("strength", 19);
	set_stats("charisma", 8);
	set_stats("wisdom", 16);
	set_stats("dexterity", 17);
	set_stats("constitution", 15);
	set_mob_magic_resistance("high");
	set_exp(2000);
	set_max_level(20);
	set_spells(({
		"meteor swarm",
		"monster summoning vii",
		"chain lightning",
	}));
	set_spell_chance(90);
	new(OBJ + "silver_sword")->move(TO);
	force_me("wield silver sword");
	if (!random(10)) {
		new(OBJ + "bracers")->move(TO);
		force_me("wear bracers");
	}
}

void heart_beat()
{
	object ob, *atkrs;
	int x, CALL;
	if (!objectp(TO)) return;
	atkrs = TO->query_attackers();
	::heart_beat();
	if (atkrs != ({ }) && CALL != 1) {
		call_out("summon_guards", 5);
		force_me("yell Help, I'm being attacked! Someone call the guards!");
		CALL = 1;
	}else if (!random(200) && talking != 1) {
		say_stuff();
	}
}

int summon_guards()
{
	object ob;
	tell_room(ETO, "%^BOLD%^Several guards burst into the room.");
	new(MONS + "royal guard")->move(ETO);
	if (sizeof(TO->query_attackers()) > 1) {
		new(MONS + "royal_guard")->move(ETO);
	}
	if (sizeof(TO->query_attackers()) > 2) {
		new(MONS + "royal_guard")->move(ETO);
	}
	if (sizeof(TO->query_attackers()) > 3) {
		new(MONS + "royal_guard")->move(ETO);
	}
	if (sizeof(TO->query_attackers()) > 4) {
		new(MONS + "royal_guard")->move(ETO);
	}
	if (sizeof(TO->query_attackers()) > 5) {
		new(MONS + "royal_guard")->move(ETO);
	}
	return 1;
}

void catch_say(string message)
{
	if (!present("bracers of magi", TO)) return;
	if (strsrch(message, "gold") != -1 || strsrch(message, "bracers") != -1) {
		call_out("do_talk", 1, TP, message);
	}
}

void do_talk(object ob, string message)
{
	if (TP->query_lowest_level() < 10) {
		force_me("say You're a little too young to be trusted with such magic. Perhaps" +
			 " when you have learned more of the world we can discuss this.");
		return;
	}
	if (!TP->is_class("mage")) {
		force_me("say I'm sorry, but I wouldn't feel right about entrusting these" +
			 " bracers to anyone who did not practice the Art.");
		return;
	}
	set_spoken(ob->query_spoken());
	if (strsrch(message, "bracers") != -1) {
		if (objectp(current_haggler) && present(current_haggler, ETO)) {
			if (current_haggler == ob) {
				force_me("show bracers of magi to " + TPQN + "");
				force_me("say These are very special bracers, they have saved me in" +
					 " many a battle.");
				force_me("say But I suppose my adventuring days are over. If you're" +
					 " really interested in them, make me an offer in gold.");
				return;
			}
			force_me("say I'm sorry " + ob->query_cap_name() + ", I'm busy with " + current_haggler->query_cap_name() + " right now.");
			return;
		}
		current_haggler = ob;
		if (ob->is_class("thief") || ob->is_class("fighter")) {
			current_price = 20000 + random(1000);
		}else  {
			current_price = 15000 + random(1000);
		}
	}else if (strsrch(message, "gold") != -1) {
		if (objectp(current_haggler) && present(current_haggler, ETO)) {
			if (current_haggler != ob) {
				force_me("say I'm sorry " + ob->query_cap_name() + ", I'm busy with " + current_haggler->query_cap_name() + " right now.");
				return;
			}
			if (sscanf(message, "%s%d gold", before, amount) != 2) {
				force_me("say I'm sorry, I didn't understand what you offered me in gold.");
				return;
			}
			if (amount >= current_price) {
				force_me("say That sounds like a fair price to me. Now, do you have the gold with you?");
				if (ob->query_funds("gold", amount)) {
					force_me("say Excellent, I see that you do.");
					ob->use_funds("gold", amount);
					force_me("drop bracers");
					force_me("say There you are, hope you like them.");
					return;
				}else  {
					force_me("say Running a bit short on gold, eh? Well no matter, there is" +
						 " a bank just south of the fountain in town. Come back when you have the money.");
				}
				current_price = 0;
				current_haggler = 0;
			}else  {
				force_me("sigh");
				force_me("say These bracers have served me well, I'm afraid I'm not about" +
					 " to part with them for that small sum of gold.");
			}
		}else  {
			force_me("say I'm sorry, what are you offering me gold for again? I seem" +
				 " to have forgotten already.");
			force_me("smile");
			return;
		}
	}
}

void say_stuff()
{
	talking = 1;
	switch (random(5)) {
	case 0:
		force_me("emote leans back in his chair.");
		force_me("say I've scraped through by the skin of my teeth more times than" +
			 " I'd really care to remember.");
		force_me("say Contingency's saved me more than a few times. That can be a" +
			 " useful spell.");
		break;
	case 1:
		force_me("say I used to be an adventurer like yourself.");
		force_me("say Not too many of us 'old' adventurers around, you have to" +
			 " survive to grow old and retire.");
		break;
	case 2:
		if (present("bracers of magi", TO)) {
			force_me("say I still remember the adventure that I found these bracers" +
				 " on.");
			force_me("say They were locked in a warded chest in the tower of an evil" +
				 " warlock that my party had defeated.");
			force_me("say They've served me well.");
			force_me("emote runs his fingers idly over the bracers.");
			return;
		}
		force_me("say Every now and then I get out some of my old adventuring gear" +
			 " and put it on.");
		force_me("say The bracers of the magi are my favorite. They make me feel" +
			 " young and powerful again.");
		force_me("emote chuckles to himself.");
		force_me("say Of course, that's just a feeling. I'm getting too old.");
		break;
	case 3:
		force_me("say One of the toughest battles I ever fought was when I went" +
			 " head to head against this high strung sorceress.");
		force_me("say She almost killed me, too. I still think the only reason" +
			 " I survived was because of those bracers I had found.");
		force_me("emote smiles wistfully at the memory.");
		break;
	case 4:
		force_me("say King Cealith and I go way back. We used to adventure together before he was king.");
		force_me("say When this new town was constructed he gave me a position in" +
			 " the palace.");
		force_me("say I must have saved his life a few dozen times.");
		force_me("emote winks conspiratorially at you.");
		force_me("say Of course, if you hear him tell the stories, it's the other" +
			 " way around.");
		break;
	}
	talking = 0;
	return;
}
