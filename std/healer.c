// /std/healer.c
// added messages to the room for better feel of interactions & put max of 20
// changed to prevent commands working in combat. Nienne, 11/06
#include <std.h>
#include <objects.h>
#include <money.h>
#include <move.h>
#include <daemons.h>
#define ADJUST_COST(x) "/std/vendor"->adjust_cost(x)
#define MAX_HP_LIMIT 75
#define MAX_HP_LIMIT_II 150
#define MAX_HP_LIMIT_III 250
#define TIER_I 1
#define TIER_II (TIER_I   * 5)
#define TIER_III (TIER_II * 5)
#define TIER_IV (TIER_III * 5)
inherit ROOM;

int cl, cs, cc, np, bp, cb, bnp, cd, rnl;
string name;

//newbie_heal stuff added by Circe for lower-cost healing
//vials usable by newbies only 6/3/07
//If you are going to sell the newbie-only potions in the shop,
//set_newbie_heal(1); in create for the shop.  Note that this
//overrides the normal potions

void set_newbie_heal(int x);
int query_newbie_heal();

int newbie_heal;

void create() {
    ::create();
    set_property("training",1);
    cl = 20;
    cs = 45;
    cc = 100;
    np = 150;
    bp = 30;
    cb = 150;
    cd = 750;
    rnl = 15000;
    name = "The Healer";
}

void init() {
    object ob;
    ::init();
    add_action("cure_wounds", "cl");
    add_action("cure_wounds", "cs");
    add_action("cure_wounds", "cc");
    add_action("neut_poison", "np");
    add_action("buy_potion", "bp");
    add_action("buy_potion", "bxp");
    add_action("buy_potion", "bap");
    add_action("buy_potion", "blp");
    add_action("buy_potion", "bnp");
    add_action("cure_disease", "cd");
    add_action("cure_blindness", "cb");
    add_action("read_list","read");
    add_action("read_list","look");
}

int read_list(string str){
    if(str !="list") return 0;
    write("%^BOLD%^The Healer negotiates these prices with you \n"
          "%^BOLD%^%^MAGENTA%^-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-%^RESET%^%^CYAN%^\n"
          "cl    cure light wounds                 for "+ADJUST_COST(cl)+" gold \n"
          "cs    cure serious wounds               for "+ADJUST_COST(cs)+" gold \n"
          "cc    cure critical wounds              for "+ADJUST_COST(cc)+" gold \n"
          "np    neutralize all poison             for "+ADJUST_COST(np)+" gold \n"
          "bp    buy a healing potion              for "+ADJUST_COST(bp* TIER_I)+" gold \n"
          "bxp   buy an extra healing potion       for "+ADJUST_COST(bp*TIER_II)+" gold \n"
          "bap   buy an advanced healing potion    for "+ADJUST_COST(bp*TIER_III)+" gold \n"
          "blp   buy a legendary healing potion    for "+ADJUST_COST(bp*TIER_IV)+" gold \n"
          "cb    cure your blindness               for "+ADJUST_COST(cb)+" gold \n"
          "cd    cure your diseases                for "+ADJUST_COST(cd)+" gold \n"
          "%^BOLD%^%^MAGENTA%^-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n"
    );
    if(query_newbie_heal()){
       write("bnp : buy a newbie healing potion for "+ADJUST_COST(bnp*TIER_I)+" gold \n");
    }
    return 1;
}

void set_cl_price(int price){cl = price;}
void set_cs_price(int price){cs = price;}
void set_cc_price(int price){cc = price;}
void set_np_price(int price){np = price;}
void set_name(string healer_name){
    object ob;
    name = capitalize(healer_name);

    ob = present(name, TO);
}
void set_bp_price(int price){bp = price;}
void set_bnp_price(int price){bnp = price;}
void set_cb_price(int price){cb = price;}

string query_long(string str){
    string hold;

   if(str) return room::query_long(str);
          hold = room::query_long(str);
    hold += "\n%^RESET%^There is a %^BOLD%^list%^RESET%^ on the wall you can <read>.\n";
    return hold;
}

void cure_wounds(string str) {
    object ob;
   int fundage;
    if(TP->query_hidden())
	TP->force_me("step");

    if(!(ob = present(lower_case(name)))){
        tell_object(TP, "The healer is not here right now.");
        return 1;
    }
    if(sizeof(ob->query_attackers())){
        tell_object(TP, "The healer is a little busy right now!");
        return 1;
    }
    if(sizeof(TP->query_attackers())){
        tell_object(TP, "You're a little busy right now!");
        return 1;
    }
    if(!ob->should_interact(TP)){
       ob->force_me("emote waves you away in refusal.");
        ob->force_me("say Leave before you tarnish my image.");
       return 1;
    }
   if (TP->query_hp() >= TP->query_max_hp()) {
     ob->force_me("emote looks you over and scoffs.");
         ob->force_me("say You look like you aren't hurt! How can I help you?");
   }
   switch (query_verb()) {
  case "cl":
   fundage = cl;
   break;
  case "cs":
   fundage = cs;
   break;
  case "cc":
   fundage = cc;
   break;
  default:
   break;
   }
    if(!TP->query_funds("gold",ADJUST_COST(fundage))) {
//      tell_object(TP, "You don't have enough money!");
	tell_room(TO, name+" seems to be negotiating with "+TPQCN+".", TP);
	tell_room(TO, "%^MAGENTA%^"+name+" says:  %^RESET%^That's not enough money you have there, sorry.");
        return 1;
    }
    switch (query_verb()){
    case "cl":
      TP->add_hp(random(8)+1);
      //added +1 so it always does at least 1.  Circe 6/26/04
      tell_object(TP, name+" applies a balm that heals your wounds.");
      tell_room(TO, name+" collects some money and then proceeds to apply a balm to "+TPQCN+"'s wounds.", TP);
      TP->use_funds("gold", ADJUST_COST(cl));
      break;
    case "cs":
      TP->add_hp(roll_dice(2,8)+1);
      tell_object(TP, name+" heals and binds your wounds.");
      tell_room(TO, name+" collects some money and then proceeds to heal and bind "+TPQCN+"'s wounds.", TP);
      TP->use_funds("gold", ADJUST_COST(cs));
      break;
    case "cc":
      TP->add_hp(roll_dice(3,8)+3);
      tell_object(TP, name+" covers your wounds with a pungent salve.");
      tell_room(TO, name+" collects some money and then covers "+TPQCN+"'s wounds with a pungent salve.", TP);
      TP->use_funds("gold", ADJUST_COST(cc));
      break;
    default:
      break;
    }
    return 1;
}

void cure_disease(string str)
{
    object ob, *inv, *ppl;
    int x, i;
    string curemsg;
    if(TP->query_hidden())
	TP->force_me("step");

    if(!(ob = present( lower_case(name)))){
        tell_object(TP, "The healer is not here right now.");
        return 1;
    }
    if(sizeof(ob->query_attackers())){
        tell_object(TP, "The healer is a little busy right now!");
        return 1;
    }
    if(sizeof(TP->query_attackers())){
        tell_object(TP, "You're a little busy right now!");
        return 1;
    }
    if(!ob->should_interact(TP)){
        ob->force_me("emote waves you away in refusal");
        ob->force_me("say leave before you tarnish my image.");
        return 1;
    }
    if(!TP->query_funds("gold",ADJUST_COST(cd))) {
//        tell_object(TP, "You don't have enough money!");
        tell_room(TO, name+" seems to be negotiating with "+TPQCN+".", TP);
        tell_room(TO, "%^MAGENTA%^"+name+" says:  %^RESET%^That's not enough money you have there, sorry.");
        return 1;
    }
    //TP->add_poisoning(-(int)TP->query_poisoning());

    tell_object(TP,name+" tosses a soft white powder all over the room!");
    tell_room(TO, name+" collects some money and then tosses a soft white powder all over room!", TP);
    ppl = all_inventory(TO);

    filter_array(deep_inventory(TO), (:$1->is_disease():))->remove();

    TP->use_funds("gold", ADJUST_COST(cd));
    return 1;
}

void neut_poison(string str)
{
    object ob;
    if(TP->query_hidden())
	TP->force_me("step");

    if(!(ob = present( lower_case(name)))){
        tell_object(TP, "The healer is not here right now.");
        return 1;
    }
    if(sizeof(ob->query_attackers())){
        tell_object(TP, "The healer is a little busy right now!");
        return 1;
    }
    if(sizeof(TP->query_attackers())){
        tell_object(TP, "You're a little busy right now!");
        return 1;
    }
    if(!ob->should_interact(TP)){
       ob->force_me("emote waves you away in refusal");
       ob->force_me("say leave before you tarnish my image.");
       return 1;
    }
    if(!TP->query_funds("gold",ADJUST_COST(np))) {
//        tell_object(TP, "You don't have enough money!");
	tell_room(TO, name+" seems to be negotiating with "+TPQCN+".", TP);
	tell_room(TO, "%^MAGENTA%^"+name+" says:  %^RESET%^That's not enough money you have there, sorry.");
        return 1;
    }
    //TP->add_poisoning(-(int)TP->query_poisoning());

    tell_object(TP,name+" administers an antidote that cures your poisoning.");
    tell_room(TO, name+" collects some money and then administers an antidote to "+TPQCN+".", TP);
    POISON_D->clear_poisons_by_dc(TP, 1000, 0);
    TP->use_funds("gold", ADJUST_COST(np));
    return 1;
}

void buy_potion(string str){
    object ob;
    int num, funds;
    object ob2;
    string verb;
    verb = query_verb();
    if(TP->query_hidden())
	TP->force_me("step");


    if(!(ob2 = present( lower_case(name)))){
        tell_object(TP, "The healer is not here right now.");
        return 1;
    }
    if(sizeof(ob2->query_attackers())){
        tell_object(TP, "The healer is a little busy right now!");
        return 1;
    }
    if(sizeof(TP->query_attackers())){
        tell_object(TP, "You're a little busy right now!");
        return 1;
    }
    if(!ob2->should_interact(TP)){
       ob2->force_me("emote waves you away in refusal");
       ob2->force_me("say Leave before you tarnish my image.");
       return 1;
    }


    if ((TP->query_max_hp() < MAX_HP_LIMIT) && (verb == "bxp")) {
      ob2->force_me("emote looks at you and sternly shakes his head.");
      ob2->force_me("say I can't sell that to you, my other clients would riot!");
      return 1;
    }
    if ((TP->query_max_hp() < MAX_HP_LIMIT_II) && (verb == "bap")) {
      ob2->force_me("emote looks at you and sternly shakes his head.");
      ob2->force_me("say I can't sell that to you, my other clients would riot!");
      return 1;
    }
    if ((TP->query_max_hp() < MAX_HP_LIMIT_III) && (verb == "blp")) {
      ob2->force_me("emote looks at you and sternly shakes his head.");
      ob2->force_me("say I can't sell that to you, my other clients would riot!");
      return 1;
    }
    if(!str) return notify_fail(verb+" <amount of vials>\n");
    if(sscanf(str,"%d",num) != 1)
        return notify_fail(verb+" <amount of vials>\n");
    if(num > 50)
     return notify_fail("Please buy in kits of 50 or less vials at a time.");
    switch(verb) {
    case "blp":
      funds=((int)ADJUST_COST(bp)) * num * TIER_IV;
      break;

    case "bap":
      funds=((int)ADJUST_COST(bp)) * num * TIER_III;
      break;
    case "bxp":
      funds=((int)ADJUST_COST(bp)) * num * TIER_II;
      break;
    case "bnp":
      funds=((int)ADJUST_COST(bnp)) * num * TIER_I;
      break;
    case "bp":
    default:
      funds=((int)ADJUST_COST(bp)) * num * TIER_I;
      break;
    }

    if(!TP->query_funds("gold",funds)){
	tell_room(TO, name+" seems to be negotiating with "+TPQCN+".", TP);
	tell_room(TO, "%^MAGENTA%^"+name+" says:  %^RESET%^That's not enough money you have there, sorry.");
//      tell_object(TP, "You don't have enough money!");
        return 1;
    }
    if(num < 1) return notify_fail("The phrase get real comes to mind.\n");
    TP->set_adminBlock(1);
    switch(verb) {
    case "blp":
      ob = new("/d/common/obj/potion/legendary_heal.c");
      break;
    case "bap":
      ob = new("/d/common/obj/potion/advanced_heal.c");
      break;
    case "bxp":
      ob = new("/d/common/obj/potion/extra_heal.c");
      break;
    case "bnp":
      if(query_newbie_heal()){
         ob = new("/d/common/obj/potion/newbie_healing.c");
         break;
      }else{
         tell_room(TO,"%^MAGENTA%^"+name+" says%^RESET%^: I don't sell newbie potions here.");
         return;
      }
    case "bp":
    default:
      ob = new("/d/common/obj/potion/healing.c");
      break;
    }
    ob->set_uses(num);
    if((string)ob->move(TP) == MOVE_OK){
	    if (num == 1){
        	tell_object(TP, name+" takes your money and gives you a healing potion.");
    	}
    	else {
	    	tell_object(TP, name+" takes your money and gives you a kit containing "+num+" vials filled with healing potion.");
    	}
	tell_room(TO, name+" takes some money and hands a kit of healing vials to "+TPQCN+".", TP);

       } else {
       tell_room(ETP, name+" sets the healing potion on a table.");
       ob->move(ETP);
       }
        TP->use_funds("gold",funds);
        return 1;
/*   }  Changed above to move kit to room so it's not orphaned in memory if they can't carry it.
Changed again to max 50 at a time to solve typo problems with kits to large to split up.
Styx  3/16/03
  write("You can't carry any more!");  (was stranding objects in memory)*Styx*
  return 1;
*/
}

void cure_blindness(string str) {
    object ob;
    if(TP->query_hidden())
	TP->force_me("step");

    if(!(ob = present( lower_case(name)))) {
        tell_object(TP, "The healer is not here right now.");
        return 1;
    }
    if(sizeof(ob->query_attackers())) {
        tell_object(TP, "The healer is a little busy right now!");
        return 1;
    }
    if(sizeof(TP->query_attackers())){
        tell_object(TP, "You're a little busy right now!");
        return 1;
    }
    if(!ob->should_interact(TP)){
       ob->force_me("emote waves you away in refusal");
       ob->force_me("say leave before you tarnish my image.");
       return 1;
    }
    if(!TP->query_funds("gold",ADJUST_COST(cb))) {
	tell_room(TO, name+" seems to be negotiating with "+TPQCN+".", TP);
	tell_room(TO, "%^MAGENTA%^"+name+" says:  %^RESET%^That's not enough money you have there, sorry.");
//        tell_object(TP, "You don't have enough money!");
        return 1;
    }
    TP->set_blind(0);
    TP->set_temporary_blinded(0);
  if (TP->query_blindfolded()) {
     TP->set_blindfolded(0);
     tell_object(TP,name+" removes that silly blindfold for you as well.");
  }
    tell_object(TP,name+" touches your eyes and cures your blindness.");
    tell_room(TO, name+" collects some money and then touches "+TPQCN+"'s eyes, curing the blindness.", TP);
    TP->use_funds("gold", ADJUST_COST(cb));
    return 1;
}

void set_newbie_heal(int x){
   newbie_heal = x;
}

int query_newbie_heal(){
   return newbie_heal;
}
