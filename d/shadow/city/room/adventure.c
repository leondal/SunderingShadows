#include "../defs.h"
#include <daemons.h>
inherit "/std/rquestroom.c";

void create(){
  object ob;
  ::create();
  set_terrain(CITY);
  set_travel(PAVED_ROAD);
  set_property("light", 2);
  set_property("indoors", 1);
  set_short("Adventurers' Hall");
  set_long("%^BOLD%^Adventurers' Hall.\n"+
	"%^BOLD%^%^BLUE%^With its %^RESET%^%^BLUE%^shale"+
	"%^BOLD%^%^BLUE%^ tiled floor"+
	" and blue wooden walls%^RESET%^, the Adventurers Hall"+
	"%^BOLD%^%^BLUE%^ looks even more massive.  A %^WHITE%^"+
	"white stone%^BOLD%^%^BLUE%^ fireplace"+
	" is built into the western wall, nearly taking up "+
	"half of the wall.  Adorning the tall walls of the hall"+
	" are trophies and symbols of successful quests.  Heads"+
	" of strange beasts such as a %^RED%^chimera%^BLUE%^,"+
	"%^ORANGE%^ drake%^BOLD%^%^BLUE%^, and an %^BOLD%^%^WHITE%^"+
	"owlbear%^BLUE%^ grace the walls, with mounted"+
	" %^GREEN%^horns%^BLUE%^, %^YELLOW%^claws%^BLUE%^"+
	", %^MAGENTA%^weapons%^BLUE%^, %^CYAN%^pieces of "+
	"armor%^BLUE%^ and %^BLACK%^clothing%^BLUE%^.  These trophies are "+
	"symbols of past adventures.  Leather sofas and chairs are"+
	" arranged in small sitting areas around the large room. On"+
	" the northern wall a massive %^YELLOW%^wooden bulletin board"+
	"%^BLUE%^ is framed, providing the news of the city "+
	"Shadow.  In the center of the room a smooth %^RED%^cedar "+
	"column%^BLUE%^ rises to the roof.  The column is covered "+
	"with bits of paper of missing items that people are offering"+
	" rewards for.  There is also a list of %^YELLOW%^<bounties>"+
      "%^BLUE%^ nearby.\n  ");
	 set_items(([
      	({"cedar column","column"}) : "%^RED%^A large cedar column rises up"+
	" to the ceiling of the room.  The column is dotted with papers "+
	"of people offering rewards for lost or stolen items. \n%^BOLD%^"+
	"%^WHITE%^Please note these rewards are meant for people level 14-23 with <read list>.",
		({"bulletin board","wooden board"}) : "%^YELLOW%^Crafted out of oak, the bulletin "+
	"board is where the latest news and rumors of Shadow and the "+
	"surrounding lands are posted.  The board is extremely large, "+
	"allowing for plenty of space for news to be placed.  Fresher "+
	"pieces of paper are hammered into the board above older posting.",
      	({"sofas","chairs"}) : "%^BOLD%^%^BLUE%^Blue leather sofas"+
	" and chairs are arranged into a sitting area in this massive "+
	"hall.  Here is where adventures usually take some time out to "+
	"relax while looking for the newest rumors about danger and "+
	"riches to be found.  The sitting area is also a place where "+
	"many debates are started earning the nickname of 'Speaker's "+
	"Corner' from the locals in shadow.",
		({"trophies","symbols"}) : "%^CYAN%^Trophies brought back from "+
	"past adventures are proudly displayed around the hall.  Exotic"+
	" weapons from the Tsarven Empire, armor crafted by elves, and "+
	"even gnomish contraptions intermix with the mounted heads of "+
	"beasts.  Nearly every adventurer one day dreams of seeing some "+
	"new trophy they found hanging on the walls of the hall in Shadow.",
		({"fireplace"}) : "%^BOLD%^%^WHITE%^A white stone fireplace "+
	"helps to add warmth to the hall during the cold winter months.",
	]));

  set_quest_daemon("/daemon/quests_mid");
  set_smell("default","The cedar column masks the odors of adventurers.");
  set_listen("default","Numerous groups of people are engaged in chatter.");
  set_exits(
          (["northeast" : ROOMS"plaza"]) );
//  ob = new("std/bboard");
  ob = find_object_or_load("/d/shadow/mon/guards/board.c");
// New board replacement to auto-log seen posters.
  ob->set_name("board");
  ob->set_short("Adventurers' board");
  ob->set_long("The Latest News of Shadow");
  ob->set_id( ({ "board", "bulletin board", "reality board" }) );
  ob->set_board_id("quests_board");
  ob->set("long", "A wooden board where the adventurers "
      "who pass through Shadow post information on the "
      "oddities they have discovered.\n");
  ob->set_max_posts(50);
  ob->set_queue();
  ob->set_location(ROOMS"adventure");
}

void init(){
  ::init();
  add_action("quest_info","quest");
  add_action("mycauses","bounties");
}

int quest_info(){
  string *quests;
  int how_many;

  quests = TP->query_quests();
  how_many = sizeof(quests);
  while(how_many--){
    write("%^GREEN%^Quest %^WHITE%^#%^YELLOW%^ "+(how_many + 1)+" %^BLUE%^ "+quests[how_many]);
  }
  return 1;
}
int remove_message(string str) {
  write("Permission administratively denied.");
 return 1;
}
void reset(){
    ::reset();
    if(!present("shadow guard")) new("/d/shadow/mon/guardnew")->move(TO);
	if(!present("shadow guard 2")) new("/d/shadow/mon/guardnew")->move(TO);
}

private void swap(int i, int j, string *bounties){
  string tmp;

  tmp = bounties[i];
  bounties[i]=bounties[j];
  bounties[j]=tmp;
}

void sort(string *bounties){
  int i,j;

  for(j=0;j<sizeof(bounties);j++) {
    for(i=sizeof(bounties)-1;i>j;i--){
      if(bounties[i] < bounties[i-1]){
        swap(i-1,i,bounties);
      }
    }
  }
}

string evil_mycause(string *evil,object player) {
  int i;
  string myreturn, currentdesc, knownas;
  myreturn = "";
  if(sizeof(evil)){
    myreturn += "%^BOLD%^%^MAGENTA%^The following people must be stopped from committing their %^GREEN%^evil %^MAGENTA%^acts!\n";
    myreturn += "%^BOLD%^%^BLUE%^======================================================================%^RESET%^\n";
    for (i=0;i<sizeof(evil);i++) {
      currentdesc = USERCALL->user_call(evil[i],"getDefaultDescriptivePhrase");
      knownas = (string)player->knownAs(evil[i]);
      if(knownas == "" || !knownas) myreturn += "%^BOLD%^"+currentdesc+"\n";
      else myreturn += "%^BOLD%^"+capitalize(knownas)+", "+currentdesc+"\n";
    }
    myreturn += "%^BOLD%^%^BLUE%^======================================================================%^RESET%^\n";
  }
  else myreturn = "%^BOLD%^Nobody has been excessively evil lately.\n";
  return myreturn;
}

string good_mycause(string *good, object player) {
  int i;
  string myreturn, currentdesc, knownas;
  myreturn = "";
  if(sizeof(good)){
    myreturn += "%^BOLD%^%^MAGENTA%^The following people must be stopped from committing their %^GREEN%^good %^MAGENTA%^acts!\n";
    myreturn += "%^BOLD%^%^BLUE%^======================================================================%^RESET%^\n";
    for (i=0;i<sizeof(good);i++) {
      currentdesc = USERCALL->user_call(good[i],"getDefaultDescriptivePhrase");
      knownas = (string)player->knownAs(good[i]);
      if(knownas == "" || !knownas) myreturn += "%^BOLD%^"+currentdesc+"\n";
      else myreturn += "%^BOLD%^"+capitalize(knownas)+", "+currentdesc+"\n";
    }
    myreturn += "%^BOLD%^%^BLUE%^======================================================================%^RESET%^\n";
  }
  else myreturn = "%^BOLD%^Nobody has been excessively good lately.\n";
  return myreturn;
}

int mycauses() {
  string *evil, *good;
  evil = KILLING_D->query_evil_bounties();
  sort(evil);
  good = KILLING_D->query_good_bounties();
  sort(good);

  tell_object(TP,evil_mycause(evil,TP));
  tell_object(TP,good_mycause(good,TP));
  return 1;
}