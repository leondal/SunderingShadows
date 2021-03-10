// voting.c
// Voting booth room inheritable by Bane@Shadowgate
#include <std.h>
#include <daemons.h>
#include <rooms.h>
inherit ROOM;
string room, title, *voted, *voptions;
void create(){
    ::create();
    voptions = ({});
    voted = ({});
    room = base_name(TO);
    //restore_object(room);
     if(!voptions) voptions = ({});
    if(!voted) voted = ({});
}
void init(){
    ::init();
    add_action("me_vote","vote");
    add_action("me_view","view");
    add_action("add_option","addoption");
    add_action("rm_option","rmoption");
    add_action("add_title","addtitle");
}
void add_title(string str){
    if(!wizardp(TP)) return 1;
    if(!str) return notify_fail("What would you like to add as a title?\n");
    title = str;
    save_object(room);
    return 1;
}
void add_option(string str){
    if(!wizardp(TP)) return 1;
   if(!voptions || !pointerp(voptions)) voptions = ({});
    if(!str) return notify_fail("What option would you like to add?\n");
    if(sscanf(str, "%s", voptions) != 1) return notify_fail("That is already an option!\n");
    voptions += ({str});
//
    save_object(room);
    return 1;
}
void rm_option(string str){
    if(!wizardp(TP)) return 1;
    if(!str) return notify_fail("What option would you like to remove?\n");
    if(sscanf(str, "%s", voptions) != 1) return notify_fail("That is not a current option!\n");
    voptions -= ({str});
    save_object(room);
    return 1;
}
void me_view(string str){
    string bane;
    int i, j;
    if(!str) return 0;
    if(str != "votes") return 0;
    j = sizeof(voptions);
    bane = "%^BOLD%^BLUE%^************************************************************%^RESET%^";
    bane += "\n%^CYAN%^You are currently voting on: "+title+"%^RESET%^";
    bane += "\n%^BOLD%^BLUE%^************************************************************%^RESET%^";
    for(i=0;i<j;i++){
	bane += "\n| "+voptions[i]+" | ";
    }
    write(bane);
    return 1;
}
