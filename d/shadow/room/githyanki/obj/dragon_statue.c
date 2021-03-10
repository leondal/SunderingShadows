//Statue of Tiamat - Githyanki Fortress - LoKi - 07-02-2008

#include <std.h>
#include "../githyanki.h"
inherit OBJECT;

void create(){
    ::create();
    set_name("statue of tiamat");
    set_id(({"statue","dragon statue","statue of tiamat"
,"tiamat","Statue of a Five Headed Dragon"}));
    set_short("%^RESET%^%^BOLD%^%^BLACK%^Stat%^RESET%^"+
"%^WHITE%^u%^RESET%^%^BOLD%^%^BLACK%^e of a Fi%^RESET%^"+
"%^WHITE%^v%^RESET%^%^BOLD%^%^BLACK%^e Hea%^RESET%^%^WHITE"+
"%^d%^RESET%^%^BOLD%^%^BLACK%^ed D%^RESET%^%^WHITE%^r"+
"%^RESET%^%^BOLD%^%^BLACK%^agon%^RESET%^");
    set_long("%^RESET%^%^BOLD%^%^BLACK%^This statue "+
"stands over fifteen feet tall and has been constructed"+
" from solid iron. It is a statue of Tiamat, the goddess"+
" of evil dragons. Each head has been formed with lifelike"+
" quality. The %^RESET%^%^WHITE%^black head %^RESET%^"+
"%^BOLD%^%^BLACK%^is scaled in ob%^RESET%^%^WHITE%^s%^RESET%^"+
"%^BOLD%^%^BLACK%^idi%^RESET%^%^WHITE%^o%^RESET%^%^BOLD%^"+
"%^BLACK%^n sh%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^%^BLACK%^"+
"rds, its sunken eyes looking into the shadows. The %^RESET%^"+
"%^BLUE%^b%^RESET%^%^BOLD%^%^BLUE%^l%^RESET%^%^BLUE%^ue h%^RESET"+
"%^%^BOLD%^%^BLUE%^e%^RESET%^%^BLUE%^ad %^RESET%^%^BOLD%^%^BLACK"+
"%^rises above them all and is scaled in fist sized %^RESET%^"+
"%^BOLD%^%^BLUE%^s%^RESET%^%^CYAN%^a%^RESET%^%^BOLD%^%^BLUE%^pphire"+
" sca%^RESET%^%^CYAN%^l%^RESET%^%^BOLD%^%^BLUE%^es%^RESET%^%^BOLD%^"+
"%^BLACK%^. The %^RESET%^%^GREEN%^gr%^RESET%^%^BOLD%^%^GREEN%^e"+
"%^RESET%^%^GREEN%^en head %^RESET%^%^BOLD%^%^BLACK%^is scaled with"+
" %^RESET%^%^BOLD%^%^GREEN%^gli%^RESET%^%^GREEN%^tt%^RESET%^%^BOLD%^"+
"%^GREEN%^ering e%^RESET%^%^GREEN%^m%^RESET%^%^BOLD%^%^GREEN%^erald"+
"%^RESET%^%^GREEN%^s%^RESET%^%^BOLD%^%^GREEN%^ %^RESET%^%^BOLD%^"+
"%^BLACK%^and is low to the ground, ready to strike. The %^RESET%^"+
"%^RED%^red he%^RESET%^%^BOLD%^%^RED%^a%^RESET%^%^RED%^d %^RESET%^"+
"%^BOLD%^%^BLACK%^shines with %^RESET%^%^BOLD%^%^RED%^gia%^RESET%^"
"%^RED%^n%^RESET%^%^BOLD%^%^RED%^t rubies %^RESET%^%^BOLD%^%^BLACK%^"+
"and looks with malign wisdom. The %^RESET%^%^WHITE%^wh%^RESET%^%^"+
"BOLD%^%^WHITE%^i%^RESET%^%^WHITE%^te h%^RESET%^%^BOLD%^%^WHITE%^e"+
"%^RESET%^%^WHITE%^ad %^RESET%^%^BOLD%^%^BLACK%^is scaled in %^RESET%^"+
"%^BOLD%^%^WHITE%^mil%^RESET%^%^WHITE%^k%^RESET%^%^BOLD%^%^WHITE%^y "+
"white di%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^%^WHITE%^mond%^RESET%^"+
"%^WHITE%^s%^RESET%^%^BOLD%^%^WHITE%^ %^RESET%^%^BOLD%^%^BLACK%^and"+
" has its jaw open in a perpetual scream.%^RESET%^");
    set_weight(1000);
    set_value(5000);
    set_property("no animate",1);
}
