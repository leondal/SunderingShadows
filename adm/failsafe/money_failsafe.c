//      /std/money.c
//      from the Nigttmare mudlib
//      an inheritable money object, for hard and soft currencies
//      created by Descartes of Borg 24 april 1994

#include "daemons.h"

#define MONEY_TYPES ({ "copper", "silver", "electrum", "gold", "platinum" })

private mapping money;

string *query_currencies();
int query_funds(string type, int amount);

int has_value(){ return money?sizeof(keys(money)):0;}
int query_money(string str) {
    if(!money) money = ([]);
    if(!str || !stringp(str)) return 0;
    return money[str];
}

void add_money(string str, int amount) {
    string logging;

    if(!str || !stringp(str) || !intp(amount)) return;
    if(!money) money = ([]);
     if(amount > 0 && str == "platnium") str = "platinum";
    if(!money[str]) money[str] = amount;
    else money[str] += amount;
    if(money[str] < 1) map_delete(money, str);
    if(wizardp(this_object()) || !this_object()->is_player()) return;
    switch(str) {
        case "platinum": amount *=5; break;
        case "gold": break;
        case "silver": amount /=10; break;
        case "electrum": amount /=50; break;
        case "copper": amount /= 100; break;
        default: return;
    }
    if(amount < 700) return;
    if(!this_player() || this_player() == this_object())
      logging = "euid: "+geteuid(previous_object())+" ("+file_name(previous_object())+")";
    else logging = (string)this_player()->query_name();
    log_file("money", this_object()->query_name()+" received "+
      amount + " gold in "+str+" from "+logging+" at "+ctime(time())+"\n");
    //log_file("money", ctime(time())+"\n");
}

void set_money(string type, int amount) {
    if(this_object()->is_player()) return;
    if(amount < 0) return;
    if(!type || !stringp(type) || !intp(amount)) return;
    if(!money) money = ([]);
    money[type] = amount;
}


string *query_currencies() {
    if(!money) return MONEY_TYPES;
    else return distinct_array(keys(money) + MONEY_TYPES);
}

void use_funds(string type, int amount){
   int i,j,hold, tmp;

   if(amount < 0) amount = -1 * amount;
   if(!query_funds(type,amount)) return;
   if(query_money(type) >= amount){
      add_money(type, -1 * amount);
      return;
   }
   amount -= query_money(type);
   add_money(type, -1 * query_money(type));
   j = sizeof(MONEY_TYPES);
   for(i=0;i<j;i++){
           if(MONEY_TYPES[i] == type)
         continue;

      hold = query_money(MONEY_TYPES[i]) * (int)ECONOMY_D->currency_rate(MONEY_TYPES[i]);
      hold = to_int(hold / (int)ECONOMY_D->currency_rate(type));

      if(hold < amount){
	 amount -= hold;
	 add_money(MONEY_TYPES[i], -1 * query_money(MONEY_TYPES[i]));
	 continue;
      }

      hold = amount * (int)ECONOMY_D->currency_rate(type);

      hold = to_int(ceil(to_float(hold / (int)ECONOMY_D->currency_rate(MONEY_TYPES[i]))));

      if(hold == 0) hold =1;
      add_money(MONEY_TYPES[i], -1 * hold);
      break;
   }
}

// added by *Styx* 1/26/03 for use by comp_vend.c and no doubt other places
int query_gold_equiv() {
   int total, i, j, hold;
//   if(query_money("gold") >= amount) return 1;
   total = query_money("gold");
   j = sizeof(MONEY_TYPES);
   for(i=0;i<j;i++){
      if(MONEY_TYPES[i] == "gold")
         continue;
      hold = query_money(MONEY_TYPES[i]) * (int)ECONOMY_D->currency_rate(MONEY_TYPES[i]);
      total += to_int(hold / (int)ECONOMY_D->currency_rate("gold"));
   }
//   if(total >= amount) return 1;
   return total;
}

int query_funds(string type,int amount){
   int total, i, j, hold;
   if(query_money(type) >= amount) return 1;
   total = query_money(type);
   j = sizeof(MONEY_TYPES);
   for(i=0;i<j;i++){
      if(MONEY_TYPES[i] == type)
         continue;
      hold = query_money(MONEY_TYPES[i]) * (int)ECONOMY_D->currency_rate(MONEY_TYPES[i]);
      total += to_int(hold / (int)ECONOMY_D->currency_rate(type));
   }
   if(total >= amount) return 1;
   return 0;
}
