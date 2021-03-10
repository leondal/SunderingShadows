#include <std.h>
#include <daemons.h>
#include "../tunnel.h"

inherit TUNNELS + "mouthroom.c";
int digging;

int taste_blood(string str);
int drink_blood(string str);
int dig_deeper(string str);
void dig_deeper2(object ob);
void dig_deeper3(object ob);
int searches(string str);
void crawl_hole(string str);

void create(){
  // searched is set before the ::create function, to ensure that the mob  
  // is loaded every time on first creation of the room. See the reset
  // function
  digging =5;
  ::create();
  digging = 0;
  set_name("A grim lair");
  set_short("%^BOLD%^%^BLACK%^A grim lair");
  
  set_property("indoors",1);
  set_property("light",2);

  set_smell("default","The air smells dank, with a sharp overlay of"
                     +" tin.");

  set_listen("default","There are distinct sounds of scrabbling and"
                     + " scratching up above, and the music is louder"
                     + " than ever here.");

  set_exits( ([
        "southeast":TUNNELS + "tun15",
    ]) );

  set_items( ([ 
    ({ "wall", "walls"}):"%^BOLD%^%^BLACK%^The walls are of"
                        +" black slate. They are smooth in places, but"
                        +" c%^RESET%^r%^BOLD%^%^BLACK%^ack%^RESET%^e"
                        +"%^BOLD%^%^BLACK%^d and un%^RESET%^e%^BOLD%^"
                        +"%^BLACK%^v%^RESET%^e%^BOLD%^%^BLACK%^n in"
                        +" others. However, it is clear that this cavern"
                        +" is not entirely natural.",

  "ceiling" : "%^BOLD%^%^BLACK%^Vertical columns rise from the walls and"
             +" reach up towards the roof. They spread inwards, giving an"
             +" effect like a vaulted cathedral ceiling", 

  "hole": "%^BOLD%^%^BLACK%^The hole is dark and damp looking, but it"
         +" seems like you would be able to %^RESET%^crawl"
         +"%^BOLD%^%^BLACK%^ through it",

  ({ "pile", "piles", "shale"}):"%^BOLD%^%^BLACK%^There are piles of"
                               +" loose %^BOLD%^%^BLACK%^s%^RESET%^h"
                               +"%^BOLD%^%^BLACK%^al%^RESET%^e%^BOLD%^"
                               +"%^BLACK%^ around the edges of the room,"
                               +" backing onto the walls.",

  "floor" : "The floor is smooth, and relatively free of dirt. A pool of" 
           +" %^BOLD%^%^BLACK%^black liquid%^RESET%^ sits in the middle"
           +" of the room, its surface patterned with %^BOLD%^%^BLACK%^r"
           +"%^RESET%^i%^BOLD%^%^BLACK%^ppl%^RESET%^e%^BOLD%^%^BLACK%^s.",

  ({"cracks","fissures"}):"%^BOLD%^%^BLACK%^the larger cracks look big"
                         +" enough for something to go into of come out"
                         +" of, but all except the one in the south wall"
                         +" are way up out of reach.%^RESET%^", 

({ "crack", "fissure"}):"%^BOLD%^%^BLACK%^There is one hole in the south"
                       +" wall that looks big enough to scramble into."
                       +"%^RESET%^", 

({ "pool", "black pool"}): "%^BOLD%^%^BLACK%^A strange pool of black"
                          +" liquid in a depression on the floor. It"
                          +" looks %^RESET%^%^MAGENTA%^viscous %^BOLD%^"
                          +"%^BLACK%^and has a %^GREEN%^s%^RESET%^"
                          +"%^GREEN%^h%^BOLD%^%^GREEN%^arp%^BOLD%^"
                          +"%^BLACK%^ smell. A thick %^RESET%^"
                          +"%^RED%^crust%^BOLD%^%^BLACK%^ has dried"
                          +" around the edges.%^RESET%^",
  ]) );

  set_search("pool","Looking more closely at the pool, you realise the %"
                   +"^BOLD%^%^BLACK%^black liquid%^RESET%^ is the"
                   +" %^RED%^blood%^RESET%^ of some unknown creature." );

  set_search("pile","Digging into one of the loose piles of %^BOLD%^"
                   +"%^BLACK%^s%^RESET%^h%^BOLD%^%^BLACK%^ale%^RESET%^,"
                   +" you uncover a %^BOLD%^%^BLACK%^black skinned hand"
                   +"%^RESET%^, attached to an %^BOLD%^%^BLACK%^arm"
                   +"%^RESET%^ disappearing further into the stuff. You"
                   +" could probably dig deeper to uncover the rest of"
                   +" the corpse." );

  set_search("shale","Digging into one of the loose piles of %^BOLD%^"
                    +"%^BLACK%^s%^RESET%^h%^BOLD%^%^BLACK%^ale%^RESET%^,"
                    +" you uncover a %^BOLD%^%^BLACK%^black skinned hand"
                    +"%^RESET%^, attached to an %^BOLD%^%^BLACK%^arm"
                    +"%^RESET%^ disappearing further into the stuff. You"
                    +" could probably dig deeper to uncover the rest of"
                    +" the corpse." );

set_search("corpse", (: TO, "search_corpse" :) );

  set_property("no teleport",1);
}

void init(){
  ::init();
  add_action("taste_blood","taste");
  add_action("drink_blood","drink");
  add_action("dig_deeper","dig");
  add_action("crawl_hole","crawl");
  add_action("crawl_hole","enter");
  add_action("crawl_hole","scramble");
  find_object_or_load(TUNNELS + "wormhole.c");
}

void reset(){
  ::reset();
  if (!present("rock devil"))
  {
    if (random(3)<1||digging == 5)
    {
      new(MOB+"rockdevil")->move(TO);
    }
  }
  digging = 0;
}

string long_desc(){
  return "%^BOLD%^%^BLACK%^The dark walls open out into a larger"
            +" cavern here. Piles of loose"
            +" s%^RESET%^h%^BOLD%^%^BLACK%^ale and slate creep outwards"
            +" from the walls like giant feet, and the air tastes of"
            +" %^RESET%^tin%^BOLD%^%^BLACK%^. Above them, vertical"
            +" columns reach up towards the roof and the spread inwards"
            +" in a strange imitation of a cathedral ceiling. However,"
            +" instead of any religious altar, there is a pool of black"
            +" liquid in the middle of the room, its surface patterned"
            +" with ripples. On the walls, %^BOLD%^%^RED%^torches%^BOLD%^"
            +"%^BLACK%^ gutter in their brackets, spitting and hissing"
            +" occasionally. There is a small hole a few feet off the"
            +" ground in the south wall.";
}

int search_corpse(){
  if (!objectp(TO)||!objectp(TP)){return 0;}
  if (present("barbazu corpse", TO)){
    if (present("barbazu corpse", TO)->query_searched() >0) {
      tell_object(TP, "The corpse has already been searched. There's"
                     +" nothing more to find");
      tell_room(ETP,TPQCN + " searches the grisly corpse of a barbazu"
                    +" devil but seems disappointed", TP);
      return 1;
    }
    tell_object(TP,"You find something of interest on the corpse.");
    tell_room(ETP,TPQCN + " searches the grisly corpse of a barbazu devil"
                     +" and seems to find something", TP);
    switch(random(10)){
    case 0:
      new(OBJ + "bracelets_o_c.c")->move(TO);
      break;
    case 1..7:
      new(OBJ + "gem.c")->move(TO);
      new(OBJ + "gem.c")->move(TO);
      break;
    case 8..9:
      new(OBJ + "gem.c")->move(TO);
      new(OBJ + "page.c")->move(TO);
      break;
    }
    present("barbazu corpse", TO)->set_searched(1);
    return 1;
  }
  switch(digging){
  case 0:
    tell_object(TP, "What corpse?");
    return 1;
  case 1:
    tell_object(TP, "The corpse is only partially uncovered; you can't"
                   +" really search it yet.");
    return 1;
  default:
    return 0;
  }
}

int taste_blood(string str){
  if (str != "blood" && str !="pool")
  {
    tell_object(TP, "Taste what?");
    return 1;
  }
  tell_object(TP, "Dipping your finger into the pool, you put a little"
                 +" of the %^RED%^blood%^RESET%^ to your lips. It tastes"
                 +" %^BOLD%^%^GREEN%^sharp%^RESET%^ and %^BOLD%^"
                 +"%^CYAN%^metallic%^RESET%^.");

  tell_room(TO, "Dipping " + TP->QP + " finger into the pool, " + TPQCN 
              + " puts a little of the %^RED%^blood%^RESET%^ to " + TP->QP 
              + " lips and tastes it.",TP);

  return 1;
}

int drink_blood(string str){
  int max_hp;
  if (str == "pool")
  {
    tell_object(TP,"As you go to drink from the pool, you realise it is"
                  +" full of %^RED%^blood%^RESET%^. Are you sure you want"
                  +" to %^RED%^drink blood%^RESET%^?");

    return 1;
  }
  if (str != "blood")
  {
    tell_object(TP, "Drink what?");
    return 1;
  }

  tell_object(TP, "Kneeling before the %^RED%^pool of blood%^RESET%^, you"
                 +" scoop up a double handful of the stuff and raise it"
                 +" to your lips to drink. A %^BOLD%^%^RED%^d%^RESET%^"
                 +"%^RED%^e%^BOLD%^%^RED%^vil%^RESET%^%^RED%^i%^BOLD%^"
                 +"%^RED%^sh heat%^RESET%^ and warmth surge though your"
                 +" veins, healing your body comlpetely!");

  max_hp = TP->query_max_hp();
  TP->set_hp(max_hp);
  set_property("alignment adjustment",-2);
  KILLING_D->check_actions(TP,TP);

  tell_room(TO, "Kneeling before the %^RED%^pool of blood%^RESET%^, "
               + TPQCN + " scoops up a double handful of the stuff and"
               +" raises it to " + TP->QP + " lips to drink. " + TP->QS 
               +" looks startled, then smiles, looking pleased with " 
               + TP->QO + "self",TP);

  return 1;
}

int dig_deeper(string str){
  if (!objectp(TO)||!objectp(TP)){return 0;}
  if (str != "deeper" && str != "shale" && str != "pile" && 
str !="corpse")  {
    tell_object(TP, "dig what?");
    return 1;
  }
  if (present("devil", TO)){
    tell_object(TP, "%^BOLD%^%^RED%^The devil won't let you do that!");
    return 1;
  }
  if (digging == 1)  {
    tell_object("Someone is already digging and there's not really room"
               +" for you to join in");

    return 1;
  }
  if (digging ==2)  {
    tell_object("Someone has already dug up the pile. There's not much"
                +" point digging again");

    return 1;
  }
  tell_object(TP, "You begin digging at the %^BOLD%^%^BLACK%^pile of "
                 +"s%^RESET%^h%^BOLD%^%^BLACK%^ale%^RESET%^");
  tell_room(TO, TPQCN + " begins digging at the %^BOLD%^%^BLACK%^pile of "
               +"s%^RESET%^h%^BOLD%^%^BLACK%^ale%^RESET%^",TP);
  call_out("dig_deeper2",5,TP);
  digging = 1;
  return 1;
}

void dig_deeper2(object ob){
  if (!objectp(TO)||!objectp(ob)){return;} 
  tell_object(ob, "You are getting through the %^BOLD%^%^BLACK%^pile of "
                 +"s%^RESET%^h%^BOLD%^%^BLACK%^ale%^RESET%^, and"
                 +" uncovering more of the corpse.\n");
  tell_room(TO, ob->query_cap_name() + " is getting through the %^BOLD%^"
               +"%^BLACK%^pile of s%^RESET%^h%^BOLD%^%^BLACK%^ale"
               +" %^RESET%^and uncovering the grisly remains of a"
               +" corpse.\n",ob);
  call_out("dig_deeper3",5, ob);
}

void dig_deeper3(object ob){
  if (!objectp(TO)||!objectp(ob)){return;}
  tell_object(ob, "You dig deeper into the %^BOLD%^%^BLACK%^s%^RESET%^"
                 +"h%^BOLD%^%^BLACK%^ale, uncovering the entire limp"
                 +" corpse of a %^BOLD%^%^BLACK%^m%^RED%^a%^BLACK%^"
                 +"licious rock d%^RED%^e%^BLACK%^vil%^RESET%^. Entire,"
                 +" that is, a part from its chest cavity, which seems to"
                 +" have been ripped away, and all the %^RED%^blood"
                 +"%^RESET%^ drained out. Suddenly the pool in the centre"
                 +" of the room makes an evil kind of sense. ");

  tell_room(TO,ob->query_cap_name() + " digs deeper into the %^BOLD%^"
              +"%^BLACK%^s%^RESET%^h%^BOLD%^%^BLACK%^ale, uncovering the"
              +" entire limp corpse of a %^BOLD%^%^GREEN%^f%^RESET%^"
              +"%^GREEN%^ie%^BOLD%^%^GREEN%^rce %^RESET%^%^GREEN%^b"
              +"%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^rb%^BOLD%^%^GREEN%^a"
              +"%^RESET%^%^GREEN%^zu d%^RED%^e%^GREEN%^v%^BOLD%^%^RED%^i"
              +"%^RESET%^%^GREEN%^l%^RESET%^. Entire, that is, apart from"
              +" its chest cavity, which seems to have been ripped away,"
              +" and all the %^RED%^blood%^RESET%^ drained out. Suddenly"
              +" the pool in the centre of the room makes an evil kind of"
              +" sense.",ob);
  new(OBJ+"barb_corpse")->move(TO);
  digging = 2;
}

void crawl_hole(string str){
  object bigweapon;
  object *myweapons;
  int i;
  int flag = 0;
  
  if (str != "hole" && str != "into hole" && str != "crack" && str !=
 "into crack" && str != "through crack" && str != "through hole")
  {
    if (query_verb() == "scramble")
    {
      return 0;
    }
    tell_object(TP, query_verb()+" where?");
    return 1;
  }

  if (sizeof(TP->query_wielded())>0)
  {
    myweapons = TP->query_wielded();
    for (i = 0;i<sizeof(TP->query_wielded());i++)
    {
      if(myweapons[i]->query_size() > 1) 
      {
        flag = 1; 
        bigweapon = myweapons[i];
      }
    }
    if (flag)
    {
      tell_object(TP, "You're not able to get into the hole while"
                     +" carrying a weapon the size of your " 
                     + bigweapon->query_name()
                     +". It's just too cumbersome."  );

      return 1;
    }
  }
  if (find_object(TUNNELS+"wormhole")->is_empty()==0)
  {
    tell_object(TP, "You struggle a bit, but there is someone in the"
                   +" way and you can't get into the hole.");   

    tell_room(TO, TPQCN + " struggles a bit, but can't get into the"
                 +" hole.", TP);

    return 1;   
  }
  tell_object(TP, "You scramble into the hole...");     

  tell_room(TO, TPQCN + " scrambles into the hole to the south.", TP);

  TP->move_player(TUNNELS + "wormhole.c");
  find_object_or_load(TUNNELS+ "wormhole.c")->enter_north();
  return 1;
}
