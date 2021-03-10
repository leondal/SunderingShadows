//t6.c
#include <std.h>
#include "../bpeak.h"
inherit IHRMS+"transition2";
int searched;

void create(){
::create();
set_exits(([
"south":INRMS+"t7","northwest":INRMS+"t5"
]));
}
string ldesc(string str){
   return("%^RESET%^The %^ORANGE%^path %^RESET%^continues to get steeper as it"
" winds its way up towards the base of the %^BLUE%^mountains.  %^RESET%^Looking"
" north you can see the %^ORANGE%^beach %^RESET%^below you and to the south the"
" %^BLUE%^mountains %^RESET%^are simply overwhelming in appearance now.  The"
" %^BOLD%^%^BLACK%^rocks %^RESET%^lining the path are now very large and even more"
" jagged, as now they are actually part of the base of the %^BLUE%^mountain."
"%^RESET%^\n");
}
