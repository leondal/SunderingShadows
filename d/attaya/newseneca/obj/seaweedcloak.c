#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("seaweed cloak");
	set_id(({ "seaweed", "cloak", "seaweed cloak", "cloak of the seas" }));
	set_short("%^BOLD%^%^BLUE%^C%^RESET%^l%^CYAN%^o%^BLUE%^a%^BOLD%^%^BLUE%^k %^RESET%^%^BLUE%^o%^BOLD%^f %^RESET%^%^CYAN%^t%^RESET%^h%^BLUE%^e %^BOLD%^S%^RESET%^%^CYAN%^e%^BLUE%^a%^BOLD%^%^BLUE%^s%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^pile of s%^BLUE%^e%^CYAN%^a%^GREEN%^we%^WHITE%^e%^GREEN%^d%^RESET%^");
	set_long(
@AVATAR
%^CYAN%^Until unfurled, this cloak looks like nothing more then a pile of seaweed.  Woven from %^GREEN%^green%^CYAN%^, %^ORANGE%^brown %^CYAN%^and %^RED%^red %^CYAN%^strands, this cloak is surprising dry and warm despite the way the leaves glisten with %^BOLD%^%^BLUE%^m%^CYAN%^o%^RESET%^i%^CYAN%^s%^BOLD%^%^BLUE%^tu%^RESET%^%^CYAN%^r%^BOLD%^%^BLUE%^e%^RESET%^%^CYAN%^.  Each strand appears whole and unbroken, tapering from the wide base of the cloak where the strands are thickest, to the collar of the cloak where they are thinnest.  This allows the cloak a greater circumference at its base without causing the neck to be bunched.  A band of kelp has been decorated with small pieces of %^BLUE%^a%^MAGENTA%^b%^CYAN%^a%^BLUE%^l%^MAGENTA%^o%^BLUE%^ne s%^CYAN%^h%^WHITE%^e%^BLUE%^ll %^CYAN%^that glint and glitter in the light and can be used to affix the cloak around the wearer's neck.%^RESET%^ 

AVATAR
	);
	set_weight(5);
	set_value(1000);
	set_lore(
@AVATAR
Little is known about how these cloaks are made or where they come from.  The few that have turned up over the years are always found washed up on shore and are often mistaken for little more then a large pile of seaweed.  The ones that are found however, are believed to be gifts of Istishia to those who dwell within the ocean's depths.  Lost to the ever churning waters of the sea, they wash up on shore and are occasionally found by those who ply the sea and who claim that despite the cloak's wet appearance the garment protects one from even the heaviest of rains or sea swells.

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(2);
	set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^The leaves of "+ETOQCN+"'s %^RESET%^"+query_short()+" %^BOLD%^%^BLUE%^glisten with moisture as it is worn.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You can hear the distant crash of the surf as you secure %^RESET%^"+query_short()+"%^BOLD%^%^BLUE%^ about your shoulders!%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLUE%^The leaves of "+ETOQCN+"'s %^RESET%^"+query_short()+" %^BOLD%^%^BLUE%^glisten with moisture as it is removed.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You long to return to the sea as you remove your %^RESET%^"+query_short()+"%^RESET%^.");
	return 1;
}
