// /std/temple.c
// added to make ckpts in player notes on join/dedicate (knights) and forsake
// *Styx*  4/22/02
// Donation boxes added by Styx
// Uses add_actions for donate/check_funds/withdraw/look_box 6/2002
// Added random actions into reset - 10/25/03, last change 5/03, *Styx*
// Made donating items populate the search treasure -Ares 5/3/06
// Added the restrictions for ranger deities. Nienne, 02/07
// Lowered paladin/antipaladin charisma requirement to 15, from 17. Nienne, 07/07
// Added <reequip> command to gain basic gear by level. Nienne, 08/07
// additions for the temple ward effect. Nienne, 01/09.

#include <std.h>
#include <move.h>
#include <daemons.h>
#include <objects.h>
#include <dieties.h>
#define DIETY_D "/daemon/diety_d.c"
#define FORSAKE_DELAY 86400
#define FUNDS "/daemon/templefunds_d.c"
inherit "/std/church";

string diety;

void init() {
    ::init();
    add_action("select_diety","choose");
    add_action("leave_diety","forsake");
    add_action("get_water","bw");
    add_action("new_symbol","new");
    add_action("donate", "donate");
    add_action("check_funds", "check");
    add_action("withdraw", "withdraw");
    add_action("look_box", "look");
    add_action("soulbind", "soulbind");
    if(!present("templewardxxx",TP)) new("/d/magic/obj/templeward")->move(TP);
}

void create() {
    ::create();
}

void reset() {  // this section added 10/25/03 by *Styx*
   ::reset();
   switch(random(20)) {
	case 0..10:  break;
	case 11:  if(!diety)  break;
	   tell_room(TO, "%^BLUE%^A small group of humans nod in greeting as they enter.\n  They proceed to the altar and make numerous offerings to "+capitalize(diety)+".");
	   break;
	case 12:
	   tell_room(TO, "%^BOLD%^%^CYAN%^The temple acolytes turn their attention to carefully cleaning and polishing the altar.");
	   break;
	case 13:
	   tell_room(TO, "%^ORANGE%^An elderly priest wanders in and begins to meditate at the altar.");
	   break;
	case 14:
	   tell_room(TO, "%^YELLOW%^You hear the acolytes begin chanting daily prayers at the altar.");
	   break;
	case 15:
	   tell_room(TO, "%^ORANGE%^Some local peasants enter and nod to you, then kneel at the altar and humbly pray before making their meager offerings and donations.");
	   break;
	case 16:
	   tell_room(TO, "A lone stranger enters and converses quietly with an acolyte, watching you thoughtfully before quietly slipping back out.");
	   break;
	case 17:
	   if(!diety)  break;
	   tell_room(TO, "%^RED%^You hear murmurs from the back of the temple as some visitors pray for "+capitalize(diety)+"'s favour.");
	   break;
	case 18:
	   tell_room(TO, "%^BOLD%^BLUE%^Vestments and robes rustle as acolytes and clerics attend to various duties around you.");
	   break;
	case 19:
	   tell_room(TO, "%^GREEN%^A pair of acolytes nod to you respectfully and then slip out of the room quietly.");
	   break;
        default:  break;
   }
}

void set_temple(string str) {
    diety = str;
    set_property("blessed",({diety}));
}

string query_diety() {
    return diety;
}

int can_request() {
    if(query_diety() == (string)TP->query_diety()) {
        return ::can_request();
    }
    return 0;
}

int select_diety(string str) {
    string old;
    object symbol;
    int align;

    if(!str) return notify_fail("Try choose <DEITY NAME>.");
    str = lower_case(str);
    if(str != diety) return notify_fail("You can only choose to follow "+capitalize(diety)+" while in here.\n");
    if(TP->query_property("dominated")) return notify_fail("The god senses your true feelings and does not accept you as a follower.\n");
//    align = TP->query_alignment();
    align = TP->query_true_align();
// no longer required, all lawful new gods run by clergy limitations.
/*    if(TP->is_class("cavalier") || TP->is_class("paladin")) {
        if(member_array(str, KNIGHTS) == -1) {
            tell_object(TP, "A knight may not worship "+capitalize(str)+".");
            return 1;
        }
    } */
    if((int)TP->query("last forsake") + FORSAKE_DELAY > time() && !avatarp(TP)) {
        tell_object(TP,"You must ponder your recent decision to forsake a god longer.");
        return 1;
    }

    if (!DIETY_D->allowed_follow((string)TP->query_name(), str)) {
        tell_object(TP,capitalize(str)+ "will not have you as a follower. You must prove your faith.");
        return 1;
    }
    if(member_array(align,DIETIES[str][1]) == -1) {
        tell_object(TP,capitalize(str)+" does not allow followers of your alignment.");
        return 1;
    }
    if(TP->is_class("paladin") || TP->is_class("cavalier") || TP->is_class("cleric") || TP->is_class("monk")) { // clergy/orders
        if(member_array(align,DIETIES[str][2]) == -1) {
            tell_object(TP,capitalize(str)+" does not allow clergy of your alignment.");
            return 1;
        }
    }

    old = TP->query_diety();
    symbol = present("holy symbol",TP);
    if(old && old != "pan" && old != "godless") {
        tell_object(TP,"You have already chosen to follow "+capitalize(old)+"!");
        return 1;
    }
    tell_object(TP,"%^BOLD%^You have decided to follow "+capitalize(str)+"!");
    TP->set_diety(str);
//    TP->set_sphere(DIETIES[str][0]);
    TP->forget_all_cl_spells();
    if(objectp(symbol)) symbol->remove();
    TP->set("god changed",1);
    TP->update_channels();
    if(!avatarp(TP))
        ADVANCE_D->diety_news(diety,TPQCN+" has chosen to follow "+capitalize(diety)+"!");
    log_file("player/god_change", capitalize(TP->query_name())+" joined "+capitalize(diety)+": "+ctime(time())+"\n");
//added by Styx 4/21/02
    "/cmds/avatar/_note.c"->cmd_note("ckpt "+TPQN+" %^BOLD%^%^CYAN%^chose to follow "+capitalize(diety)+".");
    return 1;
}

int leave_diety(string str) {
    string old, myclass;
    object symbol;
    int align,i,hp_loss;
    string curclass,*classes;

    if(!str) return notify_fail("Try forsake <name>.");

    if(TP->query_property("dominated")) return notify_fail("You are dominated, the god knows your heart well enough to see the magic.\n");
    str = lower_case(str);
    if(str!=diety) return notify_fail("You cannot leave "+capitalize(str)+"'s service here!");
    old = (string)TP->query_diety();
    if(old!=diety) return notify_fail("You are not a follower of "+capitalize(diety)+"!");
    if((int)TP->query_lowest_level() < 10) return notify_fail("You have not been one of the faithful long enough to forsake your deity.");
    symbol = present("holy symbol",TP);
    if(!avatarp(TP))
        ADVANCE_D->deity_news(diety,TPQCN+" has forsaken "+capitalize(diety)+" as "+TP->query_possessive()+" deity!");
    log_file("player/god_change", capitalize(TP->query_name())+" left "+capitalize(diety)+": "+ctime(time())+"\n");
//added by Styx 4/21/02
    "/cmds/avatar/_note.c"->cmd_note("ckpt "+TPQN+" %^BOLD%^%^CYAN%^chose to forsake "+capitalize(diety)+".");
    tell_object(TP,""+capitalize(diety)+" will no longer have you as a follower!");
    tell_object(TP,"A bolt of energy streaks toward you from above, exacting "+capitalize(diety)+"'s revenge.");
    tell_object(TP,"Once you have reflected on this adequately, you may seek out a temple and choose another deity to follow.");
    TP->set_diety(0);
//    TP->set_sphere(0);
    TP->set_divine_domain(({}));
    TP->set("last forsake",time());
    TP->forget_all_spells();

    if(objectp(symbol)) symbol->remove();
    TP->update_channels();
    if(avatarp(TP)) return 1;
//    TP->add_exp(-((int)TP->query_exp()*1/7));
    if((int)"/daemon/config_d.c"->check_config("character improvement") == 0)
    {
        TP->general_exp_adjust_perc(-15);
        TP->resetLevelForExp(0);
    }
    else if((int)"/daemon/config_d.c"->check_config("character improvement") == 1) TP->set_XP_tax((((int)TP->query_exp()/100) * 15), 0, "improvement");

    TP->setenv("TITLE", (string)ADVANCE_D->get_new_title(TP));
    return 1;
}

int get_water(string str) {
    int num;
    int cost;
    object ob;

    if(!str) return notify_fail("Try bw #.");
    if(!sscanf(str,"%d",num)) return notify_fail("Try bw #.");
    if((string)TP->query_diety()!=diety) return notify_fail("You have no use for holy water of "+capitalize(diety)+"!");
    if(num > 200) num = 200;
    if(num < 0) return notify_fail("We'll take your money but we won't give it to you.\n");
    if(num == 0) return notify_fail("What are you going to do with 0 vials of holy water?\n");
    cost = num * 1;
    if(!TP->query_funds("gold",cost)) return notify_fail("You don't have enough money for "+num+" vials of holy water.");
    TP->use_funds("gold",cost);
    ob = new("/d/magic/obj/holy_water.c");
    ob->set_uses(num);
    ob->set_god(diety);
    tell_object(TP,"You take a kit of holy water.");
    if(ob->move(TP) != MOVE_OK) {
      ob->move(TO);
      tell_object(TP,"You drop the kit of holy water on the ground!");
}
    return 1;
}

int new_symbol(string str) {
    string god;
    object ob, symbol;

    if(!TP->query_diety())
        return notify_fail("You don't follow a god, you don't need a symbol.");
    if(!str) return notify_fail("New what?\n");
    if(str != "symbol" && str != "holy symbol")
        return notify_fail("You can't get a new "+str+" here!\n");
    if((string)TP->query_diety() != diety)
        return notify_fail("You are not a follower of "+capitalize(diety)+", whose temple you are in!\n");
    if(!ob = present("holy symbol",TP))
        return notify_fail("You need to have a regular holy symbol first.\n");
    if(ob->id(diety+"_holy_symbol"))
        return notify_fail("You already have one of "+capitalize(diety)+"'s holy symbols.\n");
    symbol = new("/d/magic/symbols/"+diety+"_symbol.c");
    if(!objectp(symbol))
        return notify_fail("Your deity has no fancy symbol yet. Perhaps you could try to <request> a common one meanwhile.\n");
    ob->remove();
    symbol->move(TP);
    symbol->set_owner();
    tell_object(TP,"%^BOLD%^"+capitalize(diety)+" has gifted you with a new holy symbol!");
    return 1;
}

// Donation-related functions added by Styx - 6/2002

// checking individual donations added 5/3/03 by *Styx*
int check_donations(object who, string str) {
   int i, j;
   string name, *temples, which;
   mapping donations;
   if(!str)
	return notify_fail("check what?");
   if(sscanf(str, "donations by %s", name) != 1) {
	tell_object(who, "Syntax is <check donations by [name]>");
	return 1;
   }
   donations = FUNDS->query_donations(name);
   temples = keys(donations);
   j = sizeof(temples);
   tell_object(who, capitalize(name)+" has made the following donations to temples:\n");
   for(i=0;i < j;i++) {
      which = temples[i];
      if(!which)  continue;
// improvement to formatting while I'm in here *Styx* 10/3/05
      write(sprintf("%%^RED%%^%-12s %%^YELLOW%%^%10d", capitalize(which), donations[which]) + " gold");
//      tell_object(who, capitalize(which)+":  %^YELLOW%^\t"+donations[which]+" gold.");
   }
   return 1;
}

int check_funds(string str) {
   int bal, donations;
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!str)   // bug fix by *Styx* 10/3/05
	return notify_fail("check what?\n");
   if(strsrch(str, "donations") != -1){
      if(!avatarp(TP)) {
/*         tell_object(TP,"Try <check balance> or <check withdrawals>.");
*         return 1;
*  and also to avoid conflicts with lanterns 10/3/05
*/
	return notify_fail("Did you want to <check balance> or <check withdrawals> or something else?\n");
      }
//added return 0 for !avatarp to avoid bug some HMs were getting.  Circe 2/20/04
	check_donations(TP, str);
	return 1;
   }
/* added here to return 0 if not checking the right things so it won't interfere
* with lanterns, etc. *Styx*  11/26/03, last change 10/26/03
*   if(str != "balance" && str != "withdrawals")
*	return 0;
* now that I know more about notify_fail, changing the below should work *Styx* 10/3/05
*/
//   if((high_mortalp(TP) && (string)TP->query_diety() == diety) || avatarp(TP)) {
// adjusting to allow HM accounts to check balance ~Circe~ 4/9/13
     //if((OB_ACCOUNT->is_high_mortal((string)TP->query_true_name()) && (string)TP->query_diety() == diety) ||avatarp(TP))
     if(TP->query_diety() == diety || avatarp(TP))
     {
// /* don't need this now (didn't, but changing it back now - *Styx* 10/3/05)
      if(str != "balance" && str != "withdrawals")
      {
        return notify_fail("Did you want to <check balance> or <check withdrawals> or something else?\n");
//        return 0;
      }
      switch(str) {
        case "balance" :
          bal = (int)FUNDS->query_temple_account(base_name(TO));
          tell_object(TP,"Checking the donation box, you find that this temple "
            "has a balance of %^YELLOW%^"+bal+" gold %^RESET%^from donations.");
          break;
        case "withdrawals" :
          bal = (int)FUNDS->query_temple_withdrawals(base_name(TO));
          tell_object(TP,"Checking the donation box, you find records of "
            "withdrawals totaling %^YELLOW%^"+bal+" gold%^RESET%^.");
          break;
      }
      tell_room(ETP,TPQCN+" reads a note attached to the donation box.", TP);
      return 1;
   }
// this probably won't get used now, but leaving it just in case *Styx*  11/26/03
   tell_object(TP,"A magical force prevents you from checking the temple "
         "funds.");
   return 1;
}

int withdraw(string str) {
   int amount;
   if(!avatarp(TP))  return 0;
   if(!str) {
      notify_fail("Correct syntax: <withdraw [amount] >\n");
      return 0;
   }
   if(sscanf(str, "%d", amount) != 1) {
      notify_fail("Correct syntax: <withdraw [amount] >\n");
      return 0;
   }
   FUNDS->withdraw_funds(base_name(TO), amount, TP);
   return 1;
}

int donate(string str) {
   string type;
   int x, amount, amt2;
   object what;
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!str) {
      notify_fail("Correct syntax: <donate [amount] [type]> or <donate [item]>\n");
      return 0;
   }
    if(TP->query_property("dominated"))
	return notify_fail("The god senses your true feelings and does not accept your donation.\n");
// added to allow donation of items per Vivian's suggestions *Styx*  2/18/03
   if(what = present(str, TP)) {
      amount = (int)what->query_value();
      type = what->query_cointype();
      if(!amount || !type) {
         write("That "+str+" is apparently worthless.");
         return 1;
      }
      if(what->query_worn()) {
        write("Please remove that before donating it.");
        return 1;
      }
      if(what->query_wielded()) {
        write("Please unwield that before donating it.");
        return 1;
      }
      if(what->query_property("plot_item") || what->query_property("soulbound")) {
        write("The temple doesn't want that item.");
        return 1;
      }
      tell_room(TO, TPQCN+" donates "+(string)what->query_short()+" to the temple.",TP);
      tell_object(TP, "You donate "+(string)what->query_short()+" to the temple.");
      tell_room(TO, "An acolyte accepts the donation, makes a careful note in the tithe book, and stores the item away carefully.");
      "/daemon/search_d.c"->add_object(what); // Added to allow donations to populate search treasures - Ares
      what->remove();
      if(what)   destruct(what);
      FUNDS->add_temple_gold(base_name(TO), amount, type, TP, diety, 1);
      return 1;
   }
   if(sscanf(str, "%d %s", amount, type) != 2) {
      notify_fail("Please try either <donate [amount] [type]> or <donate [item]>\n");
      return 0;
   }
   if((int)TP->query_money(type) < amount) {
      notify_fail("You check your pockets and realize you do not have that "
	"many "+type+"!\n");
      return 0;
   }
   if(amount < 0) {
      notify_fail("No, you can't do that and yes, we're watching!\n");
      return 0;
   }

   FUNDS->add_temple_gold(base_name(TO), amount, type, TP, diety);
   tell_object(TP,"You slip the "+amount+" "+type+" coins into the donation box.");
   switch(amount + random(50)) {
      case 0..30 :   tell_room(ETP,TPQCN+" drops a few "+type+" coins into "
                       "the donation box.",TP);
                     break;
      case 31..100 : tell_room(ETP,TPQCN+" donates a handful of "+type+" coins "
                        "to the donation box.",TP);
                     break;
      case 101..475: tell_room(ETP,TPQCN+" slips a few handfuls of "+type+
                       " coins into the donation box.",TP);
                     break;
      case 476..1475: tell_room(ETP,TPQCN+" donates several handfuls of "+type+
                       " coins to the donation box.",TP);
                     break;
      case 1476..4975 : tell_room(ETP,TPQCN+" empties a pouch of "+type+
                       " coins into the donation box.",TP);
                      break;
      case 4976..14050 : tell_room(ETP,TPQCN+" empties a %^YELLOW%^small sackful"
                       "%^RESET%^ of "+type+" coins into the donation box.",TP);
                      break;
      case 14051..50000 : tell_room(ETP,TPQCN+" empties a %^BOLD%^large sack"
                       "%^RESET%^ of "+type+" coins into the donation box.",TP);
                      break;
      default : tell_room(ETP,TPQCN+" donates some "+type+
                       " coins to the temple's donation box.",TP);
                      break;
   }
   return 1;
}

int look_box(string str) {
   if(!str || (str != "donations box" && str != "donation box"))   return 0;
   if(avatarp(TP)) {
      tell_object(TP,"You (avatar/wiz) have the ability to <check "
         "balance|withdrawals>, <withdraw [amount]>, or to "
	 "<check donations by [name]>.  High mortal "
         "followers will see that they can <check balance|withdrawals>.\n");
   }
   if(wizardp(TP))
       tell_object(TP,"FYI (wiz eyes only) - All is logged to /log/tithes.\n");
   if((string)TP->query_diety() == diety)  {
      tell_object(TP,"Due to your status in the church, you are allowed the "
         "privelege to <check balance> or <check withdrawals> of funds.\n");
   }
   tell_object(TP,"There is a slot in the top of the box to allow you to "
         "%^BOLD%^<donate> %^RESET%^money or items to this temple.");
   return 0;
// Yes, I mean to return 0 so it will still go to normal look and let them see
// the description of the box set by the room too.  *Styx*
}

int is_temple() {
    return 1;
}

void trigger_ward()
{
    	object *combatants, destroom, MyWard;
    	int i, flag, MyFlag;
    	combatants = all_living(TO);

    	for(i = 0;i< sizeof(combatants); i++)
    	{
        	if(!objectp(combatants[i])) { continue; }
		//adding this because I'm guessing it bugs whenever
		//someone summons fodder to a battle in a temple, since
		//they wont get a temple ward object - (it removes it
		//on heartbeat - in /d/magic/obj/templeward.c) - if
		//it's not a user that it's adding it to - Saide
     	  	MyWard = present("templewardxxx", combatants[i]);
		MyFlag = 0;
	  	if(objectp(MyWard))
	  	{
			MyFlag = (int)MyWard->is_combatant();
		}
        	if(sizeof(combatants[i]->query_attackers()) || MyFlag)
        	{
            	if(!flag)
            	{
                		destroom = new("/d/magic/room/templeward");
                		flag = 1;
            	}
            	tell_object(combatants[i],"%^BOLD%^%^CYAN%^A s%^WHITE%^p%^CYAN%^ar"
                	"%^BLUE%^k%^CYAN%^ling orb of azure energy springs into being around you, and "
                	"the temple disappears from view!%^RESET%^");
                	combatants[i]->move(destroom);
        	}
    	}

    	if(flag)
    	{
      	tell_room(TO,"%^BOLD%^%^CYAN%^A s%^WHITE%^p%^CYAN%^ar%^BLUE%^k"
            "%^CYAN%^ling orb of azure energy springs into being around the combatants, and "
            "they disappear from view!%^RESET%^");
    	}
}

int confirm_soulbind(string str,object bob,object bindob,int cost,object unbindob) {
    object *contents=({});
    if(!objectp(bob)) { return 0; }
    if(!objectp(bindob)) { return 0; }
    if(!objectp(unbindob)) { return 0; }
    if(!intp(cost)) { return 0; }

    if(str != "yes") {
        tell_object(bob,"%^BOLD%^%^WHITE%^You think better of it, and thank the priest for their time.");
        return 0;
    }
    if(!(int)bob->query_funds("gold",cost)) {
        tell_object(bob,"%^BOLD%^%^WHITE%^The priest shakes his head, you don't have enough money for that.");
        return 0;
    }
    bob->use_funds("gold",cost);
    tell_room(TO,"%^BOLD%^%^WHITE%^An acolyte accepts a donation from "+bob->QCN+".",bob);
    tell_object(bob,"%^BOLD%^%^WHITE%^An acolyte accepts your offering for the spell.");
    tell_room(TO,"%^YELLOW%^The priest speaks blessings over the "+bindob->query_name()+", concentration apparent on their face. Moments pass, before finally the binding is done.");
    unbindob->remove_property("soulbound");
    if(unbindob->is_sheath()) {
      contents = all_inventory(unbindob);
      if(sizeof(contents)) contents[0]->remove_property("soulbound");
    }
    bindob->set_property("soulbound",1);
    return 1;
}

int soulbind(string str) {
   object bindob,unbindob,*myinven=({}),invisobj;
   int i,findbind=0,cost;
   if(!str) return 0;
   if(!bindob = present(str, TP)) return notify_fail("The "+str+" must be in your possession.\n");
   if(TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
     TP->send_paralyzed_message("info",TP);
     return 1;
   }
   if(TP->query_hidden()) {
     if(objectp(invisobj=present("TSR80",TP)))
     invisobj->force_cancel();
   }
   if (TP->query_magic_hidden()) return notify_fail("Noone can see you to bless the item!\n");
   if((string)TP->query_diety() != diety) return notify_fail("You could only hope for such a powerful blessing from your own temple.\n");
   if(!bindob->is_armor() && !bindob->is_weapon()) return notify_fail("You can only bind an item of equipment with such a blessing.\n");
   if(bindob->query_property("soulbound")) return notify_fail("That item is already bound to you!\n");

   myinven = all_inventory(TP);
   if(sizeof(myinven)) {
     for(i=0;i<sizeof(myinven);i++) {
       if(myinven[i]->query_property("soulbound")) {
         unbindob = myinven[i];
         findbind++;
       }
     }
   }
   if(!findbind) unbindob = bindob;
   if(findbind>1) return notify_fail("You have more than one soulbound item already (or are bugged!); please contact a wiz to resolve before you can bind anything further!\n");
   cost = ((int)TP->query_exp() /5) / (int)TP->query_level(); // exponential; benchmarks: circa 10k for L10; 100k for L20; 200k for L30; 500k for L40.

   tell_object(TP,"%^YELLOW%^You approach one of the higher priests of the temple. They inform you that it will cost %^MAGENTA%^"+cost+" gold %^YELLOW%^to place such a powerful blessing on the "+bindob->query_name()+".");
   if(findbind) tell_object(TP,"%^YELLOW%^They also warn you that it will negate the blessing on the soulbound item you already carry.");
   tell_room(TO,"%^YELLOW%^"+TP->QCN+" approaches one of the priests of the temple, and they confer for a moment.",TP);
   tell_object(TP,"%^YELLOW%^Do you wish to continue? Enter %^WHITE%^<yes> %^YELLOW%^to confirm, or anything else to abort.");
   input_to("confirm_soulbind",TP,bindob,cost,unbindob);
   return 1;
}
