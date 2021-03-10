inherit "/std/room";
void init() {
    ::init();
    add_action("read", "read");
}
void create() {
    ::create();
    set_property("light", 2);
    set_property("no teleport", 1);
    set_property("indoors", 1);
   set_short("Fighters' Bar");
    set("long",
@GRAY
                         %^RED%^Welcome Fighters!%^RESET%^
  This wooden structure is laid out like most bars but upon closer
inspection you can tell it is also a good place to hole up in, meaning this
place is like a fortress. The walls are lined with banners, armour and
shields to give it the right atmosphere for the enjoyment of the fighters
who frequent the bar. So pull up a chair and grab a drink! The menu's on the wall.
GRAY
);
    set_smell("default", "You smell sweat and alcohol.");
    set_listen("default", "You can hear some drunken fighters singing heartily.");
    set_items( ([
       "bar" : "Fighters Bar",
          "sign" : "The menu is posted there.",
          "menu" : "Maybe you should read the sign to see the menu."]));
    set_exits( ([
      "west" : "/d/tharis/Tharis/cguilds/fighter/fhall"
]) );
}
void reset() {
  ::reset();
  if(!present("barkeep")) {
    new("/d/tharis/monsters/brunhilda.c")->move(this_object());
  }
}
int read(string str) {
    object ob;
    int i;

   if(str != "menu") return 0;
    ob = present("barkeep");
    if(!ob) {
      write("You cannot read the menu, as it is splattered with blood.");
        return 1;
    }
  write("The following alcoholic beverages are served here.");
write("-------------------------------------------------------------------");
write("Fighter Special\t\t\t"+(int)ob->get_price("fighter special")+" gold");
write("Red Wine\t\t\t"+(int)ob->get_price("red wine")+" gold");
 write("Ale\t\t\t\t"+(int)ob->get_price("ale")+" gold");
write("Shot of Tequilla\t\t"+(int)ob->get_price("tequilla")+" gold");
write("Water\t\t\t\t "+(int)ob->get_price("water")+" gold");
    write("-----------------------------------------------------------");
    return 1;
}
