#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("heart clasp");
   set_id(({"clasp","white flower clasp","flower clasp","cloak clasp"}));
   set_short("%^BOLD%^%^WHITE%^White flower clasp%^RESET%^");
   set_long("Designed as a whimsical flower, this cloak clasp "+
      "is studded with %^YELLOW%^topaz %^RESET%^and %^BOLD%^"+
      "moonstone%^RESET%^.\n\n"+
"%^BOLD%^                     @@@@ \n"+
"                 @@@@@@@@ \n"+
"                @@@    @@@                  @@@@@@@@@@@@@ \n"+
"              @@@      @@@               @@@@@@       @@@@ \n"+
"             @@@        @@@           @@@@    %^RESET%^//((((((/  %^BOLD%^@@@ \n"+
"            @@@          @@@@       @@@   %^RESET%^ ///////((((((/ %^BOLD%^@@@ \n"+
"            @@@           @@@@@@@@@@@        %^RESET%^ /////(((((/ %^BOLD%^@@@ \n"+
"            @@                @@@@@@          %^RESET%^ /((((((((/ %^BOLD%^@@@ \n"+
"            @@                               %^RESET%^ ((  ///(((  %^BOLD%^@@@ \n"+
"            @@@                             %^RESET%^ /     ///(/ %^BOLD%^@@@ \n"+
"            @@@    %^RESET%^%^ORANGE%^  /%^RESET%^                      /      ////%^BOLD%^ @@@@ \n"+
"             @@@    %^RESET%^%^ORANGE%^  /                       %^BOLD%^%^WHITE%^         @@@ \n"+
"         @@@@@@@@    %^RESET%^%^ORANGE%^   /                          %^BOLD%^%^WHITE%^    @@ \n"+
"    @@@@@@@@@@@@        %^RESET%^%^ORANGE%^  /                         %^BOLD%^%^WHITE%^    @@ \n"
"  @@@@                   %^RESET%^%^ORANGE%^  ///                     %^BOLD%^%^WHITE%^    @@ \n"+
" @@                       %^RESET%^%^ORANGE%^   ///           %^BOLD%^%^WHITE%^            @@ \n"+
"@@@                        %^RESET%^%^ORANGE%^   /////             %^BOLD%^%^WHITE%^      @@ \n"+
" @@                        %^RESET%^%^ORANGE%^    6  //////6      %^BOLD%^%^WHITE%^      @@@@ \n"+
" @@@  %^RESET%^   /////              %^YELLOW%^     66666666       %^WHITE%^      @@ \n"+
" @@@   %^RESET%^   //////               %^YELLOW%^ 66666666666          %^WHITE%^ @@@@@@ \n"+
" @@    %^RESET%^   //////            %^YELLOW%^   6%%%%%%%%%%%6          %^WHITE%^  @@@@@@ \n"+
" @@    %^RESET%^  /////////////      %^YELLOW%^  6%%%%%%%%%%%666         %^WHITE%^  @@@@@@@ \n"+
" @@@   %^RESET%^  ////               %^YELLOW%^66666666666666666          %^WHITE%^   @@@@@@@ \n"+
"  @@@                   %^YELLOW%^    6666666666666666          %^WHITE%^      @@@@@@@ \n"+
"   @@@@               %^YELLOW%^      666666666666666          %^WHITE%^       @@@@@@@ \n"+
"     @@@@         %^YELLOW%^     ((   66666666666666            %^WHITE%^       @@@@@@@ \n"+
"         @@@@         %^YELLOW%^        66666666666              %^RESET%^%^ORANGE%^  ^^^^ %^BOLD%^%^WHITE%^ @@@@@@ \n"+
"           @@@@@@@           %^YELLOW%^  666666666666            %^RESET%^%^ORANGE%^  ^^^^//%^BOLD%^%^WHITE%^ @@@@@ \n"+
"              @@@      %^YELLOW%^        6666((666/6              %^RESET%^%^ORANGE%^^^^^//// %^BOLD%^%^WHITE%^@@@@ \n"+
"             @@@   %^RESET%^     ////////    /////              %^RESET%^%^ORANGE%^ ^^/////// %^BOLD%^%^WHITE%^@@@ \n"+
"            @@@      %^RESET%^  //////    ////////            %^RESET%^%^ORANGE%^  ^^^^/////// %^BOLD%^%^WHITE%^@@ \n"+
"           @@      %^RESET%^  ////////// ////////              %^RESET%^%^ORANGE%^ ^^^//////// %^BOLD%^%^WHITE%^@@ \n"+
"           @@      %^RESET%^ /////////   ///////%^ORANGE%^//               %^RESET%^%^ORANGE%^  ^^^^^^^^ %^BOLD%^%^WHITE%^@ \n"+
"          @@@     %^RESET%^ /////////   /////////%^ORANGE%^/       %^BOLD%^%^WHITE%^  @@@@@@@@@@@@@@@@@@ \n"+
"          @@       %^RESET%^   //////   //////// %^ORANGE%^/       %^BOLD%^%^WHITE%^  @@         @@  @@ \n"+
"          @@         %^RESET%^  ///     //////// %^ORANGE%^/       %^BOLD%^%^WHITE%^  @@ \n"+
"          @@@                 %^RESET%^ //////// %^ORANGE%^/     %^BOLD%^%^WHITE%^   @@@ \n"+
"           @@@@@       @@@@@@ %^RESET%^ ///////// %^ORANGE%^/     %^BOLD%^%^WHITE%^  @@@ \n"+
"              @@@@     @@  @@  %^RESET%^///////// %^ORANGE%^/     %^BOLD%^%^WHITE%^  @@@ \n"+
"                @@    @@@  @@@ %^RESET%^///////// %^ORANGE%^/     %^BOLD%^%^WHITE%^  @@@ \n"+
"                @@   @@@    @@@ %^RESET%^////////  %^ORANGE%^/    %^BOLD%^%^WHITE%^  @@ \n"+
"                @@@@@@@     @@@@%^RESET%^ ///////  %^ORANGE%^/    %^BOLD%^%^WHITE%^  @@ \n"+
"                  @@         @@@ %^RESET%^////////  %^ORANGE%^/   %^BOLD%^%^WHITE%^  @@ \n"+
"                               @@ %^RESET%^//////// %^ORANGE%^//   %^BOLD%^%^WHITE%^ @@ \n"+
"                               @@@ %^RESET%^///////  %^ORANGE%^/   %^BOLD%^%^WHITE%^ @@ \n"+
"                                @@@  %^RESET%^//////  %^ORANGE%^/  %^BOLD%^%^WHITE%^ @@ \n"+
"                                  @@@ %^RESET%^/////   %^ORANGE%^/ %^BOLD%^%^WHITE%^ @@ \n"+
"                                   @@@@ %^RESET%^ ////   %^BOLD%^%^WHITE%^ @@ \n"+
"                                      @@@@@    @@@ \n"+
"                                          @@@@@@ %^RESET%^\n"
   );
   set_value(450);
   set_type("ring");
   set_weight(1);
   set_ac(0);
   set_limbs(({"neck"}));
}
