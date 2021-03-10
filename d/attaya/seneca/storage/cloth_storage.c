#include <std.h>
#include <objects.h>

inherit ROOM;
#define OPATH "/d/attaya/seneca/obj/clothing/"+

void create() {
    ::create();
    set_properties((["light":1, "indoors":1]));
    set_short("A storage room for the clothery.");
    set_long("Clothes are stored here - and you shouldn't be!\n");
    set_exits( (["up" : "/d/attaya/seneca/clothshop"]) );
    set_property("no teleport",1);

}
void reset() {
    ::reset();           
    if(!present("elegant robe"))
	new(OPATH "erobe")->move(TO);
    if(!present("fur coat"))
	new(OPATH "fcloak")->move(TO);
    if(!present("Lace girdle"))
	new(OPATH "girdle")->move(TO);
    if(!present("Lace girdle 2"))
	new(OPATH "girdle")->move(TO);
    if(!present("leather gloves"))
	new(OPATH "gloves")->move(TO);
    if(!present("fine hosery"))
	new(OPATH "hose")->move(TO);
    if(!present("fine hosery 2"))
	new(OPATH "hose")->move(TO);
    if(!present("fine breeches"))
	new(OPATH "pants")->move(TO);
    if(!present("fine breeches 2"))
	new(OPATH "pants")->move(TO);
    if(!present("waterproof cloak"))
	new(OPATH "plcloak")->move(TO);
    if(!present("waterproof cloak") && !random(3))
	new(OPATH "plcloak")->move(TO);
    if(!present("leather riding boots"))
	new(OPATH "rboots")->move(TO);
    if(!present("fine leather sandals"))
	new(OPATH "sandals")->move(TO);
    if(!present("boots of soft leather"))
	new(OPATH "sboots")->move(TO);
    if(!present("fine shoes"))
	new(OPATH "shoes")->move(TO);
    if(!present("fine shoes 2"))
	new(OPATH "shoes")->move(TO);
    if(!present("brocade doublet"))
	new(OPATH "sjacket")->move(TO);
    if(!present("well-made tunic"))
	new(OPATH "tunic")->move(TO);
    if(!present("well-made tunic 2"))
	new(OPATH "tunic")->move(TO);
    if(!present("well-made tunic 3") && !random(3))
	new(OPATH "tunic")->move(TO);
}
