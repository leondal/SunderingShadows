// voting.c
// Voting booth room inheritable by Bane@Shadowgate
#include <std.h>
#include <daemons.h>
#include <rooms.h>
inherit ROOM;
string room, title, vote, *name, *ivoted, *voptions;
mapping votes;
void create(){
    ::create();
    voptions = ({});
    votes = ([]);
    ivoted = ({});
    room = base_name(TO);
   seteuid("over");
    restore_object(room);
   seteuid(getuid());
    remove_property("light");
    set_property("light",2);
    if(!voptions) voptions = ({});
    if(!ivoted) ivoted = ({});
    if(!votes) votes = ([]);
}
void init(){
    ::init();
    add_action("me_vote","vote");
    add_action("me_view","view");
    add_action("add_option","addoption");
    add_action("rm_option","rmoption");
    add_action("add_title","addtitle");
    add_action("read_sign","read");
}
void read_sign(string str){
    if(!str) return notify_fail("Read what?\n");
    if(str != "sign") return 0;
    write("%^BOLD%^GREEN%^          Voting room options%^RESET%^");
    write("%^BOLD%^--------------------------------------------%^RESET%^");
    write("%^CYAN%^<view votes> : Allows you to check the voting polls");
    write("%^CYAN%^<vote> : Allows you to cast a vote (you cant vote more than once)");
    if(wizardp(TP)){
	write("%^CYAN%^<addoption> : Allows you to add another voting option");
	write("%^CYAN%^<rmoption> : Allows you to remove a current voting option");
	write("%^CYAN%^<addtitle> : Allows you to change whats being voted on");
    }
    return 1;
}
void add_title(string str){
    if(!wizardp(TP)) return 1;
    if(!str) return notify_fail("What would you like to add as a title?\n");
    title = str;
    seteuid("over");
    save_object(room);
  seteuid(getuid());
    return 1;
}
void add_option(string str){
    if(!wizardp(TP)) return 1;
    if(!voptions || !pointerp(voptions)) voptions = ({});
    if(!str) return notify_fail("What option would you like to add?\n");
    if(member_array(str, voptions) != -1) return notify_fail("That is already an option!\n");
    voptions = voptions + ({str});
    voptions = distinct_array(voptions);
   seteuid("over");
    votes[str] = 0;
  write("room = "+room);
    save_object(room);
  seteuid(getuid());
    return 1;
}
void rm_option(string str){
    if(!wizardp(TP)) return 1;
    if(!pointerp(voptions)) voptions = ({});
    if(!str) return notify_fail("What option would you like to remove?\n");
    if(member_array(str, voptions) == -1) return notify_fail("That is not yet an option!\n");
    voptions -= ({str});
    seteuid("over");
    save_object(room);
   seteuid(getuid());
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
    bane += "\n|%^BOLD%^       voting options       %^RESET%^|%^BOLD%^        current votes        %^RESET%^|";
    bane += "\n------------------------------------------------------------";
    for(i=0;i<j;i++){
	bane += "\n| "+arrange_string(voptions[i], 26)+" |   "+arrange_string(""+votes[voptions[i]], 25)+" |";
    }
    bane += "\n------------------------------------------------------------";
    write(bane);
    return 1;
}
void me_vote(){
    string bane;
    int i, j;
    j = sizeof(voptions);
    if(member_array(TPQN, ivoted) != -1) return notify_fail("You already voted!\n");
    bane = "%^BOLD%^BLUE%^************************************************************%^RESET%^";
    bane += "\n%^CYAN%^You are currently voting on: "+title+"%^RESET%^";
    bane += "\n%^BOLD%^BLUE%^************************************************************%^RESET%^";
    bane += "\n|%^BOLD%^       voting options       %^RESET%^|%^BOLD%^        current votes        %^RESET%^|";
    bane += "\n------------------------------------------------------------";
    for(i=0;i<j;i++){
	bane += "\n| "+arrange_string(voptions[i], 26)+" |   "+arrange_string(""+votes[voptions[i]], 25)+" |";
    }
    bane += "\n------------------------------------------------------------";
    write(bane);
    write("%^BOLD%^<Choices: Q, [your vote]>%^RESET%^");
    input_to("actual_vote",0,TP);
    return 1;
}
void actual_vote(string str, object player){
      string name;
    if(!str){
	input_to("actual_vote",0,player);
	return 1;
    }
    if(str == "Q") return 1;
    if(member_array(str, voptions) == -1){
	write("That is not an option!");
	input_to("actual_vote",0,player);
	return 1;
    }
    name = player->query_name();
    if(member_array(name, ivoted) == -1){
	ivoted += ({name});
    }
    votes[str]++;
    write("Thank you for voting!");
   seteuid("over");

    save_object(room);
   seteuid(getuid());
    return 1;
}
