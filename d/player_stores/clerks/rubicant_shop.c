#include <std.h>

#define RSHOP "/d/player_stores/rubicant/"
#define MAX_ITEMS 10

inherit "/std/vendor_pstore";

create() {
  ::create();
   set_shop(RSHOP+"shop_main");
   set_hd(28,2);
   set("aggressive", 0);
   set_level(29);
   set_gender("female");
   set_class("mage");
   set_mlevel("mage", 35);
   set_guild_level("mage",35);
   set_race("human");
   add_money("gold", random(500));
   set_body_type("human");
   set_mob_magic_resistance("average");
   set_overall_ac(-9);
   set_stats("strength",18);
   set_max_hp(250+random(50));
   set_hp(query_max_hp());
   set_exp(100);
   set_spell_chance(95);
   set_spells(({"lightning bolt", "lightning bolt", "hold person", "powerword stun", "magic missile", "magic missile", "wall of fire", "phantom guardians", "prismatic spray", "sonic orb" }));
   make_me();
   new("/d/player_stores/obj/rubicant_shop_key")->move(TO);
   command("wear key");
}

void heart_beat() {
    object *killers;
    int i;
    ::heart_beat();
    if(!objectp(TO) || !objectp(ETO)) return;
    if(query_hp() < 80) {
       command("say You'll pay for this one of these days!!");
       tell_room(ETO, TOQCN+" reaches in a pocket and tosses a bag of dust to the floor.\n");
       tell_room(ETO, "%^BOLD%^There is a blinding flash and %^RED%^ear-splitting pop.\n");
       killers = query_attackers();
       for(i=0;i<sizeof(killers);i++) {
		  killers[i]->cause_typed_damage(killers[i], "head", roll_dice(3, 5), "untyped");
       }
    tell_room(ETO, "%^ORANGE%^When you regain your senses, you find the lady is gone.");
    TO->move("/d/Shadowgate/void");
    TO->remove();
    }
}

void make_me() {
   switch(random(2)) {
      case 0:
	set_name("Satine");
	set_id(({ "shop clerk","shopkeeper","clerk", "satine", "Satine"}));
	set_short("Satine, the shop clerk");
	set_alignment(6);
        set_stats("strength",12);
        set_stats("dexterity",17);
        set_stats("constitution",15);
        set_stats("intelligence",14);
        set_stats("wisdom",14);
        set_stats("charisma",17);

	set_long("%^RESET%^%^WHITE%^Satine is a human woman whose %^BOLD%^"
	  "%^MAGENTA%^soft, feminine features%^RESET%^%^WHITE%^ define her. "
	  "She is young, about 17 years old, and has blossomed into womanhood "
	  "well. Though young, it is said that she is Rubicant's apprentice, "
	  "and as such, is quite knowledgeable about tailoring and jewelling, "
	  "and handles much of the day-to-day affairs and repairs of the shop. "
	  "Her eyes are a deep %^GREEN%^sh%^BOLD%^a%^RESET%^%^GREEN%^de of "
	  "em%^BOLD%^e%^RESET%^%^GREEN%^ra%^BOLD%^l%^RESET%^%^GREEN%^d%^WHITE%^ "
	  "and her soft features are accented by her %^BOLD%^%^ORANGE%^"
	  "straight, fl%^WHITE%^o%^ORANGE%^wing g%^WHITE%^o%^ORANGE%^lden "
	  "b%^WHITE%^l%^ORANGE%^onde ha%^WHITE%^i%^ORANGE%^r%^RESET%^%^WHITE%^. "
	  "She is beautiful, though though you can glean that she keeps in "
	  "shape under the %^RED%^flow%^BOLD%^i%^RESET%^%^RED%^ng sc%^BOLD%^a"
	  "%^RESET%^%^RED%^rlet r%^BOLD%^o%^RESET%^%^RED%^bes%^WHITE%^ that "
	  "she wears, her figure is played down somewhat by the professional "
	  "look.%^RESET%^"
	);
	set_emotes(1, ({
	   "Seeing few customers about, Satine opens the %^BOLD%^%^CYAN%^jewelry case%^RESET%^ and arranges the %^BOLD%^jewelry%^RESET%^ inside.",
	   "Satine explains the quality and general make of some of the %^BOLD%^finest jewelry%^RESET%^ in the store to a wealthy %^RED%^female dwarf%^WHITE%^ with a %^ORANGE%^b%^BOLD%^r%^RESET%^%^ORANGE%^a%^BOLD%^i%^RESET%^%^ORANGE%^d%^BOLD%^e%^RESET%^%^ORANGE%^d %^BOLD%^g%^RESET%^%^ORANGE%^o%^BOLD%^l%^RESET%^%^ORANGE%^d%^BOLD%^e%^RESET%^%^ORANGE%^n %^BOLD%^b%^RESET%^%^ORANGE%^e%^BOLD%^a%^RESET%^%^ORANGE%^r%^BOLD%^d.",
	   "Satine discusses the finer details of a %^CYAN%^beautiful dress%^WHITE%^ with an %^GREEN%^enchanting elven noblewoman.",
	   "Satine wanders through the store, straightening the clothing and putting new items on display on the %^BOLD%^%^BLACK%^ma%^RESET%^r%^BOLD%^b%^RESET%^l%^BOLD%^%^BLACK%^e st%^RESET%^a%^BOLD%^%^BLACK%^tu%^RESET%^e%^BOLD%^%^BLACK%^s%^RESET%^.",
	   "Satine works on repairing some wear and tear on an %^YELLOW%^expensive-looking%^RESET%^ garment that %^BOLD%^shimmers%^RESET%^ with magic.",
	   "Satine tinkers with an %^BOLD%^%^BLUE%^exq%^RESET%^%^BLUE%^u%^BOLD%^isite n%^RESET%^%^BLUE%^e%^BOLD%^ck%^RESET%^%^BLUE%^l%^BOLD%^ace%^RESET%^, reworking one of the gem settings.",
	   "Satine examines some %^ORANGE%^sketches%^WHITE%^ and %^BOLD%^%^CYAN%^designs%^RESET%^ for clothing in pair of %^BOLD%^%^BLACK%^books%^RESET%^ and works on her own creations on a few %^BOLD%^pieces of paper%^RESET%^, flipping through the %^BOLD%^%^BLACK%^books%^RESET%^ now and again for ideas.",
	   "Satine takes a piece of %^BOLD%^beautiful jewelry%^RESET%^ from the %^BOLD%^%^CYAN%^case%^RESET%^ and places it in a %^BOLD%^%^RED%^scarlet box%^RESET%^ for an %^ORANGE%^elderly, well-dressed man%^WHITE%^, who hands her a large sack jingling with coins of %^BOLD%^platinum%^RESET%^.",
	   "Satine %^BOLD%^smiles brightly%^RESET%^ and greets a customer walking in through the %^RED%^double doors%^WHITE%^, walking over to help them personally.",
	   "When there are few customers about, Satine takes the opportunity to stride slowly past the %^MAGENTA%^paintings%^WHITE%^, her %^GREEN%^e%^BOLD%^y%^RESET%^%^GREEN%^es g%^BOLD%^l%^RESET%^%^GREEN%^itter%^BOLD%^i%^RESET%^%^GREEN%^ng%^WHITE%^ with admiration.",
	}),0 );
	break;
     case 1:
	set_name("Ivy");
	set_id(({ "shop clerk","shopkeeper","clerk", "ivy", "Ivy", "enchantress"}));
	set_short("Ivy, the shop clerk");
	set_alignment(3);
        set_stats("strength",10);
        set_stats("dexterity",16);
        set_stats("constitution",12);
        set_stats("intelligence",18);
        set_stats("wisdom",16);
        set_stats("charisma",18);
	set_long("%^RESET%^%^WHITE%^Ivy is a statuesque human woman, with noble "
	  "features becoming of an %^MAGENTA%^enchantress%^WHITE%^. She is young "
	  "and beautiful, appearing not a day older than 25 years old. "
	  "%^MAGENTA%^P%^BOLD%^o%^RESET%^%^MAGENTA%^ols of vi%^BOLD%^o%^RESET%^"
	  "%^MAGENTA%^let %^RESET%^form her eyes, which gaze about with a "
	  "sharp, piercing "
	  "intelligence. Framing her face is her %^BOLD%^%^BLACK%^long, wavy "
	  "midnight black hair%^RESET%^%^WHITE%^, which falls to about her "
	  "mid-back. Her figure is in the classic hourglass shape and is covered "
	  "by a %^BOLD%^%^BLACK%^slinky low-cut black dress%^RESET%^%^WHITE%^ "
	  "that falls to her calves, but is split up the side to her mid-thigh.%^RESET%^"
        );
	set_emotes(1, ({
	   "When there are few customers about, Ivy mutters a quite phrase and any %^ORANGE%^dust%^WHITE%^ or %^BOLD%^%^BLACK%^gr%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^me%^RESET%^ in the room just seems to rise like smoke into the air as it %^BOLD%^%^CYAN%^disintigrates%^RESET%^ into nothingness.",
	   "Ivy smiles at a %^MAGENTA%^young woman%^WHITE%^ as she emerges from the fitting room wearing a %^RED%^r%^BOLD%^a%^RESET%^%^RED%^vish%^BOLD%^i%^RESET%^%^RED%^ng d%^BOLD%^r%^RESET%^%^RED%^ess%^WHITE%^ and adjusts the dress to better fit the woman.",
	   "Ivy folds an %^BOLD%^%^BLACK%^e%^RESET%^x%^BOLD%^%^BLACK%^qu%^RESET%^i%^BOLD%^%^BLACK%^si%^RESET%^t%^BOLD%^%^BLACK%^e%^RESET%^,%^BOLD%^%^BLACK%^ g%^RESET%^e%^BOLD%^%^BLACK%^nt%^RESET%^l%^BOLD%^%^BLACK%^em%^RESET%^a%^BOLD%^%^BLACK%^nl%^RESET%^y %^BOLD%^%^BLACK%^su%^RESET%^i%^BOLD%^%^BLACK%^t%^RESET%^ and places it gently into a %^RED%^scarlet box%^RESET%^ for a middle-aged nobleman.",
	   "Ivy focuses her attention on a %^BOLD%^%^BLACK%^be%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^uti%^RESET%^%^MAGENTA%^f%^BOLD%^%^BLACK%^ul c%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLACK%^rset%^RESET%^ and strands of %^BOLD%^sh%^CYAN%^i%^WHITE%^mme%^CYAN%^r%^WHITE%^ing m%^CYAN%^a%^WHITE%^gic%^RESET%^ seem to seep into it from her hands as she chants an arcane spell.",
	   "Ivy explains the details of the creation of an outfit with %^BOLD%^%^BLACK%^anc%^RESET%^%^GREEN%^i%^BOLD%^%^BLACK%^ent e%^RESET%^%^GREEN%^l%^BOLD%^%^BLACK%^ven s%^RESET%^%^GREEN%^t%^BOLD%^%^BLACK%^yl%^RESET%^%^GREEN%^i%^BOLD%^%^BLACK%^ng%^RESET%^ to an %^GREEN%^elderly elven nobleman%^RESET%^.",
	   "Ivy shows a set of %^CYAN%^st%^BOLD%^y%^WHITE%^l%^CYAN%^i%^RESET%^%^CYAN%^sh m%^BOLD%^a%^WHITE%^g%^CYAN%^e %^RESET%^%^CYAN%^ro%^BOLD%^b%^RESET%^%^CYAN%^es%^WHITE%^ to a %^ORANGE%^young human magus%^WHITE%^, parting the robes on the %^BOLD%^%^BLACK%^st%^RESET%^%^WHITE%^a%^BOLD%^%^BLACK%^tu%^RESET%^%^WHITE%^e%^BOLD%^%^BLACK%^s%^RESET%^ to reveal the cleverly hidden inner pockets.",
	   "Ivy discusses, in fluent gnomish, the features of some of the more %^BOLD%^flashy jewelry%^RESET%^%^WHITE%^ with a %^YELLOW%^rich-looking%^RESET%^%^WHITE%^, %^MAGENTA%^od%^CYAN%^d%^MAGENTA%^ly-%^CYAN%^d%^MAGENTA%^re%^CYAN%^s%^MAGENTA%^se%^CYAN%^d %^MAGENTA%^ma%^CYAN%^l%^MAGENTA%^e g%^CYAN%^n%^MAGENTA%^om%^CYAN%^e%^RESET%^.",
	   "Ivy helps a %^BOLD%^handsome young man%^RESET%^%^WHITE%^ dressed in %^CYAN%^upper merchant-class attire%^WHITE%^ and his entourage choose between some pieces of suitably dashing jewelry.",
	   "Ivy flashes an %^MAGENTA%^enchanting smile%^WHITE%^ at a %^BOLD%^%^BLACK%^darkly armored knight%^RESET%^%^WHITE%^ and his bodyguards as they peruse some of the %^BOLD%^%^BLACK%^g%^RESET%^%^WHITE%^o%^BOLD%^%^BLACK%^thic garments%^RESET%^.",
	   "A %^BOLD%^%^MAGENTA%^perky, cute young priestess%^RESET%^%^WHITE%^ walks out of the fitting room door dressed in %^CYAN%^fl%^BOLD%^o%^RESET%^%^CYAN%^wi%^BOLD%^n%^RESET%^%^CYAN%^g, g%^BOLD%^a%^RESET%^%^CYAN%^uz%^BOLD%^y%^RESET%^%^CYAN%^ ro%^BOLD%^b%^RESET%^%^CYAN%^es%^WHITE%^ and turns in a circle before Ivy, who hmms and gives the girl some advice about her robes."
	}), 0);
	break;
   }
}

void init() {
   ::init();
   add_action("get_key", "request");
}

int get_key(string str) {
     if(member_array(TPQN, "/d/player_stores/rubicant/shop_main"->query_owners()) == -1)
	return notify_fail("I don't think you're authorized!\n");
     if(str != "key")
        return notify_fail("Request what?\n");
     if(!present("key", TO))
	return notify_fail("The clerk apparently does not have a key.\n");
     tell_room(ETO,TPQCN+" whispers something to the clerk.", TP);
     tell_object(TP,"You whisper your request to the clerk.");
     force_me("say As you wish.");
     command("give key to "+TPQN);
     return 1;
}


/********************************
Satine, tailor and jeweller
You look over the female human.
%^RESET%^%^WHITE%^Satine is a human woman whose %^BOLD%^%^MAGENTA%^soft, feminine features%^RESET%^%^WHITE%^ define her. She is young, about 17 years old, and has blossomed into womanhood well. Though young, it is said that she is Rubicant's apprentice, and as such, is quite knowledgeable about tailoring and jewelling, and handles much of the day-to-day affairs and repairs of the shop. Her eyes are a deep %^GREEN%^sh%^BOLD%^a%^RESET%^%^GREEN%^de of em%^BOLD%^e%^RESET%^%^GREEN%^ra%^BOLD%^l%^RESET%^%^GREEN%^d%^WHITE%^ and her soft features are accented by her %^BOLD%^%^ORANGE%^straight, fl%^WHITE%^o%^ORANGE%^wing g%^WHITE%^o%^ORANGE%^lden b%^WHITE%^l%^ORANGE%^onde ha%^WHITE%^i%^ORANGE%^r%^RESET%^%^WHITE%^. She is beautiful, though though you can glean that she keeps in shape under the %^RED%^flow%^BOLD%^i%^RESET%^%^RED%^ng sc%^BOLD%^a%^RESET%^%^RED%^rlet r%^BOLD%^o%^RESET%^%^RED%^bes%^WHITE%^ that she wears, her figure is played down somewhat by the professional look.%^RESET%^

She is carrying:
A black iron key (worn)


Lawful Neutral
Tailor and Jeweller
Str: 12 Dex: 17 Con: 15 Int: 14 Wis: 14 Cha: 17


Ivy, the enchantress
You look over the female human.
%^RESET%^%^WHITE%^Ivy is a statuesque human woman, with noble features becoming of an %^MAGENTA%^enchantress%^WHITE%^. She is young and beautiful, appearing not a day older than 25 years old. %^MAGENTA%^P%^BOLD%^o%^RESET%^%^MAGENTA%^ols of vi%^BOLD%^o%^RESET%^%^MAGENTA%^let form her eyes, which gaze about with a sharp, piercing intelligence. Framing her face is her %^BOLD%^%^BLACK%^long, wavy midnight black hair%^RESET%^%^WHITE%^, which falls to about her mid-back. Her figure is in the classic hourglass shape and is covered by a %^BOLD%^%^BLACK%^slinky low-cut black dress%^RESET%^%^WHITE%^ that falls to her calves, but is split up the side to her mid-thigh.%^RESET%^

She is carrying:
A darksteel key (worn)

Lawful Evil
Mage (Enchantment)
Str: 10  Dex: 16  Con: 12 Int: 18 Wis: 16 Cha:18
***********************/
