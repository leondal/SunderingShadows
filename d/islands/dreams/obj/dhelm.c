//Coded by Bane//
//updated to current code and removing references to old gods ~Circe~ 9/22/19
#include <std.h>
inherit "/d/common/obj/armour/helm";

int flag, count, sapphire, amethyst, bopal, jet;
string owner;

int query_sapphire(){return sapphire;}
int query_amethyst(){return amethyst;}
int query_bopal(){return bopal;}
int query_jet(){return jet;}

void set_sapphire(int x){sapphire = x;}
void set_amethyst(int x){amethyst = x;}
void set_bopal(int x){bopal = x;}
void set_jet(int x){jet = x;}


void create(){
   ::create();
   set_id(({"helm","darkness","helm of darkness","blackened helm"}));
   set_name("helm of darkness");
   set_obvious_short("%^BOLD%^%^BLACK%^A blackened helm%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^Helm of %^BLUE%^D%^BLACK%^ar%^RESET%^%^BLUE%^k%^MAGENTA%^n%^BOLD%^%^BLACK%^e%^BLUE%^s%^BLACK%^s%^RESET%^");
   set_long("%^CYAN%^Crafted from %^BOLD%^%^BLACK%^darkened %^RESET%^silver%^CYAN%^ and %^BOLD%^steel%^RESET%^%^CYAN%^, this ancient style helm has a dark appearance.  The smooth helm looks battered and worn, as if it has seen numerous battles.  With its nose guard and the cheek plates that curve in, the open-faced helm looks as if it would offer a fair amount of protection.  The helm fits close to the wearer's head and then slightly curves outwards at the bottom to allow for ease in removal and wear.  %^BOLD%^%^BLACK%^B%^GREEN%^l%^BLACK%^ack %^GREEN%^o%^BLACK%^p%^RESET%^a%^BOLD%^%^BLACK%^ls%^RESET%^%^CYAN%^ are inlaid around the edge of the helm, adding an inky greenish glow to the darkened metal.  The surface of the helm is covered with jeweled dark disks made from %^BLUE%^dark sapphires%^CYAN%^, %^MAGENTA%^amethysts%^CYAN%^, and %^BOLD%^%^BLACK%^polished jet%^RESET%^%^CYAN%^.  An %^MAGENTA%^inscription %^CYAN%^is carved into the metal inside the helm.%^RESET%^");
   set_lore("Within the many tales of knights, one tale has always stood the test of time.  The story of Sir Laton Thunderfalls and his eternal foe Lady Lawaxana Al'Raisha.  Knighted as a Templar Knight of the Night, Sir Laton spread the message and fear of Lord Shadow throughout the lands.  Mounted on his nightmare steed and with his jet lance, Sir Laton was an imposing and powerful figure.  Lady Lawaxana was a noble from a Tsvaren household who dedicated herself as a Knight of the Dawn, pledging herself to serve Jarmila.  From the moment the two met, the animosity and loathing could be felt by all.  Sir Laton's and Lady Lawaxana's battles spread across the known lands, each seeking to put an end to the other.  It was not uncommon for the two to charge into battle against each other when spotted.  For her dedication to her faith, the cleric of Jarmila created the Helm of Brilliance to help her overcome her dark-loving foe.  Sir Laton was jealous of the gift that Lady Lawaxana had and prayed fervently to Lord Shadow to aid him in his battle.  It was when the Helm of Darkness came into being.  Like the eternal struggle of the night and the dawn, these two continued their battles on for decades. - A Knight's Tale - Master Ledger Heath Aussip");
   set_property("lore difficulty",18);
   set_value(8000);
   set_property("enchantment",2);
   set_item_bonus("sight bonus",2);
   set_sapphire(random(5) + 5);
   set_amethyst(random(10) + 10);
   set_bopal(random(10) + 20);
   set_jet(random(20) + 20);
   count = 0;
   flag = 0;
   set_heart_beat(1);
   set_wear((:TO,"wear_me":));
   set_remove((:TO,"remove_me":));
}

void init(){
   ::init();
   if(!objectp(TP)) return;
   if (!objectp(ETO)) return;
   if (TP != ETO) return;
   if(interactive(TP) && !owner && !avatarp(TP)) {
      owner = TPQN;
      tell_object(ETO, "%^BOLD%^%^BLACK%^The helm's magic shifts it to conform to fit your head.");
      set_size(TP->query_size());
   }
   add_action("read","read");
   add_action("throw","throw");
   add_action("smash","smash");
}

int wear_me(){
   if(ALIGN->is_good(ETO)){
      tell_object(ETO,"The helm reject someone of your nature!");
      return 0;
   }
   if(ETO->query_property("good item")) {
      tell_object(ETO,"The helm refuse to be worn while you're using such goodly items.");
      return 0;
   }
   if((int)ETO->query_level() < 25){
      tell_object(ETO,"%^MAGENTA%^The power of the helm is too great for one as weak as you!%^RESET%^");
      return 0;
   }
   tell_object(ETO,"%^BOLD%^%^BLACK%^A shadowy aura falls over the helm as you put it on.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^BLACK%^The helm seems to darken as "+ETOQCN+" dons it.%^RESET%^",ETO);
   TP->set_property("strength","fire");
   ETO->set_property("evil item",1);
   return 1;
}

int remove_me(){
   tell_object(ETO,"%^BOLD%^%^BLACK%^The shadowy aura fades away from the helm as you take it off.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^BLACK%^The helm seems to brighten a bit as "+ETOQCN+" removes it.%^RESET%^",ETO);
   ETO->remove_property("strength","fire");
   ETO->set_property("evil item",-1);
   return 1;
}

void read(string str){
   if(!str) return notify_fail("Read what?\n");
   if(member_array(str,TO->query_id()) == -1) return 0;
   tell_object(TP,"This Helm of Darkness the following functions:\n%^BLUE%^throw sapphire at <name>%^RESET%^: sends a darkbolt at target ("+query_sapphire()+" sapphires)\n%^MAGENTA%^smash amethyst%^RESET%^: raises an army of undead ("+query_amethyst()+" amethyst)\n%^GREEN%^throw bopal at <name>%^RESET%^: sends a weakening ray at a target ("+query_bopal()+" black opals)\n%^BOLD%^%^BLACK%^smash jet%^RESET%^: creates an orb of darkness ("+query_jet()+" jets)");
   return 1;
}

void throw(string str){
   string tmp;
   object ob;
   if(!str) return notify_fail("Throw what?\n");
   if(sscanf(str,"sapphire at %s",tmp)){
      if(TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()){
         TP->send_paralyzed_message("info",TP);
         return 1;
      }
      if(!TO->query_worn()) return notify_fail("You have to wear the helm first!\n");
      if(!(ob = present(tmp, ETP))) return notify_fail("That isn't here!\n");
      if(sapphire < 1) return notify_fail("The helm has no sapphires left.\n");
      tell_object(ETO,"%^BLUE%^You pull a sapphire from your helm and throw it at "+ob->QCN+"!%^RESET%^");
      tell_object(ob,"%^BLUE%^"+TPQCN+" pulls a sapphire from "+TPQP+" helm and throws it at you!%^RESET%^");
      tell_room(ETP,"%^BLUE%^"+TPQCN+" pulls a sapphire from "+TPQP+" helm and throws it at "+ob->QCN+"!%^RESET%^",({TP,ob}));
      new("/cmds/spells/d/_darkbolt")->use_spell(TP,ob,16,100,"cleric");
      TP->set_paralyzed(7,"Your hands are full at the moment.");
      sapphire -= 1;
      return 1;
   }
   if(sscanf(str,"bopal at %s",tmp)){
      if(TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()){
         TP->send_paralyzed_message("info",TP);
         return 1;
      }
      if(!TO->query_worn()) return notify_fail("You have to wear the helm first!\n");
      if(!(ob = present(tmp, ETP))) return notify_fail("That isn't here!\n");
	if(bopal < 1) return notify_fail("The helm has no black opals left.\n");
      tell_object(TP,"%^BOLD%^%^BLACK%^You pull a black opal from your helm and throw it at "+ob->QCN+"!%^RESET%^");
      tell_object(ob,"%^BOLD%^%^BLACK%^"+TPQCN+" pulls a black opal from "+TPQP+" helm and throws it at you!%^RESET%^");
      tell_room(ETP,"%^BOLD%^%^BLACK%^"+TPQCN+" pulls a black opal from "+TPQP+" helm and throws it at "+ob->QCN+"!%^RESET%^",({TP,ob}));
      new("/cmds/spells/r/_ray_of_enfeeblement")->use_spell(TP,ob,3,100,"mage");
      TP->set_paralyzed(7,"Your hands are full at the moment.");
      bopal -= 1;
      return 1;
   }
   return 0;
}

void smash(string str){
   string tmp;
   if(!str) return notify_fail("Smash what?\n");
   if(TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(str == "jet"){
      if(!TO->query_worn()) return notify_fail("You have to wear the helm first!\n");
      if(jet < 1) return notify_fail("The helm has no jets left.\n");
      tell_object(TP,"%^BOLD%^%^BLACK%^You pull an jet from the helm and smash it!%^RESET%^");
      tell_room(ETP,"%^BOLD%^%^BLACK%^"+TPQCN+" pulls an jet from "+TPQP+" helm and smashes it!%^RESET%^",TP);
      new("/cmds/spells/d/_darkness")->use_spell(TP,TP,6,100,"mage");
      TP->set_paralyzed(7,"Your hands are full at the moment.");
      jet -= 1;
      return 1;
   }
   if(str == "amethyst"){
      if(!TO->query_worn()) return notify_fail("You have to wear the helm first!\n");
      if(amethyst < 1) return notify_fail("The helm has no amethysts left.\n");
      tell_object(TP,"%^MAGENTA%^You pull a amethyst from the helm and smash it!%^RESET%^");
      tell_room(ETP,"%^MAGENTA%^"+TPQCN+" pulls a amethyst from "+TPQP+" helm and smashes it!%^RESET%^",TP);
      new("/cmds/spells/a/_animate_dead")->use_spell(TP,0,14,100,"mage");
      TP->set_paralyzed(7,"Your hands are full at the moment.");
      amethyst -= 1;
      return 1;
   }
   return 0;
}

void heart_beat(){
   object ob, holder, env, helm;
   env = ETO;
   if(!objectp(ETO)) return;
   if((helm = present("helm of darkness",ETO)) && living(ETO) && helm != TO){
      tell_object(ETO,"The helm resonates with energy in close proximity to another of its kind!");
      ETO->do_damage(ETO->return_target_limb(),roll_dice(15,15));
      ETO->add_attacker(TO);
      ETO->continue_attack();
      if(TO->query_worn()){
         ETO->force_me("remove helm of darkness");
      }
      TO->remove();
      return 1;
   }
   if(sapphire == 0 && amethyst == 0 && bopal == 0 && jet == 0){
      tell_room(EETO,""+ETOQCN+"'s helm crumbles to dust.",ETO);
      tell_object(ETO,"Your help crumbles to dust.");
      if(TO->query_worn()){
	   ETO->force_me("remove helm of darkness");
      }
      TO->remove();
      return 1;
   }
   count++;
   if(objectp(env) && living(env) && interactive(env)){
      holder = env->query_name();
   }else{
      return;
   }
   if(holder != owner && !wizardp(ETO)){
      tell_object(ETO,"The helm realizes you aren't its owner and disappears!");
      TO->remove();
   }else{
      return;
   }
}

