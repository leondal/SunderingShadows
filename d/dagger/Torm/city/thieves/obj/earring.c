//Updated with color and lore, last change 4/10/01 - Octothorpe 1/2/10
//moving a copy over to torm for vethor guild -H 12/27/20
#include <std.h>

inherit "/d/common/obj/jewelry/circlet.c";

void create(){
   ::create();
   set_name("Onyx Earring");
   set_id(({"raider ring","earring","ear ring","guild earring","raidersearring"}));
   set_short("%^RESET%^s%^BOLD%^i%^RESET%^lv%^BOLD%^e%^RESET%^r %^BOLD%^"+
      "%^BLACK%^a%^RESET%^n%^BOLD%^d %^BOLD%^%^BLACK%^on%^RESET%^y"+
	  "%^BOLD%^%^BLACK%^x e%^WHITE%^a%^BLACK%^rr%^WHITE%^i%^BLACK%^"+
	  "ng%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This small loop is made of %^RESET%^s"+
      "%^BOLD%^i%^RESET%^lv%^BOLD%^e%^RESET%^r %^BOLD%^%^BLACK%^and "+
	  "on%^RESET%^y%^BOLD%^%^BLACK%^x mixture.  It's a small single "+
	  "earring that loops through the left earlobe of its wearer.  "+
	  "The small loop has a delicate design that wraps around "+
	  "it.%^RESET%^");
   set_lore("This earring once identified its wearer as a member of the "+
      "Raiders in Night's Cloak, or the Tempered Blades, as the guild "+
	  "eventually became to be known as.  The Raiders were initially "+
	  "founded and led by the drow expatriates Zilath and Kieryn, "+
	  "sometime during the late 630s/early 640s SG.  The drow "+
	  "leadership was deposed in a coup by Vethor, whom changed the "+
	  "name of the guild to the Tempered Blades, sometime after 645 SG. "+
	  "The guild is perhaps best known for it's famous rivalry with the "+
	  "Alliance of Light, as well as its two famous members, Daelmas, "+
	  "and the future demi-god, Durias.");

   set_property("lore difficulty",26);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_weight(1);
}
int wear_fun(){
   ETO->set_property("evil item",1);
   return 1;
}
int remove_fun(){
   ETO->set_property("evil item",-1);
   return 1;
}