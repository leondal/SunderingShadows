// File   : blacksmith.c
// Author : Pator@Shadowgate
// Date   : Jun 14 1995

#include <castle.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("Terresias");
    set("id", ({"terresias", "smith", "blacksmith", "halfling"}) );
    set("short", "Terresias,the Marleen castle blacksmith");
    set("long", 
@PATOR
  This is the castle blacksmith. He is very nice, but you can't ask him to make anything for you, because he will only work for his queen.
PATOR
);
    set("race", "halfling");
    set_gender("male");
    set_body_type("human");
    set_hd(10,5);
    set_max_sp(650);
    set_wielding_limbs( ({"right hand", "left hand"}) );
    set_hd(10,4);
    set_alignment(4);
    set_size(2);
    set_class("fighter");
    set_achats(20, ({
               "Terresias shouts : YER KNEECAPS BE MINE!!!\n",
               "You are nearly knocked over as Terresias swings at your "+
                    "kneecaps",
               "Terresias screams:  YER MODDER BE A TROLL!!!\n",
              }) );
    set_emotes(10, ({
       "Terresias slams his hammer onto the anvil.",
        "Sparks fly from the anvil.",
        "Steam fills the room as the Swordsmith plunges something "+
            "into a bucket of water."
    }), 0);
//    new(CASTLE+"object/hammer")->move(this_object());
//    new(CASTLE+"object/apron")->move(this_object());
//    command("wear apron");
    command("wield hammer in right hand");
}
