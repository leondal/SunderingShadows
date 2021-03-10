#include <std.h>
inherit NPC;

void make_me();

void create(){
   ::create();
   make_me();
   set_property("official", "Tabor");
   set_body_type("human");
   set_hd(20,8);
   set_size(2);
   set_alignment(8);
   set_overall_ac(-1);
   set_max_hp(random(40)+100);
   set_hp(query_max_hp());
   set_exp(100);
   set_level(20);
   set_class("mage");
   set_mlevel("mage",17);
   set_guild_level("mage",17);
   set_stats("intelligence", 18);
   set_stats("wisdom", 15);
   set_stats("strength", 18);
   set_stats("charisma", 15);
   set_stats("dexterity", 16);
   set_stats("constitution", 15);
   set_mob_magic_resistance("average");
   set_speed(60);
   set_spell_chance(95);
   set_spells(({"lightning bolt","lightning bolt","magic
missile", "hideous laughter","fireball","fireball","cone of cold"}));
}

void init(){
   ::init();
}

void make_me() {
   switch(random(5)) {
      case 0:
         set_nwp("escape",8);
         set_name("Raelzyr");
         set_id(({"Raelzyr","raelzyr","trainer","wanderer"}));
         set_short("Raelzyr, a wanderer");
         set_long("%^RESET%^Raelzyr is a lithe male human that looks to "
	   "be in his early 20's.  He wears a %^BOLD%^%^BLACK%^darkly flowing "
	   "cape %^RESET%^over a pair of tight %^ORANGE%^leather pants %^RESET%^"
	   "and tall %^BOLD%^%^BLACK%^black boots.  %^RESET%^His %^BOLD%^%^BLACK%^"
	   "black hair %^RESET%^is combed back into a low pony tail that is "
	   "tied at the base of his neck, falling down between his shoulder "
	   "blades in curly masses.  His face consists of sharply chiseled "
	   "features and a hook nose that rests between a pair of intense "
	   "%^BOLD%^%^BLUE%^blue eyes.  %^RESET%^He seems to carry very "
	   "little on his person, save for a %^ORANGE%^rope %^RESET%^that "
	   "dangles from his beltline.");
         set_gender("male");
         set_race("human");
         break;
      case 1:
         set_nwp("forage",8);
         set_name("Delai");
         set_id(({"Delai","delai","trainer","wanderer"}));
         set_short("Delai, a wanderer");
         set_long("%^RESET%^Delai is an attractive female half-elf in her "
	   "late 20's.  Long whisps of %^YELLOW%^golden blonde %^RESET%^hair "
	   "fall down around her shoulders, framing her heart shaped face "
	   "and covering all but the tips of her slightly pointed ears.  "
	   "Her eyes are a deep %^BOLD%^%^GREEN%^emerald green %^RESET%^in "
	   "color and compliment her fair features.  Her clothing is simple, "
	   "consisting of a %^GREEN%^forest green %^RESET%^tunic and "
 	   "%^ORANGE%^light brown leggings %^RESET%^that are tucked into "
	   "soft %^ORANGE%^deerskin boots. %^RESET%^A few sacks hang from "
	   "around her belt, and smell of freshly gathered %^MAGENTA%^f%^RED%^"
	   "r%^BOLD%^%^RED%^u%^MAGENTA%^i%^RESET%^%^RED%^t%^MAGENTA%^s "
	   "%^RESET%^and %^BOLD%^%^RED%^b%^RESET%^%^RED%^er%^MAGENTA%^r%^RED%^"
	   "ie%^BOLD%^%^RED%^s%^RESET%^.");
         set_gender("female");
         set_race("half-elf");
      break;
      case 2:
         set_nwp("skinning",8);
         set_nwp("hunting",8);
         set_name("Galdien");
         set_id(({"Galdien","galdien","wanderer","trainer"}));
         set_short("Galdien, a wanderer");
         set_long("%^RESET%^Galdien is a large male human with a bushy "
	   "%^BOLD%^%^RED%^r%^RESET%^%^RED%^e%^BOLD%^%^RED%^d %^RESET%^"
	   "%^RED%^b%^BOLD%^%^RED%^e%^RESET%^%^RED%^a%^BOLD%^%^RED%^r"
	   "%^RESET%^%^RED%^d %^RESET%^and equally %^BOLD%^%^RED%^w"
	   "%^RESET%^%^RED%^i%^BOLD%^%^RED%^ld hair.  %^RESET%^His face "
	   "is tanned from much exposure to the sun, and his %^BOLD%^"
	   "%^BLACK%^g%^RESET%^re%^BOLD%^%^BLACK%^y %^RESET%^eyes "
	   "%^BOLD%^%^WHITE%^sparkle %^RESET%^with humor.  He wears a "
	   "%^RED%^red %^BOLD%^%^RED%^c%^RESET%^%^RED%^h%^BOLD%^%^BLACK%^"
	   "e%^RED%^c%^RESET%^%^RED%^k%^BOLD%^%^BLACK%^e%^RED%^d "
	   "%^BLACK%^flannel shirt %^RESET%^that does nothing to hide "
	   "his large belly, and a pair of %^ORANGE%^brown workman's "
	   "pants %^RESET%^that have a few smears of %^RED%^blood "
	   "%^RESET%^here and there.  A %^BOLD%^%^BLACK%^black knife "
   	   "handle %^RESET%^sticks out of a small sheath worn on his side, "
	   "and many %^ORANGE%^furs %^RESET%^and %^ORANGE%^skins "
	   "%^RESET%^are slung over his broad shoulders.");
         set_gender("male");
         set_race("human");
         break;
      case 3:
         set_nwp("concealment",8);
	 set_nwp("eavesdropping", 8);
         set_name("Kayel");
         set_id(({"kayel","Kayel","wanderer","trainer"}));
         set_short("Kayel, a wanderer");
         set_long("%^RESET%^Kayel is a thin little female woman with "
	   "%^BOLD%^%^BLACK%^long black hair %^RESET%^that is worn in two "
	   "braids reaching down to her mid thighs.  %^BOLD%^%^WHITE%^S"
	   "%^RESET%^i%^BOLD%^%^WHITE%^lv%^RESET%^e%^BOLD%^%^WHITE%^r "
	   "%^RESET%^eyes peer out from underneath perfectly arched "
	   "%^BOLD%^%^BLACK%^brows, %^RESET%^and her hallowed face keeps "
	   "a calm expression.  She wears nothing but %^BOLD%^%^BLACK%^"
	   "form-fitting body armor %^RESET%^tucked into a pair of "
	   "%^BOLD%^%^BLACK%^heeled black boots %^RESET%^that lace up her "
	   "shins.  From her lack of scars and other signs of wear, she "
	   "appears to not have seen many battles.  Her hands are quick, "
   	   "and you sometimes think you catch a glimpse of her hiding "
	   "something on her person.");
         set_gender("female");
         set_race("human");

	case 4:
		set_nwp("disguise",8);
		set_name("adrian");
	set_short("Adrian Brodicus, actor");
	set_id(({"Adrian Brodicus","adrian","brodicus","human","actor"}));
	set_long("%^CYAN%^A regular at the Crown and Castle Inn, "+
		"Adrian Brodicus is a favored thespian.  His "+
		"slender form and good looks have earned him a"+
		" small legion of devoted fans.  With his "+
		"%^ORANGE%^bronzed%^CYAN%^ complexion and "+
		"the classical symmetry of his face, there "+
		"are very few roles that Adrian does not get."+
		"  His %^ORANGE%^dark brown%^CYAN%^ hair is "+
		"combed back from his face, setting off his "+
		"%^BLUE%^stormy blue%^CYAN%^ eyes.  Dressed "+
		"in a %^RED%^red %^CYAN%^brocade vest over "+
		"his %^BOLD%^%^BLACK%^black%^RESET%^%^CYAN%^"+
		" cotton shirt and a pair of stripped %^BOLD%^"+
		"%^BLACK%^black%^RESET%^%^CYAN%^ and %^RED%^red"+
		"%^CYAN%^ velvet leggings, there are few woman "+
		"who don't succumb to the charms of this famous "+
		"actor; on or off stage. ");
	set_gender("male");
	set_race("human");
	set_emotes(4, ({"%^BOLD%^%^RED%^Adrian waves to a group of young fans.","%^BOLD%^%^BLACK%^Adrian bows to kiss the hand of a middle aged noble woman.","%^RED%^Adrian impresses the crowd around him with an impromptu performance.","%^ORANGE%^A young freckled faced girl screams in joy upon seeing Adrian and faints!"}), 0);
	break;
   }    
}     
