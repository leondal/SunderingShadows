//Coded by Bane//
#include <std.h>
inherit "/std/vendor";
void create() {
    ::create();
    set_id(({"ximiz","shopkeeper","ximiz the shopkeeper"}));
    set_name("ximiz");
    set_short("Ximiz the shopkeeper");
    set_long(
	"Ximiz is your larger than average troll.  He stands nearly 10 feet "+
	"tall and has a shoulder width of about 5 feet.  His greasy black "+
	"hair is pulled back and tied tightly behind his head.  You can "+
	"<help shop> to get a list of the shop commands offered here."
    );
   set_gender("male");
    set_body_type("human");
    set_race("troll");
    set_size(2);
    set_alignment(5);
    set_storage_room("/d/laerad/parnelli/systyquah/gen_storage");
    set_hd(19,3);
    set_hp(155);
    set("aggressive",0);
}
void heart_beat(){
    ::heart_beat();
    if(TP->query_hp() < 154){
        TP->add_hp(2);
        return 1;
    }
}
