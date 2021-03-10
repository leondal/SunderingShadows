#include <std.h>
#include <objects.h>
      
inherit ROOM;
      
void create() {
  room::create();
  set_light(2);
  set_indoors(1);
  set_property("no attack", 1);
  set_short("Sanctuary's magical store");
  set_long("%^BLUE%^%^BOLD%^
This small building is a magical store for the town of %^YELLOW%^Sanctuary%^BLUE%^
All along the walls are strange and wonderful itmes whose purposes
are only understand for highly skilled adventures.  The walls are
filled with all kinds of strange bottles, scrolls and artifacts.
There is a %^YELLOW%^sign%^BLUE%^ next to the counter telling what is for sale.
      ");
  set_smell("default","The room is filled with mingled smells of various herbs and
concotions.");
     set_exits(([
                 "north":"/d/dragon/town/roadSW2"]));
      set_items(([
         "sign":"\n"+
         "%^RED%^***************************************************************%^RESET%^\n"+
         "%^GREEN%^                   ITEMS OFFERED:%^RESET%^\n"+
         "\n"+
         "     Vial of bright white liquid (extra healing)    150 gold\n"+
         "     Vial of dull white liquid (cure poison)        100 gold\n"+
         "     Vial of white liquid (regular healing)          50 gold\n"+
         "\n"+
         "%^%^BOLD%^GREEN%^          TYPE <%^YELLOW%^LIST%^GREEN%^> TO SEE WHATS IN STOCK.%^RESET%^\n"+
         "%^RED%^***************************************************************%^RESET%^\n",
"shelves":"These shelves are stacked with the components so vital to the mage."
        ] ));
  }
void reset(){
  ::reset();
  if(!present("rathe")) {
    new("/d/dragon/mon/rathe")->move(this_object());
  }
}


