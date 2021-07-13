//adapted from hmboard command to provide universal remote
//board read/post/etc. ability for ooc boards *Styx*  9/2002
//improvements to provide login listing by Garrett
// next option added by Styx per Grendel's suggestion 8/2003

#include <std.h>
#include <daemons.h>
#include <objects.h>

inherit DAEMON;

string * BBOARDS=({
            "announcement",
            "newbie",
            "law",
            "avatarmail",
            "pkmail",
            "bugs",
            "ideas",
            "plots",
            });


int check_access(string my_command, string which_board);
int do_all_info()
{
    int iter, board_count, new_count;
    string board_spam;
    object board, tmp;
    if (!objectp(TP)) return 0;
    iter=sizeof(BBOARDS);
    board_spam="\n";
    board_count = new_count = 0;
    while (iter--)
    {
        if (!check_access("info", BBOARDS[iter])) {
            continue;
        }
        if (!file_exists("/d/common/boards/" + BBOARDS[iter] + "board.c")) {
            continue;
        }

        board = present("board", find_object_or_load("/d/common/boards/" + BBOARDS[iter] + "board"));
        board_count++;
        if (!objectp(board)) {
            tmp = find_object_or_load("/d/common/boards/" + BBOARDS[iter] + "board")->reset();
            if (!objectp(tmp)) {
                continue;
            }
            board = present("board", tmp);
            if (!objectp(board)) {
                continue;
            }
        }
        if (board->has_new()) {
            new_count += board->has_new();
        }
        board_spam += "%^ORANGE%^"+board->query_remote_short();
        board_spam += "\n";
    }
    board_spam = replace_string(board_spam,"OOC ","");
    board_spam = replace_string(board_spam," unread","");
    write(board_spam);
    write("%^GREEN%^To access these %^BOLD%^%^OOC%^RESET%^%^GREEN%^ virtual boards, use %^ORANGE%^<bboard next>%^GREEN%^%^ or %^ORANGE%^<help bboard>%^GREEN%^%^GREEN%^ for more information and examples.%^GREEN%^");
    if (new_count) write("%^BOLD%^%^MAGENTA%^You have %^YELLOW%^"+new_count+"%^MAGENTA%^ unread posts!");
}

int check_access(string my_command, string which_board)
{
    if ((base_name(ETP) == "/d/shadowgate/jail") && (member_array(my_command,({"read","info","next" }) ) == -1 ) )
        return 0;
    switch (which_board)
    {
        case "newbie":
            return 1;
            break;
        case "plots":
            return 1;
            break;
        case "announcement":
            switch (my_command)
            {
                case "answer": case "post": case "edit": case "remove":
                    if(avatarp(TP)) return 1;
                    return 0;
                    break;
                default:
                    return 1;
                    break;
            }
        case "bugs" : case "ideas" :
            if(wizardp(this_player()))
                return 1;
            else
                return 0;
            break;
        case "law":
            if(wizardp(this_player()))
                return 1;
            else
                return 0;
            break;
        case "avatarmail": case "lawboard":
            if(avatarp(TP)) return 1;
            else return 0;
            break;
        default:
            if (TP->is_class(which_board) || avatarp(TP)) return 1;
            else return 0;
            break;
    }
    return 0;
}

int cmd_bboard(string str)
{
    object board, tmp;
    string which, command, myclass;
    mixed what;
    int ret, ok, iter, number;

    if (!TP->query_level()) {
        return notify_fail("Please create a character before using this command!");
    }
    if (!str) {
        do_all_info();
        return 1;
    }
    if (str == "next") {
        iter = sizeof(BBOARDS);
        while (iter--) {
            if (!check_access("info", BBOARDS[iter])) {
                continue;
            }
            if (!file_exists("/d/common/boards/" + BBOARDS[iter] + "board.c")) {
                continue;
            }
            board = present("board", find_object_or_load("/d/common/boards/" + BBOARDS[iter] + "board"));
            if (!objectp(board)) {
                tmp = find_object_or_load("/d/common/boards/" + BBOARDS[iter] + "board")->reset();
                if (!objectp(tmp)) {
                    continue;
                }
                board = present("board", tmp);
                if (!objectp(board)) {
                    continue;
                }
            }
            if ((int)BBOARD_D->get_new_post(board->query_board_id(), (string)TP->query_true_name()) == -1) {
                continue;
            }
            if ((int)BBOARD_D->get_new_post(board->query_board_id(), (string)TPQN) == sizeof((mapping*)BBOARD_D->query_posts(board->query_board_id()))) {
                continue;
            }
            write("Message read from the %^YELLOW%^" + BBOARDS[iter] + " board%^RESET%^.");
            return board->read_message();
        }
        write("%^BOLD%^There are no unread messages on your list of boards.\n");
        return 1;
    }
    if(sscanf(str, "%s %s %s", which, command, what) != 3) {
        sscanf(str, "%s %s", which, command);
    }
    if(!command) {
        which = str;
    }
    if( which == "info" || (which == "all" && command=="info") ) {
        do_all_info();
        return 1;
    }
    if(member_array(which, BBOARDS) == -1) {
        write("That is not a valid board name, please try again or "
              "check the list in <help bboard>.");
        return 1;
    }

    ok = check_access(command,which);

    if(!ok) {
       write("Sorry, you aren't allowed "+command+" access to the "
             +which+" board.  If you believe that is an error, please "
             "bug report which board and what class or classes you are.");
       return 1;
    }

    board = present("board",find_object_or_load("/d/common/boards/"+which+"board"));
    if (!objectp(board)) {
        "/d/common/boards/"+which+"board"->reset();
    }
    switch (command) {
    case "post" :
        ret = board->post_message(what);
        break;
    case "remove":
        ret =  board->remove_message(what);
        break;
    case "read":
        ret =  board->read_message(what);
        break;
    case "readall":
        ret =  board->read_all();
        break;
    case "answer":
        ret =  board->reply_message(what);
        break;
    case "edit":
        if(!avatarp(TP)) {
           write("Sorry, you aren't allowed to edit messages.");
           ret = 1;
           break;
        }
        ret =  board->edit_message(what);
        break;
    case "info":
        write(board->query_short());
        ret=1;
        break;
     case "top":
         ret =  board->show_top(what);
         break;
    case "list":
    case "view":
        write(board->query_long());
        ret= 1;
        break;
    default :
        ret = 1;
        write(board->query_short());
        break;
    }
  return ret;
}


int help(){
  int i;
  write(
"
%^CYAN%^NAME%^RESET%^

bboard - read and access boards

%^CYAN%^SYNOPSIS%^RESET%^

bboard %^ORANGE%^%^ULINE%^NAME%^RESET%^ post %^ORANGE%^%^ULINE%^TITLE%^RESET%^
bboard %^ORANGE%^%^ULINE%^NAME%^RESET%^ [read|answer|remove|view] [%^ORANGE%^%^ULINE%^POST_NUMBER%^RESET%^]
bboard %^ORANGE%^%^ULINE%^NAME%^RESET%^ list
bboard %^ORANGE%^%^ULINE%^NAME%^RESET%^ readall
bboard next
bboard [info]

%^CYAN%^DESCRIPTION%^RESET%^

This command allows you to access out of character boards from any location.

Sub-commands that apply are:

%^ORANGE%^<bboard>%^RESET%^
%^ORANGE%^<bboard info>%^RESET%^

    List all available  to you boards.

%^ORANGE%^<bboard %^ORANGE%^%^ULINE%^NAME%^RESET%^%^ORANGE%^ post %^ORANGE%^%^ULINE%^TITLE%^RESET%^>%^RESET%^

    Post message with the %^ORANGE%^%^ULINE%^TITLE%^RESET%^ on the %^ORANGE%^%^ULINE%^NAME%^RESET%^ board.

%^ORANGE%^<bboard %^ORANGE%^%^ULINE%^NAME%^RESET%^%^ORANGE%^ list>%^RESET%^

    Lists all messages on board %^ORANGE%^%^ULINE%^NAME%^RESET%^.

%^ORANGE%^<bboard %^ORANGE%^%^ULINE%^NAME%^RESET%^%^ORANGE%^ readall>%^RESET%^

    Marks all messages on board %^ORANGE%^%^ULINE%^NAME%^RESET%^ as read.

%^ORANGE%^<bboard %^ORANGE%^%^ULINE%^NAME%^RESET%^%^ORANGE%^ [read|answer|remove|view] [%^ORANGE%^%^ULINE%^POST_NUMBER%^RESET%^%^ORANGE%^]>%^RESET%^

    View, reply to, remove or view message with the number %^ORANGE%^%^ULINE%^POST#%^RESET%^ on the board %^ORANGE%^%^ULINE%^NAME%^RESET%^.

%^ORANGE%^<bboard next>%^RESET%^

    View next unread message.

There are special boards normal player con only post to.

%^CYAN%^SEE ALSO%^RESET%^

avatarmail, pkmail, lines
"
   );
  return 1;
}
