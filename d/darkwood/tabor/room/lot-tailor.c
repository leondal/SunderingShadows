#include <std.h>
#include "../include/tabor.h"
inherit ROOM;

int count;
void create()
{
	::create();
      set_terrain(WOOD_BUILDING);
      set_travel(DIRT_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_short("Shahryar's Clothier");
	set_long(
         "%^BOLD%^Shahryar's Clothing, Tabor%^RESET%^\n"+
         "%^CYAN%^This spacious shop is most unlike other shops in the "+
         "fair city of Tabor.  Rather than a business counter and bare "+
         "shelves supporting his goods, Shahryar has set up his shop "+
         "to be a most pleasant shopping experience.  Thick, plush "+
         "%^MAGENTA%^cushions %^CYAN%^made of %^MAGENTA%^velvet %^CYAN%^"+
         "in a %^RED%^r%^ORANGE%^a%^YELLOW%^i%^RESET%^%^GREEN%^n%^CYAN%^"+
         "b%^BOLD%^%^BLUE%^o%^RESET%^%^BLUE%^w %^CYAN%^of muted hues "+
         "are piled around the floor, leaving only the central area "+
         "open to walk in.  Shahryar can often be seen lounging on a "+
         "pile of %^MAGENTA%^cushions %^CYAN%^in the far corner, "+
         "smoking from an ornate %^ORANGE%^hookah%^CYAN%^.  The "+
         "fantastic %^RESET%^clothing %^CYAN%^he creates and imports "+
         "can be seen on a marvelous %^BOLD%^%^BLACK%^mahogany case "+
         "%^RESET%^%^CYAN%^centered on the north wall directly across "+
         "from the door.  The east and west walls are dominated by "+
         "fantastic onion-shaped %^BOLD%^windows %^RESET%^%^CYAN%^"+
         "provide a view of the quiet town of Tabor outside.  Inside, "+
         "it seems you've stepped into a completely new world.  "+
         "The somewhat unusual decor is completed by several strands "+
         "of %^BOLD%^glass %^RED%^b%^YELLOW%^e%^WHITE%^a%^GREEN%^d"+
         "%^BLUE%^s %^RESET%^%^CYAN%^and swaths of %^MAGENTA%^"+
         "silk %^CYAN%^hanging low from the ceiling.\n"
	);
	set_smell("default","The somewhat spicy scent of tobacco "+
         "lingers in the air.");
	if(query_night() == 1) {
		set_listen("default","The sound of crickets chirping outside "+
               "can be heard through the open windows.");
	}
	else {
		set_listen("default","The quiet puffing of the hookah "+
               "can be heard.");
	}
	set_items(([
         ({"floor","cushion","cushions"}) : "The thickly carpeted "+
            "floor is further hidden by piles of plush cushions "+
            "scattered near the base of the walls.  They are colored "+
            "in a %^RED%^r%^ORANGE%^a%^YELLOW%^i%^RESET%^%^GREEN%^n%^CYAN%^"+
            "b%^BOLD%^%^BLUE%^o%^RESET%^%^BLUE%^w %^RESET%^of muted hues "+
            "that is rather pleasant to the eyes.  They look quite "+
            "comfortable and you could sit on the cushions for awhile "+
            "if you wanted to relax.",
         ({"pile of cushions","pile","far corner"}) : "%^MAGENTA%^The "+
            "far western corner is dominated by Shahryar's own "+
            "personal pile of cushions.  He has clearly used them for "+
            "some time, as they feature a permanent indention even "+
            "when he stands to show a customer an item.  He can "+
            "often be found here, lounging and smoking his %^ORANGE%^"+
            "hookah%^MAGENTA%^.",
         "hookah" : "%^BOLD%^%^BLUE%^Shahryar's hookah is a most "+
            "beautiful creation.  It features a blue glass base "+
            "decorated with small %^RED%^red %^BLUE%^and %^YELLOW%^"+
            "gold %^RED%^b%^YELLOW%^e%^RED%^a%^YELLOW%^d%^RED%^s"+
            "%^BLUE%^.  The base is filled with water, which "+
            "cools the %^RESET%^%^ORANGE%^tumbak %^BOLD%^%^BLUE%^"+
            "drawn from one of the four slender %^WHITE%^tubes "+
            "%^BLUE%^sprouting from the %^YELLOW%^golden top"+
            "%^BLUE%^.  Shahryar often invites customers to "+
            "come smoke with him, so long as there is an "+
            "available pipe, of course.  If you'd like, you "+
            "may <start smoking>.",
         ({"case","mahogany case","clothing"}) : "%^BOLD%^%^BLACK%^"+
            "The case in "+
            "the northern end of the room is made of intricately "+
            "carved mahogany.  The carvings are of birds and "+
            "flowers, and they have been filled with that looks "+
            "to be %^YELLOW%^molten gold%^BLACK%^.  Piles of the "+
            "wonderful clothing that Shahryar creates are "+
            "folded neatly atop it.",
         ({"ceiling","beads","strands","silk","swaths","silk swaths"}) :
            "The ceiling above is hidden within layers of silk in "+
            "muted hues.  Several strands of beads hang there as "+
            "well, adding color and a delicate beauty to the "+
            "shop.  Shahryar can often be seen gazing overhead "+
            "at them as he smokes his hookah.",
         ({"windows","window","onion-shaped windows"}) : (:TO,"window_desc":)
	]));
	set_exits(([
   	   "south" : ROOMDIR+"gwy3",
	]));
      set_pre_exit_functions(({"south"}),({"GoThroughDoor"}));
}

void reset()
{
	::reset();
	if(!present("shahryar")) {
		new(MONDIR+"shahryar")->move(TO);
	}
}

void init(){
   ::init();
   add_action("start","start");
   add_action("smoke","smoke");
   add_action("stop","stop");
   add_action("sit_em","sit");
   add_action("sit_em","lounge");
}

int start(string str){
   if(!str || str != "smoking"){
      tell_object(TP,"Try 'start smoking'.");
      return 1;
   }
   if(count > 3){
      tell_object(TP,"There are no more pipes on the hookah.  "+
         "Someone else will have to get up first.");
      return 1;
   }
   if(TP->query_property("smoking hookah")){
      tell_object(TP,"Perhaps you've had enough!  You're already "+
         "smoking the hookah.");
      return 1;
   }
   tell_object(TP,"%^BOLD%^You settle on the cushions near the far "+
      "corner and take up one of the pipes.  You inhale, drawing "+
      "in the sweet tumbak that tastes lightly of honey and fruit "+
      "mixed with tobacco.  You may <smoke> whenever you like or "+
      "<stop smoking> when you are finished.");
   tell_room(ETP,"%^BOLD%^"+TPQCN+" settles on one of the cushions "+
      "in the far corner and begins smoking the hookah.",TP);
   TP->force_me("pose sitting in the corner smoking the hookah");
   TP->set_property("smoking hookah",1);
   count++;
   return 1;
}

int smoke(string str){
   if(!str || str == "hookah"){
      if(!TP->query_property("smoking hookah")){
         tell_object(TP,"You have not started smoking the hookah!");
         return 1;
      }
      tell_object(TP,"%^BOLD%^You take a long drag off the hookah, "+
         "enjoying the cool, lightly spiced smoke.");
      tell_room(ETP,"%^BOLD%^"+TPQCN+" takes a drag off the hookah "+
         "with a smile, sending a small puff of smoke in the air.",TP);
      if(!random(4)){
         switch(random(6)){
            case 0:  tell_object(TP,"%^YELLOW%^You watch in "+
                        "amazement as the puff of smoke turns into "+
                        "a prancing cat.");
                     break;
            case 1:  tell_object(TP,"%^BOLD%^%^BLUE%^You could swear "+
                        "that puff of smoke looks just like a huge "+
                        "ship sailing on the ocean.");
                     break;
            case 2:  tell_object(TP,"%^BOLD%^You see many different "+
                        "%^CYAN%^c%^BLUE%^o%^MAGENTA%^l%^RED%^o"+
                        "%^GREEN%^r%^YELLOW%^s %^WHITE%^swirling in "+
                        "the smoke.");
                     break;
            case 3:  tell_object(TP,"%^MAGENTA%^You watch the smoke "+
                        "swirl in the air above your head.");
                     break;
            case 4:  tell_object(TP,"%^CYAN%^You watch in "+
                        "amazement as the puff of smoke turns into "+
                        "a proud stallion.  Look...he's running "+
                        "through the fields!");
                     break;
            case 5:  tell_object(TP,"%^BOLD%^You look up at the "+
                        "beaded ceiling as the smoke relaxes you");
                     break;
         }
         tell_room(ETP,""+TPQCN+" stares at the ceiling with "+
            "wide eyes.",TP);
      }
      return 1;
   }
   return 0;
}

int stop(string str){
   if(!str || str != "smoking"){
      tell_object(TP,"Try 'stop smoking'.");
      return 1;
   }
   if(!TP->query_property("smoking hookah")){
      tell_object(TP,"You are not smoking the hookah.");
      return 1;
   }
   tell_object(TP,"%^BOLD%^You set the pipe aside and stand, "+
      "feeling slightly dizzy.");
   tell_room(ETP,"%^BOLD%^"+TPQCN+" puts the pipe aside and stands.",TP);
   TP->force_me("pose clear");
   TP->remove_property("smoking hookah");
   count = count-1;
   return 1;
}

int sit_em(string str){
   if(!str) return 0;
   if(str != "cushions" && str != "on cushions" && str != "on the cushions"){
      tell_object(TP,"You may sit on the cushions if you like.");
      return 1;
   }
   tell_object(TP,"%^MAGENTA%^You settle into a pile of comfortable "+
      "cushions and relax.  Nice and soothing...");
   tell_room(ETP,"%^MAGENTA%^"+TPQCN+" settles onto a pile of cushions.",TP);
   TP->force_me("pose lounging on the cushions");
   return 1;
}

int GoThroughDoor(){
   if((int)TP->query_property("smoking hookah") == 1){
      tell_object(TP,"You cannot leave while smoking the hookah!");
      return 0;
   }
   return 1;
}

int window_desc(){
   switch(random(6)){
      case 0:  tell_object(TP,"As you glance out the window, you see "+
                  "the top of a woman's hat as she wanders by.");
               break;
      case 1:  tell_object(TP,"You see a small group of soldiers walk "+
                  "by on patrol.");
               break;
      case 2:  tell_object(TP,"You see only the clear sky above the "+
                  "forest to the east.");
               break;
      case 3:  tell_object(TP,"A small %^BOLD%^%^BLUE%^blue jay "+
                  "%^RESET%^lights on the windowsill before taking "+
                  "to the sky again.");
               break;
      case 4:  tell_object(TP,"You see several children run by, "+
                  "giggling as they tag each other.");
               break;
      case 5:  tell_object(TP,"A young couple strolls lazily by, "+
                  "talking to each other and pointing at the shop.");
               break;
   }
   tell_room(ETP,""+TPQCN+" looks over the windows.",TP);
   return 1;
}