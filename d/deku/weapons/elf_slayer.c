#include <std.h>
#define H_RACES ({"elf","half-elf","drow","half-drow"}) 
inherit "/d/common/obj/weapon/longsword.c";

void create() {
    ::create();
    set_name("longsword");
    set_id(({"sword","longsword","elfslayer"}));
    set_obvious_short("An iron longsword");
    set_short("An elf slayer");

    set_long("%^BOLD%^%^WHITE%^The blade of this long sword is made "+
    "from a piece of %^BOLD%^%^BLACK%^darkened iron%^BOLD%^%^WHITE%^."+
    "  It is always sharp, suggesting the involvement of some type "+
    "of dormant magic.  It is covered with ancient %^BLUE%^runes"+
    "%^BOLD%^%^WHITE%^ which depict battle scenes, each of elves "+
    "fighting brutally against elves.  A simple iron cross-piece "+
    "connects the blade to the hilt.  The hilt itself is made "+
    "from a softer and lighter colored %^RESET%^steel%^BOLD%^ "+
    "%^WHITE%^and is inscribed with a single phrase.  The hilt "+
    "ends with a similarly %^BOLD%^%^BLACK%^darkened%^BOLD%^"+
    "%^WHITE%^ iron pommel.%^RESET%^");
    
    set_language("elven");
    set_read("%^BOLD%^%^GREEN%^May the extinction of the elven "+
    "race come swiftly and brutally.%^RESET%^");
    
    set_lore("This is an ancient Elf slayer. These swords are relics "+
    "of the elven wars. When the elves fought amongst "+
    "themselves trying to rid themselves of the perceived evil in "+
    "the other elves. This of course ended with what where to become "+
    "the dark elves being driven deep into the earth.");
    set_value(5000);
    set_property("enchantment",3);
    set_hit( (: this_object(), "weapon_hit" :) );
    set_destroy();  // do I need this?
    set_wield((:TO,"wield_me":));
    set_unwield("%^RED%^You carefully release the sword.%^RESET%^");
	set_hit((:TO,"weapon_hit":));
}

int wield_me() {
  if(ETO->query_highest_level() < 20) {
    tell_object(ETO,"%^RED%^The magic of this weapon is beyond "+
    "you!%^RESET%^");
    return 0;
  }
  tell_object(ETO,"%^BLUE%^A strange sensation pulses through your "+
  "body!%^RESET%^");
  return 1;
}   


int weapon_hit(object targ) {
  int bonus;
  string race;
  if(!objectp(targ)) return 1;
  race = (string)targ->query_race();
  //tell_object(find_player("saide"),identify(race));
//  if(!objectp(targ)) return 1;
  if(!random(3)) {
   if(member_array(race,H_RACES) != -1) {
     switch(random(2)) {
        case 0:
            tell_room(EETO,ETO->QCN+"%^RED%^ strikes "+
            targ->QCN+"%^RED%^ with "+ETO->QP+ "%^RED%^ sword "+
            "and "+targ->QCN+"%^RED%^ screams out in agony"+
            "!%^RESET%^",({targ,ETO}));
     
            tell_object(ETO,"%^RED%^You strike "+targ->QCN+"%^RED%^ "+
            "with your sword and "+targ->QS+ " cries out in "+
            "agony!%^RESET%^");
         
            tell_object(targ,ETO->QCN+"%^RED%^ strikes you with "+ETO->QP+
            " sword and you feel your blood beginning to boil!%^RESET%^");
            
            return roll_dice(2,6);
            break;
        case 1:
            tell_room(EETO,ETO->QCN+"%^YELLOW%^ screams "+
            "loudly and thrusts "+ETO->QP+" sword %^RED%^deep "+
            "%^YELLOW%^into "+targ->QCN+"%^YELLOW%^, impaling "+
            targ->QO+"!%^RESET%^",({targ,ETO}));

            tell_object(ETO,"%^YELLOW%^An intense anger wells up "+
            "in you as you thrust into "+targ->QCN+"%^YELLOW%^, "+
            "%^RED%^impaling%^YELLOW%^ "+targ->QO+"!%^RESET%^");

            tell_object(targ,ETO->QCN+"%^YELLOW%^ screams loudly "+
            "and thrusts "+ETO->QP+" sword %^RED%^deep%^YELLOW%^ "+
            "into you, impaling you with it!%^RESET%^");
            return roll_dice(2,6);
            break;
        }
   }
   return 1;
  }
}


