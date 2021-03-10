//updated to current code and to remove references to old gods ~Circe~ 9/25/19
#include <std.h>
#include <daemons.h>

inherit "/d/common/obj/clothing/magerobe.c";

int FLAG;

void create(){
   ::create();
   set_name("robe of starlight");
   set_id(({"robe","robe of starlight","velvet robe"}));
   set_short("%^RESET%^%^BLUE%^Robe of %^RESET%^S%^BOLD%^t%^RESET%^a%^BOLD%^r%^RESET%^l%^BOLD%^i%^RESET%^g%^BOLD%^h%^RESET%^t");
   set_obvious_short("%^RESET%^%^BLUE%^A %^BOLD%^%^WHITE%^shimmering%^RESET%^ %^BLUE%^velvet robe%^RESET%^");
   set_long("%^RESET%^%^BLUE%^This robe is made from deep plush blue velvet.  The robe is of a normal silhouette, with long sleeves and a rounded collar.  Twinkling in the velvet are the images of nearly hundreds of %^BOLD%^%^WHITE%^s%^RESET%^t%^BOLD%^a%^RESET%^rs %^BLUE%^that shine with a soft %^RESET%^glow%^BLUE%^.  The stars cluster together at the shoulders and then fade to nearly nothing down to the bottom hem of the robe. All manner of shapes and sizes of stars are represented on the robe, from small four-pointed stars to large eight-pointed ones.%^RESET%^");
   set_value(1500);
   set_lore("The Robe of Starlight was made by a diviner human sorceress named Magelia.  Magelia so loved astronomy and the stars that she took them as her personal sigil.  With loving care, she crafted these robes and hand-stitched each star into them.  They say Magelia gave a special ability to the robes, but few have learned of their secrets.- Gazing Through the Crystal Ball:Famous Diviners in History - Valant Ro");
   set_property("lore difficulty",16);
   set_property("enchantment",3);
   set_wear((:TO,"wear_func":));
   set_remove((:TO,"remove_func":));
   set_struck((:TO,"strike_func":));
   FLAG = 0;
}

int wear_func(){
  if(member_array("%^BOLD%^%^CYAN%^Lucid Dreams%^RESET%^",ETO->query_mini_quests())== -1) {
      tell_object(ETO,"You have not earned the right to make use of this item.");
      return 0;
   }
   if((string)ETO->query_diety() == "kismet"){
      tell_object(ETO,"%^BOLD%^%^BLUE%^As you slide into the velvet robes, the %^WHITE%^s%^RESET%^t%^BOLD%^a%^RESET%^r%^BOLD%^s %^BLUE%^shimmer briefly.%^RESET%^");
      tell_room(EETO,"%^BLUE%^"+ETOQCN+" slides into "+ETO->QP+" blue velvet robes.  The images of the %^BOLD%^%^WHITE%^s%^RESET%^t%^BOLD%^a%^RESET%^r%^BOLD%^s%^RESET%^%^BLUE%^ on "+ETO->QP+" robes shimmer briefly.%^RESET%^",ETO);
	set_item_bonus("magic resistance",1);
      set_item_bonus("sight bonus",5);
      FLAG = 1;
      return 1;
   }else{
	tell_room(EETO,"%^BLUE%^"+ETOQCN+" slips in a plush blue velvet robe.%^RESET%^",ETO);
	tell_object(ETO,"%^BLUE%^You slip on the plush blue velvet robe and can't help but feel a bit %^WHITE%^special%^RESET%^.%^RESET%^");
	set_item_bonus("magic resistance",1);
      set_item_bonus("sight bonus",2);
	return 1;
   }
}

int remove_func(){
   if(FLAG){
     	tell_object(ETO,"%^BOLD%^%^BLUE%^Sliding out of the velvet robes, you notice the %^WHITE%^s%^RESET%^t%^BOLD%^a%^RESET%^r%^BOLD%^s %^BLUE%^shimmer briefly before fading.%^RESET%^");
      tell_room(EETO,"%^BLUE%^"+ETO->QCN+" slides out of "+ETO->QP+" blue velvet robes.  The images of the %^BOLD%^%^WHITE%^s%^RESET%^t%^BOLD%^a%^RESET%^%^BOLD%^s%^RESET%^%^BLUE%^ on "+ETO->QP+" robes shimmer briefly before fading.%^RESET%^",ETO);
      return 1;
   }else{
      tell_room(EETO,"%^BLUE%^"+ETOQCN+" slips out of a blue velvet robe.%^RESET%^",ETO);
      tell_object(ETO,"%^BLUE%^You slip out of the robes and can't help but feel ordinary now!%^RESET%^");
	return 1;
   }
}

int strike_func(int damage, object what, object who){
   if(random(1000) < 125){
      tell_room(environment(query_worn()),"%^BLUE%^"+ETOQCN+" tears off a star from "+ETO->QP+" robe that forms into a %^BOLD%^%^WHITE%^silver shuriken%^RESET%^%^BLUE%^, which is hurled at "+who->QCN+"!%^RESET%^",({ETO,who}));
      tell_object(ETO,"%^BLUE%^Reaching for one of the images on the stars on the robe, you tear it off.  The star takes the shape of a %^BOLD%^%^WHITE%^silver shuriken%^RESET%^%^BLUE%^ that you hurl at "+who->QCN+"!%^RESET%^");
      tell_object(who,"%^BLUE%^"+ETOQCN+" rips a star off "+ETO->QP+" robe that takes the shape of a %^BOLD%^%^WHITE%^silver shuriken%^RESET%^%^BLUE%^ which they hurl at you!%^RESET%^");
      who->do_damage("torso",random(4)+6);
   }
}

