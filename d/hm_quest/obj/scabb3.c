#include <std.h>
inherit OBJECT;

string owner;
int SHEATH;

void create() {
    ::create();
    set_name("scabbard");
    set_id(({"scabbard3","hm_quest_symbols","scabbard of symbols","scabbard"}));
    set_short("%^RESET%^%^MAGENTA%^Scabbard of symbols%^RESET%^");
    set_long("%^RESET%^This %^CYAN%^metallic %^RESET%^scabbard must have once been home to an impressive blade, for it is incredibly fine in its crafting. Obviously %^RED%^old%^RESET%^, and "
"worn in several places, it must have been %^YELLOW%^breathtaking %^RESET%^to look upon when first made. The entire outer surface of it is covered in strange %^MAGENTA%^symbols %^RESET%^"
"that still bear a faint glow of power. You could sheath a blade in it, though you would have to find one very specifically shaped to fit.%^RESET%^");
    set_weight(4);
    set_value(0);
    set_heart_beat(1);
}

void init() {
    ::init();
    if(interactive(TP) && !owner) owner = TP->query_true_name();
    add_action("sheath_fun","sheath");
    add_action("insert_fun","insert");
}

void heart_beat() {
    string holder;
    if(!objectp(ETO)) return;
    if(!interactive(ETO)) return;
    holder = ETO->query_true_name();
    if(holder != owner) {
      tell_object(ETO,"The scabbard of symbols vanishes!");
      TO->remove();
    }
}

int sheath_fun(string str) {
    object blade;
    if((string)TP->query_name() != owner) return 0;
    if((int)TP->query_level() < 19) return 0;
    if(!str) {
	notify_fail("Sheath what in what?\n");
	return 0;
    }
    if(str != "blade in scabbard") {
      notify_fail("You can't sheath that.\n");
      return 0;
    }
    if(SHEATH) {
	notify_fail("There is already a weapon in that sheath!\n");
	return 0;
    }
    if(!blade = present("hm_quest_bronze",TP)) {
	notify_fail("You don't have a blade that would fit!\n");
	return 0;
    }
    if(base_name(blade) != "/d/hm_quest/obj/blade3") {
	notify_fail("That blade doesn't fit the scabbard!\n");
	return 0;
    }
    if(!(int)blade->is_joined()) {
	notify_fail("You should try to assemble the sword first!\n");
	return 0;
    }
    tell_object(TP,"%^CYAN%^The magical energy around both the blade and the scabbard flares brightly as they are brought together, and the weapon slides smoothly into the scabbard, as though it were made to fit.%^RESET%^");
    SHEATH = 1;
    blade->remove();
    set_short("%^RESET%^%^MAGENTA%^Scabbard of symbols (blade sheathed)%^RESET%^");
    set_long("%^RESET%^This %^CYAN%^metallic %^RESET%^scabbard must have once been home to an impressive blade, for it is incredibly fine in its crafting. Obviously %^RED%^old%^RESET%^, and "
"worn in several places, it must have been %^YELLOW%^breathtaking %^RESET%^to look upon when first made. The entire outer surface of it is covered in strange %^MAGENTA%^symbols %^RESET%^"
"that still bear a faint glow of power. A %^ORANGE%^bronze %^RESET%^sword has been sheathed within, and there is a depression in the center of the protruding hilt that appears to have held a "
"%^YELLOW%^jewel %^RESET%^at one time, leaving you to think that you could insert a similarly-shaped gem to complete the weapon.%^RESET%^");
    set_weight(13);
    return 1;
}

int insert_fun(string str) {
    object gem;
    if((string)TP->query_name() != owner) return 0;
    if((int)TP->query_level() < 19) return 0;
    if(!str) {
	notify_fail("Insert what in what?\n");
	return 0;
    }
    if(str != "diamond into hilt" && str != "diamond into sword" && str != "gem into hilt" && str != "gem into sword") {
      notify_fail("You can't insert that.\n");
      return 0;
    }
    if(!gem = present("hm_quest_diamond",TP)) {
	notify_fail("You don't have a gem that would fit!\n");
	return 0;
    }
    if(base_name(gem) != "/d/hm_quest/obj/gem3") {
	notify_fail("That gem doesn't fit into the hilt!\n");
	return 0;
    }
    if(!SHEATH) {
	notify_fail("The weapon isn't yet properly assembled!\n");
	return 0;
    }
    tell_object(TP,"%^CYAN%^The magical energy around the gem and the sheathed weapon flares brightly as they are brought together, and the gem settles into place with a satisfying click. Finally the Sword of Fate is complete!%^RESET%^");
    gem->remove();
    TO->move("/d/shadowgate/void");
    new("/d/hm_quest/obj/sword3.c")->move(TP);
    TO->remove();
    return 1;
}
