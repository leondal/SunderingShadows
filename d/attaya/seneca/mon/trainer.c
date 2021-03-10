// random high level trainer type to wander in Seneca by *Styx*  8/2002
// add others as the nwps go in?
//added studying trainer.  Circe 5/23/04
#include <std.h>

inherit NPC;

void make_me();

void create(){
   ::create();
   make_me();
   set_body_type("human");
   set_hd(30,15);
   set_max_level(30);
   set_size(2);
   set_alignment(8);
   set_overall_ac(0);
   set_max_hp(random(20)+260);
   set_hp(query_max_hp());
   set_exp(100);
   set_level(30);
   set_class("mage");
   set_mlevel("mage",30);
   set_guild_level("mage",30);
   set_stats("intelligence", 18);
   set_stats("wisdom", 15);
   set_stats("strength", 18);
   set_stats("charisma", 15);
   set_stats("dexterity", 16);
   set_stats("constitution", 15);
   set_mob_magic_resistance("average");
   set_property("full attacks",1);
   set_property("alignment adjustment",-5);
   add_money("electrum",random(500));
   set_speed(80);
   set_spell_chance(90);
   set_spells(({"hold person","powerword stun","hold person","lightning bolt", "magic missile", "meteor swarm"}));
   "daemon/place_d"->place_in("/d/attaya/seneca/",TO);
}

void init(){
   ::init();
}

void make_me() {
   switch(random(6)) {
     case 0:
        set_nwp("escape", 20, 500);
        set_nwp("concealment", 20, 500);
   	set_name("Durita");
	set_id(({"durita","Durita","trainer","wanderer"}));
	set_short("Durita, a wanderer");
	set_long("Durita appears to be middle-aged even for a half-elf "
	   "and carries herself with a confidence that belies her look "
	   "of a common traveler.  She carries a silk rope tied to her "
	   "belt and her lithe build and graceful movement indicate she's "
	   "very nimble.  Her clothing is rather simple although somewhat "
	   "loose-fitting.  Oddly enough, she seems to carry very little "
	   "else.");
	set_gender("female");
	set_race("half-elf");
        break;
     case 1:
        set_nwp("healing mount", 20, 500);
   	set_name("Steinsal");
	set_id(({"steinsal","Steinsal","trainer","wanderer"}));
	set_short("Steinsal, a wanderer");
	set_long("Steinsal is a large man with dark brown hair and "
	   "intense green eyes.  He wears a backpack that smells of "
	   "ointments and has rolls of bandages hanging from it.  "
	   "He is dressed simply but wears sturdy heavily oiled "
	   "leather boots and has a pair of heavy gloves sticking "
	   "out of his pocket.  The leather chaps on his thighs are "
	   "well worn and have marks that look like hoofprints on them.");
	set_gender("male");
	set_race("human");
        break;
     case 2:
        set_nwp("skinning", 20, 500);
   	set_name("Tharstan");
	set_id(({"tharstan","Tharstan","trainer","wanderer"}));
	set_short("Tharstan, a wanderer");
	set_long("Tharstan appears to have spent most of his life "
	   "outdoors and you might guess that would be at least forty "
	   "or fifty years from his weatherworn skin and graying hair.  "
	   "His thick, unkempt curly beard is laced with gray as well.  "
	   "He wears simple leather clothing with a pouch around his "
	   "waist and some furs hanging from his belt.  You see the "
	   "hilt of what looks to be a very sturdy looking knife "
	   "sticking out of a small sheath tied on his thigh.");
	set_gender("male");
	set_race("human");
        break;
     case 3:
        set_nwp("hunting", 20, 500);
	set_nwp("tracking", 20, 500);
   	set_name("Duerstan");
	set_id(({"duerstan","Duerstan","trainer","wanderer"}));
	set_short("Duerstan, a wanderer");
	set_long("Duerstan is dressed in leather breeches, a doeskin "
	  "shirt, and wears knee high boots that look like they've seen "
	  "their share of woodland brambles and other rough terrain.  "
	  "He has a bow slung over his shoulder and wears a sheath on "
	  "his hip that looks like it might contain a sword of some "
	  "sort.  A forest green bandana is wrapped around his head and "
	  "looks like it might make good camoflauge in the woods with "
	  "his curly dark brown hair peeking out and covering his neck.");
	set_gender("male");
	set_race("human");
        break;
        
    case 4:
//        set_nwp("fast talking", 20, 500);  // T didn't want this one in yet
        set_nwp("eavesdropping", 20, 500);
   	set_name("Maestrala");
	set_id(({"maestrala","Maestrala","trainer","wanderer"}));
	set_short("Maestrala, a wanderer");
	set_long("Maestrala is a tall, lean, and well-proportioned lady.  "
	   "Her dark hair falls becomingly to her shoulders, framing "
	   "and flattering the delicate features of her face.  She is "
	   "dressed in well-fitted, rather revealing studded leather "
	   "armor.  Small heavily jeweled sheaths are strapped to her "
	   "thighs.  She wears several rings, bracelets, and other "
	   "jewelry, but all in such a way that it doesn't make a "
	   "sound when she moves.  She wears a dark flowing, floor "
	   "length cloak and dark boots that would easily cover the "
	   "gems and her fair skin to let her blend into the shadows.");
	set_gender("female");
	set_race("human");
        break;
    case 5:
      set_nwp("studying", 20);
   	set_name("Aidan");
	set_id(({"aidan","Aidan","trainer","wanderer"}));
	set_short("Aidan, a loremaster");
	set_long("%^RESET%^%^CYAN%^Aidan is an aged elf who has "+
         "spent his entire life studying every piece of lore he "+
         "could find.  An adventurer in his younger days, he now "+
         "makes Seneca his home, wandering the streets and "+
         "conversing with the brave souls who travel the realms.  "+
         "He is said to have more knowledge than most anyone else "+
         "in the realms, though this is hard to ascertain.  He "+
         "moves with the unbelievable elven grace, most unlike "+
         "humans who have dedicated their lives to studying, and "+
         "he is dressed simply in flowing linen robes that seem to "+
         "shift natural shades of green, yellow, and brown.");
	set_gender("male");
	set_race("elf");
        break;
   }    
}     
     
void move_around() {
   string *exits;
   string exitn;
   int j;

   if(!this_object()) return;
   if(!objectp(ETO)) return;
   ETO->setupExits();
   if(query_current_attacker()) return;
   if(environment(this_object()))
      exits = environment(TO)->query_exits();
   if(sizeof(exits)){
      j = random(sizeof(exits));
      exitn = (string)environment(TO)->query_exit(exits[j]);
      if(exitn != "/d/attaya/seneca3") {
         exitn->init();
         TO->force_me(exits[j]);
      }
   }
   moving=0;
}