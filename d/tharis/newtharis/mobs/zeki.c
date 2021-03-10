
#include <std.h>
#include "../tharis.h"
inherit "/std/spell_vend.c";

// Based on old Tharis City Buildings, Mobs, etc.
// Tharis City Remodle - Created by LoKi in 2009.  
// Tharis Mage Tower - Coded in October 2005 by Circe
// Player Designed Area - Originally Player "shop" 
// Never installed into game prior to Tharis City Remodle
// Design work by Sevotharte & Nightfall, finished by Azalon
// Incorporated into the Tharis City Remodle in February 2009 by Ari

void create() {
  int i,j;
  float fi;
  object ob;
  mapping spells_sold,spells_to_sell;
  string *spells;
  ::create();
  set_property("no bump", 1);
  set("aggressive", 0);
  set_name("zeki");
  set_id(({"zeki","clerk","shop keeper","shopkeeper","Zeki"}));
  set_short("%^RED%^Zeki Duman Effendi,%^RESET%^ "+
	"%^MAGENTA%^Resident Alchemist%^RESET%^");
  set_level(16); 
  set_long(
     "%^MAGENTA%^Zeki Duman %^ORANGE%^is a man of average height.  "+
     "His skin is bronzed and his lively eyes %^BOLD%^%^BLACK%^black "+
     "as coal%^RESET%^%^ORANGE%^.  His %^BOLD%^%^WHITE%^snowy white"+
     "%^RESET%^ %^ORANGE%^hair is loosely tied in a bun at the base "+
     "of his neck, but most of it is hidden by the mage's hat he is "+
     "wearing.  A pair of %^WHITE%^legless spectacles %^ORANGE%^rests "+
     "on the bridge of his nose and occasionally slides down, forcing "+
     "him to push them back up with a finger.  The top of his amber "+
     "colored puffy pantaloons is hidden by a %^BOLD%^%^MAGENTA%^"+
     "bright fuchsia%^RESET%^ %^ORANGE%^embroidered overcoat with "+
     "bell sleeves, the thread of the embroidery and the sash both "+
     "of the same amber as the pantaloons.  The toes of his "+
     "%^YELLOW%^curly toed shoes%^RESET%^ %^ORANGE%^rise high, "+
     "a symbol of wealth and status in the Tsarven society.\n"+
     "%^RESET%^<help shop> will get you a list of shop commands.");
  set_gender("male");
  set_alignment(4);
  set_race("human");
  set_class("mage");
  set_hd(16,1);
  set_stats("intelligence",19);
  set_stats("wisdom",16);
  set_stats("strength",12);
  set_stats("charisma",13);
  set_stats("dexterity",18);
  set_stats("constitution",14);
  set_guild_level("mage",16);
  set_mlevel("mage",16);
  set_overall_ac(0);
  set_spells_sold(gen_spells_sold(20));
  set_spell_chance(90);
  set_spells(({"color spray","hideous laughter","acid arrow",
	"sleep","monster summoning ii"}));
}

int __Pickup(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || avatarp(TP)) return
::__Pickup(str);
    else {
      tell_object(TP, "%^RESET%^%^MAGENTA%^Zeki says%^RESET%^: "+
		"You?  Hahaha, you're not worthy of one of these.");
      return 1;
    }
}

int __Buy(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || avatarp(TP)) return
::__Buy(str);
    else {
      tell_object(TP, "%^RESET%^%^MAGENTA%^Zeki says%^RESET%^: You?  "+
		"Hahaha, you're not worthy of one of these.");
      return 1;
    }
}

int __List(string str){ 
    if(TP->is_class("mage") || TP->is_class("bard") || avatarp(TP)) return
::__List(str);
    else {
      tell_object(TP, "%^RESET%^%^MAGENTA%^Zeki says%^RESET%^: "+
		"You?  Hahaha, you're not worthy of one of these.");
      return 1;
    }
}

int __Sell(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || avatarp(TP)) return
::__Sell(str);
    else {
      tell_object(TP, "%^RESET%^%^MAGENTA%^Zeki says%^RESET%^: You?  "+
		"Hahaha, you're not worthy of one of these.");
      return 1;
    }
}

int __Help(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || avatarp(TP)) return
::__Help(str);
    else {
      tell_object(TP, "%^RESET%^%^MAGENTA%^Zeki says%^RESET%^: "+
		"You?  Hahaha, you're not worthy of one of these.");
      return 1;
    }
}
