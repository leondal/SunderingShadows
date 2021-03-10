#include <std.h>
inherit "/d/common/obj/armour/hide.c";

#define COLORS ({"%^BOLD%^%^BLACK%^panther",\
"%^RESET%^%^ORANGE%^p%^RESET%^u%^ORANGE%^m%^RESET%^a",\
"%^BOLD%^%^YELLOW%^l%^RESET%^%^ORANGE%^i%^BOLD%^o%^RESET%^%^ORANGE%^n",\
"%^RESET%^%^ORANGE%^ch%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^et%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^h",\
"%^RESET%^c%^BOLD%^%^BLACK%^l%^RESET%^o%^BOLD%^%^BLACK%^u%^RESET%^d%^BOLD%^%^BLACK%^e%^RESET%^d %^BOLD%^%^BLACK%^leopard",\
"%^ORANGE%^t%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^g%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^r",\
"%^YELLOW%^j%^BLACK%^a%^RESET%^%^ORANGE%^g%^YELLOW%^u%^BLACK%^a%^RESET%^%^ORANGE%^r",\
"%^ORANGE%^l%^RESET%^y%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^x",\
"%^YELLOW%^o%^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^l%^YELLOW%^o%^RESET%^%^ORANGE%^t",\
"%^YELLOW%^l%^BOLD%^%^BLACK%^e%^YELLOW%^o%^BOLD%^%^BLACK%^p%^YELLOW%^a%^BOLD%^%^BLACK%^r%^YELLOW%^d"})

void create()
{ 
    int j;
    string str, COLOR;
    ::create();
    j = random(sizeof(COLORS));
    COLOR = COLORS[j];
    set_name("a "+COLOR+" tunic");
    set_id(({ "tunic","leather","armor","armour","skin" }));
    set_short("%^RESET%^"+COLOR+" skin tunic%^RESET%^");
    set_long( "%^GREEN%^This tunic made from the skin of "+
    "a %^RESET%^"+COLOR+" %^RESET%^%^GREEN%^.  Its "+
    "surface is completely smooth and has been carefully "+
    "treated to a dull tint, to prevent it from "+
    "reflecting any light when worn.  It is thin and "+
    "light, and successfully creates a suit of armor "+
    "that is both easy to move in and comfortable to "+
    "wear.%^RESET%^\n");
    set_value(700);
    set_lore( "The warrior women of Dallyh have a deep respect for "+
    "their totem animals, wild cats.  The women take great "+
    "pride in hunting down the sacred cats during the changes"+
    " of the season.  Using the pelts from the cats they are "+
    "able to create light armor to help them move in the dense "+
    "forest of their forest island.  The women don't needlessly "+
    "hunt the cats, fighting to preserve their presence on the "+
    "island.  It is considered extremely fortunate for these "+
    "women to wear the skins of the great cats.  Many claim that"+
    " the spirts of the cat grants them strength, agility, and vigor."+
    " Essays on Beast Cults - Volume Three Dallyh - Henrietta Audestban");
    set_property("lore difficulty",8);
    set_size(2);
    set_property("enchantment",2);
    set_item_bonus("survival",1);
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
}
int wear_func()
{
    tell_room(environment(ETO),"%^GREEN%^"+ETOQCN+" pulls the "+
    "tunic over "+ETO->QP+" head.",ETO);
    tell_object(ETO,"%^GREEN%^You pull on the tunic over your "+
    "head, feeling invigorated.");
    return 1; 
}
int remove_func()
{
    tell_room(environment(ETO),"%^GREEN%^"+ETOQCN+" pulls "+ETO->QP+" "+
    "tunic off.",ETO);
    tell_object(ETO,"%^GREEN%^You pull your tunic off, feeling less"+
    " invigorated now.");
    return 1;
}
