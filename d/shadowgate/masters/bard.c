
//bard.c ... for the masters

#include <std.h>
inherit "/d/shadowgate/newmasters/masters.c";

void bardness();

void create(){
  ::create();
  set_name("Bard master");
  set_id(({"Bard master", "bard", "master"}));
  set_short("Master Entertainer");
  set_long(
@OLI
  This is a grand figure, many times your greatest hope. Yet
his job is simple now.... he is to make you ready for the 
world of shadowgate and your quest to make a name for you as a 
bard.
OLI
   );
  set_class("bard");
}

void init(){
  ::init();
  //To be adjusted as needed
}


void kit_sub_class(){
  write("There are no sub classes for bards at this time.");
  return 1;
}

void help_file(){
  write("The bard lives by wits and charm.");
  write(
@OLI
 You are granted several abilities:
 
 detect -> this will allow you to detect noise in the next room
 sneak  -> this will allow you to move silently to other rooms
 steal -> This allows you to steal items from others
 pp -> allows you to steal money from others.
 skills -> this command must be used to improve your skills upon 
           gaining levels
 charm -> this command allows you to adjust the reactions of 
          interactive monsters and to determine whether a monster
          will attack the rest of your party, if performed before 
          the party enters
 rally -> this allows you to make your friends fight better and react 
          better to special attacks
OLI
 );
  return 1;
}

void done()
{
  bardness();
  return 1;
}
  
int bardness() 
{
  object ob, ob2;

  write("The master hands you a large tome and a bag.");
  ob2 = new("/d/magic/bard_comp_book");
  ob2->move(TP);
  TP->add_mp(TP->query_max_mp());
  pick_diety();
  return 1;
}