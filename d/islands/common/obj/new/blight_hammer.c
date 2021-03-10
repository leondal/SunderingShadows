#include <std.h>

inherit "/d/common/obj/weapon/hammer_sm";


void create() 
{
    ::create();

    set_id(({"hammer","blight","blightbringer"}));

    set_name("blightbringer");

    set_obvious_short("%^RESET%^%^GREEN%^A sickly green and black hammer%^RESET%^");

    set_short("%^BOLD%^%^BLACK%^Bl%^RESET%^%^GREEN%^i%^BOLD%^%^BLACK%^gh%^RESET%^%^GREEN%^t%^BOLD%^%^BLACK%^br%^RESET%^%^GREEN%^"
			  "i%^BOLD%^%^BLACK%^ng%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^r%^RESET%^");

    set_long("%^ORANGE%^This small hammer is tarnished with a %^GREEN%^s%^BOLD%^i%^BLACK%^ck%^GREEN%^l%^RESET%^%^GREEN%^y g%^BOLD"
	         "%^r%^BLACK%^e%^GREEN%^e%^RESET%^%^GREEN%^n %^ORANGE%^hue and m%^WHITE%^o%^ORANGE%^t%^WHITE%^t%^ORANGE%^l%^WHITE%^e%^"
			 "ORANGE%^d in strange patterns by a rotten %^BOLD%^%^BLACK%^black s%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^a%^RESET%^%^O"
			 "RANGE%^i%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^. The feeling of an %^BOLD%^%^RED%^e%^RESET%^%^RED%^vi%^BOLD%^l %^RESET%"
			 "^%^ORANGE%^taint permeats the ancient %^BOLD%^c%^RESET%^%^ORANGE%^o%^BOLD%^pp%^RESET%^%^ORANGE%^e%^BOLD%^r%^RESET%^%^O"
			 "RANGE%^. The head arches in a full %^WHITE%^s%^ORANGE%^e%^WHITE%^m%^ORANGE%^i%^WHITE%^-%^ORANGE%^ci%^WHITE%^r%^ORANGE%^"
			 "cl%^WHITE%^e %^ORANGE%^and looks %^BOLD%^%^BLACK%^s%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^u%^RESET%^%^ORANGE%^n%^BOLD%^%^B"
			 "LACK%^d %^RESET%^%^ORANGE%^enough despite the b%^CYAN%^r%^ORANGE%^i%^CYAN%^t%^ORANGE%^t%^CYAN%^l%^ORANGE%^e appearance, an"
			 " eight inch long handle, %^CYAN%^contoured %^ORANGE%^for a c%^BOLD%^om%^RESET%^%^ORANGE%^fo%^BOLD%^rt%^RESET%^%^ORANGE%^a%"
			 "^BOLD%^bl%^RESET%^%^ORANGE%^e grip, extends down and is wrapped %^WHITE%^t%^ORANGE%^i%^WHITE%^g%^ORANGE%^h%^WHITE%^t%^ORANGE"
			 "%^l%^WHITE%^y %^ORANGE%^with a now %^BOLD%^%^BLACK%^b%^RESET%^l%^BOLD%^%^BLACK%^a%^RESET%^c%^BOLD%^%^BLACK%^k%^RESET%^e%^BOLD"
			 "%^%^BLACK%^n%^RESET%^e%^BOLD%^%^BLACK%^d %^RESET%^%^ORANGE%^strip of soft %^WHITE%^hide%^ORANGE%^. %^BOLD%^%^BLACK%^In%^RESET%^"
			 "s%^BOLD%^%^BLACK%^et %^RESET%^%^ORANGE%^into the pommel was once a %^BOLD%^%^WHITE%^b%^ORANGE%^r%^WHITE%^i%^ORANGE%^l%^WHITE%^l%"
			 "^ORANGE%^i%^WHITE%^a%^ORANGE%^n%^WHITE%^t %^RESET%^%^ORANGE%^hemisphere of %^WHITE%^polished %^BOLD%^%^BLACK%^hematite%^RESET%^%^"
			 "ORANGE%^, now seems to have taken %^GREEN%^o%^ORANGE%^l%^GREEN%^i%^ORANGE%^v%^GREEN%^e %^ORANGE%^hue and holds hairline %^WHITE%^"
			 "f%^ORANGE%^ra%^WHITE%^c%^ORANGE%^tu%^WHITE%^r%^ORANGE%^e%^WHITE%^s %^ORANGE%^sp%^WHITE%^l%^ORANGE%^i%^WHITE%^n%^ORANGE%^te%^WHITE%^"
			 "r%^ORANGE%^in%^WHITE%^g %^ORANGE%^the %^BOLD%^%^BLACK%^gl%^CYAN%^o%^BLACK%^s%^CYAN%^s%^BLACK%^y %^RESET%^%^ORANGE%^surface. On each"
			 " side of the hammer head is %^WHITE%^i%^BOLD%^%^BLACK%^n%^RESET%^l%^BOLD%^%^BLACK%^a%^RESET%^y%^BOLD%^%^BLACK%^e%^RESET%^d %^ORANGE%^the"
			 " dwarven rune for %^BOLD%^justice%^RESET%^%^ORANGE%^, which softly glows with a pale %^GREEN%^gr%^ORANGE%^e%^GREEN%^e%^ORANGE%^n%^GREEN%^"
			 "i%^ORANGE%^s%^GREEN%^h %^BOLD%^%^CYAN%^g%^RESET%^l%^CYAN%^i%^BOLD%^m%^RESET%^m%^CYAN%^e%^WHITE%^r%^ORANGE%^.%^RESET%^");

    set_value(130000);

    set_property("no curse",1);
    set_property("enchantment",7);

    set_item_bonus("attack bonus",7);
    set_item_bonus("damage resistance",10);

    set_wield((:TO,"wield_me":));
    set_unwield("%^BOLD%^%^BLACK%^The sweet stench of decay fills you as you lower the hammer.");
    set_hit((:TO,"hit_me":));
    
    set_lore("This small %^YELLOW%^c%^RESET%^%^ORANGE%^o%^BOLD%^p%^RESET%^%^ORANGE%^p%^BOLD%^e%^RESET%^%^ORANGE%^r %^WHITE%^hammer"
	         " was made by the blacksmith %^BOLD%^Theon Dal%^RESET%^g%^BOLD%^ras %^RESET%^of old %^BOLD%^%^CYAN%^Asgard%^RESET%^."
			 " One of the most prominent and famous blacksmiths of his time, %^BOLD%^Theon %^RESET%^crafted many %^CYAN%^weapons"
			 " %^WHITE%^and pieces of %^ORANGE%^armor%^WHITE%^. When he originally crafted this %^ORANGE%^h%^BOLD%^a%^RESET%^%^ORA"
			 "NGE%^m%^BOLD%^m%^RESET%^%^ORANGE%^e%^BOLD%^r %^RESET%^it was made for a priest of %^YELLOW%^Tyr %^RESET%^who was on a"
			 " journey to %^CYAN%^r%^WHITE%^ai%^CYAN%^n %^YELLOW%^justice %^RESET%^on a %^GREEN%^green %^WHITE%^dragon ravaging the"
			 " lands at the time. On his journey, the priest %^BOLD%^%^RED%^fell %^RESET%^and %^BOLD%^%^BLACK%^lost %^RESET%^the hammer"
			 " to the dragon, %^BOLD%^%^GREEN%^A%^RESET%^%^GREEN%^r%^BOLD%^ga%^RESET%^%^GREEN%^d%^BOLD%^em%^RESET%^%^GREEN%^e%^BOLD%^do%"
			 "^RESET%^%^GREEN%^r%^WHITE%^. It is speculated that the time it spent with the %^BOLD%^%^RED%^e%^RESET%^%^RED%^vi%^BOLD%^l"
			 " %^RESET%^dragon somehow %^BOLD%^%^GREEN%^c%^BLACK%^o%^RESET%^%^GREEN%^r%^BOLD%^r%^BLACK%^u%^GREEN%^p%^RESET%^%^GREEN%^t%^BOLD"
			 "%^e%^RESET%^%^GREEN%^d %^WHITE%^the %^BOLD%^%^CYAN%^c%^WHITE%^or%^CYAN%^e %^RESET%^of the weapon, twisting it's nature into"
			 " something %^GREEN%^f%^BOLD%^%^BLACK%^o%^GREEN%^u%^RESET%^%^GREEN%^l%^WHITE%^.");
   
    set_property("quest required","%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");
    set_property("level required",35);
}


int wield_me()
{
    tell_object(ETO,"%^BOLD%^%^GREEN%^The sickeningly sweet stench of "+
        "%^BLACK%^decay %^GREEN%^fills the air as you take up the hammer.");
    tell_room(EETO,"%^BOLD%^%^GREEN%^"+ETOQCN+" takes up a hammer as the "+
        "stench of %^BLACK%^decay %^GREEN%^surrounds "+ETO->QO+".",ETO);
    return 1;
}


int hit_me(object targ)
{
    if(!objectp(TO)) return 1;
    if(!objectp(ETO)) return 1;
    if(!objectp(targ)) return 1;
    
    tell_object(ETO,"%^BOLD%^%^BLACK%^You relish the scent of decay "+
        "as you bring your hammer across "+targ->QCN+"'s face.");
    tell_object(targ,"%^BOLD%^%^BLACK%^A sickening scent of death rises "+
        "as "+ETOQCN+" bashes into you.");
    tell_room(EETO,"%^BOLD%^%^BLACK%^The scent of death rises in the air "+
        "as "+ETOQCN+" bashes "+targ->QCN+".",({ETO,targ}));
    targ->do_damage("torso",random(50)+24);
    return 1;
}
