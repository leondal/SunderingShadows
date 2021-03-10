//minor bug fixed by Circe 10/26/03.  Her command was set to "speak purr" instead of "speech purr", making her unintelligible
#include <std.h>
#include "../juran.h"
inherit BARKEEP;

object ob;
int timer;

void create(){
	::create();
	set_name("Sherilinn");
	set_short("%^BOLD%^%^RED%^Sheri%^RESET%^%^RED%^l%^RED%^i%^BOLD%^%^RED%^n%^RESET%^%^RED%^n%^BOLD%^%^RED%^,%^RESET%^%^MAGENTA%^ the bartender");
	set_body_type("humanoid");
	set_id(({"monster","barmaid","Sherilinn","sherilinn","sheri","Sheri","bartender"}));
	set_long(
		"%^MAGENTA%^Sherilinn is a beautiful, voluptuous rakshasa. She appears to be a tiger in human form as do all of these evil spirits. She is attired in gauzy strips of colorful cloth and a turban much as you would find in the city of Ahza. Smiling with very sharp teeth it is hard to determine whether she is being friendly or sizing you up as she moves with the amazing grace of her kind about the room. Her prices are cheap, but then again...you get what you pay for."
	);
	set_race("rakshasa");
	set_gender("female");
	set_hd(20,2);
	set("aggressive",0);
     	set_property("swarm",1);
	add_money("gold",random(100));
  	set_property("no attack",1);
  	set_property("no bump", 1);
  	set_property("strength","spells");
	set_alignment(9);
  	set_stats("intelligence",19);
  	set_stats("wisdom",16);
  	set_stats("strength",16);
  	set_stats("charisma",20);
  	set_stats("dexterity",19);
  	set_size(2);
  	set_stats("constitution",16);
  	set_class("mage");
  	set_guild_level("mage",20);
  	set_mlevel("mage",20);
  	set_overall_ac(0);
	set_max_hp(200);
	set_hp(200);
	set_exp(1000);
    	set_spell_chance(75);
  	set_spells(({
  		"powerword stun",
  		"hideous laughter",
  		"lightning bolt",
  		"magic missile",
  		"vampiric touch",
  		"monster summoning i"
  	}));
  	set_size(2);
  	set_emotes(0,({
    		"%^BOLD%^%^RED%^Sherilinn purrs%^RESET%^: What can I interest you in?",
    		"%^BOLD%^%^RED%^Sherilinn purrs%^RESET%^: You are very "+
    			"attractive.\nSherilinn purrs.",
    		"%^BOLD%^%^RED%^Sherilinn purrs%^RESET%^: I think you're just my type.",
    		"%^BOLD%^%^RED%^Sherilinn purrs%^RESET%^: This your first time here?.",
    		"Sherilinn watches you hungrily.",
    		"Sherilinn slams a tray upside the head of a too friendly patron.",
    		"Sherilinn purrs contentedly."
    	}), 0);
  	set_emotes(0, ({
    		"%^BOLD%^%^RED%^Sherilinn hisses%^RESET%^: Bad move morsel...I'll "+
    			"kill you for that!",
    		"%^BOLD%^%^RED%^Sherilinn hisses%^RESET%^: Run!  At least make this fun for me!",
    		"%^BOLD%^%^RED%^Sherilinn hisses%^RESET%^: I will dine on your soul!",
    		"Sherilinn's tail twitches excitely."
    	}), 1);
	remove_std_db();
  	ob=new("/d/shadow/obj/armor/robe.c");
  	ob->set_short("A gauzy colorful robe");
  	ob->set_long("This robe is made up of many thin strips of colorful "+
  		"material loosely connected and barely covering normally hidden "+
  		"parts of the wearer's anatomy.");
  	ob->move(TO);
  	command("wear robe");
	command("speech %^BOLD%^%^RED%^purr%^RESET%^");
	set_currency("electrum");
	set_menu(
	({"muddy water","clean water","sulfur fizz","grin burn","blood wine","orcish swill","bread","halfling stew","dwarf kabobs","elf ribs","rat roast","sprite legs","shroom salad","fried lizard legs","glowfish taco","dark steak"}),
	({"water","water","soft drink","alcoholic","alcoholic","alcoholic","food","food","food","food","food","food","food","food","food","food"}),
	({5,10,10,15,20,25,10,25,15,35,50,20,30,25,20,50}),
	);

set_my_mess( ({
"You drink a glass of muddy water, it has a metallic taste.",
"You drink a glass of water.",
"The bubbles tickle your throat as you drink the sulfur laden drink.",
"You chug down the liquid and realize why it is called grin burn. Your face feels like it has open wounds.",
"You drink the warm thick red wine savoring the flavor.",
"You choke down what passes for orcish beer.",
"You eat the stale hard bread.",
"You eat the thick meaty stew. Halflings cook up real nice.",
"You devour dwarvish meat on a stick and toss the stick aside.",
"You eat the barbequed elf ribs, making a complete mess in the process.",
"The rat roast is delicious and tender, practically falling apart in your mouth.",
"The chocolate covered sprite legs have just the right amount of sweet and crunch as you hungrily devour them.",
"You find it hard to figure out which color of mushrooms that you favor, and it's gone before you can decide.",
"Pinching the two halves together and cupping the back of the taco with your palm, you take measured bites until it's gone.",
"The spicy spore flour has been fried into the skin, leaving you satisfied, but a bit thirsty.",
"Your mouth fills with a perfectly seared meaty flavor... with a surprising hint of mushroom.",
}) );

set_your_mess( ({
"guzzles a glass of muddy water.\n",
"guzzles a glass of water.\n",
"guzzles a bubbling glass of liquid that smells like brimstone.\n",
"coughs and sputters as the burning liquid is swallowed.\n",
"savors a glass of blood wine.\n",
"gulps down a mug of orchish ale.\n",
"eats a large piece of stale crunchy bread.\n",
"eats a bowl of thick halfling stew.\n",
"chows down on dwarf meat skewered on a stick.\n",
"manages to make a huge mess while eating the elf ribs.\n",
"enjoys the large rat roast.\n",
"devours the chocolate covered sprite legs hungrily.\n",
"seems to contemplate each mushroom in the salad, yet manages to clean the bowl swiftly.\n",
"seems to savor the crispy meat, but you can smell the spice from here.\n",
"expertly handles the taco, bite by fishy bite.\n",
"bites into the steak and tears off chunk by chunk, leaving only a pool of mushroom juice behind.\n",
}) );

set_menu_short( ({
"%^RESET%^%^ORANGE%^a glass of muddy water%^RESET%^",
"%^RESET%^%^CYAN%^a glass of water%^RESET%^",
"%^BOLD%^%^WHITE%^a tall bubbling drink%^RESET%^",
"%^BOLD%^%^RED%^a glass of an unknown red liquid%^RESET%^",
"%^RESET%^%^MAGENTA%^a glass of blood wine%^RESET%^",
"%^RESET%^%^ORANGE%^a mug of orcish ale%^RESET%^",
"%^RESET%^%^WHITE%^a thick slab of stale hard bread%^RESET%^",
"%^RESET%^%^ORANGE%^a bowl of thick stew%^RESET%^",
"%^RESET%^%^ORANGE%^a stick filled with skewered meat%^RESET%^",
"%^BOLD%^%^RED%^a plate full of juicy elf ribs%^RESET%^",
"%^RESET%^%^ORANGE%^a large rat roast%^RESET%^",
"%^BOLD%^%^BLACK%^a serving of chocolate covered sprite legs%^RESET%^",
"%^BOLD%^%^BLACK%^a bowl of shroom salad%^RESET%^",
"%^RESET%^%^GREEN%^some fried lizard legs%^RESET%^",
"%^YELLOW%^a fresh fish taco%^RESET%^",
"%^RESET%^%^ORANGE%^a delicious dark red steak%^RESET%^",
}) );

set_menu_long(({
"%^RESET%^%^ORANGE%^This is a glass of %^BOLD%^%^BLACK%^muddy water%^RESET%^%^ORANGE%^. It can be refreshing after a long day if you don't mind the stuff that's floating in it, or the %^RED%^metallic %^ORANGE%^taste.%^RESET%^",
"%^RESET%^%^CYAN%^This is a glass of %^BOLD%^water%^RESET%^%^CYAN%^, clear and fresh. It should sate your thirst.%^RESET%^",
"%^YELLOW%^This is a tall glass of clear b%^RESET%^u%^ORANGE%^b%^BOLD%^bli%^RESET%^n%^YELLOW%^g l%^RESET%^i%^ORANGE%^q%^BOLD%^ui%^RESET%^d%^YELLOW%^. The bartender calls it a 'soda', but it is %^RESET%^y%^ORANGE%^e%^BOLD%^llow%^RESET%^i%^ORANGE%^s%^WHITE%^h %^ORANGE%^b%^BOLD%^r%^RESET%^o%^ORANGE%^w%^BOLD%^n and smells like sulfur.%^RESET%^",
"%^BOLD%^%^RED%^This is a glass of %^RESET%^%^RED%^red liquid %^BOLD%^the makes your nose hairs curl as you sniff it.%^RESET%^",
"%^RESET%^%^MAGENTA%^This is a glass of %^RED%^blood wine%^MAGENTA%^. It is very thick and %^RED%^red %^MAGENTA%^and is served %^BOLD%^warm%^RESET%^%^MAGENTA%^. The aroma of this drink makes your mouth water.%^RESET%^",
"%^RESET%^%^ORANGE%^This is a mug of orcich ale. Orcs are not renowned for their beer making ability, prefering to steal what they can from dwarves... but this it what happens when they run out.%^RESET%^",
"%^BOLD%^%^WHITE%^This is a thick slab of %^RESET%^hard %^ORANGE%^stale %^WHITE%^bread%^BOLD%^. Maybe you better soak it a bit before you chip a tooth.%^RESET%^",
"%^RESET%^%^ORANGE%^This is a very thick %^BOLD%^%^BLACK%^stew%^RESET%^%^ORANGE%^. It has some %^GREEN%^v%^BOLD%^e%^RESET%^%^ORANGE%^g%^GREEN%^etabl%^BOLD%^e%^RESET%^%^GREEN%^s %^ORANGE%^in it, you can make out the %^BOLD%^%^RED%^carrots %^RESET%^%^ORANGE%^and %^WHITE%^potatoes %^ORANGE%^quite easily, along with some other %^GREEN%^green vegetables %^ORANGE%^that are probably supposed to be good for you. The meat comes from tender young %^BOLD%^%^BLACK%^halflings %^RESET%^%^ORANGE%^and was simmered so that the stew has a nice home-spun taste.%^RESET%^",
"%^BOLD%^%^BLACK%^This it a stick with skewered meat. The meat tastes like %^RESET%^%^ORANGE%^dwarf %^BOLD%^%^BLACK%^and has been roasted over an open %^RED%^fl%^RESET%^%^ORANGE%^a%^RED%^m%^BOLD%^e %^BLACK%^with secret spices added.%^RESET%^",
"%^BOLD%^%^RED%^This plate is piled high with %^RESET%^%^ORANGE%^juicy elf ribs%^BOLD%^%^RED%^, smeared in %^RESET%^%^RED%^barbeque sauce%^BOLD%^. They look great, and you can't wait to sink your teeth into them.%^RESET%^",
"%^BOLD%^%^BLACK%^This is a large %^RESET%^%^ORANGE%^rat roast %^BOLD%^%^BLACK%^that has been baking in the oven until it was perfectly tender. Some %^RED%^carrots %^BLACK%^and %^RESET%^potatoes %^BOLD%^%^BLACK%^are on the plate around it, but this looks like a meal that could fill up almost anyone and only the best %^RESET%^%^ORANGE%^rats were %^BOLD%^%^BLACK%^used!%^RESET%^",
"%^RESET%^%^ORANGE%^The %^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^h%^BOLD%^%^BLACK%^ocol%^RESET%^%^ORANGE%^at%^BOLD%^%^BLACK%^e c%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^ver%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^d %^MAGENTA%^sprite legs %^RESET%^%^ORANGE%^make you drool just by looking at them.  There are many in the serving, surely enough to fill your sweet tooth.%^RESET%^",
"%^BOLD%^%^GREEN%^No mere vegetable salad could match the beauty of the variety of %^BLACK%^c%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^l%^RESET%^%^GREEN%^o%^MAGENTA%^r%^BOLD%^%^BLACK%^f%^RESET%^%^CYAN%^ul %^GREEN%^s%^BOLD%^%^BLACK%^hr%^RESET%^%^CYAN%^o%^GREEN%^o%^MAGENTA%^m%^BOLD%^%^BLACK%^s %^GREEN%^in this bowl.%^RESET%^",
"%^GREEN%^Thicker than sprite legs and crispier, these haunches have a surprising %^BOLD%^kick %^RESET%^%^GREEN%^to them.%^WHITE%^",
"%^YELLOW%^As the name suggests, %^BLACK%^spore flour tortillas %^ORANGE%^cradle small stips of slightly %^GREEN%^glowing fish %^ORANGE%^flesh and shredded %^BLACK%^mushrooms %^ORANGE%^and %^RESET%^%^ORANGE%^roots%^BOLD%^.%^RESET%^",
"%^RED%^This %^BOLD%^%^BLACK%^dark red steak %^RESET%^%^RED%^is thick and juicy.%^WHITE%^",
}));
}
void init(){
    	::init();
}
void eat_em(object targ){
	command("emote looks thoughtfully at the passed out patron.");
	command("emote leaps over the bar and pounces on "+targ->query_name()+".");
	command("emote licks her lips hungrily and looks around the room.");
	command("drag "+targ->query_name());
	command("emote leaps behind the counter and disappears.");
	TO->move(JROOMS+ "inn_cellar");
	command("drop "+targ->query_name());
	command("emote %^BOLD%^%^RED%^smiles then plunges her dagger into the "+
		"base of "+targ->query_cap_name()+"'s skull!%^RESET%^");
	set_property("magic",1);
	targ->do_damage("torso",1000);
	set_property("magic",-1);
	targ->add_attacker(TO);
	targ->continue_attack();
	command("get coins from corpse");
	command("up");
	command("emote licks her fingers contentedly.");
	command("say yummy.");
}
void kill_em(object targ){
	command("emote looks thoughtfully at the passed out patron.");
	command("emote leaps over the bar and pounces on "+targ->query_name()+".");
	command("drag "+targ->query_name());
	command("emote runs back behind the bar with her prey.");
	command("say not very tasty so I will just dispose of this trash.");
	TO->move(JROOMS+ "inn_cellar");
	command("drop "+targ->query_name());
	command("emote %^BOLD%^%^RED%^smiles then plunges her dagger into the "+
		"base of "+targ->query_cap_name()+"'s skull!%^RESET%^");
	set_property("magic",1);
	targ->do_damage("torso",1000);
	set_property("magic",-1);
	targ->add_attacker(TO);
	targ->continue_attack();
	command("get coins from corpse");
	command("up");
	command("emote dusts off her hands and chuckles to herself.");
}
void rob_em(object targ){
	command("emote looks thoughtfully at the passed out patron.");
	command("emote leaps over the bar and pounces on "+targ->query_name()+".");
	command("emote chuckles to herself.");
	command("strip "+targ->query_name()+" of money");
	command("emote casually walks back behind the bar counting her new coins.");
	command("emote looks at you and smiles devilishly.");
	command("say for the bill of course and, also, room and board.");
	command("emote laughs wickedly.");
}

int do_check(){
    	int i;
    	object *people, *list, person;
	string mrace, srace;
     	people = ({});
    	list = ({});

    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(TO->query_current_attacker()) return 1;

    	people = all_living(environment(this_object()));

    	for(i=0;i<sizeof(people);i++){
		if(!((people[i] == TO) || (wizardp(people[i]))))
	  		list += ({people[i]});
      }
	if(!list || !sizeof(list)) return 2;

	person = list[random(sizeof(list))];

	if(!present(person, ETO)) return 1;

	if(person->query_unconscious()){
		if(person->query_bound())return 1;
		mrace = person->query_race();
		srace = person->query("subrace");
		if (	mrace == "elf" || mrace == "human" ||
			mrace == "halfling" || mrace == "half-elf"){
	    		call_out("eat_em", 1, person);
		}else if((mrace == "dwarf" && srace != "gray dwarf") || mrace == "beastman"){
			call_out("kill_em", 1, person);
		}else call_out("rob_em",1,person);
	}
	return 1;
}
void heart_beat(){
    	::heart_beat();
    	timer++;
    	if(timer > 10){
      	timer = 0;
      	do_check();
    	}

}
