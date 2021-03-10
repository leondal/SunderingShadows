//  Kriton's Standard Shop 
//  created May 11, 1994
//  For use on OrionII

#include <std.h>
#define TP	this_player()
#define SK	capitalize(shopkeep)
inherit ROOM ;

string *files, *names;
string currency, shopkeep, thankyou;
int *cost;

void set_currency(string curtype);
void set_inventory(string *xfiles,int *xcost,string *xnames);
void set_vendor_name(string who);
void set_thank_you(string thanks);

void init()    {
  ::init();
  add_action("list_items","list");
  add_action("purchace","buy");
  add_action("help","help");
}

void create()    {
  ::create();
  files=({});
  cost=({});
  names=({});
}

void set_thank_you(string thanks)    {
  thankyou = thanks;
}

void set_currency(string curtype)    {
  currency = curtype;
}

void set_inventory(string *xfiles,int *xcost,string *xnames)    {
  cost = xcost;
  files = xfiles;
  names = xnames;
}

void set_vendor_name(string who)    {
  shopkeep = who;
}

int help(string str)    {
  if(!str || str != "shop") return 0;
  write(
@TEXT

Commands for the store:
  <list>	:	List of items that can be bought here.
  <buy [item]>	:	Buy the item specified.
  <help shop>	:	(This screen)

Items are purchaced by number, not name.
Mail any problems, suggestions or comments to Kriton (@orion.ii)
TEXT
  );
  return 1;
}

int list_items()    {
  int count;
  if(sizeof(names)==0)    {
    write("This shop doesn't appear to be selling anything!");
    return 1;
  }
  write("\n");
    write("Items for sale at this shop are:\n"+
  "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  for(count=0;count<sizeof(names);count++)    {
    write(
    (count+1) + ") "+
    arrange_string(names[count],40) +
    arrange_string(cost[count],10) + currency + " coins");
  }
  write("\n");
  write("Type: help shop for a list of commands.");
  return 1;
}

void do_thanks()    {
  if(!thankyou) thankyou="Thank you for shopping here... come again!";
  write("%^RED%^BOLD%^"+SK+" tells you:%^RESET%^ "+thankyou);
}

int purchace(string x)    {
  object ob;
  int money, what;
  if(!present(shopkeep))    {
    write("Who did you expect to buy that from?");
    return 1;
  }
  if(sscanf(x,"%d",what) != 1)    {
    write("Please purchace by number.");
    return 1;
  }
  sscanf(x,"%d",what);
  what = what - 1;
  if(what<0 || what>sizeof(names))   {
    write("This shop does not offer that!");
    return 1;
  }
  if(!currency) currency = "gold";
  money = (int)TP->query_money(currency);
  if(cost[what]>money)    {
    write("You cannot afford that!");
    return 1;
  }
  ob = new(files[what]);
  write("You buy a "+names[what]+" from "+SK+".");
  say(TP->query_cap_name()+" buys something from "+SK+".");
  ob->move(TP);
  TP->add_money(currency,(cost[what]*-1));
  call_out("do_thanks",2);
  return 1;
}

string *query_inventory()    {
  return names;
}

string *query_files()    {
  return files;
}
