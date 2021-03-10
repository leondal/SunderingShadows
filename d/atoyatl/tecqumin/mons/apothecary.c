//jontar.c - The Old Priest                                 
// Coded by Lujke 29/12/06
#include <std.h>
#include "../tecqumin.h"
inherit MOB + "QNPC.c";

nosave int BEAT;

void set_responses();

void create(){
   ::create();
   set_name("Apothecary");
   set_id( ({"apothecary", "ghost", "tecqumin"}) );
   set_short("%^RESET%^%^CYAN%^Tecqumin %^ORANGE%^apothecary");
   set_long("%^RESET%^This %^CYAN%^Tecqumin%^RESET%^ ghost is a"
     +" little more substantial than most, and appears to be"
     +" wearing a long, %^ORANGE%^stained%^RESET%^ robe. Its"
     +" %^BOLD%^%^WHITE%^t%^RESET%^u%^BOLD%^%^WHITE%^ft%^RESET%^"
     +"e%^BOLD%^%^WHITE%^d %^RESET%^ha%^BOLD%^%^WHITE%^i%^RESET%^r"
     +" shoots upwards from its head, giving it a rather surprised"
     +" air. It appears to have been missing most of its teeth in"
     +" life.");
   set_gender("male");
   set_race("ghost");
   set_body_type("human");
   set_hd(60,5);
   set_alignment(5);
   set_max_hp(1500);
   set_hp(query_max_hp());
   set_overall_ac(50);
   set_class("fighter");
   set_mlevel("fighter",30);
   set_level(30);
   set_stats("wisdom",19);
   set_stats("strength",18);
   set_stats("constitution",18);
   set_stats("intelligence",18);
   set_stats("charisma",16);
   set_stats("dexterity",18);
   set_exp(60);
   set("aggressive",0);
   set_responses();
   set_property("untrackable", 1);
   will_open = 1;
   BEAT = 0;
   check_my_heart();
}

void check_my_heart()
{
    if(BEAT > 7)
    {
        set_heart_beat(1);
        BEAT = 0;
        call_out("check_my_heart",1);
        return;
    }
    BEAT++;
    call_out("check_my_heart",1);
    return;
}


set_responses(){
  set_response(({"draught of flowers"}), 
   ({"Yes, yes, I used to make the draught. But I don't have it"
    +" - a sneaky jaguar took it, you see!", "If you want it, you'll"
    +" have to track him down!"}) );

  set_response(({"mushroom pot"}), 
   ({"Yes, yes, I used to make the draught. But I don't have it"
    +" - a sneaky jaguar took it, you see!", "If you want it, you'll"
    +" have to track him down!"}) );
  set_response(({"mushroom cup"}), 
   ({"Yes, yes, I used to make the draught. But I don't have it"
    +" - a sneaky jaguar took it, you see!", "If you want it, you'll"
    +" have to track him down!"}) );

  set_response(({ "mushroom vessel"}), 
   ({"Yes, yes, I used to make the draught. But I don't have it"
    +" - a sneaky jaguar took it, you see!", "If you want it, you'll"
    +" have to track him down!"}) );

}

