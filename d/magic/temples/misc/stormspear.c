#include <std.h>
//inherit "/d/common/obj/weapon/spear_lg.c";
inherit "/d/common/obj/weapon/glaive.c";
// using glaive as the closest martial match for the weapon (so shortsword same prof when switched). N, 2/20

void badStuff();

void create(){
   ::create();
   set_name("Spire of the Vengeful Storm");
   set_id(({"spear","large spear","Spire of the Vengeful Storm","spear of the vengeful storm","spire of the vengeful storm","spire","spire of the vengeful storm","large spire","polearm"}));
   set_short("%^BOLD%^%^BLACK%^Sp%^CYAN%^i%^BLACK%^r%^BLUE%^e %^BLACK%^o%^BLUE%^f %^BLACK%^t%^CYAN%^h%^BLACK%^e Ve%^BLUE%^n%^BLACK%^ge%^CYAN%^f%^BLACK%^ul S%^BLUE%^t%^CYAN%^o%^BLACK%^rm%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^A sp%^BLUE%^e%^CYAN%^a%^BLACK%^r ch%^CYAN%^a%^BLACK%^r%^BOLD%^%^BLUE%^g%^BOLD%^%^BLACK%^ed wi%^CYAN%^t%^BLACK%^h %^BLUE%^e%^BLACK%^ne%^CYAN%^r%^BLUE%^g%^BLACK%^y%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^From its haft to its r%^BOLD%^%^YELLOW%^a%^BOLD%^%^BLACK%^zo%^BOLD%^%^RED%^r%^BOLD%^%^BLACK%^-sh%^BOLD%^%^WHITE%^a%^BOLD%^%^YELLOW%^r%^BOLD%^%^BLACK%^p tip, this "
"incredible weapon positively thrums with %^BOLD%^%^YELLOW%^p%^BOLD%^%^BLACK%^o%^BOLD%^%^BLUE%^w%^BOLD%^%^CYAN%^e%^BOLD%^%^BLACK%^r.  A br%^RED%^i%^BLACK%^ll%^RED%^i%^YELLOW%^a%^BLACK%^nt "
"%^RED%^r%^RESET%^%^RED%^u%^BOLD%^b%^RESET%^%^RED%^y %^BOLD%^%^BLACK%^spike forms the cap, lit by fl%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^sh%^BOLD%^%^CYAN%^e%^BOLD%^%^BLACK%^s of barely contained "
"e%^BOLD%^%^CYAN%^n%^BOLD%^%^BLUE%^e%^BOLD%^%^BLACK%^r%^BOLD%^%^CYAN%^g%^BOLD%^%^BLACK%^y surging within its multifaceted depths.  The dark shaft of the weapon is warm to the touch, and "
"decorated with intricate jagged etchings that gleam with traces of %^BOLD%^%^WHITE%^a%^BOLD%^%^BLUE%^z%^BOLD%^%^WHITE%^u%^BOLD%^%^CYAN%^r%^BOLD%^%^BLUE%^e %^BOLD%^%^BLACK%^as they run the "
"length of the weapon.  Small studs of on%^RESET%^y%^BOLD%^%^BLACK%^x ring the grip, each polished to a flawless finish and producing a barely visible %^BOLD%^%^YELLOW%^g%^RESET%^%^ORANGE%^o"
"%^BOLD%^%^BLACK%^l%^BOLD%^%^WHITE%^d%^BOLD%^%^YELLOW%^e%^BOLD%^%^BLACK%^n l%^BOLD%^%^YELLOW%^i%^BOLD%^%^BLACK%^ght from its depths.  An incredibly detailed image of a hawk in flight crowns "
"the polearm, its hooked beak open in a defiant s%^BOLD%^%^WHITE%^c%^BOLD%^%^RED%^r%^BOLD%^%^BLACK%^e%^YELLOW%^a%^BOLD%^%^BLACK%^m as sparks of en%^BOLD%^%^YELLOW%^e%^BOLD%^%^BLACK%^"
"rgy arc between the feathers of its flared wings.  Springing from between them rises a long teardrop shaped bl%^BOLD%^%^BLUE%^a%^BOLD%^%^BLACK%^de of gl%^YELLOW%^e%^BOLD%^%^BLACK%^am%^RESET%^"
"%^RED%^i%^BOLD%^%^BLACK%^ng %^YELLOW%^a%^BOLD%^%^BLACK%^d%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^m%^YELLOW%^a%^BOLD%^%^BLACK%^nt%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^u%^YELLOW%^m%^BOLD%^%^BLACK%^.  "
"Jagged, forked veins of cra%^BOLD%^%^YELLOW%^c%^BOLD%^%^BLACK%^kling l%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^ght%^YELLOW%^n%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^ng run the length of the blade in "
"chaotic paths.  The entire length of the spire is perfectly balanced, though despite its solid and sturdy make it seems to thrum with s%^BOLD%^%^BLUE%^t%^BOLD%^%^BLACK%^atic %^BOLD%^%^YELLOW%^e"
"%^BOLD%^%^BLACK%^ne%^BOLD%^%^WHITE%^r%^BOLD%^%^CYAN%^g%^BOLD%^%^BLACK%^y.  A palpable aura of r%^YELLOW%^i%^BOLD%^%^WHITE%^g%^BOLD%^%^BLACK%^ht%^BOLD%^%^CYAN%^e%^BOLD%^%^BLACK%^ous vi%^BOLD%^"
"%^BLUE%^n%^BOLD%^%^BLACK%^di%^BOLD%^%^CYAN%^c%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^ti%^YELLOW%^o%^BOLD%^%^BLACK%^n surrounds the sp%^BLUE%^e%^CYAN%^a%^BLACK%^r, lifting your spirits.\n%^RESET%^");
   set_lore("%^BOLD%^%^WHITE%^Originally of devilish make and a tool of utter evil, this spear was the creation of the Lord of the 8th, Mephistopheles.  It was granted to his champion, Bele, "
"and from there passed through many hands to eventually find its way to the possession of the church of the Warhawk.  The priesthood of Anhur could not tolerate such a weapon, and while many "
"initially spoke to have it destroyed, it was decided in the end to try and reforge the spear, to turn it against the very evil for which it was first made.  Many years went into their efforts, "
"drawing upon the greatest of their priesthood and the most competent magi and smiths they could gather, but in the end the rites were refined, and deemed a blessed success.  The spear was "
"renamed, though it retained many of its original powers, including the ability to %^YELLOW%^transform %^WHITE%^from a spear to a more easily concealed shortsword at will.  In its most potent "
"form, the spear could also be %^YELLOW%^thrust %^BOLD%^%^WHITE%^into the ground to call upon Anhur's blessings, preventing foes from escaping the righteous storm held within the weapon."
"After the god's war and falling of Anhur, Kreysneothosies took up the mantle of %^YELLOW%^purging%^WHITE%^ the spire in honor of Anhur his Tsarven brother!%^RESET%^");
   set_property("lore difficulty",35);
   set_property("enchantment",6);
   set_item_bonus("attack bonus",5);
   set_item_bonus("damage bonus",5);
   set_item_bonus("sight bonus",5);
   set_weight(8); // leaving this intact so it matches shortsword, avoids glitches on change. N, 2/20
   set_value(50000);
   set_hit((:TO,"hitme":));
   set_wield((:TO,"wieldme":));
   set_unwield((:TO,"unwieldme":));
//   set_weapon_prof("exotic"); // removing for inherit fixes, N 2/20
}

int wieldme(){
   if(!wizardp(ETO)){
     if((int)ETO->query_highest_level() < 35 || member_array("Solved the mystery of Ibrandul",ETO->query_mini_quests()) ==-1){
         tell_object(ETO,"%^BOLD%^%^CYAN%^You are unable to wield the mighty spear!%^RESET%^");
         return 0;
      }
   }
   if(!((int)ETO->query_true_align()%3)) {
     tell_object(ETO,"%^BOLD%^%^CYAN%^The engraved hawk lets out an ear-splitting scream of rage, and you drop the spear!%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^CYAN%^The engraved hawk upon the spear lets out an ear-splitting scream of rage, and "+ETO->QCN+" relinquishes hold of it!%^RESET%^",ETO);
     ETO->set_paralyzed(25,"%^BOLD%^%^RED%^You're still recovering from the shriek!%^RESET%^");
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
        tell_room(EETO,"%^BLUE%^"+ETO->QCN+" suddenly thrusts the shaft of "+ETO->QP+" spear forward, slamming it into "+targ->QCN+"'s face!%^RESET%^",({targ,ETO}));
        tell_object(targ,"%^BLUE%^"+ETO->QCN+" suddenly thrusts the shaft of "+ETO->QP+" spear forward, slamming it into your face!%^RESET%^!");
        tell_object(ETO,"%^BLUE%^You suddenly thrust the shaft of the spear forward, slamming it into "+targ->QCN+"'s face!%^RESET%^");
        targ->set_paralyzed(roll_dice(2,8),"%^RED%^You are still reeling from the blow!%^RESET%^");
        return roll_dice(2,8);
    case 2..3:
      tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" whirls "+ETO->QP+" spear effortlessly, becoming a veritable s%^BOLD%^%^CYAN%^t%^BOLD%^%^BLUE%^o%^BOLD%^%^BLACK%^rm of violence as "+ETO->QS+" slashes through "+ETO->QP+" foes in rapid succession!%^RESET%^",ETO);
      tell_object(ETO,"%^BOLD%^%^BLACK%^You whirl the spear effortlessly, becoming a veritable s%^BOLD%^%^CYAN%^t%^BOLD%^%^BLUE%^o%^BOLD%^%^BLACK%^rm of violence as you slash through your foes in rapid succession!%^RESET%^");
      ETO->execute_attack();
      return roll_dice(2,6);
   case 4..8:
      tell_object(targ,"%^RED%^"+ETO->QCN+"'s spear slashes into you, discharging a sh%^YELLOW%^o%^RED%^c%^RESET%^%^RED%^ki%^ORANGE%^n%^RED%^g burst of %^BOLD%^%^CYAN%^a%^BLUE%^z%^CYAN%^u%^WHITE%^r%^CYAN%^e %^BLUE%^l%^WHITE%^i%^YELLOW%^g%^CYAN%^h%^BLUE%^t%^CYAN%^n%^WHITE%^i%^BLUE%^n%^CYAN%^g %^RESET%^%^RED%^that burn you horribly!%^RESET%^");
      tell_room(EETO,"%^RED%^"+ETO->QCN+"'s spear slashes into "+targ->QCN+", discharging a sh%^YELLOW%^o%^RED%^c%^RESET%^%^RED%^ki%^ORANGE%^n%^RED%^g burst of %^BOLD%^%^CYAN%^a%^BLUE%^z%^CYAN%^u%^WHITE%^r%^CYAN%^e %^BLUE%^l%^WHITE%^i%^YELLOW%^g%^CYAN%^h%^BLUE%^t%^CYAN%^n%^WHITE%^i%^BLUE%^n%^CYAN%^g%^RESET%^%^RED%^!%^RESET%^",({targ,ETO}));
      tell_object(ETO,"%^RED%^Your spear slashes into "+targ->QCN+", discharging a sh%^YELLOW%^o%^RED%^c%^RESET%^%^RED%^ki%^ORANGE%^n%^RED%^g burst of %^BOLD%^%^CYAN%^a%^BLUE%^z%^CYAN%^u%^WHITE%^r%^CYAN%^e %^BLUE%^l%^WHITE%^i%^YELLOW%^g%^CYAN%^h%^BLUE%^t%^CYAN%^n%^WHITE%^i%^BLUE%^n%^CYAN%^g%^RESET%^%^RED%^!%^RESET%^");
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

   tell_room(EETO,"%^BOLD%^%^BLUE%^Spinning the spear around "+ETO->QP+" body, gusting w%^WHITE%^i%^CYAN%^n%^BLUE%^ds pick up as "+ETO->QCN+" suddenly jabs the spear into the ground!\n%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^BLUE%^Spinning the spear around your body, gusting w%^WHITE%^i%^CYAN%^n%^BLUE%^ds pick up as you suddenly jab the spear into the ground!\n%^RESET%^");
   if(!EETO->query_property("indoors")){
      tell_room(EETO,"%^BOLD%^%^CYAN%^The winds die away, leaving your hair and clothes ruffled.%^RESET%^");
      return 1;
   }
   if(!str){
      if(!sizeof(EETO->query_exits())){
         tell_room(EETO,"%^BOLD%^%^CYAN%^The winds die away, leaving your hair and clothes ruffled.%^RESET%^");
         return 1;
      }
      tell_room(EETO,"%^BOLD%^%^WHITE%^Crac%^YELLOW%^k%^WHITE%^ling energy arcs out from the spear, charging the air as a %^BLACK%^bo%^RED%^o%^BLACK%^m %^WHITE%^of thunder shakes the walls around you!  The sheer force sends them tumbling, cutting off all routes of escape!%^RESET%^");
      EETO->collapse_all_exits();
   }
   else{
      if(member_array(str, EETO->query_exits()) == -1){
         tell_room(EETO,"%^BOLD%^%^CYAN%^The winds die away, leaving your hair and clothes ruffled.%^RESET%^");
         return 1;
      }
      tell_room(EETO,"%^BOLD%^%^WHITE%^Crac%^YELLOW%^k%^WHITE%^ling energy arcs out from the spear, charging the air as a %^BLACK%^bo%^RED%^o%^BLACK%^m %^WHITE%^of thunder shakes the walls around you!  The sheer force sends them tumbling, cutting off escape to the "+str+"!%^RESET%^");
      EETO->collapse_exit(str);
   }
   if(!random(100) && userp(ETO)) badStuff();
   return 1;
}

void badStuff(){
   tell_room(EETO,"%^BOLD%^%^CYAN%^Instead of dissipating, the growing storm of a%^WHITE%^i%^CYAN%^r and li%^YELLOW%^g%^CYAN%^htn%^WHITE%^i%^CYAN%^ng seems to intensify!%^RESET%^");
   call_out("moreBadStuff",10,ETO);
}

void moreBadStuff(object ob){
   object *inven;
   int i,j,hp;
   tell_room(environment(ob),"%^BOLD%^%^CYAN%^With a final thu%^BLACK%^n%^CYAN%^de%^WHITE%^r%^CYAN%^ous roar, the storm expends its energy in a single great ex%^BLUE%^p%^WHITE%^l%^CYAN%^os%^YELLOW%^i%^CYAN%^on!%^RESET%^");
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
   object ob,*names;
   int i,myenchant;
   if(!str) {
     notify_fail("Transform what?");
     return 0;
   }
   if(str != "spear" && str == "spear of the vengeful storm" && str != "spire"){
     notify_fail("You can't transform that!\n");
     return 0;
   }
   if (TP != ETO) {
     notify_fail("You should pick that up first.\n");
     return 0;
   }
   if(!query_wielded()){
      notify_fail("You must be wielding the spear to command it!");
      return 0;
   }
   myenchant = TO->query_property("enchantment");
   TO->set_weight(0);  //to prevent bugs caused by over capacity in players carry weight
   ob = new("/d/magic/temples/misc/stormsword.c");
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

   tell_object(ETO,"%^BOLD%^%^BLACK%^The spear's shaft contracts in on itself, shrinking until it resembles an elaborate short sword!%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^BLACK%^The shaft of "+ETO->QCN+"'s spear contracts in on itself, shrinking until it resembles an elaborate short sword!%^RESET%^",ETO);
   ETO->force_me("unwield spear of the vengeful storm");
   ETO->force_me("wield sword of the vengeful storm");
   TO->remove();
   return 1;
}
