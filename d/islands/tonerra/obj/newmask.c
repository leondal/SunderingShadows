#include <std.h>
inherit ARMOUR;

int tracker, trackerb, timer;

void create(){
	::create();
	set_name("ivory half-mask");
	set_id(({ "mask", "half-mask","half mask","ivory mask","ivory half mask","ivory half-mask","ivory halfmask","halfmask","harlequin mask" }));
	set_short("%^BOLD%^%^WHITE%^Harlequin Mask%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^ivory half-mask%^RESET%^");
	set_long("%^RESET%^%^CYAN%^This half mask is of a simple design, one that might be found in any costume shop "
"around the realm. The only difference is that it is made out of a thin, smooth sheet of %^BOLD%^%^WHITE%^pale ivory"
"%^RESET%^%^CYAN%^. Consisting of two ovals that connect with a slightly raised nose and possessing two smaller oval "
"holes through which the eyes might gaze. Unadorned, the mask has a %^BOLD%^%^BLACK%^black ribbon %^RESET%^%^CYAN%^tied "
"to either side, by which the wearer may adjust the fit.%^RESET%^\n");
	set_weight(2);
	set_value(3000);
	set_lore("When Ibrandul died, the story goes that he reached out with his life essence and placed it within the "
"nearest inanimate object available. That object was a simple mask that one of his followers was wearing to cover their "
"identity. In truth, the mask did not belong to one of Ibrandul's faithful but that of a traitor. A traitor whose "
"ability to disguise their true nature via the enchantments within the mask, allowed them to rise within the ranks of "
"Ibrandul's worshippers until he was in a place where he could aid in Shar's attempts to destroy the Skulking God. The "
"use of the mask was a deliberate snubbing of the Mistress of the Night's success as Ibrandul's strength grew within the "
"former traitor, and through him the Lord of the Dry Depths was able to destroy several of Shar's temples before She "
"realized what had happened.");
	set_property("lore difficulty",20);
	set_type("clothing");
	set_limbs(({ "head" }));
	set_size(-1);
    set_property("enchantment",6);
	set_item_bonus("influence",4);
	set_item_bonus("stealth",4);
	set_item_bonus("perception",4);        
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
      set_heart_beat(1);
      timer = 0;
}

void init() {
   ::init();
   add_action("alignswitch","conceal");
}

int wear_func(){
    object *armor;
    int i,FLAG;
    FLAG = 0;
    if((int)ETO->query_lowest_level() < 28){
      tell_object(ETO,"The mask rejects one as weak as you!");
      return 0;
    }
    if(!living(ETO)) return 1;
    if(TP == ETO){
      armor = TP->query_armour("head");
      if(armor != ({})){
        for(i=0;i<sizeof(armor);i++){
          if(((string)armor[i]->query_type() != "ring") && ((string)armor[i]->query_type() != "bracer")) FLAG ++;
        }
        if(FLAG != 0){
          tell_object(TP,"You may not wear the mask with other headgear!");
          FLAG = 0;
          return 0;
        }
      }
    }
    tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" draws the half-mask over "+ETO->QP+" visage.%^RESET%^",ETO);
    tell_object(ETO,"%^BOLD%^%^WHITE%^You draw the half-mask on and gaze about, feeling a sense of obfuscation washing "
"over you.  You feel like you could %^YELLOW%^conceal my alignment%^WHITE%^ with only a thought.%^RESET%^");
    return 1;
}

int remove_func(){
      if(timer) {
        timer = 0;
        if(ETO->query_property("hidden alignment")) ETO->remove_property("hidden alignment");
      }
	tell_room(EETO,"%^BOLD%^%^WHITE%^%^"+ETOQCN+" removes the half-mask, revealing "+ETO->QP+" visage.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^You remove the half-mask and feel the sense of deception slide away.%^RESET%^");
	return 1;
}

void heart_beat(){
    object *armor;
    string *myids;
    int i;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!living(ETO)) return;
    armor = ({});
    armor += ETO->query_armour("head");
    if(TO->query_worn()){
      for(i=0;i<sizeof(armor);i++) {
        if(((string)armor[i]->query_type() != "clothing") && ((string)armor[i]->query_type() != "ring") && ((string)armor[i]->query_type() != "bracer")){
          if(!armor[i]->query_property("no remove")) {
            tell_object(ETO,"The mask rejects the "+armor[i]->query_name()+" you were wearing!");
            myids = armor[i]->query_id();
            ETO->force_me("unwear "+myids[0]+"");
          }
        }
      }
    }
    if(timer) {
      timer--;
      if(!timer && ETO->query_property("hidden alignment")) {
        tell_object(ETO,"%^BOLD%^%^WHITE%^The haze concealing your intentions seems to fade, leaving you feeling "
"vulnerable again.%^RESET%^");
        ETO->remove_property("hidden alignment");
      }
    }
}

int alignswitch(string str){
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!str) return notify_fail("What do you want to conceal?\n");
   if(str != "my alignment") return notify_fail("You can't conceal that.\n");
   if(!TO->query_worn()) return notify_fail("You need to be wearing the mask.\n");
   if((int)ETO->query_property("hidden alignment")) return notify_fail("Your intentions are already masked.\n");
   if(tracker > time()) return notify_fail("You've already spent the power within the mask for today.\n");
   if(trackerb) {
     tracker = time() + 28800;
     trackerb = 0;
   }
   else trackerb = 1;
   tell_object(ETO,"%^BOLD%^%^WHITE%^You focus intently, and feel your intentions become shrouded from the prying eyes "
"of others.%^RESET%^");
   ETO->set_property("hidden alignment",5);
   timer = 1200;
   return 1;
}
