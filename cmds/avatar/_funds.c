//Updated by Saide to show how much money is in each bank 
//acount - as opposed to the current display of all their
//money - June 2008

#include <std.h>
#include <daemons.h>
#include <money.h>
#include <bank.h>


inherit DAEMON;

int cmd_funds(string str)
{
      string *currs=({}),*accounts=({}),tmp="", tmp_acc="", act_str = "";
    	mapping bankmoney;
    	mapping totals;
    	object targ;
    	int i, j, amt;

   	string posxxx; 
   	if(!objectp(TP)) 
	{ 
		return 0; 
	}
   	posxxx = lower_case((string)TP->query_position());
   	if(posxxx == "builder" || posxxx == "apprentice")
   	{
       	tell_object(TP,"You cannot use this command as a builder or "+						"apprentice.");
       	return 1;
   	}

    	if(!str) 
	{
		return notify_fail("on who?\n");
	}
     	if(!user_exists(str))
	{
		return notify_fail("Can't find "+str+".\n"); 
	}
	accounts = BANK_D->query_bank_accounts(str);
    	totals = ([]);
	if(sizeof(accounts) >= 1) 
	{
		if(sizeof(accounts) == 1)
		{
			act_str = "one bank account.";
		}
		else
		{
			act_str = sizeof(accounts) + " bank accounts.";
		}
		tmp += "%^BOLD%^%^RED%^" + capitalize(str) + " has " + act_str + "\n%^RESET%^";
		for(i = 0;i < sizeof(accounts);i++)
		{
			amt = 0;
			tmp_acc = "%^BOLD%^%^RED%^Bank%^RESET%^ : " + capitalize(accounts[i]) + "\n";
			bankmoney = (mapping)BANK_D->query_balance(str, accounts[i]);
			if(!bankmoney) 
			{
				tmp += "%^BOLD%^%^YELLOW%^Something is wrong with the "+
				"account in "+capitalize(accounts[i])+"!\n";
				continue;
			}
			for(j = 0; j < sizeof(HARD_CURRENCIES);j++)
			{		
				tmp_acc += "%^BOLD%^%^RED%^" + capitalize(HARD_CURRENCIES[j]) + 
				"%^RESET%^ : " + bankmoney[HARD_CURRENCIES[j]];
				tmp_acc += "\n";
				amt += to_int(bankmoney[HARD_CURRENCIES[j]]);
				totals[HARD_CURRENCIES[j]] = totals[HARD_CURRENCIES[j]] + 
				bankmoney[HARD_CURRENCIES[j]];
			}
			if(amt <= 0)
			{
				tmp_acc = "%^BOLD%^%^WHITE%^No money in "+
				capitalize(accounts[i])+"%^RESET%^";
			}			
			tmp += tmp_acc + "\n";
		}
	}
	currs = USERCALL->user_call(str,"query_currencies");
	for(j = 0; j < sizeof(HARD_CURRENCIES); j++)
	{
      	tmp += "%^BOLD%^%^RED%^" + capitalize(HARD_CURRENCIES[j])+" amount total%^RESET%^ : "+
		(totals[HARD_CURRENCIES[j]]+
		USERCALL->user_call(str,"query_money",HARD_CURRENCIES[j])) + "\n";
    	}
	tmp += "%^BOLD%^%^RED%^Total laundered money (gold?)%^RESET%^ :"+
	USERCALL->user_call(str,"query","total laundered money") + "\n";

	tmp += "%^BOLD%^%^RED%^Total fenced money (gold?)%^RESET%^ :"+
	USERCALL->user_call(str,"query","total fenced money") + "\n";

	tmp += "%^BOLD%^%^RED%^Thief account money (gold?)%^RESET%^ :"+
	USERCALL->user_call(str,"query","thief account") + "\n";

	tmp += "%^BOLD%^%^RED%^Credit for stolen money (gold?)%^RESET%^ :"+
	USERCALL->user_call(str,"query","stolen money") + "\n";
	TP->more(explode(tmp, "\n"));
    	return 1;
}

int help()
{
	write("Syntax: <funds [player]>\n\n"+
	"This will tell you the number of bank accounts [player] has, "+
	"how much they have in each account, and the total of all said "+
	"accounts, along with the total amount of money they are carrying.  "+
	"It will also list the total amount of money they have fenced, "+
	"laundered, and their thief account credits.\n\n"+
	"Please note that the player must exist, though they do not "+
	"have to be logged in.");
	return 1;
}