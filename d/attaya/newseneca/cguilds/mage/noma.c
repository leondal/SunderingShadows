#include <std.h>
inherit VENDOR;

string *badpeople;
void do_display_help();
void do_say(string str);

void create() {
   ::create();
    set_name("Noma");
    set_id( ({ "noma", "clerk", "shop keeper", "shopkeeper"}) );
    set_short("Noma, the enabler of spells");
    set("aggressive", 0);
    set_level(30);
    set_long(
"Noma is a lethe, strong, and magical elf. She wears robes of red, and her brown hair is long, trailing behind her. Noma is here to serve you, presenting you with scrolls, wands, and sundry tools of academia. ");
    set_gender("female");
    set_alignment(5);
    set("race", "elf");
    set_class("mage");
    set_hd(144,1);
    set_level(30);
    set_body_type("elf");
    set_property("no bump", 1);
    set_property("no animate",1);
    set_storage_room("/d/attaya/newseneca/cguilds/mage/noma_storage.c");
    set_items_allowed("misc");
    set_mymaxvalue(1);
    set_spell_chance(90);
    set_spells(({
"acid arrow",
"burning hands",
"color spray",
"chill touch",
"hideous laughter",
"magic missile",
"lightning bolt",
"scorcher",
"cone of cold",
}));
    set_emotes(15,({
"%^MAGENTA%^Noma says:%^RESET%^ Welcome to my humble store. I trust you will find all you need here. ",
"Noma moves around her store sorting components and other mage essentials. ",
"%^GREEN%^With graceful movements, Noma flips her long hair away from her face and smiles at you.%^RESET%^ ",
"%^BOLD%^%^WHITE%^Almost imperceiveably, you see slight flashes of %^MAGENTA%^colour%^WHITE%^ shimmer around Noma's body. ",
"%^BLUE%^Noma giggles softly.%^RESET%^"}),0);
  set_exp(1);
new("/d/attaya/seneca/cguilds/mage/mrobe.c")->move(TO);
   command("wear armor");
}
 
//eof

