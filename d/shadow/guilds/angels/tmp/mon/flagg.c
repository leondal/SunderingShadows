//Coded by Bane//
#include <std.h>
inherit "/std/vendor.c";
create() {
    ::create();
    set_name("flagg");
    set_id(({"flagg","barkeep","dealer","tobacco dealer"}));
    set_short("Flagg the tobacco dealer");
    set_long(
	"Flagg is dressed in a long back trench "+
	"coat.  He is rather short but a stocky man.  The "+
	"inside of his coat is filled with different "+
	"types of tobacco that you may purchase.  You can see "+
	"what he is selling by typing <list>."
    );
    set_gender("male");
    set("aggressive",0);
    set_race("human");
    set_hd(15,0);
   set_hp(300);
    set_property("no bump",1);
   add_money("gold", random(200));
    set_body_type("human");
    set_storage_room("/d/shadow/guilds/angels/tmp/smoke_house");
}
