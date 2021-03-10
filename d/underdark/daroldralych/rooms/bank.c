#include <std.h>
#include "../defs.h"
inherit BANK;

string getBankId() { return "daroldralych";}

void create(){
   object ob; 
   ::create();
   set_property("light",-1);
   set_property("indoors",1);
   set_property("teleport proof",(25+roll_dice(1,20)));
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("Bank of Darol'Dralych");
   set_short("%^RESET%^%^BLUE%^Bank of Darol'Dralych%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Bank of Darol'Dralych%^RESET%^\n"
"%^BLUE%^This lowset, somewhat ominous building lacks much of the finesse in crafting that most others in the "
"city exhibit.  Instead, it is blatantly %^RED%^so%^ORANGE%^li%^RED%^d%^BLUE%^, without any windows whatsoever, and none "
"of the delicate arched beams to support the roof that are so commonly seen in drow architecture.  A long %^RED%^zurk"
"%^MAGENTA%^hw%^RED%^ood %^BLUE%^bench splits the room in half, on the opposite side of which are several drow, as well "
"as desks and tables covered in %^WHITE%^pap%^BOLD%^e%^RESET%^rwo%^BOLD%^r%^RESET%^k%^BLUE%^.  Set within the rear wall "
"is the massive, circular door of %^ORANGE%^gl%^YELLOW%^e%^RESET%^%^ORANGE%^ami%^BOLD%^%^WHITE%^n%^RESET%^%^ORANGE%^g "
"%^BLUE%^metal that likely leads to the vault beyond, but is firmly bolted closed.  There is a sign on the desk that you "
"could probably read.  The doorway, as the only public means in and out of the room, opens westwards onto the street "
"outside.%^RESET%^\n");

   set_smell("default","%^ORANGE%^The air is a little %^CYAN%^stale %^ORANGE%^and %^WHITE%^dry %^ORANGE%^in here.");
   set_listen("default","%^GREEN%^The clink of %^ORANGE%^c%^BOLD%^%^WHITE%^o%^RESET%^i%^BOLD%^%^WHITE%^n%^YELLOW%^s "
"%^RESET%^%^GREEN%^and the rustle of %^RESET%^paper %^GREEN%^fills the room.");

   set_items(([
     ({"wall","walls","roof"}):"%^BLUE%^The walls and roof of this shop are made of %^BOLD%^%^BLACK%^black "
"st%^RESET%^%^ORANGE%^on%^BOLD%^%^BLACK%^e%^RESET%^%^BLUE%^, a common sight in this city.  Here, however, they are "
"entirely bare and undecorated, giving the room a very spartan feel.%^RESET%^",
     "sign":"%^BLUE%^A sign rests upon the top of the bench, which you could probably %^WHITE%^read%^BLUE%^."
"%^RESET%^",
     ({"bench","wooden bench"}):"%^BLUE%^A long %^RED%^zurk%^MAGENTA%^hw%^RED%^ood %^BLUE%^bench splits the room in half"
".  Behind it are several drow, who clearly work here, and tables scattered with numerous sheets of %^WHITE%^pap%^BOLD%^e"
"%^RESET%^rwo%^BOLD%^r%^RESET%^k%^BLUE%^.%^RESET%^",
     ({"vault","massive vault"}):"%^BLUE%^Behind all the desks, set within the stone wall at the back of the room, is the "
"massive door of %^ORANGE%^gl%^YELLOW%^e%^RESET%^%^ORANGE%^ami%^BOLD%^%^WHITE%^n%^RESET%^%^ORANGE%^g %^BLUE%^metal, the "
"only apparent entry to the bank's vault.  Multiple thick, heavy bolts hold it closed, and its outer surface is etched "
"with numerous %^GREEN%^gl%^BOLD%^o%^CYAN%^w%^GREEN%^i%^RESET%^%^GREEN%^ng %^BLUE%^runes, likely some kind of ward"
".%^RESET%^",
   ]));
   set_exits(([
     "west":ROOMS"south2",
   ]));
}

void reset(){
   ::reset();
   if(!present("bank teller")) {
       new(MON"naddaer")->move(TO);
       tell_room(TO,"%^GREEN%^Naddaer stalks back in, a perpetual scowl etched upon his dark visage.%^RESET%^");
       return;
   }
}