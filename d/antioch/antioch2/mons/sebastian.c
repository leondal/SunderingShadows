#include <std.h>
#include "../antioch.h"
#include <daemons.h>

inherit "/std/townsman";

object obj2;
int heals;

void create()
{
	::create();
	set_name("Sebastian");
	set_id(({ "sebastian", "Sebastian", "cleric", "high cleric" }));
	set_short("Sebastian, High Cleric of the Church of Jarmila");
	set_long(
		"Sebastian is the High Cleric of the Church of Jarmila. He is a jolly sort" +
		" of man, round in figure. He is almost six feet tall, and has a slight" +
		" smile always on his face. He is wearing a white robe with the symbol" +
		" of the Lady of Light in the center of it. Simple sandals adorn his feet." +
		" His hair is sandy blonde and kept short. Although he looks a bit like" +
		" a simpleton, there is an aura of power that is almost tangible around" +
		" him."
		);
	set_gender("male");
	set_race("human");
	set_body_type("human");
	set_hd(30, 6);
	set_alignment(2);
	set_diety("jarmila");
	set_max_hp(300 + random(50));
	set_hp(query_max_hp());
	set_overall_ac(-17);
	set_class("cleric");
	set_mlevel("cleric", 30);
	set_level(30);
	set_stats("wisdom", 23);
	set_stats("strength", 15);
	set_stats("intelligence", 18);
	set_stats("constitution", 18);
	set_stats("charisma", 20);
	set_stats("dexterity", 5);
	set_mob_magic_resistance("insanely high");
	set_exp(5000);
	set_max_level(20);
	new("/d/magic/symbols/jarmila_symbol.c")->move(TO);
	set_spells(({
		"limb attack",
		"flame strike",
		"hold person",
		"mystic bolt",
	}));
	set_spell_chance(100);
	set("aggressive", 0);
	heals = 12;
}

void init()
{
	::init();
	if (avatarp(TP) && TP->query_invis()) {
		return 1;
	}
	if (ALIGN->is_evil(TP)) {
		if (TP->query_lowest_level() < 15) {
			force_me("say It is sad that you have chosen the path of evil, but I" +
				 " shall not tolerate your presence in my room.");
			tell_object(TP, "Sebastian shoves you out the door.");
			tell_room(ETP, "Sebastian shoves " + TP->query_cap_name() + " out the door.", TP);
			TP->move_player(ROOMS + "church9");
			return;
		}
		force_me("say Evil is not allowed within these sacred walls! For thy" +
			 " insolence I shall vanquish thee!");
		if (!present("guard", ETO)) {
			call_out("summon_guards", 3);
			write("A bell loudly tolls the alarm.");
		}
		kill_ob(TP, 1);
		return 1;
	}
	if (TP->is_class("cleric") && random(3)) {
		force_me("say I can tell thee about this church if thou art interested.");
		force_me("smile " + TP->query_true_name() + "");
	}
	if ((string)TP->query_diety() != "jarmila" && random(3)) {
		force_me("hmm");
		force_me("say I see that thou doust not serve Jarmila. Perhaps tis not thy" +
			 " calling, but hast thou ever explored the option?");
		return 1;
	}
	if ((string)TP->query_diety() == "jarmila") {
		force_me("say I can sense Jarmila's guidance within thee, tis good to know that" +
			 " there art other disciples who protect this land.");
		return 1;
	}
}

void heart_beat()
{
	::heart_beat();
	if (TO->query_hp() < 125 && heals != 0) {
		new("/cmds/spells/h/_heal")->use_spell(TO, TO->query_name(), 30, 100, "cleric");
		heals -= 1;
		return 1;
	}
}

int summon_guards()
{
	object ob;
	tell_room(ETO, "%^BOLD%^Several guards burst into the room.");
	new(MONS + "guard")->move(ETO);
	new(MONS + "guard")->move(ETO);
	new(MONS + "guard")->move(ETO);
	switch (random(3)) {
	case 0:
		new(MONS + "guard")->move(ETO);
		break;
	case 1:
		new(MONS + "guard")->move(ETO);
		new(MONS + "guard")->move(ETO);
		break;
	case 2:
		new(MONS + "guard")->move(ETO);
		new(MONS + "guard")->move(ETO);
		new(MONS + "guard")->move(ETO);
		break;
	}
	return 1;
}

void catch_say(string message)
{
	call_out("reply_func", 1, message, TP);
}

void reply_func(string message, object who)
{
	object ob;
	if ((mixed *)TO->query_attackers() != ({ })) {
		force_me("say Can't thee see I'm busy fighting here? Maybe thou shouldst" +
			 " give me a hand!");
		return 1;
	}
	if (member_array(who->query_name(), KILLING_D->query_bounties()) != -1) {
		force_me("say Thou hast chosen to break the laws of the land, begone" +
			 " from here lest I see fit to summon the guards to take thee away.");
		return 1;
	}
	if (strsrch(message, "church") != -1 || strsrch(message, "cleric") != -1) {
		if (who->is_class("cleric")) {
			force_me("say This church was built not that long ago by the lesser god" +
				 " Ignatius in gratitude to his goddess for saving him and his city. Here we may" +
				 " still keep an eye on the evil to our east and make sure that it never" +
				 " rises out of hand again.");
			if ((string)who->query_diety() == "jarmila") {
				force_me("whisper " + who->query_name() + " There is a secret entrance from the first floor" +
					 " into a cleric sanctuary. Look to the cross.");
				return 1;
			}
			if (!random(2)) {
				force_me("say Hast thou explored the church yet? Tis a mighty bastion of" +
					 " strength, and we allow clerics of all faiths safe passage within most of" +
					 " these sacred walls. Provided they doust not cause any trouble, of course.");
				force_me("whisper " + who->query_name() + " Many find the basement a calm and relaxing place to unwind.");
				return 1;
			}
			return 1;
		} else {
			force_me("emote rubs his hands delightedly.");
			force_me("say Yes, isn't this a magnificent church?");
			force_me("say It twas built by the lesser god Ignatius in gratitude to his goddess." +
				 " Tis a bastion of strength in these dark times, and tis filled with its own" +
				 " carefully guarded secrets.");
			return 1;
		}
		return 1;
	}
	if (strsrch(message, "jarmila") != -1) {
		if ((string)who->query_diety() == "jarmila") {
			force_me("smile " + who->query_name() + "");
			force_me("say Thou has chosen the true path, I see. Although following Jarmila" +
				 " and Her charge is no easy task, tis well worth the reward.");
			force_me("say This church will provide thee with whatever services and help" +
				 " that it can.");
			return 1;
		} else {
			force_me("say Hast thou come to see the error of thy ways?");
			force_me("say Jarmila is the one and only Lady of Light, but only the worthy" +
				 " may follow Her.");
			force_me("say Thou must show excellence, vigilance, purity and loyalty to be" +
				 " considered for a position among Jarmila's ranks.");
			force_me("say Think about these things, there is much honor and glory in" +
				 " Jarmila's service.");
			force_me("emote smiles smugly.");
			return 1;
		}
	}
	if (strsrch(message, "ruins") != -1) {
		force_me("frown");
		force_me("say There is a great evil that lurks in the ruins still, though much" +
			 " of it is still contained fortunately.");
		return 1;
	}
	if (strsrch(message, "evil") != -1) {
		force_me("say Antioch was once destroyed by great evil, and so we all watch and" +
			 " guard against it.");
		force_me("say Even evil items are dangerous and must be destroyed, if thou" +
			 " doust come across any, give them to me and I shalt destroy them.");
		return 1;
	}
	if (strsrch(message, "demon") != -1) {
		force_me("say Demons are horrible dangerous creatures, and I have heard that" +
			 " there is one that doust dwell in the ruins still. If thou doust find him and" +
			 " vanquish him, I will be happy to cleanse any items he might have for thee.");
		return 1;
	}
}


void receive_given_item(object obj)
{
	string name, *ids;
	object obj2;
	int TSIZE;
	TSIZE = TP->query_size();

	if (!objectp(obj)) return;
	name = obj->query_name();
	if (ALIGN->is_evil(TP)) return;
	if (name == "Nightbringer") {
		obj->remove();
		if (TP->is_class("cavalier") || TP->is_class("paladin")) {
			obj2 = new("/d/antioch/ruins/obj/pearl_lance");
			force_me("say This is an evil weapon of Shar's making. I am glad to see it destroyed.");
			force_me("emote tosses Nightbringer into the %^BOLD%^silver mirror%^RESET%^" +
				 " where it vanishes.");
			force_me("say For thy help in destroying such a foul object, I shalt give" +
				 " thee this %^BOLD%^Pearl Lance%^RESET%^ to aid thee in thy fights. Use it" +
				 " well and honorably.");
			if ((int)obj2->move(TP) != 0) {
				obj2->move(ETO);
				obj2->set_owner(TPQN);
				return 1;
			}else  {
				obj2->move(TP);
				return 1;
			}
		}else  {
			force_me("say This evil mace is one of Shar's making. She has been growing" +
				 " bolder lately and I fear that she is also growing stronger.");
			force_me("emote tosses Nightbringer into the %^BOLD%^silver mirror%^RESET%^" +
				 " where it vanishes.");
			force_me("say Take this %^YELLOW%^Mace of the Heavens%^RESET%^ in its stead," +
				 " may it help thee in thy fight.");
			obj2 = new("/d/antioch/ruins/obj/heavens_mace.c");
			if ((int)obj2->move(TP) != 0) {
				obj2->move(ETO);
				return 1;
			}else  {
				obj2->move(TP);
				return 1;
			}
		}
	}else if (name == "demon heart") {
		obj->remove();
		force_me("say This is the heart of a very powerful and evil demon. For" +
			 " vanquishing it I will give thee this sword as a reward.");
		force_me("emote throws the demon heart into the %^BOLD%^silver mirror%^RESET%^" +
			 " where it vanishes as though thrown into the depths of a bottomless lake.");
		tell_room(ETP, "From the mirror emerges a well-crafted sword of amazing power" +
			  " that moves to " + TP->query_cap_name() + ".", TP);
		tell_object(TP, "From the mirror emerges a well-crafted sword of amazing power," +
			    " it magically levitates towards you.");
		obj2 = new("/d/antioch/ruins/obj/eternity_sword");
		obj2->move(TP);
		obj2->set_owner(TPQN);
		return 1;
	}else if (name == "demonskin boots") {
		obj->remove();
		force_me("emote throws the demonskin boots distastefully into the %^BOLD%^mirror%^RESET%^ where they vanish.");
		force_me("say For bringing me those filthy things I shalt reward thee with this" +
			 " cloak.");
		obj2 = new("/d/antioch/ruins/obj/valor_cloak");
		obj2->set_size(TSIZE);
		obj2->move(TP);
	}else if (name == "Bracers of Doom") {
		obj->remove();
		force_me("say These bracers have been permeated and corrupted by evil! I shalt" +
			 " destroy them for thee.");
		force_me("emote tosses the Bracers of Doom into the %^BOLD%^silver mirror%^RESET%^" +
			 " where they vanish.");
		force_me("say Here are some leggings that may serve thee well in thy fight" +
			 " against evil.");
		obj2 = new("/d/antioch/ruins/obj/leggings");
		obj2->set_size(TSIZE);
		obj2->move(TP);
	}else if (name == "%^BOLD%^%^BLACK%^Armor of Ebony%^RESET%^") {
		obj->remove();
		force_me("emote throws the %^BOLD%^%^BLACK%^Armor of Ebony%^RESET%^ into the" +
			 " %^BOLD%^silver mirror%^RESET%^ immediately.");
		force_me("say The evil in that armor was overwhelming! Here is a set of plate" +
			 " that will serve thee much better.");
		tell_room(ETP, "From the %^BOLD%^silver mirror%^RESET%^ emerges a brilliant set" +
			  " of %^BOLD%^Diamond Fullplate%^RESET%^ armor that hovers before " + TPQCN + ".", TP);
		tell_object(TP, "From the %^BOLD%^silver mirror%^RESET%^ emerges a brilliant set" +
			    " of %^BOLD%^Diamond Fullplate%^RESET%^ armor that hovers before you.");
		obj2 = new("/d/antioch/ruins/obj/diamond_plate");
		obj2->set_size(TSIZE);
		obj2->move(TP);
		obj2->set_owner(TPQN);
	}else if (name == "Gloves of Darkness") {
		obj->remove();
		force_me("say Yes, thou sensed the evil in these gloves just as I did. Although" +
			 " once merely the tools of thieves, these gloves have been corrupted by the" +
			 " evil that wore them for so long.");
		force_me("emote tosses the Gloves of Darkness into the %^BOLD%^mirror%^RESET%^" +
			 " where they vanish.");
		force_me("say Here are some gloves that would serve thee better.");
		obj2 = new("/d/antioch/ruins/obj/neutralgloves");
		obj2->set_size(TSIZE);
		obj2->move(TP);
	}else if (name == "Shadow Bracelets") {
		obj->remove();
		force_me("say Yes, these are horribly tainted by dark magic, or so the stories" +
			 " tell. But from the first they were designed to serve the cause of the light," +
			 " not darkness.");
		force_me("emote tosses the dark bracelets into the mirror, from" +
			 " which a light blue reflection of the bracelets tumbles forth.");
		force_me("say Here are some Bracelets of Power that will serve thee well.");
		obj2 = new("/d/antioch/ruins/obj/bracelets");
		obj2->set_size(TSIZE);
		obj2->move(TP);
	}else if (name == "screamer") {
		obj->remove();
		force_me("say Ahhhh, yes, Archmage Welkanar gave me something just for this occassion.");
		force_me("emote throws the dagger into the %^BOLD%^%^WHITE%^mirror%^RESET%^ where it vanishes.");
		force_me("say Here is the weapon he made along with those fine elves Mithras and Jancarius, and the halfling Tara.");
		obj2 = new("/d/antioch/ruins/obj/diamonddagger")->move(TP);
	}else if (name == "drow mask") {
		obj->remove();
		force_me("say This mask is stinks of evil magic!");
		force_me("emote throws the mask into the %^BOLD%^%^WHITE%^mirror%^RESET%^ where it
vanishes.");
		force_me("say You will find this crystal ball, equally useful, if you need to %^BOLD%^%^YELLOW%^scry%^RESET%^.");
		obj2 = new("/d/antioch/ruins/obj/crystalball")->move(TP);
	}else if (name == "shining longsword") {
		obj->remove();
		force_me("say This is a fine weapon, but thou doust not want it? I can tell it" +
			 " has had the hand of evil upon it, but tis not tainted.");
		force_me("emote puts the Starlight Sword in a large chest.");
		force_me("say Here is another weapon that might suit thee better, it is called" +
			 " Hammer of the Crimson Blaze.");
		obj2 = new("/d/antioch/ruins/obj/hammer");
		if ((int)obj2->move(TP) != 0) {
			obj2->move(ETO);
			return 1;
		}else  {
			obj2->move(TP);
		}
	}else  {
		ids = obj->query_id();
		force_me("say I'm sorry, I have no need of this item.");
		force_me("drop " + ids[0]);
		return 1;
	}
}
