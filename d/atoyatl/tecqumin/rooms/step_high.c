#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit ROOM;

string long_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_terrain(GRASSLANDS);
  set_travel(FOOT_PATH);
  set_name("Near the top of a staircase on the side of a ziggurat");
  set_short("Near the top of a staircase on the side of a ziggurat");
  set_long( (:TO, "long_desc":) );
  set("night long",(:TO, "night_desc":));
  set_items(([  "ziggurat": "The ziggurat rises out of the jungle like a mountain, its stepped sides climbing tier by tier until it breaks through the upper canopy to reach the sky. There appears to be some kind of additional structure right at the top.",

  ({"step", "steps", "staircase"}): "The steps are carved from the same stones as the rest of the ziggurat, in smaller blocks to make it possible to walk up them. Despite the shared origin, the stones of the staircase are a noticeably different hue to the rest of the ziggurat. Something, over the years seems to have stained them an odd orangey brown. They are adorned with carved motifs",

 ({"stonework", "motif", "motifs", "carved motif", "carved motifs"}):"The stones on either side of the"
   +" staircase are decorated with intricately linked carvings and"
   +" sculptures. They carry images of a sun god, and of the ziggurat itself",

 ({"sun", "sun deity", "sun god", "sun motif", "sun god motif", "sun deity motif"}):(:TO, "sun_desc" :),

 ({"ziggurat motif", "ziggurat itself"}):(:TO, "zig_desc" :)
 ]));
  set_smell("default","The scent of the jungle reaches you");
  set_listen("default","The souds of the jungle are all there is to be"
             +" heard.");
}
void init() {
   ::init();
}

string query_path(){
  return ROOMS;
}

string query_name(){
  return base_name(TO)[strlen(ROOMS)..strlen(base_name(TO))-1];
}

string long_desc(){
return "%^ORANGE%^You stand on near the top of the broad staircase"
      +" leading up the side of the ziggurat. A glance down at the ground"
      +" tells you you must be more than a hundred feet up. The%^BOLD%^"
      +" %^CYAN%^s%^BLUE%^k%^CYAN%^y%^RESET%^%^ORANGE%^ opens up above"
      +" you, breathtaking in its scale compared to the enclosed spaces"
      +" you have emerged from. Below you, they unfettered tangle of the"
      +" %^GREEN%^jungle%^ORANGE%^ seems to go on for miles in all"
      +" directions, broken only by the bare patches where traces of the"
      +" ancient city still remain. A little way above, the ziggurat's"
      +" zenith stands in splendid isolation. The stonework either side"
      +" of the staircase is carved with motifs of some kind of sun deity,"
      +" and images of the ziggurat itself.";
}

string night_desc(){
  return "%^BLUE%^You stand on near the top of the broad"
         +" %^ORANGE%^staircase%^BLUE%^ leading up the side of the"
         +" ziggurat. The night sky swaddles you in %^BOLD%^"
         +"%^BLACK%^darkness%^RESET%^%^BLUE%^, and the %^BOLD%^"
         +"%^BLACK%^black silhouettes%^RESET%^%^BLUE%^ of the %^BOLD%^"
         +"%^BLACK%^jungle's tangled shapes%^RESET%^%^BLUE%^ spread out"
         +" for miles all around. You sense that the ziggurat's"
         +" %^RESET%^zenith%^BLUE%^ is not far away.";
}

string sun_desc(){
  string * str;
  int i, count;
  str =  ({"%^YELLOW%^You see a carving of some form of sun deity.",
"                  @(/                  ",
"      #(     /    #&    /        #     ",
"           ((   %/,  /    (%*//        ",
"        %#&    // %%%& /  @(*%         ",
"         %&@&/*%,(&/@. /(&%*           ",
"     (       (@@%/%@#*(@(@@( (*/       ",
"        (//((/%&&(((,.#@@/ #/.         ",
"  ,      @*&%&&(%(#*#***@#// ,/((#     ",
"   @(%/(@%#/#%@(#%*,*,,*%@@@@%#& (#///(",
"           (/(%&/**,**#%(              ",
"         // (#@%#&%&(@&/((     *       ",
"      ((   (@#((((/&(/,(/%%.*          ",
"          &(#  (.(/@#//(   ,(**        ",
"       /&%&&   #/ %((   /(   %/        ",
"     %#        /   //%   *    &/       ",
"                   (%                  ",
"                  *&                   ",
"                  *,                   ",
  });
  count = sizeof(str);
  for (i=0;i<count;i++){
    tell_object(TP, str[i]);
  }
  return "";
}

string zig_desc(){
  string * str;
  int i, count;
  str =  ({"%^BOLD%^%^BLUE%^You see a carving of the ziggurat itself. Some form of light or energy seems to be depicted radiating from the top",
"############### #\# | #/# #############",
"################ #\ | /# ##############",
"################# #\|/# ###############",
"--------------------X------------------",
"############## ,##,@|@.##. ############",
"############# ,##*/%%,,,,##. ##########",
"########### ,##@%  ##,,,,@@##. ########",
"######### ,##%##.../%%..,.#@@##. ######",
"####### ,##%&%%.,,%#%&,.,....@@##. ####",
"##### ,##&&((#.,,%#%&&%,,,....,@@##. ##",
"### ,##(#%##..,.,&%&&%%%... ..,..@@##. ",
"# ,##&&*#(/......%&%((%#,.,..... ...@#.",
",###%(/&., ,,,,,(#(%#####. .  . ....&@#",

  });
  count = sizeof(str);
  for (i=0;i<count;i++){
    tell_object(TP, str[i]);
  }
  return "";
}
