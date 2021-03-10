//updated by Circe 5/26/04 with new desc, lore, radiate magic, etc.
#include <std.h>
#include <move.h>

inherit POTION;


int uses, toggle;

void create() {
   ::create();
   set_name("bright white vial");
   set_obvious_short("%^BOLD%^A kit of bright white potions%^RESET%^");
   set_short("%^BOLD%^Potion of Extra Healing%^RESET%^");
   set_id(({"white","bright white","vial","potion","kit","kitxyz"}));
   set_long(
@OLI
           %^BOLD%^The bright white liquid in the kit swirls around.
           you can <take # from kit> to split up the kit or you can
           <combine kit with kit #> to combine two kits.
OLI
           );
    set_lore("This potion is one crafted by many healers of the land.  "+
       "Because of the ingredients used, such potions often have "+
       "similar qualities, such as color and smell.  The color of "+
       "this potion suggests it might be used to cure a good deal of "+
       "damage.");
    set_property("lore difficulty",12);
   set("color", "bright white");
   set("effect_time",30);
   uses = 1;
   toggle = 0;
   set_value(100);
   set_weight(2);
}
int do_effect() {
 return 0;
  }
void new_do_effect(object drinker) {
   int healing;
   if(!objectp(drinker)) return 1;
   if(drinker->query_hp() < drinker->query_max_hp()) {
      healing = random(8) + random(8) + random(8) + 3;
      tell_object(drinker,"Suddenly, you begin to feel better.\n");
      tell_object(drinker,"You have gained back "+healing+" hit points.\n");
      drinker->add_hp(healing);
   }
   else {
      tell_object(drinker,"You feel no different than before.\n") ;
   }
   return 1;
}

int do_wear_off() {return 0;}


int wear_off() {
   if(!uses) {
      do_wear_off() ;
      destruct(this_object());
   }
   return 1;
}

int quaff_potion(string str, object doer, object target) {

   object vial;
   int temp ;

   if(TP->query_bound() || TP->query_unconscious()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }

   if(doer != target && (!target->query_unconscious() && !target->query_bound())) {
      return notify_fail("You can't force a conscious and unbound player to drink.\n");
   }
   if(!uses) {return 0;}
   if( id(str)) {
      if(closed==1) {
         write("Perhaps you should open the potion vial first.\n");
         return 1;
      }

      if(uses <1) return 0;


      if(doer == target) {
         tell_object(doer,"You quickly quaff the draught from the "+query("color")+" potion.\n");
         tell_room(ETP,doer->query_cap_name() +" drinks from a small vial.\n",doer);
         seteuid(getuid());
         drinker = doer;
      }
      else {
         tell_object(doer,"You force the draught from the "+query("color")+" potion down "+target->query_cap_name()+"'s throat.\n");
         tell_room(ETP,doer->query_cap_name() +" forces "+target->query_cap_name()+" to drink from a small vial.\n",({doer, target}));
         if(!target->query_unconscious()) {
            tell_object(target,doer->query_cap_name()+" forces you to drink from the "+query("color")+" potion.\n");
         }
         seteuid(getuid());
         drinker = target ;
      }
      uses--;
      set_weight(query_weight() - 2);
      ETO->add_encumbrance(-2);
      delay=4+(random(4));
//      call_out("potion_effect",delay, drinker);
     "/daemon/delay_d"->sleep( "/d/common/obj/potion/extra_heal", "new_do_effect", delay, ({ drinker }) );

      if(!uses){
         move("/d/shadowgate/void");
         call_out("remove",30);
      }

// Don't want anyone messing with this while it's in effect.
// this isn't the Right Way to do this but it's better than
// any equally easy alternative.

      make_empty(TP);
      return 1;
   }
   return 0;
}

void add_use() {
   uses += 1;
}

int query_uses() {return uses;}

void set_uses(int num) {
   uses = num;
   set_weight(2 * num);
}


string query_short() {
   string holder;

   holder = ::query_short();

   holder += " ["+uses+" left]";
   return holder;
}

string query_long(string str) {
   string holder;

   holder = ::query_long(str);

   holder += "\t["+uses+" left]";
   return holder;
}

int restore_me(string file) {
   int holder;

   holder = ::restore_me(file);

   set_weight(uses *2);
   return holder;
}

void toggle() {
   if(!toggle)
      toggle = 1;
   else
      toggle = 0;
}


void init() {
   ::init();

   if(TP == ETO) {
      add_action("split","take");
      add_action("split","split");
//
      add_action("combine","combine");
      add_action("combine","join");
   }
}

int split(string str) {
   object ob;
   int num;
   string word;

   if(!str) return 0;

   if(sscanf(str,"%d from %s",num,word) !=2)
      return notify_fail("Syntax: take # from kit\n");

   if(num >= uses || num <= 0)
      return notify_fail("You may take from 1 to "+(uses-1)+" vials from this kit!\n");

   set_uses(uses-num);
   seteuid(getuid());
   ob=new(base_name(TO));
   ob->set_uses(num);
   ob->toggle();
   TP->add_encumbrance((-1)*2*num);
   ob->toggle();
   tell_room(ETP,"%^BOLD%^You see "+TPQCN+" take several vials from "+TP->query_possessive()+" kit.",TP);
   write("%^BOLD%^You remove "+num+" vials from your kit.");
   if (ob->move(TP)) {
      write("%^BOLD%^%^WHITE%^You appear to have your arms too full and fumble the kit.");
      tell_room(ETP,"%^BOLD%^%^WHITE%^You see "+TPQCN+" fumble the kit. and it falls to the
ground",TP);
      ob->move(ETP);
   }
   return 1;
}

int combine(string str) {
   object ob;
   int num;
   string targ, dest;

   if(!str) return 0;

   if(sscanf(str,"%s with %s",targ,dest) !=2)
      return notify_fail("Syntax: combine kit # with kit #\n");

   if(!id(targ))
      return 0;
   if(!ob=present(dest,TP))
      return notify_fail("No second kit.\n");
   if(!ob->query_b_white())
      return notify_fail("Those don't mix!\n");
   if(ob==TO)
      return notify_fail("You can't do that.\n");

   num = ob->query_uses();
   set_uses(query_uses()+num);
   seteuid(getuid());
   ob->remove();
   TP->add_encumbrance(2*num);
   tell_room(ETP,"%^BOLD%^You see "+TPQCN+" combine two kits of healing vials.",TP);
   write("%^BOLD%^You combine the two kits of healing vials.");
   return 1;
}

int query_b_white() {return 1;}

int query_value(){
   int v = ::query_value();
   if(v) return v;
    return uses * 50;
}

int isMagic(){
   int magicpotion;
   magicpotion = ::isMagic();
   magicpotion = magicpotion+1;
   return magicpotion;
}
