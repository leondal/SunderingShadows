//Coded by Bane//
#include <std.h>
inherit BARKEEP;
void create(){
    ::create();
    set_id(({"dar","barkeep","dar the barkeep"}));
    set_name("dar");
    set_short("Dar the barkeep");
    set_long(
	"Dar is a rather large Bugbear.  He stands over 9 feet tall and "+
	"is wearing a leather apron.  He stands behind the bar closely "+
	"watching everyone, just in case a fight breaks out."
    );
    set_gender("male");
    set_alignment(9);
    set_race("bugbear");
    set_hd(19,1);
   set_hp(300);
    set("aggressive",0);
   add_money("gold", random(200));
    set_body_type("human");
    set_currency("gold");
    set_menu(
        ({
	"systyquah special","fire water","leg of elf","dwarf stew","water"
        }),
	({"alcoholic","alcoholic","food","food","water"}),
	({10, 15, 25, 5, 1})
    );
    set_my_mess(
        ({
	"You down the special and pucker at its tart tast.\n",
	"You slam a shot of Fire water and nearly scream in pain.\n",
	"You quickly scarf down the Leg of Elf, yummy.\n",
	"You drain the bowl of Dwarf stew, talk about chunky.\n",
	"You drink the mug of water.\n"
        })
    );
    set_your_mess(
        ({
	"downs the special and puckers up.\n",
	"slams a shot of Fire water and coughs very loud.\n",
	"scarfs down a Leg of Elf.\n",
	"drains a bowl of Dwarf stew.\n",
	"drinks a mug of water.\n",
        })
    );
    set_menu_short(
        ({
	"Systyquah special",
	"A shot of Fire water",
	"Plate of Leg of Elf",
	"Bowl of Dwarf stew",
	"Mug of water"
        })
    );
    set_menu_long(
        ({
	"A Systyquah special, straight from troll land.\n",
	"A shot of the infamous Fire water from Systyquah.\n",
	"A plate of Leg of Elf, a tasty delicacy in Systyquah.\n",
	"A large bowl of Dwarf stew from Systyquah.\n",
	"A small mug of water.\n"
        })
    );
} 
