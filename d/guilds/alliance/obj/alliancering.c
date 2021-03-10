//Updated with color and lore, last change 4/24/01 - Octothorpe 1/2/10

#include <std.h>

inherit "/std/guild.c";

void create(){
   ::create();
   set_name("Signet Ring");
   set_id(({"alliance ring","ring","signet ring"}));
   set_short("%^RESET%^S%^BOLD%^i%^RESET%^lv%^BOLD%^e%^RESET%^r S"+
      "%^BOLD%^i%^RESET%^gn%^BOLD%^e%^RESET%^t R%^BOLD%^i%^RESET%^ng");
   set_long("%^BOLD%^This is a small silver signet ring. Its sealing "+
      "mark is one of a pair of gauntlets shaking hands. This ring "+
	  "once represented the agreement of various factions of knights, "+
	  "warriors, and magicians dedicated to fight for good. This symbol "+
	  "represented the strength in this collaboration.%^RESET%^");
   set_lore("Rings of this design were once used as symbols of "+
      "membership in the Alliance of Light.  The Alliance was founded "+
	  "during the early part of the 640s SG out of the remnants of the "+
	  "Order of Metallic Dragons in order to combat the forces of evil "+
	  "in the region.  The Alliance is perhaps best known for its "+
	  "prolonged hostilities with the Raiders in Night's Cloak/Tempered "+
	  "Blades, which lasted through much of the '40s.  Many famous "+
	  "adventurers were members of the Alliance, such as Tanis, Korath, "+
	  "Ungrim, Zeal, Tanamen, Xodor, Vrax, and Brenamen.  Due to "+
	  "internal disagreements on the organization's direction, and "+
	  "renewed pressure from the Tempered Blades, the Alliance suddenly "+
	  "disbanded in 650 SG.");
   set_type("ring");
   set_limbs(({"right hand"}));
   set_weight(1);
    set_guild_name("Alliance Reborn");
   set_guild_object("/d/guilds/alliance/obj/alliancering.c");
   set_property("lore difficulty",17);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

/*void init(){
   ::init();
   if(!objectp(TO)) {
      message("info","The ring rejects you.",TP);
      return;
   }
   ETO->force_me("wear alliance ring");
}*/

int wear_fun(){
   string mname = ETO->query_name();
   if(mname == "zeal" || mname == "ungrim" || mname == "vrax" || mname == "brenamen" || mname == "korath"){
      tell_object(ETO,"%^BOLD%^As you wear the signet ring, you are "+
	     "reminded of your friends that are long gone, and the triumphs "+
		 "of the %^YELLOW%^Alliance of Light %^WHITE%^that have faded "+
		 "from history.%^RESET%^");
	  tell_room(EETO,"%^BOLD%^"+ETOQCN+" appears to be fortified with "+
	     "renewed purpose as he wears the signet ring.%^RESET%^",ETO);	 
	  return 1;
   }
   ETO->set_property("good item",1);
   return 1;
}

int remove_fun(){
   ETO->set_property("good item",-1);
   return 1;
}
