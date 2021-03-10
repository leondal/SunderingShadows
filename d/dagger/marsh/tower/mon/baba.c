//Circe 11/5/03 - added hints for syntax
#include <std.h>
inherit MONSTER;

void create() {
    :: create();
    set_name("baba");
    set_id(({
	"baba","yaga","baba yaga"
    }));
    set_short("%^RESET%^"
	"%^RED%^B"
	"%^GREEN%^a"
	"%^RED%^b"
	"%^GREEN%^a "
	"%^MAGENTA%^Y"
	"%^GREEN%^a"
	"%^BLUE%^g"
	"%^GREEN%^a%^RESET%^"
    );
    set_long(
	"%^GREEN%^The small imp of a humanoid looks very crafty and money hungry. "
	"She is dressed in long merchant robes and sports a sly grin.  If you feel "+
      "lucky, you might be able to <purchase> what's in the box from him.%^RESET%^"
    );
    set_gender("female");
    set_hd(5,1);
    set_size(2);
    set_wielding_limbs(({"right hand","left hand"}));
    set_overall_ac(0);
    set_hp(32);
    set_max_hp(32);
    set_exp(400);
    set_body_type("humanoid");
    set_race("human");
    set_class("mage");
    set_guild_level("mage",5);
    set_stats("strength",16);
    set_stats("constitution",9);
    set_stats("dexterity",16);
    set_stats("wisdom",12);
    set_stats("intelligence",15);
    set_stats("charisma",10);
    set_alignment(1);
    set_emotes(3, ({
	"%^MAGENTA%^Baba Yaga says: %^RESET%^Lets make a deal!",
	"%^MAGENTA%^Baba Yaga says: %^RESET%^Do you like surprises?",
	"%^MAGENTA%^Baba Yaga says: %^RESET%^I wonder whats in this box?",
	"%^MAGENTA%^Baba Yaga says: %^RESET%^Would you like to purchase this box?",
	"%^MAGENTA%^Baba Yaga says: %^RESET%^10000 gold and the contents of the box are yours!",
	"%^MAGENTA%^Baba Yaga says: %^RESET%^For 10000 gold you can have whats inside this box!",
    }),0);
}

	
