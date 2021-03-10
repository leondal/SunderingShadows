//  standard vendor

//  Purpose:  To allow for items to be bought and sold for less than
//            one gold piece.

#include <std.h>
#define TP  this_player()

inherit MONSTER;

private mapping __store;
string *languages;

void set_storage(string str);
int haggle_cost(int price,int skill);
void set_languages(string *str);
varargs void speak(string str,object who);
void set_shop_type(string str);
void query_storage();
object query_storage_room();
void emote(string str);
string query_shop_type();
int ok_type(object ob);
void sell_all(object pc);

void create()   {
  ::create();
  __store = ([  ]);
  enable_commands();
}

void init()    {
  ::init();
  add_action("__sell","sell");
  add_action("__buy","buy");
  add_action("__list","list");
  add_action("__value","value");
}

// *** add_actions() *** //

int __list(string str)    {
  object *inv;
  int i;
  
  inv = all_inventory(query_storage_room());
  if(str) inv = filter_array(inv,"filter_stuff",this_object(),str);
  if(sizeof(inv) == 0)    {
    speak("Sorry, I don't have anything like that to sell.",TP);
    return 1;
  }
  message("store",
  arrange_string("Item:",50)+arrange_string("Cost:",10)+
  "---------------------------------------------------------------------",TP);
  for(i=0;i<sizeof(inv);i++) 
    message("info",arrange_string(inv[i]->query_short(),50)+"%^RESET%^"+
            inv[i]->query_value()+" "+inv[i]->query_coin_type(),TP);
  message("store",
  "---------------------------------------------------------------------",TP);
  return 1;
}

int __buy(string str)    {
  object ob;
  int value, price;
  string coin;
  
  if(!str)    {
    speak("What did you want to buy?",TP);
    return 1;
  }
  if(!(ob = present(str,query_storage_room())))   {
    speak("Sorry, I don't have that for sale.",TP);
    return 1;
  }
  value = ob->query_value();
  price = haggle_cost(value,(int)TP->query_skill("bargaining"));
  if(!(coin = ob->query("coin_type"))) coin = "gold";
  if((int)TP->query_money(coin) < price)   {
    speak("Sorry, come back when you have more money.",TP);
    return 1;
  }
  speak("Great!  That will be "+price+" "+coin+"!",TP);
  TP->add_money(coin,-price);
  ob->move(TP);
  emote("smiles at "+TP->query_cap_name());
  return 1;
}
  
int __sell(string str)    {
  string lang, obj, coin;
  object thing;
  int value, payment;
  if(!str)    {
    speak("Sell what?",TP);
    return 1;
  }
  say(TP->query_cap_name()+" tries to sell something to "+query_short()+".");
  if(str != "all")    {
    if(!present(str,TP))    {
      speak("You don't have that to sell, "+TP->query_cap_name()+"!",TP);
      return 1;
    }
    thing = present(str,this_player());
    if(!ok_type(thing))    {
      speak("Sorry, "+TP->query_cap_name()+", I don't buy that sort of stuff.",TP);
      emote("shrugs");
      return 1;
    }
    if(!(value = thing->query_value()))    {
      speak("That isn't worth anything ",TP->query_cap_name()+"!",TP);
      return 1;
    }
    coin = thing->query("coin_type");
    if(!coin) coin = "gold";
    if(value > 2000)    {
      speak("I don't carry that much coin on me, sorry.",TP);
      payment = 1000 + random(750);
    }
    speak("Your total comes to "+value+" "+coin+" coins.",TP);
    speak("Thanks for your patronage, "+TP->query_cap_name(),TP);
    emote("gives some money to "+TP->query_cap_name()+".");
    thing->move(query_storage_room());
    TP->add_money(coin,value);
    return 1;
  }
  sell_all(TP);
  return 1;
}  

void sell_all(object pc)    {
  int i, value;
  string str, *money, coin, temp;
  mapping __totals;
  object *inv;
  
  inv = all_inventory(pc);
  __totals = ([  ]);
  for(i=0;i<sizeof(inv);i++)    {
    if(!(value = inv[i]->query_value())) continue;
    if(!ok_type(inv[i])) continue;
    if(value>2000) value -= random(1000);
    if(!(coin = (int)inv[i]->query("coin_type"))) coin = "gold";
    if(!__totals[coin])  __totals[coin] = value;
      else __totals[coin] += value;
    inv[i]->move(query_storage_room());
  }
  if(sizeof(keys(__totals)) >= 1)   {
    money = keys(__totals);
    temp =(__totals[money[0]]+" "+money[0]);
    pc->add_money(money[0],__totals[money[0]]);
    for(i=1;i<sizeof(money);i++)   {
      temp += ", "+__totals[money[i]]+" "+money[i];
      pc->add_money(money[i],__totals[money[i]]);
    }
    speak("You total comes to "+temp,pc);
    emote("thanks you.");
    return;
  } 
  speak("You have nothing I can buy, "+pc->query_cap_name(),pc);
  say(temp);
  emote("shrugs.");
}  
     
// *** set_ type stuff *** //

void set_storage(string str)    {
  __store["storage"] = str;
}

object query_storage_room()    {
  return find_object_or_load(query_storage());
}

string query_storage()   {   return __store["storage"];   }  
      
void set_shop_type(string str)   {   __store["type"] = str;    }

string query_shop_type()    {
  if(!__store["type"]) return "general store";
    else return __store["type"];
}

int ok_type(object ob)    {
  switch(query_shop_type())    {
    case "weapon": case "weapons": 
      return (int)ob->is_weapon();
      break;
    case "armour": case "armor": case "armoury":
      return (int)ob->is_armour();
      break;
    case "food shop": case "resteraunt": case "deli": case "pub":
    case "grocery store":
      if(!ob->is_food() && !ob->is_drink()) return 0;
        else return 1;
      break;
    default: return 1;
  }
}

// *** Language / Skill Stuff *** //

string *query_known_languages()    {
  if(!__store["language"])  return ({ "common" });
  else return __store["languages"];
}  

varargs void speak(string str,object who)    {
  string lang, tongue, *languages;
  lang = (string)who->query_primary_lang();
  languages = query_known_languages();
  if(member_array(lang,languages) == -1)
    tongue = "common";
      else tongue = lang;
  this_object()->force_me(("speak in "+tongue+" "+str));
}

void set_languages(string *str)    {  
  int i;
  for(i=0;i<sizeof(str);i++) this_object()->set_lang_prof(str[i],10);
  __store["languages"] = str;  }

void emote(string str)    {
      tell_room(environment(this_object()),
    capitalize((string)this_object()->query_short())+" "+str);
}

int haggle_cost(int price,int skill)    {
      int my_skill,diff;
  my_skill = this_object()->query_skill("bargaining");
    if(!my_skill) my_skill = 20;
  if(price < 50) return price;
  if(skill > my_skill) return (price - 5);
  if(skill = 0) return (price*4);
  diff = to_int( percent(skill,my_skill) );
  if(diff > 90) return (price+to_int((price/100)*10));
   else if(diff > 80) return (price+to_int((price/100)*20));
    else if(diff > 70) return (price+to_int((price/100)*30));
     else if(diff > 60) return (price+to_int((price/100)*40));
      else if(diff > 50) return (price+to_int((price/100)*50));
       else if(diff > 40) return (price+to_int((price/100)*65));
        else if(diff > 30) return to_int(price+to_int((price/100)*75));
         else if(diff > 20) return (price+price);
          else if(diff > 10) return (price+to_int((price/100)*150));
           else return (price+price+price);
}

int filter_stuff(object stuff,string str)    {
      if(living(stuff)) return 0;
  switch(str)    {
        case "weapon": case "weapons":
      return (int)stuff->is_weapon();
      break;
    case "food": case "foods":
      return (int)stuff->is_food();
      break;
    case "armour": case "armours": case "armor": case "armors":
      return (int)stuff->is_armour();
      break;
    case "drink": case "drinks":
      return (int)stuff->is_drink();
      break;
    default: return (int)stuff->id(str);
}
}
