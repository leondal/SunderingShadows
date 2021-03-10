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
  set_name("Midway up a staircase on the side of a ziggurat");
  set_short("Midway up a staircase on the side of a ziggurat");
  set_long( (:TO, "long_desc":) );
  set("night long",(:TO, "night_desc":));

  set_items(([  "ziggurat":"The ziggurat rises out of the jungle like a mountain, its stepped sides climbing tier by tier until it breaks through the upper canopy to reach the sky. There appears to be some kind of additional structure right at the top.",

  ({"step", "steps", "staircase"}): "The steps are carved from the same stones as the rest of the ziggurat, in smaller blocks to make it possible to walk up them. Despite the shared origin, the stones of the staircase are a noticeably different hue to the rest of the ziggurat. Something, over the years seems to have stained them an odd orangey brown. They are adorned with carved motifs",

 ({"stonework", "motif", "motifs", "carved motif", "carved motifs"}):"The stones on either side of the staircase are decorated with intricately linked carvings and sculptures. At this level they are mostly some form of tree or jungle spirit",

 ({"tree", "tree spirit", "jungle spirit"}):(:TO, "tree_desc" :)
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
return "%^ORANGE%^You are about halfway up the broad staircase which"
      +" climbs this face of the ziggurat. Trailing %^GREEN%^vines"
      +"%^ORANGE%^ and %^GREEN%^creepers%^ORANGE%^ stretch across from"
      +" the upper canopy of the surrounding %^GREEN%^jungle%^ORANGE%^"
      +" and settle on the stones. Intricately carved stonework is all"
      +" around you, marked with the motifs of some form of tree or jungle spirit.";
}

string night_desc(){
  return "%^BLUE%^You are standing on the broad staircase that leads up"
        +" this face of the ziggurat. Glimpses of the night sky can be"
        +" seen through occasional gaps in the upper canopies of the"
        +" surrounding %^GREEN%^jungle%^BLUE%^. Trailing %^GREEN%^vines"
        +" %^BLUE%^and %^GREEN%^creepers%^BLUE%^ threaten to grab and"
        +" snare unwary feet in the %^BOLD%^%^BLACK%^darkness"
        +"%^RESET%^%^BLUE%^.";
}

string tree_desc(){
  string * str;
  int i, count;
  str =  ({"%^GREEN%^You see a carving of a tree or jungle spirit.",
           "                                   ",
           "            #&&%%(%(.%%.#%         ",    
           "      %% *(&&(%%@#/%&%( #          ",  
           "       %%%@##%#%#%%#%##(,#,%(      ",    
           "      /#%#%#%%&%&%%#%#(%&%&&(&%%%/.",    
           "    #%%#&%#%( )%%%( )%(%%#%%#*(%   ", 
           "   /(#%##%%%&.%%&%(###&%(%%%%(##   ",  
           "    . (,#.#%#% %%#%%&&%(%#(%/(,.   ",    
           "     ( #*##&&%%%&,&%( %,.#         ", 
           "     %&/   % . %%/#%%#.,(# .  . *  ",    
           "        //   #(#%#&%(%   (#. * *   ",    
           "            &#%&&%%&(&&/           ",  
           "          %%   %#&%%  ,&%%         ",  
           "         #&     %&%&%/    #%       ",    
           "        %&      %&&%&,    &&       ",    
           "       &&&     %%&&&%%(    &%.     ",    
           "       # &    &%&% %&%,    #%      ",    
           "             &&&%  #&&%.           ",    
           "          %&&&%&&  &%&&&&%.        ",
           "          && &&&& %& & & &%        ", 
           "         %&  &  &  & &  &  &%      ",
  });
  count = sizeof(str);
  for (i=0;i<count;i++){
    tell_object(TP, str[i]);
  }
  return "";
}
