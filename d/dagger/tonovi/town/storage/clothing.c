//storage room for Tonovi.  Circe 12/29/04
#include <std.h>
#include "../../short.h"
inherit ROOM;

#define TORM "/d/dagger/Torm/obj/"+
#define TABOR "/d/darkwood/tabor/obj/"+
#define THARIS "/d/tharis/obj/clothing/"+
#define LOTH "/d/barriermnts/lothwaite/obj/"+

void create()
{
	::create();
	set_property("indoors",1);
	set_property("light",2);
	set_short("Clothing Storage Room");
	set_long("Various items are stored here.");
	set_property("no teleport",1);
	set_exits((["down" : "/d/dagger/tonovi/town/bazaar5"]));
}

void reset()
{
	::reset();
if(!present("robe"))
 new("/d/common/obj/armour/robe")->move(TO);
if(!present("blue silk sash") && !random(3))
 new(TORM"bluesash")->move(TO);
if(!present("red silk sash") && !random(3))
 new(TORM"silksash")->move(TO);
if(!present("fine hosery") && !random(2))
 new(TORM"hose")->move(TO);
if(!present("tight leather pants") && !random(4))
 new(TORM"pantsl")->move(TO);
if(!present("puffy pantaloons") && !random(3))
 new(TORM"pantsp")->move(TO);
if(!present("riding boots") && !random(2))
 new(TORM"rboots")->move(TO);
if(!present("cork sandals") && !random(3))
 new(TORM"sandal")->move(TO);
if(!present("silk shirt") && !random(2))
 new(TORM"silkshirtb")->move(TO);
if(!present("silk shirt") && !random(2))
 new(TORM"silkshirtbb")->move(TO);
if(!present("silk shirt") && !random(2))
 new(TORM"silkshirtg")->move(TO);
if(!present("silk shirt") && !random(2))
 new(TORM"silkshirtr")->move(TO);
if(!present("silk shirt") && !random(2))
 new(TORM"silkshirtw")->move(TO);
if(!present("embroidered robe") && !random(3))
 new(THARIS"erobe")->move(TO);
if(!present("fur cloak") && !random(4))
 new(THARIS"fcloak")->move(TO);
if(!present("leather corset") && !random(2))
 new(THARIS"girdle")->move(TO);
if(!present("hose leggings") && !random(2))
 new(THARIS"hose")->move(TO);
if(!present("leather pants") && !random(4))
 new(THARIS"pants")->move(TO);
if(!present("cloak of good cloth"))
 new(THARIS"plcloak")->move(TO);
if(!present("shoes") && !random(3))
 new(THARIS"shoes")->move(TO);
if(!present("brocade jacket") && !random(6))
 new(THARIS"sjacket")->move(TO);
if(!present("tharis tunic") && !random(3))
 new(THARIS"tunic")->move(TO);
if(!present("choli") && !random(6))
 new(TABOR"c_choli")->move(TO);
if(!present("ghagra") && !random(6))
 new(TABOR"c_ghagra")->move(TO);
if(!present("kameez") && !random(6))
 new(TABOR"c_kameez")->move(TO);
if(!present("silk leggings") && !random(3))
 new(TABOR"c_leggings")->move(TO);
if(!present("tabor pantaloons") && !random(4))
 new(TABOR"c_pantaloons")->move(TO);
if(!present("embroidered robe") && !random(6))
 new(TABOR"c_robe")->move(TO);
if(!present("salwar") && !random(6))
 new(TABOR"c_salwar")->move(TO);
if(!present("sari") && !random(5))
 new(TABOR"c_sari")->move(TO);
if(!present("turban") && !random(8))
 new(TABOR"c_turban")->move(TO);
if(!present("short vest") && !random(6))
 new(TABOR"c_vest")->move(TO);
}
