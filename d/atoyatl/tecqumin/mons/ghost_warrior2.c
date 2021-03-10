//Coded by Lujke, with code plundered from Cythera and Bane
#include <std.h>
#include "../tecqumin.h"

inherit "/std/monster.c";

void create()
{
      string gender_poss,gender_Subj, gender_subj, gender_obj;
      object guider;
      ::create();
      set_property("not random monster", 1);
  	set_name("Ghost warrior");
  	set_id(({"ghost","tecqumin","warrior","tecqumin warrior","monster",
               "tecqumin ghost warrior","ghost warrior",}));
  	set_short("%^RESET%^%^ORANGE%^Tecqumin %^BOLD%^%^WHITE%^gh"
               +"%^RESET%^o%^BOLD%^%^WHITE%^st %^RESET%^"
               +"%^ORANGE%^warrior");
  	set_race("ghost");
  	set_body_type("humanoid");
      set_wielding_limbs(({"right hand","left hand"}));
  	if (random(2)){
        set_gender("male");
        gender_poss = "his";
        gender_Subj = "He";
        gender_subj = "he";
        gender_obj = "him";
      } else {
        set_gender("female");
        gender_poss = "her";
        gender_Subj = "She";
        gender_subj = "she";
        gender_obj = "her";
      }
  	set_long("%^RESET%^A long dead %^ORANGE%^warrior%^RESET%^ of the"
              +" Tecqumin. Once a fierce and proud fighter, " 
              + gender_poss +" spirit now appears as a flickering,"
              +" %^CYAN%^tr%^RESET%^a%^CYAN%^nsl%^RESET%^u%^CYAN%^cent"
              +" %^RESET%^human figure. When at its most visible, you can"
              +" make out the deep bronzed skin stretched tight across a"
              +" lithe, well muscled body. " + gender_Subj + " is dressed"
              +" in a woven kilt, with a multi coloured"
              +" %^RED%^p%^MAGENTA%^o%^ORANGE%^n%^MAGENTA%^c%^ORANGE%^h"
              +"%^RED%^o%^RESET%^ thrown over " + gender_poss 
              +" shoulders. %^YELLOW%^G%^RESET%^%^ORANGE%^ol%^YELLOW%^d"
              +"%^RESET%^%^ORANGE%^e%^YELLOW%^n br%^RESET%^%^ORANGE%^a"
              +"%^YELLOW%^c%^RESET%^%^ORANGE%^e%^YELLOW%^rs%^RESET%^"
              +" adorn " + gender_poss + " arms and " + gender_subj 
              +" wears an abundance of decorative s%^BOLD%^%^WHITE%^i"
              +"%^RESET%^lv%^BOLD%^%^WHITE%^e%^RESET%^r %^BOLD%^"
              +"%^WHITE%^t%^RESET%^or%^BOLD%^%^WHITE%^c%^RESET%^s and"
              +" bangles. At different times, though it %^CYAN%^fl"
              +"%^RESET%^i%^CYAN%^ck%^RESET%^e%^CYAN%^rs%^RESET%^ and"
              +" becomes almost completely invisible, with %^BOLD%^"
              +"%^GREEN%^horrific%^RESET%^ flashes of uncovered"
              +" %^MAGENTA%^m%^BOLD%^%^MAGENTA%^u%^RESET%^%^MAGENTA%^scle"
              +"%^RESET%^, %^BOLD%^%^RED%^f%^MAGENTA%^l%^RESET%^"
              +"%^MAGENTA%^e%^BOLD%^%^MAGENTA%^sh%^RESET%^ and %^BOLD%^"
              +"%^WHITE%^b%^RESET%^o%^BOLD%^%^WHITE%^ne%^RESET%^ striking"
              +" your eyes as different layers of " + gender_poss 
              +" body fade in and out of vision." );
  	set_hd(120,12);
  	set_size(2);
  	set("aggressive",25);
	set_class("fighter");
	set_mlevel("fighter",33);
	set_level(33);
	set_guild_level("fighter",33);
   	set_hp(400 + random(200));
	set_speed(0);

   	set_exp(10000);
	set_max_level(45);
	set_property("swarm",1);
  	set_overall_ac(-25);
      set_stats("strength",18);
      set_stats("dexterity",18);
      set_exp(9000);
  	set_alignment(4);
      set_mob_magic_resistance("average");
      set_property("full attacks",1);
      set_property("swarm", 1); 
//      set_spell_chance(5);
  	set_emotes(2,({
           "The %^CYAN%^translucent%^RESET%^, %^BOLD%^%^WHITE%^g%^RESET%^"
          +"%^ORANGE%^h%^BOLD%^%^WHITE%^ost%^RESET%^%^ORANGE%^l%^BOLD%^"
          +"%^WHITE%^y%^RESET%^%^ORANGE%^ w%^BOLD%^%^WHITE%^a%^RESET%^"
          +"%^ORANGE%^rri%^BOLD%^%^WHITE%^o%^RESET%^%^ORANGE%^r%^RESET%^"
          +" flickers in and out of sight.",
    	}),0);
  	set_emotes(10,({
           "The ghostly warrior %^BOLD%^%^WHITE%^flashes%^RESET%^ and"
          +" disappears for a moment",

          "The ghost of the tecqumin warrior brandishes its ethereal"
         +" weapon",

    	}),1);
      new(OBJ+"ether_knife")->move(TO);
}

void init(){
  ::init();
//  force_me("wield knife");
}

int drag_me(object who){
  if (!objectp(who)){
//    force_me("say Hah! I can't drag that, it doesn't exist!");
    return -1;
  }
  force_me("drag " + who->query_name());
  return 1;
}

 object query_draggee(){
   object * inv;
   int i;

   inv = all_inventory(TO);
   if (sizeof(inv)<1){
     return 0;
   }
   for (i=0;i<sizeof(inv);i++){
     if (living(inv[i])){
       return inv[i];
     }
   }
   return 0;
 }
 
void reach_destination(){
  object draggee;
  if (!objectp(TO)||!objectp(ETO)){
    return;
  }
 
  draggee = query_draggee();
  if (!objectp(draggee)){
    return;
  }
  if (ETO->query_sacrificing()){
    return;
  }
  force_me("say Let all rejoice in the gifts of the %^BOLD%^%^YELLOW%^S"
          +"%^WHITE%^u%^YELLOW%^nl%^WHITE%^o%^YELLOW%^rd%^RESET%^! The"
          +" mighty warriors of the %^ORANGE%^Tecqumin%^RESET%^ bring Him"
          +" another gift of %^RED%^l%^BOLD%^%^RED%^i%^RESET%^%^RED%^febl"
          +"%^BOLD%^%^RED%^oo%^RESET%^%^RED%^d%^RESET%^!");
  force_me("drop " + draggee->query_race());
  ETO->begin_sacrifice(draggee);
}
