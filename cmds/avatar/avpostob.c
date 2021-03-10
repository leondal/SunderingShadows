#include <std.h>
#include "items.h"
#include <move.h>
#include <daemons.h>
#include <bboard.h>
#include <security.h>
#define APB "/d/save/avpost_boards"

inherit OBJECT;
string POST_TITLE;
mapping board_names = ([]);
nosave string *boards_selected = ({});
nosave string *menu = ({});
int do_auto_remove = 0;
void build_menu();
void display_board_menu();

void set_avpost_title(string title)
{
	POST_TITLE = title;
}

int save_me(string file)
{
	return 1;
}

void init()
{
      ::init();
	board_names = ([]);
	boards_selected = ({});
	do_auto_remove = 0;
	menu = ({});
	ETO->edit(BBOARD_EDIT+(string)ETO->query_name(), "finish", TO);
}

void exit_avpost()
{
	tell_object(ETO, "Exiting the avpost system.  Good bye.");
	ETO->remove_property("AV_POST_TITLE");
	TO->remove();
	if(objectp(TO))
	{
		destruct(TO);
	}
}

void finish()
{
	board_names = ([]);
	if(file_exists(BBOARD_EDIT+(string)ETO->query_name()) &&
	file_size(BBOARD_EDIT+(string)ETO->query_name()) != -1)
	{
		if(read_file(BBOARD_EDIT+(string)ETO->query_name()) != 0)
		{
			tell_object(ETO, "%^CYAN%^Your post is as follows : \n%^RESET%^");
			tell_object(ETO, "%^BOLD%^%^GREEN%^============================="+
			"==============="+
			"======================%^RESET%^");
			ETO->more(explode(read_file(BBOARD_EDIT+(string)ETO->query_name()), "\n"));
			tell_object(ETO, "\n%^BOLD%^%^GREEN%^===================="+
			"========================"+
			"======================%^RESET%^");
			tell_object(ETO, "%^BOLD%^%^WHITE%^\nPlease review your post and make "+
			"SURE that it is CORRECT. \n"+
			"As of now there is no way to mass edit your post after it's made, "+
			"so if it is NOT "+
			"CORRECT you will have to manually edit it on each board you "+
			"choose to post on.");
			tell_object(ETO, "Is your post correct?  yes/no?");
			tell_object(ETO, "You may use ** to exit the system.");
			input_to("check_is_post_correct");
			return;
		}
	}
	exit_avpost();
	return 1;
}

void check_is_post_correct(string str)
{
	if(str == "**")
	{
		exit_avpost();
		return 1;
	}
	if(!str || str == "" || (str != "yes" && str != "y" && str != "no" && str != "n"))
	{
		finish();
		return 1;
	}
	if(str == "yes" || str == "y")
	{
		boards_selected = ({});
		board_names = ([]);
		menu = ({});
		if(!file_exists(APB + ".o"))
		{
			tell_object(ETO, "Something went wrong... the list of boards "+
			"registered to work with avpost is missing.");
			exit_avpost();
			return;
		}
		if(file_exists(APB + ".o"))
		{
			restore_object(APB);
		}
		build_menu();
		display_board_menu();
		input_to("my_action");
		return 1;
	}
	if(str == "no" || str == "n")
	{
		rm(BBOARD_EDIT+(string)ETO->query_name());
		ETO->edit(BBOARD_EDIT+(string)ETO->query_name(), "finish", TO);
		return 1;
	}
}


void build_menu()
{
	menu = keys(board_names);
	menu += ({ "All Boards" });
	menu += ({ "Post It!" });
	menu += ({ "Exit" });
}

void display_board_menu()
{
	int x, y;
	string tmp;
	tell_object(ETO, "\n%^BOLD%^%^GREEN%^============================================"+
	"======================%^RESET%^\n");
	for(x = 0;x < sizeof(menu);x++)
	{
		y = x + 1;
		tmp = "%^BOLD%^%^WHITE%^"+(y)+ ".%^BOLD%^%^GREEN%^) %^RESET%^";
		if(menu[x] != "Post It!" && menu[x] != "Exit" && menu[x] != "All Boards")
		{
			if(member_array(menu[x], boards_selected) != -1)
			{
				tmp += "%^YELLOW%^*%^RESET%^ ";
			}
			tmp += board_names[menu[x]][0];
		}
		else
		{
			tmp += menu[x];
		}
		tell_object(ETO, tmp);
	}
	tell_object(ETO, "\n%^BOLD%^%^GREEN%^============================================"+
	"======================%^RESET%^");
	tell_object(ETO, "%^RED%^Instructions :%^RESET%^");
	tell_object(ETO, "\n1. ) %^YELLOW%^*%^RESET%^ = Indicates A board that "+
	"you've selected to post to.");
	tell_object(ETO, "2. ) Please input a number from the list above.\n" +
	"3.) You must select at least one board to post to.");
	tell_object(ETO, "4. ) Selecting 'All Boards' will take you to the "+
	"next step - as if you selected 'Post It!'\n5.) When Finished select 'Post It!' to "+
	"continue.");
	tell_object(ETO, "6. ) Input ** at any time to exit.");
	return;
}

void my_action(string str)
{
	int choice;
	string str_choice;
	if(str == "**")
	{
		exit_avpost();
		return 1;
	}
	choice = to_int(str);
	choice = choice - 1;
	if(choice < 0 || choice >= sizeof(menu))
	{
		tell_object(ETO, "Please input a number between 1 - "+sizeof(menu)+".");
		display_board_menu();
		input_to("my_action");
		return 1;
	}
	str_choice = menu[choice];
	if(str_choice == "Exit")
	{
		exit_avpost();
		return 1;
	}
	if(str_choice == "All Boards")
	{
		boards_selected = keys(board_names);
		tell_object(ETO, "Do you wish for avpost to automatically remove a post "+
		"from the any selected board, if needed?  yes/no?  Default is NO.");
		tell_object(ETO, "Please note that if you answer no, then your post will "+
		"not be added to any board that is full.");
		input_to("do_auto_remove");
		return 1;
	}
	if(str_choice == "Post It!")
	{
		if(sizeof(boards_selected) < 1)
		{
			tell_object(ETO, "You must select at least 1 board to post to.");
			display_board_menu();
			input_to("my_action");
			return 1;
		}
		tell_object(ETO, "Do you wish for avpost to automatically remove a post "+
		"from the any selected board, if needed?  yes/no?  Default is NO.");
		tell_object(ETO, "Please note that if you answer no, then your post will "+
		"not be added to any board that is full.");
		input_to("do_auto_remove");
		return 1;
	}
	if(member_array(str_choice, boards_selected) == -1)
	{
		boards_selected += ({str_choice});
		display_board_menu();
		input_to("my_action");
		return 1;
	}
	if(member_array(str_choice, boards_selected) != -1)
	{
		boards_selected -= ({str_choice});
		display_board_menu();
		input_to("my_action");
		return 1;
	}
}

void add_my_avpost()
{
	int posts, result, max;
	int x, y;
	string tmp;
	POST_TITLE = ETO->query_property("AV_POST_TITLE");
	cp(BBOARD_EDIT+(string)ETO->query_name(), BBOARD_EDIT+(string)ETO->query_name()+"_tmp");
	for(x = 0;x < sizeof(boards_selected);x++)
	{
		max = board_names[boards_selected[x]][1];
		if(BBOARD_D->get_num_posts(boards_selected[x]) >= max && do_auto_remove == 1)
		{
			y = 1;
			result = -1;
			tmp = "Removing post from " + board_names[boards_selected[x]][0]+"....";
			while(result != BBOARD_OK && y <= max)
			{
				result = BBOARD_D->remove_message(boards_selected[x], y);
				y++;
			}
			if(result == BBOARD_OK)
			{
				tmp += " success.";
			}
			if(result != BBOARD_OK)
			{
				tmp += " failure.";
				tell_object(ETO, tmp + "\n.Msg NOT posted on "+
				board_names[boards_selected[x]][0]+"!");
				continue;
			}
			tell_object(ETO, tmp + "\n");
		}
		if(BBOARD_D->get_num_posts(boards_selected[x]) >= max && do_auto_remove == 0)
		{
			tell_object(ETO, board_names[boards_selected[x]][0]+
			" is full.  Skipping.\n");
			continue;
		}
		result = -1;
		result = BBOARD_D->post_message(boards_selected[x], POST_TITLE);
		if(result == BBOARD_OK)
		{
			tell_object(ETO, "Msg posted successfully on "+
			board_names[boards_selected[x]][0]+"!\n");
			cp(BBOARD_EDIT+(string)ETO->query_name()+"_tmp",
			BBOARD_EDIT+(string)ETO->query_name());
			continue;
		}
		else
		{
			tell_object(ETO, "Msg NOT posted on "+
			board_names[boards_selected[x]][0]+"!\n");
			continue;
		}
	}
	rm(BBOARD_EDIT+(string)ETO->query_name());
	rm(BBOARD_EDIT+(string)ETO->query_name()+"_tmp");
	exit_avpost();
	return;
}

void do_auto_remove(string str)
{
	if(str == "**")
	{
		exit_avpost();
		return 1;
	}
	if(str == "y" || str == "yes")
	{
		tell_object(ETO, "You have selected to have avpost attempt to remove "+
		"a post from any board that is full.");
		do_auto_remove = 1;
	}
	tell_object(ETO, "Attempting to post your message, please be patient.\n\n");
	add_my_avpost();
}
