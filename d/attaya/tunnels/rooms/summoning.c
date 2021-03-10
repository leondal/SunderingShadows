///d/attaya/tunnels/rooms/summoning.c
//summoning.c - Summoning room for Stefano's house.  Coded by Circe 12/3/03
//updated to current code and to change out the mirror for a crystal ball since Gaius paid for it ~Circe~ 11/30/19
//Crystal ball had been removed. Its presence here upsets me on a thematic level so much I raged for 30 minutes, but then fell asleep. Illy 2020-01-06

#include <std.h>
//#include "/d/player_houses/stefano/stefano.h"
#include "../tunnel.h"
#include <daemons.h>

inherit VAULT;

int coal_moved;
int press_bump(string str);
int lift_coal(string str);
void remember_door();
void close_trapdoor();
void open_trapdoor();
string long_desc();

void create(){
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("A black walled room with no apparent way out");
   set_short("A black walled room with no apparent way out");
   set_long( (:TO,"long_desc":));
   set_smell("default","The room is pleasantly scented with the smell of fresh pine.");
   set_listen("default","It is quiet.");
   set_items(([
      ({"runes", "sigils", "rune", "sigil"}) : "%^BOLD%^%^BLACK%^The magical symbols seem to %^RESET%^%^RED%^twist%^BOLD%^%^BLACK%^ and %^RESET%^%^GREEN%^writhe%^BOLD%^%^BLACK%^ in tortured fashion under your gaze, making it hard to study them closely. They all look ugly and unpleasant, however.%^RESET%^",
      "floor" : "%^BOLD%^%^BLACK%^The floor slopes up, away from the west wak.  It is made of black slate, and there are two strange looking %^RESET%^d%^BOLD%^%^WHITE%^i%^RESET%^agrams%^BOLD%^%^BLACK%^ engraved upon it and inlaid with %^BOLD%^%^WHITE%^silver%^BOLD%^%^BLACK%^.",
      "diagram" : "The large one or the small one?",
      "carpet" : "The carpet is a %^GREEN%^rich deep green%^RESET%^ in color, and plush and comfortable to walk on. There is a noticeable absence of trodden-in mud and dirt, even round the doorway.",
      "small diagram" : "This is a %^BOLD%^%^WHITE%^simple circle%^RESET%^, ten feet in diameter, engraved into the floor and %^BOLD%^%^WHITE%^inlaid with silver%^RESET%^.  There is a %^BOLD%^%^BLACK%^brazier%^RESET%^ positioned within the circle, a good few inches away from the edge.",
      "large diagram" : "A large, eight pointed %^BOLD%^%^WHITE%^star%^RESET%^ within a%^BOLD%^%^WHITE%^ perfect circle%^RESET%^ has been engraved into the floor, and the outline inlaid with %^BOLD%^%^WHITE%^silver%^RESET%^. The points of the star break out through the line of the circle, but the space enclosed lays within a continuous line of unbroken silver. Strange looking runes and sigils have been inscribed in odd colours around the outside of the circle, and there are thick %^BOLD%^%^BLACK%^black candles%^RESET%^ surrounded by further magical writings at each of the eight points of the star. Looking closely, you can see that the floor in the centre of the diagram appears to have been scorched.",
      "brazier" : "A black iron brazier half filled with coals sits within the smaller of the two diagrams on the floor. It looks like it could be used to burn oils or other components during ritual spellcasting.",
      "coals" : "They look like ordinary coals sitting within the brazier ready to be lit.",
      "candles" : "%^BOLD%^%^BLACK%^The thick black candles are partly used, and have trickles of wax running down the sides of them.%^RESET%^",
      "door" : "You look at the wall, but you can't seem to remember where the door was.",
      "west wall" : "%^BOLD%^%^BLACK%^You think you can faintly make out some difference of shade in the inky black slate of the west wall."
   ]));
   set_search("brazier","You notice a little coal dust on the floor by the foot of the brazier.");
   set_search("coals","The coals are in something of a jumble, as if they have been disturbed.");
   set_post_exit_functions(({"west"}),({"go_west"}));
}

void init(){
   ::init();
   add_action("close_em","close");
   add_action("remember","remember");
   add_action("escape","escape");
   add_action("search_wall","search");
   add_action("wave","wave");
   add_action("gesture","gesture");
   add_action("lift_coal", "lift");
   add_action("lift_coal", "disturb");
   add_action("press_bump", "press");
   add_action("close_trapdoor", "close");

}

string long_desc(){
   return "%^BOLD%^%^BLACK%^This is a very large, oval shaped room with a high ceiling. The walls, floor and ceiling are faced in dark slate.  One large diagram and one smaller one are inscribed upon the floor, a short distance from each other. There is a small iron brazier within the smaller of the two diagrams. You notice that the floor slopes gently upwards, away from the west wall.%^RESET%^";
}

void reset(){
   ::reset();

//Crystal ball had been removed. Its presence here upsets me on a thematic level so much I raged for 30 minutes, but then fell asleep. Illy 2020-01-06
   if(!present("mirror")) new("/d/magic/obj/mirror")->move(TO);
   coal_moved = 0;
}


int go_west(){
   object other_room;
   if (!objectp(TP)||!objectp(TO)){return 0;}
   other_room = find_object_or_load(TUNNELS + "library");
   tell_object(TP,"As you move through the secret door, it slides shut behind you, hiding the exit.");
   tell_room(TO,""+TPQCN+" moves through a secret door secret door in the west wall, and it closes behind "+TP->QO+".",TP);
   tell_room(TUNNELS + "library",""+TPQCN+" arrives suddenly through a hidden entrance in the west wall, which closes behind "+TP->QO+".",TP);
   if(query_exit("west")){ remove_exit("west");}
   if(other_room->query_exit("east")){other_room->remove_exit("east");}
   return 1;
}

int press_bump(string str){
   if(!objectp(TP)||!objectp(TO)){return 0;}
   if(str=="bump" && coal_moved){
      tell_object(TP,"You press the bump in the bowl of the brazier. At first nothing happens, but as you apply more pressure it gives way slightly under your fingers.");
      tell_room(TO,""+TPQCN+" does something to the brazier.",TP);
      if((string)TO->query_exit("down")==TUNNELS + "tun21"){
         tell_room(TO,""+TPQCN+" does something to the coals in the brazier.",TP);
         close_trapdoor();
         return 1;
      }else{
         tell_object(TP,"There is a click, and then a secret trapdoor swings silently open in the east end of the wall, as you drop the coal back into the brazier.");
         tell_room(TP,"There is a click, and then a secret trapdoor swings silently open in the east end of the wall, as "+TPQCN+" drops the coal back into the brazier.",TP);
        open_trapdoor();
      }
   }
   return 1;
}

void open_trapdoor(){
   object other_room;
   other_room = find_object_or_load(TUNNELS+"tun21");
   if(!objectp(TO)){return;}
   add_exit(TUNNELS + "tun21","down");
   if((string)other_room->query_exit("up")){
      tell_room(TUNNELS + "tun21","A trap door in the ceiling swings open.");
      other_room->add_exit(TUNNELS+"summoning","up");
   }
   return;
}

void close_trapdoor(){
   if(!objectp(TO)){return;}
   tell_room(TO, "There is a click, and the trapdoor swings silently closed.");
   remove_exit("down");
   if((string)find_object_or_load(TUNNELS+"tun21")->query_exit("up")){
      tell_room(TUNNELS + "tun21","The trap door swings shut.");
      find_object_or_load(TUNNELS + "tun21")->remove_exit("up");
   }
   return;
}

int lift_coal(string str){
   if(str=="coal"||str=="coals"){
      tell_object(TP,"You move one of the coals from the brazier, and notice a small bump in the bowl of the brazier.");
      tell_room(TO,""+TPQCN+" does something to the coals in the brazier.",TP);
      coal_moved = 1;
      return 1;
   }
   return 0;
}


void remember_door(){
   int i;
   if(sizeof(all_living(TO))<1){return;}
   for(i=0;i<sizeof(all_living(TO));i++){
      if(all_living(TO)[i]->is_player()){
         all_living(TO)[i]->set_property("remember_door",1);
      }
   }
   return;
}

int close_em(string str){
   if(!str){
      tell_object(TP,"Close what?");
      return 1;
   }
   if(str == "door"){
      tell_object(TP,"The heavy door closes with a leaden slam. The rim of light from outside disappears without a trace, leaving you in the darkness of the room. The outline of the door vanishes into the %^BOLD%^%^BLACK%^dark slate facing%^RESET%^ of the rest of the room, and it could be difficult to remember exactly where the door is positioned in the wall.");
      tell_room(ETP,"The heavy door closes with a leaden slam behind "+TPQCN+", vanishing without a trace.",TP);
      remove_exit("west");
      tell_room(TUNNELS + "library","The door in the eastern wall swings shut.");
      find_object_or_load(TUNNELS + "library")->remove_exit("east");
      return 1;
   }
   return 0;
}

int remember(string str){
   if(!str){
      tell_object(TP,"Umm...what are you trying to remember?");
      return 1;
   }
   if(str == "door" && TP->query_property("remember_door")){
      tell_object(TP,"You carefully memorize the exact position of the door and hopefully will be able to %^BLUE%^escape%^RESET%^ in a hurry if you need to.");
      tell_room(ETP,""+TPQCN+" concentrates carefully for a moment.",TP);
      TP->set_property("escape_route",1);
      return 1;
   }
   tell_object(TP,"You can't seem to remember that!");
   return 1;
}

int escape(string str){
   if(!objectp(TP)||!objectp(TO)){return 1;}
   if(!str){
      if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed() || TP->query_tripped()){
         TP->send_paralyzed_message("info",TP);
         return 1;
      }
      if(TP->query_property("escape_route")){
         tell_object(TP,"Turning, you run headlong towards the blank wall, at the point where you remember the door to be. Thankfully your memory serves you well and the door swings open as you pass through, then slams shut behind you.");
         if(!TP->query_true_invis()){
            tell_room(TO,""+TPQCN+" runs wildly at the wall!  The door opens just in front of "+TP->QO+" then slams shut!",TP);
            tell_room(TUNNELS + "library",""+TPQCN+" comes barging in from a hidden entrance in the east wall, which closes behind "+TP->QO+"!",TP);
         }
         TP->move(TUNNELS + "library");
         TP->force_me("look");
         return 1;
      }
      tell_object(TP,"You can't remember where the door is!");
      return 1;
   }
}

int search_wall(string str){
   if(str == "wall" || str == "door" || str == "west wall"){
      tell_object(TP,"Your searching reveals the outline of the door only by touch.  It fits so tightly against the wall that your eyes simply cannot make it out in the gloom.");
      tell_room(ETP,"You watch "+TPQCN+" search along the wall, and you see the outline of a door.",TP);
      add_exit(TUNNELS + "library","west");
      add_item("door","The door is at least five inches thick and very heavy. A closer examination reveals that at its core is a three inch thickness of lead, sandwiched between the %^BOLD%^%^BLACK%^dark slate facing on either side%^RESET%^. Despite the massive weight, the door is perfectly balanced and moves easily on greased hinges. When pushed from either direction, it opens without effort then immediately swings back to a closed position. The frame fits the door snugly, making it all but invisible when closed.");
      add_item("frame", "Examining the inside of the door frame, you notice that the surrounding wall and the floor also seem to have a three-inch thickness of lead tucked behind the lead facing. You can guess that when the door is closed, the lead will all line up to leave the room fully enclosed in the dense metal.");
      return 1;
   }
   return 0;
}

int wave(string str){
   if(!str){
      tell_object(TP,"What are you trying to wave at?");
      tell_room(ETP,""+TPQCN+" waves a hand in the air strangely.",TP);
      return 1;
   }
   if(str == "up" || str == "brazier up"){
      tell_object(TP,"%^BOLD%^%^BLACK%^You wave a hand at the brazier and the coals spring to life, suddenly g%^RED%^l%^BOLD%^%^RED%^o%^RESET%^%^RED%^wi%^BOLD%^%^RED%^n%^BOLD%^%^BLACK%^g with a slow, sullen heat.%^RESET%^");
      tell_room(ETP,""+TPQCN+" waves a hand at the brazier, causing them to spring to life with a slow, sullen heat.%^RESET%^",TP);
      set_property("light",1);
      return 1;
   }
   if(str == "down" || str == "brazier down"){
      tell_object(TP,"%^BOLD%^%^BLACK%^You wave a hand at the brazier and the fire in the coals instantly dies away, leaving them as cold and dead as if it had never been.%^RESET%^");
      tell_room(ETP,""+TPQCN+" waves a hand at the brazier, causing fire to instantly die.%^RESET%^",TP);
      set_property("light",-1);
      return 1;
   }
   return 0;
}

int gesture(string str){
   if(!str){
      tell_object(TP,"What are you trying to gesture at?");
      tell_room(ETP,""+TPQCN+" waves a hand in the air strangely.",TP);
      return 1;
   }
   if(str == "up" || str == "candles up"){
      tell_object(TP,"%^BOLD%^%^BLACK%^ you make an odd gesture towards the candles placed within the eight points of the star on the floor and they spring to life, their yellow %^BOLD%^%^YELLOW%^flames%^BOLD%^%^BLACK%^ adding little to the lighting of the room, but somehow emphasizing the pools of shadow around the edges of the room.  The inscriptions around the diagram  seem to shimmer.%^RESET%^");
      tell_room(ETP,""+TPQCN+" waves a hand at the candles, causing them to spring to life around the star.  The inscriptions around the diagram seem to shimmer.%^RESET%^",TP);
      set_property("light",1);
      return 1;
   }
   if(str == "down" || str == "candles down"){
      tell_object(TP,"%^BOLD%^%^BLACK%^You make an odd gesture towards the candles placed in the large diagram and their flames wink out, leaving the room darker once more.%^RESET%^");
      tell_room(ETP,""+TPQCN+" waves a hand at the candles, causing them to wink out.",TP);
      set_property("light",-1);
      return 1;
   }
   return 0;
}
