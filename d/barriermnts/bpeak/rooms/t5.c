//t5.c
#include <std.h>
#include "../bpeak.h"
inherit IHRMS+"transition2";
int searched;

void create(){
::create();
set_exits(([
"southeast":INRMS+"t6","northeast":INRMS+"t4"
]));
}
string ldesc(string str){
   return("%^RESET%^The %^ORANGE%^path %^RESET%^here begins to get steeper as it"
" winds its way up towards the base of the %^BLUE%^mountains.  %^RESET%^Looking"
" north you can see the %^ORANGE%^beach %^RESET%^below you and to the south the"
" %^BLUE%^mountains %^RESET%^continue to get more imposing.  The"
" %^BOLD%^%^BLACK%^rocks %^RESET%^lining the path are getting larger and more"
" jagged, some of them are easily the size of a small house now.%^RESET%^\n");
}
