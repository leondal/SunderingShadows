//wargruf.c - The Wemic Elder
// Coded by Lujke 29/12/06
#include <std.h>
#include "../wemic.h"
inherit TEC_MOB + "QNPC.c";

void set_responses();

void create(){
   ::create();
   set_name("Wargruf");
   set_id( ({"wargruf","wemic","elder", "wemic elder", "elder wemic"}) );
   set_short("Wargruf, the wemic elder");
   set_long("An old wemic");
   set_gender("male");
   set_race("ghost");
   set_hd(90,5);
   set_alignment(5);
   set_max_hp(2500);
   set_hp(query_max_hp());
   set_overall_ac(-30);
   set_class("fighter");
   set_mlevel("fighter",35);
   set_level(35);
   set_stats("wisdom",19);
   set_stats("strength",18);
   set_stats("constitution",18);
   set_stats("intelligence",18);
   set_stats("charisma",16);
   set_stats("dexterity",18);
   set_exp(60);
   set("aggressive",0);
   set_responses();
}

set_responses(){
  set_response(({"jungle", "Jungle"}), ({"A sacred trust we hold, to"
            +" guard the jungle. For not only is it our hunting ground,"
            +" it is also the home of our %^GREEN%^ancestors%^RESET%^."
            +" There are many %^BLUE%^strange things%^RESET%^ in the"
            +" jungle."}) );
  set_response(({"ancestors", "Ancestors"}),({"We are an old people. On"
           +" this island we have lived for an age. And yet, we were not"
           +" always as we are now. Some of our youngsters do not like to"
           +" hear this, but..." , "Our %^BLUE%^oldest tales%^RESET%^ tell"
           +" of the founding of our race in the relationship between the"
           +" %^CYAN%^Tecqumin %^RESET%^and the jaguar God they"
           +" worshipped."}), "chuckle" );
  set_response(({"tecqumin", "Tecqumin"}), ({"Deep in the %^GREEN%^jungle"
           +"%^RESET%^ there is a %^BLUE%^lost city%^RESET%^, inhabited by"
           +" the %^BLUE%^ghosts%^RESET%^ of a long dead nation.", 
            "The Tecqumin are human, or were once. The remains of their"
           +" city have long since been lost in the jungle, and only their"
           +" shades now remain to haunt the place. Their artefacts suggest"
           +" they were worshippers of many gods and jungle spirits,"
           +" including the spirits of the jaguar. Our tales tell that"
           +" their closeness to the jaguar spirit lead to the creation of"
           +" our race.",
            "The tales also tell that they fell to a mighty curse, though"
           +" we do not know why."}) );
  set_response(({"lost city"}), ({"No, I can't tell you where it is. It's"
                                 +" lost.", 
                                  "It is most certainly in the%^GREEN%^"
                                 +" jungle%^RESET%^ somewhere, though."}) );
  set_response(({"where were you when you last had it?", "where did you"
                +" last have it?"}), ({"We've never had it. It was a"
                +" %^CYAN%^Tecqumin city%^RESET%^. The only hunters from"
                +" our tribe who have seen it went mad.",  
                 "Though to be honest, I think some of them were several"
                +" spots short of a leopardskin anyway."}) );
  set_response(({"Downfall of the Tecqumin", "downfall of the Tecqumin"}),
          ({"You have spoken with one of the ghosts of the %^CYAN%^Tecqumin"
           +" %^RESET%^about this?",
            "What an incredible tale! The power of the desctruction the"
           +" ghost told you must surely have come from Talos himself!"}),
            "surprise", ({"Knows about the downfall of the Tecqumin"}) );
  set_response(({"Lift the curse", "lift the curse"}),
          ({""}),
            "frowns", ({"Knows about the downfall of the Tecqumin"}) );


}
void chuckle (object speaker){
  force_me("emote chuckles");
}
void surprise(object speaker){
  force_me("emote widens his eyes in surprise");
}

void frowns(object speaker){
  force_me("emote frowns thoughtfully");
}