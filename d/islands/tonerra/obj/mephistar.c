//balanced for +6 - Yves 9/3/19
//slight change by ~Circe~ 5/7/11 to query the enchantment of the spear
//in response to a bug report by a player who increased the enchantment to +7
//Mephistar alternative to the great hammer on player request

#include <std.h>
//inherit "/d/common/obj/weapon/spear_lg.c";
inherit "/d/common/obj/weapon/glaive.c";
// using glaive as the closest martial match for the weapon (so shortsword same prof when switched). N, 2/20

void badStuff();

void create(){
   ::create();
   set_name("Spear of Mephistar");
   set_id(({"spear","large spear","Spear of Mephistar","spear of destruction","spear of mephistar","mephistar","spire","spire of mephistar","large spire","polearm"}));
set_obvious_short("%^BOLD%^%^BLACK%^A %^BLUE%^r%^CYAN%^i%^BLACK%^m%^BLUE%^e %^BLACK%^co%^BLUE%^a%^BLACK%^ted sp%^BLUE%^e%^CYAN%^a%^BLACK%^r%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^Sp%^CYAN%^i%^BLACK%^r%^BLUE%^e %^BLUE%^o%^BLACK%^f M%^CYAN%^e%^BLACK%^p%^BLUE%^h%^CYAN%^i%^BLUE%^s%^BLACK%^t%^RED%^a%^BLACK%^r%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Coated in a thick layer of %^BLUE%^f%^WHITE%^r%^CYAN%^o%^WHITE%^s%^BLUE%^t%^BLACK%^, this incredible weapon positively thrums with %^RESET%^%^RED%^p%^BOLD%^%^YELLOW%^o%^RESET%^%^RED%^w%^BOLD%^%^YELLOW%^e%^RESET%^%^RED%^r%^BOLD%^%^BLACK%^."+
   "  A br%^RED%^i%^BLACK%^ll%^RED%^i%^YELLOW%^a%^BLACK%^nt %^RED%^r%^RESET%^%^RED%^u%^BOLD%^b%^RESET%^%^RED%^y %^BOLD%^%^BLACK%^spike forms the cap, l%^RED%^i%^BLACK%^q%^YELLOW%^u%^RED%^i%^BLACK%^d %^RED%^f%^YELLOW%^i%^RED%^r%^YELLOW%^e%^BLACK%^ churning within its multifaceted depths. The c%^BLUE%^o%^BLACK%^ld dark shaft of the weapon is decorated with intricate jagged etchings that pulse faintly %^BLUE%^bl%^CYAN%^u%^WHITE%^e%^BLACK%^ beneath the"+
   " %^BLUE%^r%^CYAN%^i%^BLACK%^m%^BLUE%^e%^BLACK%^. Small studs of onyx ring the grip, each one completely free of ice and producing a barely visible %^RESET%^%^RED%^r%^BOLD%^e%^RESET%^%^RED%^d%^BOLD%^%^BLACK%^d%^RED%^i%^RESET%^%^RED%^s%^BOLD%^%^BLACK%^h l%^RED%^i%^BLACK%^ght from its depths.  An incredibly detailed devilish visage crowns the polearm, complete with curling horns and streams of "+
   "%^RESET%^%^RED%^f%^BOLD%^%^YELLOW%^i%^BLACK%^e%^RED%^r%^YELLOW%^y e%^RED%^n%^YELLOW%^e%^RED%^r%^BLACK%^g%^YELLOW%^y%^BLACK%^ spilling forth from the empty sockets of its eyes. From the devils fanged maw spring forth a long tear drop shaped "+
   "bl%^BLUE%^a%^BLACK%^de of fr%^BLUE%^o%^BLACK%^st %^BLUE%^e%^BLACK%^nc%^CYAN%^a%^BLACK%^s%^BLUE%^e%^BLACK%^d %^YELLOW%^a%^BLACK%^d%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^m%^YELLOW%^a%^BLACK%^nt%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^n%^YELLOW%^e%^BLACK%^. Veins of what appears to be %^RED%^m%^YELLOW%^o%^RED%^lt%^YELLOW%^e%^RED%^n "+
   "f%^YELLOW%^i%^RED%^r%^YELLOW%^e%^BOLD%^%^BLACK%^ run the length of the blade in perfectly symmetrical paths. The entire length of the spire is perfectly balanced, though strangely despite the ice clinging to the weapon it seems to radiate %^RED%^h%^YELLOW%^e%^RED%^a%^BLACK%^t. A palpable aura of %^RESET%^%^RED%^evil%^BOLD%^%^BLACK%^ surrounds the sp%^BLUE%^e%^CYAN%^a%^BLACK%^r ch%^BLUE%^i%^BLACK%^ll%^BLUE%^i%^BLACK%^ng you to the core.%^RESET%^");
   set_lore("%^BOLD%^%^BLACK%^It is said that the lord of the 8th, Mephistopheles, forged this mighty weapon from the very heart of his ice fortress Mephistar. Granting it as a reward to his champion Bele for his enormous contributions in the battles against Baalzebul. Bele was sent into the heart of the volcano of Tonerra by his lord when it was discovered that the dead god Ibrandul had been interred there. Hoping to claim any remaining scrap of divine essence so that he might challenge Asmodeus for "+
"dominion of hell, Mephistopheles was eager to see his justicar return successful. Unfortunately it seems that the dead god still retained enough power to destroy the Arch devils Champion and his mighty weapon "+
"was claimed as a reminder to the fiends that even a dead god is beyond them.%^RESET%^ %^BOLD%^%^BLACK%^Legends claim that in his descend into the heart of the volcano Bele was able to transform the his mighty weapon from a dagger into an intimidating spear at will. In its most potent form he was also able to channel the very power of Mephistar through his blade by %^CYAN%^thrust%^BLACK%^ing it into the ground, conjuring great glacial walls to crush any means of escape his enemies might have. "
"Other tales tell of how the church of the Warhawk laid hands upon such a weapon, and found a means to lift the corruption from the weapon. It is said that they are still willing to offer the same to any who brought the spear to before them, to %^CYAN%^purge %^BLACK%^it of its evil.%^RESET%^");
   set_property("lore difficulty",25);
   set_property("enchantment",6);
   set_weight(8); // leaving this intact so it matches shortsword, avoids glitches on change. N, 2/20
   set_value(50000);
   set_hit((:TO,"hitme":));
   set_wield((:TO,"wieldme":));
   set_unwield((:TO,"unwieldme":));
   set_item_bonus("attack bonus",5);
   set_item_bonus("damage bonus",5);
   set_item_bonus("influence",5);
//   set_weapon_prof("exotic"); // removing for inherit fixes, N 2/20
}

int wieldme(){
   if(!wizardp(ETO)){
     if((int)ETO->query_highest_level() < 35 || member_array("Solved the mystery of Ibrandul",ETO->query_mini_quests()) ==-1){
         tell_object(ETO,"%^BOLD%^%^CYAN%^You are unable to wield the frosty spear!%^RESET%^");
         return 0;
      }
   }
   tell_object(ETO," %^BOLD%^%^BLACK%^As you gr%^BLUE%^i%^BLACK%^p the weapon "+
      "%^WHITE%^s%^RESET%^t%^BOLD%^e%^RESET%^a%^BOLD%^m%^BLACK%^ rises from the point of contact%^RESET%^");
   return 1;
}

int unwieldme(){
   tell_object(ETO," %^BOLD%^%^CYAN%^A slight crackling can be heard as you release your grip on the cold weapon. ");
   return 1;
}

int hitme(object targ){
   if(!objectp(targ)) return roll_dice(1,4);
   if(random(100) > 40) return roll_dice(1,4);
   switch(random(10)){
   case 0..1:
      tell_room(EETO,"%^BLUE%^"+ETO->QCN+" suddenly thrusts the shaft of his spear forward slamming it into "+targ->QCN+"'s  face!%^RESET%^ ",({targ,ETO}));
      tell_object(targ,"%^BLUE%^"+ETO->QCN+" suddenly thrusts the shaft of "+ETO->QP+" spear forward slamming it into your face!%^RESET%^!");
      tell_object(ETO," %^BLUE%^You suddenly thrust the shaft of the spear forward slamming it into "+targ->QCN+"'s  face!%^RESET%^");
      targ->set_paralyzed(roll_dice(2,8)," %^RED%^ You are still reeling from the blow!%^RESET%^");
      return roll_dice(2,8);
   case 2..3:
      tell_room(EETO," %^BOLD%^%^BLACK%^"+ETO->QCN+" whirls the spear effortlessly around "+ETO->QO+", slashing through "+targ->QCN+" in rapid succession!%^RESET%^",({targ,ETO}));
      tell_object(targ," %^BOLD%^%^BLACK%^"+ETO->QCN+"  whirls the bladestaff effortlessly around "+ETO->QO+", slashing through you in rapid succession!%^RESET%^");
      tell_object(ETO,"%^BOLD%^%^BLACK%^You whirl the spear effortlessly around yourself slashing through "+targ->QCN+"  in rapid succession!%^RESET%^");
      ETO->execute_attack();
      return roll_dice(2,6);
   case 4..8:
      tell_object(targ,"%^RED%^"+ETO->QCN+"'s blade slashes into you releasing a gout of %^RESET%^s%^BOLD%^t%^RESET%^e%^BOLD%^a%^RESET%^m%^RED%^ and %^BOLD%^h%^YELLOW%^e%^RED%^l%^BLACK%^l%^RED%^f%^YELLOW%^i%^RED%^r%^YELLOW%^e%^RESET%^%^RED%^ that burn you horribly!!");
      tell_room(EETO," %^RED%^"+ETO->QCN+"'s blade slashes into "+targ->QCN+" releasing a gout of %^RESET%^s%^BOLD%^t%^RESET%^e%^BOLD%^a%^RESET%^m%^RED%^ and %^BOLD%^h%^YELLOW%^e%^RED%^l%^BLACK%^l%^RED%^f%^YELLOW%^i%^RED%^r%^YELLOW%^e%^RESET%^%^RED%^!%^RESET%^",({targ,ETO}));
      tell_object(ETO," %^RED%^Your blade slashes into "+targ->QCN+"  releasing a gout of %^RESET%^s%^BOLD%^t%^RESET%^e%^BOLD%^a%^RESET%^m%^RED%^ and %^BOLD%^h%^YELLOW%^e%^RED%^l%^BLACK%^l%^RED%^f%^YELLOW%^i%^RED%^r%^YELLOW%^e%^RESET%^%^RED%^!%^RESET%^");
      return roll_dice(4,8);
   case 9:
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
   return 0;
}

void init(){
   int num;
   ::init();
    if(!objectp(TP)) return;
    if(!objectp(ETO)) return;
    if(TP != ETO) return;
   add_action("transform","transform");
   add_action("thrust","thrust");
}

int thrust(string str){
   if(!query_wielded()) return 0;
   if(!objectp(TO)) return 0;
   if(!objectp(ETO)) return 0;
   if(!objectp(EETO)) return 0;
   if(str == "spear") return 0;
      tell_room(EETO,"%^BOLD%^%^BLUE%^Spinning the spear around "+ETO->QP+" body, "+ETO->QCN+" suddenly jabs the blade into the ground, causing a layer of %^WHITE%^i%^CYAN%^c%^WHITE%^e %^BLUE%^to rapidly spread across the area!%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^BLUE%^Spinning the spear around your body, you suddenly jabs the blade into the ground, causing a layer of %^WHITE%^i%^CYAN%^c%^WHITE%^e %^BLUE%^to rapidly spread across the area!%^RESET%^");
   if(!EETO->query_property("indoors")){
      tell_room(EETO,"%^BOLD%^%^CYAN%^The %^WHITE%^i%^CYAN%^c%^WHITE%^y %^CYAN%^layer melts quickly, leaving nothing but a %^RESET%^%^ORANGE%^m%^BOLD%^%^BLACK%^u%^RESET%^%^ORANGE%^ddy %^BOLD%^%^CYAN%^mess%^RESET%^.");
   return 1;
   }
      if(!str){
       if(!sizeof(EETO->query_exits())){
         tell_room(EETO,"%^BOLD%^%^CYAN%^The %^WHITE%^i%^CYAN%^c%^WHITE%^y %^CYAN%^layer melts quickly, leaving nothing but a %^RESET%^%^ORANGE%^m%^BOLD%^%^BLACK%^u%^RESET%^%^ORANGE%^ddy %^BOLD%^%^CYAN%^mess%^RESET%^.");
      return 1;
     }
      tell_room(EETO," %^BOLD%^%^WHITE%^The area quakes as %^BLUE%^g%^WHITE%^l%^CYAN%^a%^BLUE%^c%^CYAN%^i%^WHITE%^a%^BLUE%^l sh%^WHITE%^a%^BLUE%^rds%^WHITE%^ explode from the ground and walls collapsing all routes of escape!%^RESET%^");
      EETO->collapse_all_exits();
   }
else{
   if(member_array(str, EETO->query_exits()) == -1){
      tell_room(EETO,"%^BOLD%^%^CYAN%^The %^WHITE%^i%^CYAN%^c%^WHITE%^y %^CYAN%^layer melts quickly, leaving nothing but a %^RESET%^%^ORANGE%^m%^BOLD%^%^BLACK%^u%^RESET%^%^ORANGE%^ddy %^BOLD%^%^CYAN%^mess%^RESET%^.");
   return 1;
   }
   tell_room(EETO," %^BOLD%^%^WHITE%^The area quakes as %^BLUE%^g%^WHITE%^l%^CYAN%^a%^BLUE%^c%^CYAN%^i%^WHITE%^a%^BLUE%^l sh%^WHITE%^a%^BLUE%^rds%^WHITE%^ explode from the ground and walls collapsing the way "+str+"%^RESET%^.");
   EETO->collapse_exit(str);
   }
   if(!random(100) && userp(ETO)){
   badStuff();
   return 1;
   }
}

void badStuff(){
   tell_room(EETO,"%^BOLD%^%^CYAN%^The ground continues to tremble as the shards of %^WHITE%^ice %^CYAN%^climb even higher!");
   call_out("moreBadStuff",10,ETO);
}

moreBadStuff(object ob){
   object *inven;
   int i,j,hp;
   tell_room(environment(ob),"%^BOLD%^%^CYAN%^The %^WHITE%^ice %^CYAN%^begins to %^BLUE%^crack %^CYAN%^rapidly before collapsing on you!!");
    inven = all_living(environment(ob));
   for(i=0;i<j;i++){
       if (!objectp(inven[i])) continue;
      if(inven[i]->query_true_invis()) continue;
      ETO->set_property("magic",1);
      inven[i]->do_damage("head",roll_dice(50,10));
      ETO->set_property("magic",-1);
      inven[i]->add_attacker(TP);
      inven[i]->continue_attack();
      inven[i]->remove_attacker(TP);
   }
}

int transform(string str){
   object ob,theplayer,*names;
   int i,myenchant;
   if (!str) {
     notify_fail("Transform what?");
     return 0;
   }
   if(!str == "sword"||str=="sword of mephistar"||str=="sword of destruction"){
     notify_fail("You can't transform that!\n");
     return 0;
   }
   if (TP != ETO) {
     notify_fail("You should pick that up first.\n");
     return 0;
   }
   myenchant = TO->query_property("enchantment");
//  TO->set_weight(0);  //to prevent bugs caused by over capacity in players carry weight
// so this doesn't actually work as it's already in inven and doesn't reduce player carry capacity on the command. New weapon needs to be moved AFTER old is gone. N, 12/15.
   ob = new("/d/islands/tonerra/obj/mephistarsword.c");
//it was still pulling from Tsera's directory. Changed that ~Circe~ 5/7/11
//   ob->move(ETO);

/*
   if ((int)TO->query_property("enchantment") < 0) {
     ob->remove_property("enchantment");

ob->set_property("enchantment",(int)TO->query_property("enchantment"));
   }
   else {
     while((int)ob->query_property("enchantment") != 5) {
       ob->remove_property("enchantment");
       ob->set_property("enchantment",5);
     }
   }
Previous code - leaving just in case.
*/
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
      tell_object(ETO," %^BOLD%^%^BLACK%^The spears shaft contracts in on itself, shrinking until it resembles an elaborate short sword%^RESET%^");

   tell_room(EETO,"%^BOLD%^%^BLACK%^The shaft of "+ETO->QCN+"'s spear contracts in on itself, shrinking until it resembles an elaborate short sword!%^RESET%^",ETO);
   ETO->force_me("unwield spear of destruction");
   theplayer = ETO;
   TO->move("/d/shadowgate/void");
   ob->move(theplayer);
   theplayer->force_me("wield sword of destruction");
   TO->remove();
   return 1;
}
