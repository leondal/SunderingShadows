//Assassins guild hall coded by Bane//
#include <std.h>
#include <daemons.h>
#include "/realms/grendel/grendel.h"

inherit ROOM;
string *registered;

#define SAVEFILE "/d/save/assrings"
#define RINGFILE "/d/laerad/parnelli/cguild/assassin/rings/aring"
#define MAXRINGS 15

void get_ring(object who);
int add_member(string str);

void create(){
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(DIRT_ROAD);
    registered = SAVE_D->query_array("assassin_list");
    set_name("Assassins guild");
    set_short("Assassins guild");
    set_long(
	"You are standing in some sort of holed up office.  This must "+
	"the grand master assassins quarters.  It is rumored he works "+
	"his business right out of this guild hall.  There is a small "+
	"wooden desk and chair in one corner of the room, covered in cob "+
	"webs and dust.  A registry sits open on the desk.  A message "+
	"board is on the wall near the desk, a personal bounty board of "+
	"the most feared killer in the realm. You can probably get a "+
      "new <ring> here if you need one."
    );
    set_property("indoors",1);
    set_property("light",2);
//    set_property("no teleport", 1);  removing safe haven from guild halls *Styx*  4/6/03
    set_listen("default","The room is deathly silent.");
    set_smell("default","The room smells strangely fresh and untainted.");
    set_items( ([
	({"board"}):"There are a few names scribled illegibly on the board.",
	({"desk"}):"The desk is covered in dust, it is obviously not used "+
	    "very often.",
	({"registry"}):"This has the names of the Assassins who registered "+
	    "here in the guild hall.  You can <register> if you wish."
    ]) );
    set_exits( ([
	"north":"/d/laerad/parnelli/cguild/assassin/aguild1"
    ]) );
}
void init(){
    ::init();
    add_action("read","read");
    add_action("register","register");
    add_action("new_ring","ring");
}

int read(string str){
    int i;
    if(!str || str != "registry") return 0;
    tell_room(TO,TPQCN+" reads the registry.",TP);
    write("This book contains the names of Assassins who have officially registered.");
    write("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    registered = SAVE_D->query_array("assassin_list");
    sort(registered);
    for(i=0;i<sizeof(registered);i++)
	write("%^BOLD%^"+capitalize(registered[i]));
    return 1;
}

int register(){
    if(!TP->query("is_assassin") && !TP->is_class("assassin")) return notify_fail("You cant find a pencil.\n");
    if(TO->add_member(TPQN)){
	write("You write your name down in the registry.");
	return 1;
	} else {
	notify_fail("You are already registered!\n");
    }
}

int add_member(string str){
    registered = SAVE_D->query_array("assassin_list");
    if(member_array(str, registered) == -1){
      SAVE_D->set_value("assassin_list", str);
      return 1;
    }
    return 0;
}

void remove_member(string str){
    registered = SAVE_D->query_array("assassin_list");
    if(member_array(str, registered) != -1){
      SAVE_D->remove_name_from_array("assassin_list", str);
      return 1;
    }
    return 0;
}

int new_ring(string str){
   if(!TP->query("is_assassin") && !TP->is_class("assassin")) return 0;
   if(present("assassin ring",TP)){
      write("You already have a guild ring.");
      return 1;
   }
   if(!TP->query_funds("gold",500)){
      write("You think we just give these away? 500 gold.");
      return 1;
   }
   TP->use_funds("gold",500);
   get_ring(TP);
   return 1;
}

void get_ring(object who){
   string *key;
   object ring;
   mapping owners;
   int i;
   
   if(file_exists(SAVEFILE+".o")){
      ring = new(RINGFILE+"0");
      ring->restore_me(SAVEFILE);
      owners = ring->query_ring_owners();
      key = keys(owners);
      if(sizeof(key) < MAXRINGS){
         for(i=1;i<MAXRINGS+1;i++){
            if(member_array(RINGFILE+i,key) != -1) continue;
            if(!random(sizeof(key)+2)) 
               ring = new(RINGFILE+i);
            else
               ring = new(RINGFILE);
            break;
         }
      }
      else{
         ring = new(RINGFILE);
      }
   }
   else{
      if(random(20)) 
         ring = new(RINGFILE+"1");
      else
         ring = new(RINGFILE);
   }
   ring->move(who);
   return;
}

