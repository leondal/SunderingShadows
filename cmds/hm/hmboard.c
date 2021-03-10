#include <std.h>

inherit DAEMON;

object getBoard(){
    object ob;
    ob = present("board",find_object_or_load("/d/dagger/dumbyroom"));
    if (!objectp(ob)) {
        ob = new("std/bboard");
        ob->set_name("board");
        ob->set_id( ({ "board", "bulletin board", "reality board"}) );
        ob->set_board_id("hm_board");
        ob->set("short", "High Mortal Board");
        ob->set("long", "A large board where the high mortals of the realm may post and read information pertenant to them.");
        ob->set_max_posts(100);
       ob->set_ooc_board(1);
       ob->set_no_clean(1);
        ob->set_location("/d/dagger/dumbyroom.c");  
    }
    return ob;
}

int cmd_hmboard(string str){
    object board;
    string command, tail;
    int ret;

    if (!str || str == "") {
        str= "view";
    }

    if (sscanf(str, "%s %s", command, tail) != 2) {
        command = str;
    }

    board = getBoard();

    switch (command) {
    case "post":
        ret = board->post_message(tail);
        break;
    case "remove":
        ret =  board->remove_message(tail);
        break;
    case "read":
        ret =  board->read_message(tail);
        break;
    case "answer":
        ret =  board->reply_message(tail);
        break;
    case "edit":
        ret =  board->edit_message(tail);
        break;
    case "info":
        write(board->query_short());
        ret=1;
        break;
    case "view":
        write(board->query_long());
        ret= 1;
        break;

    }

    return ret;



}


int help(){
    write(
@OLI
         hmboard <command> <parameters>

         The hmboard is an ooc board that you can access at anytime. All board commands apply
    simply prefix with the hmboard command.
         hmboard post <subject>
         hmboard answer <##>
         hmboard read <##>
         hmboard remove <##>
         hmboard info  -> this will return to you the short description
         hmboard view  -> as if you are looking at it
OLI
         );
    return 1;

}
