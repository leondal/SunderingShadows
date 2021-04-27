//Octothorpe (2/16/09)
//Underdark Mining Caverns, Mask of the Deep Wyrm

#include <std.h>
#include "../defs.h"
inherit ARMOUR;

void create(){
   ::create();
   set_name("mask of the deep wyrm");
   set_id(({"mask of the deep wyrm", "mask", "deep wyrm", "wyrm mask", "deep wyrm mask"}));
   set_short("%^BOLD%^%^BLACK%^Mask of the D%^RESET%^%^MAGENTA%^ee"+
      "%^BOLD%^%^BLACK%^p W%^RESET%^%^RED%^y%^BOLD%^%^BLACK%^rm"+
      "%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^grotesque dr%^RESET%^"+
      "%^MAGENTA%^a%^BOLD%^%^BLACK%^c%^RESET%^%^MAGENTA%^o%^BOLD%^"+
      "%^BLACK%^n%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^c mask%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This mask has been shoddily constructed "+
      "out some sort of rough wood. Although some artistic license is "+
      "involved, the mask has the general shape of a dragon's head. "+
      "Sloppy coats of black and %^RESET%^%^MAGENTA%^purple %^BOLD%^"+
      "%^BLACK%^paint have been applied in splotches all over the mask. "+
      "The visage incorporates a dichotomy of hideous, abject terror "+
      "and ineptitude in its craftmanship.%^RESET%^");
   set_lore("Those kobold communities that are dominated by draconic "+
      "cults are led usually by a shaman or sorceror. The cult leader "+
      "is bound to serve as the dragon's proxy within the community "+
      "and will usually adorn himself in draconic costumes and other "+
      "artifacts. Usually the leader will make use of a dragon mask, "+
      "which is used to both impress and strike fear into his rivals "+
      "and charges.\n"+
      "-An excerpt from 'On the Kobold Race,' by Thaddeus Kranzot");
   set_property("lore",13);
   set_weight(8);
   set_value(1000+random(1000));
   set_property("enchantment",3);
   set_type("clothing");
   set_limbs(({"head"}));
   set_size(1);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
   set_ac(0);
}

int wear_fun(){
   if(base_name(ETO) == "/d/underdark/mines/mon/kobsorc") return 1;
   if(base_name(ETO) != "/d/underdark/mines/mon/kobsorc"){
      if((int)ETO->query_highest_level() < 5 && member_array("Assisted the Kobolds",ETO->query_mini_quests()) == -1 && member_array("Assisted the Svirfneblin",ETO->query_mini_quests()) == -1){
      tell_object(ETO,"%^BOLD%^Your vision is too obstructed by the "+
         "mask so you give up and remove it.%^RESET%^");
      return 0;
      }
   }
   if((string)ETO->query_race() == "kobold") set_item_bonus("charisma",2);
   else set_item_bonus("charisma",0);
   tell_object(ETO,"%^BOLD%^%^BLACK%^The heavy mask is very "+
      "uncomfortable as you don it.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^BLACK%^%^"+ETOQCN+" looks somewhat "+
      "foolish as they wear the mask.%^RESET%^",ETO);
   return 1;
}

int remove_fun(){
   tell_object(ETO,"%^BOLD%^%^BLACK%^%^You are glad to be free of "+
      "the stifling mask.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^BLACK%^%^"+ETOQCN+" appears overheated "+
      "as they remove the mask.%^RESET%^",ETO);
   return 1;
}

int struck_fun(int damage,object what,object who){
   if(!random(7)){
      tell_room(EETO,"%^BOLD%^%^BLACK%^"+who->QCN+" becomes entranced "+
         "by "+ETOQCN+"'s masked visage.%^RESET%^",({ETO,who}));
      tell_object(ETO,"%^BOLD%^%^BLACK%^"+who->QCN+" becomes entranced "+
         "by your mask.%^RESET%^");
      tell_object(who,"%^BOLD%^%^BLACK%^Your eyes are drawn to "+
         ""+ETOQCN+"'s mask, and you are unable to look away!%^RESET%^");
      who->set_paralyzed(random(5),"%^BOLD%^You are entranced by the mask!%^RESET%^");
      return 0;
   }
   return damage;
}
