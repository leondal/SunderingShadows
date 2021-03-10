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
	set_value(25000);
	set_id(({ "tattoo" }));
	set_short("%^RESET%^%^RED%^large %^BOLD%^s%^YELLOW%^w%^RESET%^%^RED%^i%^BOLD%^%^YELLOW%^r%^RESET%^%^RED%^l%^BOLD%^i%^YELLOW%^n%^RESET%^%^RED%^g %^BOLD%^f%^RESET%^%^RED%^l%^BOLD%^a%^YELLOW%^m%^RESET%^%^RED%^e%^BOLD%^s%^RESET%^");
	set_long(
@MYLONG
%^RESET%^%^GREEN%^The colors %^BOLD%^vibrant%^RESET%^%^GREEN%^, almost %^BOLD%^%^WHITE%^startling%^RESET%^%^GREEN%^, both forearms from wrist to elbow are covered in %^BOLD%^%^RED%^s%^YELLOW%^w%^RESET%^%^RED%^i%^BOLD%^%^YELLOW%^r%^RESET%^%^RED%^l%^BOLD%^s, %^BOLD%^l%^YELLOW%^o%^RESET%^%^RED%^o%^BOLD%^p%^RESET%^%^RED%^s %^RESET%^%^GREEN%^and %^BOLD%^%^YELLOW%^w%^RESET%^%^RED%^h%^BOLD%^o%^YELLOW%^r%^RESET%^%^RED%^l%^BOLD%^%^YELLOW%^s%^RESET%^%^GREEN%^ in rich %^BOLD%^%^RED%^reds%^RESET%^%^GREEN%^, deep %^RED%^crimsons%^GREEN%^ and bright %^BOLD%^%^YELLOW%^yellows%^RESET%^%^GREEN%^. When one looks closely at the patterns, though it seems more like a lack of pattern at first glance, something can be seen, suggestions of a more organized picture. Unless the images were held still for examination, however, it is unlikely that it could be discerned.%^RESET%^

MYLONG
	);
	set_limbs(({"right arm"}));
}

int get(){ return 1; }

int drop(){ return 1; }

void unwear(){ return;}

int query_mysize(){ return "large"; }

int is_tattoo(){ return 1; }

int wear_me(){
	"daemon/hide_d"->hideItem(TO,ETO,1);
return 1;
}

