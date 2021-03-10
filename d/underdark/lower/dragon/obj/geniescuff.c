#include <std.h>
#include <daemons.h>
inherit ARMOUR;

int OWNED, tracker, trackerb;
string owner;

void create(){
	::create();
	set_name("cuff bracelet");
	set_id(({ "armlet", "arm cuff", "cuff", "cuff bracelet", "jelzaba's gem", "jelzabas gem", "gem" }));
	set_short("%^BOLD%^%^MAGENTA%^J%^RESET%^%^MAGENTA%^el%^RED%^za%^CYAN%^ba%^BLUE%^'s %^BOLD%^Ge%^CYAN%^m%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a %^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^l%^YELLOW%^d%^RESET%^%^ORANGE%^e%^YELLOW%^n %^RESET%^%^ORANGE%^arm cuff%^RESET%^");
	set_long("%^RESET%^%^ORANGE%^This one of a kind cuff bracelet is designed to easily wrap around the "
"%^YELLOW%^wearer's arm %^RESET%^%^ORANGE%^and adjust to a proper fit by lightly squeezing or expanding the "
"soft golden metal.  Created from a single band of %^YELLOW%^pure gold%^RESET%^%^ORANGE%^, the armlet is "
"unblemished and holds a %^BOLD%^%^BLUE%^bright %^RESET%^%^ORANGE%^and %^BOLD%^%^MAGENTA%^lustrous %^RESET%^"
"%^ORANGE%^glow within its metal.  Set into the center and held with thin strings of crisscrossing gold wires, "
"is a circular oval of %^BOLD%^%^MAGENTA%^ra%^RESET%^%^MAGENTA%^inb%^RED%^ow %^CYAN%^tou%^BLUE%^rm%^BOLD%^ali"
"%^CYAN%^ne%^RESET%^%^ORANGE%^ that flows between a deep, %^MAGENTA%^luminescent purple %^ORANGE%^to a pale "
"blaze of %^BLUE%^sapphire blue%^ORANGE%^.  The gem is polished smooth but appears unfinished as the interior "
"is foggy and clouded.  Tiny etchings mark its underside.%^RESET%^\n"); 
	set("read","%^BOLD%^%^MAGENTA%^Etched on the underside of the cuff are a set of tiny runic markings "
"which spell out: %^CYAN%^R U B%^RESET%^");
      set("langage","gnomish");
	set_weight(2);
	set_value(10000);
	set_lore("Five thousand years ago, give or take a decade, a genie named Jelzaba was cursed to reside "
"inside a bejeweled flask for all eternity.  A clever creature, Jelzaba realized that while he would never be "
"free of the curse, he might find a means by which to gain a degree of freedom.  Back then, Jelzaba's master "
"was a gnomish wizard by the name of Iximixi.  Known for his wonderful experiments, many visited Iximixi's "
"elaborate events where he displayed grand wonders.  When Iximixi grew older, his ability to travel began to "
"wane and Jelzaba came up with a solution.  Iximixi would free Jelzaba to wander the world collecting rare "
"ingredients, and when Iximixi had need, he would simply summon Jelzaba home.  Iximixi agreed and transformed "
"the bottle into an oval stone.  It is unknown what came to pass in the time since then, but in 685 SG, the "
"bracelet containing Jelzaba's gem was given to the winner of the first annual Adventurous Summer storytelling "
"contest.  A young wizard named Arelyn.");
	set_property("lore difficulty",35);
      set_property("id difficulty",35);
	set_type("ring");
	set_limbs(({ "right arm" }));
	set_size(-1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
      tracker = 0;
      trackerb = 0;
      set_property("no alter",1);
}

int wear_func(){
   if(!ETO->is_class("mage")&& !ETO->is_class("sorcerer")) {
     tell_object(ETO,"The cuff doesn't seem to fit you.");
     return 0;
   }
   if(ETO->query_level() < 35) {
     tell_object(ETO,"You are not experienced enough to use this item.");
     return 0;
   }
   tell_object(ETO,"%^RESET%^%^ORANGE%^The clouds within the gem %^MAGENTA%^sw%^CYAN%^i%^BLUE%^rl %^ORANGE%^about as you set the bracelet about your wrist.%^RESET%^");
   return 1;
}

int remove_func(){
   tell_object(ETO,"%^RESET%^%^ORANGE%^You slip the smooth golden band from your wrist.%^RESET%^");
   return 1;
}

void init() {
   ::init();
   add_action("conjure_genie","rub");
}

int conjure_genie(string str){
   object mygenie;
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) {
     notify_fail("You should try to wear the cuff first.\n");
     return 0;
   }
   if(!str) {
     notify_fail("What are you trying to rub?\n");
     return 0;
   }
   if(str != "the cuff" && str != "cuff") {
     notify_fail("Nothing happens.\n");
     return 0;
   }
   if(tracker > time()) {
     tell_object(TP,"The cuff's power is spent for today.");
     return 1;
   }
   if(!OWNED) {
     owner = TP->query_name();
     OWNED = 1;
   }
   if((string)TP->query_name() != owner) {
     tell_object(TP,"Nothing happens.");
     return 1;
   }
   if(present("jelzaba",ETP)) {
     tell_object(TP,"The genie is already here!");
     return 1;
   }
   if(trackerb == 2) {
     tracker = time() + 86400;
     trackerb = 0;
   }
   else { trackerb++; }
   mygenie = new("/d/underdark/lower/dragon/obj/genie");
   mygenie->move(ETP);
   mygenie->set_owner(owner);
   tell_object(TP,"%^RESET%^%^CYAN%^You rub the cuff's %^RED%^c%^BOLD%^%^MAGENTA%^lo%^RESET%^%^MAGENTA%^ud"
"%^BLUE%^y g%^BOLD%^em%^RESET%^%^CYAN%^, and from it issues a stream of %^BOLD%^azure smoke%^RESET%^%^CYAN%^. "
"It expands before you, taking on the shape of a man!%^RESET%^");
   tell_room(ETP,"%^RESET%^%^CYAN%^"+TP->QCN+" rubs the cuff's %^RED%^c%^BOLD%^%^MAGENTA%^lo%^RESET%^"
"%^MAGENTA%^ud%^BLUE%^y g%^BOLD%^em%^RESET%^%^CYAN%^, and from it issues a stream of %^BOLD%^azure smoke"
"%^RESET%^%^CYAN%^. It expands before you, taking on the shape of a man!%^RESET%^",TP);
   return 1;
}

int isMagic(){ return 1; }
