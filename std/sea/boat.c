inherit "/std/bag_logic";

mapping rooms;
int people, capacity;

void set_room(string room_name, string room_file);
object query_room(string room_name);
int move(mixed dest) { return ::move(dest); }


create() {
  ::create();
  rooms = ([ ]);
  set_weight(100);
  set_short();
}

void set_room(string room_name, string room_file) {
  object ob;
  int x;
  
  ob = new(room_file);
  if(!ob) return;
  x = ob->move(this_object());
//  tell_player(find_player("kai"),"Move returned: "+x+".\n");
  rooms[room_name] = ob;
}

object query_room(string room_name) {
  return rooms[room_name];
}

init() {
  ::init();
  add_action("board", "board");
}

int query_people() { return people; }
int query_capacity() { return capacity; }
void set_capacity(int x) { capacity = x; }

int ok_to_enter(object ob) {
  int ppl;
  
  if(wizardp(ob)) return 1;
  ppl=query_people();
  if(ppl > (query_capacity()-1) ) {
    return 0;
  }
}

void board(string str) {
  object ob;

  if(!str) {
    write("Board what?");
    return 1;
  }  
  if (ob = present(str)) {
    if(!ob->ok_to_enter(this_player())) {
      write("The boat can hold no more!");
      return 1;
    }
    write("You board the boat.");
    say(this_player()->query_cap_name()+" boards the boat.",environment(this_player()));
    if(!query_room("enter")) {
      write("This boat has no entry ramp!  Ack!");
      return 1;
    }
    this_player()->move_player(ob->query_room("enter"));
    people++;
    return 1;
  }
}
