#include <std.h>
#include <move.h>
#include <daemons.h>
#include "../../tecqumin.h"

inherit J_MAZE;

int snake_dead;

string long_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  add_item("vine", (:TO, "vine_desc":));
  add_item("tree", "The large tree looks like you could climb it");
  set_terrain(JUNGLE);
  set_travel(GAME_TRACK);
  set_climb_exits(([ "climb" : ({base_name(TO)[0..strlen(base_name(TO)) - 11] + "branch",2,6,200}) ]));
  snake_dead = 0;
  set_pre_exit_functions( ({"north", "northeast", "east", "southeast", "south", "southwest", "west", "northwest"}), ({"snake_grab","snake_grab","snake_grab","snake_grab","snake_grab","snake_grab","snake_grab","snake_grab"}) );
}
void init() {
   ::init();
 
}

int query_snake_dead(){
  return snake_dead;
}

void set_snake_dead(int t){
  snake_dead = t;
}

int snake_grab()
{
  object player1, player2;
  int i;
  if (snake_dead >0) return 1;
  i = 1;
  player1 = present("player", TO);
  if (!objectp(player1)) return 1;
  while(objectp(player1) && i<15 && (player1->query_true_invis()||(player1->query_invis() && !random(3))) )

  {
    i++;
    player1 = present("player " + i, TO);    
  }
  if(!objectp(player1)) return 1;
  i++;
  player2 = present("player " + i, TO);
  while(objectp(player2) && i<20 && (player2->query_true_invis()||(player2->query_invis() && !random(3))) )
  {
    i++; 
    player2 = present("player " + i, TO);    
  }
  if (!objectp(player2))
  {
    tell_object(TP, "As you walk past the hanging vine, it loops around you and drags you up into the branches above.");
    tell_object(TP, "Too late, you realise it's not a vine at all, but the tail of an enormous snake!");
    tell_room(TO, TPQCN + " %^RESET%^is suddenly grabbed by what looks like a living vine, and whisked up into the branches above!", TP);
    TP->move(base_name(TO)[0..strlen(base_name(TO)) - 11] + "branch");
    present("anaconda", find_object_or_load(base_name(TO)[0..strlen(base_name(TO)) - 11] + "branch"))->constrict(TP);
    return 0;
  }
  return 1;
}

int other_players(object player) 
{
  object * critters;
  int i, count;
  critters = all_living(TO);
  count = sizeof(critters);
  if(count<1) return 0;
  for(i=0;i<count;i++)
  {
    if(critters[i]->id("player") && !critters[i]->query_true_invis() && critters[i] != player)
    {
      return 1;
    }
  }
  return 0;
}

string vine_desc()
{
  object room;
  room = find_object_or_load(base_name(TO)[0..strlen(base_name(TO)) - 11] + "branch");
  if (present("anaconda", room))
  {
    return "On closer inspection, the vine looks rather more like the long tail of"
      +" a frighteningly %^GREEN%^large snake%^RESET%^. The rest of the body"
      +" disappears above your head in the branches of a %^GREEN%^tree%^RESET%^.";
  }
  return "You can't see that here";
}

void reset()
{
  object room;
  ::reset();
  room = find_object_or_load(base_name(TO)[0..strlen(base_name(TO)) - 11] + "branch");
  if (objectp(room))
  {
    room->reset();
  }
  if (random(2)) snake_dead = 0;
}

string long_desc(){
  string result;
  result = ::long_desc();
  if (present("snake", find_object_or_load(base_name(TO)[0..strlen(base_name(TO)) - 11] + "branch")))
  {
    result += " A vine hangs down from one of the tree branches.";
  }
  return result;
}
