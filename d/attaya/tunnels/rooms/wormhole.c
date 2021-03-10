
#include <std.h>
#include "../tunnel.h"

inherit BTUNNEL;

#define NORTH 1
#define SOUTH 0

int direction;
int progress;
int facing;
int worm;
void new_worm();
string long_desc();
object * hiders;

void create(){
    ::create();
      hiders = ({});
      worm = 0;
	progress = 0;
	direction =3;
      set_name("A slimy wormhole");
      set_short("A slimy wormhole");
	set_long((:TO,"long_desc":));

      set_items( ([ 
  ({ "wall", "walls"}):"%^BOLD%^%^MAGENTA%^The w%^RESET%^%^MAGENTA%^a"
                      +"%^BOLD%^%^MAGENTA%^lls are pink and soft and"
                      +" sl%^RESET%^%^MAGENTA%^i%^BOLD%^%^MAGENTA%^my as"
                      +" they press in around you.", 
  ]) );


    set_exits(([
                "south":TUNNELS + "tun09",
		    "north":TUNNELS + "lair",
        ]));
    set_property("no teleport",1);

}

void init(){
  ::init();
  add_action("wield","wield");
  add_action("head_north", "north");
  add_action("head_south", "south");
}

object * query_hiders(){
  return hiders;
}

void eject(object ob){
  object room;
  switch (random(2)){
  case 0:
    room = find_object_or_load(TUNNELS + "tun09");
  case 1:
    room = find_object_or_load(TUNNELS + "lair");
  }
  if (!objectp(room)){
    tell_object(ob, "%^BOLD%^%^RED%^There's been an error with one of the exits! Please leave this room immediately, and make a bug"
                   +" report on the wormhole!");
    return;
  }
  tell_object(ob, "%^BOLD%^%^CYAN%^Overcome with a sudden claustrophobia, you wriggle out of the wormhole!");
  tell_room(room, ob->QCN + "%^BOLD%^%^CYAN%^ drops into the room from a hole in the wall!");
  ob->move(room);
}

int is_empty(){
  int i;
  if (sizeof(all_living(TO))==0)
  {
    return 1;
  }
  for(i=0;i<sizeof(all_living(TO));i++)
  {
    if (all_living(TO)[i]->is_player())
    {
      return 0;
    }
  }
  return 1;
}

void reset(){
  int i;
  object * critters;
  ::reset();
  // dump out anyone who's been here since the last reset
  if (sizeof(hiders) > 0 ){
    for (i=0;i<sizeof(hiders);i++){
      if (present(hiders[i], TO)){
        eject(hiders[i]);
      }
    }
    hiders = ({});
  }
  // add any player still present to the list of hiders
  critters = all_living(TO);
  if (sizeof(critters)>0){
    for (i=0;i<sizeof(critters);i++){
      if (interactive(critters[i]) && (int)critters[i]->query_true_invis() !=1) {
        hiders += ({critters[i]});
      }
    }
  }
  // reset vars
  if (is_empty())
  {
    progress = 0;
    direction =3;
  }
  if (random(1)<1)
  {
    worm = 0;
  }
}


string long_desc(){
        return "%^BOLD%^%^MAGENTA%^The cold, hard chill of the rock has"
              +" vanished, and the %^BOLD%^%^RED%^pulsating%^BOLD%^"
              +"%^MAGENTA%^ walls around you suddenly feel disgustingly"
              +" soft, warm and damp like a digestive tract. There is"
              +" little to do but carry on, or try to squirm backwards"
              +"%^RESET%^";
}






int wield(string str){
  if(present(str, TP)->query_size()>1) {
    tell_object(TP, "%^BOLD%^%^RED%^You fumble for your " 
                   + present(str, TP)->query_name() + "%^BOLD%^%^RED%^,"
                   +" but there's just no room to wield it here!");

    tell_object(TP, "You'll have to try a smaller weapon, or fight empty"
                   +" handed.");
    return 1;
  }
  return 0;
}

void enter_south(){
  facing = NORTH;
  direction = NORTH;
  progress = 0;
}
void enter_north()
{
  facing = SOUTH;
  direction = SOUTH;
  progress = 9;
}

void exit_north()
{
  object ob;
  if (direction == SOUTH){
    return;
  }
  tell_object(TP, "%^MAGENTA%^You slip out of the %^BOLD%^"
               +"%^MAGENTA%^tunnel%^RESET%^%^MAGENTA%^ to the north.\n");

  ob = present("rock devil", find_object_or_load(TUNNELS + "lair"));
  if (ob){
    ob->set_aggressive(0);
    tell_object(TP, "The %^BOLD%^%^BLACK%^d%^RESET%^%^RED%^e%^BOLD%^"
                   +"%^BLACK%^v%^RED%^i%^BOLD%^%^BLACK%^l%^RESET%^"
                   +" doesn't seem to have noticed you arriving from this"
                   +" direction!\n");
  }
  progress = 0;
  TP->move_player(TUNNELS + "lair");
}

int head_north(string str){
  string dir;
  if (facing == SOUTH){
    dir = "backwards";
  }
  if (facing == NORTH){
    dir = "forwards";
  }
  if (progress ==5){
    new_worm();
  }
  if (progress > 9){
    direction = NORTH;
    exit_north();
    return 1;
  }
  if (direction == SOUTH){
    tell_object(TP, "%^BOLD%^%^MAGENTA%^You begin squirming in the other"
                   +" direction.%^RESET%^");
  }
  tell_object(TP, "%^MAGENTA%^You crawl " + dir + " on your stomach,"
                 +" heading north along the %^BOLD%^%^MAGENTA%^fl"
                 +"%^RESET%^%^MAGENTA%^e%^BOLD%^%^MAGENTA%^shy t%^RESET%^"
                 +"%^MAGENTA%^u%^BOLD%^%^MAGENTA%^nnel.%^RESET%^");
  direction = NORTH;
  call_out("head_north2",3, TP);
  return 1;
}

void head_north2(object * ob)
{
  if (!objectp(ob)){return;}
  if (!present(ob,TO)){return;}
  if (direction == SOUTH){return;}
  if (present("worm",TO)&& facing==NORTH) {
    tell_room(TO, "%^MAGENTA%^The w%^BOLD%^%^MAGENTA%^o%^RESET%^"
                 +"%^MAGENTA%^rm is blocking your way!\n");
    return;
  }

  progress += 1;

  if (progress ==5){
    new_worm();
  }

  if (progress > 9) {
    exit_north();
    return;
  }
  else{
    tell_object(ob, "%^BOLD%^%^MAGENTA%^You manage to edge a little"
                   +" further north on your stomach, heading for the"
                   +" exit.%^RESET%^");
    call_out("head_north2",3,ob);
  }
}


void exit_south(){
  if (direction == NORTH){
    return;
  }
  tell_object(TP, "%^MAGENTA%^You slip out of the %^BOLD%^"
                 +"%^MAGENTA%^tunnel%^RESET%^%^MAGENTA%^ to the south.");
  progress = 0;
  TP->move_player(TUNNELS + "tun09");
}


int head_south(string str){
  string dir;
 if (facing == NORTH){
    dir = "backwards";
  }
  if (facing ==SOUTH){
    dir = "forwards";
  }
  if (progress ==5){
    new_worm();
  }
  if (progress < 1){
    direction = SOUTH;
    exit_south();
    return 1;
  }
  if (direction == NORTH){
    tell_object(TP, "%^BOLD%^%^MAGENTA%^You begin squirming in the other"
                   +" direction.%^RESET%^");
  }
  tell_object(TP, "%^MAGENTA%^You begin crawling " + dir + " on your"
                 +" stomach, heading south along the %^BOLD%^"
                 +"%^MAGENTA%^fl%^RESET%^%^MAGENTA%^e%^BOLD%^"
                 +"%^MAGENTA%^shy t%^RESET%^%^MAGENTA%^u%^BOLD%^"
                 +"%^MAGENTA%^nnel.%^RESET%^");
  direction = SOUTH;
  call_out("head_south2",3, TP);
  return 1;
}

void head_south2(object * ob){
  if (!objectp(ob)){return;} 
  if (!present(ob,TO)){return;}
  if (direction == NORTH){return;}
  if (present("worm",TO)&& facing==SOUTH){
    tell_room(TO, "%^MAGENTA%^The w%^BOLD%^%^MAGENTA%^o%^RESET%^"
                 +"%^MAGENTA%^rm is blocking your way!\n");
    return;
  }
  progress -= 1;
  if (progress ==5){
    new_worm();
  }
  if (progress < 1){
    exit_south();
    return;
  }
  else{
    tell_object(ob, "%^BOLD%^%^MAGENTA%^You manage to edge a little"
                   +" further south on your stomach, heading for the"
                   +" exit.%^RESET%^");

    call_out("head_south2",3,ob);
  }
}

void new_worm(){
  if (worm ==0){
    tell_room(TO, "%^MAGENTA%^A %^BOLD%^%^RED%^huge %^RESET%^"
                 +"%^MAGENTA%^sl%^BLUE%^i%^MAGENTA%^my w%^BOLD%^"
                 +"%^MAGENTA%^o%^RESET%^%^MAGENTA%^rm wriggles into the"
                 +" tunnel and %^BOLD%^%^RED%^attacks%^RESET%^"
                 +"%^MAGENTA%^!");
    new(MOB+"tunnelworm.c")->move(TO);
  }
  worm =1;
}
