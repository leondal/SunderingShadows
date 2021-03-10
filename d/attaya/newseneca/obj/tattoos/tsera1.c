#include <std.h>
inherit ARMOUR;

void create(){
        ::create();
        set_weight(0);
        set_ac(0);
        set_type("ring");
        set_property("death keep",1);
        set_property("no animate",1);
        set_name("tattoo");
        set_value(30000);
        set_id(({ "tattoo", "test" }));
        set_short("A huge dragon tattoo");
 set_long(
"%^RESET%^%^BOLD%^Starting at her waistline and ending near her shoulder, this stylized" 
" %^BOLD%^%^BLACK%^t%^RESET%^a%^BOLD%^%^CYAN%^t%^WHITE%^t%^RESET%^o%^BOLD%^%^BLACK%^o %^WHITE%^of a"
" %^BLACK%^d%^RESET%^r%^BOLD%^%^CYAN%^a%^WHITE%^g%^RESET%^o%^BOLD%^%^BLACK%^n %^WHITE%^is"
" an impressive display of flesh etching. A wingless Eastern interpretation of the this beast"
" gives it a curving, %^BLACK%^sn%^RESET%^a%^BOLD%^%^BLACK%^k%^CYAN%^e%^BLACK%^-l%^CYAN%^i"
"%^RESET%^k%^BOLD%^%^BLACK%^e %^WHITE%^body that accentuates the feminine architecture of"
" its wearer's right side. Great %^BLACK%^three-tiered"
" %^CYAN%^h%^WHITE%^o%^BLACK%^r%^RESET%^n%^BOLD%^%^CYAN%^s%^WHITE%^, flared nostrils and large,"
" round %^CYAN%^r%^RESET%^o%^BOLD%^a%^CYAN%^m%^BLACK%^i%^RESET%^n%^BOLD%^%^BLACK%^g"
" %^CYAN%^e%^RESET%^%^CYAN%^y%^RESET%^e%^BOLD%^%^CYAN%^s %^WHITE%^give this creature"
" a %^CYAN%^w%^BLACK%^i%^WHITE%^l%^CYAN%^d %^WHITE%^and %^BLACK%^f%^RESET%^e%^BOLD%^%^CYAN%^a%^WHITE%^r%^BLACK%^s%^CYAN%^o%^RESET%^m%^BOLD%^%^BLACK%^e %^WHITE%^countenance."
" %^BOLD%^%^CYAN%^F%^RESET%^l%^BOLD%^%^BLACK%^a%^CYAN%^m%^WHITE%^e%^RESET%^"
"-%^BOLD%^%^CYAN%^l%^RESET%^i%^BOLD%^%^WHITE%^k%^BLACK%^e sp%^RESET%^i%^BOLD%^%^BLACK%^kes"
" %^WHITE%^travel down the dragon's spine, which ends in a"
" %^BOLD%^%^BLACK%^l%^RESET%^e%^BOLD%^%^BLACK%^th%^RESET%^a%^BOLD%^%^BLACK%^l"
" t%^RESET%^a%^BOLD%^i%^BLACK%^l %^WHITE%^with razor sharp"
" %^BLACK%^b%^RESET%^a%^BOLD%^%^BLACK%^r%^CYAN%^b%^BLACK%^s%^WHITE%^. Held high within the"
" one of its clawed hands is a %^BOLD%^%^CYAN%^br%^BLUE%^i%^CYAN%^l%^WHITE%^l%^CYAN%^ia%^BLUE%^n%^CYAN%^tly bl%^BLUE%^oo%^WHITE%^m%^BLUE%^in%^CYAN%^g %^RESET%^%^CYAN%^w%^GREEN%^a%^BOLD%^%^BLUE%^t%^RESET%^%^CYAN%^e%^GREEN%^r %^BOLD%^%^CYAN%^L%^BLUE%^i%^CYAN%^ly,"
" %^WHITE%^surrounded by %^BLUE%^a%^RESET%^%^BLUE%^z%^BOLD%^%^CYAN%^u%^BLUE%^re %^BLACK%^sm%^RESET%^%^CYAN%^o%^BOLD%^%^BLACK%^ke %^WHITE%^that"
" streams from the monster's %^BLACK%^b%^RESET%^e%^BOLD%^%^CYAN%^a%^WHITE%^r%^BLACK%^d%^RESET%^e%^BOLD%^%^BLACK%^d %^CYAN%^m%^WHITE%^a%^CYAN%^w%^WHITE%^."
"  %^BLACK%^I%^RESET%^n%^BOLD%^%^CYAN%^k %^WHITE%^that %^CYAN%^g%^WHITE%^l%^RESET%^i%^BOLD%^t%^CYAN%^t%^RESET%^e%^BOLD%^r%^CYAN%^s %^WHITE%^like"
" %^CYAN%^d%^RESET%^i%^BOLD%^a%^CYAN%^m%^WHITE%^o%^RESET%^n%^BOLD%^%^CYAN%^d d%^RESET%^u%^BOLD%^%^BLACK%^s%^CYAN%^t %^WHITE%^emphases"
" the vast amount of detail placed into each %^CYAN%^s%^BLACK%^h%^RESET%^i%^BOLD%^m%^BLACK%^m%^CYAN%^e%^RESET%^r%^BOLD%^i%^CYAN%^n%^BLACK%^g"
" %^CYAN%^s%^RESET%^c%^BOLD%^%^CYAN%^a%^WHITE%^l%^CYAN%^e%^WHITE%^. The colors shift"
" from %^MAGENTA%^v%^CYAN%^i%^RESET%^o%^BOLD%^%^BLUE%^l%^CYAN%^e%^RESET%^%^MAGENTA%^t"
" %^BOLD%^%^WHITE%^to %^BLACK%^s%^RESET%^i%^BOLD%^%^CYAN%^l%^WHITE%^v%^RESET%^e%^BOLD%^%^BLACK%^r%^WHITE%^, making"
" it seem as if the %^BLACK%^d%^RESET%^r%^BOLD%^%^CYAN%^a%^WHITE%^g%^RESET%^o%^BOLD%^%^BLACK%^n%^CYAN%^'%^WHITE%^s"
" %^RESET%^s%^BOLD%^%^BLACK%^e%^CYAN%^r%^WHITE%^p%^RESET%^e%^BOLD%^%^CYAN%^n%^BLACK%^t%^RESET%^i%^BOLD%^n%^CYAN%^e"
" %^BLACK%^b%^RESET%^o%^BOLD%^%^CYAN%^d%^BLACK%^y %^WHITE%^writhes whenever its owner twists or turns.%^RESET%^" 
        );
int get(){ return 1; }

int drop(){ return 1; }

void unwear(){ return;}

int query_mysize(){ return "huge"; }

int is_tattoo(){ return 1; }

int wear_me(){
        "daemon/hide_d"->hideItem(TO,ETO,1);
return 1;
}
