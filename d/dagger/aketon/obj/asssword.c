#include <std.h>
#include <daemons.h>

inherit WEAPON;

string owner;

int flag;

create() {
   ::create();
   set_name("assassin longsword");
   set_id( ({"sword","longsword","assassin longsword","asssword"}) );
   set_short("%^RESET%^%^RED%^Longsword of the assassins");
   set_long("%^RED%^This is a blood stained, venom covered longsword "
      "used by the Assassins of Shadowgate. You feel lucky to be looking "
      "at one and not feeling it in your back and wounds.%^RESET%^");
   set_weight(15);
   set_value(1000);
   set_wc(2,4);
   set_large_wc(3,4);
   set_type("slashing");
   set_size(2);
   set_wield( (: TO,"more_wield" :) );
   set_unwield( (: TO,"more_unwield" :) );
   set_hit( (: TO,"more_hit" :) );
   set_property("enchantment",4);
   set_heart_beat(1);
   flag = 0;
}

int more_wield() {
   int bonus;
   bonus = (int)TP->query_class_level("assassin") / 5;
   if( wizardp(TP) || !interactive(TP) )
      return 1;
   if( (string)TPQN != owner || !TP->is_class("assassin") ) {
      write("%^RED%^The Longsword of the assassins fails bonding with you "
         "and vanishes.%^RESET%^");
      remove();
      return 0;
   }
   if( (int)TP->query_level() < 20 ) {
      write("You are not skillful enough to handle this sword!");
      return 0;
   }
   else {
      write("%^RED%^You feel the power of the Assassin Master within your "
         "hand.%^RESET%^");
      say("%^RED%^"+TPQCN+" looks shocked by a strange force.%^RESET%^");
      switch( (int)TP->query_size() ) {
         case 1:
            set_wc(2, 4 + (bonus + 1) );
            set_large_wc(3, 4 + (bonus + 1) );
            bonus -= 1;
            remove_property("enchantment");
            set_property("enchantment",bonus);
            while(query_property("enchantment") < 0) {
               remove_property("enchantment");
               set_property("enchantment",bonus);
            }
            break;
         case 2:
            bonus -= 2;
            set_wc(2, 4 + bonus);
            set_large_wc(3, 4 + bonus);
            remove_property("enchantment");
            if(bonus < 3)
               bonus = 3;
            if(bonus > 10)
               bonus = 10;
            set_property("enchantment",bonus);
            while(query_property("enchantment") < 0) {
               remove_property("enchantment");
               set_property("enchantment",bonus);
            }
            break;
         case 3:
            bonus -= 4;
            set_wc(2, 4 + bonus);
            set_large_wc(3, 4 + bonus);
            remove_property("enchantment");
            if(bonus < 3)
               bonus = 3;
            if(bonus > 6)
               bonus = 6;
            set_property("enchantment",bonus);
            while(query_property("enchantment") < 0) {
               remove_property("enchantment");
               set_property("enchantment",bonus);
            }
            break;
      }
      return 1;
   }
}

int more_unwield() {
   if( wizardp(TP) || !interactive(TP) )
      return 1;
   else {
      write("%^RED%^You will not have mercy on the wicked wanted one!");
      return 0;
   }
}

int more_hit(object vic) {
   int bonus,dam;
   object wielder;
   wielder = query_wielded();
   bonus = (int)wielder->query_class_level("assassin") / 5;
   if( !objectp(vic) || random(10) > 4 )
      return 0;
   message("my_action","%^RED%^You slash your sword deep into your "
      "opponent's flesh!%^RESET%^",wielder);
   message("other_action","%^RED%^"+wielder->query_cap_name()+" slashes "
      "deep into "+vic->query_cap_name()+"'s flesh!",environment(vic),
      ( ({wielder,vic}) ) );
   message("my_action","%^RED%^"+wielder->query_cap_name()+" slashes "
      "deep into your flesh!",vic);
   switch( (int)wielder->query_size() ) {
      case 1:
         dam = roll_dice( 2,4 + (bonus + 1) );
         break;
      case 2:
         dam = roll_dice( 2,4 + (bonus - 2) );
         break;
      case 3:
         dam = roll_dice( 2,4 + (bonus - 4) );
         break;
   }
   return dam;
}

void init() {
   int i;
   object *wielded;
   ::init();
   if( wizardp(TP) )
      return;
   if( !interactive(TP) )
      return;
   set_heart_beat(1);
   if(interactive(TP) && TP == environment(TO) && !owner) {
      owner = TPQN;
      if( TP->is_class("assassin") ) {
         set_short("%^RESET%^%^RED%^Longsword of "+capitalize(TPQN)+" the "
            "assassin");
         set_long("%^RED%^This is a blood stained, venom covered "
            "longsword used by "+capitalize(TPQN)+" the Assassin of "
            "Shadowgate. You feel lucky to be looking at one and not "
            "feeling it in your back and wounds.%^RESET%^");
      }
   }
   if( (object *)ETO->query_wielded() == ({}) ) {
      if( (int)ETO->query_size() == 1 )
         ETO->force_me("wield assassin longsword in left hand and right "
            "hand");
      else
         ETO->force_me("wield assassin longsword");
   }
}

int drop() {
   if( wizardp(TP) || !interactive(TP) )
      return 0;
   if( base_name(PO) != "/std/user" ) {
      write("%^RED%^Somehow you cannot drop the sword!");
      return 1;
   }
   set_wc(2,4);
   set_large_wc(3,4);
   remove_property("enchantment");
   set_property("enchantment",4);
   while(query_property("enchantment") < 0) {
      remove_property("enchantment");
      set_property("enchantment",4);
   }
}

void heart_beat() {
   string *badboy;
   object *living;
   int i,j,num;
   mixed *deaths;
   if( !objectp(TO) || !objectp(ETO) || !objectp(environment(ETO)) )
      return;
   if( wizardp(ETO) )
      return;
   if( flag )
      return;
   if( (object *)ETO->query_attackers() != ({}) )
      return;
   living = all_living( environment(ETO) );
   living -= ({ETO});
   for(j = 0;j < sizeof(living);j++) {
      if( !interactive(living[i]) ) {
         living -= ({living[i]});
         continue;
      }
   }
   badboy = KILLING_D->query_bounties() + KILLING_D->query_personals();
   for(i = 0;i < sizeof(living);i++) {
      if(member_array((string)living[i]->query_true_name(),badboy) != -1) {
         if( query_idle(living[i]) >= 60 )
            continue;
         if( query_idle(ETO) >= 60 )
            continue;
         if( (int)living[i]->query_lowest_level() < 6 )
            continue;
         if( (int)living[i]->query_level() < ((int)ETO->query_level()-25))
            continue;
         deaths = living[i]->query_deaths();
         num = sizeof(deaths);
         if( num > 0 ) {
            if( (time() - deaths[num-1][1]) < 900 )
               continue;
         }
         call_out("do_it",10,living[i]);
         flag = 1;
      }
   }
   return;
}

void do_it(object target) {
   flag = 0;
   if( !objectp(target) )
      return;
   if( !present(target->query_name(),environment(ETO)) )
      return;
   ETO->force_me("say In the name of the Law, I sentence you to "
      "death!");
   ETO->force_me("stab "+target->query_name());
   if( (int)target->query_level() >= ((int)ETO->query_level() + 5) ) {
      if( present("blinding powder",ETO) )
         ETO->force_me("toss powder at "+target->query_true_name());
   }
}

int save_me(string file) {
   return ::save_me(file);
}
