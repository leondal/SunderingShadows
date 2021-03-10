//naturecloak.c - altered cloak of silk
#include <std.h>
//Four other cloaks are being copied from this one.

inherit "/d/common/obj/clothing/cloak.c";


void create() 
{
    ::create();
    set_name("cloak of nature");
    
    set_id( ({"cloak","cloak of nature","nature cloak"}) );
    
    set_obvious_short("%^RESET%^%^GREEN%^A %^BOLD%^f%^RESET%^%^ORANGE%^i%^GREEN%^n%^BOLD%^e %^CYAN%^"
					  "s%^RESET%^%^CYAN%^i%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^k%^BOLD%^%^RED%^e%^RES"
					  "ET%^%^RED%^n %^GREEN%^c%^BOLD%^l%^CYAN%^o%^GREEN%^a%^RESET%^%^GREEN%^k%^RESET%^");
    
    set_short("%^RESET%^%^ORANGE%^C%^BOLD%^%^RED%^l%^RESET%^%^RED%^o%^GREEN%^a%^BOLD%^k %^RESET%^%^GR"
			 "EEN%^of %^BOLD%^%^CYAN%^Sh%^RESET%^%^CYAN%^if%^BOLD%^%^GREEN%^ti%^RESET%^%^GREEN%^ng %^"
			 "BOLD%^%^CYAN%^S%^RESET%^%^CYAN%^e%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^s%^BOLD%^%^RED%^o%"
			 "^RESET%^%^RED%^n%^ORANGE%^s%^RESET%^");
    
    set_long("%^RESET%^%^GREEN%^This %^BOLD%^fine cloak %^RESET%^%^GREEN%^drapes the wearer's shoulder"
			 "s like a %^CYAN%^gentle breeze %^GREEN%^and %^BOLD%^%^BLUE%^cascades %^RESET%^%^GREEN%^d"
			 "own its back like a miniature %^BOLD%^%^BLUE%^waterfall%^RESET%^%^GREEN%^. The %^BOLD%^s"
			 "ilken sheen %^RESET%^%^GREEN%^of the fabric s%^BOLD%^h%^RESET%^%^GREEN%^im%^BOLD%^m%^RES"
			 "ET%^%^GREEN%^e%^BOLD%^r%^RESET%^%^GREEN%^s, reflecting light like a bubbling %^CYAN%^bro"
			 "ok%^GREEN%^. It latches close beneath the neckline, by use of a %^ORANGE%^leather buckle"
			 " %^GREEN%^with an %^WHITE%^iv%^BOLD%^ory p%^RESET%^ro%^BOLD%^ng%^RESET%^%^GREEN%^. Narrow"
			 " bands of %^RED%^druidic runes %^GREEN%^line the edges of the %^BOLD%^hood%^RESET%^%^GREE"
			 "N%^, trailing the borders of the entire cloak. It is colored by the %^BOLD%^%^CYAN%^sh%^R"
			 "ESET%^%^CYAN%^if%^BOLD%^%^GREEN%^ti%^RESET%^%^GREEN%^ng %^BOLD%^%^CYAN%^s%^RESET%^%^CYAN%"
			 "^e%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^s%^BOLD%^%^RED%^o%^RESET%^%^RED%^n%^ORANGE%^s %^GRE"
			 "EN%^of %^BOLD%^nature%^RESET%^%^GREEN%^. The %^CYAN%^hood %^GREEN%^is %^BOLD%^%^CYAN%^icy"
			 " blue %^RESET%^%^GREEN%^with a myriad of nearly indistinguishable %^BOLD%^%^WHITE%^snowfl"
			 "akes %^RESET%^%^GREEN%^that tumble chaotically down towards the shoulders. Here, the %^CY"
			 "AN%^shades o%^BOLD%^%^BLUE%^f blue %^RESET%^%^GREEN%^become gradually %^BOLD%^%^BLUE%^sof"
			 "ter %^RESET%^%^GREEN%^and %^BOLD%^purer%^RESET%^%^GREEN%^, finally gliding into hues of %"
			 "^BOLD%^vibrant green%^RESET%^%^GREEN%^. A multitude of %^RED%^birds %^GREEN%^in flight re"
			 "place the now melting snowflakes. At the waist, the birds %^RED%^tra%^BOLD%^nsf%^ORANGE%^"
			 "o%^RESET%^%^ORANGE%^rm %^GREEN%^into life-like %^BOLD%^leaves%^RESET%^%^GREEN%^, bright %"
			 "^BOLD%^green %^RESET%^%^GREEN%^in %^BOLD%^summer %^RESET%^%^GREEN%^and gradually darkened"
			 " by the %^ORANGE%^brown %^GREEN%^and %^BOLD%^%^RED%^fire red %^RESET%^%^GREEN%^shades of %"
			 "^ORANGE%^au%^RED%^t%^BOLD%^u%^ORANGE%^m%^RESET%^%^ORANGE%^n %^GREEN%^that adorn the bottom"
			 " of the cloak.%^RESET%^");
			 
	set_lore("%^RESET%^%^ORANGE%^The C%^BOLD%^%^RED%^l%^RESET%^%^RED%^o%^GREEN%^a%^BOLD%^k %^RESET%^%^GRE"
	         "EN%^of %^BOLD%^%^CYAN%^Sh%^RESET%^%^CYAN%^if%^BOLD%^%^GREEN%^ti%^RESET%^%^GREEN%^ng %^BOLD%"
			 "^%^CYAN%^S%^RESET%^%^CYAN%^e%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^s%^BOLD%^%^RED%^o%^RESET%^%"
			 "^RED%^n%^ORANGE%^s is a favored garment among wanderers and trailblazers of all faiths and "
			 "outlooks. A rare relic, indeed, it is said to have been woven by nature itself, as a gift to"
			 " those whose spirit aligns with the natural world. The runes that line the edges of the cloak"
			 " are druidic in origin and seem to read: -Those favored few, by natures grace, will find rel"
			 "ief in my embrace.- The depiction of the shifting seasons on the back of the cloak further su"
			 "ggests that it offers comfort to its wearer in even the toughest of weather conditions.%^RESET%^"); 	
    
    set_weight(2);

    set_property("no curse",1);
    set_property("enchantment",7);
    
    set_item_bonus("spell damage resistance",25);
    set_item_bonus("survival",6);
    set_item_bonus("wisdom",6);
    
    set_value(150000);
    
    set_wear( (: TO,"wear_func" :) );
    set_remove( (: TO,"remove_func" :) );
    
    set_read("%^RESET%^%^GREEN%^-Those %^BOLD%^favored %^RESET%^%^GREEN%^few, by %^RED%^n%^BOLD%^ature%^RESET%^%^RED%^s"
	         " %^YELLOW%^grace%^RESET%^%^GREEN%^, will find %^CYAN%^r%^BOLD%^elie%^RESET%^%^CYAN%^f %^GREEN%^in my %^RED"
			 "%^e%^BOLD%^m%^ORANGE%^bra%^RED%^c%^RESET%^%^RED%^e%^GREEN%^-.%^RESET%^");
        
    //set_property("quest required","%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");
    set_property("level required",35);
}


int wear_func() 
{
    tell_object(ETO,"%^RESET%^%^GREEN%^You %^BOLD%^drape %^RESET%^%^GREEN%^the %^ORANGE%^c%^BOLD%^%^RED%^l%^RESET%^%^RED"
					"%^o%^GREEN%^a%^BOLD%^k %^RESET%^%^GREEN%^around your shoulders and feel %^ORANGE%^b%^BOLD%^lesse%^R"
					"ESET%^%^ORANGE%^d %^GREEN%^by %^RED%^n%^BOLD%^atur%^RESET%^%^RED%^e %^GREEN%^itself.%^RESET%^");
    return 1;
}


int remove_func() 
{
    tell_object(ETO, "%^RESET%^%^GREEN%^The %^RESET%^%^ORANGE%^c%^BOLD%^%^RED%^l%^RESET%^%^RED%^o%^GREEN%^a%^BOLD%^k %^R"
					"ESET%^%^GREEN%^glides lightly from your shoulders, its %^ORANGE%^b%^BOLD%^lessin%^RESET%^%^ORANGE%^g"
					"%^GREEN%^lingering like %^CYAN%^m%^BOLD%^ornin%^RESET%^%^CYAN%^g d%^BOLD%^e%^RESET%^%^CYAN%^w%^GREEN%^.%^RESET%^ ");
    return 1;
}
