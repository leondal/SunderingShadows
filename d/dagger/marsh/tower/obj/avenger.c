// fixed wear/unwear to use ETO, added obvious short-last change was 7/01  *Styx* 8/2003
// Updated to new desc, abilities, lore, etc by Circe 9/5/04
//Added Auppenser and Sune to the list - Cythera 8/05
//removed some redefines that are already in inherit -Hades 10/18/20
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
    set_id(({"holy avenger","avenger","sword"}));
    set_obvious_short("%^BOLD%^%^WHITE%^A magnificent sword%^RESET%^");
    set_short("%^BOLD%^%^WHITE%^Holy Avenger%^RESET%^");
/*
Original description -
    set_long(
	"%^WHITE%^%^BOLD%^This is the Holy Avenger of the Order of "
	"Paladins. Besides being a tool of destruction against evil "
	"beings, it lends magical protection to the wielder.%^RESET%^"
    );
*/
    set_long("%^BOLD%^This magnificent weapon is a double-edged "+
       "broadsword made of s%^RESET%^h%^BOLD%^i%^RESET%^m%^BOLD%^m"+
       "%^RESET%^e%^BOLD%^r%^RESET%^i%^BOLD%^n%^RESET%^g %^BOLD%^"+
       "white mithril.  Archaic %^CYAN%^runes %^WHITE%^are etched "+
       "in a flowing script along the length of the blade, filled "+
       "with molten %^CYAN%^platinum %^WHITE%^that echoes the finely "+
       "crafted %^CYAN%^platinum crossguard%^WHITE%^.  The crossguard "+
       "is made into an iron cross studded with five small colorless "+
       "gems set into the cross pattern.  Around the "+
       "gems %^WHITE%^is an "+
       "exquisitely detailed pattern of geometric runes against a "+
       "%^BOLD%^%^BLACK%^darkened backdrop %^WHITE%^that brings them "+
       "even more into focus.  The hilt of the sword is wrapped in "+
       "%^RESET%^ageless white leather %^BOLD%^that never seems to "+
       "stain or show any sign of wear - the very %^RED%^blood "+
       "%^WHITE%^of an enemy seems to fall away, leaving it pristine "+
       "once again.  The weapon is completed by the rounded %^CYAN%^"+
       "platinum pommel %^WHITE%^that houses a large, spherical "+
       "colorless gem.%^RESET%^");
    set_lore("Originally crafted by the great weaponsmith Mahavir many "+
       "centuries ago in the year 98 SG, the first Holy Avenger was "+
       "made for a paladin by the name of Erastus Moraine during his "+
       "holy crusades to free the land known as the Dagger marsh from "+
       "what he believed to be a plague upon the land.  Thoughly largely "+
       "unsuccessful in his attempts, Erastus's blade was found to be "+
       "without peer, and many knights of holy orders began requesting "+
       "such a weapon in their own wars against evil.  Mahavir responded "+
       "by taking on several younger apprentices, all of whom learned the "+
       "the secrets of the weapon.  These apprentices were bound to "+
       "secrecy and formed their own order - the Right Hand of "+
       "the Light - which has kept the secret of making this blade "+
       "to this very day.  The members of the Right Hand are unknown, "+
       "and yet the sword still surfaces from time to time, proving "+
       "to some minds that they must still exist.");
    set_read(
@CIRCE
    %^BOLD%^%^WHITE%^The faithful heart may ask for %^CYAN%^aid
    %^WHITE%^When hope and health begin to fade
  The zealous spirit can seek to %^RED%^disrupt
 %^WHITE%^The magic of one whose heart is corrupt
  The weary warrior may send forth a %^YELLOW%^call
     %^WHITE%^To summon a mount, proud and tall
CIRCE
    );
     set_value(10000);
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
  string god = ETO->query_diety();
  string GEM;
  if(!living(ETO)) return 0;
  switch(god){
  case "lysara" :  GEM = "%^RESET%^%^ORANGE%^t%^YELLOW%^i"+
          "%^RESET%^%^ORANGE%^g%^YELLOW%^e%^RESET%^"+
          "%^ORANGE%^r's eye";
  case "kreysneothosies":  GEM = "%^BOLD%^%^MAGENTA%^rose quartz";
      break;
  case "kismet":  GEM = "%^BOLD%^%^BLUE%^st%^WHITE%^a%^BLUE%^"+
          "r sapp%^WHITE%^h%^BLUE%^ire";
      break;
  case "jarmila":  GEM = "%^BOLD%^mo%^RESET%^o%^BOLD%^nst"+
          "%^RESET%^o%^BOLD%^ne";
      break;
  case "lord shadow":  GEM = "%^BOLD%^dia%^CYAN%^m%^WHITE%^ond";
      break;
  default:  GEM = "colorless gem";
      break;
  }
  if(!ETO->is_class("paladin") && !ETO->is_class("cleric") && !ETO->is_class("inquisitor")) {
	tell_object(ETO,"You may not wield this weapon!");
	return 0;
    }
  if((int)ETO->query_true_align() != 1 && (int)ETO->query_true_align() != 2) {
	tell_object(ETO,"You may not wield this weapon!");
	return 0;
    }
    if((string)ETOQN != owned && (string)ETOQN != "knight") {
	tell_object(ETO,"The sword fails to bond with you and vanishes!");
        TO->remove();
        return 0;
    }
  if((int)ETO->query_level() < 25) {
	tell_object(ETO,"You are too inexperienced to wield this weapon!");
	return 0;
    }
    tell_object(ETO,"%^BOLD%^%^WHITE%^The colorless gems on the sword's "+
       "hilt f%^RESET%^l%^BOLD%^i%^RESET%^c%^BOLD%^k%^RESET%^e%^BOLD%^r "+
       "then suddenly %^FLASH%^%^B_CYAN%^flash%^RESET%^%^BOLD%^%^WHITE%^ the color "+
       "of "+GEM+"%^WHITE%^!\n%^BOLD%^%^CYAN%^You feel a holy aura "+
       "embrace you!");
    tell_room(EETO, "%^BOLD%^%^WHITE%^The colorless gems on the "+
       "hilt of "+ETOQCN+"'s sword f%^RESET%^l%^BOLD%^i%^RESET%^c"+
       "%^BOLD%^k%^RESET%^e%^BOLD%^r "+
       "then suddenly %^FLASH%^%^B_CYAN%^flash%^RESET%^%^BOLD%^%^WHITE%^ the color "+
       "of "+GEM+"%^WHITE%^!",ETO);
    set_long("%^BOLD%^This magnificent weapon is a double-edged "+
       "broadsword made of s%^RESET%^h%^BOLD%^i%^RESET%^m%^BOLD%^m"+
       "%^RESET%^e%^BOLD%^r%^RESET%^i%^BOLD%^n%^RESET%^g %^BOLD%^"+
       "white mithril.  Archaic %^CYAN%^runes %^WHITE%^are etched "+
       "in a flowing script along the length of the blade, filled "+
       "with molten %^CYAN%^platinum %^WHITE%^that echoes the finely "+
       "crafted %^CYAN%^platinum crossguard%^WHITE%^.  The crossguard "+
       "is made into an iron cross studded with five small pieces "+
       "of "+GEM+" %^BOLD%^%^WHITE%^set into the cross pattern.  "+
       "Around the pieces of "+GEM+" %^BOLD%^%^WHITE%^is an "+
       "exquisitely detailed pattern of geometric runes against a "+
       "%^BOLD%^%^BLACK%^darkened backdrop %^WHITE%^that brings them "+
       "even more into focus.  The hilt of the sword is wrapped in "+
       "%^RESET%^ageless white leather %^BOLD%^that never seems to "+
       "stain or show any sign of wear - the very %^RED%^blood "+
       "%^WHITE%^of an enemy seems to fall away, leaving it pristine "+
       "once again.  The weapon is completed by the rounded %^CYAN%^"+
       "platinum pommel %^WHITE%^that houses a large, spherical "+
       ""+GEM+"%^BOLD%^%^WHITE%^.%^RESET%^");
    ETO->set_property("good item",1);
    return 1;
}

int removeme() {
  string god = ETO->query_diety();
  string GEM;
  switch(god){
  case "lysara" :  GEM = "%^RESET%^%^ORANGE%^t%^YELLOW%^i"+
          "%^RESET%^%^ORANGE%^g%^YELLOW%^e%^RESET%^"+
          "%^ORANGE%^r's eye";
  case "kreysneothosies":  GEM = "%^BOLD%^%^MAGENTA%^rose quartz";
      break;
  case "kismet":  GEM = "%^BOLD%^%^BLUE%^st%^WHITE%^a%^BLUE%^"+
          "r sapp%^WHITE%^h%^BLUE%^ire";
      break;
  case "jarmila":  GEM = "%^BOLD%^mo%^RESET%^o%^BOLD%^nst"+
          "%^RESET%^o%^BOLD%^ne";
      break;
  case "lord shadow":  GEM = "%^BOLD%^dia%^CYAN%^m%^WHITE%^ond";
      break;
  default:  GEM = "colorless gem";
      break;
  }
    tell_object(ETO,"%^BOLD%^%^WHITE%^The "+GEM+" %^BOLD%^%^WHITE%^"+
       "gems on the sword's "+
       "hilt f%^RESET%^l%^BOLD%^i%^RESET%^c%^BOLD%^k%^RESET%^e%^BOLD%^r "+
       "then fade to a dull, milky color as you let go of the hilt.");
    tell_room(EETO, "%^BOLD%^%^WHITE%^The "+GEM+" %^BOLD%^%^WHITE%^"+
       "gems on the sword's hilt f%^RESET%^l%^BOLD%^i%^RESET%^c%^BOLD%^"+
       "k%^RESET%^e%^BOLD%^r then fade to a dull, milky color as "+
       ""+ETOQCN+" lets go of the hilt.",ETO);
    set_long("%^BOLD%^This magnificent weapon is a double-edged "+
       "broadsword made of s%^RESET%^h%^BOLD%^i%^RESET%^m%^BOLD%^m"+
       "%^RESET%^e%^BOLD%^r%^RESET%^i%^BOLD%^n%^RESET%^g %^BOLD%^"+
       "white mithril.  Archaic %^CYAN%^runes %^WHITE%^are etched "+
       "in a flowing script along the length of the blade, filled "+
       "with molten %^CYAN%^platinum %^WHITE%^that echoes the finely "+
       "crafted %^CYAN%^platinum crossguard%^WHITE%^.  The crossguard "+
       "is made into an iron cross studded with five small colorless "+
       "gems set into the cross pattern.  Around the "+
       "gems %^WHITE%^is an "+
       "exquisitely detailed pattern of geometric runes against a "+
       "%^BOLD%^%^BLACK%^darkened backdrop %^WHITE%^that brings them "+
       "even more into focus.  The hilt of the sword is wrapped in "+
       "%^RESET%^ageless white leather %^BOLD%^that never seems to "+
       "stain or show any sign of wear - the very %^RED%^blood "+
       "%^WHITE%^of an enemy seems to fall away, leaving it pristine "+
       "once again.  The weapon is completed by the rounded %^CYAN%^"+
       "platinum pommel %^WHITE%^that houses a large, spherical "+
       "colorless gem.%^RESET%^");
   ETO->set_property("good item",-1);
   return 1;
}

void failure(){
   tell_object(ETO,"The sword must regain its power before it can "+
      "attempt that again.");
   return 1;
}

int extra_hit() {
    object ob;
    int dam,FLAG,align;
    FLAG = 0;
    ob=ETO->query_current_attacker();
    align = ob->query_alignment();
    if(!objectp(ob)) return random(5);
    if(random(6) > 3) return 1;
    if(random(100)>40){
        if(align == 9 || align == 6 || align == 3) {
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
    switch(random(30)){
      case 0..19:
       tell_object(ETO,"%^BOLD%^%^WHITE%^The sword channels your "+
          "%^MAGENTA%^holy energy%^WHITE%^ into its swing!\n"+
          "%^BOLD%^%^CYAN%^A bright %^RED%^flash%^CYAN%^ is seen "+
          "as you slash at "+ob->QCN+"!%^RESET%^");
          if(FLAG == 1){
             tell_object(ETO,"\n%^BOLD%^%^RED%^The Avenger tells "+
                "you: I detect great evil in our foe!%^RESET%^\n%^RED%^"+
   	          ""+ob->QCN+" screams as the avenger sinks into "
	          ""+ob->QP+" evil flesh!%^RESET%^");
             FLAG = 0;
          }
       tell_room(EETO,"%^BOLD%^%^WHITE%^The sword wielded by "+
          ""+ETOQCN+" %^MAGENTA%^sings %^WHITE%^out to the "+
          "heavens!\n%^BOLD%^%^CYAN%^A bright %^RED%^flash%^CYAN%^ "+
          "is seen as "+ETOQCN+" slashes at "+ob->QCN+"!%^RESET%^",({ETO,ob}));
       tell_object(ob,"%^BOLD%^%^WHITE%^The sword wielded by "+
          ""+ETOQCN+" %^MAGENTA%^sings %^WHITE%^out to the "+
          "heavens!\n%^BOLD%^%^CYAN%^A bright %^RED%^flash"+
          "%^CYAN%^ is seen as "+ETOQCN+" slashes at you!%^RESET%^");
       break;
      case 20..28:
       tell_object(ETO,"%^YELLOW%^Your sword radiates a divine "+
          "light, and you feel the benevolent gaze of "+
          ""+capitalize(ETO->query_diety())+" upon you as you "+
          "strike "+ob->QCN+"!\n%^RED%^A voice utters%^RESET%^: "+
          "Be well, my warrior.\n%^BOLD%^%^CYAN%^You feel "+
          "some of your weariness drain away!");
       tell_object(ob,"%^YELLOW%^"+ETOQCN+"'s sword radiates a brilliant "+
          "light as it slashes into you!");
       tell_room(EETO,"%^YELLOW%^"+ETOQCN+"'s face beams as "+
          ""+ETO->QP+" sword slashes into "+ob->QCN+" with a "+
          "brilliant flash!",({ob,ETO}));
       ETO->add_hp(dam);
       break;
      case 29:
       tell_object(ETO,"%^BOLD%^The sword begins to vibrate in your "+
          "hands, then sends forth a %^YELLOW%^blinding beam of light "+
          "%^WHITE%^at "+ob->QCN+"!");
       tell_object(ob,"%^BOLD%^"+ETOQCN+" points the sword at you, and "+
          "a %^YELLOW%^blinding beam of light %^WHITE%^sprays forth, "+
          "blinding you!");
       tell_room(EETO,"%^BOLD%^"+ETOQCN+" points the sword at "+
          ""+ob->QCN+", causing a %^YELLOW%^beam of light %^WHITE%^"+
          "to shoot forth!",({ETO,ob}));
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
         if((align == 3) || (align == 6) || (align == 9)){
            tell_object(ETO,"%^CYAN%^Your sword glows blue as "+
               "it senses the presence of an evil intent.");
            tell_room(EETO,"%^CYAN%^The sword held by "+ETOQCN+" "+
               "glows blue.",ETO);
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
      tell_object(ETO,"%^BOLD%^%^CYAN%^Your sword glows with a soft "+
         "light and you feel your wounds heal.");
      tell_room(EETO,"%^BOLD%^%^CYAN%^"+ETOQCN+"'s sword glows softly.",ETO);
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
   tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" turns to face "+
      ""+ob->QCN+" and closes "+ETO->QP+" "+
      "eyes while uttering a fervent prayer!",ETO);
   tell_object(ETO,"%^BOLD%^%^WHITE%^You face "+ob->QCN+" and close "+
      "your eyes, uttering a fervent prayer to "+
      ""+capitalize(ETO->query_diety())+"!");
   new("/cmds/spells/d/_dispel_magic")->use_spell(TP,ob,45,100,"cleric");
   TP->set_paralyzed(3,"You are channelling your deity through the sword!");
   return 1;
}

int summon_em(string str)
{
    string god = ETO->query_diety();
    object ob;
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
        tell_object(ETO, "%^CYAN%^You plant the tip of your sword into " +
                    "the ground and spread your arms wide, calling for aid.");
        tell_room(EETO, "%^CYAN%^" + ETOQCN + " plants " + ETO->QP + " sword " +
                  "in the ground and spreads " + ETO->QP + " arms wide.", ETO);
        tell_room(EETO, "%^BOLD%^%^CYAN%^A mighty beast appears before you, answering the call!");
        switch (god) {
        case "lysara": ob = new("/d/common/mounts/panther"); break;
        case "kreysneothosies":  ob = new("/d/common/mounts/gpegasus"); break;
        case "jarmila": ob = new("/d/common/mounts/funicorn"); break;
        case "lord shadow":  ob = new("/d/common/mounts/graywolf"); break;
        default: case "kismet":  ob = new("/d/common/mounts/spegasus");
        }
        if (ob) {
            ob->set_owner(TP);
            ob->move(EETO);
        }
        return 1;
    }
    tell_object(ETO, "You may only ask the sword to <call mount>.");
    return 1;
}
