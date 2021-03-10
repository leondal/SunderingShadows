//lysara_shrine.c - Designed by Kiya, coded by Circe 2/4/04
//edited by ~Circe~ 6/10/14 to function as a temple since other shrines do
//updated to remove references to Selune

#include <std.h>
#include <daemons.h>
inherit "/std/temple";

void create() {
        ::create();
        set_property("indoors",1);
        set_property("light",2);
        set_terrain(STONE_BUILDING);
        set_travel(PAVED_ROAD);
        set_temple("lysara");
        set_name("A small shrine");
        set_short("%^ORANGE%^A small shrine%^RESET%^");
        set_long("%^CYAN%^This small temple has been formed of what "+
           "looks like %^ORANGE%^pale-brown sandstone%^CYAN%^.  Small, "+
           "circular stepping-stones with irregularly cut edges lead in "+
           "from the surrounding %^BOLD%^%^GREEN%^grassy meadows%^RESET%^"+
           "%^CYAN%^ to the partly-enclosed building.  %^ORANGE%^Low "+
           "sandstone walls%^CYAN%^ edge both sides of the path, gently "+
           "sloping upward until they meet the roof of the building, over "+
           "which hangs a few %^GREEN%^leafy branches%^CYAN%^ of a tall tree "+
           "growing nearby.  Within the temple itself, the walls are flat and "+
           "smooth, with an occasional few etchings upon them of tiny stars and "+
           "phases of the moon.  Near the entryway, a simple %^ORANGE%^oak "+
           "plaque %^CYAN%^hangs, bearing a message.  A few low-set "+
           "%^ORANGE%^sandstone benches"+
           "%^CYAN%^ are located around the edges of the room, leaving the center "+
           "free for visitors to move. Small ledges have been placed at regular "+
           "intervals along the walls, each with a %^WHITE%^clear, transparent "+
           "globe%^CYAN%^ upon them.  Before the far wall of the room is a simple "+
           "altar, again carved of sandstone, and draped with a %^BLACK%^%^BOLD%^"+
           "jet-black cloth%^RESET%^%^CYAN%^ of some unknown material, trimmed "+
           "with %^WHITE%^%^BOLD%^silver%^RESET%^%^CYAN%^.  Behind the altar upon "+
           "the back wall is a simple tapestry again in %^BLACK%^%^BOLD%^black"+
           "%^RESET%^%^CYAN%^-and-%^WHITE%^%^BOLD%^silver%^RESET%^%^CYAN%^, stitched "+
           "carefully with the words of the Lysaran charge.%^RESET%^\n"
        );
        set("night long","%^BLUE%^This small temple has been formed of "+
           "what looks like %^ORANGE%^pale-brown sandstone%^BLUE%^.  "+
           "Small, circular stepping-stones with irregularly cut edges "+
           "lead in from the surrounding %^GREEN%^grassy meadows%^BLUE%^ "+
           "to the partly-enclosed building.  %^ORANGE%^Low sandstone walls"+
           "%^BLUE%^ edge both sides of the path, gently sloping upward until "+
           "they meet the roof of the building, over which a few %^GREEN%^leafy "+
           "branches%^BLUE%^ of a tall tree cast their shadows.  Within the "+
           "temple itself, the walls are flat and smooth, with an occasional "+
           "few etchings upon them of tiny stars and phases of the moon.  "+
           "Near the entryway, a simple %^ORANGE%^oak "+
           "plaque %^BLUE%^hangs, bearing a message.  A few "+
           "low-set %^ORANGE%^sandstone benches%^BLUE%^ are located around the "+
           "edges of the room, leaving the centre free for visitors to move.  "+
           "Small ledges have been placed at regular intervals along the walls, "+
           "each with a %^WHITE%^%^BOLD%^glowing, transparent globe%^RESET%^%^BLUE%^ "+
           "upon them to shed soft light around the room.  Before the far wall of "+
           "the room is a simple altar, again carved of sandstone, and draped with "+
           "a %^BLACK%^%^BOLD%^jet-black cloth%^RESET%^%^BLUE%^ of some unknown "+
           "material, trimmed with %^WHITE%^%^BOLD%^silver%^RESET%^%^BLUE%^.  "+
           "Behind the altar upon the back wall is a simple tapestry again in "+
           "%^BLACK%^%^BOLD%^black%^RESET%^%^BLUE%^-and-%^WHITE%^%^BOLD%^silver"+
           "%^RESET%^%^BLUE%^, stitched carefully with the words of the Lysaran "+
           "charge.%^RESET%^");
        set_smell("default","Fresh scents of the surrounding meadows fill the room, "+
           "blending with the dusky smell of stone.");
        set_listen("default","Few noises disturb the peace and quiet here.");
        set_items(([
           ({"altar","cloth"}) : "%^CYAN%^A simple cloth of some unknown "+
              "material rests atop the %^ORANGE%^smooth sandstone altar%^CYAN%^.  "+
              "It is dyed a %^BLACK%^%^BOLD%^midnight-black hue%^RESET%^%^CYAN%^, "+
              "trimmed with a pattern of %^WHITE%^shi%^BOLD%^m%^RESET%^%^WHITE%^mer"+
              "%^BOLD%^i%^RESET%^%^WHITE%^ng si%^BOLD%^l%^RESET%^%^WHITE%^ver sta"+
              "%^BOLD%^r%^RESET%^%^WHITE%^s%^CYAN%^ and %^WHITE%^moons%^CYAN%^ "+
              "around its edges, and embroidered in the center with a pair of "+
              "feminine eyes, surrounded by seven stars.%^RESET%^",
           ({"charge","tapestry"}) : "%^CYAN%^Another embroidered cloth, of the same "+
              "%^BLACK%^%^BOLD%^jet-black hue%^RESET%^%^CYAN%^ as the one "+
              "upon the altar, has been hung on the wall behind the altar.  "+
              "Upon its surface, painstakingly embroidered in %^WHITE%^shi%^BOLD%^"+
              "m%^RESET%^%^WHITE%^mer%^BOLD%^i%^RESET%^%^WHITE%^ng si%^BOLD%^l"+
              "%^RESET%^%^WHITE%^ver thre%^BOLD%^a%^RESET%^%^WHITE%^d%^CYAN%^, "+
              "is written the charge of the Selunite church.%^RESET%^",
           ({"stones","stepping stones"}) : "%^CYAN%^These flat stones are of "+
              "the same %^ORANGE%^sandstone%^CYAN%^ as the building they lead to, "+
              "each with an irregular cut, but with gently smoothed edges.  They "+
              "form a path of sorts, leading up through the %^GREEN%^%^BOLD%^grass"+
              "%^RESET%^%^CYAN%^ into the small building.%^RESET%^",
           "walls" : "%^ORANGE%^Low sandstone walls%^CYAN%^ lead in from the "+
              "%^GREEN%^%^BOLD%^grassy meadow%^RESET%^%^CYAN%^, gradually rising "+
              "to meet the roof above. Within the temple the walls are smooth and "+
              "even, save for the occasional %^BLACK%^%^BOLD%^detailed etching"+
              "%^RESET%^%^CYAN%^ within the stone of little stars and moons in "+
              "various phases.%^RESET%^",
           "benches" : "%^CYAN%^A few low-set benches with smoothed surfaces, "+
              "of the same %^ORANGE%^pale-brown sandstone%^CYAN%^, have been "+
              "placed around the edges of the room, giving visitors somewhere to "+
              "rest without obstructing the center of the room.%^RESET%^",
           ({"plaque","oak plaque","wooden plaque"}) : ({"%^ORANGE%^The "+
              "oak plaque looks weathered and aged, but seems to be "+
              "solid and well-kept.  A message has been carved in a "+
              "simple script, filled with %^BOLD%^%^WHITE%^molten silver.","+
              ""\n"+
              "                   %^BOLD%^%^WHITE%^In memory of\n "+
              "\n"+
              "               %^MAGENTA%^~ %^YELLOW%^Vivian Nightsong %^MAGENTA%^~\n"+
              "\n"+
              "         %^WHITE%^Whose gentle heart and warm laughter\n"+
              "              Echo now above as a %^YELLOW%^Shard\n"+
              "                %^WHITE%^In Our Lady's service\n","common"}),
           ({"globes","lights","ledges","globe"}) : (:TO,"globe_desc":)
        ]));
        set_exits(([
           "out" : "/d/antioch/valley/rooms/g108",
        ]));
}

int globe_desc(){
   string tod;
    tod = EVENTS_D->query_time_of_day();
    if(tod == "night") {
       return("%^CYAN%^Around the walls of the room are several small "+
          "ledges jutting out from the %^ORANGE%^sandstone%^CYAN%^.  "+
          "Upon each is supported a %^WHITE%^%^BOLD%^glowing, translucent "+
          "orb%^RESET%^%^CYAN%^ that sheds a soft light around the room.%^RESET%^");
    }
    else{
       return("%^CYAN%^Around the walls of the "+
              "room are several small ledges jutting out from the %^ORANGE%^"+
              "sandstone%^CYAN%^. Upon each is supported a %^WHITE%^clear, "+
              "translucent orb%^CYAN%^.%^RESET%^");
    }
}

void init(){
   ::init();
   add_action("kneel_em","kneel");
   add_action("read","read");
}

int kneel_em(string str){
   if(!str){
      return 0;
   }
   if(str == "before altar" || str == "altar" || str == "before the altar"){
      if((string)TP->query_diety() != "lysara"){
         tell_object(TP,"%^WHITE%^%^BOLD%^You kneel before the sandstone altar.%^RESET%^");
         tell_room(TO,"%^WHITE%^%^BOLD%^"+TPQCN+" kneels before the sandstone altar.%^RESET%^",TP);
         TP->force_me("pose kneeling before a sandstone altar");
         return 1;
      }
      tell_object(TP,"%^WHITE%^%^BOLD%^A feeling of %^YELLOW%^peace%^WHITE%^ "+
         "and %^RESET%^%^RED%^warmth%^WHITE%^%^BOLD%^ washes over you as you kneel "+
         "before the sandstone altar.%^RESET%^");
      tell_room(TO,"%^WHITE%^%^BOLD%^An expression of %^RESET%^%^CYAN%^tranquility"+
         "%^WHITE%^%^BOLD%^ crosses "+TPQCN+"'s features as "+TP->QS+" kneels "+
         "before the sandstone altar.%^RESET%^",TP);
         TP->force_me("pose kneeling before a sandstone altar");
         return 1;
   }
   tell_object(TP,"Try kneeling before the altar.");
   return 1;
}

int read(string str){
   if(!str || str != "charge") return 0;
   tell_object(TP,
@CHARGE
The writing is weathered with time.
CHARGE
   );
}

void reset(){
   ::reset();
      switch(random(16)){
         case 0..2: tell_room(TO,"%^GREEN%^Overhanging branches brush the "+
                       "temple's roof with a light scratching noise, swaying "+
                       "in the wind.");
                    break;
         case 3..5: tell_room(TO,"%^YELLOW%^Somewhere outside, a bird raises "+
                       "its voice a cheerful song, breaking the quiet serenity "+
                       "of the temple.");
                    break;
         case 6..8: tell_room(TO,"%^BOLD%^%^BLACK%^The tapestry upon the far "+
                       "wall sways gently, as a breeze whispers through the temple.");
                    break;
         case 9..10: tell_room(TO,"%^RED%^A lone visitor enters and sits to "+
                       "the side, bowing toward the altar and taking relaxation "+
                       "in the serenity of the temple.");
                    break;
         case 11..12: tell_room(TO,"%^MAGENTA%^A brightly-colored butterfly "+
                       "spreads its wings, fluttering around the branches "+
                       "overhanging the doorway.");
                    break;
         case 13: tell_room(TO,"%^ORANGE%^A small group of brownies scramble "+
                       "over the stones on the path outside, chattering among "+
                       "themselves in some unknown language as they continue on "+
                       "their way.");
                    break;
         case 14: tell_room(TO,"%^BLUE%^A tiny sprite flits around the room "+
                       "on its tiny translucent wings, moving around the temple "+
                       "and beneath the benches, and finally disappearing again "+
                       "out the doorway.");
                    break;
         case 15: tell_room(TO,"%^BOLD%^%^CYAN%^A melodic giggle echoes just "+
                       "beside your ear, as you catch a glimpse of a feminine "+
                       "face out of the corner of your eye... or did you?");
                    break;
   }
}
