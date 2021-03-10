#include "/d/islands/giant/giant.h"

inherit WEAPON;

create() {
    ::create();
   set_id(({"hammer","crusher"}));
   set_name("%^RED%^The Crusher%^RESET%^");
   set_short("%^RED%^The Crusher%^RESET%^");
   set_long(
@TERRATO
      %^RED%^This is one of the most coveted of Giant weapons.  It was created
by one of the only magically talented giants to ever live.  It's
purpose was to defeat the enmies of the Giant people whose size made
them difficult to destroy.  It's name is spoken only in hused tones
amoung all of the small people of Shadowgate.
TERRATO
   );
   set_weight(30);
   set_size(4);
   set_value(15000);
   set_wc(1,10);
   set_large_wc(3,6);
   set_type("bludgeoning");
   set_prof_type("giant hammer");
   set_property("enchantment",3);
   set_hit((:TO, "hit_fun":));
   set_wield((:TO, "wield_fun":));
}

int wield_fun(){
   object ob;
   if((TP->query_level() < 25) || (TP->query_stats("strength") < 18)){
      tell_object(TP,"%^RED%^YTou are too weak and puny to wield this weapon of power and %^BLACK%^destruction%^RESET%^RED%^!");
      TO->remove_me();
      return 0;
   } else {
      new(HMON+"ant.c")->move(environment(TP));
      tell_object(TP,"%^RED%^You notice the ant and begin grinning like a madman as you raise the hammer high above your head and %^BOLD%^SLAM%^RESET%^%^RED%^ it down upon the small insect!%^RESET%^");
      tell_room(ETP,"%^RED%^"+TPQCN+" notices the ant and begin grinning like a madman as "+TP->query_subjective()+" raises the hammer high above "+TP->query_objective()+" head and %^BOLD%^SLAM%^RESET%^%^RED%^ it down upon the small insect!%^RESET%^",TP);
      tell_room(ETP, TPQCN+" %^RED%^%^BOLD%^roars like a crazed BEAST!%^RESET%^", TP);
      ob = present("ant", ETP);
      ob->do_damage(2,10);
      TP->force_me("kill ant");
      return 1;
   }
}

int hit_fun(object targ) {
   if(targ->query_size() < 2){
      tell_object(TP, "%^RED%^%^BOLD%^You deal your puny apponent a %^RESET%^%^BOLD%^MIGHTY%^RED%^ blow!%^RESET%^");
      tell_object(targ, "%^RED%^The Crusher wielded by "+TP->query_cap_name()+" slams into your small body dealing massive damage!");
      tell_room(ETP, "%^RED%^The Crusher%^BOLD%^ deals "+targ->query_cap_name()+" a %^RESET%^%^BOLD%^MIGHTY%^RED%^ blow!%^RESET%^", (({targ,TP})));
      targ->do_damage(1,10);
   }
   if(random(6) > 4){
      tell_object(TP, "%^RED%^The Crusher seems to aid you by putting it's full weight into your crushing blow!%^RESET%^");
      tell_object(targ, "%^RED%^the Crusher %^BOLD%^SLAMS %^RESET%^%^RED%^ into you with it's full weight!%^RESET%^");
      tell_room(ETP, "%^RED%^The Crusher %^BOLD%^SLAMS%^RESET%^%^RED%^ into "+TP->query_cap_name()+" foe with it's full weight!%^RESET%^", (({targ,TP})));
      return (random(8)+1);
   }
}
