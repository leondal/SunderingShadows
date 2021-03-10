/**
 * @file
 * @brief a standard object that sells spell components in shops
 */

//      /std/comp_vend.c
//      a standard object that sells spell components in shops
//      created by Melnmarn@ShadowGate
// now generic for all classes, use set_shop_type(mage/psion/bard) to pick component set.
// if no shop type is set, the store will default to mage components. N, 5/14.
#include <std.h>
#include <money.h>
#include <move.h>

#define MAX_COMPONENTS 40
#define COMP_PATH "/d/magic/store_comp"
inherit NPC;

#include <spellcomponents.h>

string *Available, shoptype, *compset = ({});
mapping Amount = ([]), compcosts = ([]);

mixed sort_items(object one, object two);
int get_amount(int price);
void sell_comp(int number, int amount);
void set_shop_type(string str);
string query_shop_type();

void create(){
     ::create();
     compcosts = COMPONENTS1;
}

void init() {
   ::init();
   add_action("__Buy", "buy");
   add_action("__List", "list");
   add_action("__Help", "help");
}

void set_shop_type(string str){
    if(str == "mage") {
      compset += MAGE_COMPONENTS;
      add_dbs(({"alchemist"}));
    }
    if(str == "psion") {
      compset += PSI_COMPONENTS;
    }
}

string query_shop_type() { return shoptype; }

int __Buy(mixed str) {
    object ob, newbag;
    int number, cost;
    string *not_allowed, response;

    if(!sizeof(compset)) {
        compset += MAGE_COMPONENTS;
        add_dbs(({"alchemist"}));
    }
    not_allowed = ({ "bound", "disabled" });
    if(disabled(TP, not_allowed)) return 1;
    if(disabled(TO, not_allowed)){
        write("Do you really expect someone who cannot move to sell you something?");
        return 1;
    }
    response = "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^";
    if(!str) return notify_fail("Syntax: buy <itemname> || <itemnumber>\n");
    if(member_array(str,({"bag","leather bag","components bag"})) != -1){
        if(!TP->query_funds("gold",10)){
            tell_room(ETO, response+"You do not have enough gold for a new components bag.");
            return 1;
        }
        TP->use_funds("gold",10);
        tell_room(ETO, response+"Here is your new components bag.");
        newbag = new("/d/magic/comp_bag");
        if (newbag->move(TP) != MOVE_OK){
            newbag->move(ETP);
            tell_room(ETO, response+"It seems your hands are full.  I'll "+
                      "just put this on the floor for you.");
        }
        return 1;
    }
    if(!sscanf(str,"%d",number)) {
        if(member_array(str,Available) == -1) {
            tell_room(ETO, response+"I do not have any "+str+" available at this time.");
            return 1;
        } else {
            number = member_array(str,Available);
        }
        if(Amount[Available[number]] <= 0) {
            tell_room(ETO, response+"I do not have any "+str+" available at this time.");
            return 1;
        }
    }
    if(number > sizeof(Available) || number < 0 || !sizeof(Available))
        return notify_fail("There is no component number%^BOLD%^ "+number+"\n");
    tell_room(ETO, response+"%^CYAN%^So, you want a little %^BOLD%^"+Available[number]+"%^RESET%^%^CYAN%^, do ya.. ");

    cost = adjust_cost(compcosts[Available[number]]);

   tell_room(ETO, response+"%^CYAN%^Ok, tell me how many %^BOLD%^"+Available[number]+"s%^RESET%^%^CYAN%^ you want at "+"%^YELLOW%^"+cost+"%^RESET%^%^CYAN%^ gold each?");
   input_to("buy_quantity",0,number);
   return 1;
}

buy_quantity(string str, int number){
   int temp,pgold,cost;
   int cost1;
   object ob;
   string response;

    if(!sizeof(compset)) {
      compset += MAGE_COMPONENTS;
      add_dbs(({"alchemist"}));
    }
   if(!str) input_to("buy_quantity");
   if((!sscanf(str,"%d",temp)) || (temp < 1)) {
      write("Sale Cancelled");
      return;
   }
   response = "%^MAGENTA%^"+TOQCN+" says:  %^RESET%^";
   if(temp > 100) {
      tell_room(ETO, response+"%^CYAN%^I am not allowed to make such large sales.");
      return 1;
   }
   if(temp > Amount[Available[number]]) {
      tell_room(ETO, response+"%^CYAN%^I'm sorry, I have only %^YELLOW%^"+Amount[Available[number]]+"%^BOLD%^%^CYAN%^ "+Available[number]+" %^RESET%^%^CYAN%^for sale at this time.");
      temp = Amount[Available[number]];
   }
   cost = adjust_cost(compcosts[Available[number]]);
   cost1 = cost*temp;
   if(!TP->query_funds("gold",cost1)) {
      if(!TP->query_funds("gold", cost))
         tell_room(ETO, response+"%^RED%^You don't have enough money for even one "+Available[number]+"!");
      else
         tell_room(ETO, response+"%^YELLOW%^You can only afford %^RED%^"+(int)TP->query_gold_equiv()/cost+"%^GREEN%^ " +Available[number]+"'s!");
      return;
   }
   TP->use_funds("gold",cost1);
   tell_room(ETO, response+"%^CYAN%^Ok, then, %^YELLOW%^"+temp+" %^CYAN%^"+Available[number]+"s %^RESET%^%^CYAN%^it is!");
   ob = new(COMP_PATH);
   ob->set_name(Available[number]);
   ob->set_id(({Available[number],"component"}));
   ob->set_short(capitalize(Available[number])+" (a spell component)");
   ob->set_long("             %^BOLD%^" + temp + " " +capitalize(Available[number]) + ". \n" + ob->query_long());
   ob->set_comp_quantity(temp);
   sell_comp(number,temp);
   if((int)(ob->move(TP)) != MOVE_OK ) {
      tell_room(ETO, response+"You cannot carry the component, I will drop it on the floor.");
      ob->move(ETP);
   }
}

int __List(string str) {
   string melnmarn, *not_allowed;
   int inc,lines;

    if(!sizeof(compset)) {
      compset += MAGE_COMPONENTS;
      add_dbs(({"alchemist"}));
    }
    not_allowed = ({ "disabled" });
    if(disabled(TP, not_allowed))
	return 1;
   lines = to_int(TP->getenv("LINES"));
   lines -= 2;
   tell_room(ETO, TPQCN+" studies the list of components available.", TP);
   Available = sort_array(Available,"sort_strings",TO);
   melnmarn = "%^BOLD%^%^BLUE%^--=< %^WHITE%^Components %^BLUE%^>=--%^RESET%^\n";
   for(inc = 0; inc < sizeof(Available);inc++) {
      melnmarn += sprintf("%3d: ",inc);
      melnmarn += sprintf("%%^GREEN%%^%-35s %%^YELLOW%%^%5d %%^RESET%%^%%^CYAN%%^gold%%^YELLOW%%^%4d %%^RESET%%^%%^CYAN%%^stored\n",capitalize(Available[inc]),adjust_cost(compcosts[Available[inc]]),Amount[Available[inc]]);
   }
   melnmarn += "     %^CYAN%^Components bag                         %^YELLOW%^10%^RESET%^%^CYAN%^ gold%^RESET%^\n";
   TP->more(explode(melnmarn,"\n"));
   return 1;
}

string sort_strings(string one,string two) {
   return strcmp(one,two);
}

int set_components(int total) {
   int inc,temp, number;

    if(!sizeof(compset)) {
      compset += MAGE_COMPONENTS;
      add_dbs(({"alchemist"}));
    }
   number = total;
   if(!number) return 0;
   if(number < 1) number = 1;
   if(number > MAX_COMPONENTS) number = MAX_COMPONENTS;
   if(number > sizeof(compset)) number = sizeof(compset);
   Available = allocate(number);
   for(inc = 0;inc < number;inc ++) {
      temp = random(sizeof(compset));
      if(member_array(compset[temp],Available) == -1) {
         Available[inc] = compset[temp];
         Amount[compset[temp]] = get_amount(compcosts[Available[inc]]);
      }
      else {
         inc --;
      }
   }
   return 1;
}

string *query_components() {return Available;}

mixed sort_items(object one,object two) {
   return strcmp(one->query_short(),two->query_short());
}

int __Help(string nothing) {
   if(nothing != "shop") return 0;
   tell_room(ETO, TPQCN+" seems to be asking the shopkeeper for help.", TP);
   write(
@MELNMARN
%^CYAN%^COMPONENT SHOP%^RESET%^

Here you can buy some components for your spellcasting needs. The syntax is as follows:

%^ORANGE%^<list comp>%^RESET%^
  List available components.

%^ORANGE%^<buy %^ORANGE%^%^ULINE%^NAME%^RESET%^%^ORANGE%^>%^RESET%^
  Buy component. You will be prompted for quantity.

%^ORANGE%^<buy components bag>%^RESET%^
  Buy empty components bag.

%^ORANGE%^<help shop>%^RESET%^
  Display this screen.
MELNMARN
        );
   return 1;
}

int get_amount(int price) {
   return 1+random(100);
}

void sell_comp(int number, int amount) {
   Amount[Available[number]] = Amount[Available[number]] - amount;
   if(Amount[Available[number]] == 0) {
      map_delete(Amount,Available[number]);
      Available -= ({Available[number]});
   }
}
