#include <std.h>
#include <terrain.h>
#include "../tunnel.h"
inherit ROOM;


void attack_me(object targ);
int cast_spell (string str);
void add_monsters();
void enter_room(object ob);
void enter_room2();
void enter_room3();

int dancers;
int drowsearched;



void create() {
  // dancers is set prior to the ::create function, to ensure that the
  // mobs load when the room is first created. See the reset() function
  dancers = 3;
  ::create();
 

  set_property("indoors", 1);
  set_property("light", 2);
  set_terrain(NAT_CAVE);
  set_travel(SLICK_FLOOR);
  set_name("An oval cavern");
  set_short("An oval cavern");
  set_long("%^MAGENTA%^The tunnels widen out a little here, into an oval"
          +" cavern with %^BOLD%^%^BLACK%^s%^RESET%^l%^BOLD%^%^BLACK%^ate"
          +" walls%^RESET%^%^MAGENTA%^ and a high ceiling. A%^RED%^"
          +" f%^YELLOW%^i%^BOLD%^%^RED%^r%^RESET%^%^RED%^e %^MAGENTA%^is"
          +" burning in the middle of the room. Chained to one of the"
          +" walls is a sorry looking %^BOLD%^%^BLUE%^Ogre%^RESET%^"
          +"%^MAGENTA%^-%^BOLD%^%^BLUE%^Mage%^RESET%^%^MAGENTA%^. Tied"
          +" to a %^ORANGE%^stake%^MAGENTA%^ in the middle of the fire is"
          +" the slumped form of a very dead-looking%^BOLD%^%^BLACK%^"
          +" drow%^RESET%^%^MAGENTA%^.");

  set_items( ([ 
   ({ "wall", "walls"}):"%^BOLD%^%^BLACK%^The walls are of black"
                       +" s%^RESET%^l%^BOLD%^%^BLACK%^ate. They are"
                       +" smooth in places, but cracked and uneven in"
                       +" others, making it hard to know whether they"
                       +" have been worked or not..",

  "ceiling" : "the ceiling is so high up as to be out of sight.", 

  "floor" : "The floor is smooth, and relatively free of dirt. There are"
           +" scuff marks on it suggesting this place is frequently"
           +" travelled.",
  "drow" : "The %^BOLD%^%^BLACK%^drow%^RESET%^ hangs limply from the"
          +" %^ORANGE%^stake%^RESET%^. As you look more closely, you see"
          +" that it has not just been tied to the stake, but has been"
          +" %^BOLD%^%^CYAN%^impaled%^RESET%^. The pointed end of the"
          +" stake protrudes from its open mouth, while the other end"
          +" emerges from a most uncomfortable place."

 ]) );

  set_search("drow", (:TO, "search_drow":) );


  set_exits( ([ "northwest" : TUNNELS + "lair" ,
	          "south" : TUNNELS + "tun14",]) );
  set_pre_exit_functions(({"northwest",}),({"go_northwest",}));

}

void init()
{
  ::init();
  add_action("cast_spell", "cast" );
  add_action("cast_spell", "chant" );

}

void reset()
{
  ::reset();
  if (random(3)<2||dancers == 3) //dancers will only be set to 3 when the
                                 //room is first created and the mobs need
                                 //to definitely load
  {
    dancers = 1;
    drowsearched = 1;
    if (!present("rock devil") && !present("devilkin"))
    {
      add_monsters();
    }
  }
}

void search_drow()
{
  object * ob;
  if (present("devilkin")||present("rock devil"))
  {
    tell_object(TP, "%^BOLD%^%^RED%^The devils won't let you do that!");
    tell_room(TO, "%^BOLD%^%^RED%^" + TPQCN +"%^BOLD%^%^RED%^ goes to"
                 +" search the corpse of the drow, but the devils won't"
                 +" let " + TP->QO + " near!", TP);
    return;
  }
  if (drowsearched>0)
  {
    tell_object(TP, "You find a wadded up piece of paper that has been"
                   +" stuffed in the drow's mouth.");
    tell_room(TO,TPQCN + " seems to find something in the mouth of the"
                +" dead %^BOLD%^%^BLACK%^drow%^RESET%^", TP);
    new(OBJ+"drow_note")->move(TO);
    drowsearched = 0;
    return;
  }
 tell_object(TP, "There is nothing to be found on the corpse this time,"
                +" other than gore and general unpleasantness.");
 tell_room(TO,TPQCN + " spends a little time examining the gory corpse of"
                     +" the %^BOLD%^%^BLACK%^drow%^RESET%^", TP);
}

int go_northwest(string str)
{
  if (present("rock devil")||present ("devilkin"))
  {
    tell_object(TP, "%^BOLD%^%^RED%^The devils are in your way!\n");
    return 0;
  }
  return 1;
}


void enter_here(object ob)
{
  switch (ob->query_property("hummed"))
  {
  case 1:
    ob->set_property("hummed", -1);
  case 2:
    ob->set_property("hummed", -2);
  }
  if (dancers==1)
  {
    dancers = 0;
    call_out("enter_room2", 1);
  }
}


void enter_room2()
{
  int i;
  tell_room(TO, "%^RESET%^%^MAGENTA%^You can see that this is where the"
               +" %^BOLD%^%^BLUE%^music %^RESET%^%^MAGENTA%^has been"
               +" coming from. Four little %^RED%^D%^BOLD%^%^RED%^e"
               +"%^RESET%^%^RESET%^v%^BOLD%^%^BLACK%^i%^RESET%^%^RED%^lk"
               +"%^BOLD%^%^RED%^i%^RESET%^%^RED%^ns%^MAGENTA%^ are"
               +" dancing round a %^RED%^f%^YELLOW%^i%^RED%^r%^RESET%^"
               +"%^RED%^e%^RESET%^%^MAGENTA%^ to a tune beaten out by two"
               +" %^BOLD%^%^BLACK%^Rock D%^RESET%^%^RED%^e%^BOLD%^"
               +"%^BLACK%^v%^BOLD%^%^RED%^i%^BOLD%^%^BLACK%^ls%^RESET%^"
               +"%^MAGENTA%^.");
  if (present("devilkin"))
  {
    for (i=0;i<sizeof(all_living(TO));i++)
    {
      if ((string)all_living(TO)[i]->query_race()=="devilkin")
      {
        all_living(TO)[i]->dance(0);
      }
    }
  }
  call_out("enter_room3",2);
}

void enter_room3()
{
  tell_room(TO, "The occupants of the room seem to be intent on their"
               +" music and dancing!");
  
}

void add_monsters()
{
  object ob;
  int i;
  for (i=0;i<4;i++)
  {
    ob = new(MOB+"devilkin");
    ob->set("aggressive", 0);
    ob->move(TO);
  }
  for (i=0;i<2;i++)
  {
    ob = new(MOB+"rockdevil");
    ob->set("aggressive", 0);
    ob->move(TO);
  }
}

int cast_spell (string str)
{
  if (interact("wall of fire", str) || interact("stoneskin", str)
    || interact("faithful", str) || interact("monster", str) 
    || interact("animate",str)  || interact("conjure", str)
    || interact("incendiary",str) || interact("blink", str)
    || interact("sticks", str)  ||interact("aura", str)
    || interact("ice storm",str) || interact("lower", str)
     )
  {
    call_out("attack_me", 1, TP);
    return 0;
  }
  return 0;
}

void attack_me(object targ)
{
  int noticed;
  noticed =0;
  if (present("devilkin"))
  {
    present("devilkin")->spell_effect(0);
    present("devilkin")->kill_ob(targ);
    noticed = 1;
  }
  if (present("rock devil"))
  {
    present("rock devil")->kill_ob(targ); 
    noticed =1;
  }
  if (noticed)
  {
    tell_object(targ, "%^BOLD%^%^RED%^The %^BOLD%^%^BLACK%^d%^RESET%^"
                     +"%^RED%^e%^BOLD%^%^BLACK%^v%^RED%^i%^BOLD%^"
                     +"%^BLACK%^ls %^BOLD%^%^RED%^suddenly notice you and"
                     +" attack!");
    tell_room(TO,  "%^BOLD%^%^RED%^The %^BOLD%^%^BLACK%^d%^RESET%^"
                  +"%^RED%^e%^BOLD%^%^BLACK%^v%^RED%^i%^BOLD%^%^BLACK%^ls"
                  +" %^BOLD%^%^RED%^suddenly notice " 
                  + targ->query_cap_name() + " and attacks " + targ->QO 
                  +"!", targ);
  }
}

