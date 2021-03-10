#include <std.h>
inherit NPC;

void create() {
    ::create();
    set_name("Raliat");
    set_id( ({"raliat", "Raliat", "healer", "woman"}) );
    set_short("%^BOLD%^%^GREEN%^Raliat, a simple woman giving off an aura of peace%^RESET%^");
    set_long("%^BOLD%^%^GREEN%^This woman is towering, approaching six and a half feet tall. She is also "+
    "very muscular from what glimpses of her flesh you can get. She has very simple light red hair "+
    "which hangs lazily down to her shoulders and brilliant blue eyes. Her eye reflect a deep and unabiding kindness. "+
    "She is dressed in very simple robes which flow loosely across her torso, down to her elbows, and slightly below her "+
    "knees. At first glance you believe that she is a simple woman, but something about her radiates power and "+
    "peace. It is almost like you can see a tangible aura surrounding her.%^RESET%^");
    set("aggressive", 0);
    set_guild_level("cleric", 30);
    set_mlevel("cleric", 30);
    set_new_exp(30, "very low");
    set_gender("female");
    set_alignment(4);
    set_race("human");
    add_money("gold", random(50));
    set_body_type("human");
    set_hd(30,3);
    set_hp(1500);
}
