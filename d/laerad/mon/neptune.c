//Coded by Bane//
#include <std.h>
inherit "/std/comp_vend";
void create() {
    ::create();
    set_id(({"neptune","shopkeeper","neptune the shopkeeper"}));
    set_name("neptune");
    set_short("Neptune the shopkeeper");
    set_long(
	"Neptune is a very slim and dark figure.  He is dressed in a black robe "+
	"with a hood pulled down over his head.  His voice is very deep and "+
	"dominant.  You can <list comp> to see what is for sale."
    );
   set_gender("male");
    set_body_type("human");
    set_race("human");
    set_size(2);
    set_alignment(5);
    set_components(100);
    set_hd(19,3);
    set_hp(155);
    set("aggressive",0);
}

