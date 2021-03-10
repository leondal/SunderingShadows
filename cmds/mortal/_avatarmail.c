//shamelessly adapted from hmboard command to save spamming mail of inactive
//immortals and streamline handling of player requests  *Styx*  6/2002

#include <std.h>

inherit DAEMON;

object getBoard(){
    object ob;
    ob = present("avatarmail board",find_object_or_load("/d/dagger/avaboard2"));
    if (!objectp(ob)) {
        "/d/dagger/avaboard2"->reset();
    }
    return ob;
}

int cmd_avatarmail(string str) {
    object board;
    board = getBoard();
    if(!str)
        return notify_fail("Please specify a title for your message.  The correct syntax is <avatarmail>  <title of message>\n");

    if(strlen(str) > 30)
        return notify_fail("Please be more brief on the title, less than 30 characters.\n  You can elaborate in the editor.\n");
    
    tell_object(TP,"You are now in edit to post a message to a board "
           "that the immortals read.  Note:  They may not respond to every "
           "request and may also take some time discussing some requests "
           "before responding.\nPlease use this only if you have not been "
           "able to get an immortal to respond on lines OR they have "
           "suggested this means of submitting your question or request.\n"
           "The title is set to:  %^BOLD%^%^YELLOW%^"+str);
    board->post_message(str);
    return 1;
}

int help(){
  write(
"
%^CYAN%^NAME%^RESET%^

avatarmail - commune with avatars

%^CYAN%^SYNOPSIS%^RESET%^

avatarmail %^ORANGE%^%^ULINE%^TITLE%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^
  
This command is to allow mortals to post a message with %^ORANGE%^%^ULINE%^TITLE%^RESET%^ to a board that the immortals read. They may not respond to every request or question and may take some time discussing a request/question before responding.

Mortals cannot view, read, or access the board.
  
%^CYAN%^SEE ALSO%^RESET%^

see also:  pkmail, lawmail, game.
"
      );
  return 1;
}
