#include <std.h>
      
inherit ROOM;
      
void create() {
  ::create();
  set_light(2);
  set_indoors(1);
  set_short("Gareth's magical store");
  set_terrain(STONE_BUILDING);
  set_travel(PAVED_ROAD);
  set_long(
@GRAY
%^YELLOW%^Gareth's Magic Shop%^RESET%^
This is a shop that sells potions in Keep Blacktongue.  All along
the walls are strange and wonderful items with purposes only truly
understood by mages or healers.  The shelves are filled with all kinds
of strange bottles and ingredients for them.  There is a sign next
to the counter telling what is for sale.
GRAY
     );
  set_smell("default","The room is filled with mingled smells of various herbs "
    "and concoctions.");
  set_exits(([  "east":"/d/deku/keep/keepE4"]));
  set_items(([
  "sign":"\n"+
   "%^RED%^***************************************************************"
   "%^RESET%^\n"+
   "%^GREEN%^                   ITEMS OFFERED:%^RESET%^\n\n"+
   "     Vial of dull white liquid (cure poison)        100 gold\n\n"+
   " Other potions have become unavailable due to supply problems.\n\n"+
   " See the healer in Verbobone for healing kits.\n\n"+
   "%^%^BOLD%^GREEN%^          Type <%^YELLOW%^list%^GREEN%^> to see what's in "
     "stock.%^RESET%^\n"+
   "%^RED%^***************************************************************"
   "%^RESET%^\n",
"shelves":"These shelves are stacked with the ingredients for the potions."
        ] ));
}

void reset(){
  ::reset();
  if(!present("gareth")) {
    new("/d/deku/keep/monster/gareth")->move(TO);
  }
}


