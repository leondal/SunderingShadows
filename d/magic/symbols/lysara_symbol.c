#include <std.h>
inherit "/d/magic/symbols/holy_symbol.c";

void create(){
   ::create();
   set_id(({"holy symbol","symbol","lysara_holy_symbol","amulet","silver amulet","three ringed amulet","amulet of interlocked rings"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_name("amulet of interlocked rings");
   set_short("%^RESET%^%^CYAN%^amulet of %^BOLD%^%^BLACK%^in%^RESET%^t%^BOLD%^%^WHITE%^er%^RESET%^lo%^BOLD%^%^BLACK%^ck%^RESET%^i%^BOLD%^%^WHITE%^ng %^RESET%^%^CYAN%^rings%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This simple amulet hangs upon a chain of %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^%^WHITE%^lv%^RESET%^e%^BOLD%^%^BLACK%^r%^BOLD%^%^WHITE%^, its links polished and "
"%^RESET%^%^MAGENTA%^flawlessly %^BOLD%^%^WHITE%^worked. They lead down to an amulet formed of three metallic hoops, each about an inch in diameter. The hoops have been interlocked in such "
"a %^RESET%^%^CYAN%^careful %^BOLD%^%^WHITE%^manner that they cannot be moved out of place. The upper ring is made of the same %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^%^WHITE%^lv%^RESET%^e%^BOLD%^%^BLACK%^r %^BOLD%^%^WHITE%^as the chain, while of the lower two one is made of %^BOLD%^%^BLACK%^ebony%^BOLD%^%^WHITE%^, and one of %^RESET%^ivory%^BOLD%^%^WHITE%^. The result is a plain, but striking pattern for its stark coloration.\n\n%^RESET%^"
"\n%^RESET%^%^CYAN%^                     .   :       : .                        "
"\n%^RESET%^%^CYAN%^                      .NMMMMMMMMMMMM.   .                   "
"\n%^RESET%^%^CYAN%^                  : MMMMMM8~. .~$MMMMMM :                   "
"\n%^RESET%^%^CYAN%^                 7MMMZ :.      .   . ZMMMM.                 "
"\n%^RESET%^%^CYAN%^               .MMM+ .               .:?MMM..               "
"\n%^RESET%^%^CYAN%^             .,MMM                       OMMN.              "
"\n%^RESET%^%^CYAN%^            ,IMM?:                        ?MMI,             "
"\n%^RESET%^%^CYAN%^            DMM                            .MMD:            "
"\n%^RESET%^%^CYAN%^            MMZ                              MM,            "
"\n%^RESET%^%^CYAN%^          :DMM.                            .,MMM:           "
"\n%^RESET%^%^CYAN%^           MM, %^BOLD%^%^WHITE%^.        . .    %^BOLD%^%^BLACK%^.       . .   %^RESET%^%^CYAN%^,MM            "
"\n%^RESET%^%^CYAN%^          +MN %^BOLD%^%^WHITE%^.MMMMMMMMMMM= , %^BOLD%^%^BLACK%^, .MMMMMMMMMMM= %^RESET%^%^CYAN%^MM=           "
"\n         %^BOLD%^%^WHITE%^, +MMMMMMMNDNMMMMMM %^BOLD%^%^BLACK%^?MMMMMMMNDNMMMMM7%^RESET%^%^CYAN%^MM8,%^BOLD%^%^BLACK%^.         "
"\n       %^BOLD%^%^WHITE%^. MMMMM,.,.   .  ,%^BOLD%^%^BLACK%^. MMMMM..,. .    %^BOLD%^%^BLACK%^,. O%^RESET%^%^CYAN%^NMN%^BOLD%^%^BLACK%^8.         "
"\n      %^BOLD%^%^WHITE%^.ZMMM+%^RESET%^%^CYAN%^7~          %^BOLD%^%^BLACK%^,$MMM+%^BOLD%^%^WHITE%^IMM$.          ~%^RESET%^%^CYAN%^MMO%^BOLD%^%^BLACK%^NM$.       "
"\n    %^BOLD%^%^WHITE%^. MMM %^RESET%^%^CYAN%^:MM        %^BOLD%^%^BLACK%^  MMM  %^BOLD%^%^WHITE%^.  MMM:         %^RESET%^%^CYAN%^.MM, %^BOLD%^%^BLACK%^MMM:  .   "
"\n    %^BOLD%^%^WHITE%^.MMM  %^RESET%^%^CYAN%^.MM=.     %^BOLD%^%^BLACK%^..MMM     %^BOLD%^%^WHITE%^ :MMM  .      %^RESET%^%^CYAN%^=MM  %^BOLD%^%^BLACK%^:MMM      "
"\n    %^BOLD%^%^WHITE%^MM$: %^RESET%^%^CYAN%^..$MM       %^BOLD%^%^BLACK%^.MM$:     %^BOLD%^%^WHITE%^. :ZMM      %^RESET%^%^CYAN%^.:MMM.  %^BOLD%^%^BLACK%^~ZMM     "
"\n  %^BOLD%^%^WHITE%^,MMM: .%^RESET%^%^CYAN%^   MMM     %^BOLD%^%^BLACK%^,MMM:.        %^BOLD%^%^WHITE%^:OMM     %^RESET%^%^CYAN%^ :MM    %^BOLD%^%^BLACK%^.:OMM    "
"\n %^BOLD%^%^WHITE%^.IMM .  %^RESET%^%^CYAN%^   .MM?:  %^BOLD%^%^BLACK%^.7MM            %^BOLD%^%^WHITE%^:MMM.  %^RESET%^%^CYAN%^,?MM.      %^BOLD%^%^BLACK%^~MMM.. "
"\n %^BOLD%^%^WHITE%^ MM+    %^RESET%^%^CYAN%^   .,MMN. %^BOLD%^%^BLACK%^.MM+            %^BOLD%^%^WHITE%^.+MM  %^RESET%^%^CYAN%^,NMM,.       %^BOLD%^%^BLACK%^+MM.  "
"\n %^BOLD%^%^WHITE%^,MM     %^RESET%^%^CYAN%^     .MMM %^BOLD%^%^BLACK%^,MM             %^BOLD%^%^WHITE%^  MM, %^RESET%^%^CYAN%^MMM? .       %^BOLD%^%^BLACK%^.MM,  "
"\n%^BOLD%^%^WHITE%^.OMM:    %^RESET%^%^CYAN%^     ..DMMM,%^BOLD%^%^BLACK%^8~        ..   %^BOLD%^%^WHITE%^~MMO%^RESET%^%^CYAN%^NMD          %^BOLD%^%^BLACK%^,MMO. "
"\n %^BOLD%^%^WHITE%^NMN: .   %^RESET%^%^CYAN%^        MMMMD ,         , $%^BOLD%^%^WHITE%^NMN%^RESET%^%^CYAN%^8  .          %^BOLD%^%^BLACK%^:NMN. "
"\n %^BOLD%^%^WHITE%^DMM~     %^RESET%^%^CYAN%^      . , ZMMMMMMNZ$ZNMMMM$%^BOLD%^%^WHITE%^MMD,%^RESET%^%^CYAN%^.           %^BOLD%^%^BLACK%^.=MM8  "
"\n %^BOLD%^%^WHITE%^+MM               %^BOLD%^%^BLACK%^+MZ %^RESET%^%^CYAN%^=MMMMMMMMMMM$ %^BOLD%^%^WHITE%^MM+               %^BOLD%^%^BLACK%^MM+  "
"\n %^BOLD%^%^WHITE%^.MM.              %^BOLD%^%^BLACK%^ MM.     %^RESET%^%^CYAN%^,,,   %^BOLD%^%^WHITE%^..,MM               %^BOLD%^%^BLACK%^.MM   "
"\n %^BOLD%^%^WHITE%^:NMM.             %^BOLD%^%^BLACK%^:NMM..         %^BOLD%^%^WHITE%^..MMM:             %^BOLD%^%^BLACK%^.MMM:. "
"\n  %^BOLD%^%^WHITE%^.MM7               %^BOLD%^%^BLACK%^MM7 .        %^BOLD%^%^WHITE%^  MM~.             %^BOLD%^%^BLACK%^ MM~   "
"\n   %^BOLD%^%^WHITE%^NMM               %^BOLD%^%^BLACK%^NMM          %^BOLD%^%^WHITE%^ MMN,              %^BOLD%^%^BLACK%^MMN:   "
"\n   %^BOLD%^%^WHITE%^:ZMM~,.           %^BOLD%^%^BLACK%^:ZMM~:      %^BOLD%^%^WHITE%^~MMZ:             %^BOLD%^%^BLACK%^~MMZ:.   "
"\n    %^BOLD%^%^WHITE%^,=MMM,           %^BOLD%^%^BLACK%^ :=MMM,   %^BOLD%^%^WHITE%^.IMMM,.           %^BOLD%^%^BLACK%^:IMMM,     "
"\n      %^BOLD%^%^WHITE%^:MMM:,          %^BOLD%^%^BLACK%^ .:MMM:,%^BOLD%^%^WHITE%^:MMM:,.          %^BOLD%^%^BLACK%^,:MMM::      "
"\n        %^BOLD%^%^WHITE%^8MMM+ ,.     .    %^BOLD%^%^BLACK%^8MMM%^BOLD%^%^WHITE%^+ N             %^BOLD%^%^BLACK%^?MMMM         "
"\n         %^BOLD%^%^WHITE%^.:MMMMMMI..   =MMM:%^BOLD%^%^BLACK%^:MMMMMMI   %^BOLD%^%^BLACK%^. =MMMMMM,.          "
"\n             %^BOLD%^%^WHITE%^=MMMMMMMMMMMMM= %^BOLD%^%^BLACK%^. =MMMMMMMMMMMMM= ,            "
"\n              %^BOLD%^%^WHITE%^ ,,  ...  ,,.     %^BOLD%^%^BLACK%^ ,, . .   ,,                %^RESET%^\n");
}

