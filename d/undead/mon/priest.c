#include <std.h>
#include "../undead.h"
inherit NPC;

void create() {
    ::create();
    set_name("priest");
    set_id(({"priest", "ximes priest","order of ximes priest"}));
    set_short("Priest of the Order of Ximes");
    set("aggressive", 0);
    set_level(19);
    set_long("%^RESET%^%^CYAN%^This man is one of many of his Order that tends "
"to the castle.  %^YELLOW%^The Order of Ximes %^RESET%^%^CYAN%^is a sect of "
"%^BOLD%^%^RED%^Tempus %^RESET%^%^CYAN%^based upon the cursed island of Sangri"
".  They worship the Lord of Battle, taking His fight against the dark powers "
"that threaten to constantly overwhelm the isle.  While this man is garbed "
"in the robe of a priest and is quiet and respectful here, his sturdy build and "
"muscled frame hints that he too, plays his part in the fight for this city.");
    set_gender("male");
    set_alignment(5);
    set_race("human");
    add_money("gold", random(100));
    set_body_type("human");
    set_hd(19,3);
    set_max_hp(query_hp());
}

void init(){
   ::init();
   if (TP->query_ghost()) call_out("whisper_dead",1,TP);
}

void whisper_dead(object who){
   command("whisper "+who->query_name()+" you can %^YELLOW%^pray %^RESET%^for a "
"new body, or %^YELLOW%^return %^RESET%^if you feel strong enough to stand on "
"your own.");
}
