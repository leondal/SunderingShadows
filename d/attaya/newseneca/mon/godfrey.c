//godfrey.c - aasimar spell vendor for new Seneca
//struggles with his hatred for the tiefling downstairs
//~Circe~ 1/9/08
#include <std.h>

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
  set_name("Godfrey");
  set_id(({"godfrey","Godfrey","godfrey kieran","kieran","shopkeeper","shop keeper","vendor"}));
  set_short("Godfrey Kieran, Proprietor of Ethereal Wonders");
  set_level(40); 
  set_long("Dressed in a plush velvet %^BLUE%^indigo doublet "+
     "%^CYAN%^embroidered with %^YELLOW%^stars%^RESET%^%^CYAN%^, "+
     "Godfrey looks most "+
     "unlike the typical wizard.  Strapped to his back is a "+
     "%^BOLD%^%^WHITE%^two-handed sword %^RESET%^%^CYAN%^"+
     "made from some unknown metal that %^RESET%^g%^BOLD%^l"+
     "%^RESET%^i%^BOLD%^t%^RESET%^t%^BOLD%^e%^RESET%^r%^BOLD%^s "+
     "%^RESET%^%^CYAN%^even in the absence of light.  %^BLUE%^"+
     "Stockinged %^CYAN%^legs with %^BLUE%^knee-high boots "+
     "%^CYAN%^are well-muscled, hinting at his raw power.  "+
     "His %^YELLOW%^golden locks "+
     "%^RESET%^%^CYAN%^curve naturally up and away from his "+
     "face, falling gently to his shoulders.  Stunning wide "+
     "%^BOLD%^%^WHITE%^silver eyes %^RESET%^%^CYAN%^gaze serenely upon "+
     "his surroundings, while his full %^RED%^rosebud lips "+
     "%^CYAN%^combine with the slightly %^YELLOW%^golden "+
     "tint %^RESET%^%^CYAN%^of his skin to give him the "+
     "appearance of an angel.  Godfrey became the shopkeeper "+
     "here in Seneca to help keep an eye on Octavia when the "+
     "city refused to expel her, and he often finds himself "+
     "at odds with the tiefling and her little imp.%^RESET%^"+
     "\n\n<help shop> will get you a list of shop commands.");
  set_gender("male");
  set_alignment(1);
  set_race("aasimar");
  set_class("mage");
  set_class("paladin");
  set_hd(40,12);
  set_stats("intelligence",18);
  set_stats("wisdom",20);
  set_stats("strength",18);
  set_stats("charisma",18);
  set_stats("dexterity",14);
  set_stats("constitution",18);
  set_body_type("human");
  set_guild_level("mage",40);
  set_mlevel("paladin",40);
  set_guild_level("cleric",40);
  set_guild_level("paladin",40);
  set_mlevel("mage",40);
  set_overall_ac(0);
  set_spells_sold(gen_spells_sold(20));
  set_spell_chance(100);
  set_spells(({"sunburst","searing light","searing light","lightning bolt","lighting bolt","magic missile","magic missile","magic missile"}));
   set_emotes(5,({
      "%^MAGENTA%^Godfrey declares%^RESET%^: That Octavia has gone "+
      "too far this time!","%^MAGENTA%^Godfrey declares%^RESET%^: "+
      "I will see that gods-forsaken imp banished back to the hells "+
      "from whence he came!","Godfrey brushes back his golden locks "+
      "and gives a charming smile.","Glancing into a mirror, "+
      "Godfrey brushes imaginary dust off his doublet."
   }),0);
   set_emotes(5,({
      "Godfrey glares righteously at you!","%^MAGENTA%^Godfrey "+
      "declares%^RESET%^: This foul deed will not go unpunished!",
      "%^MAGENTA%^Godfrey declares%^RESET%^: You are a coward and "+
      "a fool!"
   }),1);
}

int __Pickup(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP)) return
::__Pickup(str);
    else {
      tell_object(TP, "%^MAGENTA%^Godfrey declares%^RESET%^: You "+
         "are not authorized to do business here!");
      return 1;
    }
}

int __Buy(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP)) return
::__Buy(str);
    else {
      tell_object(TP, "%^MAGENTA%^Godfrey declares%^RESET%^: You "+
         "are not authorized to do business here!");
      return 1;
    }
}

int __List(string str){ 
    if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP)) return
::__List(str);
    else {
      tell_object(TP, "%^MAGENTA%^Godfrey declares%^RESET%^: You "+
         "are not authorized to do business here!");
      return 1;
    }
}

int __Sell(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP)) return
::__Sell(str);
    else {
      tell_object(TP, "%^MAGENTA%^Godfrey declares%^RESET%^: You "+
         "are not authorized to do business here!");
      return 1;
    }
}

int __Help(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP)) return
::__Help(str);
    else {
      tell_object(TP, "%^MAGENTA%^Godfrey declares%^RESET%^: You "+
         "are not authorized to do business here!");
      return 1;
    }
}
