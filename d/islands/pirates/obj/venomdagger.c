#include <std.h>
inherit "/d/common/obj/weapon/dagger";

int charges, venom, poisonstr;

void create(){
   ::create();
   set_name("dagger");
   set_id(({"dagger of venom","dagger","venom dagger","ornate dagger"}));
   set_short("%^RESET%^%^GREEN%^Dagger of Venom%^RESET%^");
   set_obvious_short("an ornate dagger");
   set_long("%^BOLD%^%^GREEN%^This short, ornate dagger is rather strange in appearance, and holds a rather "
"odd balance, as if the hilt were hollow for some reason.  The hilt is exquisitely designed; it is made from "
"what seems like some sort of %^RESET%^%^GREEN%^green crystal%^BOLD%^, and carries a recessed button at its "
"base.  Its blade appears to have two tiny channels running through it, right to the sharpened tip"
".%^RESET%^");
   set_weight(3);
   set_value(500);
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"removeme":));
   set_hit((:TO,"extra_hit":));
   set_prof_type("venomdagger");
   set_property("enchantment",2);
   charges=5;
   set_lore("%^WHITE%^%^BOLD%^You recall similarly designed weapons as this from your studies, commonly used "
"by thieves and assassins.  One can %^YELLOW%^<inspect>%^WHITE%^ the dagger to check if it has been filled "
"with venom.  If it is filled, you can %^YELLOW%^<press>%^WHITE%^ the button to drain some of the venom into "
"the blade, allowing for the next attack of the weapon to be poisoned.  If it is empty, with a proper "
"container of the venom you can %^YELLOW%^<refill>%^WHITE%^ the dagger with it.%^RESET%^\n");
   set_property("lore difficulty",10);
}

void init(){
   ::init();
   add_action("press","press");
   add_action("inspect","inspect");
   add_action("refill","refill");
}

int wield_func(string str){
   if(TP->query_level() < 15){
     tell_object(ETO,"You are not experienced enough to wield that!");
     return 0;
   }
   tell_object(ETO,"%^BOLD%^%^GREEN%^You wrap your hand knowingly around the hilt of the dagger.%^RESET%^");
   tell_room(EETO,"%^GREEN%^"+TPQCN+" wields an exquisite looking dagger.%^RESET%^",ETO);
   ETO->set_property("evil item",1);
   return 1;
}

int removeme() {
   ETO->set_property("evil item",-1);
   return 1;
}

int press(string str){
   if(!str) return notify_fail("Press what?\n");
   if(str != "button") return notify_fail("You can't press that.\n");
   if(venom==1) return notify_fail("But the dagger is already envenomed!\n");
   if(ALIGN->is_good(TP)) return notify_fail("Your conscience would never allow you to do that.\n");
   if(charges==0) return notify_fail("The venom cartridge is empty!\n");

   tell_object(TP,"You press the button and a %^GREEN%^vile green liquid%^RESET%^ fills the blade's "
"channels.");
   tell_room(environment(TP),""+TPQCN+" fiddles with a dagger.",TP);
   poisonstr=(roll_dice(1,5));
   charges=charges-1;
   venom=1;
   if(userp(TP)) TP->set_paralyzed(2,"%^BOLD%^%^GREEN%^You are still activating the dagger.%^RESET%^");
   return 1;
}

int inspect(string str){
   if(!str) return notify_fail("Inspect what?\n");
   if(str != "dagger") return notify_fail("You can't refill that.\n");
   if(venom==1){
     tell_object(TP,"The channels on the blade are filled with %^GREEN%^vile green venom%^RESET%^!");
     return 1;
   }
   tell_object(TP,"The channels on the blade are empty.");
   return 1;
}

int refill(string str){
   object ob;
   if (!str) return notify_fail("Refill what?\n");
   if(!(ob = present(str,TP)) || ob != TO) return 0;
   if(charges==5) return notify_fail("Your venom dagger is already full.\n");

   if (ob=present("container of venom",TP)){
     tell_object(TP,"You refill the hilt of the dagger with %^GREEN%^venom%^RESET%^.");
     tell_room(ETP,""+TPQCN+" fills the hilt of a dagger with a %^GREEN%^foul smelling liquid.%^RESET%^",TP);
     charges=5;
     ob->remove();
     return 1;
   }
   return notify_fail("You need a container of venom to do that.");
}

int extra_hit(object targ){
   if(!objectp(targ)) return 0;
   if(!objectp(ETO)) return 0;
   targ = ETO->query_current_attacker();
   if(venom==1){
     tell_object(ETO,"%^GREEN%^Your envenomed blade unleashes its deadly wrath on "+targ->QCN+"!%^RESET%^");
     tell_object(targ,""+ETOQCN+" stabs you with a strange dagger, and your blood %^RED%^burns%^RESET%^!");
     tell_room(EETO,"%^GREEN%^"+ETOQCN+" takes a stab at "+targ->QCN+", who screams in agony!%^RESET%^",({ETO,targ}));
     venom=0;

     if("daemon/saving_d"->saving_throw(targ,"paralyzation_poision_death")) {
       tell_object(targ,"The wound burns fiercely, but the pain subsides seconds later.");
       return 0;
     }
     call_out("burn",5,targ,1);
     return 0;
   }
   return 0;
}

void burn(object ob, int time){
   if(!objectp(ob)) return;
   switch (time){
     case 1..4:
     tell_object(ob,"%^RED%^The stabbed wound aches, and your blood burns fiercely!");
     ob->do_damage("torso",random(10)+3);
     call_out("burn",5,ob,time+1);
     break;

     case 5:
     tell_object(ob,"%^RED%^The burning sensation from the wound finally subsides!");
     break;
   }
}

