//command to allow avatars to post to multiple IG boards at once
//for Lurue and her long winded posts :P
//Saide - October 2008
#include <std.h>
#include <daemons.h>
#define APB "/d/save/avpost_boards"
#define AVPOSTITEM "/cmds/avatar/avpostob.c"
inherit DAEMON;
int help();
mapping board_names = ([]);
int cmd_avpost(string str)
{
	string action, target, bn, bs, *bnames, bk;
	object targ, apo;
	int x;
	if(!str || str == "") 
	{
		return help();
	}
	if(str == "list" || str == "List")
	{	
		board_names = ([]);
		if(!file_exists(APB+".o")) 
		{
			tell_object(TP, "There are currently no boards registered to work "+
			"with avpost.");
			return 1;
		}
		restore_object(APB);
		tell_object(TP, "The following boards are registered to work with "+
		"avpost. (If you notice any missing please register them.  Thanks, Saide.");
		bnames = ({});
		bk = keys(board_names);
		for(x = 0;x < sizeof(bk);x++)
		{
			bnames += ({board_names[bk[x]][0]});
		}
		TP->more(bnames);
		return 1;
	}
		
	if(sscanf(str, "%s %s", action, target) != 2)
	{
		return help();
	}
	if(sscanf(str, "%s %s", action, target) == 2)
	{
		//code dealing with registering a board to work with 
		//avpost - which will show up on the list of boards to post to
		if(action == "register" || action == "Register")
		{
			if(!objectp(targ = present(target, ETP)))
			{
				tell_object(TP, "There is no "+target+" here!");
				return 1;
			}
			bn = targ->query_board_id();
			bs = explode(targ->query_short(), "[")[0];
			board_names = ([]);
			if(file_exists(APB + ".o")) 
			{
				restore_object(APB);
			}
			if(member_array(bn, keys(board_names)) == -1)
			{
				board_names += ([bn : ({ bs, targ->query_max_posts() })]);
				save_object(APB);	
				tell_object(TP, bs +" was successfully registered!");		
				return 1;
			}		
			if(member_array(bn, keys(board_names)) != -1)
			{
				tell_object(TP, bs + " is already registered to work "+
				"with avpost.");
				return 1;
			}
			return 1;
		}
		if(action == "unregister" || action == "Unregister")
		{
			if(!objectp(targ = present(target, ETP)))
			{
				tell_object(TP, "There is no "+target+" here!");
				return 1;
			}
			bn = targ->query_board_id();
			bs = explode(targ->query_short(), "[")[0];
			board_names = ([]);
			if(file_exists(APB + ".o")) 
			{
				restore_object(APB);
			}
			if(member_array(bn, keys(board_names)) == -1)
			{
				tell_object(TP, bs +" is not currently registered to work "+
				"with avpost.");
				return 1;
			}		
			if(member_array(bn, keys(board_names)) != -1)
			{
				map_delete(board_names, bn);
				tell_object(TP, bs +" was unregistered successfully and will "+
				"no longer show up in the list of boards available to "+
				"avpost.");
				save_object(APB);
				return 1;
			}
			return 1;
		}
		//end of board registering code
		//Code that allows you to write a post and then 
		//attempt to post it to the boards you specify
		if(action == "title" || action == "Title")
		{
			board_names = ([]);
			if(!file_exists(APB + ".o")) 
			{
				tell_object(TP, "There are not currently any boards registered "+
				"to work with avpost.  Consider registering some and then try again.");
				return 1;
			}
			restore_object(APB);
			if(sizeof(keys(board_names)) < 1) 
			{
				tell_object(TP, "There are not currently any boards registered "+
				"to work with avpost.  Consider registering some and then try again.");
				return 1;
			}
			if(strlen(target) > 30) 
			{
				tell_object(TP, "Title cannot contain more than 30 characters.");
				return 1;
			}
			if(strlen(target) <= 0)
			{
				tell_object(TP, "You must give a title for your post.");
				return 1;
			}
			apo = new(AVPOSTITEM);
			apo->move(TP);
       		TP->set_property("AV_POST_TITLE", target);
			return 1;
		}
		//end of posting code
	}
	return 1;
}

int help()
{
	write("\t%^BOLD%^%^CYAN%^Syntax: %^RESET%^avpost register [%^BOLD%^"+
	"%^WHITE%^board%^RESET%^] \n"+
	"\t\tavpost unregister [%^BOLD%^%^WHITE%^board%^RESET%^] \n"+
	"\t\tavpost title [%^BOLD%^%^WHITE%^Title Text%^RESET%^]"+
	"%^RESET%^\n"+
	"\t\tavpost list\n\n"+
	"This command is meant to be an effiecient and easy to use method for posting to "+
	"multiple IG boards at the same time.  The following are examples of how to use it.\n\n"+
	"avpost list - this syntax lists the boards that are currently registered to be used "+
	"with avpost.\n\n"+
	"avpost register [board] - this allows you to register [board] to be used with "+
	"avpost - you must be standing in the same room as the [board] you specify and "+
	"it will not register if it's already in the list. (you can just do 'avpost "+
	"register board' and it will register any board in the room with you that "+
	"responds to the id word 'board'\n\n"+
	"avpost unregistere [board] - this works exactly the same as "+
	"register, except in reverse.  In the case were you accidentally "+
	"register a board and dont want to use it anymore or whatever other "+
	"use you might find for it.\n\n"+
	"avpost title [title text] - this is basically the meat of the command, it works "+
	"almost exactly the same way as standing in the room with a board and using the post "+
	"command - use it like avpost title 'this is a test' - will try to make a post "+
	"with the title 'this is a test'.  After you do this, you will be asked to enter "+
	"your post, then asked to make sure it looks correct (PLEASE NOTE:  MAKE SURE IT's "+
	"CORRECT - there is currently no way to mass edit posts).  After you make sure it's "+
	"correct, you will be taken to a menu of sorts where you can choose which boards or "+
	"'All Boards' that you would like to post to.  Then simply select the # for the option "+
	"'Post It!' and it will ask you if you would like for the command to try to remove "+
	"posts automatically if a board is full, answer and watch it work.  Hopefully "+
	"the prompts in the command are sorta self explanatory.");
	return 1;
}