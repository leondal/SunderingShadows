#include "/d/attaya/newseneca/seneca.h"
inherit "/std/fence";
    object ob;

void create() {
    ::create();
    set_name("sharpie");
    set_id( ({ "sharpie","Sharpie","shop keeper"}) );
    set_short("Sharpie, the Seneca thief's guild shopkeeper.");
    set("aggressive", 0);
    set_level(30);
    set_long("Sharpie is here to help you buy and sell your stuff. He gets his name because when he is not doing things for customers he spends time sharpening his daggers.\n"+
      "<help shop> will get you a list of shop commands.\n");
    set_gender("male");
    set_alignment(9);
    set_hd(35, 9);
    set_class("thief");
    set_mlevel("thief", 35);
    set("race", "human");
    add_money("gold", random(500));
    set_body_type("human");
    set_wielding_limbs(({"left hand","right hand"}));
    ob = new("/d/attaya/obj/screamer");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wield dagger in right hand");
    ob = new("/d/attaya/obj/screamer");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wield dagger in left hand");
    //set_storage_room(THIEF "storage");
    set_property("no bump", 1);
    set_emotes(20,({
	"%^CYAN%^You can hear Sharpie running his blade over a sharpening stone.%^RESET%^",
	"Sharpie hums softly to himself as he helps customers.",
	"%^MAGENTA%^Sharpie says%^RESET%^: I can remember a time when thieves were thieves and no laws or hunters could touch us!%^RESET%^",
      }) ,0);

}
