/* getting rid of bottles for more realism & less spam *Styx*  12/29/05 */

#include <std.h>
#include <move.h>
#include "/d/common/common.h"
#define VALUE 20

inherit POTION;

int uses, toggle;
/* I can't see any actual use of the toggle variable doing anything, anyone 
*  see what I'm missing or can we take it out?  *Styx*  12/29/05
*/

void create() {
  ::create();
  set_name("blue vial");
  set_short("A kit of blue healing vials");
  set_id(({"blue","vial","potion","kit","kitxyz"}));
  set_long("%^BOLD%^%^CYAN%^The pale blue liquid contained in this kit's "
	"vials is smooth but bitter.  %^RESET%^%^ORANGE%^The case can hold "
	"many vials, each one slipping into a pocket where tubes poke "
	"through valved holes in the cork.  The tubes from each vial are "
	"connected to a central one, allowing the user to quickly <quaff> "
	"or <drink> several doses by tipping it up or simply sucking the "
	"liquid through the central tube.  There seems to be a small "
	"flapper inside the drinking tube that prevents the potion from "
	"seeping out but gives way under suction or when held for drinking.  "
	"You will find the case itself will vaporize if all the vials are emptied."
  	"\n%^RESET%^You can <take # from kit> to split up the kit or you can "
	"<combine kit with kit #> to combine two kits.");

/*********
@OLI
  %^CYAN%^The pale blue liquid contained in this kit's vials
  is smooth but bitter. The case can hold many vials and it has .
  you can <take # from kit> to split up the kit or you can
  <combine kit with kit #> to combine two kits.
OLI
**********/
  set("color", "blue");
  closed = 0;  // added by *Styx* to simplify use and go with adapted describe
  uses = 1;
  toggle = 0;
  set_weight(2);
  set_cointype("gold");
}

// these would be the old functions, unused now since Garrett's fix
// probably can't comment them out because they overload the super (?)
int do_effect() {
   if(!objectp(drinker)) return 1;
   tell_object(drinker, "The potion seems to cool your body.");
   drinker->add_hp(roll_dice(2,4)+2);
//   if(!uses) remove();
   return 1;
}
int potion_effect() {
   int temp;
   do_effect();
   return 1;
}


int new_do_effect(object drinker) {
   if(!objectp(drinker)) return 1;
   tell_object(drinker, "%^BOLD%^The potion seems to cool your body.");
   drinker->add_hp(roll_dice(2,4)+2);
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
  string pcolor;
/* adding so it doesn't have to keep doing the query color as often as this runs *Styx* */
  pcolor = "%^BOLD%^%^CYAN%^"+query("color"); 
/* and adding a failure message if they don't have a string */
  if(!str) {
	write("Try <drink kit> or <quaff kit> (or vial or potion in place of kit)");
	return 0;
  }
  if(TP->query_bound() || TP->query_unconscious()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }

   if(doer != target && (!target->query_unconscious() && !target->query_bound())) {
      return notify_fail("You can't force a conscious and unbound player to drink.\n");
   }
   if(!uses) {return 0;}
   if( id(str)) {
/*  let's simplify this too and assume a one-way, self-closing/opening valve *Styx*
*      if(closed==1) {
*         write("Perhaps you should open the potion vial first.\n");
*         return 1;
*      }
*/
      if(uses <1) return 0;

      if(doer == target) {
         tell_object(doer,"You quickly quaff a dose of the "+pcolor+" potion%^RESET%^.");
         tell_room(ETP,doer->QCN +" quaffs some "+pcolor+" liquid %^RESET%^from a kit.",doer);
         seteuid(getuid());
         drinker = doer;
      }
      else {
         tell_object(doer,"You force the draught from the "+pcolor+" potion %^RESET%^down "+target->QCN+"'s throat.");
         tell_room(ETP,doer->QCN +" forces some "+pcolor+" liquid%^RESET%^ down "+target->QCN+"'s throat.",({doer, target}));
         if(!target->query_unconscious()) {
            tell_object(target,doer->QCN+" forces you to drink some the "+pcolor+" liquid%^RESET%^.");
         }
         seteuid(getuid());
         drinker = target ;
      }
      drinker->add_hp(random(5));  // added to make up for bottles going away
      uses--;
      set_weight(query_weight() - 2);
      ETO->add_encumbrance(-2);
      delay=4+(random(4));
//      make_empty(TP);  // doing away with bottles *Styx* 12/29/05

//      call_out("potion_effect",delay, drinker);
     "/daemon/delay_d"->sleep( base_name(TO), "new_do_effect", delay, ({ drinker }) );

// Don't want anyone messing with this while it's in effect.
// this isn't the Right Way to do this but it's better than
// any equally easy alternative.

      if(!uses){
//         move("/d/shadowgate/void");
//         call_out("remove",30);
       TO->remove();
      }
      return 1;
   }
   return 0;
}

void add_use() {   uses += 1; }

int query_uses() {return uses;}

void set_uses(int num) {
   if(num < 0) num = -1*num;
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
      add_action("combine","combine");
      add_action("combine","join");
   }
}

int split(string str) {
   object ob;
   int num;
   string word;

   if(TP->query_bound() || TP->query_unconscious()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!str) return 0;

   if(sscanf(str,"%d from %s",num,word) !=2)
      return notify_fail("Syntax: take # from kit\n");
   if(!id(word)) return 0; //added by Circe so it won't conflict with quivers

   if(num >= uses || num <= 0)
      return notify_fail("You may take from 1 to "+(uses-1)+" vials from this kit!\n");

   set_uses(uses-num);
   seteuid(getuid());
   ob=new(base_name(TO));
   ob->set_uses(num);
   ob->toggle();  // I really don't see this actually doing anything *Styx*
   TP->add_encumbrance((-1)*2*num);
   tell_room(ETP,"%^BLUE%^You see "+TPQCN+" take several vials from "+TP->QP+" kit.",TP);
   write("%^BLUE%^You remove "+num+" vials from your kit.");
   if (ob->move(TP)) {
      write("%^BLUE%^You appear to have your arms too full and fumble the kit.");
      tell_room(ETP,"%^BLUE%^You see "+TPQCN+" fumble the kit and it falls to the ground",TP);
      ob->move(ETP);
   }
   ob->toggle();
   return 1;
}

int combine(string str) {
   object ob;
   int num;
   string targ, dest;

   if(!str) return 0;

   if(TP->query_bound() || TP->query_unconscious()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(sscanf(str,"%s with %s",targ,dest) !=2)
      return notify_fail("Syntax: combine kit # with kit #\n");

   if(!id(targ))
      return 0;
   if(!ob=present(dest,TP))
      return notify_fail("No second kit.\n");
   if(ob==TO)
      return notify_fail("You can't do that.\n");
   if(!id(dest)) return 0;

   if(ob->query_b_white())
     return notify_fail("Those don't mix!\n");
   num = ob->query_uses();
   set_uses(query_uses()+num);
   seteuid(getuid());
   ob->remove();
   TP->add_encumbrance(2*num);
   tell_room(ETP,"%^BLUE%^You see "+TPQCN+" combine two kits of healing vials.",TP);
   write("%^BLUE%^You combine the two kits of healing vials.");
   return 1;
}

int query_value(){
   int v = ::query_value();
   if(v) return v;
    return uses * 20;
}

int clean_up() {
  if (file_name(TO) != base_name(TO)) return ::clean_up();
  return 0;
}
