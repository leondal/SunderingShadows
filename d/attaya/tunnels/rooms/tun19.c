
#include <std.h>
#include "../tunnel.h"

inherit TUNNELS + "mouthroom";

string long_desc;

void create(){
  ::create();
  set_long((:"long_desc":));
  set_exits( ([ "west" : TUNNELS + "tun18" ,
	          "south" : TUNNELS + "office",
                "southeast":TUNNELS + "d_cauldron"]) );
  set_door("door",TUNNELS + "office","south",0);
  set_door("stone door",TUNNELS + "d_cauldron","southeast",0);

  set_door_description("iron door","%^BOLD%^%^BLACK%^A solid door of"
                      +" black iron%^RESET%^");
 
  set_door_description("stone door","a tall square door with a heavy"
                                   +" stone for a lintel");
  
  set_lock_description("iron door","lock","%^MAGENTA%^A %^BOLD%^"
                                         +"%^YELLOW%^complex%^RESET%^"
                                         +"%^MAGENTA%^, cruciform lock");

  lock_difficulty("iron door",40,"lock");

  set_items( ([ 
 ({ "notice", "notices"}):"The notices have been attached to the wall by"
                         +" the south door and appear to be in more than"
                         +" one language. You can <read notice 1>,"
                         +" <read notice 2>, etc",

  "notice 1":({"A small notice written in a firm, elegant script","Zut"
            +" zumglutchn vashud kraagstr, kurgh slarn glun sprag"
            +" bhaarg zarfzd. Unglt denbaht plackn yuurt gsh vashud"
            +" flangenahzkn. Storrlzzorg\n\n"
            +"When entering the tower, please be sure to wipe your feet."
            +" I cannot abide mud on the carpets. Stefano", "common"}),

  "notice 2" : ({"A small notice written in a firm, elegant"
                +" script","Vashud shoor lahg ng jrx flsh venzzd."
                +" Storrlzzorg\n\nThe bath house is out of bounds."
                +" Stefano","common"}),

  "notice 3" :  ({"A small notice written in a firm, elegant"
                 +" script","Maaragzchn vashud grelmzd flsh uglinzd ng"
                 +" zeshling zeklagzn xplar lagak vahzhn den bkad"
                 +" uqpleshzn minakh hrrkzaz dazzhor vashud hxagrin."
                 +" Meshd rakhajpuzz undzag glun kurgh omzkhar gnazkhachn"
                 +" vashud deshazd flsh naarakn vahkarr klagh vahoren"
                 +" nmptaz golm neah. Vaarkshazd glun maarang vahoren"
                 +" ashkaz.\n\n"

               +"Taking the souls of humans is firmly discouraged for all"
               +" those not yet granted free movement through the realm."
               +" Also strict discipline to be held over eating the"
               +" corpses of any that find their way in here. Leaders to"
               +" take their share first.","common"}), 

     ({ "wall", "walls"}):" %^BOLD%^%^BLACK%^The walls are of black"
                         +" s%^RESET%^l%^BOLD%^%^BLACK%^ate. They are"
                         +" smooth in places, but cracked and uneven in"
                         +" others, making it hard to know whether they"
                         +" have been worked or not..",

  ({ "cracks", "fissures"}):"the larger cracks look big enough for"
                           +" something to go into of come out of, but"
                           +" they are way up out of reach.", 

  "ceiling" : "the ceiling is so high up as to be out of sight.",

  "floor" : "The floor is smooth, and relatively free of dirt. There are"
           +" scuff marks on it suggesting this place is frequently"
           +" travelled." 
 
  ]) );

}

void init()
{
  ::init();
  add_action("open_door", "open");
}

string long_desc(){
   return "%^BOLD%^%^BLACK%^This is a narrow tunnel cut through the"
          +" black rock. It is unclear whether this is a crudely"
          +" constructed tunnel or simply a natural fissure, but the"
          +" walls are steep and tall, and the ceiling is way out of"
          +" sight overhead. There is a tall, square door to the"
          +" southeast and an iron door to the south seems to lead to"
          +" some sort of holding cell. There are some notices attached"
          +" to the wall by the southern door.%^RESET%^";
}

int open_door(string str)
{
  if (!objectp(TO)){return 0;}
  if (interact("iron door", str))
  {
    mouthsay("You really don't want to be going in there. It's the sort"
            +" of place you might never come out from.");
   }
   return 0;
}

void enter_room()
{
  if (!objectp(TO)){return 0;}
  mouthsay("This is a place to tread carefully. Nearby is the fiendish"
          +" %^BOLD%^%^RED%^l%^RESET%^%^RED%^o%^BOLD%^%^RED%^rd of the"
          +" pit%^RESET%^. It is probably best just to go back.");
}