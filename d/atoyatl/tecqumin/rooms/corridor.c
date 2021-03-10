#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit VAULT;

string long_desc();
int mummy;

void create() {
  
  ::create();
  set_property("indoors", 1);
  set_property("light", 2);
  set_short("stone corridor");
  set_long((:TO, "long_desc":));
  set_terrain(STONE_BUILDING);
  set_travel(DECAYED_FLOOR);
  set_smell("default","The musty air cloggs your nose with the"
                     +" dust of ages long past");
  set_listen("default","Hardly a sound makes it inside here. All is"
                      +" still");

  set_items( ([ 
     ({ "wall", "walls", "block", "blocks"}):
                         "The walls are made from huge blocks of solid"
                         +" granite. It is impressive that these massive"
                         +" blocks were moved at all. On top of that,"
                         +" every available surface has been carved and"
                         +" marked with a wild variety of motifs and"
                         +" designs",

  ({ "treess", "plants", "plant", "tree"}):(:TO, "tree_desc":), 
  ({"seated mummy"}): (:TO, "mummy_desc":), 
  ({ "jaguar", "jaguars", "cat", "cats"}):(:TO, "jag_desc":), 
  ({ "serpent", "snake", "plumed serpent", "plumed serpents"}):(:TO, "serp_desc":), 
  ({ "warthog", "warthogs"}):(:TO, "warthog_desc":), 
  ({ "shapes", "shape", "geometric shape", "geometric shapes"}):(:TO, "shape_desc":), 
  ({"recess", "recesses"}) : (:TO, "recess_desc":),

  ({ "carving", "carvings", "motif", "motifs"}):"Carved into every inch"
                         +" of the walls are designs and motifs"
                         +" significant in %^CYAN%^Tecqumin%^RESET%^ life"
                         +" and culture. There are"
                         +" %^GREEN%^trees%^RESET%^ and%^BOLD%^%^GREEN%^"
                         +" plants%^RESET%^, creatures of the forest -"
                         +" %^BOLD%^%^BLACK%^jaguar%^RESET%^,%^ORANGE%^"
                         +" warthog%^RESET%^, bears and%^GREEN%^"
                         +" serpents%^RESET%^. In amongst these are a"
                         +" great many fantastical creatures. Serpents"
                         +" with wings, huge beetles standing upright,"
                         +" plants that seem to move and walk. At places"
                         +" within the designs you also make out a number"
                         +" of odd,%^ORANGE%^ geometric%^RESET%^ shapes"
                         +" which seem very much out of place.",

  "ceiling" : "The ceiling is made of the same gray stone as the walls",

  "floor" :"The floor is smooth, but laid over with a fine film of dust."
  ]) );
  set_search("mummy", (:TO, "search_mummy":));
  set_search("seated mummy", (:TO, "search_mummy":));
  set_search("skeleton", "There is nothing there but bare bones");
  mummy = 1;
}

void reset(){
  ::reset();
  if (!random(3)){
    mummy = 1;
  }
}

string recess_desc(){
  string desc;
  desc =  "Peering into the recesses, you can make"
                             +" out that each one contains a complete"
                             +" human skeleton.";
  if (mummy > 0){
  desc += "\nOne of the recesses also contains a %^ORANGE%^seated mummy";
  }
  return desc;
}

string mummy_desc(){
  if (mummy<1){
    return "You can't see that here.";
  }
  return "A cloth wrapped mummy is seated in one of the recesses. The"
    +" wrappings cover it from head to foot, and it wears a mask of"
    +" %^CYAN%^t%^BOLD%^%^BLUE%^u%^RESET%^%^CYAN%^rqu%^MAGENTA%^o"
    +"%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^se";
}

void search_mummy(){
  object ob;
  if (mummy <1){
    tell_object(TP, "There is nothing there to search");
    return;
  }
  ob = new(MOB + "mummy");
  ob->move(TO);
  tell_room(TO, "As " + TPQCN +" approaches one of the recesses, a"
    +" %^BOLD%^%^WHITE%^cloth wrapped %^RESET%^%^ORANGE%^mummy"
    +" %^RESET%^stands up from it, and lurches to the attack!", TP);
  tell_object(TP, "As " + TPQCN +" approach one of the recesses, a"
    +" %^BOLD%^%^WHITE%^cloth wrapped %^RESET%^%^ORANGE%^mummy"
    +" %^RESET%^stands up from it, and lurches to the attack!"); 
  if (interactive(TP)){
    ob->force_me("rush " + TP->query_name());
  }
  mummy = 0;
}

int query_mummy(){
  return mummy;
}

void set_mummy(int m){
  mummy = m;
}

string jag_desc(){
  string * str;
  int i, count;
  str =  ({"%^BLUE%^You see a carving of a jaguar climbing downwards.",
    "                @@               ",
    "         .     @  @@@@@,         ",
    "                      @@         ",
    "                     @@          ",
    "                   @@            ",
    "                  @@             ",
    "                 @&              ",
    "                @@               ",
    "                @.@@@@           ",
    "            .@@@@@@@@@@    ..    ",
    "           @@@@#@@@@@@@ @@       ",
    "          /@@@@@@@@@@@@@@@       ",
    "          @@@@@@@@@@@@.@@@       ",
    "         @@.@@@@@@@@@@ @@@@      ",
    "          @@@@@/@@/@@%@@@@@(     ",
    "         @@@(@@@@@@&@ @@ @ @     ",
    "      .@ @&@@@@@@@@@@  .         ",
    "       @(@@@@@@@@%@@@@           ",
    "      #@.@@&@@@@@@@@@@           ",
    "      @@@@@@@  &%@@@@#  ##@@@@@  ",
    "     @@ @@@@@@@@@%%@@.@@@@@*(@@@(",
    "     @@@ @@@@@@@@@@@@@@@@@@@@@ & ",
    "      &@@ @@@@@@@@@@@@.@%@@@@@@  ",
    "        @@@@@@@@@@@@@@@@@@@@@@   ",
    "        @@@@    @@@@@@ &     @@& ",
    "        *# @ @     /@@@@         ",
    "                   @@@@%@@       ",
    "                    @@ @@@&      ",
    "                      @@ @@      ",
    "                        @@@@     ",
    "                          @@@@   ",
    "                          @@@@@#*",
    "                           ../   "});
  count = sizeof(str);
  for (i=0;i<count;i++){
    tell_object(TP, str[i]);
  }
  return "";
}


string serp_desc(){
  string * str;
  int i, count;
  str = ({  "%^BLUE%^You see a carving of a %^BOLD%^%^WHITE%^feathered serpent%^RESET%^%^BLUE%^.%^BOLD%^%^WHITE%^",
"               @ @ % (               ",  
"             %/ @  @   %.&           ",  
"            & . @(. .@,,  @#,@       ",  
"           @.@@@@@@,(@%. @%          ",  
"          @@@@.*#/@@ @, &%/./@,*##   ",  
"         @@#@@%@     .@@#@@          ", 
"            @.      %#     @@@@@,    ",  
"                          *@*,, #@(* ",  
"               @.@ %/# @@&@@@@       ",  
"            @&(%.@@&&& ,@@ *@ @@     ",  
"        @  @@.@&&             @.@    ",  
"    ,   (  @@@@   ,,@@##@@      (    ",  
"     @ * ##/@@*# @@*   .#@ @@(       ",  
"   /  /     @,,.* @      *(#  @      ",  
"     @@..    #@ %@@&@   @@@(@        ",  
"      ,@(//@#@ @.# /@@@%@ % .&       ",  
"         .,   # /#  @@ (,@           ",  
"         %       #@  ,&  /           ",  
"               *%(@@,@/&(            ",  
"                  &@  @              ",  
"                ,#&, .#  *           "});   
  count = sizeof(str);
  for (i=0;i<count;i++){
    tell_object(TP, str[i]);
  }
  return "";
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

string warthog_desc(){
  string * str;
  int i, count;
  str =  ({"%^ORANGE%^You see a carving of a warthog.",
"                      @*               ",
"                     @*@*@@@@@@        ",
"            @@       @*#@*@@@@@@@@     ",
"          ,@       &&\\\\\\\\/////\\\\@@@@@  ",
" ,^,    &'@     &@*@ # @////\\\\//\\\\\\#@  ",
"@* *@@&  @  &@/\\\\\\\\\\\\\\\\\\/\\\\\\///\\///\\\\\\@",
"#* **@   @\\\\\\\\\\///////\\\\\\//////\\\\\\\\\\\\\\\\",
"@* @*@  @./////\\\\\\\\\\\\\\/////\\\\\\\\///////@",
" @@ *@@ & @&\\\\\\///////\\\\//@\\\\\\@@%////@ ",
"  ////\\\\@@//\\@@*@\\\\\\\\\\/\\\\\\ /\\\\\\//@@/@  ",
"   @@@@*@\\\\\\//////\\\\\\\\\\@@//////\\\\\\@@   ",
"           \\\\\\\\\\\\\\////\\/@@@\\\\\\\\/(@@    ",
"             @////\\\\\\\\/@@@@\\\\\\@        " 
  });
  count = sizeof(str);
  for (i=0;i<count;i++){
    tell_object(TP, str[i]);
  }
  return "";
}


string shape_desc(){
  string * str;
  int i, count;
  str =  ({"%^MAGENTA%^You see a carving of some strange shapes.",
"                #@@@@@                ",
"      %        ,@@*@&@@         ,     ",
"    .@        % &@   @@ %             ",
"    @@         @@   . @@         @@*  ",
"   (@/@. *    @ @@@ &@@.&(    . #@@   ",
"    @@./@@@   @#,@@ &@%,@   @@@@(@@#  ",
"       %@&%@   @%@@@@/,@   (,@@@      ",
"         @,@   ,%@@@@*.*   @ @        ",
"         &@%    .@*@@@.#   .@@        ",
"         &@     &@@%@@.     #@        ",
"        /(     @& ,@&*@@      @.      ",
"      /@     .@.@@ ,.@@#@(.    @      ",
"    &@    ,@( @#@ . %.@.@ .@%    @*   ",
"   /.    #*  @,@ &@ @/ @%%   @,    @  ",
"  .    (@    @@@.&   @%@@&*.  @%    % ",
" #&    #  &@  %@@     @@@  @%  @    , ",
" (&    @@@&   &@@     @@,   @/@@    , ",
"  .@  (@@/   * ,@(    @# &/  @@@,. ((.",
"   `''   (@&@    @   @,   @@@@   `''  ",
"         (@ %@   @@ &@   @@ @         ",
"        @ **  @(  @ @   @   * @       ",
"       .%   %/ @/ @(@  @  @   .&      ",
"       *.  %  &@@ &(@ @@@  ,   @      ",
"        @ @   &@@.@ @ @@@   @ %       ",
"         @    (  %@ @@  #    /        ",
"             /#,@( @( @*/@            ",
"           .,, /(*/%%/ ,(%%           "  });
  count = sizeof(str);
  for (i=0;i<count;i++){
    tell_object(TP, str[i]);
  }
  return "";
}


