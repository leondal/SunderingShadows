// /std/bank.c 
// <<==-- Coded By Fire Dragon --==>>
// Adjusted by Thorn 970209

#include <std.h>
#include <daemons.h>
#include <money.h>
#include <bank.h>

#define BANK_ID "praxis"

inherit VAULT;

void create() 
{
  ::create();
  set_property("magic hold", 50);
  set_property("no castle", 1);
  set_property("light", 2);
  set_property("night light", 2);
  set_property("indoors", 1);
  set_short("A Bank");
  set_long("%^BOLD%^A Town Bank%^RESET%^\n");
  set_smell("default","The smell of money fills your nostrils.");
  set_listen("default","The sounds of rustling coins fill your ears.");
}

void init() 
{
  ::init();
  add_action("read", "read");
  add_action("open", "open");
  add_action("close", "close");
  add_action("deposit", "deposit");
  add_action("withdraw", "withdraw");
  add_action("balance", "balance");
  add_action("exchange", "exchange");
}

int exchange(string str) 
{
  string from, to;
  float val;
  int amount;

  if(!str) 
   {
     notify_fail("Correct syntax: <exchange # type for type>\n"+
                 "ex: <exchange 100 gold for copper>\n");
     return 0;
   }

  if(sscanf(str, "%d %s for %s", amount, from, to) !=3) 
   {
     notify_fail("Correct syntax: <exchange # type for type\nex: "
	         "<exchange 100 gold for copper>\n");
     return 0;
   }

  if(amount < 1) 
   {
     notify_fail("That would be a nifty trick indeed!\n");
     return 0;
   }

  if((int)this_player()->query_money(from) < amount) 
   {
     notify_fail("You do not have that much of that currency.\n");
     return 0;
   }

  if( member_array( from, MONEY_TYPES ) == -1 )
   {
     write("The bank does not support "+from+".\n");
     return 0;
   }

  if( member_array( to, MONEY_TYPES ) == -1)
   {
     write("The bank does not support "+to+".\n");
     return 0;
   }

  val = amount * (int)ECONOMY_D->currency_rate(from);

  this_player()->add_money(from, -(amount));

  amount = to_int(val / (int)ECONOMY_D->currency_rate(to));

  this_player()->add_money(to, amount);

  write("You exchange your "+from+" coins for "+amount+" "+to);
  say((string)this_player()->query_cap_name()+" exchanges some money.");
  return 1;
}

int close(string str) 
{
  int i;
  mapping money;
  
  if(!str || str != "account")
    return 0;
  money = (mapping)BANK_D->query_balance(
          (string)this_player()->query_name(), BANK_ID );
  if(!money || money == ([])) 
   {
     write("The teller says: You have no account here to close!");
     say(this_player()->query_cap_name()+" tries to close a "
         "non-existent account!");
     return 1;
   }
  for(i=0; i<sizeof(HARD_CURRENCIES); i++) 
   {
     if(money[HARD_CURRENCIES[i]]) 
       this_player()->add_money(HARD_CURRENCIES[i], money[HARD_CURRENCIES[i]]);
   }
  write("The teller hands you all your money.");
  say(sprintf("%s collects all %s money from the teller.",
     (string)this_player()->query_cap_name(), possessive(this_player())));
  BANK_D->close_account((string)this_player()->query_name(), BANK_ID);
  return 1;
}

int open(string str) {
    int x;

    if(!str || str != "account") return 0;
    x = (int)BANK_D->open_account((string)this_player()->query_name(), BANK_ID);
    if(x != TRANSACTION_OK) {
	write("You already have an account here!");
	return 1;
    }
    write("You open up an account at this bank.");
    say(this_player()->query_cap_name()+" opens an account.");
    return 1;
}

int balance(string str) {
    mapping money;
    int i;

    money = (mapping)BANK_D->query_balance(
	(string)this_player()->query_name(), BANK_ID
    );
    if(!money || money == ([])) {
	write("The teller says: You have no account here!");
	return 1;
    }
    say(this_player()->query_cap_name()+" receives a peice of paper from the teller.");
    write("\n\n The teller looks up your account. He writes something down ");
    write(" on a small peice of paper and hands it to you. On the paper");
    write(" you see the following:\n");	
    for(i=0; i<sizeof(HARD_CURRENCIES); i++) {
	printf("%-10s : %7d coins\n",capitalize(HARD_CURRENCIES[i]),money[HARD_CURRENCIES[i]]);
    }
    write(" \nThe paper disappears from your hand.");
    return 1;
}

int deposit(string str) {
    string type;
    int x, amount;

    if(!str) {
	notify_fail("Correct syntax: <deposit [amount] [type]>\n");
	return 0;
    }
    if(sscanf(str, "%d %s", amount, type) != 2) {
	notify_fail("Correct syntax: <deposit [amount] [type]>\n");
	return 0;
    }
    if((int)this_player()->query_money(type) < amount) {
	notify_fail("The teller says: You do not have that much money!\n");
	return 0;
    }
    x = (int)BANK_D->deposit(
	(string)this_player()->query_name(), BANK_ID, amount, type
    );
    if(x != TRANSACTION_OK) {
	switch(x) {
	    case NO_ACCOUNT:
		notify_fail("The teller says: You have no account here!\n");
		break;
	    case BAD_MONEY:
		notify_fail("The teller says: That is not a real money type!\n");
		break;
	    default: notify_fail("The teller says: You can't do that!\n");
	}
	return 0;
    }
    this_player()->add_money(type, -amount);
     this_player()->force_me("save");
    write("The teller takes your "+amount+" "+type+" coins.");
    say(this_player()->query_cap_name()+" deposits some money.");
    return 1;
}

int withdraw(string str) {
    string type;
    int x, amount;

    if(!str) {
	notify_fail("Correct syntax: <deposit [amount] [type]>\n");
	return 0;
    }
    if(sscanf(str, "%d %s", amount, type) != 2) {
	notify_fail("Correct syntax: <deposit [amount] [type]>\n");
	return 0;
    }
    if(amount < 0) {
	notify_fail("The teller says: That would be a neat trick!\n");
	return 0;
    }
    x = (int)BANK_D->withdraw(
	(string)this_player()->query_name(), BANK_ID, amount, type
    );
    if(x != TRANSACTION_OK) {
	switch(x) {
	    case NO_ACCOUNT:
		notify_fail("The teller says: You have no account here!\n");
		break;
	    case BAD_MONEY:
		notify_fail("The teller says: That is not a real money type!\n");
		break;
	    default: notify_fail("The teller says: You can't do that!\n");
	}
	return 0;
    }
    this_player()->add_money(type, amount);
    write("The teller gives you your "+amount+" "+type+" coins.");
    say(this_player()->query_cap_name()+" withdraws some money.");
    return 1;
}

int read(string str) {
    if(str != "sign") return notify_fail("Read what?\n");
	write(
@MELNMARN
%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
%^BOLD%^%^GREEN%^      You may do any of the following at this bank....
%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
%^BOLD%^%^CYAN%^Open account%^BLACK%^ ------------------------ %^RESET%^%^CYAN%^Will open an account for you. 
%^BOLD%^%^CYAN%^Close account%^BLACK%^ ----------------------- %^RESET%^%^CYAN%^Closes your account.
%^BOLD%^%^CYAN%^Balance%^BLACK%^ ----------------------------- %^RESET%^%^CYAN%^Gives your account balance info.
%^BOLD%^%^CYAN%^Deposit <#> <type>%^BLACK%^ ------------------ %^RESET%^%^CYAN%^Deposits # of currency of type.
%^BOLD%^%^CYAN%^Withdraw <#> <type>%^BLACK%^ ----------------- %^RESET%^%^CYAN%^Withdraws # of currency of type.
%^BOLD%^%^CYAN%^Exchange <#> of <type1> for <type2>%^BLACK%^ - %^RESET%^%^CYAN%^Exchanges currencies.
%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
MELNMARN
    );
    return 1;
}

float dnd_currency_rate(string from)
{
  switch( from )
   {
     case "copper"   : return 1;
                       break;
     case "silver"   : return 10;
                       break;
     case "electrum" : return 50;
                       break;
     case "gold"     : return 100;
                       break;
     case "platinum" : return 500;
                       break;
   }
  return 0;
}
