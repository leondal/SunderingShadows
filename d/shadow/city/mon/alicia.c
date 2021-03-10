//Octothorpe (1/22/17)
//Shadow, Alicia Spell Vendor
//Designed by Ivyes
//Adapted from /d/attaya/newseneca/mon/godfrey.c

#include <std.h>
#include "../defs.h"

inherit "/std/spell_vend.c";

void create(){
  int i,j;
  float fi;
  object ob;
  mapping spells_sold,spells_to_sell;
  string *spells;

  ::create();
  set_property("no attack",1);
  set_property("no bump", 1);
  set_property("strength","spells");
  set("aggressive", 0);
  set_name("Alicia");
  set_id(({
     "Alicia","alicia","alicia glimmering","shopkeeper","shop keeper","vendor"
   }));
  set_short("%^BOLD%^%^GREEN%^Alicia Glimmering, Proprietor of The "+
     "Green Hag's Relics and Runes%^RESET%^");
  set_level(40);
  set_long("%^RESET%^%^CYAN%^Alicia is one of the most beautiful "+
     "women you've ever imagined - until she smiles. Her teeth are a "+
     "%^GREEN%^sic%^ORANGE%^k%^GREEN%^ly gr%^ORANGE%^e%^GREEN%^en "+
     "col%^ORANGE%^o%^GREEN%^r%^CYAN%^! %^BOLD%^%^GREEN%^Green curls "+
     "%^RESET%^%^CYAN%^thickened with %^BOLD%^%^GREEN%^glittering "+
     "green leaves %^RESET%^%^CYAN%^tumble about her torso, providing "+
     "a little extra coverage to her scantily clad body. The tips of "+
     "her pointed ears poke through those lush tresses. Her eyes are "+
     "so %^BOLD%^%^BLACK%^dark %^RESET%^%^CYAN%^as to be nearly black, "+
     "and she is known for her uncanny ability to %^WHITE%^suddenly"+
     "%^CYAN%^, and %^WHITE%^silently%^CYAN%^, be anywhere in the "+
     "shop that she is wanted.%^RESET%^");
  set_gender("female");
  set_alignment(7);
  set_race("dryad");
  set_class("mage");
  set_class("druid");
  set_hd(40,12);
  set_stats("intelligence",18);
  set_stats("wisdom",20);
  set_stats("strength",18);
  set_stats("charisma",18);
  set_stats("dexterity",14);
  set_stats("constitution",18);
  set_body_type("human");
  set_guild_level("mage",20);
  set_mlevel("druid",10);
  set_guild_level("druid",10);
  set_mlevel("mage",20);
  set_overall_ac(-10);
  set_spells_sold(gen_spells_sold(20));
  set_spell_chance(100);
  set_spells(({
      "fireball","lightning bolt","acid arrow","powerword stun","incendiary cloud","magic missile"
   }));
}

int __Pickup(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP)) return
::__Pickup(str);
    else {
      tell_object(TP, "%^MAGENTA%^Alicia says softly%^RESET%^: I am "+
         "unable to help you.");
      return 1;
    }
}

int __Buy(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP)) return
::__Buy(str);
    else {
      tell_object(TP, "%^MAGENTA%^Alicia says softly%^RESET%^: I am "+
         "unable to help you.");
      return 1;
    }
}

int __List(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP)) return
::__List(str);
    else {
      tell_object(TP, "%^MAGENTA%^Alicia says softly%^RESET%^: I am "+
         "unable to help you.");
      return 1;
    }
}

int __Sell(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP)) return
::__Sell(str);
    else {
      tell_object(TP, "%^MAGENTA%^Alicia says softly%^RESET%^: I am "+
         "unable to help you.");
      return 1;
    }
}

int __Help(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP)) return
::__Help(str);
    else {
      tell_object(TP, "%^MAGENTA%^Alicia says softly%^RESET%^: I am "+
         "unable to help you.");
      return 1;
    }
}
