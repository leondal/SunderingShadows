// Chernobog (4/4/21)
// Shadow Coliseum

#include <std.h>
inherit MONSTER;

void create()
{
    ::create();
    set_name("dummy");
    set_id(({ "dummy", "test dummy", "training dummy", }));
    set_race("test dummy");
    set_body_type("human");
    set_short("%^BOLD%^%^BLACK%^An %^RESET%^average %^BOLD%^%^BLACK%^looking %^RESET%^%^ORANGE%^dummy%^BOLD%^%^BLACK%^, %^RESET%^wo%^BOLD%^r%^RESET%^n %^BOLD%^%^BLACK%^and %^RESET%^%^RED%^b%^BOLD%^a%^RESET%^%^RED%^t%^BOLD%^te%^RESET%^%^RED%^r%^BOLD%^e%^RESET%^%^RED%^d%^WHITE%^");
    set_long("%^RESET%^%^BOLD%^Pa%^RESET%^d%^BOLD%^di%^RESET%^n%^BOLD%^g %^RESET%^%^CYAN%^has been wrapped around a vaguely humanoid %^ORANGE%^wooden frame%^CYAN%^. The padding is %^RED%^be%^MAGENTA%^a%^RED%^ten %^CYAN%^and %^MAGENTA%^th%^RED%^r%^MAGENTA%^eadb%^RED%^a%^MAGENTA%^re %^CYAN%^in spots, evidence of hard use. Some enterprising warrior has added a %^BOLD%^%^BLACK%^crude face %^RESET%^%^CYAN%^in coal, perhaps to envision his enemy better while training. The base of the dummy is a wooden post, allowing it to be slotted in place around the room.%^RESET%^");
    set_hd(1, 1);
    set_class("fighter");
    set_mlevel("fighter", 1);
    set_hp(1000);
}

void die(object ob) {
    tell_room(ETO,"%^BOLD%^%^RED%^The dummy cracks and splinters into pieces!%^RESET%^");
    if(sizeof(all_inventory(TO))){
        all_inventory(TO)->move("/d/shadowgate/void.c");
    }
    ::die();
}

