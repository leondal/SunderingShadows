inherit "/std/room";

int BD, IW, BB;
int SV, PA;

void init() {
    ::init();
    add_action("read", "read");
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "Spider Web tavern");
    set_long("%^BOLD%^%^BLUE%^
Inside this timber and stone structure, the cool air gives way to
blasting heat.  A raging fire burns in the fireplace within the east
wall.  In the normal times, this tavern served as a gathering place
for the townsfolk after the day's chores.  Now adays only drunks and
adventurers come here for a soothing, cool drink.  If the bartender 
is around, she will gladly fulfill your order.  A large wooden sign
hangs above the dark wooden bar thats in front of you.
  ");
     set_smell("default","You smell the odor of exotic alcohol.");
    set_items(
        (["tavern" : "Sanctuary Pub",
          "sign" : "The menu is posted there.",
          "menu" : "Maybe you should read the sign to see the menu."]));
    set_exits(
              (["west" : "/d/dragon/town/roadN1"]) );
  new("/d/dragon/mon/drunk")->move(this_object());
}

void reset() {
  ::reset();
  if(!present("barkeep")) {
    new("/d/dragon/mon/autre")->move(this_object());
  }
}
int read(string str) {
    object ob;
    int i;
    ob = present("barkeep");
    if(!ob) {
        write("You cannot read the sign, as it is splattered with blood.");
        return 1;
    }
  BD = (int)ob->get_price("burningdeath");
  IW = (int)ob->get_price("wine");
  BB = (int)ob->get_price("beer");
  SV = (int)ob->get_price("vodka");
  PA = (int)ob->get_price("ale");
    write("%^BOLD%^%^GREEN%^
[=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-]
                     %^YELLOW%^     Sanctuary Pub%^GREEN%^
 =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
%^RED%^
     Burningdeath                           "+BD+" gold
     Imported Wine                          "+IW+" gold
     Bottle of beer                         "+BB+" gold
     Shot of vodka                          "+SV+" gold
     Pale ale                               "+PA+" gold
%^GREEN%^
[=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-]
  ");
    return 1;
}
