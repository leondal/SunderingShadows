#include <std.h>
#include "../githyanki.h"

inherit STORAGE"barracks.c";

void create(){
   ::create();
   set_long(::query_long()+"%^ORANGE%^On the far wall, a much larger set of runes dominates the wall.%^RESET%^\n");
   set_exits(([
      "east" : ROOMS"1_34",

    ]));  

add_item("runes","%^BOLD%^You look over the runes. As you stare at them your vision seems to "+
"swim and the runes slowly change. Symbols meld or split into letters..\n\n\n "+
"%^RESET%^%^RED%^                      O . G I  T  H                       \n"+
"%^RESET%^%^RED%^                  R       %^RESET%^%^ORANGE%^O   D   O%^RESET%^%^RED%^ "+
"  G                    \n"
"%^RESET%^%^RED%^               B     %^RESET%^%^ORANGE%^R  . %^RESET%^%^GREEN%^K  A   N  "+
"     %^RESET%^%^RED%^ A                  \n"
"%^RESET%^%^RED%^                  %^RESET%^%^ORANGE%^O   %^RESET%^%^GREEN%^ L . %^BLUE%^%^"+
"BOLD%^ I  T    %^RESET%^%^GREEN%^D   %^RESET%^%^ORANGE%^F   %^RESET%^%^RED%^ V               \n"+
"%^RESET%^%^RED%^            E  %^RESET%^%^ORANGE%^W  %^RESET%^%^GREEN%^ L   %^BLUE%^%^BOLD%^"+
" O . %^RESET%^%^MAGENTA%^ R    %^BLUE%^%^BOLD%^H   %^RESET%^%^GREEN%^K   %^RESET%^%^ORANGE%^T"+
"   %^RESET%^%^RED%^ E             \n"+
"%^RESET%^%^RED%^                    %^BLUE%^%^BOLD%^ N          %^RESET%^%^MAGENTA%^T   %^BLUE%^"+
"%^BOLD%^ I   %^RESET%^%^GREEN%^E  %^RESET%^%^ORANGE%^I   %^RESET%^%^RED%^ U           \n"+
"%^RESET%^%^RED%^          H  %^RESET%^%^ORANGE%^E  %^RESET%^%^GREEN%^ I %^BLUE%^%^BOLD%^O    "+
"%^RESET%^%^MAGENTA%^V E R . %^BOLD%^%^MAGENTA%^S    %^RESET%^%^MAGENTA%^H   %^BLUE%^%^BOLD%^D                    \n"+
"%^RESET%^%^RED%^                      %^RESET%^%^MAGENTA%^L     .    %^BOLD%^%^MAGENTA%^W   "+
"%^RESET%^%^MAGENTA%^E   %^RESET%^%^GREEN%^ E  %^RESET%^%^ORANGE%^A   %^RESET%^%^RED%^ S          \n"+
"%^RESET%^%^RED%^        T   %^RESET%^%^ORANGE%^H  %^RESET%^%^GREEN%^T  %^BLUE%^%^BOLD%^H     "+
"%^BOLD%^%^MAGENTA%^ U    %^RESET%^%^BOLD%^. R  %^BOLD%^%^MAGENTA%^O    %^BLUE%^%^BOLD%^ B                     \n"+
"%^RESET%^%^RED%^                    %^RESET%^%^MAGENTA%^ I     %^RESET%^%^BOLD%^ E        "+
"%^RESET%^%^MAGENTA%^ R    %^RESET%^%^GREEN%^P  %^RESET%^%^ORANGE%^M   %^RESET%^%^RED%^ F         \n"+
"%^RESET%^%^RED%^        H   %^RESET%^%^ORANGE%^T %^RESET%^%^GREEN%^ S  %^BLUE%^%^BOLD%^T     "+
"%^BOLD%^%^MAGENTA%^O  %^RESET%^%^BOLD%^D    %^RESET%^%^BOLD%^S  %^BOLD%^%^MAGENTA%^R    %^BLUE%^%^BOLD%^U                  \n"+
"%^RESET%^%^RED%^                     %^RESET%^%^MAGENTA%^S        %^RESET%^%^BOLD%^ I      "+
"%^RESET%^%^MAGENTA%^E    %^RESET%^%^GREEN%^T  %^RESET%^%^ORANGE%^A   %^RESET%^%^RED%^ R        \n"+
"%^RESET%^%^RED%^        T  %^RESET%^%^ORANGE%^E  %^RESET%^%^GREEN%^ N %^BLUE%^%^BOLD%^ S     "+
" %^BOLD%^%^MAGENTA%^Y        %^BOLD%^%^MAGENTA%^D    %^BLUE%^%^BOLD%^ R                  \n"+
"%^RESET%^%^RED%^                     %^RESET%^%^MAGENTA%^E              %^RESET%^%^MAGENTA%^ "+
"D     %^RESET%^%^GREEN%^H  %^RESET%^%^ORANGE%^T   %^RESET%^%^RED%^ E         \n"+
"%^RESET%^%^RED%^         I  %^RESET%^%^ORANGE%^U %^RESET%^%^GREEN%^ I  %^BLUE%^%^BOLD%^ U  "+
" %^RESET%^%^MAGENTA%^ H   %^BOLD%^%^MAGENTA%^T   %^BOLD%^%^MAGENTA%^A   %^RESET%^%^MAGENTA%^"+
"A  %^BLUE%^%^BOLD%^N                  \n"+
"%^RESET%^%^RED%^                  %^RESET%^%^GREEN%^A  %^BLUE%^%^BOLD%^M     %^RESET%^%^MAGENTA%^T"+
"      %^RESET%^%^MAGENTA%^N      %^RESET%^%^GREEN%^E   %^RESET%^%^ORANGE%^W             \n"+
"%^RESET%^%^RED%^          W   %^RESET%^%^ORANGE%^N        %^BLUE%^%^BOLD%^ E     %^RESET%^%^"+
"MAGENTA%^ D    %^BLUE%^%^BOLD%^ I     %^RESET%^%^ORANGE%^E    %^RESET%^%^RED%^ E           \n"+
"%^RESET%^%^RED%^            D   %^RESET%^%^ORANGE%^I    %^RESET%^%^GREEN%^G    %^BLUE%^%^BOLD%"+
"^W       %^BLUE%^%^BOLD%^N   %^RESET%^%^GREEN%^F  %^RESET%^%^ORANGE%^M    %^RESET%^%^RED%^ D             \n"+
"%^RESET%^%^RED%^              N    %^RESET%^%^ORANGE%^T   %^RESET%^%^GREEN%^ A     %^BLUE%^%^"+
"BOLD%^G   %^RESET%^%^GREEN%^ I   %^RESET%^%^ORANGE%^U    %^RESET%^%^RED%^ O              \n"+
"%^RESET%^%^RED%^                 O    %^RESET%^%^ORANGE%^N   %^RESET%^%^GREEN%^E    R    %^RESET%^"+
"%^ORANGE%^S     %^RESET%^%^RED%^ M             \n"+
"%^RESET%^%^RED%^                    B    %^RESET%^%^ORANGE%^O   C  T     %^RESET%^%^RED%^ A"+
"                   \n"+
"%^RESET%^%^RED%^                      R  U  O  D  N");
 
}
