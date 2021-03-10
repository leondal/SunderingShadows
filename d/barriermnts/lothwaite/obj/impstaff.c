#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/quarter_staff";

#define MAXUSES 100
int uses;
int iced = 0;
int OWNED;
string owner;
void remove_shield();

void create() {
   ::create();
   set_id(({"staff","grand staff","spider staff","staff of spiders","ironwood staff"}));
   set_name("ironwood staff");
   set_short("%^BOLD%^%^BLACK%^Staff of %^RED%^Spiders%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^A solid ironwood staff%^RESET%^");
   set_long(
      "%^BOLD%^%^BLACK%^This twisting staff is made of deep gray ironwood "+
      "that spirals from a %^RESET%^mithril tip %^BOLD%^%^BLACK%^all the way "+
      "to a %^RED%^dark ruby %^BLACK%^set in the top.  Tiny %^RED%^spiders "+
      "%^BLACK%^have been carved all along the surface and set with %^RESET%^"+
      "mithril%^BOLD%^%^BLACK%^, giving the illusion of spiders crawling all "+
      "along the staff.  A strange %^RESET%^flowing script %^BOLD%^%^BLACK%^"+
      "resides in the low portions of the spiral, giving you a message you "+
      "could read.%^RESET%^");
   set_read(
@CIRCE
%^BOLD%^%^WHITE%^The spider's %^BLACK%^embrace %^WHITE%^shelters you from harm
%^BOLD%^%^WHITE%^While a simple word will call forth a %^BLACK%^swarm
%^BOLD%^%^WHITE%^A %^BLACK%^curse %^WHITE%^is said to pray on one's fear
%^BOLD%^%^WHITE%^And when poison's in your veins, you may make it %^BLACK%^clear
CIRCE
   );
   set_lore("The Staff of Spiders is often considered a drow creation.  "+
      "In fact the original Staff of Spiders was not a drow creation at all, "+
      "but a gift from an imnp to the drow in return for a favor they had "+
      "done.  The details of the deal are now lost, but several copies of the "+
      "staff now exist.  The staff is often sought after by clerics of the "+
      "darker deities, who find great use in it.");
   set_value(8600);
   if(query_property("enchantment") < 3){
      remove_property("enchantment");
      set_property("enchantment",3);
   }
   set_wield((:TO,"wieldme":));
   set_unwield((:TO,"unwieldme":));
}

void init()
{
        ::init();
        if(!interactive(ETO)) return;
        if(interactive(TP) && TP == environment(TO) && !OWNED) {
                owner = TPQN;
                OWNED = 1;
        }
        add_action("shield","embrace");
        add_action("swarm_em","swarm");
        add_action("curse_em","curse");
        add_action("antidote","clear");
}

int wieldme(){
   if((ETO->is_class("cleric")) && (!ETO->is_class("mage")) && (!ETO->is_class("fighter"))){
       if (!ETO->query_property("silent_wield")) {
           tell_object(ETO, "%^BOLD%^%^BLACK%^You feel a hidden power within the " +
               "staff and know its abilities are yours to command!");
           tell_room(EETO, "%^BOLD%^%^BLACK%^You hear a strange whisper as " + ETOQCN + " " +
               "takes up the staff.", ETO);
       }
       return 1;
   }
   tell_object(ETO,"You have no idea how to use a staff such as this!");
   return 0;
}

int unwieldme(){
    if (!ETO->query_property("silent_wield")) {
        if (iced != 0) {
            remove_shield();
            remove_call_out("remove_shield");
        }
        tell_object(ETO, "You set aside the power of the staff for now.");
    }
    return 1;
}

int swarm_em(string str){
int i,num;
object obj;
num = random(3)+2;
   if(TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!query_wielded()){
      tell_object(ETO,"You must wield the staff first!");
      return 1;
   }
   if(str){
      tell_object(ETO,"Simply use <swarm> to call forth your army.");
      return 1;
   }
   if(uses < MAXUSES){
      if(present("staff_spider",EETO)){
         tell_object(ETO,"You are already controlling spiders!");
         return 1;
      }
      tell_object(ETO,"%^RED%^You focus your energies on the staff "+
         "and begin to chant for a swarm!");
      tell_room(EETO,"%^RED%^"+ETOQCN+" holds the staff in hand and "+
         "begins to chant.",ETO);
      tell_room(EETO,"%^RED%^Several large spiders suddenly appear!");
      ETO->set_paralyzed(4,"You are busy controlling the staff.");
      for(i=0;i<num;i++){
         obj = new("/d/common/mons/spider");
         obj->move(EETO);
         ETO->add_protector(obj);
         ETO->add_follower(obj);
      }
      return 1;
   }else{
      tell_object(ETO,"The magic of the staff has been depleted.");
      return 1;
   }
}

int curse_em(string str){
object targ;
int i,num;
   if(TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!query_wielded()){
      tell_object(ETO,"You must wield the staff first!");
      return 1;
   }
   if(!str){
      tell_object(ETO,"Who do you want to curse?  You must "+
         "designate a target!");
      return 1;
   }
   if(!(targ = present(str, EETO))){
      tell_object(ETO,"You do not see that!");
      return 1;
   }
   if(uses < MAXUSES){
      tell_object(ETO,"%^BLUE%^As you chant, the countless tiny "+
         "spiders spring forth off the staff!");
      tell_room(EETO,"%^BLUE%^"+ETOQCN+" begins to chant, "+
         "and the countless tiny spiders spring to life off the staff!",ETO);
      if((int)targ->query_stats("constitution") < random(26)){
         tell_object(targ,"%^BOLD%^%^BLACK%^Spiders swarm "+
            "all over you, plunging your mind into your "+
            "darkest fear!\n%^RED%^The spider's stings "+
            "burn in your veins!");
         tell_room(EETO,"%^BOLD%^%^BLACK%^The spiders surge "+
            "forth, completely covering "+targ->QCN+" as they "+
            "bite "+targ->QO+" ceaselessly!",targ);
         num = random(10)+10;
         for(i=0;i<num;i++){
            targ->do_damage(targ->return_target_limb(),4);
            tell_object(targ,"%^RED%^The spider bites you!");
         }
         targ->add_attacker(ETO);
         targ->continue_attack();
         targ->set_paralyzed(10,"You are still reeling in fear.");
         ETO->set_paralyzed(4,"You are busy controlling the staff.");
         return 1;
      }
      tell_room(EETO,"%^BLUE%^The spiders writhe, but then "+
         "stop, and the staff goes still!");
      ETO->set_paralyzed(4,"You are busy controlling the staff.");
      targ->add_attacker(ETO);
      return 1;
   }else{
      tell_object(ETO,"The magic of the staff has been depleted.");
      return 1;
   }
}

int shield(string str){
   if(TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!query_wielded()){
      tell_object(ETO,"You must wield the staff first!");
      return 1;
   }
   if(str){
      tell_object(ETO,"You may only use that on yourself!");
      return 1;
   }
   if(uses < MAXUSES){
      if(iced == 0){
         tell_object(ETO,"%^RED%^You chant softly and feel the staff "+
            "begin to writhe in your hands!");
         tell_room(EETO,"%^RED%^The spiders on the staff seem to come "+
            "to life as "+ETOQCN+" chants!",ETO);
         tell_object(ETO,"%^BOLD%^%^RED%^A chitinous armor forms all over "+
            "your body!");
         tell_room(EETO,"%^BOLD%^%^RED%^A chitinous armor forms on "+ETOQCN+"'s "+
            "body, making "+ETO->QO+" look like a spider!",ETO);
         ETO->add_ac_bonus(4);
         call_out("remove_shield",200+random(50));
         iced = 1;
         ETO->set_paralyzed(4,"You are busy controlling the staff.");
         return 1;
      }else{
         tell_object(ETO,"You already have the spider's armor!");
         return 1;
      }
   }else{
      tell_object(ETO,"The magic of the staff has been depleted.");
      return 1;
   }
}

int antidote(string str){
int tmp;
   tmp = ETO->query_poisoning();
   if(TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!query_wielded()){
      tell_object(ETO,"You must wield the staff first!");
      return 1;
   }
   if(str){
      tell_object(ETO,"You may only cure yourself of poison!  Simply <clear>.");
      return 1;
   }
   if(uses < MAXUSES){
      tell_object(ETO,"%^BOLD%^%^BLACK%^You take the staff in both hands "+
         "and close your eyes, whispering softly!");
      tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" takes the staff in both "+
         "hands with eyes closed and whispers softly!",ETO);
      if(!tmp){
         tell_object(ETO,"You stop whispering as you realize you are not poisoned.");
         return 1;
      }
      tell_object(ETO,"%^BOLD%^You feel the poison leave your body!");
      ETO->add_poisoning(-tmp);
      ETO->set_paralyzed(4,"You are busy controlling the staff.");
      return 1;
   }else{
      tell_object(ETO,"The magic of the staff has been depleted.");
      return 1;
   }
}

void remove_shield()
{
        tell_room(EETO,"%^RED%^You chitinous armor falls away.");
        ETO->add_ac_bonus(-4);
        iced = 0;
        return 1;
}
