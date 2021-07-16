//Coded by Lujke//
#include <std.h>
#include <daemons.h>
#include "../tunnel.h"
#define DAY 24000
#define TREASURY_D "/daemon/treasury_d"

inherit TUNNELS + "passroom.c";


void add_monsters();
int say_password(string str);
string long_desc();

void create(){
  ::create();
//  set_storage(1);
  set_name("devil's cauldron");
  set_short("%^BOLD%^%^BLACK%^d%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^v"
            +"%^BOLD%^%^RED%^i%^BOLD%^%^BLACK%^l's c%^RESET%^au%^BOLD%^"
            +"%^BLACK%^ldr%^RESET%^o%^BOLD%^%^BLACK%^n");
  set_long((:TO,"long_desc":));
  set_terrain(NAT_CAVE);
  set_travel(SLICK_FLOOR);
  set_property("indoors",1);
  set_property("light",2);
  
  set_smell("default","The air smells dank, with a sharp overlay of"
                     +" tin.");

  set_listen("default","There are quiet cr%^ORANGE%^a%^GREEN%^ckl%^RED%^e"
                      +"%^GREEN%^s from the %^RED%^f%^YELLOW%^i%^BOLD%^"
                      +"%^RED%^r%^RESET%^%^RED%^es%^GREEN%^ round about");

 set_exits( ([

      "northwest": TUNNELS+"tun19",
      "south": TUNNELS+"tun20",
    ]) );
  set_door("stone door",TUNNELS+"tun19","northwest",0); 

  set_door_description("stone door","a tall square door with a heavy"
                                   +" stone for a lintel");
  set_door("door",TUNNELS+"tun20","south",0); 

  set_items( ([ 
         ({ "wall", "walls"}):"%^BOLD%^%^BLACK%^The walls are of"
          +" black slate. They are smooth in places, but c%^RESET%^r"
          +"%^BOLD%^%^BLACK%^ack%^RESET%^e%^BOLD%^%^BLACK%^d and"
          +" un%^RESET%^e%^BOLD%^%^BLACK%^v%^RESET%^e%^BOLD%^%^BLACK%^n"
          +" in others. The lower part of the walls is stained %^RESET%^"
          +"%^RED%^red%^BOLD%^%^BLACK%^, finishing in a tide mark about"
          +" four feet up.%^RESET%^",

         ({ "brazier", "braziers"}):"The %^BOLD%^%^BLACK%^br%^RESET%^"
          +"%^RED%^a%^BOLD%^%^BLACK%^ziers%^RESET%^ are full of %^RESET%^"
          +"%^RED%^red %^BOLD%^%^RED%^h%^RESET%^%^RED%^o%^BOLD%^%^RED%^t"
          +" %^BOLD%^%^BLACK%^c%^RESET%^%^RED%^o%^BOLD%^%^RED%^a%^BOLD%^"
          +"%^BLACK%^ls%^RESET%^.",

         "blue door" : "%^RED%^A strange looking %^BOLD%^%^CYAN%^door"
          +"%^RESET%^%^RED%^, set on hinges but with no apparant lock,"
          +" handle or other means of opening it. There is some writing"
          +" on the frame above the door.%^RESET%^",

         "frame" : "%^RED%^The writing on the frame above the%^BOLD%^"
          +" %^CYAN%^blue door%^RESET%^%^RED%^ proclaims: %^YELLOW%^Tr"
          +"%^BOLD%^%^WHITE%^e%^YELLOW%^as%^RESET%^%^ORANGE%^u%^BOLD%^"
          +"%^YELLOW%^ry"

  ]) );

//  new(OBJ+"firepit")->move(TO);// Removed when setting the room to save
                                 // its inventory with set_storage - Lujke

  set_property("no teleport",1);
//  restore_room();
}

void init(){
  ::init();
  add_action("say_password", "say");
  add_action("open_blue_door", "open");
// if (!present("firepit", TO) {  new(OBJ+"firepit")->move(TO);}
}

void reset(){
  ::reset();
  if (!present("fiend")&& !present("rock devil"))
  {
    add_monsters();
  }
  remove_exit("treasury");
}

string long_desc(){
    return  "%^BOLD%^%^RED%^F%^YELLOW%^i%^RESET%^%^RED%^r%^BOLD%^"
           +"%^RED%^es%^RESET%^%^RED%^ burn br%^BOLD%^%^RED%^i%^RESET%^"
           +"%^RED%^ghtly all around this cavernous opening in the rock."
           +" A large %^BOLD%^%^BLACK%^f%^RESET%^%^%^RED%^i%^BOLD%^"
           +"%^RED%^rep%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^t%^RESET%^"
           +" %^RED%^has been built into the centre of the floor and"
           +" there are %^BOLD%^%^BLACK%^braziers%^RESET%^%^RED%^ of"
           +" burning %^BOLD%^%^BLACK%^c%^RESET%^%^RED%^o%^BOLD%^"
           +"%^RED%^a%^BOLD%^%^BLACK%^ls%^RESET%^%^RED%^ pushed up"
           +" against the walls. There is a pile of coals in one corner"
           +" of the cave, and a pile of %^RESET%^%^ORANGE%^wood%^RESET%^"
           +" %^RED%^in another. Torches"
           +" fl%^YELLOW%^i%^RESET%^%^RED%^cker in their brackets, adding"
           +" to the general h%^BOLD%^%^RED%^ea%^RESET%^%^RED%^"
           +"t%^RESET%^%^RED%^ and %^RESET%^l%^YELLOW%^i%^RESET%^ght"
           +" %^RED%^in the vicinity. At the far east end of the room is"
           +" a strange looking %^BOLD%^%^CYAN%^blue door%^RESET%^"
           +"%^RED%^. The%^BOLD%^%^BLACK%^ s%^RESET%^l%^BOLD%^"
           +"%^BLACK%^ate%^RESET%^%^RED%^ floor and walls are stained"
           +" red, finishing in an uneven tide line about four feet up.";
}

void add_monsters(){
  object ob;
  int i;
  for (i=0;i<2;i++)
  {
    ob = new(MOB+"rockdevil");
    ob->set_nogo(TUNNELS+"tun19");
    ob->set_speed(0);
    ob->move(TO);
  }
  ob = new(MOB+"pitfiend");
  ob->set_nogo(TUNNELS+"tun19");
  ob->move(TO);

}

int say_password(string str)
{
  object timer;
  string * quests;
  object speaker;
  int i;
  string password;
  string commword;
  if (!objectp(TO)){return 0;}

  password = query_password(query_day_number());
  commword = query_commword(query_day_number());
  timer = present("quest timer",TO);
  new("/cmds/mortal/_say.c")->cmd_say(str);

  if (interact(password, str))
  {
    new("/cmds/mortal/_say.c")->cmd_say(str);
    if (sizeof(all_living(TO))<1){return 1;}
/*
    for (i=0;i<sizeof(all_living(TO));i++)
    {
      if (objectp(all_living(TO)[i]))
      {
        if (interact((string)all_living(TO)[i]->query_name(),str))
        {
          speaker = all_living(TO)[i];
          break;
        }
      }
    }

    if (!objectp(all_living(TO)[i]))
    {
      tell_room(TO,"Who said that?");
      return 1;
    }
*/
    if(member_array("treasury",query_exits()) != -1)
    {
      tell_object(TP,"The door to the treasury is already open!");
      return 1;
    }

    tell_room(TO, "%^BOLD%^%^CYAN%^With a near silent sigh, the blue door"
                 +" swings smoothly open.");  
    add_exit(TUNNELS + "treasury", "treasury"); 
    // Check the player has not done the quest already, and that the
    // quest has not been done already today.
    quests = TP->query_quests();
    if(member_array("Treasury Quest",quests) != -1)
    {return 1;}
    if ( TREASURY_D->query_time() > time()-DAY) 
    { 
      tell_object(TP,"The quest has been completed recently. You will"
                    +" have to wait for another day to claim a reward.");
      return 1;
    }

    // If they haven't done the quest already, give them experience and a 
    // quest marker
                                      //**********************************
    TP->set_quest("Treasury Quest");//**add this line back in once the**
                                      //** quest is approved.*************
                                      //**********************************
    TP->add_exp(6200000);
    tell_object(TP,"%^BOLD%^%^CYAN%^You have gained experience for"
                  +" speaking in the %^BOLD%^%^RED%^inf%^RESET%^"
                  +"%^RED%^e%^BOLD%^%^RED%^rn%^RESET%^%^GREEN%^a"
                  +"%^BOLD%^%^RED%^l %^CYAN%^tongue of the %^BOLD%^"
                  +"%^BLACK%^D%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^v"
                  +"%^RED%^i%^BOLD%^%^BLACK%^ls%^BOLD%^%^CYAN%^ and"
                  +" gaining access to the %^YELLOW%^Archm%^RESET%^"
                  +"%^ORANGE%^a%^YELLOW%^gi's Tr%^RESET%^"
                  +"%^ORANGE%^ea%^YELLOW%^s%^BOLD%^%^WHITE%^u"
                  +"%^YELLOW%^ry%^CYAN%^!");
    TREASURY_D->set_time(time());
    return 1;
  }
  if (interact(commword, str))
  {
    tell_object(TP, "As you utter the words, you think you see the door"
                   +" begin to quiver.\nYou feel quite sure you have the"
                   +" correct password!\nBut nothing happens. You wonder"
                   +" if you are even speaking the right language.");  
    tell_room(TO, TPQCN+" gets a hopeful look on " + TP->QP +"face as "
                  +TP->QO + " speaks, but nothing happens and frustration"
                  +" settles on "+ TP->QP + " features.",TP);
    return 1;
  }

  if (interact("what's the password?", str)&&(string)TP->query_name()=="lujke")
  {
    tell_object(TP, query_password(query_day_number()));
    return 1;
  }
  return 1;
}

int open_blue_door(string str)
{
  if (interact("blue door", str))
  {
    
    tell_object(TP, "As you put your hands on the %^BOLD%^%^CYAN%^blue"
                   +" door %^RESET%^to open it, a blast of %^BOLD%^"
                   +"%^YELLOW%^e%^BOLD%^%^WHITE%^n%^YELLOW%^er%^CYAN%^g"
                   +"%^YELLOW%^y%^RESET%^ throws %^RED%^ex%^BOLD%^"
                   +"%^RED%^plo%^RESET%^%^RED%^des %^RESET%^from the door"
                   +" and throws you across the room!");
    tell_room(TO, "As "+TPQCN+" puts " + TP->QP + " hands on the %^BOLD%^"
                +"%^CYAN%^blue door %^RESET%^to open it, a blast of"
                +" %^BOLD%^%^YELLOW%^e%^BOLD%^%^WHITE%^n%^YELLOW%^er"
                +"%^CYAN%^g%^YELLOW%^y%^RESET%^ throws %^RED%^ex%^BOLD%^"
                +"%^RED%^plo%^RESET%^%^RED%^des %^RESET%^from the door"
                +" and throws " + TP->QO + " across the room!",TP);

    TP->do_damage(TP->return_target_limb(),50 + random(50)+ random(100));
    TP->add_attacker(TO);
    TP->continue_attack();
    if(objectp(TP))    TP->remove_attacker(TO);
    
    return 1;
  }
  return 0;
}

