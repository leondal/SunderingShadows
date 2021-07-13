//      /std/bboard.c
//      from the Nightmare mudlib
//      a new, inheritable bulletin board
//      created by Descartes of Borg 06 march 1993

//      Bulletin Board object version 1.5
//      Added optional permissions checking for read
//      and/or post
//      Added optional queue logic
//      Thorn@ShadowGate
//      12 December 2000
// Pator@ShadowGate Aug 14, 2003
// Added <top> command to show the latest 20 additions to the board

#include <std.h>
#include <move.h>
#include <daemons.h>
#include <bboard.h>
#include <security.h>

inherit OBJECT;

/**
 * @file
 * @brief Bboard base object
 */

int max_posts;
string location, board_id;
string *edit_ok;
int ooc_board;
int anonymous_board;
mapping title;
string *allowed;
int restricted_read, restricted_post, queue;

int post_message(string str);

int valid_user(object user);
void set_restricted_read();
void set_restricted_post();
void set_allowed(string *arr);
string *query_allowed();
int check_queue();
void set_queue();

int query_ooc_board();

int save_me(string file){ return 1;}
void init() {
      ::init();
	ETO->set_property("training",1);
    set_id(({"board","bboard","x_bboard"}));
	set_property("no animate",1);
	add_action("remove_message", "remove");
	add_action("reply_message", "answer");
	add_action("post_message", "post");
	add_action("edit_message", "edit");
	add_action("read_message", "read");
    add_action("read_all", "readall");
    add_action("show_top", "top");
    if (wizardp(TP)) add_action("do_purge","purgeread");
}

int post_message(string str) {
	if(queue) check_queue();
	if(restricted_post) {
		if(!valid_user(TP)) {
			write("You may not post to this board.");
			return 1;
		}
	}
    if(!title) title = ([]);
    if(!str) {
        notify_fail("You must give a title for your post.\n");
        return 0;
    }
    if((int)BBOARD_D->get_num_posts(board_id) >= max_posts) {
        notify_fail("You will first have to remove a note!\n");
        return 0;
    }
    if(strlen(strip_colors(str)) > 60) {
        notify_fail("Title cannot contain more than 60 characters.\n");
        return 0;
    }
	if(title[TP]) write("Warning! You are already marked as posting!\n");
	title[TP] = str;
	write("Edit post.\n");
	TP->edit(BBOARD_EDIT+(string)TPQN, "postit", TO);
    return 1;
}

varargs int postit() {
    int x;

    x = (int)BBOARD_D->post_message(board_id, title[TP]);
    if(x == BBOARD_OK) write("Posted.\n");
    else if(x == EDIT_ABORT) write("Edit aborted.\n");
    else if(x == BAD_DATA) write("Error in posting call. Please try again.\n");
    map_delete(title, TP);
   if(x == BBOARD_OK) tell_room(ETO,TPQCN+" posts something on the "+query_name()+".",TP);
    return 1;
}

int reply_message(string str) {
    int number;

	if(queue) check_queue();
	if(restricted_post) {
		if(!valid_user(TP)) {
			write("You may not post to this board.");
			return 1;
		}
	}
    if(!title) title = ([]);
    if(!str) {
        notify_fail("Reply to which message?\n");
        return 0;
    }
    if((int)BBOARD_D->get_num_posts(board_id) >= max_posts) {
        notify_fail("You will first have to remove a note.\n");
        return 0;
    }
    if(sscanf(str, "%d", number) != 1) {
        notify_fail("Invalid message number.\n");
        return 0;
    }
    number --;
    str = (string)BBOARD_D->get_title(board_id, number);
    str = "Re: "+str;
    return post_message(str);
}

int edit_message(string str) {
    int number, x;

    if(!title) title = ([]);
    if(!str) {
        notify_fail("You must specify which message you wish to edit.\n");
        return 0;
    }
	if(queue) check_queue();
    if(sscanf(str, "%d", number) != 1) {
        notify_fail("Invalid message number.\n");
        return 0;
    }
    number --;
    title[TP] = (string)BBOARD_D->get_title(board_id, number);
    x = (int)BBOARD_D->edit_note(board_id, number);
    if(x==BBOARD_OK) {
        write(title[TP]+": "+number+"\n");
        write("Editing post.\n");
        TP->edit(BBOARD_EDIT+(string)TPQN, "edit_stop_ed", TO);
        return 1;
    }
    else if(x == INVALID_MSG) write("Invalid message number.\n");
    else if(x == ILLEGAL_ACCESS) write("You may only edit your own posts.\n");
    else write("Error in editing post.\n");
    map_delete(title, TP);
    return 1;
}
void edit_stop_ed() {
    int x;

    x = (int)BBOARD_D->post_message(board_id, title[TP]);
    if(x == BBOARD_OK) write("Message edited.\n");
    else write(title[TP] + " "+x+"\n");
    map_delete(title, TP);
    rm((string)TP->query_edit_filename());
}

int remove_message(string str) {
    int number, x;
    string title;


    if(!str) {
        notify_fail("You must specify which note you wish to remove!\n");
        return 0;
    }
    if(sscanf(str, "%d", number) != 1) {
        notify_fail("Invalid message number!\n");
        return 0;
    }
    number --;
    title = (string)BBOARD_D->get_title(board_id, number);
    x = (int)BBOARD_D->remove_message(board_id, number);
    if(x==BBOARD_OK) {
        write("Message "+(number+1)+" removed.\n");
        tell_room(ETP,TPQCN+" removed message # "+(number+1)+" on the "+query_name()+".",TP);
    }
    else if(x == INVALID_MSG) write("Invalid message number.\n");
    else if(x == ILLEGAL_ACCESS) write("You may only remove your own posts.\n");
    else write("Error "+x+" in removing post.\n");
    seteuid(UID_LOG);
    if (x == BBOARD_OK) {
        log_file("player/boards",capitalize(TPQN)+" removed a post "+(number+1)+"  titled '"+title+"' from "+query_short()+" on "+ctime(time())+".\n");
    } else {
        log_file("playerboards",capitalize(TPQN)+" failed to remove a post "+(number+1)+"  titled '"+title+"' from "+query_short()+" on "+ctime(time())+".\n");
    }
    return 1;
}

int read_message(string str) {
    int number;
    mapping msg;
    string *lines;

	if(restricted_read) {
		if(!valid_user(TP))
			return write("You may not read this board.");
	}
	if(queue) check_queue();
    if(!str)
        number = 1 + (int)BBOARD_D->get_new_post(board_id, (string)TPQN);
    else if(sscanf(str, "%d", number) != 1) {
        notify_fail("Invalid message number.\n");
        return 0;
    }
    msg = (mapping)BBOARD_D->get_message(board_id, number-1);
    if(!msg) {
        notify_fail("No more messages.\n");
        return 0;
    }
    write("%^GREEN%^Message "+number+":%^RESET%^");

    if(query_ooc_board())
    {
        if(!query_anonymous_board()||wizardp(TP))
            write("%^GREEN%^From: "+msg["owner"]);
        write("%^GREEN%^Date: "+ctime(msg["date"]));
    }

    write("%^GREEN%^Subject: "+msg["title"]+"%^RESET%^");
    write("");
    write(msg["message"]);
    BBOARD_D->set_read(board_id, (string)TPQN, number-1);
    return 1;
}

/**
 * Marks all messages as read
 */
int read_all(){
    int i;
    i=0;
    while((BBOARD_D->set_read(board_id, (string)TPQN,i)))
    {
        i++;
    }
    write(query_short());
    return 1;
}

string query_long(string junk) {
    string borg;

    borg = ::query_long();
	if(restricted_read) {
		if(!valid_user(TP)) {
			borg += "\nYou may not read this board.\n";
			return borg;
		}
	}
	if(queue) check_queue();
    borg += "\n%^GREEN%^There are %^YELLOW%^"+(int)BBOARD_D->get_num_posts(board_id)+"%^RESET%^%^GREEN%^ messages posted.\n";
    borg += (string)BBOARD_D->display_board(board_id);
    borg += "
%^GREEN%^Board commands:
%^ORANGE%^<post %^ORANGE%^%^ULINE%^TITLE%^RESET%^%^ORANGE%^>%^RESET%^, %^ORANGE%^<edit %^ORANGE%^%^ULINE%^NUM%^RESET%^%^ORANGE%^>%^RESET%^, %^ORANGE%^<read [%^ORANGE%^%^ULINE%^NUM%^RESET%^%^ORANGE%^]>%^RESET%^, %^ORANGE%^<answer %^ORANGE%^%^ULINE%^NUM%^RESET%^%^ORANGE%^>%^RESET%^, %^ORANGE%^<remove %^ORANGE%^%^ULINE%^NUM%^RESET%^%^ORANGE%^>%^RESET%^
%^ORANGE%^<top%^ORANGE%^>%^GREEN%^ to show the 20 latest posts
%^ORANGE%^<readall%^ORANGE%^>%^GREEN%^ to mark everything as read
";
    return borg;
}

string show_top(string junk) {
    string borg;

	borg = "";
    if(restricted_read) {
        if(!valid_user(TP)) {
            borg += "\nYou may not read this board.\n";
            return borg;
        }
    }
    if(queue) check_queue();
    borg += "\nThere are "+(int)BBOARD_D->get_num_posts(board_id)+" messages posted.\n";
    borg += (string)BBOARD_D->display_board_top(board_id);
	write(borg);
	return borg;
}

void set_board_id(string str) {
    if(board_id) return;
    board_id = str;
}
/****************************** DON'T REMOVE. I HAVE A GOOD REASON FOR THIS!
 * - Garrett 12/04/2001
**************************************/

void force_reset_board_id(string str) {
  board_id=0;
  set_board_id(str);
  return;
}

string query_board_id() { return board_id; }

void set_max_posts(int x) { max_posts = x; }

int query_max_posts() { return max_posts; }

void remove_board()
{
    if(!objectp(TO)) return;
    TO->remove();
}

void set_location(string file) {
    if(location) return;
    location = file;
    if(present("board", find_object_or_load(location)))
    {
        call_out("remove_board", 1);
        return;
    }
    ::move(location);
}

int move(mixed dest) { return MOVE_NOT_ALLOWED; }

int get() { return 0; }

int drop() { return 1; }

void set_edit_ok(string *who) {
    if(!who) edit_ok = ({});
    else edit_ok = who;
}

string *query_edit_ok() {
    if(!edit_ok) return ({});
    return edit_ok;
}

void set_ooc_board(int x){
     ooc_board = x;
}

int query_ooc_board(){ return ooc_board;}

/**
 * Anonymous boards don't display message author name even if they are ooc boards
 */
void set_anonymous_board(int x)
{
    anonymous_board = x;
}
int query_anonymous_board()
{
    return anonymous_board;
}
//changing this to int clean_up() as it is in move.c
//see if it will stop the occassional bug where it doesnt
//find function postit after you've typed your message - Saide - Oct 2008
//void clean_up() { return; }
int clean_up() { return 0; }
//

int is_nonmember(mixed * arr, mixed what) {
  if (member_array((string)what, arr) == -1) return 1;
  return 0;
}
int count_new(string id) {
    mixed *read_by;
    read_by=BBOARD_D->query_read_by(board_id);
    return sizeof(filter_array(read_by,"is_nonmember",TO,TPQN));
        //   if(member_array((string)TPQN,
         //       read_by[i]) == -1)
         //       newposts++;
}


int has_new() { return count_new(board_id); }

string display_new( string id ) {
    mapping *posts;
    mixed *read_by;
    int maxi,i, newposts;
    string str;

    if(!id)
        return 0;
	if(restricted_read && restricted_post) {
		if(!TP) return 0;
		if(!valid_user(TP)) {
			return " {No access}";
		}
	}
    read_by=BBOARD_D->query_read_by(board_id);
    maxi = sizeof(posts = (mapping *)BBOARD_D->query_posts(board_id));
    newposts=0;
    if(maxi)
    {
        for(i=0; i<maxi; i++)
        {
            if(member_array((string)TPQN,
                            read_by[i]) == -1)
                newposts++;
        }
    }
    if(!TP)
        return 0;

    str=" ";

    str+="%^RESET%^%^GREEN%^(";
    if(newposts)
        str+="%^YELLOW%^";
    str+=sprintf("%2d",newposts)+"%^GREEN%^ out of "+sprintf("%2d",maxi)+"%^RESET%^%^GREEN%^)%^RESET%^";


	if(restricted_read) {
		if(!valid_user(TP)) {
			str+= "%^GREEN%^[Write only]%^RESET%^";
		}
	}
	if(restricted_post) {
		if(!TP) return 0;
		if(!valid_user(TP)) {
			str+= "%^GREEN%^[Read only]%^RESET%^";
		}
	}
    return str;
}

string query_remote_short()
{
    int j;
    string str;
    str = ::query_short();
	if(queue) check_queue();
    if (objectp(TP))
    j = 26 - strlen(str);
    str += arrange_string(" ", j) + display_new(board_id);
    return str;
}

string query_short()
{
    string str;
    str = ::query_short();
	if(queue) check_queue();
    if (objectp(TP))
    str += display_new(board_id);
    return str;
}

// Checks for a property to be set in the player for them to
// be allowed to post to or read this board.  Wizzes and avatars
// may also use this board. - v1.5 thorn 001212
int valid_user(object user) {
	int inc;

	if(avatarp(user)) return 1;
	for(inc=0;inc<sizeof(allowed);inc++) {
		if(user->query_property(allowed[inc])) return 1;
	}
	return 0;
}

// Sets whether the permissions are checked on this board
// before posting. - v1.5 thorn 001212
void set_restricted_post() { restricted_post = 1; }

// Sets whether the permissions are checked on this board
// before allowing reading or listing. - v1.5 thorn 001212
void set_restricted_read() { restricted_read = 1; }

// Sets the properties required in a user to be able to post to
// this board. - v1.5 thorn 001212
void set_allowed(string *arr) {
	allowed = arr;
}

// Returns the properties required in a user to be able to post
// to this board. - v1.5 thorn 001212
string *query_allowed() { return allowed; }

// If queue behavior is selected, then anytime the number of
// posts reaches max_posts, the first post on the board is
// removed on init(); - v1.5 thorn 001212
int check_queue() {
	int posts;

	posts = (int)BBOARD_D->get_num_posts(board_id);
    while(posts >= max_posts) {
		BBOARD_D->remove_message(board_id, 0);
		posts--;
    }
    return posts - max_posts;
}

// Set queue behavior in this board. - v1.5 thorn 001212
void set_queue() {
	if(max_posts) queue = 1;
}


int do_purge() {
  BBOARD_D->purge_read(board_id);
  return 1;
}
