

#include <std.h>

#include "../githyanki.h"
inherit MONSTER;

int bound;

void create() {
   object ob;
   ::create();
   set_name("Joseph Doren");
   set_short("%^RESET%^%^BOLD%^%^CYAN%^Joseph Doren, %^RESET%^%^BOLD%^%^RED%^C"+
"%^RESET%^%^RED%^a%^RESET%^%^BOLD%^%^RED%^pti%^RESET%^%^RED%^v%^RESET%^%^BOLD%^"+
"%^RED%^e%^RESET%^");
   set_id(({ "Joseph Doren","Joseph Doren, Captive","Joseph","joseph","captive"}));
   set_long("%^RESET%^%^BOLD%^%^BLACK%^This %^RESET%^%^ORANGE%^gaunt %^RESET%^"+
"%^BOLD%^%^BLACK%^man is dressed in %^RESET%^%^BOLD%^%^RED%^blo%^RESET%^%^RED%^"+
"o%^RESET%^%^BOLD%^%^RED%^dy rag%^RESET%^%^RED%^s%^RESET%^%^BOLD%^%^RED%^ "+
"%^RESET%^%^BOLD%^%^BLACK%^that hang by threads. He is in his late twenties,"+
" but %^RESET%^%^BOLD%^%^RED%^cuts %^RESET%^%^BOLD%^%^BLACK%^and %^RESET%^"+
"%^BOLD%^%^BLUE%^br%^RESET%^%^BLUE%^u%^RESET%^%^BOLD%^%^BLUE%^ises %^RESET%^"+
"%^BOLD%^%^BLACK%^make it hard to tell. His %^RESET%^%^YELLOW%^lo%^RESET%^"+
"%^ORANGE%^n%^RESET%^%^YELLOW%^g blo%^RESET%^%^WHITE%^n%^RESET%^%^YELLOW%^d"+
" hair %^RESET%^%^BOLD%^%^BLACK%^is %^RESET%^%^ORANGE%^filthy %^RESET%^%^BOLD%^"+
"%^BLACK%^and caked in %^RESET%^%^RED%^dried blood%^RESET%^%^BOLD%^%^BLACK%^. "+
"His left arm is burned and %^RESET%^%^BOLD%^%^BLUE%^brui%^RESET%^%^BLUE%^s"+
"%^RESET%^%^BOLD%^%^BLUE%^ed%^RESET%^%^BOLD%^%^BLACK%^, and his right is "+
"obviously broken as it hangs at an un natural angle from his body. He is "+
"bound in %^RESET%^%^WHITE%^thick black chains %^RESET%^%^BOLD%^%^BLACK%^caked in"+
" %^RESET%^%^BOLD%^%^RED%^blood%^RESET%^%^BOLD%^%^BLACK%^. You should "+
"%^RESET%^%^BOLD%^free him%^BLACK%^%^BOLD%^. %^RESET%^");
   set_race("human");
   set_stats("intelligence",16);
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
   set_exp(0);
   set_overall_ac(10);
   set_hd(35,15);
   set_max_hp(200);
   set_hp(20);
   set("aggressive",0);
   set_mob_magic_resistance("average");
   set_emotes(10, ({"%^RESET%^%^RED%^Joseph coughs, spitting up blood%^RESET%^.",
"%^RESET%^%^RED%^Blood drips from several wounds along Joseph's neck%^RESET%^",
"%^BLACK%^%^BOLD%^Joseph shivers"}), 0);
   set_spoken("wizish");
   command("speech mumble hoarsely");

   ob = new(OBJ"doren_wedding_ring.c");
   ob->move(TO);
   force_me("pose %^BLACK%^%^BOLD%^Bound in chains%^RESET%^");


}



void init() {
    ::init();
    add_action("free_fcn","free");
    bound = 1;
}



int free_fcn(string str) {
    if(!str) { return 0; }

    if( (str == "captive") || 
(str == "joseph") || 
(str == "Joseph") ||
(str == "Joseph Doren") ) {

        if (bound != 1){
            tell_object(TP,"%^RESET%^%^BOLD%^The man is not bound...%^RESET%^");
        return 1;
        }

        tell_object(TP,"%^RESET%^%^ORANGE%^You unbind the man...%^RESET%^");
        tell_room(ETO,"%^RESET%^RED%^\nAs the man is unbound, he coughs and "+
"drops an item he had hidden in his rags\n%^RESET%^");
        force_me("say Take this to my wife... Tell her I love her... \n"); 
        force_me("say I can't make it out.");
        force_me("drop ring");
        force_me("emote lays back against the wall and closes his eyes");
        force_me("pose %^BLACK%^%^BOLD%^Leaning against the wall%^RESET%^");
        bound = 0;
        return 1;
    }
}