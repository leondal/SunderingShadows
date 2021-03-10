#include <std.h>
#include <daemons.h>
#include "/d/dagger/aketon/short.h"

inherit ARMOUR;

int uses;

void create() {
   ::create();
   set_id( ({"ring","ram","ram ring","ring ram"}) );
   set_name("ring of the ram");
   set("short","%^RESET%^%^BOLD%^Silver ring");
   set("long","%^BOLD%^This ornate silver ring has the head of a ram on "
       "it. The head seems to be sending a strong arua of evocation from it. "
      "A small inscription is carved on the band.");
   set_type("clothing");
   set_ac(0);
   set_limbs( ({"right hand"}) );
   set_weight(2);
   set_value(4000);
   set_property("magic",1);
   set_property("no animate",1);
   uses = random(5) + 6;
}

void query_uses() {
   return uses;
}

int read_ins(string str) {
   if(!str) return notify_fail("Read what?\n");
   if(str != "inscription") return 0;
   write("This is a ring of the ram. You can use it to strike on a living "
      "thing with three different power levels.");
   return 1;
}

int strike_func(string str) {
   string name,lvl;
   object vic;
   int mod;
   if(!query_worn()) return notify_fail("You have to wear the ring first!\n");
   if(!str) return notify_fail("Syntax: strike <living> light/medium/heavy\n");
   if(uses <= 0) {
      write("%^BOLD%^The ring is useless now.");
      remove();
      return 1;
   }
   if(TP->query_paralyzed()) return 0;
   if(sscanf(str,"%s %s",name,lvl) != 2)
      return notify_fail("Syntax: strike <living> light/medium/heavy\n");
   if(!present(name,ETP))
      return notify_fail("That is not here!\n");
   if(!living(vic = present(name,ETP)))
      return notify_fail("Target must be a living thing!\n");
   if(vic == TP)
      return notify_fail("Are you out of your mind?\n");
   if(member_array(lvl,({"light","medium","heavy"})) == -1)
      return notify_fail("Syntax: strike <living> light/medium/heavy\n");

   mod = -2;
   if((int)vic->query_size() == 1) mod--;
   if((int)vic->query_size() == 3) mod = mod+2;
   if((int)vic->query_stats("strength")<12) mod--;
   if((int)vic->query_stats("strength")>17 && vic->query_stats("strength")<21) mod = mod+3;
   if((int)vic->query_stats("strength")>20) mod = mod+6;
   if((string *)vic->query_attackers() != ({})) mod = mod-2;
   if(lvl == "medium") mod--;
   if(lvl == "heavy") mod = mod-2;

   tell_object(TP,"%^BOLD%^You strike at your target with power of the ram!");
   tell_object(vic,"%^BOLD%^"+TPQCN+" strikes at you with the power of the ram!");
   tell_room(ETP,"%^BOLD%^"+TPQCN+" strikes at "+vic->query_cap_name()+
      " with the power of the ram!",({vic,TP}));
   switch(lvl) {
      case "light":
         vic->do_damage("torso",roll_dice(1,6));
         uses = uses-1;
         break;
      case "medium":
         vic->do_damage("torso",roll_dice(2,6));
         uses = uses-2;
         break;
      case "heavy":
         vic->do_damage("torso",roll_dice(3,6));
         uses = uses-3;
         break;
   }
   if(!SAVING_D->saving_throw(TP,"spell",mod)) {
      tell_object(vic,"%^RED%^The force is so great that you are knocked "
         "down unconscious by the ramlike force.");
      tell_object(TP,"%^RED%^You knock "+vic->query_cap_name()+
         " unconscious with ramlike force!");
      switch(lvl) {
         case "light":
            vic->set_paralyzed(roll_dice(5,6),"%^RED%^You were knocked "
               "unconscious by the ramlike force!");
            break;
         case "medium":
            vic->set_paralyzed(roll_dice(8,6),"%^RED%^You were knocked "
               "unconscious by the ramlike force!");
            break;
         case "heavy":
            vic->set_paralyzed(roll_dice(12,6),"%^RED%^You were knocked "
               "unconscious by the ramlike force!");
            break;
      }
   }
   return 1;
}

void init() {
   ::init();
   if( !objectp(ETO) ) return;
   add_action("read_ins","read");
   add_action("strike_func","strike");
}
