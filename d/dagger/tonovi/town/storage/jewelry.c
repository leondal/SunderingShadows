//storage room for Tonovi.  Circe 12/29/04
#include <std.h>
#include "../../short.h"
inherit ROOM;

#define TORM "/d/dagger/Torm/obj/"+
#define TABOR "/d/darkwood/tabor/obj/"+
#define THARIS "/d/tharis/obj/rings/"+
#define DAGGER "/d/dagger/Daggerdale/shops/items/"+

void create()
{
	::create();
	set_property("indoors",1);
	set_property("light",2);
	set_short("Jewelry Storage Room");
	set_long("Various items are stored here.");
	set_property("no teleport",1);
	set_exits((["down" : "/d/dagger/tonovi/town/bazaar5"]));
}

void reset()
{
object obj;
	::reset();
if(!present("crushed bracelet") && !random(5))
 new(TABOR"c_bracelet")->move(TO);
if(!present("clasp") && !random(2))
 new(TABOR"c_clasp")->move(TO);
if(!present("crystal necklace") && !random(2))
 new(TABOR"c_crystal")->move(TO);
if(!present("cufflinks") && !random(3))
 new(TABOR"c_cufflinks")->move(TO);
if(!present("petal earrings") && !random(3))
 new(TABOR"c_earrings")->move(TO);
if(!present("cabochon ring") && !random(4))
 new(TABOR"c_ring")->move(TO);
if(!present("crystal strand") && !random(3))
 new(TABOR"c_strand")->move(TO);
if(!present("golden link belt") && !random(6))
 new(TABOR"belt")->move(TO);
if(!present("bangle bracelet") && !random(4))
 new(THARIS"bangle_bracelet")->move(TO);
if(!present("braided bracelet") && !random(2))
 new(THARIS"braided_bracelet")->move(TO);
if(!present("talon earrings") && !random(3))
 new(THARIS"claw_earrings")->move(TO);
if(!present("coiffe") && !random(2))
 new(THARIS"coiffe")->move(TO);
if(!present("engagement ring"))
 new(THARIS"de")->move(TO);
if(!present("fibula") && !random(3))
 new(THARIS"fibula")->move(TO);
if(!present("jeweled ring") && !random(2))
 new(THARIS"hj")->move(TO);
if(!present("king's platinum band") && !random(6))
 new(THARIS"kp")->move(TO);
if(!present("peacock brooch") && !random(5))
 new(THARIS"peacock_brooch")->move(TO);
if(!present("majestic pendant") && !random(6))
 new(THARIS"pendant_royal")->move(TO);
if(!present("three-stone pendant") && !random(3))
 new(THARIS"pendant_three")->move(TO);
if(!present("slight gold band"))
 new(THARIS"sg")->move(TO);
if(!present("whalebone choker") && !random(5))
 new(TORM"choker")->move(TO);
if(!present("carved necklace") && !random(3))
 new(TORM"r_necklace")->move(TO);
if(!present("glasses") && !random(5))
 new(TORM"eyeglasses")->move(TO);
if(!present("pearls") && !random(2))
 new(TORM"freshpearls")->move(TO);
if(!present("gold bracelet") && !random(2))
 new(TORM"gbracelet")->move(TO);
if(!present("pearl anklet") && !random(3))
 new(TORM"panklet")->move(TO);
if(!present("pearl earrings") && !random(4))
 new(TORM"pearrings")->move(TO);
if(!present("silver comb") && !random(5))
 new(TORM"scomb")->move(TO);
if(!present("silver anklets") && !random(3))
 new(DAGGER"anklets")->move(TO);
if(!present("r_clasp") && !random(3))
 new(DAGGER"r_clasp")->move(TO);
}
