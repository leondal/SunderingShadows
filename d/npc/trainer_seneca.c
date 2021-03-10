// random high level trainer type to wander in Seneca by *Styx*  8/2002
// add others as the nwps go in?
// moved to /d/npc/ dir & renamed file 12/21/03 *Styx*

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
//   "daemon/place_d"->place_in("/d/attaya/seneca/",TO);
}

void init(){
   ::init();
}

void make_me() {
   switch(random(5)) {
     case 0:
        set_nwp("escape", 20, 500);
        set_nwp("concealment", 20, 500);
   	set_name("Durita");
	set_id(({"durita","Durita","trainer"}));
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
	set_id(({"steinsal","Steinsal","trainer"}));
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
	set_id(({"tharstan","Tharstan","trainer"}));
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
	set_id(({"duerstan","Duerstan","trainer"}));
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
	set_id(({"maestrala","Maestrala","trainer"}));
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
	set_nwp("disguise",20, 500);
	set_name("razarthan");
	set_short("Razarthan Bel'Jance, famed thespian");
	set_id(({"Razarthan","Razarthan Bel'Jance","bard"}));
	set_long("%^CYAN%^Hailing from deep within the "+
		"Tsvaren Empire, Razarthan Bel'Jance has "+
		"found fame and fortune in the northern "+
		"lands.  Known for his almost chameleon "+
		"like skill to morph into any role, Razarthan"+
		" has become on of the most famous thespians "+
		"in the lands.  Dressed in a %^ORANGE%^dark "+
		"orange%^CYAN%^ silk robe embroidered with "+
		"images of sphinxes, this swarthy skinned male"+
		" still dresses in the typical regalia of the "+
		"Tsvaren Empire.  %^RED%^Dark red%^CYAN%^ silk "+
		"leggings are worn under his lavish robe.  A "+
		"brocade silk turban rests on his head, "+
		"covering nearly all of his coal black hair. "+
		" In typical Tsvaren fashion, his eyes are lined"+
		" with kohl, a black cosmetic that draws attention"+
		" to their sandy brown color.  His clothing and skin"+
		" is infused with a warm rich spicy cologne.  ");
	set_gender("male");
	set_race("human");
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