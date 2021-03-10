//balanced for +6 - Yves 9/3/19
//slight change by ~Circe~ 5/7/11 to query the enchantment of the spear
//in response to a bug report by a player who increased the enchantment to +7

//MephistarSword alternative to the great hammer on player request
#include <std.h>
inherit "/d/common/obj/weapon/shortsword.c";

void create(){
   ::create();
   set_name("Fang of Mephistar");
   set_id(({"fang","Fang of Mephistar", "fang of destruction", "fang of mephistar","mephistar","sword","shortsword","sword of destruction","shortsword of destruction","sword of mephistar","gladius","gladius of destruction","gladius of mephistar","talon" }));
   set_obvious_short("%^BOLD%^%^BLACK%^A %^CYAN%^r%^RESET%^%^CYAN%^i%^BOLD%^me co%^BLACK%^a%^CYAN%^ted %^BLACK%^sh%^CYAN%^o%^BLACK%^rtsw%^CYAN%^o%^BLACK%^rd%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^F%^CYAN%^a%^BLACK%^n%^BLUE%^g %^BLUE%^o%^BLACK%^f M%^CYAN%^e%^BLACK%^p%^BLUE%^h%^CYAN%^i%^BLUE%^s%^BLACK%^t%^RED%^a%^BLACK%^r%^RESET%^");
   set_long("%^%^BOLD%^%^BLACK%^Coated in a thick layer of %^BLUE%^f%^WHITE%^r%^CYAN%^o%^WHITE%^s%^BLUE%^t%^BLACK%^, this incredible weapon positively thrums with %^RESET%^%^RED%^p%^BOLD%^%^YELLOW%^o%^RESET%^%^RED%^w%^BOLD%^%^YELLOW%^e%^RESET%^%^RED%^r%^BOLD%^%^BLACK%^.  A br%^RED%^i%^BLACK%^ll%^RED%^i%^YELLOW%^a%^BLACK%^nt"+
   " %^RED%^r%^RESET%^%^RED%^u%^BOLD%^b%^RESET%^%^RED%^y%^BOLD%^%^BLACK%^ sp%^RED%^i%^BLACK%^ke forms the pommel, l%^RED%^i%^BLACK%^q%^YELLOW%^u%^RED%^i%^BLACK%^d %^RED%^f%^YELLOW%^i%^RED%^r%^YELLOW%^e%^BLACK%^ churning within its multifaceted depths."+
   "  The c%^BLUE%^o%^BLACK%^ld dark grip of the weapon is decorated with intricate jagged etchings that pulse faintly %^BLUE%^bl%^CYAN%^u%^WHITE%^e%^BLACK%^ beneath the %^BLUE%^r%^CYAN%^i%^BLACK%^m%^BLUE%^e%^BLACK%^. Small studs of onyx ring the grip, each one completely free of ice and producing a barely visible %^RESET%^%^RED%^r%^BOLD%^e%^RESET%^%^RED%^d%^BOLD%^%^BLACK%^d%^RED%^i%^RESET%^%^RED%^s%^BOLD%^%^BLACK%^h l%^RED%^i%^BLACK%^ght from its depths."+
   "  An incredibly detailed devilish visage crowns the hilt, its curled horns forming the guard and streams of %^RESET%^%^RED%^f%^BOLD%^%^YELLOW%^i%^BLACK%^e%^RED%^r%^YELLOW%^y e%^RED%^n%^YELLOW%^e%^RED%^r%^BLACK%^g%^YELLOW%^y%^BLACK%^ spilling forth from the empty sockets of its eyes."+
   "  From the devils fanged maw spring forth a long broad  bl%^BLUE%^a%^BLACK%^de of fr%^BLUE%^o%^BLACK%^st %^BLUE%^e%^BLACK%^nc%^CYAN%^a%^BLACK%^s%^BLUE%^e%^BLACK%^d %^YELLOW%^a%^BLACK%^d%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^m%^YELLOW%^a%^BLACK%^nt%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^n%^YELLOW%^e%^BLACK%^. Veins of what appears to be %^RED%^m%^YELLOW%^o%^RED%^lt%^YELLOW%^e%^RED%^n f%^YELLOW%^i%^RED%^r%^YELLOW%^e%^BOLD%^%^BLACK%^ run the length of the blade in perfectly symmetrical paths."+
   "  The entire length of the blade is perfectly balanced though strangely despite the ice clinging to the weapon it seems to radiate %^RED%^h%^YELLOW%^e%^RED%^a%^BLACK%^t. A palpable aura of %^RESET%^%^RED%^evil%^BOLD%^%^BLACK%^ surrounds the %^BLUE%^s%^BLACK%^wo%^CYAN%^r%^BLACK%^d, ch%^BLUE%^i%^BLACK%^ll%^BLUE%^i%^BLACK%^ng you to the core.%^RESET%^");
   set_lore("%^BOLD%^%^BLACK%^It is said that the lord of the 8th, Mephistopheles, forged this mighty weapon from the very heart of his ice fortress Mephistar. Granting it as a reward to his champion Bele for his enormous contributions in the battles against Baalzebul."+
   "  Bele was sent into the heart of the volcano of Tonerra by his lord when it was discovered that the dead god Ibrandul had been interred there. Hoping to claim any remaining scrap of divine essence so that he might challenge Asmodeus for dominion of hell, Mephistopheles was eager to see his justicar return successful."+
   "  Unfortunately it seems that the dead god still retained enough power to destroy the Arch devils Champion and his mighty weapon was claimed as a reminder to the fiends that even a dead god is beyond them.%^RESET%^  %^BOLD%^%^BLACK%^Legends claim that in his descend into the heart of the volcano Bele was able to %^RESET%^%^CYAN%^transform %^BOLD%^%^BLACK%^the his mighty weapon from a gladius into an intimidating spear at will."+
   "  In its most potent form he was also able to channel the very power of Mephistar through his blade, conjuring great glacial walls to crush any means of escape his enemies might have.%^RESET%^");
   set_property("lore difficulty",25);
   set_property("enchantment",6);
   set_item_bonus("attack bonus",5);
   set_item_bonus("damage bonus",5);
   set_item_bonus("influence",5);
   set_weight(8); //to match weight of spear since same weapon
   set_value(5000);
   set_hit((:TO,"hitme":));
   set_wield((:TO,"wieldme":));
   set_unwield((:TO,"unwieldme":));
//   set_weapon_prof("exotic"); // removed for inherit fixing, N 2/20
}

int wieldme(){
   if(!wizardp(ETO)){
      if((int)ETO->query_highest_level() < 35 || member_array("Solved the mystery of Ibrandul",ETO->query_mini_quests()) ==-1){
         tell_object(ETO,"%^BOLD%^%^CYAN%^You are unable to wield the frosty sword!%^RESET%^");
         return 0;
      }
   }
   tell_object(ETO," %^BOLD%^%^BLACK%^As you gr%^BLUE%^i%^BLACK%^p the weapon %^WHITE%^s%^RESET%^t%^BOLD%^e%^RESET%^a%^BOLD%^m%^BLACK%^ rises from the point of contact%^RESET%^ ");
   tell_room(environment(ETO)," %^BOLD%^%^BLACK%^As "+ETO->QCN+" gr%^BLUE%^i%^BLACK%^ps the weapon %^WHITE%^s%^RESET%^t%^BOLD%^e%^RESET%^a%^BOLD%^m%^BLACK%^ rises from the point of contact%^RESET%^ ",ETO);
   return 1;
}

int unwieldme(){
   tell_object(ETO," %^BOLD%^%^CYAN%^A slight crackling can be heard as you release your grip on the cold weapon. ");
   tell_room(environment(ETO),"%^BOLD%^%^CYAN%^A slight crackling can be heard as "+ETO->QCN+" releases the chilling weapon.",ETO);
   return 1;
}

int hitme(object targ){
   if(!objectp(targ)) return roll_dice(1,4);
   if(random(100) > 40) return roll_dice(1,4);
   switch(random(10)){
      case 0..1:
         tell_room(EETO,"%^BLUE%^"+ETO->QCN+" suddenly turns and slams the pommel of the sword it into "+targ->QCN+"'s  face!%^RESET%^ ",({targ,ETO}));
         tell_object(targ,"%^BLUE%^"+ETO->QCN+" suddenly turns and slams the pommel of "+ETO->QP+" sword into your face!%^RESET%^!");
         tell_object(ETO," %^BLUE%^You turn suddenly and slam the pommel of your sword into "+targ->QCN+"'s  face!%^RESET%^");
         targ->set_paralyzed(roll_dice(2,8)," %^RED%^ You are still reeling from the blow!%^RESET%^");
         return roll_dice(2,8);

      case 2..3:
         tell_room(EETO," %^BOLD%^%^BLACK%^"+ETO->QCN+" whirls the sword effortlessly around "+ETO->QO+", slashing through "+targ->QCN+" in rapid succession!%^RESET%^",({targ,ETO}));
         tell_object(targ," %^BOLD%^%^BLACK%^"+ETO->QCN+"  whirls the sword effortlessly around "+ETO->QO+", slashing through you in rapid succession!%^RESET%^");
         tell_object(ETO,"%^BOLD%^%^BLACK%^You whirl the sword effortlessly around yourself, slashing through "+targ->QCN+"  in rapid succession!%^RESET%^");
         ETO->execute_attack();
         return roll_dice(2,6);

      case 4..8:
         tell_object(targ," %^RED%^"+ETO->QCN+"'s blade slashes into you releasing a gout of %^RESET%^s%^BOLD%^t%^RESET%^e%^BOLD%^a%^RESET%^m%^RED%^ and %^BOLD%^h%^YELLOW%^e%^RED%^l%^BLACK%^l%^RED%^f%^YELLOW%^i%^RED%^r%^YELLOW%^e%^RESET%^%^RED%^ that burn you horribly!!");
         tell_room(EETO," %^RED%^"+ETO->QCN+"'s blade slashes into "+targ->QCN+" releasing a gout of %^RESET%^s%^BOLD%^t%^RESET%^e%^BOLD%^a%^RESET%^m%^RED%^ and %^BOLD%^h%^YELLOW%^e%^RED%^l%^BLACK%^l%^RED%^f%^YELLOW%^i%^RED%^r%^YELLOW%^e%^RESET%^%^RED%^!%^RESET%^",({targ,ETO}));
         tell_object(ETO," %^RED%^Your blade slashes into "+targ->QCN+"  releasing a gout of %^RESET%^s%^BOLD%^t%^RESET%^e%^BOLD%^a%^RESET%^m%^RED%^ and %^BOLD%^h%^YELLOW%^e%^RED%^l%^BLACK%^l%^RED%^f%^YELLOW%^i%^RED%^r%^YELLOW%^e%^RESET%^%^RED%^!%^RESET%^");
         return roll_dice(4,8);
      case 9: // added to bring parity with other med/large weps. N, 2/20.
      if(targ->query_stoneSkinned()){
         tell_room(EETO," %^BOLD%^%^BLUE%^As "+ETO->QCN+"'s blade sinks into "+targ->QCN+", fr%^CYAN%^o%^BLUE%^s%^WHITE%^t%^BLUE%^ spreads across "+targ->QP+" body impossibly fast before suddenly %^WHITE%^sh%^BLUE%^%^WHITE%^attering!%^RESET%^",({targ,ETO}));
         tell_object(targ,"%^BOLD%^%^BLUE%^As the blade "+ETO->QCN+" sinks into you, chilling fr%^CYAN%^o%^BLUE%^s%^WHITE%^t%^BLUE%^ spreads across your body impossibly fast before suddenly %^WHITE%^shattering %^BLUE%^in an agonizing explosion that takes your magical protections with it!%^RESET%^");
         tell_object(ETO," %^BOLD%^%^BLUE%^As your blade sinks into "+targ->QCN+", fr%^CYAN%^o%^BLUE%^s%^WHITE%^t%^BLUE%^ spreads across "+targ->QP+" body impossibly fast before suddenly %^WHITE%^sh%^BLUE%^a%^WHITE%^ttering!%^RESET%^");
         targ->set_stoneSkinned(0);
      }
      else{
         tell_room(EETO,"%^BOLD%^%^BLUE%^As "+ETO->QCN+"'s blade sinks into "+targ->QCN+", fr%^CYAN%^o%^BLUE%^s%^WHITE%^t%^BLUE%^ spreads across "+targ->QP+" body impossibly fast before suddenly %^WHITE%^sh%^BLUE%^%^WHITE%^attering!%^RESET%^",({targ,ETO}));
         tell_object(targ,"%^BOLD%^%^BLUE%^As "+ETO->QCN+"'s blade sinks into you, chilling fr%^CYAN%^o%^BLUE%^s%^WHITE%^t%^BLUE%^ spreads across your body impossibly fast before suddenly %^WHITE%^shattering %^BLUE%^ in an agonizing explosion that leaves you shaken from its blow!%^RESET%^");
         tell_object(ETO," %^BOLD%^%^BLUE%^As your blade sinks into "+targ->QCN+", fr%^CYAN%^o%^BLUE%^s%^WHITE%^t%^BLUE%^ spreads across "+targ->QP+" body impossibly fast before suddenly %^WHITE%^sh%^BLUE%^a%^WHITE%^ttering!%^RESET%^");
         targ->set_paralyzed(roll_dice(1,8)," %^BOLD%^%^WHITE%^The numbing cold grips your limbs!%^RESET%^");
      }
   }
   return 1;
}
void init(){
    ::init();
    if(!objectp(TP)) return;
    if(!objectp(ETO)) return;
    if(TP != ETO) return;
    add_action("transform","transform");
}

int transform(string str){
   object ob,theplayer,*names;
   int i,myenchant;
   if (!str) {
      notify_fail("Transform what?");
      return 0;
   }
   if(!query_wielded()){
      notify_fail("You must be wielding the sword to command it!");
      return 0;
   }
   if(!str == "spear"||str=="spear of mephistar"||str=="spear of destruction"){
      notify_fail("That is beyond the sword's capability!");
      return 0;
   }
   if (TP != ETO) {
      notify_fail("You should pick that up first.\n");
      return 0;
   }
   myenchant = TO->query_property("enchantment");
//   TO->set_weight(0);
// so this doesn't actually work as it's already in inven and doesn't reduce player carry capacity on the command. New weapon needs to be moved AFTER old is gone. N, 12/15.
   ob = new("/d/islands/tonerra/obj/mephistar.c");
//it was still pulling from Tsera's directory. Changed that ~Circe~ 5/7/11
//   ob->move(ETO);
   if((int)TO->query_property("enchantment") < 0) {
      ob->remove_property("enchantment");
      ob->set_property("enchantment",(int)TO->query_property("enchantment"));
   }else{
      while((int)ob->query_property("enchantment") != myenchant) {
         ob->remove_property("enchantment");
         ob->set_property("enchantment",myenchant);
      }
   }
   if (TO->query_identified()) {
      names = TO->query_identified();
      for (i=0;i<sizeof(names);i++) {
         ob->add_identified(names[i]);
      }
   }
//added the below to take care of the problem with wizard oil ~Circe~ 9/5/11
   if(TO->query_property("able to cast")){
      ob->set_property("able to cast",1);
   }
   if(TO->query_property("soulbound")) ob->set_property("soulbound",1);
   tell_object(ETO," %^BOLD%^%^BLACK%^The handle of the sword expands to considerable length, becoming an intimidating spear!%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^BLACK%^The handle of "+ETO->QCN+"'s sword expands to considerable length, becoming an intimidating spear!%^RESET%^",ETO);
   ETO->force_me("unwield sword of destruction");
   theplayer = ETO;
   TO->move("/d/shadowgate/void");
   ob->move(theplayer);
   theplayer->force_me("wield spear of destruction");
   TO->remove();
   return 1;
}
