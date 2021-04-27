// fixed wear/unwear to use ETO, added obvious short-last change was 7/01  *Styx* 8/2003
// Updated to new desc, abilities, lore, etc by Circe 9/6/04
// Additions of specific creatures for each god. Nienne, 2/05 //
// Added Auppenser and Kelemvor - Cythera 8/05
#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/longsword.c";

#define AIDTIME 120
#define DISPELTIME 120
#define SUMMONTIME 240

int aid_time;
int dispel_time;
int summon_time;

object owned;

void init() {
    ::init();
    if(interactive(ETO) && !owned) owned = ETOQN;
    add_action("heal_em","aid");
    add_action("dispel_em","disrupt");
    add_action("summon_em","call");
}

void create() {
    ::create();
    set_name("avenger");
    set_id(({"unholy avenger","avenger","sword"}));
    set_obvious_short("%^BOLD%^%^BLACK%^A flawless darkened sword%^RESET%^");
    set_short("%^BOLD%^%^BLACK%^Unholy Avenger%^RESET%^");
/*
Original desc -
    set_long("%^RESET%^%^BLUE%^This is the Unholy Avenger of the Black Order of "
	"Antipaladins.  Besides being a tool of destruction against holy "
	"beings, it lends magical protection to the wielder.%^RESET%^"
    );
*/
    set_long("%^BOLD%^%^BLACK%^A palpable presence of %^RESET%^"+
       "%^GREEN%^malignancy %^BOLD%^%^BLACK%^arises from this "+
       "frightening weapon.  Over six feet in length, the blade "+
       "appears to be composed of %^GREEN%^souls %^BLACK%^tempered "+
       "into a metallic form.  They writhe and twist in a sickening "+
       "%^RESET%^%^RED%^dance %^BOLD%^%^BLACK%^as waves of spirit "+
       "essence climb in a spiral across the blade.  The blade "+
       "holds a wickedly %^WHITE%^gleaming edge %^BLACK%^while "+
       "the forms of the souls continuously shape into %^RED%^barbs "+
       "%^BLACK%^as they lash out with their own %^WHITE%^teeth "+
       "%^BLACK%^and %^RED%^talons%^BLACK%^.  Multitudes of precious "+
       "colorless gems %^BLACK%^are seamlessly joined together as the "+
       "hilt, with two protrusions of colorless gems %^BLACK%^curved "+
       "out into crosspieces.  Slick with fresh %^RED%^blood%^BLACK%^, "+
       "the hilt appears dangerous to handle.%^RESET%^");
    set_lore("Created as a mocking answer to the swords wielded by "+
       "holy paladins, the swords known as the unholy avengers were "+
       "commissioned originally by the archlich Vecna during the "+
       "last stages of what most consider his true life.  In his "+
       "quest to gain eternal life, the archmage Vecna met a "+
       "'noble' paladin of Helm named Jairus who stood against Vecna's interest "+
       "in necromancy.  After much toil and a battle lasting many "+
       "years, Vecna finally stripped the Holy Avenger from the "+
       "paladin's lifeless body and cackled as he returned to his "+
       "lab.  When he reemerged two years later, the first Unholy "+
       "Avenger was in his hands.");
    set_read(
@CIRCE
    %^BOLD%^%^BLACK%^The blackened heart may ask for %^BLUE%^aid
    %^BLACK%^When blood has seaped along your blade
  The holy one's magic you may call to %^RED%^disrupt
 %^BLACK%^So long as your heart is truly corrupt
  The wicked warrior may send forth a %^YELLOW%^call
     %^WHITE%^To summon a mount, the bane of all
CIRCE
    );
    set_weight(15);
    set_size(2);
    set_value(10000);
    set_wc(1,8);
    set_large_wc(1,12);
    set_type("slashing");
    if((int)TO->query_property("enchantment") < 5){
       remove_property("enchantment");
       set_property("enchantment",5);
    }
    set_item_bonus("sight bonus",2);
    set_prof_type("medium blades");
    set_wield((:TO,"paladin":));
    set_unwield((:TO,"removeme":));
    set_hit((:TO,"extra_hit":));
    set_heart_beat(1);
}

int paladin() {
  string god;
  string GEM;
  object player;
  
  player = environment(this_object());
  player && god = player->query_deity();
  
  if(!player)
      return 0;
  
  switch(god)
  {
      case "the faceless one":  GEM = "%^BOLD%^%^GREEN%^em%^RESET%^%^GREEN%^er"+
          "%^BOLD%^%^BLACK%^a%^GREEN%^ld";
      break;
      case "khyron":
      case "nilith":  GEM = "%^BOLD%^%^RED%^blo%^RESET%^%^RED%^od "+
          "%^BOLD%^%^BLACK%^ruby%^RED%^";
      break;
      case "lysara": GEM = "%^RESET%^%^ORANGE%^ti%^YELLOW%^g"+
          "%^RESET%^%^ORANGE%^er's e%^YELLOW%^y%^RESET%^%^ORANGE%^e";
      break;
      case "kreysneothosies":  GEM = "%^BOLD%^%^RED%^fi%^RESET%^%^RED%^r"+
          "%^BOLD%^e o%^RESET%^%^ORANGE%^pa%^BOLD%^"+
          "%^RED%^l";
      break;
      case "kismet":  GEM = "%^BOLD%^%^BLUE%^st%^BOLD%^%^WHITE%^a%^BOLD%^"+
          "%^BLUE%^r sapp%^BOLD%^%^WHITE%^h%^BOLD%^%^BLUE%^ire";
      break;
      case "lord shadow":  GEM = "%^RESET%^%^MAGENTA%^tan%^BOLD%^%^BLACK%^"+
          "za%^RESET%^%^MAGENTA%^nite";
      break;
      case "nimnavanon" : 
      case "seija" :
          GEM = "%^GREEN%^BOLD%^emerald%^RESET%^";
  break;
      default:  GEM = "colorless";
      break;
   }
   
  if(!player->is_class("paladin") && !player->is_class("inquisitor") && !player->is_class("cleric"))
  {
	tell_object(player,"You may not wield this weapon!");
	return 0;
    }
  if((int)player->query_true_align() != 3&& (int)player->query_true_align() != 2) {
	tell_object(ETO,"You may not wield this weapon!");
	return 0;
    }
    if((string)ETOQN != owned && (string)ETOQN != "angel") {
	tell_object(ETO,"The sword fails to bond with you and vanishes!");
        TO->remove();
        return 0;
    }
   if((int)ETO->query_level() < 25) {
	tell_object(ETO,"You are too inexperienced to wield this weapon!");
	return 0;
    }
    tell_object(ETO,"%^BOLD%^%^BLACK%^The %^GREEN%^souls %^BLACK%^"+
       "trapped in the blade shriek and the gems %^B_RED%^%^WHITE%^"+
       "%^FLASH%^flash %^RESET%^%^BOLD%^%^BLACK%^into "+GEM+" "+
       "%^BOLD%^%^BLACK%^as you wield the blade!\n%^BOLD%^%^RED%^You "+
       "feel an unholy aura encompass you!");
    tell_room(EETO, "%^BOLD%^%^BLACK%^The %^GREEN%^souls %^BLACK%^"+
       "trapped in the blade shriek and the gems %^B_RED%^%^WHITE%^"+
       "%^FLASH%^flash %^RESET%^%^BOLD%^%^BLACK%^ into "+GEM+" "+
       "%^BOLD%^%^BLACK%^as "+ETOQCN+" %^BOLD%^%^BLACK%^wields the blade!",ETO);
    set_long("%^BOLD%^%^BLACK%^A palpable presence of %^RESET%^"+
       "%^GREEN%^malignancy %^BOLD%^%^BLACK%^arises from this "+
       "frightening weapon.  Over six feet in length, the blade "+
       "appears to be composed of %^GREEN%^souls %^BLACK%^tempered "+
       "into a metallic form.  They writhe and twist in a sickening "+
       "%^RESET%^%^RED%^dance %^BOLD%^%^BLACK%^as waves of spirit "+
       "essence climb in a spiral across the blade.  The blade "+
       "holds a wickedly %^WHITE%^gleaming edge %^BLACK%^while "+
       "the forms of the souls continuously shape into %^RED%^barbs "+
       "%^BLACK%^as they lash out with their own %^WHITE%^teeth "+
       "%^BLACK%^and %^RED%^talons%^BLACK%^.  Multitudes of precious "+
       ""+GEM+" gems %^BLACK%^are seamlessly joined together as the "+
       "hilt, with two protrusions of "+GEM+" gems %^BLACK%^curved "+
       "out into crosspieces.  Slick with fresh %^RED%^blood%^BLACK%^, "+
       "the hilt appears dangerous to handle.%^RESET%^");
    ETO->set_property("evil item",1);
    return 1;
}

int removeme() {
  string god = ETO->query_diety();
  string GEM;
  switch(god){
  case "the faceless one":  GEM = "%^BOLD%^%^GREEN%^em%^RESET%^%^GREEN%^er"+
          "%^BOLD%^%^BLACK%^a%^GREEN%^ld";
      break;
  case "khyron":
  case "nilith":  GEM = "%^BOLD%^%^RED%^blo%^RESET%^%^RED%^od "+
          "%^BOLD%^%^BLACK%^ruby%^RED%^";
      break;
  case "lysara": GEM = "%^RESET%^%^ORANGE%^ti%^YELLOW%^g"+
          "%^RESET%^%^ORANGE%^er's e%^YELLOW%^y%^RESET%^%^ORANGE%^e";
      break;
  case "kreysneothosies":  GEM = "%^BOLD%^%^RED%^fi%^RESET%^%^RED%^r"+
          "%^BOLD%^e o%^RESET%^%^ORANGE%^pa%^BOLD%^"+
          "%^RED%^l";
      break;
  case "kismet":  GEM = "%^BOLD%^%^BLUE%^st%^BOLD%^%^WHITE%^a%^BOLD%^"+
          "%^BLUE%^r sapp%^BOLD%^%^WHITE%^h%^BOLD%^%^BLUE%^ire";
      break;
  case "lord shadow":  GEM = "%^RESET%^%^MAGENTA%^tan%^BOLD%^%^BLACK%^"+
          "za%^RESET%^%^MAGENTA%^nite";
      break;
  case "nimnavanon" : 
  case "seija" :
      GEM = "%^GREEN%^BOLD%^emerald%^RESET%^";
  break;
  default:  GEM = "colorless";
      break;
   }
    tell_object(ETO,"%^BOLD%^%^BLACK%^You hear soft sighs as you unwield "+
       "the sword and watch the "+GEM+" gems lose all color once more.");
    tell_room(EETO, "%^BOLD%^%^BLACK%^A wind whips through the area "+
       "as "+ETOQCN+" lowers "+ETO->QP+" sword and the gems in the "+
       "hilt lose their color.",ETO);
    set_long("%^BOLD%^%^BLACK%^A palpable presence of %^RESET%^"+
       "%^GREEN%^malignancy %^BOLD%^%^BLACK%^arises from this "+
       "frightening weapon.  Over six feet in length, the blade "+
       "appears to be composed of %^GREEN%^souls %^BLACK%^tempered "+
       "into a metallic form.  They writhe and twist in a sickening "+
       "%^RESET%^%^RED%^dance %^BOLD%^%^BLACK%^as waves of spirit "+
       "essence climb in a spiral across the blade.  The blade "+
       "holds a wickedly %^WHITE%^gleaming edge %^BLACK%^while "+
       "the forms of the souls continuously shape into %^RED%^barbs "+
       "%^BLACK%^as they lash out with their own %^WHITE%^teeth "+
       "%^BLACK%^and %^RED%^talons%^BLACK%^.  Multitudes of precious "+
       "colorless gems %^BLACK%^are seamlessly joined together as the "+
       "hilt, with two protrusions of colorless gems %^BLACK%^curved "+
       "out into crosspieces.  Slick with fresh %^RED%^blood%^BLACK%^, "+
       "the hilt appears dangerous to handle.%^RESET%^");
   ETO->set_property("evil item",-1);
   return 1;
}

void failure(){
   tell_object(ETO,"The sword must regain its power before it can "+
      "attempt that again.");
   return 1;
}

int extra_hit() {
    object ob;
    string godpos;
    int dam,FLAG,align;
    FLAG = 0;
    ob=ETO->query_current_attacker();
    align = ob->query_alignment();
    if(!objectp(ob)) return random(5);
    if(random(6) > 3) return 1;
    if(random(100)>40){
        if(align == 7 || align == 4 || align == 1) {
            FLAG = 1;
            dam = dam + random(5) + 1;
        } else {
	    dam = dam + random(2) - random(2);
        }
    }
    if(random(100) > 50) {
        dam = dam + random(6) + 2;
    } else {
        dam = dam + random(3) + 1;
    }
    switch((string)ETO->query_diety()){
      case "nilith":  godpos = "her";
                     break;
      case "kismet":  godpos = "her";
                       break;
      case "seija":  godpos = "her";
                    break;
      default:  godpos = "his";
                break;
    }
    switch(random(30)){
      case 0..19:
       tell_object(ETO,"%^BOLD%^%^BLACK%^The sword channels your "+
          "%^RED%^unholy energy%^BLACK%^ into its swing!\n"+
          "%^BOLD%^%^RED%^A bright %^GREEN%^flash%^RED%^ is seen "+
          "as you slash at "+ob->QCN+"!%^RESET%^");
          if(FLAG == 1){
             tell_object(ETO,"\n%^BOLD%^%^RED%^The Avenger tells "+
                "you: I detect the weakness of a good soul in our foe"+
                ".%^RESET%^\n%^RED%^"+ob->QCN+" screams as "+
                "the avenger sinks into "+ob->QP+" holy flesh!%^RESET%^");
             FLAG = 0;
          }
       tell_room(EETO,"%^BOLD%^%^BLACK%^The sword wielded by "+ETOQCN+" "+
          "%^RED%^echoes %^BLACK%^with the voices of the hells!"+
          "\n%^BOLD%^%^RED%^A bright %^GREEN%^flash%^RED%^ is seen as "+
          ""+ETOQCN+" slashes at "+ob->QCN+"!%^RESET%^",({ETO,ob}));
       tell_object(ob,"%^BOLD%^%^BLACK%^The sword wielded by "+ETOQCN+" "+
          "%^RED%^echoes %^BLACK%^with the voices of the hells!"+
          "\n%^BOLD%^%^RED%^A bright %^GREEN%^flash%^RED%^ is seen as "+
          ""+ETOQCN+" slashes at you!%^RESET%^");
       break;
      case 20..28:
       tell_object(ETO,"%^BOLD%^%^BLACK%^The %^GREEN%^souls %^BLACK%^"+
          "in your sword call fervently to "+
          ""+capitalize(ETO->query_diety())+" and draw "+godpos+" "+
          "gaze to you!\n%^RED%^A voice utters%^RESET%^: "+
          "Be well, my warrior.\n%^BOLD%^%^RED%^You see the souls' "+
          "barbs steal "+ob->QCN+"'s life away!");
       tell_object(ob,"%^BOLD%^%^GREEN%^The barbs on "+ETOQCN+"'s "+
          "sword pierce you and steal your life away!");
       tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" strikes "+
          ""+ob->QCN+" as the %^GREEN%^souls %^BLACK%^within "+
          ""+ETO->QP+" sword sprout %^RED%^barbs%^BLACK%^!",({ob,ETO}));
       ETO->add_hp(dam);
       break;
      case 29:
       tell_object(ETO,"%^BOLD%^%^BLACK%^The sword begins to vibrate in your "+
          "hands, then sends forth a %^BLUE%^cloud of pure malevolence "+
          "%^BLACK%^at "+ob->QCN+"!");
       tell_object(ob,"%^BOLD%^%^BLACK%^"+ETOQCN+" points the sword "+
          "at you, and an %^BLUE%^inky black cloud %^BLACK%^rolls over "+
          "you!");
       tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" points the sword at "+
          ""+ob->QCN+", causing an %^BLUE%^inky black cloud %^BLACK%^"+
          "to roll over "+ob->QO+"!",({ETO,ob}));
       if(random(22) > (int)ob->query_stats("constitution")){
          ob->set_blind(1);
       }
       break;
      default:  break;
   }
   return dam;
}

void heart_beat(){
object *live;
object targ;
int align, i, counter;
   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   if(!living(ETO)) return;
   if(!objectp(EETO)) return;
   live = all_living(EETO);
   live = filter_array(live, "is_non_immortal_player", FILTERS_D);
   if(TO->query_wielded()){
     if(!random(20)){
      for(i=0;i<sizeof(live);i++){
         targ = live[i];
         if(!objectp(targ)) continue;
         align = targ->query_alignment();
         if((align == 1) || (align == 4) || (align == 7)){
            tell_object(ETO,"%^BOLD%^%^BLACK%^Your sword darkens as "+
               "it senses the presence of a good heart.");
            tell_room(EETO,"%^BOLD%^%^BLACK%^The sword held by "+ETOQCN+" "+
               "darkens.",ETO);
            continue;
         }
       }
      }
   }
}

int heal_em(string str){
object ob;
   if (ETO->query_bound() || ETO->query_unconscious() || ETO->query_paralyzed()) {
        ETO->send_paralyzed_message("info",ETO);
    }
   if(!str){
      tell_object(ETO,"You may ask your deity for aid through your "+
         "sword - <aid me>");
      return 1;
   }
   if(!TO->query_wielded()){
      tell_object(ETO,"You must be wielding the sword to call on its power.");
      return 1;
   }
   if(AIDTIME > (time() - aid_time)) {
      failure();
      return 1;
   }
   if(str == "me"){
      aid_time = time();
      tell_object(ETO,"%^BOLD%^%^BLACK%^You hear whispering voices as "+
         "the souls swirl and you feel your wounds heal.");
      tell_room(EETO,"%^BOLD%^%^BLACK%^The souls in "+ETOQCN+"'s sword "+
         "swirl and whisper.",ETO);
      ETO->set_hp(ETO->query_max_hp());
      ETO->heal(1);
      return 1;
   }
   tell_object(ETO,"You may only ask the sword to <aid me>.");
   return 1;
}

int dispel_em(string str){
object ob;
   if (ETO->query_bound() || ETO->query_unconscious()
    || ETO->query_paralyzed()) {
        ETO->send_paralyzed_message("info",ETO);
    }
   if(!str){
      tell_object(ETO,"You may ask your sword to <disrupt target>.");
      return 1;
   }
   if(!TO->query_wielded()){
      tell_object(ETO,"You must be wielding the sword to call on its power.");
      return 1;
   }
   if(!(ob = present(str, ETP))) return notify_fail("You do not see that!\n");
   if(DISPELTIME > (time() - dispel_time)) {
      failure();
      return 1;
   }
   dispel_time = time();
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" sneers as "+ETO->QS+" "+
      "turns to face "+ob->QCN+" and utters a dark command!",ETO);
   tell_object(ETO,"%^BOLD%^%^BLACK%^You face "+ob->QCN+" with a "+
      "sneer and utter the dark command of "+
      ""+capitalize(ETO->query_diety())+"!");
   new("/cmds/spells/d/_dispel_magic")->use_spell(TP,ob,45,100,"cleric");
   TP->set_paralyzed(3,"You are channelling your deity through the sword!");
   return 1;
}

int summon_em(string str)
{
    string god = ETO->query_diety();
    object ob;
    god = ETO->query_diety();
    if (ETO->query_bound() || ETO->query_unconscious()
        || ETO->query_paralyzed()) {
        ETO->send_paralyzed_message("info", ETO);
    }
    if (str != "mount") {
        return 0;
    }
    if (!TO->query_wielded()) {
        tell_object(ETO, "You must be wielding the sword to call on its power.");
        return 1;
    }
    if (str == "mount") {
        if (SUMMONTIME > (time() - summon_time)) {
            failure();
            return 1;
        }
        summon_time = time();
        tell_object(ETO, "%^BOLD%^%^BLACK%^You plant the tip of your sword into " +
                    "the ground and spread your arms wide, calling for aid.");
        tell_room(EETO, "%^BOLD%^%^BLACK%^" + ETOQCN + " plants " + ETO->QP + " sword " +
                  "in the ground and spreads " + ETO->QP + " arms wide.", ETO);
        tell_room(EETO, "%^BOLD%^%^RED%^A mighty beast appears before you, answering the call!");
        switch (god) {
        case "the faceless one":  ob = new("/d/common/mounts/dpegasus"); break;
        case "grumbar":  ob = new("/d/common/mounts/bulette"); break;
        case "lysara": ob = new("/d/common/mounts/panther"); break;
        case "nilith":  ob = new("/d/common/mounts/nightmare"); break;
        case "kreysneothosies":  ob = new("/d/common/mounts/panther"); break;
        case "lord shadow":  ob = new("/d/common/mounts/shadowsteed"); break;
        default:  ob = new("/d/common/mounts/kirre"); break;
        }
        ob->set_owner(TP);
        ob->move(EETO);
        return 1;
    }
    tell_object(ETO, "You may only ask the sword to <call mount>.");
    return 1;
}
