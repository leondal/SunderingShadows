#include <std.h>
inherit "/d/magic/symbols/holy_symbol.c";

void create(){
   ::create();
   set_id(({"holy symbol","symbol","callamir_holy_symbol","pendant","arandur pendant","quartz pendant","arandur and quartz pendant"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_name("arandur and quartz pendant");
   set_short("%^BOLD%^%^WHITE%^ar%^BOLD%^%^CYAN%^a%^BOLD%^%^WHITE%^nd%^BOLD%^%^GREEN%^u%^BOLD%^%^WHITE%^r and %^RESET%^quartz %^BOLD%^%^WHITE%^pendant%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This surprisingly light pendant is suspended from woven strands of %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^%^WHITE%^lv%^RESET%^e%^BOLD%^%^BLACK%^r%^BOLD%^%^WHITE%^ "
"thread, which together are more %^RESET%^%^CYAN%^supple %^BOLD%^%^WHITE%^and %^RESET%^%^RED%^strong %^BOLD%^%^WHITE%^than their appearance would suggest. From its length is supported a "
"perfect open circle of arandur metal that gleams a bright si%^BOLD%^%^CYAN%^l%^BOLD%^%^WHITE%^ver-b%^BOLD%^%^CYAN%^l%^BOLD%^%^WHITE%^ue.  Loosely hanging within the circle, so that it swings "
"with the wearer's movements, is a %^RESET%^%^ORANGE%^tiny lapine figure %^BOLD%^%^WHITE%^cut from %^RESET%^clear quartz crystal%^BOLD%^%^WHITE%^, its feet extended as though it is perpetually "
"in flight.\n\n%^RESET%^"
"\n%^RESET%^%^CYAN%^   ........................................                 "
"\n%^RESET%^%^CYAN%^............................%^BOLD%^%^WHITE%^D~~~~+:~~%^RESET%^..%^BOLD%^%^WHITE%^D%^RESET%^%^CYAN%^...................."
"\n%^RESET%^%^CYAN%^ ............................%^BOLD%^%^WHITE%^O%^RESET%^:~%^BOLD%^%^WHITE%^DDDDDDDD%^RESET%^:,%^BOLD%^%^WHITE%^N%^RESET%^%^CYAN%^ ................"
"\n%^RESET%^%^CYAN%^ .................   .. .......%^BOLD%^%^WHITE%^=N%^RESET%^:~%^BOLD%^%^WHITE%^D7%^RESET%^....%^BOLD%^%^WHITE%^N7~N%^RESET%^%^CYAN%^..............."
"\n%^RESET%^%^CYAN%^... . ............ ............ . ,%^BOLD%^%^WHITE%^DN%^RESET%^~~~~%^BOLD%^%^WHITE%^::,%^RESET%^~~~~~~.%^BOLD%^%^WHITE%^NN%^RESET%^%^CYAN%^ ......"
"\n%^RESET%^%^CYAN%^....   ... . . ..,. .... .%^BOLD%^%^WHITE%^DDDDDDDDD8,%^RESET%^%^CYAN%^...%^BOLD%^%^WHITE%^DD%^RESET%^~~~~~%^BOLD%^%^CYAN%^.D%^RESET%^~~~~.%^BOLD%^%^WHITE%^N%^RESET%^%^CYAN%^.... "
"\n%^RESET%^%^CYAN%^.................... %^BOLD%^%^WHITE%^ND.%^RESET%^~~~~~~~~~~~~~~~~~~~~~~~~~~~..%^BOLD%^%^WHITE%^=D%^RESET%^%^CYAN%^   . "
"\n%^RESET%^%^CYAN%^........ .... .....%^BOLD%^%^WHITE%^MN%^RESET%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~..%^BOLD%^%^WHITE%^.D%^RESET%^%^CYAN%^,     "
"\n%^RESET%^%^CYAN%^............. ....%^BOLD%^%^WHITE%^D%^RESET%^.~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.%^BOLD%^%^WHITE%^.D%^RESET%^%^CYAN%^ .. ...."
"\n%^RESET%^%^CYAN%^............%^BOLD%^%^WHITE%^D%^RESET%^%^CYAN%^..%^BOLD%^%^WHITE%^DDD%^RESET%^.~~~~~~~~~~~~~~~~~~~~~~~~~~~~%^BOLD%^%^WHITE%^DDDZDNN%^RESET%^%^CYAN%^:.. .."
"\n%^RESET%^%^CYAN%^.............%^RESET%^~~~~%^BOLD%^%^WHITE%^,%^RESET%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%^BOLD%^%^WHITE%^NDZ%^RESET%^~~~~~%^BOLD%^%^WHITE%^,%^RESET%^%^CYAN%^..."
"\n%^RESET%^%^CYAN%^.........%^BOLD%^%^WHITE%^N%^RESET%^%^CYAN%^..%^BOLD%^%^WHITE%^=%^RESET%^.~~~~~~~~~~~~%^BOLD%^%^WHITE%^:%^RESET%^~~...........%^BOLD%^%^WHITE%^:%^RESET%^~~~~~%^BOLD%^%^WHITE%^,%^RESET%^~~.%^BOLD%^%^WHITE%^O?77%^RESET%^~.%^BOLD%^%^WHITE%^,D%^RESET%^%^CYAN%^  "
"\n%^RESET%^%^CYAN%^..... . %^BOLD%^%^WHITE%^N~DNN%^RESET%^.....%^RESET%^~~~~~~~~~~~~%^BOLD%^%^WHITE%^DDD8DDNDDDDDDNDN%^RESET%^~~%^BOLD%^%^WHITE%^=%^RESET%^~~~.%^BOLD%^%^WHITE%^ND%^RESET%^%^CYAN%^.. .."
"\n%^RESET%^%^CYAN%^... . %^BOLD%^%^WHITE%^N%^RESET%^~~~%^BOLD%^%^WHITE%^DDDDD%^RESET%^%^CYAN%^...%^RESET%^~~~~~~~~~~~%^BOLD%^%^WHITE%^NDDN%^RESET%^%^CYAN%^. .. ..... .. .%^BOLD%^%^WHITE%^ZN$%^RESET%^~~~,..%^BOLD%^%^WHITE%^D%^RESET%^%^CYAN%^.."
"\n%^RESET%^%^CYAN%^....%^BOLD%^%^WHITE%^D%^RESET%^?.~~%^BOLD%^%^WHITE%^D$%^RESET%^%^CYAN%^ ......%^RESET%^~~~~~~~~~~~%^BOLD%^%^WHITE%^D%^RESET%^%^CYAN%^.      . .   . .     .%^BOLD%^%^WHITE%^DDDDD%^RESET%^%^CYAN%^.. "
"\n%^RESET%^%^CYAN%^. %^BOLD%^%^WHITE%^D%^RESET%^...~%^BOLD%^%^WHITE%^D%^RESET%^%^CYAN%^.....%^BOLD%^%^WHITE%^NNDM%^RESET%^~~~~~~~~~~%^BOLD%^%^WHITE%^:8%^RESET%^%^CYAN%^ . . . . .    ... . . . .    .."
"\n%^BOLD%^%^WHITE%^N%^RESET%^...%^BOLD%^%^WHITE%^8D%^RESET%^%^CYAN%^ .....%^BOLD%^%^WHITE%^I%^RESET%^.~~~~~~~~~~~~%^BOLD%^%^WHITE%^D%^RESET%^%^CYAN%^,....... .............. ........."
"\n%^BOLD%^%^WHITE%^=N%^RESET%^%^CYAN%^  ...... %^BOLD%^%^WHITE%^8%^RESET%^:~~~%^BOLD%^%^WHITE%^MDDDDDDN%^RESET%^%^CYAN%^. .. ...... ... . ........ ... . ..."
"\n%^RESET%^%^CYAN%^... ......%^BOLD%^%^WHITE%^N%^RESET%^~~~%^BOLD%^%^WHITE%^:D%^RESET%^%^CYAN%^. ............  .    .    . .  .    . ....  "
"\n%^RESET%^%^CYAN%^. . ... %^BOLD%^%^WHITE%^8%^RESET%^.~~~%^BOLD%^%^WHITE%^+N%^RESET%^%^CYAN%^.. ..... . . . .... ..    ..................."
"\n%^RESET%^%^CYAN%^......%^BOLD%^%^WHITE%^D%^RESET%^..:~~%^BOLD%^%^WHITE%^N%^RESET%^%^CYAN%^... .. .............. .... ...................."
"\n%^RESET%^%^CYAN%^.... %^BOLD%^%^WHITE%^D%^RESET%^.....%^BOLD%^%^WHITE%^D%^RESET%^%^CYAN%^.... ..........................................."
"\n%^RESET%^%^CYAN%^      %^BOLD%^%^WHITE%^~D:%^RESET%^%^CYAN%^  .                  ..............................%^RESET%^\n");
}

