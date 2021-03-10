inherit "/std/room";

int depth, turbulence;

int query_water() { return 1; }

void set_turbulence(int x) { turbulence = x; }
int query_turbulence() { return turbulence; }
void set_depth(int x) { depth = x; }
int query_depth() { return depth; }


create() {
  ::create();
  set_turbulence(1);
  set_depth(3);
}