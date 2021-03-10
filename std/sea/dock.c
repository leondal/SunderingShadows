inherit "/std/room";

string launch_room;

int query_dock() { return 1; }

string query_launch_room() { return launch_room; }

void set_launch_room(string str) { launch_room = str; }

init() {
  ::init();
}
