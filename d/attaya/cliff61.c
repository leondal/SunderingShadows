inherit "/d/attaya/spec/cliff";

#include <std.h>
void create() {
     ::create();
     set_light(2);
     set_indoors(1);
    set_property("no teleport",1);
     set_short("Atop the altar");
      set_long("
    You are on top of the altar!  A strange magic force holds your torso to the altar's surface!  A strange glowing symbol beneath your right hand casts a light on the ceiling.  
    %^BOLD%^%^BLACK%^The shadows are closing in on you!  You can see them gathering!
    %^RESET%^%^RED%^As you struggle to free yourself, the block on which the symbol is printed pushes into the altar slightly!
");
     set_smell("default", "%^BOLD%^A glowing symbol appears on the altar for a moment, then fades away.\n");
      set_items(([
    "altar" : "The altar is made of obsidian and marble, and has a few glowing symbol blocks on it's surface.",
     "symbol" : "The glowing symbol is printed upon a strange tile beneath your hand!",
     "block" : "A symbol block lies just beneath your right hand!",
     "tile" : "A symbol block lies just beneath your right hand!",
     "ceiling" : "The ceiling is made of sandstone and is alive with the shadows upon it!",
     "shadows" : "%^BOLD%^%^BLACK%^They are coming for you."
]));
}
void reset() {
  ::reset();
    if(!present("warlock"))
new("/d/attaya/mon/warlock")->move(TO);
}
void init() {
  ::init();
  add_action("ancient", "down");
  add_action("push", "push");
}
int down(string str) {
  write("You cannot get down from here.",TP);
  this_player()->do_damage((random(5)));
        call_out("backup",1,TP);
  return 1;
}
void backup(object targ){
        object ob;
        if(objectp(targ)){
                if(present(targ->query_name())){
                        tell_room(TO,"The shadows congeal and begin to take the shape of a figure");
                        tell_room(TO,"A shadowy presence emerges from the shadows nearby!");
                       ob=new("/d/attaya/mon/entity");
                        ob->move(TO);
               }
          }
}

int push(string str) {
  write("%^BOLD%^You push the symbol block and it desends into the altar, carrying you down into mystery..\n");
  say((string)this_player()->query_cap_name()+" pushes the symbol block and it desends into the altarl.\n");
  this_player()->move_player("/d/attaya/guard3");
  return 1;
}

