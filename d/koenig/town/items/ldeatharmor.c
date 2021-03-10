#include <std.h>
inherit "/std/armour";

void create(){
    ::create();
    set_name("deathknight armor");
    set_id( ({"armor","armour","deathknight armor","deathknight armour"}) );
    set_short("%^BOLD%^%^BLACK%^Dented Darkened Armor%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This is a set of heavy, dark plate armor. It is forged in such a way so that it takes in the light around it, reflecting nothing back. It has a traditional gothic style and looks sturdy, but well worn. Scratches and dents mar the surface, and it seems a bit weak at the joints. It is quite plain.%^RESET%^");
    set_ac(4);
    set_type("armour");
    set_limbs( ({"torso","right leg","left leg","right arm","left arm",
	"left foot","right foot"}) );
    set_value(2000);
   set_weight(30);
    set_wear( (:this_object(), "eventWear":) );
}

int eventWear() {
    if(!TP->is_class("fighter") && !TP->is_class("ranger") && !TP->is_class("cleric") && !TP->is_class("paladin") && !TP->is_class("inquisitor") && !TP->is_class("antipaladin") && !TP->is_class("cavalier")){
	message("info","This armor does not seem to fit you.",this_player());
	return 0;
    }
    message("info","%^RED%^You feel ready to destroy the world.",this_player());
    return 1;
}