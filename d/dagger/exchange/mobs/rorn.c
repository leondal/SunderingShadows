// Rorn the Medic - For the Exchange - LoKi


#include <std.h>
#include <daemons.h>
inherit NPC;



void create() {
   ::create();
   set_name("healer");
   set_short("%^RESET%^%^ORANGE%^Rorn Narin, %^RESET%^%^BOLD%^"+
"%^WHITE%^Dragoon %^RESET%^%^MAGENTA%^Medic%^RESET%^");
   set_id(({ "rorn","Rorn Narin","medic","healer"}));
   set_nwp("healing", 15);
   set_long("%^RESET%^%^ORANGE%^Rorn appears to be of northern descent, "+
"judging by his height. His impressive eight and a half feet height has "+
"led more then a few to think him as a half-giant. Shoulder length, golden "+
"highlighted %^RED%^r%^ORANGE%^u%^BOLD%^b%^RESET%^%^RED%^y-%^BOLD%^r%^RESET%^"+
"%^ORANGE%^e%^RED%^d %^ORANGE%^hair has been tied back at the nape of his "+
"neck with a thick strip of plain, brown leather. Although several wavy "+
"strands have slipped loose and hang into his %^GREEN%^s%^CYAN%^e%^WHITE%^"+
"a%^GREEN%^gre%^CYAN%^e%^GREEN%^n%^ORANGE%^ eyes. This gives him a bit of"+
" a disheveled, roguish look, especially when he flashes one of his wry "+
"smiles. %^YELLOW%^L%^RESET%^%^WHITE%^a%^ORANGE%^u%^YELLOW%^gh l%^RESET%^"+
"i%^ORANGE%^n%^YELLOW%^es %^RESET%^%^ORANGE%^crease his %^BOLD%^%^BLACK%^"+
"w%^RESET%^%^ORANGE%^e%^WHITE%^a%^BOLD%^%^BLACK%^th%^RESET%^%^ORANGE%^e"+
"%^BOLD%^%^BLACK%^r w%^RESET%^%^ORANGE%^o%^RESET%^r%^BOLD%^%^BLACK%^n "+
"%^RESET%^%^ORANGE%^features and grant him a bit of a wizened mien, "+
"revealing his true age as much older then one might guess at first. "+
"Lean and fit, Rorn would seem the epitome of a warrior but for the "+
"gentleness of his nature. Instead of a weapon at his side, he carries a"+
" pouch of %^GREEN%^h%^RESET%^%^ORANGE%^e%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^"+
"bs%^ORANGE%^, %^BLUE%^p%^BOLD%^o%^BLACK%^t%^RESET%^%^BLUE%^io%^BOLD%^n%^RESET%^"+
"%^BLUE%^s %^ORANGE%^and %^BOLD%^%^BLACK%^b%^RESET%^%^ORANGE%^a%^RESET%^n%^BOLD%^"+
"%^BLACK%^da%^RESET%^%^ORANGE%^g%^RESET%^e%^BOLD%^%^BLACK%^s %^RESET%^%^ORANGE%^to"+
" treat the injured, a profession which he engages in for the Dragoon Irregulars "+
"if the insignia on his leather jerkin, a %^BOLD%^%^WHITE%^w%^RESET%^h%^BOLD%^"+
"%^BLACK%^i%^WHITE%^t%^RESET%^e %^BOLD%^d%^RESET%^r%^BOLD%^%^BLACK%^a%^WHITE%^go"+
"%^RESET%^n%^BOLD%^%^BLACK%^'%^WHITE%^s %^RESET%^%^ORANGE%^head in profile, is "+
"anything to judge by.%^RESET%^");
   set_race("human");
   set_stats("intelligence",20);
   set_stats("wisdom",18);
   set_stats("strength",16);
   set_stats("charisma",16);
   set_stats("dexterity",12);
   set_stats("constitution",14);
   set_class("fighter");
   set_mlevel("fighter",30);
   set_guild_level("fighter",30);
   set_alignment(4);
   set_gender("male");
   set_size(2);
   set_exp(0);
   set_overall_ac(-10);
   set_hd(35,15);
   set_max_hp(400);
   set_hp(query_max_hp());
   set("aggressive",0);
   set_emotes(1, ({
"%^RESET%^%^ORANGE%^Rorn looks around with a smile.%^RESET%^",
"%^RESET%^%^ORANGE%^Rorn arranges some boxes on the shelves.%^RESET%^",
"%^RESET%^%^ORANGE%^Rorn cleans the instruments on the tray.%^RESET%^",
}), 0);
   set_property("no bows",1);
   set_spoken("wizish");
   command("speech speak in a soft reassuring voice");
}
