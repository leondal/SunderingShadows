
// potion.c
// Written by Valkyrie@TMI-2
// Cleaned up a little by Mobydick@TMI-2 on 8-17-93
// This is the basic potion object. A user can open the potion and
// drink it. If that happens, the potion takes effect after 5-15
// seconds, and the function do_effect() is called. After the effect
// time passes, the function do_wear_off() is called, and the object
// destructs itself.
// To create a potion for yourself, make an object that inherits this
// object, and just add a do_effect() and a do_wear_off() function
// which do what you want your potion to do. See /obj/strength_potion.c
// for an example.
// When the user drinks the potion, an empty vial is created and move
// to him, and the potion object goes invisible. The call_out remains
// active in the potion object: the potion object stays on the user
// until the effect wears off, and it's dested then. This isn't the
// most robust way to handle things but it is very easy and flexible,
// and it's wonderfully OO.  ;)

#include <config.h>
#include <std.h>
#include <move.h>
inherit OBJECT;

// Drinker stores an object pointer to the person who drunk the potion.
// This is needed because this_player() isn't defined in the call_out.
object drinker ;
int closed;
int delay;
int full;

int do_effect();
int do_wear_off();
void make_empty(object player);
int quaff_potion(string str, object doer, object target);


void create() {
   ::create();
   set_id( ({ "potion", "vial"}) ) ;
   set_name("potion vial");  // added name here because several don't have them set and I may not find them all to fix them all - it was causing throw to bug.  *Styx*  4/17/03
   closed=1;
   full=1;
// effect_time is the length of time the potion is in effect.
   if(!query("effect_time")) set ("effect_time", 200) ;
// color is the color of the potion...

   if(!query("color")) set ("color", "black") ;
   set_weight(1);  // added to have a default min. *Styx* 1/1/06
}


void init() {
   string *hold;

 ::init();

   add_action("open_bottle","open");
   add_action("close_bottle","close");
   add_action("close_bottle","cork");
   if(TP == ETO) {

   add_action("potion_init","drink");
   add_action("potion_init","quaff");
   add_action("force_feed","feed");
}
}

int close_bottle(string str) {
   if(id(str) ) {
      if(closed==0) {

         if(TP->query_bound() || TP->query_unconscious()) {
            TP->send_paralyzed_message("info",TP);
            return 1;
         }
         closed=1;
         write("You cork the vial containing a "+query("color")+" potion.\n");
         tell_room(ETP,this_player()->query_cap_name() +" corks a small vial.\n",TP);
         return 1;
      }
      return notify_fail("The vial containing the "+query("color")+" potion is already corked.\n");
      }
   return 0;
}

int open_bottle(string str) {
   if(!full) {return 0;}
   if(TP->query_bound() || TP->query_unconscious()) {
      TP->send_paralyzed_message("info",TP);
      return 1;}

   if(id(str) ) {
      if(closed==1) {
         closed=0;
         write("You open a vial containing a "+query("color")+" potion.\n");
         tell_room(ETP,this_player()->query_cap_name() +" opens a small vial.\n",TP);
         return 1;}
      tell_object(TP,"The vial containing the "+query("color")+" potion %^RESET%^is already open.");
//Minor typo fix by Circe - return notify fail was messing up the color codes 12/1/07
      return 1;
      }
   return 0;

}

int potion_init(string str) {
   return quaff_potion(str, TP,TP);
}

int force_feed(string str){
   string what,who;
   object whoO;
   if (!str) {
      return notify_fail("feed <potion> to <target>\n");
   }
   if (sscanf(str, "%s to %s",what,who) != 2) {
      return notify_fail("feed <potion> to <target>\n");
   }

   if (!whoO = present(who, ETP)) {
      return notify_fail("That person is not present.\n");
   }
   return quaff_potion(what,TP,whoO);
}

int quaff_potion(string str, object doer, object target) {

   object vial;
   int temp ;

   if(doer->query_bound() || doer->query_unconscious()) {
      doer->send_paralyzed_message("info",doer);
      return 1;}
   if(doer->query_paralyzed())
      return notify_fail(doer->query_paralyze_message()+"\n");
   if(!full) {
      return 0;
   }
   if (doer != target && (!target->query_unconscious() && !target->query_bound())) {
      return notify_fail("You can't force a conscious and unbound player to drink.\n");
   }
   if( id(str)) {
      if(closed==1) {
         tell_object(doer,"Perhaps you should open the potion vial first.\n");
         return 1;
      }
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
      full=0;
      delay=5+(random(15));
      call_out("potion_effect",delay);

// Don't want anyone messing with this while it's in effect.
// this isn't the Right Way to do this but it's better than
// any equally easy alternative.

//        make_empty(TP);
      return 1;}
   return 0;}

int potion_effect() {
   int temp;
   do_effect();
     if(query("effect_time"))
   call_out ("wear_off", query("effect_time")) ;
   return 1;}

int do_effect() {    // define potion effect here
   return 1;}

int wear_off() {
   do_wear_off() ;
   destruct(this_object());
   return 1;}

void make_empty(object player) {
   object empty;
   string empty_name;

   if(!query("empty name")) set("empty name", "bottle");
   empty_name = query("empty name");
   empty = new("std/Object");
   empty->set_name("bottle");
   empty->set_short("An empty "+empty_name);
   empty->set_long("A "+empty_name+" which used to hold something.\n");
   empty->set_id( ({ empty_name, query_short(), "empty container", "vial"}) );
   empty->set_cointype("silver");
   empty->set_value(10);
   empty->set_cointype("silver");
   empty->set_weight(2);
   empty->set_destroy(1);
   if(empty->move(player) != MOVE_OK) empty->remove();
}

set_id(string stuff) {
   ::set_id(stuff);}





string query_long(string stuff) {
  if (full)
   return ::query_long(stuff);
 else
  return "The crystal vial is empty.\n";
}
string query_short() {
  if (full) return ::query_short();
  else return "A crystal vial";
}
