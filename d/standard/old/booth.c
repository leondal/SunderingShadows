//     /d/standard/booth.c
//     from the Nightmare mudlib
//     voting booth
//     created by Gregon@Nightmare Jan 1994
 
#include <daemons.h>
inherit "std/room";
 
int a,b;
mapping vote;
 
void create() {
  ::create();
  set("short", "Nightmare referendum room");
  set_property("light", 2);
  set_property("indoors", 1);
  set("long",
       "This is the referendum room of Nightmare.  Players come here to vote "
       "on issues that the wizards desire input on.  The current voting "
       "question is posted on the wall <read question> will display it.);
    
  set_exits( (["down" : "/d/standard/adv_main"]) );
  vote=([]);
  restore_object("/d/standard/data/votes");
}
 
void init() {
  ::init();
  add_action("vote", "vote");
  add_action("read", "read");
  if(archp(this_player())) add_action("check", "check");
  
}
 
int vote(string str) {
    string me;
 
    me=(string)this_player()->query_name();
    if(str!="a" && str!="b") {
       notify_fail("You may only vote for a or b.\n");
       return 0;
    }
    if(MULTI_D->non_voter(me)) {
       write("You are listed as a second character.  You may not vote.");
       return 1;
    }
    if(vote[me]) {
       write("You have already voted.");
       return 1;
    }
    if(str=="a") {
      vote[me]="a";
      a++;
      write("Vote counted.  Thank you.");
      save_object("/d/standard/data/votes");
      return 1;
    }
    if(str=="b") {
      vote[me]="b";
      b++;
      write("Vote counted.  Thank you.");
      save_object("/d/standard/data/votes");
      return 1;
    }
    
}
 
int read(string str) {
    if(!str || str != "question") return 0;
    write("The current voting question is this:\n\n"
          "Should an immortal's other character be permitted to player kill?\n"
          "\nYou may vote one of two ways:\n\n"
          "A. Immortal's seconds should be permitted to player kill as normal "
             "players.\n"
          "B. Immortal's seconds should only be permitted to defend themselves, "
          " and never allowed to initiate combat with another player.\n"
	  " NOTE this includes releasing Fangthanes and bone demons,\n"
	  " and other such creatures with intent to use them to kill \n"
	  " other players.\n"
          "\nTo vote for one of these choices, type <vote a> or <vote b>.  Of "
          "course you may only vote once, and seconds are not allowed to vote."
         "\n\nPlease note: this rule would apply to all wizards regardless of "
         "whether the wizard is the player's first or second character."
          );
    return 1;
}
 
int check(){
   write("A: "+a+"\nB: "+b);
   return 1;
}
