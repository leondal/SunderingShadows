//shore_inherit - basic inherit for low level caverns at the lake
//Circe 3/13/05
#include <std.h>
#include "ekibi.h"

inherit CROOM;

int crystal;
void pick_critters();

void create(){
   pick_critters();
   ::create();
   set_repop(40);
   set_property("light",0);
   set_terrain(NAT_TUNNEL);
   set_travel(FOOT_PATH);
   set_indoors(1);
   set_name("Ekibi Caverns");
   set_short("%^RESET%^%^MAGENTA%^Ekibi Caverns%^RESET%^");
   set_long("%^RESET%^%^MAGENTA%^You are in the Ekibi Caverns%^RESET%^\n"+
      "The tunnels of the cavern come to an end here at the "+
      "%^BOLD%^shore %^RESET%^of a vast %^BLUE%^subterranean "+
      "lake%^RESET%^.  The %^BLUE%^lake %^RESET%^stretches out "+
      "into the darkness, looking quite %^BOLD%^%^BLACK%^gloomy "+
      "%^RESET%^and forbidding.  Strangely, the %^BOLD%^walls "+
      "%^RESET%^here seem to be shedding a %^BOLD%^%^MAGENTA%^"+
      "glow %^RESET%^all their own.  The floor is rather slick, "+
      "probably owing to the %^CYAN%^water %^RESET%^from the "+
      "%^BLUE%^lake%^RESET%^.  Small %^CYAN%^puddles %^RESET%^"+
      "are more prominent here, littering the shore.\n");
   set_listen("default","The sound of lapping water is masked "+
      "by the chirping of crickets.");
   set_smell("default","The musty fragrance of the cave reaches "+
      "your nose.");
   set_search("default","The glowing walls draw your gaze.");
   set_search("wall","It looks like you could extract some of the "+
      "crystal from the wall, if you have the right tool.");
   set_search("walls","It looks like you could extract some of the "+
      "crystal from the wall, if you have the right tool.");
   set_items(([
      ({"wall","walls","limestone"}) : "%^BOLD%^The walls are "+
         "carved from damp limestone, which feels soft to the "+
         "touch.  They are far from perfect, seeming to have been "+
         "carved by water rather than by hand.  The walls curve, "+
         "narrowing toward the ceiling.  Here, the walls are "+
         "veined with narrow slivers of %^MAGENTA%^softly glowing "+
         "crystal%^BOLD%^%^WHITE%^.",
      ({"rivulet","rivulets","water"}) : "%^CYAN%^Tiny rivulets "+
         "run down the wall, moistening the limestone and "+
         "causing small creases and crevices.",
      ({"puddle","puddles"}) : "In low-lying places throughout "+
         "the cavern, small puddles can be seen.  They do not "+
         "seem deep enough to drink from without getting a "+
         "mouthful of limestone.",
      ({"lake","subterranean lake","water"}) : "The lake looks "+
         "incredibly wide and quite deep, though that could be "+
         "an effect of the darkness around you.  It does not "+
         "look like you can travel any further, as the roof "+
         "of the cave begins curving down and meets with the "+
         "surface of the lake.",
      ({"crystal","veins","slivers","sliver","vein"}) : "The "+
         "slivers of crystal seem to be giving a soft glow, "+
         "providing a small amount of light in the cavern.  "+
         "It looks like parts of it might almost pull away "+
         "from the softer limestone...if you had the right tool.",
      "floor" : "The floor of the cavern is made of slick "+
         "limestone and covered with sporadic puddles."
   ]));
   crystal = 1;
}

void reset(){
   ::reset();
   if(random(3)) crystal = 1;
}

void init(){
   ::init();
   add_action("extract_em","extract");
}

void pick_critters(){
   switch(random(15)){
      case 0..9:  break;
      case 10..11:  set_monsters( ({MON"gray_ooze"}),({1}));
                  break;
      case 12..13:  set_monsters( ({MON"giant_maggot"}),({1}));
                  break;
      case 14:  set_monsters( ({MON"giant_maggot"}),({2}));
                  break;
      default:  break;
   }
}

int extract_em(string str){
   object obj;
   if(present("insect")){
      tell_object(TP,"The insect seems to be standing in the way.");
      return 1;
   }
   if(!str || str != "crystal"){
      tell_object(TP,"You could try to %^BOLD%^%^MAGENTA%^<%^RESET%^extract "+
         "crystal%^BOLD%^%^MAGENTA%^>%^RESET%^ if you have the right tool.");
      return 1;
   }
   if(!crystal){
      tell_object(TP,"It looks as though someone has already "+
         "taken the available crystal from here.");
      return 1;
   }
   if(!obj = present("gnomish extractor999",TP)){
      tell_object(TP,"You must have the proper tool to extract the "+
         "crystal.  Perhaps see Rosinden for the tool if you've "+
         "lost it?");
      return 1;
   }
   tell_object(TP,"%^MAGENTA%^Concentrating carefully, you pull "+
      "out the gnomish extractor and focus the light on the wall.");
   tell_object(TP,"%^YELLOW%^You jump slightly as you hear a clicking "+
      "sound, and the crystal pulls free from the wall, landing in "+
      "your hand.");
   tell_room(TO,"%^MAGENTA%^"+TPQCN+" uses a strange device to collect "+
      "crystal from the wall.",TP);
   new(OBJ"faerzress")->move(TP);
   crystal = 0;
   return 1;
}
