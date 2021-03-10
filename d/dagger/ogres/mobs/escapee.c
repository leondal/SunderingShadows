#include <std.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("ogre escapee");
    set_id( ({"ogre", "escapee", "ogre escapee", "cavemon"}) );
    set_short("Ogre escapee");
    set_long("%^RESET%^%^ORANGE%^This ogre has been b%^RESET%^%^BOLD%^%^BLACK%^"+
"e%^RESET%^%^ORANGE%^ate%^RESET%^%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^ and b"+
"%^RESET%^%^RED%^l%^RESET%^%^ORANGE%^ood%^RESET%^%^RED%^i%^RESET%^%^ORANGE%^ed"+
" and her wounds are severe. Her left arm is hanging by the %^RESET%^%^WHITE%^"+
"tendons%^RESET%^%^ORANGE%^, and most of her right side has been %^RESET%^%^BOLD%^"+
"%^BLACK%^bu%^RESET%^%^WHITE%^r%^RESET%^%^BOLD%^%^BLACK%^ned horri%^RESET%^%^WHITE%^"+
"b%^RESET%^%^BOLD%^%^BLACK%^ly%^RESET%^%^ORANGE%^. She was wearing a dun colored cloak"+
", but it also has been torn and burned. %^RESET%^"
    );
    set_gender("female");
    set("race","ogre");
    set_body_type("human");
    set_overall_ac(5);
    set_hd(5,1);
    set("aggressive",3);
    set_size(3);
    set_max_hp(30);
    set_hp(30);
    set_emotes(5, ({
	"The ogress sits on the floor and mutters to herself.  Perhaps you could get her attention by nodding to her.",
      }),0);
}

void init() {
    ::init();
    add_action("nod_fcn","nod");
}



int nod_fcn(string str) {
    if(!str) { return 0; }

    if( (str == "ogre") || (str == "escapee") || (str == "ogre escapee") || (str == "ogress") ) {
tell_room(ETO,"%^RED%^The ogre looks up, and speaks in slow, broken language\n%^RESET%^");
tell_room(ETO,"%^ORANGE%^'You.. You strong! You go slay demons and free clan of Midnight Cave!'%^RESET%^\n");
tell_room(ETO,"%^ORANGE%^'You go slay demons that kill chief! But you need figure out bridge! Me broke bridge! Me smart!'%^RESET%^\n");
tell_room(ETO,"%^ORANGE%^'You face river! But you not clan, clan attack you too!'%^RESET%^\n");
tell_room(ETO,"%^ORANGE%^'You strong... '%^RESET%^\n");
tell_room(ETO,"%^RED%^%^BOLD%^The ogre coughs, and dies... %^RESET%^\n\n");
	TO->die();
	return 1;
    }
}


int should_interact(object ob) { return 1;}
