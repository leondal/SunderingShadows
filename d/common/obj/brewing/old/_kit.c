//*****************************************************************
//***************WARNING*******************************************
//        New kit inherit. Please be very careful!
//*****************************************************************
//*****************************************************************
#include <std.h>
#include <move.h>
#include "/d/common/common.h"
#define VALUE 1

inherit POTION;

#define GNOME         "\n\t%^RESET%^%^ORANGE%^The case can hold "+\
	"many vials, each one slipping into a pocket where tubes poke "+\
	"through valved holes in the cork.  The tubes from each vial are "+\
	"connected to a central one, allowing the user to quickly <quaff> "+\
	"or <drink> several doses by tipping it up or simply sucking the "+\
	"liquid through the central tube.  There seems to be a small "+\
	"flapper inside the drinking tube that prevents the potion from "+\
	"seeping out but gives way under suction or when held for drinking.  "+\
	"You will find the case itself will vaporize if all the vials are emptied."+\
  	"\n%^RESET%^You can <take # from kit> to split up the kit or you can "+\
	"<combine kit with kit #> to combine two kits."


int uses, toggle;
/* I can't see any actual use of the toggle variable doing anything, anyone 
*  see what I'm missing or can we take it out?  *Styx*  12/29/05
*/

//newbie stuff to support newbie-only potions ~Circe~ 6/3/07
//If a potion is going to be restricted, you simply do
//set_newbie_restricted(1); in the create()
//Right now, messages are hard-coded into this file.  If 
//we decide to restrict other potions, we could always just 
//add an ability to set the message.
void set_newbie_restricted(int x);
int query_newbie_restricted();

int newbie_restricted;

string potion_visual_look = "clear liquid";

string pot_visual() { return potion_visual_look;}

void set_pot_visual(string newvis) { 
  if (stringp(newvis))
    potion_visual_look = newvis;
  return;
}

void create() {
  ::create();
  set_name("Generic Kit");
  set_short("A kit of Generic Potions");
  set_id(({"vial","potion","kit","kitxyz"}));
  set_long("%^BOLD%^%^CYAN%^The pale generic liquid contained in this kit's "+
	"vials is smooth and tasteless.");
  set("color", "clear");
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
   drinker->remove_property("stomached_kits");
   tell_object(drinker, "%^BOLD%^The potion seems to cool your body.  But now that you think about it, it tasted like water!");
//   drinker->add_hp(roll_dice(2,4)+2);
   return 1;
}

int do_wear_off() {return 0;}

int wear_off() {
  do_wear_off() ;
  if(!uses) {
    //    destruct(this_object());
    TO->remove();
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

   switch(target->query_property("stomached_kits")) {
	case 0:
break;
case 1:
if (target != doer) tell_object(target,"The liquid feels warm in your stomach as it settles along the other potion.");
else
tell_object(doer,"The liquid feels warm in your stomach as it settles along the other potion.");
    break;
case 2:
if (target != doer) tell_object(target,"Your stomach is feeling half-full as the potion is forced down your throat.");
else
tell_object(doer,"Your stomach is feeling half-full as you drink the potion.");
    break;
case 3..5:
if (target != doer) tell_object(target,"Your stomach is feeling full and you don't think you'll be able to drink anything else after this one.");
else
tell_object(doer,"Your stomach is feeling full and you don't think you'll be able to drink anything else after this one.");
    break;
case 6..20:
if (target != doer) tell_object(target,"Your stomach is sloshing and you can't get the potion down into your stomach.");
else
tell_object(doer,"Your stomach is sloshing and you can't imagine drinking any more just yet.");

    return 0;
 default:
break;

}
  if(!uses) {return 0;}
  if( id(str)) {
    if(uses <1) return 0;
//Newbie code begins here
    if(query_newbie_restricted() && !newbiep(target)){
       if(doer == target){
          tell_object(target,"%^BOLD%^You have outgrown the ability "+
             "to use such kits!");
       }else{
          tell_object(doer,"%^BOLD%^"+target->QCN+" has outgrown "+
             "the ability to use such kits!");
       }
       return 1;
    }
//Newbie code ends here
    if (target->query_property("stomached_kits") > 4) {
      if (!interactive(doer)) {
	log_file("kits",base_name(doer)+": using kits too fast on:"+identify(target)+"\n");
	return 0; // So if it's an old-code monster,
      // spamming kits does not help it.
      } else {
	log_file("PC_kits",doer->query_true_name()+":"+ctime(time())+":"+target->query_property("stomached_kits")+".\n");
	 return notify_fail("You're far too full for that!");
	// Later.... :)
	  }
    }
    target->set_property("stomached_kits",1);
   
    seteuid(getuid());
    if(doer == target) {
      tell_object(doer,"You quickly quaff a dose of the "+pcolor+" potion%^RESET%^.");
      tell_room(ETP,doer->QCN +" quaffs some "+pcolor+" liquid %^RESET%^from a kit.",doer);
      drinker = doer;
    } else {
      tell_object(doer,"You force the draught from the "+pcolor+" potion %^RESET%^down "+target->QCN+"'s throat.");
      tell_room(ETP,doer->QCN +" forces some "+pcolor+" liquid%^RESET%^ down "+target->QCN+"'s throat.",({doer, target}));
      if(!target->query_unconscious()) {
	tell_object(target,doer->QCN+" forces you to drink some the "+pcolor+" liquid%^RESET%^.");
      }
      drinker = target ;
    }
    drinker->add_hp(random(5));  // added to make up for bottles going away
    uses--;
    set_weight(query_weight() - 2);
    ETO->add_encumbrance(-2);
    delay= (__COMBAT_SPEED__*2)+2; // Changing to combat round speed.
    //      delay=4+(random(4));
    //      make_empty(TP);  // doing away with bottles *Styx* 12/29/05
    //      call_out("potion_effect",delay, drinker);
    "/daemon/delay_d"->sleep( base_name(TO), "new_do_effect", delay, ({ drinker }) );

    if(!uses){
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
   if (query_newbie_restricted()) holder += " (newbie)";
  
  holder += " ["+uses+" left]";
  return holder;
}

string query_long(string str) {
  string holder;
  
  holder = ::query_long(str);
  holder += GNOME+"\n" ;
   if (query_newbie_restricted()) holder += "(A newbie-only kit)";
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
  tell_room(ETP,"%^BLUE%^You see "+TPQCN+" take several "+pot_visual()+" from "+TP->QP+" kit.",TP);
  write("%^BLUE%^You remove "+num+" vials from your "+pot_visual()+" kit.");
  if (ob->move(TP)) {
    write("%^BLUE%^You appear to have your arms too full and fumble the kit.");
    tell_room(ETP,"%^BLUE%^You see "+TPQCN+" fumble the "+pot_visual()+" kit and it falls to the ground",TP);
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
  
  if (base_name(ob) != base_name(TO)) return notify_fail("They're not the same kind of kit!\n");
  if (!(int)ob->query_newbie_restricted() != !query_newbie_restricted()) return notify_fail("They're not the same kind of kit!\n");
  num = ob->query_uses();
  set_uses(query_uses()+num);
  seteuid(getuid());
  ob->remove();
  TP->add_encumbrance(2*num);
  tell_room(ETP,"%^BLUE%^You see "+TPQCN+" combine two kits of "+pot_visual()+".",TP);
  write("%^BLUE%^You combine the two kits of "+pot_visual()+".");
  return 1;
}

int query_value(){
  int v = ::query_value();
  if(query_newbie_restricted()) { v = 10; }
  if(v) return v * uses;
  return uses * 20;
}

int clean_up() {
  if (!objectp(TO)) return 1;
  if (file_name(TO) != base_name(TO)) return ::clean_up();
  return 0;
}

int isMagic(){
   int magicpotion;
   magicpotion = ::isMagic();
   magicpotion = magicpotion+1;
   return magicpotion;
}

void set_newbie_restricted(int x){
   newbie_restricted = x;
}

int query_newbie_restricted(){
   return newbie_restricted;
}
