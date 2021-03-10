//balanced for +6 - Yves 9/3/19
// trade item for mephistar spear as there is no non-evil 2h equivalent (spear well outstrips the hammer).
#include <std.h>
inherit "/d/common/obj/weapon/shortsword.c";

void create(){
   ::create();
   set_name("Fang of the Vengeful Storm");
   set_id(({"sword","shortsword","Fang of the Vengeful Storm","sword of the vengeful storm","fang of the vengeful storm","fang"}));
   set_short("%^BOLD%^%^BLACK%^F%^CYAN%^a%^BLACK%^n%^BLUE%^g %^BLACK%^o%^BLUE%^f %^BLACK%^t%^CYAN%^h%^BLACK%^e Ve%^BLUE%^n%^BLACK%^ge%^CYAN%^f%^BLACK%^ul S%^BLUE%^t%^CYAN%^o%^BLACK%^rm%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^A sh%^BLUE%^o%^CYAN%^r%^BOLD%^%^BLACK%^tsw%^BOLD%^%^BLUE%^o%^BOLD%^%^BLACK%^rd ch%^CYAN%^a%^BLACK%^r%^BOLD%^%^BLUE%^g%^BOLD%^%^BLACK%^ed wi%^CYAN%^t%^BLACK%^h %^BLUE%^e%^BLACK%^ne%^CYAN%^r%^BLUE%^g%^BLACK%^y%^RESET%^");

   set_long("%^BOLD%^%^BLACK%^From its pommel to its r%^BOLD%^%^YELLOW%^a%^BOLD%^%^BLACK%^zo%^BOLD%^%^RED%^r%^BOLD%^%^BLACK%^-sh%^BOLD%^%^WHITE%^a%^BOLD%^%^YELLOW%^r%^BOLD%^%^BLACK%^p tip, this "
"incredible weapon positively thrums with %^BOLD%^%^YELLOW%^p%^BOLD%^%^BLACK%^o%^BOLD%^%^BLUE%^w%^BOLD%^%^CYAN%^e%^BOLD%^%^BLACK%^r.  A br%^RED%^i%^BLACK%^ll%^RED%^i%^YELLOW%^a%^BLACK%^nt "
"%^RED%^r%^RESET%^%^RED%^u%^BOLD%^b%^RESET%^%^RED%^y %^BOLD%^%^BLACK%^spike forms the pommel, lit by fl%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^sh%^BOLD%^%^CYAN%^e%^BOLD%^%^BLACK%^s of barely "
"contained e%^BOLD%^%^CYAN%^n%^BOLD%^%^BLUE%^e%^BOLD%^%^BLACK%^r%^BOLD%^%^CYAN%^g%^BOLD%^%^BLACK%^y surging within its multifaceted depths.  The dark grip of the weapon is decorated with "
"intricate jagged etchings that gleam with traces of %^BOLD%^%^WHITE%^a%^BOLD%^%^BLUE%^z%^BOLD%^%^WHITE%^u%^BOLD%^%^CYAN%^r%^BOLD%^%^BLUE%^e %^BOLD%^%^BLACK%^as they run its length.  Small "
"studs of on%^RESET%^y%^BOLD%^%^BLACK%^x ring the grip, each polished to a flawless finish and producing a barely visible %^BOLD%^%^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^l%^BOLD%^"
"%^WHITE%^d%^BOLD%^%^YELLOW%^e%^BOLD%^%^BLACK%^n l%^BOLD%^%^YELLOW%^i%^BOLD%^%^BLACK%^ght from its depths.  An incredibly detailed image of a hawk in flight crowns the hilt, its hooked beak "
"open in a defiant s%^BOLD%^%^WHITE%^c%^BOLD%^%^RED%^r%^BOLD%^%^BLACK%^e%^YELLOW%^a%^BOLD%^%^BLACK%^m as sparks of en%^BOLD%^%^YELLOW%^e%^BOLD%^%^BLACK%^rgy arc between the feathers of its "
"flared wings, that serve as the weapon's guard.  Springing from between them rises a long broad bl%^BOLD%^%^BLUE%^a%^BOLD%^%^BLACK%^de of gl%^YELLOW%^e%^BOLD%^%^BLACK%^am%^RESET%^"
"%^RED%^i%^BOLD%^%^BLACK%^ng %^YELLOW%^a%^BOLD%^%^BLACK%^d%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^m%^YELLOW%^a%^BOLD%^%^BLACK%^nt%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^u%^YELLOW%^m%^BOLD%^%^BLACK%^.  "
"Jagged, forked veins of cra%^BOLD%^%^YELLOW%^c%^BOLD%^%^BLACK%^kling l%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^ght%^YELLOW%^n%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^ng run the length of the blade in "
"chaotic paths.  The entire length of the sword is perfectly balanced, though despite its solid and sturdy make it seems to thrum with s%^BOLD%^%^BLUE%^t%^BOLD%^%^BLACK%^atic %^BOLD%^%^YELLOW%^e"
"%^BOLD%^%^BLACK%^ne%^BOLD%^%^WHITE%^r%^BOLD%^%^CYAN%^g%^BOLD%^%^BLACK%^y.  A palpable aura of r%^YELLOW%^i%^BOLD%^%^WHITE%^g%^BOLD%^%^BLACK%^ht%^BOLD%^%^CYAN%^e%^BOLD%^%^BLACK%^ous vi%^BOLD%^"
"%^BLUE%^n%^BOLD%^%^BLACK%^di%^BOLD%^%^CYAN%^c%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^ti%^YELLOW%^o%^BOLD%^%^BLACK%^n surrounds the sp%^BLUE%^e%^CYAN%^a%^BLACK%^r, lifting your spirits.\n%^RESET%^");

   set_lore("%^BOLD%^%^WHITE%^Originally of devilish make and a tool of utter evil, this blade was the creation of the Lord of the 8th, Mephistopheles.  It was granted to his champion, Bele, "
"and from there passed through many hands to eventually find its way to the possession of the church of the Warhawk.  The priesthood of Anhur could not tolerate such a weapon, and while many "
"initially spoke to have it destroyed, it was decided in the end to try and reforge the blade, to turn it against the very evil for which it was first made.  Many years went into their efforts, "
"drawing upon the greatest of their priesthood and the most competent magi and smiths they could gather, but in the end the rites were refined, and deemed a blessed success.  The blade was "
"renamed, though it retained many of its original powers, including the ability to %^YELLOW%^transform %^WHITE%^from a sword to the more intimidating spear at will.  In its most potent form, "
"the spear could also be used to call upon Anhur's blessings, preventing foes from escaping the righteous storm held within the weapon. After the god's war and falling of Anhur, Kreysneothosies"
"took up the mantle of %^YELLOW%^purging%^WHITE%^ the spire in honor of Anhur his Tsarven brother!%^RESET%^");
   set_property("lore difficulty",35);
   set_property("enchantment",6);
   set_item_bonus("attack bonus",5);
   set_item_bonus("damage bonus",5);
   set_item_bonus("sight bonus",5);
   set_weight(8); //to match weight of spear to avoid glitches on transform
   set_value(50000);
   set_hit((:TO,"hitme":));
   set_wield((:TO,"wieldme":));
   set_unwield((:TO,"unwieldme":));
//   set_weapon_prof("exotic"); // weapon streamlining from inherits, N 2/20
}

int wieldme(){
   if(!wizardp(ETO)){
      if((int)ETO->query_highest_level() < 35 || member_array("Solved the mystery of Ibrandul",ETO->query_mini_quests()) ==-1){
         tell_object(ETO,"%^BOLD%^%^CYAN%^You are unable to wield the frosty sword!%^RESET%^");
         return 0;
      }
   }
   if (!((int)ETO->query_true_align() % 3)) {
       tell_object(ETO, "%^BOLD%^%^CYAN%^The engraved hawk lets out an ear-splitting scream of rage, and you drop the spear!%^RESET%^");
       tell_room(EETO, "%^BOLD%^%^CYAN%^The engraved hawk upon the spear lets out an ear-splitting scream of rage, and " + ETO->QCN + " relinquishes hold of it!%^RESET%^", ETO);
       ETO->set_paralyzed(25, "%^BOLD%^%^RED%^You're still recovering from the shriek!%^RESET%^");
       return 0;
   }
   if(ETO->query_property("evil item")) {
     tell_object(ETO,"%^YELLOW%^There is so much evil in the items you carry that the spear repels your hand!%^RESET%^");
     return 0;
   }
   tell_object(ETO,"%^BOLD%^%^BLACK%^As you gr%^BLUE%^i%^BLACK%^p the weapon, sparks of e%^BOLD%^%^CYAN%^n%^BOLD%^%^BLUE%^e%^BOLD%^%^BLACK%^r%^BOLD%^%^CYAN%^g%^BOLD%^%^BLACK%^y dance across "
"your fingertips.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^BLACK%^As "+ETO->QCN+" gr%^BLUE%^i%^BLACK%^ps the weapon, sparks of e%^BOLD%^%^CYAN%^n%^BOLD%^%^BLUE%^e%^BOLD%^%^BLACK%^r%^BOLD%^%^CYAN%^g%^BOLD%^%^BLACK%^y dance "
"across "+ETO->QP+" fingertips.%^RESET%^",ETO);
   ETO->set_property("good item",1);
   return 1;
}

int unwieldme(){
   tell_object(ETO,"%^BOLD%^%^BLACK%^A slight cr%^BOLD%^%^CYAN%^a%^BOLD%^%^WHITE%^c%^BOLD%^%^BLACK%^kli%^BOLD%^%^BLUE%^n%^BOLD%^%^BLACK%^g can be heard as you release your grip on the "
"magnificent weapon.");
   tell_room(EETO,"%^BOLD%^%^BLACK%^A slight cr%^BOLD%^%^CYAN%^a%^BOLD%^%^WHITE%^c%^BOLD%^%^BLACK%^kli%^BOLD%^%^BLUE%^n%^BOLD%^%^BLACK%^g can be heard as "+ETO->QCN+" releases the "
"magnificent weapon.",ETO);
   ETO->set_property("good item",-1);
   return 1;
}

int hitme(object targ){
   if(!objectp(targ)) return roll_dice(1,4);
   if(random(100) > 40) return roll_dice(1,4);
   switch(random(10)){
      case 0..1:
         tell_room(EETO,"%^BLUE%^"+ETO->QCN+" suddenly turns and slams the pommel of "+ETO->QP+" sword into "+targ->QCN+"'s face!%^RESET%^",({targ,ETO}));
         tell_object(targ,"%^BLUE%^"+ETO->QCN+" suddenly turns and slams the pommel of "+ETO->QP+" sword into your face!%^RESET%^!");
         tell_object(ETO,"%^BLUE%^You turn suddenly and slam the pommel of your sword into "+targ->QCN+"'s face!%^RESET%^");
         targ->set_paralyzed(roll_dice(2,8),"%^RED%^You are still reeling from the blow!%^RESET%^");
         return roll_dice(2,8);
      case 2..3:
         tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" whirls "+ETO->QP+" sword effortlessly, becoming a veritable s%^BOLD%^%^CYAN%^t%^BOLD%^%^BLUE%^o%^BOLD%^%^BLACK%^rm of violence as "+ETO->QS+" slashes through "+ETO->QP+" foes in rapid succession!%^RESET%^",ETO);
         tell_object(ETO,"%^BOLD%^%^BLACK%^You whirl the sword effortlessly, becoming a veritable s%^BOLD%^%^CYAN%^t%^BOLD%^%^BLUE%^o%^BOLD%^%^BLACK%^rm of violence as you slash through your foes in rapid succession!%^RESET%^");
         ETO->execute_attack();
         return roll_dice(2,6);
      case 4..8:
         tell_object(targ,"%^RED%^"+ETO->QCN+"'s blade slashes into you, discharging a sh%^YELLOW%^o%^RED%^c%^RESET%^%^RED%^ki%^ORANGE%^n%^RED%^g burst of %^BOLD%^%^CYAN%^a%^BLUE%^z%^CYAN%^u%^WHITE%^r%^CYAN%^e %^BLUE%^l%^WHITE%^i%^YELLOW%^g%^CYAN%^h%^BLUE%^t%^CYAN%^n%^WHITE%^i%^BLUE%^n%^CYAN%^g %^RESET%^%^RED%^that burn you horribly!%^RESET%^");
         tell_room(EETO,"%^RED%^"+ETO->QCN+"'s blade slashes into "+targ->QCN+", discharging a sh%^YELLOW%^o%^RED%^c%^RESET%^%^RED%^ki%^ORANGE%^n%^RED%^g burst of %^BOLD%^%^CYAN%^a%^BLUE%^z%^CYAN%^u%^WHITE%^r%^CYAN%^e %^BLUE%^l%^WHITE%^i%^YELLOW%^g%^CYAN%^h%^BLUE%^t%^CYAN%^n%^WHITE%^i%^BLUE%^n%^CYAN%^g%^RESET%^%^RED%^!%^RESET%^",({targ,ETO}));
         tell_object(ETO,"%^RED%^Your blade slashes into "+targ->QCN+", discharging a sh%^YELLOW%^o%^RED%^c%^RESET%^%^RED%^ki%^ORANGE%^n%^RED%^g burst of %^BOLD%^%^CYAN%^a%^BLUE%^z%^CYAN%^u%^WHITE%^r%^CYAN%^e %^BLUE%^l%^WHITE%^i%^YELLOW%^g%^CYAN%^h%^BLUE%^t%^CYAN%^n%^WHITE%^i%^BLUE%^n%^CYAN%^g%^RESET%^%^RED%^!%^RESET%^");
         return roll_dice(4,8);
   case 9:
      if(targ->query_stoneSkinned()){
         tell_room(EETO,"%^BOLD%^%^BLUE%^As "+ETO->QCN+"'s blade sinks into "+targ->QCN+", el%^YELLOW%^e%^BLUE%^ctr%^CYAN%^i%^BLUE%^c%^WHITE%^i%^BLUE%^ty crackles in an impossibly fast wave across "+targ->QP+" body, shat%^CYAN%^t%^BLUE%^ering "+targ->QP+" defenses!%^RESET%^",({targ,ETO}));
         tell_object(targ,"%^BOLD%^%^BLUE%^As "+ETO->QCN+"'s blade sinks into you, el%^YELLOW%^e%^BLUE%^ctr%^CYAN%^i%^BLUE%^c%^WHITE%^i%^BLUE%^ty crackles in an impossibly fast wave across your body, shat%^CYAN%^t%^BLUE%^ering your magical protections!%^RESET%^");
         tell_object(ETO,"%^BOLD%^%^BLUE%^As your blade sinks into "+targ->QCN+", el%^YELLOW%^e%^BLUE%^ctr%^CYAN%^i%^BLUE%^c%^WHITE%^i%^BLUE%^ty crackles in an impossibly fast wave across "+targ->QP+" body, shat%^CYAN%^t%^BLUE%^ering "+targ->QP+" defenses!%^RESET%^");
         targ->set_stoneSkinned(0);
      }
      else{
         tell_room(EETO,"%^BOLD%^%^BLUE%^As "+ETO->QCN+"'s blade sinks into "+targ->QCN+", el%^YELLOW%^e%^BLUE%^ctr%^CYAN%^i%^BLUE%^c%^WHITE%^i%^BLUE%^ty crackles in an impossibly fast wave across "+targ->QP+" body!%^RESET%^",({targ,ETO}));
         tell_object(targ,"%^BOLD%^%^BLUE%^As "+ETO->QCN+"'s blade sinks into you, el%^YELLOW%^e%^BLUE%^ctr%^CYAN%^i%^BLUE%^c%^WHITE%^i%^BLUE%^ty crackles in an impossibly fast wave across your body, numbing your limbs!%^RESET%^");
         tell_object(ETO,"%^BOLD%^%^BLUE%^As your blade sinks into "+targ->QCN+", el%^YELLOW%^e%^BLUE%^ctr%^CYAN%^i%^BLUE%^c%^WHITE%^i%^BLUE%^ty crackles in an impossibly fast wave across "+targ->QP+" body!%^RESET%^");
         targ->set_paralyzed(roll_dice(1,8),"%^BOLD%^%^WHITE%^You're still trying to regain control of your limbs!%^RESET%^");
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
   object ob,*names;
   int i,myenchant;
   if (!str) {
      notify_fail("Transform what?");
      return 0;
   }
   if(str != "sword" && str != "sword of the vengeful storm" && str != "fang"){
      notify_fail("You can't transform that!");
      return 0;
   }
   if (TP != ETO) {
      notify_fail("You should pick that up first.\n");
      return 0;
   }
   if(!query_wielded()){
      notify_fail("You must be wielding the sword to command it!");
      return 0;
   }
   myenchant = TO->query_property("enchantment");
   TO->set_weight(0);  //to prevent bugs caused by over capacity in players carry weight
   ob = new("/d/magic/temples/misc/stormspear.c");
   ob->move(ETO);

   if((int)TO->query_property("enchantment") < 0) {
      ob->remove_property("enchantment");
      ob->set_property("enchantment",(int)TO->query_property("enchantment"));
   }
   else{
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
   if(TO->query_property("able to cast")) ob->set_property("able to cast",1);
   if(TO->query_property("soulbound")) ob->set_property("soulbound",1);

   tell_object(ETO,"%^BOLD%^%^BLACK%^The handle of the sword expands to considerable length, becoming an intimidating spear!%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^BLACK%^The handle of "+ETO->QCN+"'s sword expands to considerable length, becoming an intimidating spear!%^RESET%^",ETO);
   ETO->force_me("unwield sword of the vengeful storm");
   ETO->force_me("wield spear of the vengeful storm");
   TO->remove();
   return 1;
}
