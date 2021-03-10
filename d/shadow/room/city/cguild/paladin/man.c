#include <std.h>
#include <daemons.h>
#include "/d/dagger/drow/short.h"
inherit MONSTER;
void create() {
    :: create();
    set_name("man");
    set_id(({
	"man","old man"
    }));
    set_short("Old and injured man");
    set_long(
	"%^CYAN%^The man before you is very old and injured as though "
	"he was attacked by bandits or a foul wilderness beast. He is "
	"dressed in rags and blood streams from an open wound in his "
	"head. "
	"His tear streaked face cries to you his pain and suffering."
    );
    set_gender("male");
    set_hd(1,1);
    set_size(2);
    set_wielding_limbs(({"right hand","left hand"}));
    set_overall_ac(9);
    set_hp(5);
    set_max_hp(30);
    set_exp(0);
    set_body_type("human");
    set_race("human");
    set_class("mage");
    set_guild_level("mage",1);
    set_stats("strength",10);
    set_stats("constitution",9);
    set_stats("dexterity",10);
    set_stats("wisdom",12);
    set_stats("intelligence",15);
    set_stats("charisma",10);
    set_alignment(1);
    set("aggressive",1);
    set_emotes(5,({
    "%^MAGENTA%^Man says%^RESET%^: I hear there are evil Paladins in deku forming some kind of cult.",
    "Old man coughs weakly.",
    "%^MAGENTA%^Man says%^RESET%^: There is this evil cult in deku, them call themselves Antipaladins.",
    "%^MAGENTA%^Man says%^RESET%^: The Antipaladin cult near the deku fortress used to be Paladins!  Can you believe it?!",
    }),0);
}
