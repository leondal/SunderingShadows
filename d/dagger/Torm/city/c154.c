#include "../tormdefs.h"
inherit TOWN;
  int moved;
void create(){
  ::create();
  set_short(
    "Beneath the Torm townhall"
  );
  set_property("indoors",1);
  set_long(
  "  The stone walls of this room shine with a thin coating of what appears to be ice."
  "  A spell must of been laid on this room to keep it so cool, to function as storage for the wine and perishable goods here."
  "  Wine racks line the south wall, while shelves against the other three hold other goods."
  );
  set_exits(([
  "west":TCITY+"c153",
  ]));
  set_items(([
  "walls":"The walls here are dull grey stone, very cold with ice showing in places on them.",
  "floor":"The floor is rough dressed stone and there are scratches on it by the base of one of the wine racks.",
  "scratches":"The scratches look like the wine racks been moved recently.",
  ({"wind racks","racks","wine"}):"The wine in these racks seems of considerable quality but the glass is old and fragile.",
  "shelves":"The shelves hold meats and some other perishables.",
  ({"ceiling","roof"}):"The ceiling here is rough grey stone.",
      "tapestries":"Ornate gilded tapestries cover the stone walls."
  ]));
}
void init(){
  ::init();
  add_action("move","move");
}
int move(string str){
  if(!str){ write("Move what?"); return 1;}
  if(str !="wine rack"){write("try move wine rack"); return 1;}
    if(moved){write("Umm, it's already open.");return 1;}
  moved=1;
  tell_room(this_object(),"The wine rack slips out, scraping lightly against the floor.");
  add_exit("/d/dagger/Torm/city/c156","hole");
  return 1;
}
void reset(){
  ::reset();
  if(moved){
  tell_room(this_object(),"The wine rack slides back into place.");
  moved=0;
  remove_exit("hole");
  }
}
