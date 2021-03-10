//New baker for Synoria - Cythera 7/05
#include <std.h>
#include "../elfisland1.h"

inherit BARKEEP;

void create() {
   	object obj;
	::create();
	set_name("alleteirana");
   	set_short("Alleteirana Willowbrook");
   	set_id( ({"alleteirana","willowbrook","baker","elf"}) );
   	set_long(
       "%^RESET%^Dressed in shades of %^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^r"+
       "e%^BOLD%^e%^RESET%^%^GREEN%^n%^RESET%^, Alleteirana's %^ORANGE%^"+
       "coppery%^RESET%^ hair almost seems to blaze.  This slender female"+
       " elf came into ownership of the bakery when her cousin mysteriously"+
       " vanished.  Her bronze skin and copper hair reveals her wood elf "+
       "heritage.  %^BOLD%^%^GREEN%^Leaf green%^RESET%^ eyes shine brightly"+
       " against her smooth flesh, mirroring the verdant greens of her gown."+
       "  The warm aroma of fresh %^YELLOW%^baked bread%^RESET%^, "+
       "%^ORANGE%^vanilla%^RESET%^, and %^RED%^cinnamon%^RESET%^ scent "+
       "the air around her.  There almost seems to be something very "+
       "mystical about this elven woman.");
   set_race("elf");
   set_body_type("elf");
   set_gender("female");
   set_hd(19,1);
   set("aggressive","kill_evil");
   add_money("gold",random(100));
   set_alignment(4);
   set_max_hp(245);
   set_languages( ({ "elven" }) );
   command("speak elven");
   set_hp(245);
   set_exp(10);
	obj=new("/d/darkwood/yntala/obj/forestdress1.c");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	new("/d/common/obj/rand/r_shoes.c")->move(TO);
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	new("/d/darkwood/camps/obj/leafanklets.c")->move(TO);
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	command("wearall");
   remove_std_db();
//   set_random_act_db("austusrandom");
//removing the above database because it is not only out of
//date, but it also refers to the speaker as a he, which she
//is clearly not :) ~Circe~ 12/1/07
   set_random_act_chance(5);
   set_currency("electrum");
   set_property("swarm",0);
   set_menu(
      ({"water","ice tea","nectar","herbal tea","feywine","elverquisst",
        "cucumber salad","fruit cup","elven waybread","peach cobbler",
        "slice of cherry pie","large wildberry muffin",
        "leek and wild mushroom soup",
	  "flatbread rolls","smoked boar"}),
      ({"water","soft drink","soft drink","soft drink",
        "alcoholic","alcoholic",
        "food","food","food","food","food","food","food","food","food"}),
      ({1, 3, 3, 5, 100, 200, 5, 5, 18, 5, 7, 18, 20, 30, 40})
    );
    set_my_mess(
    ({
       	"%^BOLD%^%^CYAN%^You drink a glass of water.%^RESET%^",
      	"%^ORANGE%^The cool refreshing taste of the ice tea "+
			"sooths your throat.%^RESET%^",
       	"%^YELLOW%^The fragrant nectar is sweetened with honey"+
		" and flowers.%^RESET%^",
       	"%^MAGENTA%^The herbal tea goes down smooth and relaxes "+
			"your senses.%^RESET%^",
      	 "%^BOLD%^%^MAGENTA%^You drink the feywine and feel an "+
			"almost magical, blissful peace wash %^BOLD%^%^MAGENTA%^"+
			" over you as your skin starts to tingle all over. The "+
			"glass almost slips from your hands as you hear a faerie"+
			" giggling in your ear. You set the glass down, letting "+
			"the wine take full effect.",
       	"%^BOLD%^%^RED%^With each sip of the magicaly distilled ruby colored "+
			"drink you taste the full effect of a different fruit."+
			" As the smooth drink runs down your throat you"+
       		" almost feel like you are slipping from your body and"+
			" becomming weightless.%^RESET%^",
       	"%^GREEN%^You eat the salad and feel full of energy.%^RESET%^",
       	"%^YELLOW%^The combination of fruits makes for a tasty snack.%^RESET%^",
       	"%^ORANGE%^You bite into the elven waybread and enjoy the filling"+
			" taste of fresh cooked bread.%^RESET%^",
       	"%^ORANGE%^You savor the sweetness of the peach cobbler.%^RESET%^",
       	"%^RED%^The sweet but tart cherries seem to almost blossom in your"+
			" mouth as you bite into the pie.",
		"%^MAGENTA%^The flavors of fresh raspberries, blackberries, "+
		"strawberries, and blueberries seem to bloom in your mouth as"+
		" you eat the fresh baked muffin.",
		"%^ORANGE%^The fresh leeks and roasted wild mushrooms blend in"+
		" perfect harmony with the fresh herbs used in the soup's base.",
		"%^YELLOW%^Grilled vegetables are rolled up with rice and cheese"+
			" in the flatbread, making for a delightful feast!",
		"%^RED%^The smoked boar has a mild but complex rub to it."
    })
    );
    set_your_mess(
    ({
        "drinks a glass of water.",
        "enjoys glass of ice tea.",
        "sighs as they sip the nectar.",
        "sighs softly after a cup of herbal tea.",
        "is overcome with an expression of peace and smiles softly.",
        "gets a distant look in the eyes while enjoying the Elverquisst.",
         "looks energetic after eating the salad.",
        "looks pleased with the fresh fruit.",
        "takes delight in the smell of the bread before eating it all.",
        "eats all the peach cobbler and looks pleased.",
         "scarfs down the entire slice of pie.",
	  "oohs and ahhhs in response to the flavors of the large muffin.",
	  "eats the soup with gusto, enjoying the blend of herbs, leeks, and wild mushrooms.",
	  "munches on the flatbread roll.",
	  "saviors the smoked boar."
    })
    );
    set_menu_short(
    ({
       "A glass of water",
       "A glass of ice tea",
       "A glass of nectar",
       "A cup of herbal tea",
       "A glass of Feywine",
       "A glass of Elverquisst",
       "A bowl of salad",
       "A cup of cut fruit",
       "A loaf of elven waybread",
       "A cup of peach cobbler",
       "A slice of cherry pie",
       "A large wildberry muffin",
	 "A bowl of leek and wild mushroom soup",
	 "A filled flatbread rolled up",
	 "A select slices of smoked boar"
    })
    );
    set_menu_long(
    ({
       "This is a tall glass of crisp spring water.",
       "This is a nice tall glass of ice tea sweetened with honey.",
       "This is fragrant cup of nectar.",
       "This is a cup of hot fragrant herbal tea.",
       "The feywine comes up the halfway mark in this tall wine glass.",
       "This is wine glass, filled with a ruby colored substance.",
       "This is a bowl of mixed greens tossed with tomatoes and cucumbers.",
       "This is a bowl of fresh fruit that have been cut into cubes.",
       "This is a loaf of freshy baked elven waybread.",
       "This is a cup of recently made peach cobbler.",
       "This is a slice of pie that is over running with cherries.",
	 "This large muffin is stuffed full of fresh raspberries, "+
		"blueberries, blackberries and strawberries.  A crumble"+
		" top adds even more sweetness to the delicious muffin.",
	"This wooden bowl is filled with fresh leeks and roasted wild "+
		"mushrooms in a clear broth.  The broth has been flavored"+
		" with a few fresh herbs that blend in harmony with the "+
		"rest of the soup.",
	"Served on a wooden plate, the grilled flatbread is filled with"+
	" rice, grilled vegetables, and fresh cheese.  Lightly spiced, "+
	" tempting aromas rise off this treat!",
	"Select slices of smoked boar are served on a bed of greens."+
	"  The boar is rubbed with a light, but complex mixture of spices."+
	"  The salad of greens is crisp and light, served with a tangy dressing."
    })
    );
}

void init() {
   ::init();
   if( (string)TP->query_name() == "raider") {
      command("yell %^BOLD%^%^GREEN%^Someone help!%^RESET%^");
      command("kill raider");
   }
}

void kill_evil() {
   string race;
   race = TP->query_race();
      if( race == "drow" || race == "half-drow" || race == "goblin" || race == "hobgoblin" ||
      race == "orc" || race == "half-orc" || race == "ogre" || race == "half-ogre" ||
      race == "kobold" || race == "ogre-mage" || race == "bugbear" || race == "wemic" ||
      race == "gnoll") {
   force_me("yell %^BOLD%^%^GREEN%^Someone help me!%^RESET%^");
   force_me("kill "+TP->query_name());
   return;
   }
}


void heart_beat() {
   object ob,*killers;
   int i;
   ::heart_beat();
   if(!objectp(TO) || !objectp(ETO)) return;
   if(present("guard 2",ETO)) return;
   if(query_hp() < 245) {
   command("yell HELP!!");
   tell_room(ETO,"You see a guard rush in to help the baker.");
   ob = new(MON+"elguard");
   ob->move(ETO);
   ob->set_stats("strength",18);
   ob->set_exp(3500);
   ob->force_me("block out");
   ob->force_me("protect alleteirana");
   ob->force_me("protect alleteirana");
   ob->force_me("protect alleteirana");
   ob->force_me("yell I will protect our people!");
   killers = query_attackers();
   for(i=0;i<sizeof(killers);i++){
      ob->kill_ob(killers[i],1);
   }
   }
}
