#include "/d/dagger/aketon/short.h"

inherit ARMOUR;

int uses;

void create() {
   ::create();
   set_name("grey cloak");
   set_id( ({"cloak","cloak of elvenkind","elvenkind","grey cloak"}) );
   set("short","grey cloak");
   set("long","This cloak is made of good neutral grey cloth. A hood is "
      "sewed to the cloak. It looks just as an ordinary cloth cloak.");
   set_weight(4);
   set_type("clothing");
   set_limbs( ({"neck"}) );
   set_ac(0);
   set_value(12000);
   if( random(100) > 10 )
      set_size(2);
   else
      set_size(1);
   switch( random(3) ) {
      case 0:
         set_property("enchantment",2);
         break;
      case 1:
         set_property("enchantment",3);
         break;
      case 2:
         set_property("enchantment",4);
         break;
   }
   set_remove( (: TO,"unwear_func" :) );
   set_heart_beat(0);
   uses = 10 + random(5);
}

void init() {
   ::init();
   add_action("look_func","look");
   if( uses > 0 ) {
      add_action("activate_func","hood");
      add_action("deactivate_func","unhood");
   }
}

void look_func(string str) {
   if(!str || str != "hood") {
      return 0;
   }
   write("This hood is sewed to the cloak. You can probably hood or "
      "unhood yourself.\n\n%^MAGENTA%^Obsidian says: %^B_BLUE%^%^CYAN%^"
      "Wow wow you discovered the secret! But I warn you now, if you tell "
      "anyone about this cloak's special function, even the wizzes, I "
      "will kill you, repeatedly! I promise you. And if I found people "
      "running around with the cloak activated I would most likely remove "
      "this item from the game. I look forward to your cooperation."
      "%^RESET%^\n");
   return 1;
}

int activate_func(string str) {
   if( str ) {
      notify_fail("You cannot hood that!\n");
      return 0;
   }
   if( !query_property("enchantment") || !query_worn() ) {
      return 0;
   }
   if( uses > 0 ) {
      write("You hood your head and seem to merge with the surrounding.");
      set_heart_beat(5);
      tell_object(find_player("obsidian"),"Damn someone found the hood!!");
      if( !ETO->query_invis() )
         ETO->set_invis();
      uses--;
      return 1;
   }
   else {
      tell_object(ETO,"You sense the magic of the cloak diminishes.");
      call_out("remove_all",1);
      return 1;
   }
   return 0;
}

void remove_all() {
   if( interactive(ETO) ) {
      ETO->force_me("remove grey cloak");
   }
   set_value(200);
   remove_property("enchantment");
   remove_action("activate_func","hood");
   remove_action("deactivate_func","unhood");
   return;
}

int deactivate_func(string str) {
   if( str ) {
      notify_fail("You cannot unhood that!\n");
      return 0;
   }
   if( !query_property("enchantment") || !query_worn() ) {
      return 0;
   }
   tell_object(ETO,"You remove the hood.");
   set_heart_beat(0);
   if( ETO->query_invis() )
      ETO->set_invis();
   return 1;
}

void heart_beat() {
   if( !objectp(TO) || !objectp(ETO) || !objectp(environment(ETO)) )
      return;
   if( !interactive(ETO) )
      return;
   if( ETO->query_invis() ) {
      if( environment(ETO)->query_property("indoors") ) {
         if( (int)environment(ETO)->query_property("light") >= 3 ) {
            if( random(100) >= 50 )
               ETO->set_invis();
         }
         else if( random(100) >= 90 )
            ETO->set_invis();
      }
      else {
         if( (int)environment(ETO)->query_property("light") >= 3 ) {
            if( random(100) >= 95 )
               ETO->set_invis();
         }
         else if( random(100) >= 98 )
            ETO->set_invis();
      }
   }
   else {
      if( environment(ETO)->query_property("indoors") ) {
         if( (int)environment(ETO)->query_property("light") >= 3 ) {
            if( random(100) < 50 )
               ETO->set_invis();
         }
         else if( random(100) < 90 )
            ETO->set_invis();
      }
      else {
         if( (int)environment(ETO)->query_property("light") >= 3 ) {
            if( random(100) < 95 )
               ETO->set_invis();
         }
         else if( random(100) < 98 )
            ETO->set_invis();
      }
   }
}

int unwear_func() {
   TP->force_me("unhood");
   return 1;
}
